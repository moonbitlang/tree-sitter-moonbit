import * as vscode from "vscode";
import type * as Search from "./search";
import * as Sidebar from "./sidebar/types";

// Import types
type SearchHistoryItem = Sidebar.SearchHistoryItem;
type SearchBookmark = Sidebar.SearchBookmark;
type SearchLayer = Sidebar.SearchLayer;

// Use type definitions imported from types.ts

export class WebviewViewProvider implements vscode.WebviewViewProvider {
  public static readonly viewType = "moon-grep-search";

  private view?: vscode.WebviewView;
  private service: Search.Service;
  private readonly extensionUri: vscode.Uri;
  private searchHistory: SearchHistoryItem[] = [];
  private bookmarks: SearchBookmark[] = [];
  private searchId: string = "";
  private resultCountMap: Map<string, number> = new Map();
  private hasWrittenHistory: boolean = false;
  private currentSearchQuery: string = "";
  private currentSearchOptions: any = {};
  private currentSearchLayers: SearchLayer[] = [];
  private lastSearchTimestamp: number = 0;
  private isReplaceAllInProgress: boolean = false;
  private eventDisposables: vscode.Disposable[] = [];

  constructor(extensionUri: vscode.Uri, service: Search.Service) {
    this.extensionUri = extensionUri;
    this.service = service;
    this.loadHistory();
    this.loadBookmarks();
  }

  dispose() {
    this.eventDisposables.forEach(disposable => disposable.dispose());
    this.eventDisposables = [];
  }

  private static getNonce() {
    let text = "";
    const possible = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (let i = 0; i < 32; i++) {
      text += possible.charAt(Math.floor(Math.random() * possible.length));
    }
    return text;
  }

  private onDidReceiveMessage(listener: (message: Sidebar.Request) => Promise<void> | void) {
    this.view?.webview.onDidReceiveMessage(listener);
  }

