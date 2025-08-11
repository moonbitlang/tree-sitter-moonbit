import * as vscode from "vscode";
import * as Wasm from "@vscode/wasm-wasi/v1";
import ignore, { Ignore } from "ignore";

export interface Result {
  id: string;
  uri: vscode.Uri;
  range: vscode.Range;
  captures: Record<string, Capture[]>;
  context: string[];
  searchId?: string;
  lines?: string[];
}

export interface Capture {
  range: vscode.Range;
  text: string;
}

export interface SearchLayer {
  id: string;
  query: string;
  enabled: boolean;
}

export interface Options {
  language: string;
  query: string;
  includePattern?: string;
  excludePattern?: string;
  includeIgnored?: boolean;
  layers?: SearchLayer[]; // 新增：支持多层查询
}

export interface Context {
  ignore: Ignore;
  ignoreRoots: vscode.Uri[];
}

interface Task {
  id: number;
  disposable?: vscode.Disposable;
}

interface Worker {
  id: number;
  process: Wasm.WasmProcess;
  task?: Task;
  cancelTask(): void;
}

export class Service {
  private results: Map<string, Result> = new Map();
  private readonly extensionUri: vscode.Uri;
  private readonly textDecoder = new TextDecoder();
  private wasm: Wasm.Wasm | undefined = undefined;
  private grepWasm: WebAssembly.Module | undefined = undefined;
  private taskId = 0;
  private workerId = 0;
  private workerLimit = 4;
  private workers: Map<number, Worker | undefined> = new Map();
  private readonly onAvail: vscode.EventEmitter<void> = new vscode.EventEmitter();
  private availDisposables: vscode.Disposable[] = [];
  public readonly onInsert: vscode.EventEmitter<Result> = new vscode.EventEmitter();
  public readonly onRemove: vscode.EventEmitter<{ id: string; uri: vscode.Uri }> =
    new vscode.EventEmitter();
  public readonly onClear: vscode.EventEmitter<void> = new vscode.EventEmitter();
  public readonly onSearchFinished: vscode.EventEmitter<string | undefined> = new vscode.EventEmitter();
  private pendingTasks: number = 0;
  private finished: boolean = false;
  private finishSearchId: string | undefined = undefined;

