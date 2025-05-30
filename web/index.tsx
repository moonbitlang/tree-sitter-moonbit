import * as React from "react";
import * as ReactDOM from "react-dom/client";
import ThemeToggle from "./components/ThemeToggle";

window.addEventListener("DOMContentLoaded", () => {
  ReactDOM.createRoot(document.getElementById("theme-toggle")!).render(
    <React.StrictMode>
      <ThemeToggle />
    </React.StrictMode>
  );
});
