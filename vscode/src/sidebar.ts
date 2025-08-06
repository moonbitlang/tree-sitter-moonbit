import * as vscode from "vscode";
import type * as Search from "./search";
import * as Sidebar from "./sidebar/types";

// 导入类型
type SearchHistoryItem = Sidebar.SearchHistoryItem;
type SearchBookmark = Sidebar.SearchBookmark;
type SearchLayer = Sidebar.SearchLayer;

// 使用从 types.ts 导入的类型定义

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
  private eventDisposables: vscode.Disposable[] = [];

  constructor(extensionUri: vscode.Uri, service: Search.Service) {
    this.extensionUri = extensionUri;
    this.service = service;
    this.loadHistory();
    this.loadBookmarks();
  }

  dispose() {
    console.log("[SIDEBAR] dispose called", {
      timestamp: Date.now(),
      eventDisposablesCount: this.eventDisposables.length
    });
    // 清理所有事件监听器
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
    console.log("[SIDEBAR] resolveWebviewView called", {
      timestamp: Date.now(),
      eventDisposablesCount: this.eventDisposables.length,
      currentSearchId: this.searchId
    });
    
    // 清理之前的事件监听器
    this.eventDisposables.forEach(disposable => disposable.dispose());
    this.eventDisposables = [];
    
    this.view = webviewView;

    webviewView.webview.options = {
      enableScripts: true,
      localResourceRoots: [this.extensionUri],
      enableForms: true, // 允许表单交互
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
          // The webview will handle the refresh based on the current search pattern
          break;
        }
        case "collapseAll": {
          // The webview will handle collapsing all items
          break;
        }
        case "expandAll": {
          // The webview will handle expanding all items
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
        case "openMatch": {
          this._openMatch(message.value.uri, message.value.range);
          break;
        }
        // 新增的历史记录和书签处理
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
        // 移除 addToHistory 消息处理，历史记录现在完全由后端控制
        // case "addToHistory": {
        //   this.addToHistory(message.value.query, 0, message.value.options);
        //   break;
        // }
      }
    });

    const onInsertDisposable = this.service.onInsert.event((result: any) => {
      console.log("[SIDEBAR] onInsert", { resultId: result.id, resultSearchId: result.searchId, currentSearchId: this.searchId });
      // 只统计本次 searchId 的结果
      if (result.searchId === this.searchId) {
        this.resultCountMap.set(this.searchId, (this.resultCountMap.get(this.searchId) || 0) + 1);
        console.log("[SIDEBAR] resultCountMap", this.resultCountMap.get(this.searchId));
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

    const onSearchFinishedDisposable = this.service.onSearchFinished.event((searchId: any) => {
      console.log("🚀🚀🚀 [SIDEBAR] onSearchFinished triggered 🚀🚀🚀", { 
        searchId, 
        currentSearchId: this.searchId, 
        count: this.resultCountMap.get(searchId),
        hasWrittenHistory: this.hasWrittenHistory,
        currentQuery: this.currentSearchQuery,
        timestamp: Date.now()
      });
      
      // 确保只处理当前搜索的完成事件
      if (searchId !== this.searchId) {
        console.log("[SIDEBAR] Ignoring onSearchFinished for different searchId");
        return;
      }
      
      // 防止重复记录
      if (this.hasWrittenHistory) {
        console.log("[SIDEBAR] History already written, ignoring duplicate onSearchFinished");
        return;
      }
      
      // 确保有查询内容
      if (!this.currentSearchQuery.trim()) {
        console.log("[SIDEBAR] No query content, skipping history");
        this.hasWrittenHistory = true;
        return;
      }
      
      const count = this.resultCountMap.get(searchId) || 0;
      console.log("[SIDEBAR] About to call addToHistory", { 
        query: this.currentSearchQuery, 
        count,
        searchId,
        timestamp: Date.now()
      });
      
      // 获取当前启用的搜索层
      const enabledLayers = this.currentSearchLayers?.filter(layer => layer.enabled && layer.query.trim()) || [];
      
      this.addToHistory(this.currentSearchQuery, count, this.currentSearchOptions, enabledLayers);
      this.hasWrittenHistory = true;
      this.resultCountMap.delete(searchId);
      console.log("[SIDEBAR] addToHistory completed from onSearchFinished", { 
        query: this.currentSearchQuery, 
        count,
        layers: enabledLayers 
      });
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
    console.log('[SIDEBAR] search called', { 
      query: options.query, 
      timestamp: Date.now(),
      currentSearchId: this.searchId,
      hasWrittenHistory: this.hasWrittenHistory
    });
    
    // 检查查询是否为空
    if (!options.query || !options.query.trim()) {
      console.log('[SIDEBAR] Empty query, skipping search');
      return;
    }
    
    const now = Date.now();
    if (now - this.lastSearchTimestamp < 1000) {
      // 1秒内的重复search直接忽略
      console.log('[SIDEBAR] Ignoring duplicate search within 1000ms');
      return;
    }
    this.lastSearchTimestamp = now;
    
    // 生成唯一 searchId（用时间戳+随机数）
    this.searchId = `${Date.now()}_${Math.floor(Math.random() * 1000000)}`;
    console.log("[SIDEBAR] new searchId:", this.searchId);
    this.resultCountMap.set(this.searchId, 0);
    this.currentSearchQuery = options.query || "";
    this.currentSearchOptions = {
      includePattern: options.includePattern,
      excludePattern: options.excludePattern,
      includeIgnored: options.includeIgnored,
    };
    this.currentSearchLayers = (options as any).layers || [];
    this.hasWrittenHistory = false;
    
    console.log("[SIDEBAR] search state initialized", {
      searchId: this.searchId,
      query: this.currentSearchQuery,
      hasWrittenHistory: this.hasWrittenHistory,
      currentHistoryLength: this.searchHistory.length,
      timestamp: Date.now()
    });
    try {
      const workspaceFolders = vscode.workspace.workspaceFolders;
      if (!workspaceFolders) {
        vscode.window.showErrorMessage(`Search failed: no workspace folder available`);
        return;
      }
      // 传递 searchId
      await this.service.search(workspaceFolders[0].uri, { ...options, searchId: this.searchId } as any);
    } catch (error: any) {
      vscode.window.showErrorMessage(`Search failed: ${error.message || "Unknown error"}`);
    }
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

  // 历史记录相关方法
  private loadHistory() {
    const historyData = vscode.workspace.getConfiguration("moon-grep").get("searchHistory", []);
    console.log("[SIDEBAR] loadHistory", {
      loadedHistoryLength: historyData.length,
      timestamp: Date.now()
    });
    this.searchHistory = historyData;
  }

  private saveHistory() {
    console.log("[SIDEBAR] saveHistory called", {
      historyLength: this.searchHistory.length,
      latestItem: this.searchHistory[0],
      timestamp: Date.now()
    });
    vscode.workspace.getConfiguration("moon-grep").update("searchHistory", this.searchHistory, vscode.ConfigurationTarget.Global);
    console.log("[SIDEBAR] saveHistory completed");
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
    console.log("🔥🔥🔥 [SIDEBAR] addToHistory called 🔥🔥🔥", { 
      query, 
      resultCount, 
      options,
      layers,
      stack: new Error().stack,
      timestamp: Date.now()
    });
    
    const historyItem: SearchHistoryItem = {
      id: Date.now().toString(),
      query,
      timestamp: Date.now(),
      resultCount,
      options,
      layers: layers,
    };

    this.searchHistory.unshift(historyItem);
    
    // Keep only last 50 items
    if (this.searchHistory.length > 50) {
      this.searchHistory = this.searchHistory.slice(0, 50);
    }

    this.saveHistory();
    this.postMessage({
      type: "historyUpdated",
      history: this.searchHistory,
    });
    
    console.log("[SIDEBAR] addToHistory completed", { 
      historyLength: this.searchHistory.length,
      latestItem: this.searchHistory[0]
    });
  }

  // 书签相关方法
  private loadBookmarks() {
    const bookmarksData = vscode.workspace.getConfiguration("moon-grep").get("bookmarks", []);
    this.bookmarks = bookmarksData;
  }

  private saveBookmarks() {
    vscode.workspace.getConfiguration("moon-grep").update("bookmarks", this.bookmarks, vscode.ConfigurationTarget.Global);
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