  constructor(extensionUri: vscode.Uri) {
    this.extensionUri = extensionUri;
    this.loadPersistedResults();
  }
  private async getWasm(): Promise<Wasm.Wasm> {
    if (this.wasm) {
      return this.wasm;
    }
    const wasm = await Wasm.Wasm.load();
    this.wasm = wasm;
    return wasm;
  }
  private async getGrepWasm(): Promise<WebAssembly.Module> {
    if (this.grepWasm) {
      return this.grepWasm;
    }
    const grepUri = vscode.Uri.joinPath(this.extensionUri, "grep.wasm");
    const grepBytes = await vscode.workspace.fs.readFile(grepUri);
    const grepWasm = await WebAssembly.compile(grepBytes);
    this.grepWasm = grepWasm;
    return grepWasm;
  }
  private async createWorker(): Promise<Worker> {
    const workerId = this.workerId++;
    this.workers.set(workerId, undefined);
    
    try {
      const wasm = await this.getWasm();
      const grepWasm = await this.getGrepWasm();
      const grepProcess = await wasm.createProcess("moon-grep", grepWasm, {
        stdio: {
          in: { kind: "pipeIn" },
          out: { kind: "pipeOut" },
          err: { kind: "pipeOut" },
        },
      });
      
      const worker: Worker = {
        id: workerId,
        process: grepProcess,
        cancelTask: () => {
          if (worker.task) {
            worker.task.disposable?.dispose();
            worker.task = undefined;
          }
          this.onAvail.fire();
        },
      };
      
      this.workers.set(workerId, worker);
      
      // 启动进程并处理可能的错误
      worker.process.run().then(() => {
        worker.cancelTask();
      }).catch((error) => {
        console.error(`[WORKER] Worker ${workerId} process failed:`, error);
        worker.cancelTask();
        // 从workers map中移除失败的worker
        this.workers.delete(workerId);
      });
      
      return worker;
    } catch (error) {
      console.error(`[WORKER] Failed to create worker ${workerId}:`, error);
      this.workers.delete(workerId);
      throw error;
    }
  }
  private async waitAvail(): Promise<void> {
    await new Promise<void>((resolve) => {
      let disposable: vscode.Disposable | undefined;
      disposable = this.onAvail.event(() => {
        if (disposable) {
          disposable.dispose();
        }
        resolve();
      });
      this.availDisposables.push(disposable);
    });
  }
  private async getWorker(): Promise<Worker> {
    let retryCount = 0;
    const maxRetries = 3;
    
    while (true) {
      for (const [, worker] of this.workers) {
        if (worker === undefined) {
          continue;
        }
        if (worker.task) {
          continue;
        }
        if (worker.process.stdin && worker.process.stdout) {
          worker.task = {
            id: this.taskId++,
          };
          return worker;
        }
      }
      
      if (this.workers.size < this.workerLimit) {
        try {
          const worker = await this.createWorker();
          worker.task = {
            id: this.taskId++,
          };
          return worker;
        } catch (error) {
          console.error(`[WORKER] Failed to create worker (attempt ${retryCount + 1}/${maxRetries}):`, error);
          retryCount++;
          
          if (retryCount >= maxRetries) {
            throw new Error(`Failed to create worker after ${maxRetries} attempts`);
          }
          
          // 等待一段时间后重试
          await new Promise(resolve => setTimeout(resolve, 1000));
        }
      } else {
        await this.waitAvail();
      }
    }
  }
  private wrap(p: Promise<any>, searchId?: string) {
    this.pendingTasks++;
    console.log(`[SEARCH] Task wrapped, searchId: ${searchId}, pendingTasks: ${this.pendingTasks}`);
    
    p.finally(() => {
      this.pendingTasks--;
      console.log(`[SEARCH] Task completed, searchId: ${searchId}, pendingTasks: ${this.pendingTasks}`);
      
      // 防止 pendingTasks 变成负数
      if (this.pendingTasks < 0) {
        this.pendingTasks = 0;
      }
      
      // 当所有任务完成时，触发搜索完成事件
      if (this.pendingTasks === 0 && !this.finished) {
        this.finished = true;
        console.log(`[SEARCH] All tasks completed, firing onSearchFinished event, searchId: ${searchId}`);
        // 只有在 searchId 匹配时才触发事件
        if (searchId === this.finishSearchId) {
          try {
            this.onSearchFinished.fire(searchId);
            console.log(`[SEARCH] onSearchFinished event fired successfully for searchId: ${searchId}`);
          } catch (e) {
            console.error(`[SEARCH] Error firing onSearchFinished event:`, e);
            // 即使出错也要确保事件被触发
            this.onSearchFinished.fire(searchId);
          }
        } else {
          console.log(`[SEARCH] SearchId mismatch, expected: ${this.finishSearchId}, got: ${searchId}`);
        }
      }
    });
  }

