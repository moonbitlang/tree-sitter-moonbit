/* eslint-disable */
import http from "http";
import fs from "fs/promises";
import path from "path";
import { fileURLToPath } from "url";

// Get the directory name of the current module
const __dirname = path.dirname(fileURLToPath(import.meta.url));

// MIME types for different file extensions
const MIME_TYPES = {
  ".html": "text/html",
  ".js": "text/javascript",
  ".mjs": "text/javascript",
  ".css": "text/css",
  ".json": "application/json",
  ".png": "image/png",
  ".jpg": "image/jpeg",
  ".gif": "image/gif",
  ".svg": "image/svg+xml",
  ".wasm": "application/wasm",
  ".ico": "image/x-icon",
  ".txt": "text/plain",
};

// Default port
const PORT = process.env.PORT || 8080;

// Create HTTP server
const server = http.createServer(async (req, res) => {
  console.log(`${req.method} ${req.url}`);

  // Get the file path
  let filePath = path.join(__dirname, req.url === "/" ? "index.html" : req.url);

  try {
    // Check if file exists
    const stats = await fs.stat(filePath);

    if (stats.isDirectory()) {
      // If it's a directory, try to serve index.html
      filePath = path.join(filePath, "index.html");
    }

    // Read the file
    const data = await fs.readFile(filePath);

    // Determine content type based on file extension
    const ext = path.extname(filePath);
    const contentType = MIME_TYPES[ext] || "application/octet-stream";

    // Send response
    res.writeHead(200, { "Content-Type": contentType });
    res.end(data);
  } catch (err) {
    // Handle file not found
    if (err.code === "ENOENT") {
      res.writeHead(404, { "Content-Type": "text/plain" });
      res.end("404 Not Found");
      return;
    }

    // Handle other errors
    console.error(err);
    res.writeHead(500, { "Content-Type": "text/plain" });
    res.end("500 Internal Server Error");
  }
});

// Start the server
server.listen(PORT, () => {
  console.log(`Server running at http://localhost:${PORT}/`);
  console.log(`Serving files from: ${path.resolve(__dirname)}`);
});
