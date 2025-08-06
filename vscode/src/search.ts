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
    worker.process.run().then(() => {
      worker.cancelTask();
    });
    return worker;
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
    while (true) {
      for (const [, worker] of this.workers) {
        if (worker === undefined) {
          // Worker is being created, skipping
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
        const worker = await this.createWorker();
        worker.task = {
          id: this.taskId++,
        };
        return worker;
      } else {
        await this.waitAvail();
      }
    }
  }
  private wrap(p: Promise<any>, searchId?: string) {
    this.pendingTasks++;
    console.log("[SEARCH] wrap called", { 
      searchId, 
      pendingTasks: this.pendingTasks, 
      finished: this.finished,
      finishSearchId: this.finishSearchId,
      timestamp: Date.now()
    });
    
    p.finally(() => {
      this.pendingTasks--;
      console.log("[SEARCH] wrap finally", { 
        searchId, 
        pendingTasks: this.pendingTasks, 
        finished: this.finished,
        finishSearchId: this.finishSearchId,
        timestamp: Date.now()
      });
      
      // 防止 pendingTasks 变成负数
      if (this.pendingTasks < 0) {
        console.warn("[SEARCH] pendingTasks became negative, resetting to 0", { 
          searchId, 
          pendingTasks: this.pendingTasks 
        });
        this.pendingTasks = 0;
      }
      
      if (this.pendingTasks === 0 && !this.finished) {
        this.finished = true;
        // 只有在 searchId 匹配时才触发事件
        if (searchId === this.finishSearchId) {
          console.log("[SEARCH] About to fire onSearchFinished", { searchId, timestamp: Date.now() });
          try {
            this.onSearchFinished.fire(searchId);
            console.log("[SEARCH] onSearchFinished.fire completed", { searchId });
          } catch (e) {
            console.error("[SEARCH] Error firing onSearchFinished:", e);
            // 即使出错也要确保事件被触发
        this.onSearchFinished.fire(searchId);
          }
        } else {
          console.log("[SEARCH] searchId mismatch, not firing onSearchFinished", { 
            searchId, 
            finishSearchId: this.finishSearchId 
          });
        }
      } else {
        console.log("[SEARCH] Not firing onSearchFinished", { 
          pendingTasks: this.pendingTasks, 
          finished: this.finished,
          searchId,
          finishSearchId: this.finishSearchId
        });
      }
    });
  }

  public async search(uri: vscode.Uri, options: Options & { searchId?: string }): Promise<void> {
    console.log("[SEARCH] search called", {
      searchId: options.searchId,
      query: options.query,
      timestamp: Date.now()
    });
    
    // 重置状态，但不触发 onSearchFinished 事件
    await this.reset();
    this.pendingTasks = 0;
    this.finished = false;
    this.finishSearchId = options.searchId;
    
    console.log("[SEARCH] search state initialized", {
      searchId: options.searchId,
      finishSearchId: this.finishSearchId,
      pendingTasks: this.pendingTasks,
      finished: this.finished,
      timestamp: Date.now()
    });
    
    // 简化任务计数：只包装主要的搜索任务
    const stat = await vscode.workspace.fs.stat(uri);
    let searchPromise: Promise<void>;
    
    switch (stat.type) {
      case vscode.FileType.Directory:
        searchPromise = this.searchDirectory(uri, options, {
          ignore: ignore(),
          ignoreRoots: [],
        });
        break;
      case vscode.FileType.File:
        searchPromise = this.searchFile(uri, options, {
          ignore: ignore(),
          ignoreRoots: [],
        });
        break;
      default:
        return;
    }
    
    // 使用简化的包装机制
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
        // Worker task has been cancelled
        return;
      }
      let buffer = "";
      const disposable = worker.process.stdout.onData(async (data) => {
        if (!worker.task) {
          // Worker task has been cancelled
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
        // Worker is being created, skipping
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
    if (await this.shouldIgnore(uri, options, context)) {
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
      // Ignore error
    }
    const files = await vscode.workspace.fs.readDirectory(uri);
    await Promise.all(
      files.map(async ([name, type]) => {
        const fileUri = vscode.Uri.joinPath(uri, name);
        if (type === vscode.FileType.Directory) {
          await this.searchDirectory(fileUri, options, context);
        } else if (type === vscode.FileType.File) {
          await this.searchFile(fileUri, options, context);
        }
      })
    );
  }
  private async searchFile(uri: vscode.Uri, options: Options & { searchId?: string }, context: Context): Promise<void> {
    if (await this.shouldIgnore(uri, options, context)) {
      return;
    }
    if (!uri.fsPath.endsWith(".mbt")) {
      return;
    }
    const bytes = await vscode.workspace.fs.readFile(uri);
    const text = this.textDecoder.decode(bytes);
    await this.searchText(uri, options, text);
  }
  private async searchText(uri: vscode.Uri, options: Options & { searchId?: string }, content: string): Promise<void> {
    const contentLines = content.split("\n");
    
    // 检查是否有多层查询
    if (options.layers && options.layers.length > 0) {
      console.log("[SEARCH] Executing multi-layer search", { 
        mainQuery: options.query, 
        layers: options.layers,
        searchId: options.searchId 
      });
      await this.searchTextWithLayers(uri, options, content, contentLines);
    } else {
      console.log("[SEARCH] Executing single query search", { 
        query: options.query, 
        searchId: options.searchId 
      });
      // 清除之前的结果
      this.onClear.fire();
      await this.searchTextSingle(uri, options, content, contentLines);
    }
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
    
    console.log("[WASM][SEND] searchId:", options.searchId, "request:", request, "timestamp:", Date.now());
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
          // Worker task has been cancelled
          resolve();
          return;
        }
        
        let buffer = "";
        let disposable: vscode.Disposable | undefined;
        let hasResolved = false;
        
        disposable = worker.process.stdout.onData(async (data) => {
          if (!worker.task || hasResolved) {
            // Worker task has been cancelled or already resolved
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
                console.log("[WASM][JSON_OK] searchId:", options.searchId, "json:", json, "timestamp:", Date.now());
              } catch (e) {
                console.error("[WASM][JSON_FAIL] searchId:", options.searchId, "line:", line, "error:", e, "timestamp:", Date.now());
                continue;
              }
              
              if (!("id" in json)) {
                continue;
              }
              if (json.id !== request.id) {
                console.warn(`(Worker ${worker.id}) (Task ${worker.task.id}): Ignoring response for request ID ${JSON.stringify(json)}`);
                continue;
              }
              if (!("result" in json)) {
                console.error('Missing "result" in JSON:', json);
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
                  console.warn("[SEARCH] Failed to get context lines:", e);
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
                console.log("[SEARCH][onInsert] searchId:", options.searchId, "resultId:", id, "result:", result, "timestamp:", Date.now());
              } catch (e) {
                console.error("[SEARCH] Failed to process result:", e, json);
                // 继续处理其他结果，不中断整个搜索
              }
            }
          } catch (e) {
            console.error("[SEARCH] Error in stdout handler:", e);
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
          console.log("[WASM][SEND_OK] searchId:", options.searchId, "requestId:", request.id, "timestamp:", Date.now());
        } catch (e) {
          console.error("[WASM][SEND_FAIL] searchId:", options.searchId, "error:", e, "timestamp:", Date.now());
        }
      });
    } catch (e) {
      console.error("[SEARCH] searchTextSingle error:", e);
      // 即使出错也要确保方法完成
    }
  }

  private async searchTextWithLayers(uri: vscode.Uri, options: Options & { searchId?: string }, content: string, contentLines: string[]): Promise<void> {
    console.log("[SEARCH] Starting multi-layer search", { 
      mainQuery: options.query, 
      layerCount: options.layers?.length 
    });

    // 清除之前的结果，避免重复
    this.onClear.fire();

    // 首先执行主查询
    const mainResults = await this.executeSearchQuery(uri, options.query, content, contentLines, options.searchId, "main");
    
    if (!options.layers || options.layers.length === 0) {
      // 如果没有层，直接发送主查询结果
      for (const result of mainResults) {
        this.onInsert.fire({ ...result, searchId: options.searchId, lines: result.context });
      }
      return;
    }

    // 对每个层执行查询，并过滤结果
    let filteredResults = mainResults;
    
    for (let i = 0; i < options.layers.length; i++) {
      const layer = options.layers[i];
      if (!layer.enabled || !layer.query.trim()) {
        continue;
      }

      console.log("[SEARCH] Executing layer", { 
        layerIndex: i + 1, 
        layerQuery: layer.query,
        currentResultsCount: filteredResults.length 
      });

      // 执行层查询
      const layerResults = await this.executeSearchQuery(uri, layer.query, content, contentLines, options.searchId, `layer-${i + 1}`);
      
      // 过滤结果：只保留同时匹配主查询和当前层查询的结果
      filteredResults = this.filterOverlappingResults(filteredResults, layerResults);
      
      console.log("[SEARCH] Layer completed", { 
        layerIndex: i + 1, 
        filteredResultsCount: filteredResults.length 
      });
    }

    // 发送最终过滤后的结果
    console.log("[SEARCH] Sending final filtered results", { 
      finalResultsCount: filteredResults.length 
    });
    
    for (const result of filteredResults) {
      this.onInsert.fire({ ...result, searchId: options.searchId, lines: result.context });
    }
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
      
      const processResults = async () => {
      const worker = await this.getWorker();
      if (!worker.process.stdin) {
        throw new Error(`Worker ${worker.id} stdin is not available`);
      }
      if (!worker.process.stdout) {
        throw new Error(`Worker ${worker.id} stdout is not available`);
      }
      if (!worker.task) {
        // Worker task has been cancelled
          resolve(results);
        return;
      }
        
      let buffer = "";
      let disposable: vscode.Disposable | undefined;
      disposable = worker.process.stdout.onData(async (data) => {
        if (!worker.task) {
          // Worker task has been cancelled
          disposable?.dispose();
            resolve(results);
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
            worker.cancelTask();
              resolve(results);
              return;
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
            captures: json.result.captures,
          };
            
            results.push(result);
        }
      });
        
      worker.task.disposable = disposable;
      await worker.process.stdin.write(JSON.stringify(request) + "\n");
      };
      
      processResults().catch(error => {
        console.error(`[SEARCH] Error in ${queryType} query:`, error);
        resolve(results);
      });
    });
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
}