  public async search(uri: vscode.Uri, options: Options & { searchId?: string }): Promise<void> {
    console.log(`[SEARCH] Search started, searchId: ${options.searchId}, uri: ${uri.fsPath}`);
    
    // 重置状态，但不触发 onSearchFinished 事件
    await this.reset();
    this.pendingTasks = 0;
    this.finished = false;
    this.finishSearchId = options.searchId;
    
    console.log(`[SEARCH] State reset, finishSearchId: ${this.finishSearchId}`);
    
    // 简化任务计数：只包装主要的搜索任务
    const stat = await vscode.workspace.fs.stat(uri);
    let searchPromise: Promise<void>;
    
    switch (stat.type) {
      case vscode.FileType.Directory:
        // 对于目录搜索，我们需要包装整个搜索过程
        console.log(`[SEARCH] Directory search, uri: ${uri.fsPath}`);
        searchPromise = this.searchDirectory(uri, options, {
          ignore: ignore(),
          ignoreRoots: [],
        });
        break;
      case vscode.FileType.File:
        console.log(`[SEARCH] File search, uri: ${uri.fsPath}`);
        searchPromise = this.searchFile(uri, options, {
          ignore: ignore(),
          ignoreRoots: [],
        });
        break;
      default:
        console.log(`[SEARCH] Unknown file type: ${stat.type}`);
        return;
    }
    
    // 使用 wrap 方法包装搜索任务
    this.wrap(searchPromise, options.searchId);
    
    // 添加超时机制，防止搜索永远卡住
    setTimeout(() => {
      if (!this.finished && this.pendingTasks > 0) {
        console.warn("[SEARCH] Search timeout, forcing completion", {
          searchId: options.searchId,
          pendingTasks: this.pendingTasks,
          timestamp: Date.now()
        });
        this.pendingTasks = 0;
        this.finished = true;
        if (options.searchId === this.finishSearchId) {
          this.onSearchFinished.fire(options.searchId);
        }
      }
    }, 30000); // 30秒超时
  }
  public async replace(resultId: string, replace: string): Promise<void> {
    try {
      const result = this.results.get(resultId);
      if (!result) {
        vscode.window.showErrorMessage(`Result not found: ${resultId}`);
        return;
      }
      const request = {
        id: crypto.randomUUID(),
        method: "replace",
        params: {
          captures: result.captures,
          replace,
        },
      };
      const worker = await this.getWorker();
      if (!worker.process.stdin) {
        throw new Error("Child process stdin is not available");
      }
      if (!worker.process.stdout) {
        throw new Error("Child process stdout is not available");
      }
      if (!worker.task) {
        return;
      }
      let buffer = "";
      const disposable = worker.process.stdout.onData(async (data) => {
        if (!worker.task) {
          disposable?.dispose();
          return;
        }
        buffer += this.textDecoder.decode(data);
        const stdoutLines = buffer.split("\n");
        if (stdoutLines.length < 2) {
          return;
        }
        const lastIndex = stdoutLines.length - 1;
        buffer = stdoutLines[lastIndex];
        for (const line of stdoutLines.slice(0, lastIndex)) {
          let json: any;
          try {
            json = JSON.parse(line);
          } catch (e) {
            console.error("Failed to parse JSON:", line);
            continue;
          }
          if (!("id" in json)) {
            console.error('Missing "id" in JSON:', json);
            continue;
          }
          if (json.id !== request.id) {
            continue;
          }
          if (!("result" in json)) {
            console.error('Missing "result" in JSON:', json);
            continue;
          }
          const replaced = json.result;
          const editBuilder = new vscode.WorkspaceEdit();
          editBuilder.replace(result.uri, result.range, replaced);
          this.results.delete(resultId);
          await vscode.workspace.applyEdit(editBuilder);
          this.onRemove.fire({ id: resultId, uri: result.uri });
          worker.cancelTask();
        }
      });
      worker.task.disposable = disposable;
      await worker.process.stdin.write(JSON.stringify(request) + "\n");
    } catch (error: any) {
      console.error("Error during replace:", error);
      vscode.window.showErrorMessage(`Replace failed: ${error.message || "Unknown error"}`);
    }
  }
  public async dismiss(resultId: string) {
    const result = this.results.get(resultId);
    if (!result) {
      vscode.window.showErrorMessage(`Result not found: ${resultId}`);
      return;
    }
    this.results.delete(resultId);
    this.onRemove.fire({ id: resultId, uri: result.uri });
  }
  public async reset() {
    const freeWorkers: Map<number, Worker> = new Map();
    const terminationPromises: Promise<number>[] = [];
    for (const [workerId, worker] of this.workers) {
      if (worker === undefined) {
        continue;
      }
      if (!worker.task) {
        freeWorkers.set(workerId, worker);
      } else {
        terminationPromises.push(worker.process.terminate());
        worker.cancelTask();
      }
    }
    await Promise.all(terminationPromises);
    this.workers = freeWorkers;
    this.availDisposables.forEach((disposable) => disposable.dispose());
    this.availDisposables = [];
    this.results.clear();
    this.onClear.fire();
  }
  private async searchDirectory(
    uri: vscode.Uri,
    options: Options & { searchId?: string },
    context: Context
  ): Promise<void> {
    console.log(`[SEARCH] searchDirectory started, uri: ${uri.fsPath}, searchId: ${options.searchId}`);
    
    if (await this.shouldIgnore(uri, options, context)) {
      console.log(`[SEARCH] Directory ignored, uri: ${uri.fsPath}`);
      return;
    }
    const gitignoreUri = vscode.Uri.joinPath(uri, ".gitignore");
    try {
      const bytes = await vscode.workspace.fs.readFile(gitignoreUri);
      const text = this.textDecoder.decode(bytes);
      context = {
        ignore: context.ignore.add(text.split("\n")),
        ignoreRoots: [
          ...context.ignoreRoots,
          uri.fsPath.endsWith("/") ? uri : vscode.Uri.joinPath(uri, "/"),
        ],
      };
    } catch (e) {
    }
    const files = await vscode.workspace.fs.readDirectory(uri);
    console.log(`[SEARCH] Found ${files.length} files in directory: ${uri.fsPath}`);
    
    // 为每个文件创建搜索任务，但不使用 wrap 包装
    const searchPromises = files.map(async ([name, type]) => {
      const fileUri = vscode.Uri.joinPath(uri, name);
      try {
        if (type === vscode.FileType.Directory) {
          // 递归搜索子目录
          console.log(`[SEARCH] Searching subdirectory: ${fileUri.fsPath}`);
          await this.searchDirectory(fileUri, options, context);
          console.log(`[SEARCH] Subdirectory search completed: ${fileUri.fsPath}`);
        } else if (type === vscode.FileType.File) {
          // 搜索单个文件
          console.log(`[SEARCH] Searching file: ${fileUri.fsPath}`);
          await this.searchFile(fileUri, options, context);
          console.log(`[SEARCH] File search completed: ${fileUri.fsPath}`);
        }
      } catch (error) {
        console.error(`[SEARCH] Error searching ${fileUri.fsPath}:`, error);
        // 即使出错也要继续，不要让整个搜索失败
      }
    });
    
    // 等待所有文件搜索完成
    console.log(`[SEARCH] Waiting for all search tasks to complete in directory: ${uri.fsPath}`);
    try {
      await Promise.all(searchPromises);
      console.log(`[SEARCH] All search tasks completed in directory: ${uri.fsPath}`);
    } catch (error) {
      console.error(`[SEARCH] Error waiting for search tasks in directory ${uri.fsPath}:`, error);
      // 即使出错也要继续，不要让整个搜索失败
    }
  }
  
