import ESBuild from "esbuild";
import process from "node:process";
import fsp from "node:fs/promises";
import cp from "node:child_process";

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

function treeSitter(
  grammars: { name: string; path: string; outfile: string }[]
): ESBuild.Plugin {
  return {
    name: `tree-sitter`,
    setup(build) {
      build.onStart(async () => {
        for (const { name, path, outfile } of grammars) {
          const process = cp.spawnSync("tree-sitter", ["build", "--wasm"], {
            cwd: path,
          });
          if (process.error) {
            throw process.error;
          }
          if (process.status !== 0) {
            throw new Error(
              `tree-sitter build failed for ${name}: ${process.stderr.toString()}`
            );
          }
          await fsp.copyFile(`${path}/tree-sitter-${name}.wasm`, outfile);
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
    treeSitter([
      {
        name: "moonbit",
        path: "..",
        outfile: "tree-sitter-moonbit.wasm",
      },
      {
        name: "mbtq",
        path: "../mbtq",
        outfile: "tree-sitter-mbtq.wasm",
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
