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
  layers?: SearchLayer[]; // New: support multi-layer queries
  enableAstPrint?: boolean; // New: control AST printing
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
  processPromise: Promise<number>;
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
  public readonly onReplace: vscode.EventEmitter<{ id: string; uri: vscode.Uri }> =
    new vscode.EventEmitter();
  public readonly onClear: vscode.EventEmitter<void> = new vscode.EventEmitter();
  public readonly onSearchFinished: vscode.EventEmitter<string> = new vscode.EventEmitter();
  private pendingTasks: number = 0;
  private finished: boolean = false;
  private finishSearchId: string | undefined = undefined;

  // Public method to get current result count
  public getResultCount(): number {
    return this.results.size;
  }

  // Public method to get all current result IDs
  public getResultIds(): string[] {
    return Array.from(this.results.keys());
  }

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
      
      // Start the process immediately to initialize stdin/stdout
      const processPromise = grepProcess.run();
      processPromise.then((exitCode) => {
        // Mark worker as dead and trigger cleanup
        this.markWorkerAsDead(workerId, exitCode);
      }).catch((error) => {
        // Mark worker as dead and trigger cleanup
        this.markWorkerAsDead(workerId, -1);
      });
      
      const worker: Worker = {
        id: workerId,
        process: grepProcess,
        processPromise: processPromise,
        cancelTask: () => {
          if (worker.task) {
            worker.task.disposable?.dispose();
            worker.task = undefined;
          }
          this.onAvail.fire();
        },
      };
      
      this.workers.set(workerId, worker);
      
      // Wait a bit for the process to fully initialize
      await new Promise(resolve => setTimeout(resolve, 100));
      
      return worker;
    } catch (error) {
      this.workers.delete(workerId);
      throw error;
    }
  }
  private markWorkerAsDead(workerId: number, exitCode: number): void {
    const worker = this.workers.get(workerId);
    if (worker) {
      // Clean up worker resources
      if (worker.task) {
        worker.task.disposable?.dispose();
        worker.task = undefined;
      }
      // Remove dead worker
      this.workers.delete(workerId);
      
      // Trigger availability event to wake up waiting tasks
      this.onAvail.fire();
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
      for (const [workerId, worker] of this.workers) {
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
        } else {
          // Mark this worker as dead and remove it
          this.markWorkerAsDead(workerId, -1);
          continue; // Continue to next worker
        }
      }
      
      // Always try to create new workers if we're below the limit
      if (this.workers.size < this.workerLimit) {
        try {
          const worker = await this.createWorker();
          worker.task = {
            id: this.taskId++,
          };
          return worker;
        } catch (error) {
          retryCount++;
          
          if (retryCount >= maxRetries) {
            throw new Error(`Failed to create worker after ${maxRetries} attempts`);
          }
          
          // Wait for a while before retrying
          await new Promise(resolve => setTimeout(resolve, 1000));
        }
      } else {
        await this.waitAvail();
      }
    }
  }
  private wrap(p: Promise<any>, searchId?: string) {
    this.pendingTasks++;
    
    p.finally(() => {
      this.pendingTasks--;
      
      // Prevent pendingTasks from becoming negative
      if (this.pendingTasks < 0) {
        this.pendingTasks = 0;
      }
      
              // When all tasks complete, trigger search completion event
      if (this.pendingTasks === 0 && !this.finished) {
        
        this.finished = true;

                  // Only trigger event when searchId matches
        if (searchId === this.finishSearchId) {
          try {
            if (searchId) {
              // Deduplicate results before firing the event
              this.deduplicateResults();
            this.onSearchFinished.fire(searchId);
            }
  
          } catch (e) {
            console.error(`Error firing onSearchFinished event:`, e);
            // Ensure event is triggered even if error occurs
            if (searchId) {
              this.deduplicateResults();
            this.onSearchFinished.fire(searchId);
            }
          }
                  } else {
            // SearchId mismatch, not firing event
          }
      } else {
        // Not triggering search completion
      }
    });
  }

  public async search(uri: vscode.Uri, options: Options & { searchId?: string }): Promise<void> {

    
    // Reset state without triggering onSearchFinished event
    await this.reset();
    this.pendingTasks = 0;
    this.finished = false;
    this.finishSearchId = options.searchId;
    

    
          // Simplify task counting: only wrap main search tasks
    const stat = await vscode.workspace.fs.stat(uri);
    let searchPromise: Promise<void>;
    
    switch (stat.type) {
              case vscode.FileType.Directory:
          // For directory search, wrap the entire search process
    
        searchPromise = this.searchDirectory(uri, options, {
          ignore: ignore(),
          ignoreRoots: [],
        });
        break;
              case vscode.FileType.File:
          // For file search, wrap the search process
          searchPromise = this.searchFile(uri, options, {
          ignore: ignore(),
          ignoreRoots: [],
        });
        break;
              default:
          // Unknown file type
          return;
    }
    
            // Use wrap method to wrap search tasks
    this.wrap(searchPromise, options.searchId);
    
          // Add timeout mechanism to prevent search from hanging forever
          setTimeout(() => {
        if (!this.finished && this.pendingTasks > 0) {
          // Force trigger onSearchFinished event
          this.pendingTasks = 0;
          this.finished = true;
          if (options.searchId === this.finishSearchId) {
          if (options.searchId) {
            // Deduplicate results before firing the event
            this.deduplicateResults();
          this.onSearchFinished.fire(options.searchId);
          }
        }
              }
      }, 30000); // 30 second timeout
  }
  public async replace(resultId: string, replace: string, enableAstPrint: boolean = false): Promise<void> {
      const result = this.results.get(resultId);
      if (!result) {
        vscode.window.showErrorMessage(`Result not found: ${resultId}`);
        return;
      }

    try {
      // Get the current document content
      const document = await vscode.workspace.openTextDocument(result.uri);
      const currentContent = document.getText();
      
                // Create a replacement request
              const request = {
          id: crypto.randomUUID(),
          method: "replace",
          params: {
            captures: result.captures,
            replace: replace,
            content: currentContent, // Add file content so MoonBit can generate complete file AST info
            debug_mode: true, // Add debug_mode parameter
            print_ast: enableAstPrint, // Set dynamically based on enableAstPrint parameter
          },
        };

      const worker = await this.getWorker();
      if (!worker.process.stdin || !worker.process.stdout) {
        throw new Error("Worker not available");
      }

      let buffer = "";
      let disposable: vscode.Disposable | undefined;
      let replacementText = "";
      let jsonParseCount = 0;
      let validResponseCount = 0;
      let hasAppliedReplacement = false; // Add flag

      disposable = worker.process.stdout.onData(async (data) => {
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
          jsonParseCount++;

          
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
          
          validResponseCount++;
          
          // Extract the replaced text and AST info from the result object
          if (typeof json.result === 'object' && json.result.replaced) {
            replacementText = json.result.replaced;
            
                        // Log AST information if available (only when AST printing is enabled)
            if (json.result.ast_info && enableAstPrint) {
              // Show AST info in VSCode output channel
              const outputChannel = vscode.window.createOutputChannel("MoonBit AST Analysis");
              outputChannel.clear();
              outputChannel.appendLine("=== MoonBit AST Analysis ===");
              outputChannel.appendLine(json.result.ast_info);
              outputChannel.show();
              
              // Also show a brief notification
              vscode.window.showInformationMessage(
                `AST Analysis completed - check output channel for details`,
                { modal: false }
              );
            }
            
            // New: Show complete file AST info (only when AST printing is enabled)
            if (json.result.complete_file_ast && enableAstPrint) {
              // Show complete file AST info in VSCode output channel
              const outputChannel = vscode.window.createOutputChannel("MoonBit Complete File AST Analysis");
              outputChannel.clear();
              outputChannel.appendLine("=== MoonBit Complete File AST Analysis ===");
              outputChannel.appendLine(json.result.complete_file_ast);
              outputChannel.show();
              
              // Also show a brief notification
              vscode.window.showInformationMessage(
                `Complete File AST Analysis completed - check output channel for details`,
                { modal: false }
              );
            }
          } else {
            continue;
          }
          


          // Apply the replacement to the document
          try {
            // Prevent duplicate replacement application
            if (hasAppliedReplacement) {
              continue;
            }
            hasAppliedReplacement = true;
            
                        // Get the original document content before replacement
            const originalDocument = await vscode.workspace.openTextDocument(result.uri);
            const originalContent = originalDocument.getText();
            
            // Extract the original text that will be replaced
            const originalText = originalDocument.getText(new vscode.Range(
              result.range.start.line,
              result.range.start.character,
              result.range.end.line,
              result.range.end.character
            ));
            
            const edit = new vscode.WorkspaceEdit();
            
            // Create the replacement range
            const range = new vscode.Range(
              result.range.start.line,
              result.range.start.character,
              result.range.end.line,
              result.range.end.character
            );
            
            // Replace the matched text with the replacement text
            edit.replace(result.uri, range, replacementText);
            
            // Apply the edit
            const success = await vscode.workspace.applyEdit(edit);
            if (!success) {
              throw new Error("Failed to apply edit");
            }
            
            // Get the document after the edit to build the new content
            const document = await vscode.workspace.openTextDocument(result.uri);
            const newContent = document.getText();
            
            // Verify that the content is actually file content, not JSON
            if (newContent && !newContent.startsWith('{') && !newContent.startsWith('[')) {
              // Only validate syntax if content looks like file content
              // Validate file syntax after replacement using the complete file content
              const validationResult = await this.validateFileSyntax(result.uri, newContent);
              
              // If syntax validation fails, reject replacement and rollback
              if (!validationResult.isValid) {
                // Rollback replacement operation
                const rollbackEdit = new vscode.WorkspaceEdit();
                rollbackEdit.replace(result.uri, range, originalText);
                
                const rollbackSuccess = await vscode.workspace.applyEdit(rollbackEdit);
                if (rollbackSuccess) {
                  vscode.window.showErrorMessage(
                    `❌Syntax validation failed: ${validationResult.errorMessage}. Replacement has been rolled back.`,
                    { modal: false }
                  );
                  throw new Error(`Syntax validation failed: ${validationResult.errorMessage}. Replacement has been rolled back.`);
                } else {
                  vscode.window.showErrorMessage(
                    `❌Syntax validation failed: ${validationResult.errorMessage}. Failed to rollback replacement.`,
                    { modal: false }
                  );
                  throw new Error(`Syntax validation failed: ${validationResult.errorMessage}. Failed to rollback replacement.`);
                }
              }
              
              // if success, notification
              if (validationResult.isValid) {
                vscode.window.showInformationMessage(
                  "✅Syntax validation passed - replacement completed successfully",
                  { modal: false }
                );
              }
            }
            
            // Save task ID before cancelling the task
            const taskId = worker.task?.id;
            if (worker.task) {
              worker.cancelTask();
            }
          } catch (editError) {
            console.error(`Error applying replacement:`, editError);
            
            if (editError instanceof Error && !editError.message.includes('Syntax validation failed')) {
              const errorMessage = editError.message;
              vscode.window.showErrorMessage(`Error applying replacement: ${errorMessage}`, { modal: false });
            }
            
            throw editError;
          }
        }
      });
      
      if (worker.task) {
      worker.task.disposable = disposable;
      }
      
      const requestJson = JSON.stringify(request);
      
      await worker.process.stdin.write(requestJson + "\n");
      
    } catch (error: any) {
      // Show detailed error information to user
      const errorMessage = error.message || "Unknown error";
      console.error(`Replace failed:`, error);
      
      // If error message is too long, truncate it to avoid long notifications
      const displayMessage = errorMessage.length > 200 
        ? errorMessage.substring(0, 200) + "..."
        : errorMessage;
      
      vscode.window.showErrorMessage(`Replace failed: ${displayMessage}`, { modal: false });
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
    }
    const files = await vscode.workspace.fs.readDirectory(uri);
    
    
          // Create search tasks for each file without wrapping
    const searchPromises = files.map(async ([name, type]) => {
        const fileUri = vscode.Uri.joinPath(uri, name);
      try {
                  if (type === vscode.FileType.Directory) {
            // Recursively search subdirectories

          await this.searchDirectory(fileUri, options, context);
          
                  } else if (type === vscode.FileType.File) {
            // Search single file
          
          await this.searchFile(fileUri, options, context);
          
        }
      } catch (error) {
        // Continue even if error occurs, don't let the entire search fail
      }
    });
    
          // Wait for all file searches to complete
    
    try {
      await Promise.all(searchPromises);
      
    } catch (error) {
      // Continue even if error occurs, don't let the entire search fail
    }
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
    
    
    // Call searchText directly without wrapping
    await this.searchText(uri, options, text);
    
  }
  private async searchText(uri: vscode.Uri, options: Options & { searchId?: string }, content: string): Promise<void> {
    const contentLines = content.split("\n");

    
        // Check if there are multiple layer queries
    if (options.layers && options.layers.length > 0) {
      // Call multi-layer search directly without wrapping
      
      await this.searchTextWithLayers(uri, options, content, contentLines);
      
    } else {
      // Clear previous results
      this.onClear.fire();
              // Call single-layer search directly without wrapping
      
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
        print_ast: options.enableAstPrint || false, // Set dynamically based on options.enableAstPrint
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
        
        // Process is already started in createWorker, just use the existing promise
        const processPromise = worker.processPromise;
        
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
                // Check if result has range property
                if (!json.result.range) {
                  continue;
                }
                
                // Check if range has start and end properties
                if (!json.result.range.start || !json.result.range.end) {
                  continue;
                }
                
                const startLine = json.result.range.start.row;
                const endLine = json.result.range.end.row;
                const start = new vscode.Position(startLine, json.result.range.start.column);
                const end = new vscode.Position(endLine, json.result.range.end.column);
                const range = new vscode.Range(start, end);
                const id = crypto.randomUUID();
                
                // Safely get context lines with match highlighting markers
                let context: string[] = [];
                try {
                    const startChar = json.result.range.start.column;
                    const endChar = json.result.range.end.column;
                  context = this.getContextLines(contentLines, startLine, endLine, startChar, endChar);
                } catch (e) {
                  // Fallback to empty context
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
                this.onInsert.fire({ ...result, searchId: options.searchId, lines: result.context, context: result.context });
                
              } catch (e) {
                // Continue processing other results, don't interrupt the entire search
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
      
      // For single-layer search, trigger deduplication after all results are added
      if (options.searchId) {
        this.deduplicateResults();
      }
    } catch (e) {
              // Ensure method completion even if error occurs
    }
  }

  private async searchTextWithLayers(uri: vscode.Uri, options: Options & { searchId?: string }, content: string, contentLines: string[]): Promise<void> {
    // Clear previous results to avoid duplicates
    this.onClear.fire();

    // Check if Moonbit cascade search can be used
    if (options.layers && options.layers.length > 0) {
      // Use Moonbit cascade search directly, no testing needed
      await this.executeCascadeSearch(uri, options, content, contentLines);
      
      // Note: executeCascadeSearch internally triggers results via onInsert
      // finished state is now managed by wrap method, no need to set here
          } else {
        // Fallback to single-layer search
      const currentResults = await this.executeSearchQuery(uri, options.query, content, contentLines, options.searchId, "main", options.enableAstPrint);
      for (const result of currentResults) {
        this.results.set(result.id, result);
        this.onInsert.fire({ ...result, searchId: options.searchId, lines: result.context, context: result.context });
      }
      
      // For single-layer search, also trigger deduplication after all results are added
      if (options.searchId) {
        this.deduplicateResults();
      }
    }
  }

      // New: use Moonbit's cascading search
  private async executeCascadeSearch(uri: vscode.Uri, options: Options & { searchId?: string }, content: string, contentLines: string[]): Promise<void> {
    // Prepare layer queries
    const layerQueries = options.layers!
      .filter(layer => layer.enabled && layer.query.trim())
      .map(layer => layer.query);



    // Use Moonbit cascade search functionality
    const request = {
      id: crypto.randomUUID(),
              method: "cascade_search",
      params: {
        content: content,
        mainQuery: options.query,
        layerQueries: layerQueries,
        print_ast: options.enableAstPrint || false, // Set dynamically based on options.enableAstPrint
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
      
      // Process is already started in createWorker, just use the existing promise
      const processPromise = worker.processPromise;

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

          // Handle debug messages
          if (typeof json.result === "string" && json.result.startsWith("DEBUG:")) {
                          // Check if it's a search completion message
            if (json.result.includes("Cascade search completed")) {
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
          
          // Handle search results
          if (json.result && json.result.range) {
            const tsResult = {
              id: crypto.randomUUID(),
            uri: uri,
            range: new vscode.Range(
                json.result.range.start.row,
                json.result.range.start.column,
                json.result.range.end.row,
                json.result.range.end.column
            ),
              captures: json.result.captures || {},
              context: this.getContextLines(
                contentLines, 
                json.result.range.start.row, 
                json.result.range.end.row,
                json.result.range.start.column,
                json.result.range.end.column
              ),
            searchId: options.searchId,
          };

            this.results.set(tsResult.id, tsResult);
            this.onInsert.fire({ ...tsResult, lines: tsResult.context, context: tsResult.context });
          }
        }
      });

      // Send request
      worker.process.stdin.write(JSON.stringify(request) + "\n");
      
      // Set timeout
      const timeoutId = setTimeout(() => {
  
        if (worker.task) {
          worker.task.disposable?.dispose();
          worker.task = undefined;
          this.onAvail.fire();
        }
        disposable?.dispose();
        resolve();
      }, 30000); // 30 second timeout

      // Add extra safety check: if worker.task doesn't exist, resolve immediately
      if (!worker.task) {

        clearTimeout(timeoutId);
          disposable?.dispose();
          resolve();
        }
    });
  }

  // Extract context from line array, keep full lines but mark match ranges
  private getContextLines(contentLines: string[], startRow: number, endRow: number, startColumn?: number, endColumn?: number): string[] {
    // If no column info provided, fallback to original logic
    if (startColumn === undefined || endColumn === undefined) {
      const context: string[] = [];
      for (let i = Math.max(0, startRow - 2); i <= Math.min(contentLines.length - 1, endRow + 2); i++) {
        context.push(contentLines[i]);
      }
      return context;
    }

    // Keep full lines but mark match ranges
    if (startRow === endRow) {
      // Single line match: show full line but mark match range
      const line = contentLines[startRow];
              // Use special markers to identify match ranges, frontend can parse these for highlighting
      const markedLine = `${line.slice(0, startColumn)}[MATCH_START]${line.slice(startColumn, endColumn)}[MATCH_END]${line.slice(endColumn)}`;
      return [markedLine];
          } else {
        // Multi-line match: first line from match start, last line to match end, middle lines complete
      const firstLine = contentLines[startRow];
      const lastLine = contentLines[endRow];
      
      const result = [
          `${firstLine.slice(0, startColumn)}[MATCH_START]${firstLine.slice(startColumn)}`, // First line to match start
          ...contentLines.slice(startRow + 1, endRow), // Middle lines complete
          `${lastLine.slice(0, endColumn)}[MATCH_END]${lastLine.slice(endColumn)}` // Last line from start to match end
        ];

      return result;
    }
  }

  private async executeSearchQuery(uri: vscode.Uri, query: string, content: string, contentLines: string[], searchId?: string, queryType: string = "unknown", enableAstPrint: boolean = false): Promise<Result[]> {
    const request = {
      id: crypto.randomUUID(),
      method: "search",
      params: {
        query: query,
        content: content,
        print_ast: enableAstPrint, // Set dynamically based on enableAstPrint parameter
      },
    };

    return new Promise<Result[]>((resolve) => {
      const results: Result[] = [];
      let hasResolved = false;
      
      // Add timeout mechanism
      const timeout = setTimeout(() => {
        if (!hasResolved) {
          hasResolved = true;

          resolve(results);
        }
              }, 10000); // 10 second timeout
      
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
                  clearTimeout(timeout);
                  worker.cancelTask();
                  resolve(results);
                }
                return;
              }
                
                              // Check if result has range property
                      if (!json.result.range) {
          continue;
        }
                
                              // Check if range has start and end properties
                      if (!json.result.range.start || !json.result.range.end) {
          continue;
        }
                
              const startLine = json.result.range.start.row;
              const endLine = json.result.range.end.row;
              const startColumn = json.result.range.start.column;
              const endColumn = json.result.range.end.column;
              const start = new vscode.Position(startLine, startColumn);
              const end = new vscode.Position(endLine, endColumn);
              const range = new vscode.Range(start, end);
              const id = crypto.randomUUID();
              const result = {
                id,
                uri: uri,
                range: range,
                context: this.getContextLines(contentLines, startLine, endLine, startColumn, endColumn),
                captures: json.result.captures || {},
              };
                
              results.push(result);
            }
          });
            
          worker.task.disposable = disposable;
          await worker.process.stdin.write(JSON.stringify(request) + "\n");
        } catch (error) {

          if (!hasResolved) {
            hasResolved = true;
            clearTimeout(timeout);
            resolve(results);
          }
        }
      };
      
      processResults().catch(error => {

        if (!hasResolved) {
          hasResolved = true;
          clearTimeout(timeout);
          resolve(results);
        }
      });
    });
  }

    private async executeSearchQueryInResults(uri: vscode.Uri, query: string, previousResults: Result[], contentLines: string[], searchId?: string, queryType: string = "unknown"): Promise<Result[]> {
    // If no previous layer results, return empty array
    if (previousResults.length === 0) {
      return [];
    }

    // Collect ranges of all previous layer results
    const searchRanges: vscode.Range[] = [];
    for (const result of previousResults) {
      searchRanges.push(result.range);
    }

    // Merge adjacent ranges to reduce duplicate searches
    const mergedRanges = this.mergeOverlappingRanges(searchRanges);

    // Execute query in each merged range
    const allResults: Result[] = [];
    
    for (const range of mergedRanges) {
      // Extract content from this range
      const startLine = range.start.line;
      const endLine = range.end.line;
      const rangeContent = contentLines.slice(startLine, endLine + 1).join('\n');
      
      // Execute query in this range
              const rangeResults = await this.executeSearchQuery(uri, query, rangeContent, contentLines, searchId, `${queryType}-range-${startLine}-${endLine}`, false);
      
      // Adjust result line numbers to be relative to original file
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
    
    // Sort by start line
    const sortedRanges = [...ranges].sort((a, b) => a.start.line - b.start.line);
    const merged: vscode.Range[] = [];
    
    let current = sortedRanges[0];
    
    for (let i = 1; i < sortedRanges.length; i++) {
      const next = sortedRanges[i];
      
      // If current range overlaps or is adjacent to next range, merge them
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
    // Filter overlapping results: only keep results that appear in both result sets. Main logic of multi-layer queries is intersection
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
          // Check if two results overlap
          // Use simple line range overlap check here
    const range1 = result1.range;
    const range2 = result2.range;
    
          // Check if line ranges overlap
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

  /**
   * Validates Moonbit file syntax using tree-sitter
   */
  public async validateFileSyntax(uri: vscode.Uri, content?: string): Promise<{ isValid: boolean; errorMessage?: string }> {
    try {
      // Only validate .mbt and .moon files
      const fileExtension = uri.fsPath.split('.').pop()?.toLowerCase();
      if (fileExtension !== 'mbt' && fileExtension !== 'moon') {
        return { isValid: true }; // Skip validation for non-MoonBit files
      }
      
      // Get the content to validate
      let contentToValidate: string;
      
      if (content !== undefined) {
        // Use the provided content
        contentToValidate = content;
      } else {
        // Fallback to getting content from active editor or disk
        const activeEditor = vscode.window.activeTextEditor;
        
        if (activeEditor && activeEditor.document.uri.fsPath === uri.fsPath) {
          // Use content from active editor if it's the same file
          contentToValidate = activeEditor.document.getText();
        } else {
          // Fallback to reading from disk if no active editor
          const document = await vscode.workspace.openTextDocument(uri);
          contentToValidate = document.getText();
        }
      }
      
                  // Add content validation: ensure it's not a JSON string
      if (!contentToValidate || contentToValidate.trim() === '') {
        return { isValid: true }; // Skip validation for empty content
      }
      
      // Check if content looks like JSON instead of MoonBit code
      const trimmedContent = contentToValidate.trim();
      if (trimmedContent.startsWith('{') || trimmedContent.startsWith('[')) {
        return { isValid: true }; // Skip validation for JSON content
      }
      
      // Check if content contains typical MoonBit syntax elements
      const hasMoonBitSyntax = /fn\s+\w+|let\s+\w+|if\s+\w+|match\s+\w+|loop\s+\w+|try\s*\{/.test(contentToValidate);
      if (!hasMoonBitSyntax) {
        return { isValid: true }; // Skip validation for non-MoonBit content
      }
      
      // Use tree-sitter to parse the file
      const worker = await this.getWorker();
      
      if (!worker.process.stdin || !worker.process.stdout) {
        return { isValid: false, errorMessage: "Worker process not available" };
      }
      
      // Create a validation request
      const request = {
        id: crypto.randomUUID(),
        method: "validate_file_syntax", // Use the dedicated validation method
        params: {
          content: contentToValidate,
          print_ast: true, // Add print_ast parameter, enable AST printing
        },
      };
      

      
      let buffer = "";
      let disposable: vscode.Disposable | undefined;
      let hasSyntaxError = false;
      let errorMessage = "";
      let hasReceivedResponse = false;
      let resolvePromise: (() => void) | null = null;
      
      disposable = worker.process.stdout.onData(async (data) => {
        
        if (!worker.task) {
          disposable?.dispose();
          return;
        }

        // Decode the data and add to buffer
        const decoded = this.textDecoder.decode(data);
        
        buffer += decoded;
        
        // Check if we have complete lines
        const lines = buffer.split('\n');
        
        // Keep the last line in buffer if it's incomplete
        buffer = lines.pop() || "";
        
        // Process complete lines
        for (const line of lines) {
          if (line.trim() === "") continue;
          
          try {
            const response = JSON.parse(line);
            
            if (response.id === request.id) {
              hasReceivedResponse = true;
              
              if (response.error) {
                hasSyntaxError = true;
                errorMessage = response.error.message || 'Unknown syntax error';
              } else if (response.result !== undefined) {
                
                // Check if result indicates syntax error
                if (response.result === false || response.result === "false" || 
                    (typeof response.result === "string" && response.result.toLowerCase().includes("error"))) {
                  hasSyntaxError = true;
                  errorMessage = String(response.result);
                }
              }
              
              // Clean up and resolve
              disposable?.dispose();
              if (resolvePromise) {
                resolvePromise();
              }
              return;
            }
          } catch (parseError: unknown) {
            // Failed to parse line as JSON, continue to next line
          }
        }
      });
      
      if (worker.task) {
        worker.task.disposable = disposable;
      }
      
      // Send validation request
      const requestJson = JSON.stringify(request);
      
      await worker.process.stdin.write(requestJson + "\n");
      
      // Wait for response with timeout
      await new Promise<void>((resolve, reject) => {
        resolvePromise = resolve;
        
        const timeout = setTimeout(() => {
          if (!hasReceivedResponse) {
            disposable?.dispose();
            reject(new Error("Syntax validation timeout"));
          }
        }, 10000); // 10 second timeout
        
        const checkResponse = () => {
          if (hasReceivedResponse) {
            clearTimeout(timeout);
            resolve();
          } else {
            setTimeout(checkResponse, 100);
          }
        };
        checkResponse();
      });
      
      // Return validation result
      if (hasSyntaxError) {
        // Improve error message to be more user-friendly
        let userFriendlyMessage = errorMessage;
        
        // If error message contains detailed AST info, extract key information
        if (errorMessage.includes('DEBUG:') || errorMessage.includes('=== DETAILED AST INFO ===')) {
          // Extract key error information
          const debugMatch = errorMessage.match(/DEBUG: root_type=(\w+), has_error=(\w+), node_count=(\d+), text_length=(\d+)/);
          if (debugMatch) {
            const [, rootType, hasError, nodeCount, textLength] = debugMatch;
            userFriendlyMessage = `Syntax error detected in MoonBit file. File has ${nodeCount} nodes and ${textLength} characters. Root type: ${rootType}.`;
          } else {
            userFriendlyMessage = "Syntax error detected in MoonBit file. Please check the file for syntax issues.";
          }
        }
        
        return {
          isValid: false,
          errorMessage: userFriendlyMessage
        };
      } else {
        return {
          isValid: true
        };
      }
      
    } catch (error) {
      // Check if the error is related to worker process issues
      if (error && typeof error === 'object' && 'message' in error && 
          typeof error.message === 'string' && (
        error.message.includes('ERR_CONNECTION_CLOSED') ||
        error.message.includes('stdin') ||
        error.message.includes('stdout')
      )) {
        // Mark the current worker as dead to trigger cleanup
        try {
          const worker = await this.getWorker();
          if (worker && worker.id !== undefined) {
            this.markWorkerAsDead(worker.id, -1);
          }
        } catch (workerError) {
          // Worker cleanup failed, continue
        }
      }
      
      // Return error result
      return {
        isValid: false,
        errorMessage: error instanceof Error ? error.message : 'Unknown error during validation'
      };
    }
  }



      // Lightweight persistent storage - only store query info, not specific results
  private async loadPersistedResults() {
          // No longer load specific results, only log
  }

  private async savePersistedResults() {
    // No longer save specific results, only log
  }

  // Add a method to deduplicate results based on text content
  private deduplicateResults(): void {
    const seenTexts = new Set<string>();
    const resultsToRemove: string[] = [];
    
    // Iterate through all results and identify duplicates
    for (const [id, result] of this.results.entries()) {
      // Create a unique text identifier based on content and position
      const textKey = `${result.uri.fsPath}:${result.range.start.line}:${result.range.start.character}:${result.range.end.line}:${result.range.end.character}:${result.context.join('\n')}`;
      
      if (seenTexts.has(textKey)) {
        // This is a duplicate, mark for removal
        resultsToRemove.push(id);
      } else {
        seenTexts.add(textKey);
      }
    }
    
    // Remove duplicate results
    for (const id of resultsToRemove) {
      const result = this.results.get(id);
      if (result) {
        this.results.delete(id);
        this.onRemove.fire({ id, uri: result.uri });
      }
    }
    

  }
}
