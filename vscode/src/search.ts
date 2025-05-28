import * as vscode from "vscode";
import * as vscodeUri from "vscode-uri";
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

export class Service {
  private results: Map<string, Result>;
  private readonly extensionUri: vscode.Uri;
  private readonly textDecoder = new TextDecoder();
  private wasm: Wasm.Wasm | undefined = undefined;
  private workerId = 0;
  private workers: Map<number, Wasm.WasmProcess> = new Map();
  public readonly onInsert: vscode.EventEmitter<Result>;
  public readonly onRemove: vscode.EventEmitter<{ id: string; uri: vscode.Uri }>;
  public readonly onClear: vscode.EventEmitter<void>;
  constructor(extensionUri: vscode.Uri) {
    this.extensionUri = extensionUri;
    this.results = new Map();
    this.onInsert = new vscode.EventEmitter();
    this.onRemove = new vscode.EventEmitter();
    this.onClear = new vscode.EventEmitter();
  }
  private async getWasm(): Promise<Wasm.Wasm> {
    if (this.wasm) {
      return this.wasm;
    }
    const wasm = await Wasm.Wasm.load();
    this.wasm = wasm;
    return wasm;
  }
  public async searchText(uri: vscode.Uri, options: Options, content: string): Promise<void> {
    const wasm = await this.getWasm();
    const contentLines = content.split("\n");
    const request = {
      id: crypto.randomUUID(),
      method: "search",
      params: {
        query: options.query,
        content: content,
      },
    };
    const grepUri = vscode.Uri.joinPath(this.extensionUri, "grep.wasm");
    const grepBytes = await vscode.workspace.fs.readFile(grepUri);
    const grepWasm = await WebAssembly.compile(grepBytes);
    const workerId = this.workerId++;
    const child = await wasm.createProcess("moon-grep", grepWasm, {
      stdio: {
        in: { kind: "pipeIn" },
        out: { kind: "pipeOut" },
        err: { kind: "pipeOut" },
      },
    });
    if (!child.stdin) {
      throw new Error("Child process stdin is not available");
    }
    await child.stdin.write(JSON.stringify(request) + "\n");
    if (!child.stdout) {
      throw new Error("Child process stdout is not available");
    }
    let buffer = "";
    child.stdout.onData(async (data) => {
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
        console.log("Parsed JSON:", json);
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
          child.terminate();
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
    this.workers.set(workerId, child);
    console.log(`Worker ${workerId} started for ${uri.fsPath}`);
    const status = await child.run();
    if (status !== 0) {
      console.error(`Worker ${workerId} exited with status ${status}`);
    } else {
      console.log(`Worker ${workerId} completed for ${uri.fsPath}`);
    }
    this.workers.delete(workerId);
  }
  private async searchFile(uri: vscode.Uri, options: Options, context: Context): Promise<void> {
    if (options.includePattern && !uri.fsPath.match(options.includePattern)) {
      return;
    }
    if (options.excludePattern && uri.fsPath.match(options.excludePattern)) {
      return;
    }
    if (options.includeIgnored === true && context.ignore.ignores(uri.fsPath)) {
      return;
    }
    const bytes = await vscode.workspace.fs.readFile(uri);
    const text = this.textDecoder.decode(bytes);
    await this.searchText(uri, options, text);
  }
  private async searchDirectory(
    uri: vscode.Uri,
    options: Options,
    context: Context
  ): Promise<void> {
    if (options.includePattern && !uri.fsPath.match(options.includePattern)) {
      return;
    }
    if (options.excludePattern && uri.fsPath.match(options.excludePattern)) {
      return;
    }
    if (!options.includeIgnored) {
      for (const ignoredRoot of context.ignoreRoots) {
        if (uri.fsPath.startsWith(ignoredRoot.fsPath)) {
          const relativePath = uri.fsPath.slice(ignoredRoot.fsPath.length);
          if (context.ignore.ignores(relativePath)) {
            return;
          }
        }
      }
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
    for (const [workerId, worker] of this.workers.entries()) {
      await worker.terminate();
      this.workers.delete(workerId);
    }
    this.clear();
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
      const wasm = await this.getWasm();
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
      const grepUri = vscode.Uri.joinPath(this.extensionUri, "grep.wasm");
      const grepBytes = await vscode.workspace.fs.readFile(grepUri);
      const grepWasm = await WebAssembly.compile(grepBytes);
      const child = await wasm.createProcess("moon-grep", grepWasm, {
        stdio: {
          in: { kind: "pipeIn" },
          out: { kind: "pipeOut" },
          err: { kind: "pipeOut" },
        },
      });
      if (!child.stdin) {
        throw new Error("Child process stdin is not available");
      }
      await child.stdin.write(JSON.stringify(request) + "\n");
      if (!child.stdout) {
        throw new Error("Child process stdout is not available");
      }
      let buffer = "";
      child.stdout.onData(async (data) => {
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
        }
      });
      const status = await child.run();
      if (status !== 0) {
        throw new Error(`Child process exited with status ${status}`);
      }
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
  public clear() {
    this.results.clear();
    this.onClear.fire();
  }
}
