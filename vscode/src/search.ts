import * as vscode from "vscode";
import * as Wasm from "@vscode/wasm-wasi/v1";
import ignore, { Ignore } from "ignore";

export interface Result {
  id: string;
  uri: vscode.Uri;
  range: vscode.Range;
  captures: Record<string, Capture[]>;
  context: string[];
}

export interface Capture {
  range: vscode.Range;
  text: string;
}

export interface Options {
  language: string;
  query: string;
  includePattern?: string;
  excludePattern?: string;
  includeIgnored?: boolean;
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
  public async searchText(uri: vscode.Uri, options: Options, content: string): Promise<void> {
    const contentLines = content.split("\n");
    const request = {
      id: crypto.randomUUID(),
      method: "search",
      params: {
        query: options.query,
        content: content,
      },
    };
    await new Promise<void>(async (resolve) => {
      const worker = await this.getWorker();
      if (!worker.process.stdin) {
        throw new Error(`Worker ${worker.id} stdin is not available`);
      }
      if (!worker.process.stdout) {
        throw new Error(`Worker ${worker.id} stdout is not available`);
      }
      if (!worker.task) {
        // Worker task has been cancelled
        return;
      }
      let buffer = "";
      let disposable: vscode.Disposable | undefined;
      disposable = worker.process.stdout.onData(async (data) => {
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
            continue;
          }
          if (json.id !== request.id) {
            throw new Error(
              `(Worker ${worker.id}) (Task ${worker.task.id}): Ignoring response for request ID ${JSON.stringify(json)}`
            );
          }
          if (!("result" in json)) {
            console.error('Missing "result" in JSON:', json);
            continue;
          }
          if (!json.result) {
            worker.cancelTask();
            resolve();
            break;
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
          this.results.set(id, result);
          this.onInsert.fire(result);
        }
      });
      worker.task.disposable = disposable;
      await worker.process.stdin.write(JSON.stringify(request) + "\n");
    });
  }
  private async searchFile(uri: vscode.Uri, options: Options, context: Context): Promise<void> {
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
  private async searchDirectory(
    uri: vscode.Uri,
    options: Options,
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
    Promise.all(
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
  public async search(uri: vscode.Uri, options: Options): Promise<void> {
    this.reset();
    const stat = await vscode.workspace.fs.stat(uri);
    switch (stat.type) {
      case vscode.FileType.Directory:
        this.searchDirectory(uri, options, {
          ignore: ignore(),
          ignoreRoots: [],
        });
        break;
      case vscode.FileType.File:
        this.searchFile(uri, options, {
          ignore: ignore(),
          ignoreRoots: [],
        });
        break;
    }
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
}
