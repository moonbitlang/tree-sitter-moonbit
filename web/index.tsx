import * as React from "react";
import * as ReactDOM from "react-dom/client";
import ThemeToggle from "./components/ThemeToggle";

ReactDOM.createRoot(document.getElementById("theme-toggle")!).render(
  <React.StrictMode>
    <ThemeToggle />
  </React.StrictMode>
);
