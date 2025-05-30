import ESBuild from "esbuild";
import process from "node:process";
import fsp from "node:fs/promises";

function downloadAssets(
  assets: { url: string; outfile: string }[]
): ESBuild.Plugin {
  return {
    name: "download-assets",
    setup(build) {
      build.onStart(async () => {
        for (const { url, outfile } of assets) {
          const res = await fetch(url);
          if (!res.ok) throw new Error(`Failed to fetch ${url}`);
          const arrayBuffer = await res.arrayBuffer();
          await fsp.writeFile(outfile, Buffer.from(arrayBuffer));
        }
      });
    },
  };
}

function copyAssets(
  assets: { path: string; outfile: string }[]
): ESBuild.Plugin {
  return {
    name: "copy-assets",
    setup(build) {
      build.onStart(async () => {
        for (const { path, outfile } of assets) {
          await fsp.copyFile(path, outfile);
        }
      });
    },
  };
}

const context = await ESBuild.context({
  entryPoints: ["index.tsx"],
  bundle: true,
  outfile: "index.js",
  plugins: [
    downloadAssets([
      {
        url: "https://github.com/tree-sitter/tree-sitter/releases/download/v0.25.3/web-tree-sitter.js",
        outfile: "web-tree-sitter.js",
      },
      {
        url: "https://github.com/tree-sitter/tree-sitter/releases/download/v0.25.3/web-tree-sitter.wasm",
        outfile: "tree-sitter.wasm",
      },
    ]),
    copyAssets([
      {
        path: "../tree-sitter-moonbit.wasm",
        outfile: "tree-sitter-moonbit.wasm",
      },
    ]),
  ],
});

if (process.argv.includes("--watch")) {
  await context.watch();
} else if (!process.argv.includes("--serve")) {
  await context.rebuild();
  context.dispose();
}

if (process.argv.includes("--serve")) {
  const { hosts, port } = await context.serve({
    servedir: ".",
  });
  for (const host of hosts) {
    console.log(`Serving at http://${host}:${port}`);
  }
}
