import { Request } from "../types";

// Declare the vscode API
declare const acquireVsCodeApi: () => {
  postMessage: (message: Request) => void;
  getState: () => any;
  setState: (state: any) => void;
};

const vscode = acquireVsCodeApi();

// Hook for VSCode API communication
export function useVSCode() {
  return vscode;
}
