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
      searchService.clear();
    }),
    vscode.commands.registerCommand("moon-grep.collapseAll", () => {
      sidebarWebviewProvider.postMessage({ type: "collapseAll" });
    }),
    vscode.commands.registerCommand("moon-grep.expandAll", () => {
      sidebarWebviewProvider.postMessage({ type: "expandAll" });
    })
  );
}

export function deactivate() {}
