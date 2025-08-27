import * as vscode from "vscode";
import * as Sidebar from "./sidebar";
import * as Search from "./search";

export async function activate(context: vscode.ExtensionContext) {
  const searchService = new Search.Service(context.extensionUri);
  const sidebarWebviewProvider = new Sidebar.WebviewViewProvider(
    context.extensionUri,
    searchService
  );

  context.subscriptions.push(
    vscode.window.registerWebviewViewProvider(
      Sidebar.WebviewViewProvider.viewType,
      sidebarWebviewProvider
    )
  );

  // Register commands for the view title menu
  context.subscriptions.push(
    vscode.commands.registerCommand("moon-grep.refresh", () => {
      sidebarWebviewProvider.postMessage({ type: "refresh" });
    }),
    vscode.commands.registerCommand("moon-grep.clear", () => {
      sidebarWebviewProvider.postMessage({ type: "clear" });
      searchService.reset();
    }),
    vscode.commands.registerCommand("moon-grep.collapseAll", () => {
      sidebarWebviewProvider.postMessage({ type: "collapseAll" });
    }),
    vscode.commands.registerCommand("moon-grep.expandAll", () => {
      sidebarWebviewProvider.postMessage({ type: "expandAll" });
    }),
    vscode.commands.registerCommand("moon-grep.saveBookmark", () => {
      // This functionality is now integrated in sidebar
      vscode.window.showInformationMessage("Use the Bookmarks tab to save searches!");
    }),
    vscode.commands.registerCommand("moon-grep.clearHistory", () => {
      sidebarWebviewProvider.postMessage({ type: "clearHistory" } as any);
    }),
    vscode.commands.registerCommand("moon-grep.exportResults", () => {
      vscode.window.showInformationMessage("Export feature coming soon!");
    })
  );


}

export function deactivate() {}