  private async searchFile(uri: vscode.Uri, options: Options & { searchId?: string }, context: Context): Promise<void> {
    console.log(`[SEARCH] searchFile started, uri: ${uri.fsPath}, searchId: ${options.searchId}`);
    
    if (await this.shouldIgnore(uri, options, context)) {
      console.log(`[SEARCH] File ignored, uri: ${uri.fsPath}`);
      return;
    }
    if (!uri.fsPath.endsWith(".mbt")) {
      console.log(`[SEARCH] File not .mbt, skipping: ${uri.fsPath}`);
      return;
    }
    const bytes = await vscode.workspace.fs.readFile(uri);
    const text = this.textDecoder.decode(bytes);
    console.log(`[SEARCH] File content loaded, size: ${text.length} chars, uri: ${uri.fsPath}`);
    
    // 直接调用 searchText，不使用 wrap 包装
    await this.searchText(uri, options, text);
    console.log(`[SEARCH] searchText completed for file: ${uri.fsPath}`);
  }
  private async searchText(uri: vscode.Uri, options: Options & { searchId?: string }, content: string): Promise<void> {
    const contentLines = content.split("\n");
    console.log(`[SEARCH] searchText called, uri: ${uri.fsPath}, searchId: ${options.searchId}, hasLayers: ${!!options.layers?.length}`);
    
    // 检查是否有多层查询
    if (options.layers && options.layers.length > 0) {
      // 直接调用多层搜索，不使用 wrap 包装
      console.log(`[SEARCH] Executing multi-layer search directly`);
      await this.searchTextWithLayers(uri, options, content, contentLines);
      console.log(`[SEARCH] Multi-layer search completed for: ${uri.fsPath}`);
    } else {
      // 清除之前的结果
      this.onClear.fire();
      // 直接调用单层搜索，不使用 wrap 包装
      console.log(`[SEARCH] Executing single-layer search directly`);
      await this.searchTextSingle(uri, options, content, contentLines);
      console.log(`[SEARCH] Single-layer search completed for: ${uri.fsPath}`);
    }
    console.log(`[SEARCH] searchText fully completed for: ${uri.fsPath}`);
  }

