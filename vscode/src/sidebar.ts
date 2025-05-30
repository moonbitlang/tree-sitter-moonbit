import * as vscode from "vscode";
import type * as Search from "./search";
import * as Sidebar from "./sidebar/types";

export class WebviewViewProvider implements vscode.WebviewViewProvider {
  public static readonly viewType = "moon-grep-search";

  private view?: vscode.WebviewView;
  private service: Search.Service;
  private readonly extensionUri: vscode.Uri;

  constructor(extensionUri: vscode.Uri, service: Search.Service) {
    this.extensionUri = extensionUri;
    this.service = service;
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
    this.view = webviewView;

    webviewView.webview.options = {
      enableScripts: true,
      localResourceRoots: [this.extensionUri],
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
      }
    });

    this.service.onInsert.event((result) => {
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
          lines: result.context,
        },
      });
    });

    this.service.onRemove.event(({ id, uri }) => {
      this.postMessage({
        type: "remove",
        result: {
          id,
          uri: vscode.workspace.asRelativePath(uri),
        },
      });
    });

    this.service.onClear.event(() => {
      this.postMessage({
        type: "clear",
      });
    });
  }

  public async postMessage(message: Sidebar.Response) {
    this.view?.webview.postMessage(message);
  }

  private async search(options: Search.Options) {
    try {
      const workspaceFolders = vscode.workspace.workspaceFolders;
      if (!workspaceFolders) {
        vscode.window.showErrorMessage(`Search failed: no workspace folder available`);
        return;
      }
      const promises = workspaceFolders.map((folder) => {
        return this.service.search(folder.uri, options);
      });
      await Promise.all(promises);
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
