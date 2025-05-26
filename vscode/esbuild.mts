import ESBuild from "esbuild";
import * as Fs from "node:fs";
import * as Path from "path";
import * as Module from "node:module";
import * as ChildProcess from "node:child_process";

const production = process.argv.includes("--production");
const watch = process.argv.includes("--watch");
const serve = process.argv.includes("--serve");

const esbuildProblemMatcherPlugin: ESBuild.Plugin = {
  name: "esbuild-problem-matcher",

  setup(build) {
    build.onStart(() => {
      console.log("[watch] build started");
    });
    build.onEnd((result) => {
      result.errors.forEach(({ text, location }) => {
        console.error(`✘ [ERROR] ${text}`);
        if (!location) {
          return;
        }
        console.error(`    ${location.file}:${location.line}:${location.column}:`);
      });
      console.log("[watch] build finished");
    });
  },
};

function findOutdir(buildOptions: ESBuild.BuildOptions): string | undefined {
  if (buildOptions.outdir) {
    return buildOptions.outdir;
  } else if (buildOptions.outfile) {
    return Path.dirname(buildOptions.outfile);
  }
  return undefined;
}

const vscodePlugin: ESBuild.Plugin = {
  name: "vscode-plugin",
  setup(build) {
    build.onEnd(async () => {
      const outfile = build.initialOptions.outfile;
      if (!outfile) {
        throw new Error(`Could not find outfile for vscode`);
      }
      const outdir = findOutdir(build.initialOptions);
      if (!outdir) {
        throw new Error(`Could not find outdir for vscode`);
      }
      const packageJSON = JSON.parse(await Fs.promises.readFile("package.json", "utf-8"));
      packageJSON["main"] = Path.relative(outdir, outfile);
      await Fs.promises.writeFile(
        Path.join(outdir, "package.json"),
        JSON.stringify(packageJSON, null, 2),
        "utf-8"
      );
    });
  },
};

const cmakePlugin: ESBuild.Plugin = {
  name: "cmake-plugin",
  setup(build) {
    build.onEnd(async () => {
      await new Promise<void>((resolve, reject) => {
        const process = ChildProcess.spawn("cmake", ["--build", "build"]);
        process.on("close", (code) => {
          if (code === 0) {
            resolve();
          } else {
            reject(new Error(`CMake build failed with code ${code}`));
          }
        });
        process.on("error", (error) => {
          reject(new Error(`CMake build failed with error: ${error.message}`));
        });
      });
      const grepPath = Path.join("build", "grep");
      if (!Fs.existsSync(grepPath)) {
        throw new Error(`Could not find grep executable`);
      }
      const outdir = findOutdir(build.initialOptions);
      if (!outdir) {
        throw new Error(`Could not find outdir for executable`);
      }
      await Fs.promises.copyFile(grepPath, Path.join(outdir, "grep.wasm"));
    });
  },
};

async function webviewCtx(path: string): Promise<ESBuild.BuildContext> {
  return await ESBuild.context({
    entryPoints: [`src/${path}/index.tsx`],
    bundle: true,
    format: "iife",
    minify: production,
    sourcemap: !production,
    sourcesContent: false,
    platform: "browser",
    outfile: `dist/${path}/index.js`,
    logLevel: "silent",
    plugins: [esbuildProblemMatcherPlugin],
    loader: {
      ".ttf": "file",
      ".tsx": "tsx",
      ".jsx": "jsx",
    },
  });
}

async function main() {
  const extensionCtx = await ESBuild.context({
    entryPoints: ["src/extension.ts"],
    bundle: true,
    format: "cjs",
    minify: production,
    sourcemap: !production,
    sourcesContent: false,
    platform: "node",
    outfile: "dist/extension.js",
    external: ["vscode"],
    logLevel: "silent",
    plugins: [esbuildProblemMatcherPlugin, cmakePlugin, vscodePlugin],
    loader: {
      ".html": "text",
      ".wasm": "binary",
      ".worker": "file",
    },
  });
  const sidebarCtx = await webviewCtx("sidebar");

  if (watch) {
    await Promise.all([extensionCtx.watch(), sidebarCtx.watch()]);
    if (serve) {
      const { hosts, port } = await sidebarCtx.serve({
        servedir: "dist/sidebar",
      });
      for (const host of hosts) {
        console.log(`Serving sidebar on http://${host}:${port}`);
      }
    }
  } else {
    await Promise.all([extensionCtx.rebuild(), sidebarCtx.rebuild()]);
    await Promise.all([extensionCtx.dispose(), sidebarCtx.dispose()]);
  }
}

main().catch((e) => {
  console.error(e);
  process.exit(1);
});