  private async searchTextSingle(uri: vscode.Uri, options: Options & { searchId?: string }, content: string, contentLines: string[]): Promise<void> {
    const request = {
      id: crypto.randomUUID(),
      method: "search",
      params: {
        query: options.query,
        content: content,
      },
    };
    
    try {
      await new Promise<void>(async (resolve, reject) => {
        const worker = await this.getWorker();
        if (!worker.process.stdin) {
          reject(new Error(`Worker ${worker.id} stdin is not available`));
          return;
        }
        if (!worker.process.stdout) {
          reject(new Error(`Worker ${worker.id} stdout is not available`));
          return;
        }
        if (!worker.task) {
          resolve();
          return;
        }
        
        let buffer = "";
        let disposable: vscode.Disposable | undefined;
        let hasResolved = false;
        
        disposable = worker.process.stdout.onData(async (data) => {
          if (!worker.task || hasResolved) {
            disposable?.dispose();
            return;
          }
          
          try {
            buffer += this.textDecoder.decode(data);
            const stdoutLines = buffer.split("\n");
            if (stdoutLines.length < 2) {
              return;
            }
            const lastIndex = stdoutLines.length - 1;
            buffer = stdoutLines[lastIndex];
            
            for (const line of stdoutLines.slice(0, lastIndex)) {
              let json: any;
              try {
                json = JSON.parse(line);
              } catch (e) {
                continue;
              }
              
              if (!("id" in json)) {
                continue;
              }
              if (json.id !== request.id) {
                continue;
              }
              if (!("result" in json)) {
                continue;
              }
              if (!json.result) {
                if (!hasResolved) {
                  hasResolved = true;
                  disposable?.dispose();
                  worker.cancelTask();
                  resolve();
                }
                break;
              }
              
              try {
                // 检查 result 是否有 range 属性
                if (!json.result.range) {
                  console.warn(`[SEARCH] Result missing range property:`, json.result);
                  continue;
                }
                
                // 检查 range 是否有 start 和 end 属性
                if (!json.result.range.start || !json.result.range.end) {
                  console.warn(`[SEARCH] Result range missing start or end:`, json.result.range);
                  continue;
                }
                
                const startLine = json.result.range.start.row;
                const endLine = json.result.range.end.row;
                const start = new vscode.Position(startLine, json.result.range.start.column);
                const end = new vscode.Position(endLine, json.result.range.end.column);
                const range = new vscode.Range(start, end);
                const id = crypto.randomUUID();
                
                // 安全地获取上下文行
                let context: string[] = [];
                try {
                  context = contentLines.slice(startLine, endLine + 1);
                } catch (e) {
                  context = [];
                }
                
                const result = {
                  id,
                  uri: uri,
                  range: range,
                  context: context,
                  captures: json.result.captures || {},
                };
                this.results.set(id, result);
                this.onInsert.fire({ ...result, searchId: options.searchId, lines: result.context });
                
              } catch (e) {
                console.error(`[SEARCH] Error processing result:`, e);
                // 继续处理其他结果，不中断整个搜索
              }
            }
          } catch (e) {
            if (!hasResolved) {
              hasResolved = true;
              disposable?.dispose();
              worker.cancelTask();
              resolve();
            }
          }
        });
        
        worker.task.disposable = disposable;
        
        try {
          await worker.process.stdin.write(JSON.stringify(request) + "\n");
        } catch (e) {
        }
      });
    } catch (e) {
      // 即使出错也要确保方法完成
    }
  }

  private async searchTextWithLayers(uri: vscode.Uri, options: Options & { searchId?: string }, content: string, contentLines: string[]): Promise<void> {
    // 清除之前的结果，避免重复
    this.onClear.fire();

    // 检查是否可以使用 Moonbit 的级联搜索
    if (options.layers && options.layers.length > 0) {
      // 直接使用 Moonbit 的级联搜索功能，不需要测试
      await this.executeCascadeSearch(uri, options, content, contentLines);
      
      // 注意：executeCascadeSearch 内部已经通过 onInsert 触发了结果
      // finished 状态现在由 wrap 方法管理，不需要在这里设置
    } else {
      // 回退到单层搜索
      const currentResults = await this.executeSearchQuery(uri, options.query, content, contentLines, options.searchId, "main");
      for (const result of currentResults) {
        this.results.set(result.id, result);
        this.onInsert.fire({ ...result, searchId: options.searchId, lines: result.context });
      }
    }
  }

