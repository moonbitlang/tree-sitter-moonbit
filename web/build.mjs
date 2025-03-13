/* eslint-disable */
import fs from "node:fs";
import path from "node:path";
import cp from "node:child_process";
import { env } from "node:process";

const base_path = env["BASE_PATH"];

const index_html = fs
  .readFileSync(path.join("web", "index.html"), "utf-8")
  .replace(/LANGUAGE_BASE_URL = ""/, `LANGUAGE_BASE_URL = "${base_path}"`);

fs.writeFileSync(path.join("web", "index.html"), index_html);

/**
 * @type {Record<string, string>}
 * @description A list of resources to download
 */
const resources = {};

resources[path.join("web", "web-tree-sitter.js")] =
  "https://github.com/tree-sitter/tree-sitter/releases/download/v0.25.3/web-tree-sitter.js";
resources[path.join("web", "tree-sitter.wasm")] =
  "https://github.com/tree-sitter/tree-sitter/releases/download/v0.25.3/web-tree-sitter.wasm";

Object.entries(resources).forEach(([filename, resource]) => {
  fetch(resource)
    .then((response) => response.arrayBuffer())
    .then((arrayBuffer) => {
      fs.writeFileSync(filename, Buffer.from(arrayBuffer));
    });
});

cp.spawnSync("npm", [
  "exec",
  "tree-sitter",
  "--",
  "build",
  "--wasm",
  "--output",
  path.join("web", "tree-sitter-moonbit.wasm"),
]);