  public resolveWebviewView(
    webviewView: vscode.WebviewView,
    _context: vscode.WebviewViewResolveContext,
    _token: vscode.CancellationToken
  ) {
    this.eventDisposables.forEach(disposable => disposable.dispose());
    this.eventDisposables = [];
    
    this.view = webviewView;

    webviewView.webview.options = {
      enableScripts: true,
      localResourceRoots: [this.extensionUri],
              enableForms: true, // Allow form interaction
    };

    webviewView.webview.html = this.getHtmlForWebview(webviewView.webview);

    this.onDidReceiveMessage(async (message) => {
      switch (message.type) {
        case "search": {
          await this.search(message.value);
          break;
        }
        case "clear": {
          this.service.reset();
          break;
        }
        case "refresh": {
          break;
        }
        case "collapseAll": {
          break;
        }
        case "expandAll": {
          break;
        }
        case "dismissMatch": {
          this.service.dismiss(message.value.id);
          break;
        }
        case "replaceMatch": {
          this.service.replace(message.value.id, message.value.replace);
          break;
        }
        case "replaceAll": {
          // Get current result count
          const resultCount = this.service.getResultCount();
          if (resultCount === 0) {
            vscode.window.showInformationMessage("No search results to replace");
            break;
          }
          
          // Show confirmation dialog
          const confirmMessage = `Replace ${resultCount} occurrence${resultCount > 1 ? 's' : ''}?`;
          const confirmReplace = await vscode.window.showInformationMessage(
            confirmMessage,
            { modal: true },
            "Replace All"
          );
          
          if (confirmReplace !== "Replace All") {
            break;
          }
          
          try {
            // Set flag to indicate replaceAll operation is in progress
            this.isReplaceAllInProgress = true;
            
            // Get all result IDs and replace them one by one
            const resultIds = this.service.getResultIds();
            
            // Replace all results sequentially to avoid conflicts
            for (const resultId of resultIds) {
              try {
                await this.service.replace(resultId, message.value.replace);
              } catch (replaceError: any) {
                // Continue with other results even if one fails
              }
            }
            
            vscode.window.showInformationMessage(`ReplaceAll operation completed for ${resultCount} occurrence${resultCount > 1 ? 's' : ''}`);
            
            // Trigger re-search after replaceAll operation completes
            await this.triggerReSearch();
            
          } catch (error: any) {
            vscode.window.showErrorMessage(`ReplaceAll failed: ${error.message || "Unknown error"}`);
          }
          break;
        }
        case "openMatch": {
          this._openMatch(message.value.uri, message.value.range);
          break;
        }

        case "loadHistory": {
          this.postMessage({
            type: "historyLoaded",
            history: this.searchHistory,
          });
          break;
        }
        case "clearHistory": {
          this.clearHistory();
          break;
        }
        case "deleteHistoryItem": {
          this.deleteHistoryItem(message.value.id);
          break;
        }
        case "loadBookmarks": {
          this.postMessage({
            type: "bookmarksLoaded",
            bookmarks: this.bookmarks,
          });
          break;
        }
        case "addBookmark": {
          this.addBookmark(message.value.name, message.value.query, message.value.options, message.value.layers);
          break;
        }
        case "deleteBookmark": {
          this.deleteBookmark(message.value.id);
          break;
        }
        case "updateResultCount": {
          // Update the result count for the specified search ID
          this.resultCountMap.set(message.value.searchId, message.value.count);
          break;
        }
        
      }
    });

    const onInsertDisposable = this.service.onInsert.event((result: any) => {
              // Only count results for current searchId
      if (result.searchId === this.searchId) {
        const currentCount = this.resultCountMap.get(this.searchId) || 0;
        this.resultCountMap.set(this.searchId, currentCount + 1);

      }
      this.postMessage({
        type: "insert",
        result: {
          id: result.id,
          uri: vscode.workspace.asRelativePath(result.uri),
          range: {
            start: {
              line: result.range.start.line,
              character: result.range.start.character,
            },
            end: {
              line: result.range.end.line,
              character: result.range.end.character,
            },
          },
          lines: result.lines || result.context || [],
        },
      });
    });
    this.eventDisposables.push(onInsertDisposable);

    const onRemoveDisposable = this.service.onRemove.event(({ id, uri }) => {
      this.postMessage({
        type: "remove",
        result: {
          id,
          uri: vscode.workspace.asRelativePath(uri),
        },
      });
    });
    this.eventDisposables.push(onRemoveDisposable);

    const onReplaceDisposable = this.service.onReplace.event(() => {
      // Only trigger re-search for individual replace operations, not during replaceAll
      if (!this.isReplaceAllInProgress) {
        this.triggerReSearch();
      }
    });
    this.eventDisposables.push(onReplaceDisposable);

    const onSearchFinishedDisposable = this.service.onSearchFinished.event((searchId: any) => {

      
              // Ensure only current search completion events are processed
      if (searchId !== this.searchId) {

        return;
      }
      
      // Prevent duplicate records
      if (this.hasWrittenHistory) {

        return;
      }
      
              // Ensure there is query content
      if (!this.currentSearchQuery.trim()) {

        this.hasWrittenHistory = true;
        return;
      }
      
      // Use the actual result count from the service instead of the map
      // This ensures we get the accurate count after deduplication
      const count = this.service.getResultCount();

      
              // Get currently enabled search layers
      const enabledLayers = this.currentSearchLayers?.filter(layer => layer.enabled && layer.query.trim()) || [];
      
      this.addToHistory(this.currentSearchQuery, count, this.currentSearchOptions, enabledLayers);
      this.hasWrittenHistory = true;
      this.resultCountMap.delete(searchId);
    });
    this.eventDisposables.push(onSearchFinishedDisposable);
    const onClearDisposable = this.service.onClear.event(() => {
      this.postMessage({
        type: "clear",
      });
    });
    this.eventDisposables.push(onClearDisposable);
  }

  public async postMessage(message: Sidebar.Response) {
    this.view?.webview.postMessage(message);
  }

  private async search(options: Search.Options) {
            // Check if query is empty
    if (!options.query || !options.query.trim()) {

      return;
    }
    
    const now = Date.now();
    if (now - this.lastSearchTimestamp < 1000) {
      // Ignore duplicate searches within 1 second

      return;
    }
    this.lastSearchTimestamp = now;
    
            // Generate unique searchId (timestamp + random number)
    this.searchId = `${Date.now()}_${Math.floor(Math.random() * 1000000)}`;
    this.resultCountMap.set(this.searchId, 0);
    this.currentSearchQuery = options.query || "";
    this.currentSearchOptions = {
      includePattern: options.includePattern,
      excludePattern: options.excludePattern,
      includeIgnored: options.includeIgnored,
    };
    this.currentSearchLayers = (options as any).layers || [];
    this.hasWrittenHistory = false;
    
    // Notify frontend of the new search ID
    this.postMessage({
      type: "searchStarted",
      searchId: this.searchId,
    });

    try {
      const workspaceFolders = vscode.workspace.workspaceFolders;
      if (!workspaceFolders) {
        vscode.window.showErrorMessage(`Search failed: no workspace folder available`);
        return;
      }
      // Pass searchId
      await this.service.search(workspaceFolders[0].uri, { ...options, searchId: this.searchId } as any);
      
    } catch (error: any) {
      vscode.window.showErrorMessage(`Search failed: ${error.message || "Unknown error"}`);
    }
  }