  // 新增：使用 Moonbit 的级联搜索
  private async executeCascadeSearch(uri: vscode.Uri, options: Options & { searchId?: string }, content: string, contentLines: string[]): Promise<void> {
    // 准备层查询
    const layerQueries = options.layers!
      .filter(layer => layer.enabled && layer.query.trim())
      .map(layer => layer.query);

    // 使用 Moonbit 的基于Node的嵌套搜索
    const request = {
      id: crypto.randomUUID(),
      method: "nestedNodeSearch",
      params: {
        content: content,
        mainQuery: options.query,
        layerQueries: layerQueries,
      },
    };

    return new Promise<void>(async (resolve) => {
      const worker = await this.getWorker();
      if (!worker.process.stdin) {
        throw new Error(`Worker ${worker.id} stdin is not available`);
      }
      if (!worker.process.stdout) {
        throw new Error(`Worker ${worker.id} stdout is not available`);
      }
      if (!worker.task) {
        resolve();
        return;
      }

      let buffer = "";
      let disposable: vscode.Disposable | undefined;
      let requestId = request.id;
      
      disposable = worker.process.stdout.onData(async (data) => {
        if (!worker.task) {
          disposable?.dispose();
          resolve();
          return;
        }

        buffer += this.textDecoder.decode(data);
        const stdoutLines = buffer.split("\n");
        if (stdoutLines.length < 2) {
          return;
        }
        const lastIndex = stdoutLines.length - 1;
        buffer = stdoutLines[lastIndex];

        for (const line of stdoutLines.slice(0, lastIndex)) {
          let json: any;
          try {
            json = JSON.parse(line);
          } catch (e) {
            continue;
          }

          if (!("id" in json) || json.id !== requestId) {
            continue;
          }
          if (!("result" in json)) {
            continue;
          }

          // 处理调试消息
          if (typeof json.result === "string" && json.result.startsWith("DEBUG:")) {
            console.log("[MOONBIT]", json.result);
            
            // 检查是否是搜索完成消息
            if (json.result.includes("Nested search completed")) {
              console.log(`[SEARCH] Cascade search completed for ${uri.fsPath}, debug message: ${json.result}`);
              clearTimeout(timeoutId);
              if (worker.task) {
                worker.task.disposable?.dispose();
                worker.task = undefined;
                this.onAvail.fire();
              }
              disposable?.dispose();
              resolve();
              return;
            }
            
            continue;
          }

          const result = json.result;
          
          // 检查结果是否有效
          if (!result || !result.range || !result.range.start || !result.range.end) {
            continue;
          }
          
          const resultId = crypto.randomUUID();
        
          // 转换 Moonbit 结果格式为 TypeScript 格式
          const tsResult: Result = {
            id: resultId,
            uri: uri,
            range: new vscode.Range(
              new vscode.Position(result.range.start.row, result.range.start.column),
              new vscode.Position(result.range.end.row, result.range.end.column)
            ),
            captures: result.captures || {},
            context: this.extractContextFromLines(contentLines, result.range.start.row, result.range.end.row),
            searchId: options.searchId,
          };

          this.results.set(resultId, tsResult);
          this.onInsert.fire(tsResult);

          // 检查是否收到了最终结果（null 表示搜索完成）
          if (json.result === null) {
            console.log(`[SEARCH] Cascade search completed for ${uri.fsPath}, result: null`);
            clearTimeout(timeoutId);
            if (worker.task) {
              worker.task.disposable?.dispose();
              worker.task = undefined;
              this.onAvail.fire();
            }
            disposable?.dispose();
            
            // 移除这里的 onSearchFinished 事件触发，让主搜索任务统一管理
            // 触发搜索完成事件，确保多层查询记录历史
            // if (options.searchId) {
            //   this.onSearchFinished.fire(options.searchId);
            // }
            
            resolve();
            return;
          }
        }
      });

      // 发送请求到 Moonbit
      worker.process.stdin.write(JSON.stringify(request) + "\n");
      
      // 设置超时
      const timeoutId = setTimeout(() => {
        console.log(`[SEARCH] Cascade search timeout for ${uri.fsPath}, forcing completion`);
        if (worker.task) {
          worker.cancelTask();
        }
        disposable?.dispose();
        resolve();
      }, 30000); // 30秒超时
      
      // 添加额外的安全检查：如果 worker.task 不存在，立即解析
      if (!worker.task) {
        console.log(`[SEARCH] No worker task available for ${uri.fsPath}, resolving immediately`);
        clearTimeout(timeoutId);
        disposable?.dispose();
        resolve();
      }
    });
  }

