import "@vscode/codicons/dist/codicon.css";
import "./index.css";
import React from "react";
import ReactDOM from "react-dom/client";
import App from "./components/App";

// Wait for DOM to be loaded before rendering
document.addEventListener("DOMContentLoaded", () => {
  const rootElement = document.getElementById("root");

  if (rootElement) {
    // Create root and render app
    const root = ReactDOM.createRoot(rootElement);
    root.render(
      <React.StrictMode>
        <App />
      </React.StrictMode>
    );
  } else {
    console.error("Root element not found");
  }
});