  private async triggerReSearch() {
    // Check if we have a current search query to re-run
    if (!this.currentSearchQuery || !this.currentSearchQuery.trim()) {
      return;
    }
    
    // Create search options for re-search
    const searchOptions: Search.Options = {
      query: this.currentSearchQuery,
      ...this.currentSearchOptions,
      layers: this.currentSearchLayers,
    };

    // Trigger the search
    await this.search(searchOptions);
  }

  private _openMatch(file: string, range: Sidebar.Range) {
    const workspaceFolder = vscode.workspace.workspaceFolders?.[0];
    if (!workspaceFolder) {
      return;
    }
    const fileUri = vscode.Uri.joinPath(workspaceFolder.uri, file);

    vscode.window.showTextDocument(fileUri, {
      selection: new vscode.Range(
        new vscode.Position(range.start.line, range.start.character),
        new vscode.Position(range.end.line, range.end.character)
      ),
    });
  }

  private loadHistory() {
    const historyData = vscode.workspace.getConfiguration("moon-grep").get("searchHistory", []);
    this.searchHistory = historyData;
  }

  private saveHistory() {
    vscode.workspace.getConfiguration("moon-grep").update("searchHistory", this.searchHistory, vscode.ConfigurationTarget.Workspace);
  }

  private clearHistory() {
    this.searchHistory = [];
    this.saveHistory();
    this.postMessage({
      type: "historyUpdated",
      history: this.searchHistory,
    });
  }

  private deleteHistoryItem(id: string) {
    this.searchHistory = this.searchHistory.filter(item => item.id !== id);
    this.saveHistory();
    this.postMessage({
      type: "historyUpdated",
      history: this.searchHistory,
    });
  }

  public addToHistory(query: string, resultCount: number, options: any, layers?: any[]) {
    
    
    const historyItem: SearchHistoryItem = {
      id: Date.now().toString(),
      query,
      timestamp: Date.now(),
      resultCount,
      options,
      layers: layers,
    };

    this.searchHistory.unshift(historyItem);
    
    
    if (this.searchHistory.length > 50) {
      this.searchHistory = this.searchHistory.slice(0, 50);
    }

    this.saveHistory();
    
    
    this.postMessage({
      type: "historyUpdated",
      history: this.searchHistory,
    });
    
  }


  private loadBookmarks() {
    const bookmarksData = vscode.workspace.getConfiguration("moon-grep").get("bookmarks", []);
    this.bookmarks = bookmarksData;
  }

  private saveBookmarks() {

    vscode.workspace.getConfiguration("moon-grep").update("bookmarks", this.bookmarks, vscode.ConfigurationTarget.Workspace);
  }

  private addBookmark(name: string, query: string, options: any, layers?: any[]) {
    const bookmark: SearchBookmark = {
      id: Date.now().toString(),
      name,
      query,
      timestamp: Date.now(),
      options,
      layers: layers,
    };

    this.bookmarks.unshift(bookmark);
    this.saveBookmarks();
    this.postMessage({
      type: "bookmarksUpdated",
      bookmarks: this.bookmarks,
    });
  }

  private deleteBookmark(id: string) {
    this.bookmarks = this.bookmarks.filter(bookmark => bookmark.id !== id);
    this.saveBookmarks();
    this.postMessage({
      type: "bookmarksUpdated",
      bookmarks: this.bookmarks,
    });
  }

  private getHtmlForWebview(webview: vscode.Webview): string {
    const nonce = WebviewViewProvider.getNonce();

    const scriptUri = webview.asWebviewUri(
      vscode.Uri.joinPath(this.extensionUri, "sidebar", "index.js")
    );
    const styleUri = webview.asWebviewUri(
      vscode.Uri.joinPath(this.extensionUri, "sidebar", "index.css")
    );

    const cspSource = webview.cspSource;

    return `<!doctype html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta
      http-equiv="Content-Security-Policy"
      content="default-src 'none'; style-src ${cspSource} 'nonce-${nonce}'; script-src 'nonce-${nonce}'; font-src ${cspSource};"
    />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link rel="stylesheet" href="${styleUri}" nonce="${nonce}" />
    <script nonce="${nonce}" src="${scriptUri}"></script>
    <title>Moon Grep Search</title>
  </head>
  <body>
    <div id="root"></div>
  </body>
</html>`;
  }
}