  // 新增：从行数组中提取上下文
  private extractContextFromLines(contentLines: string[], startRow: number, endRow: number): string[] {
    const context: string[] = [];
    for (let i = Math.max(0, startRow - 2); i <= Math.min(contentLines.length - 1, endRow + 2); i++) {
      context.push(contentLines[i]);
    }
    return context;
  }

  private async executeSearchQuery(uri: vscode.Uri, query: string, content: string, contentLines: string[], searchId?: string, queryType: string = "unknown"): Promise<Result[]> {
    const request = {
      id: crypto.randomUUID(),
      method: "search",
      params: {
        query: query,
        content: content,
      },
    };

    return new Promise<Result[]>((resolve) => {
      const results: Result[] = [];
      let hasResolved = false;
      
      // 添加超时机制
      const timeout = setTimeout(() => {
        if (!hasResolved) {
          hasResolved = true;
          console.warn(`[SEARCH] Timeout reached for ${queryType} query`);
          resolve(results);
        }
      }, 10000); // 10秒超时
      
      const processResults = async () => {
        try {
          const worker = await this.getWorker();
          if (!worker.process.stdin) {
            throw new Error(`Worker ${worker.id} stdin is not available`);
          }
          if (!worker.process.stdout) {
            throw new Error(`Worker ${worker.id} stdout is not available`);
          }
          if (!worker.task) {
            if (!hasResolved) {
              hasResolved = true;
              clearTimeout(timeout);
              resolve(results);
            }
            return;
          }
            
          let buffer = "";
          let disposable: vscode.Disposable | undefined;
          disposable = worker.process.stdout.onData(async (data) => {
            if (!worker.task || hasResolved) {
              disposable?.dispose();
              return;
            }
              
            buffer += this.textDecoder.decode(data);
            const stdoutLines = buffer.split("\n");
            if (stdoutLines.length < 2) {
              return;
            }
            const lastIndex = stdoutLines.length - 1;
            buffer = stdoutLines[lastIndex];
              
            for (const line of stdoutLines.slice(0, lastIndex)) {
              if (hasResolved) break;
              
              let json: any;
              try {
                json = JSON.parse(line);
              } catch (e) {
                console.error("Failed to parse JSON:", line);
                continue;
              }
                
              if (!("id" in json)) {
                continue;
              }
              if (json.id !== request.id) {
                continue;
              }
              if (!("result" in json)) {
                console.error('Missing "result" in JSON:', json);
                continue;
              }
              if (!json.result) {
                if (!hasResolved) {
                  hasResolved = true;
                  clearTimeout(timeout);
                  worker.cancelTask();
                  resolve(results);
                }
                return;
              }
                
              // 检查 result 是否有 range 属性
              if (!json.result.range) {
                console.warn(`[SEARCH] Result missing range property:`, json.result);
                continue;
              }
                
              // 检查 range 是否有 start 和 end 属性
              if (!json.result.range.start || !json.result.range.end) {
                console.warn(`[SEARCH] Result range missing start or end:`, json.result.range);
                continue;
              }
                
              const startLine = json.result.range.start.row;
              const endLine = json.result.range.end.row;
              const start = new vscode.Position(startLine, json.result.range.start.column);
              const end = new vscode.Position(endLine, json.result.range.end.column);
              const range = new vscode.Range(start, end);
              const id = crypto.randomUUID();
              const result = {
                id,
                uri: uri,
                range: range,
                context: contentLines.slice(startLine, endLine + 1),
                captures: json.result.captures || {},
              };
                
              results.push(result);
            }
          });
            
          worker.task.disposable = disposable;
          await worker.process.stdin.write(JSON.stringify(request) + "\n");
        } catch (error) {
          console.error(`[SEARCH] Error in ${queryType} query:`, error);
          if (!hasResolved) {
            hasResolved = true;
            clearTimeout(timeout);
            resolve(results);
          }
        }
      };
      
      processResults().catch(error => {
        console.error(`[SEARCH] Error in ${queryType} query:`, error);
        if (!hasResolved) {
          hasResolved = true;
          clearTimeout(timeout);
          resolve(results);
        }
      });
    });
  }

    private async executeSearchQueryInResults(uri: vscode.Uri, query: string, previousResults: Result[], contentLines: string[], searchId?: string, queryType: string = "unknown"): Promise<Result[]> {
    // 如果没有前一层结果，返回空数组
    if (previousResults.length === 0) {
      return [];
    }

    // 收集所有前一层结果的范围
    const searchRanges: vscode.Range[] = [];
    for (const result of previousResults) {
      searchRanges.push(result.range);
    }

    // 合并相邻的范围，减少重复搜索
    const mergedRanges = this.mergeOverlappingRanges(searchRanges);

    // 在每个合并后的范围内执行查询
    const allResults: Result[] = [];
    
    for (const range of mergedRanges) {
      // 提取该范围内的内容
      const startLine = range.start.line;
      const endLine = range.end.line;
      const rangeContent = contentLines.slice(startLine, endLine + 1).join('\n');
      
      // 在该范围内执行查询
      const rangeResults = await this.executeSearchQuery(uri, query, rangeContent, contentLines, searchId, `${queryType}-range-${startLine}-${endLine}`);
      
      // 调整结果的行号，使其相对于原始文件
      const adjustedResults = rangeResults.map(result => ({
        ...result,
        range: new vscode.Range(
          new vscode.Position(result.range.start.line + startLine, result.range.start.character),
          new vscode.Position(result.range.end.line + startLine, result.range.end.character)
        )
      }));
      
      allResults.push(...adjustedResults);
    }

    return allResults;
  }

  private mergeOverlappingRanges(ranges: vscode.Range[]): vscode.Range[] {
    if (ranges.length === 0) return [];
    
    // 按起始行排序
    const sortedRanges = [...ranges].sort((a, b) => a.start.line - b.start.line);
    const merged: vscode.Range[] = [];
    
    let current = sortedRanges[0];
    
    for (let i = 1; i < sortedRanges.length; i++) {
      const next = sortedRanges[i];
      
      // 如果当前范围与下一个范围重叠或相邻，则合并
      if (current.end.line >= next.start.line - 1) {
        current = new vscode.Range(
          current.start,
          new vscode.Position(Math.max(current.end.line, next.end.line), next.end.character)
        );
      } else {
        merged.push(current);
        current = next;
      }
    }
    
    merged.push(current);
    return merged;
  }

  private filterOverlappingResults(results1: Result[], results2: Result[]): Result[] {
    // 过滤重叠的结果：只保留在两个结果集中都出现的结果 多层查询的主要逻辑是取交集
    const overlappingResults: Result[] = [];
    
    for (const result1 of results1) {
      for (const result2 of results2) {
        if (this.resultsOverlap(result1, result2)) {
          overlappingResults.push(result1);
          break;
        }
      }
    }
    
    return overlappingResults;
  }

  private resultsOverlap(result1: Result, result2: Result): boolean {
    // 检查两个结果是否重叠
    // 这里使用简单的行范围重叠检查
    const range1 = result1.range;
    const range2 = result2.range;
    
    // 检查行范围是否重叠
    const startLine1 = range1.start.line;
    const endLine1 = range1.end.line;
    const startLine2 = range2.start.line;
    const endLine2 = range2.end.line;
    
    return !(endLine1 < startLine2 || endLine2 < startLine1);
  }
  private async shouldIgnore(
    uri: vscode.Uri,
    options: Options,
    context: Context
  ): Promise<boolean> {
    if (options.includePattern && !uri.fsPath.match(options.includePattern)) {
      return true;
    }
    if (options.excludePattern && uri.fsPath.match(options.excludePattern)) {
      return true;
    }
    if (!options.includeIgnored) {
      for (const ignoredRoot of context.ignoreRoots) {
        if (uri.fsPath.startsWith(ignoredRoot.fsPath)) {
          const relativePath = uri.fsPath.slice(ignoredRoot.fsPath.length);
          if (context.ignore.ignores(relativePath)) {
            return true;
          }
        }
      }
    }
    return false;
  }

  // 轻量级持久化存储 - 只存储查询信息，不存储具体结果
  private async loadPersistedResults() {
    // 不再加载具体结果，只记录日志
  }

  private async savePersistedResults() {
    // 不再保存具体结果，只记录日志
  }
}
