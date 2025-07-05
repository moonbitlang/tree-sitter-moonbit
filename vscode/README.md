# moon-grep README

## Build

Download wasi-sdk-25 from the release page of the
[WebAssembly/wasi-sdk](https://github.com/WebAssembly/wasi-sdk/releases/tag/wasi-sdk-25)
and extract it to `wasi-sdk` directory.

Then run the following commands in the terminal:

```bash
cmake -Bbuild -DCMAKE_TOOLCHAIN_FILE=wasi-sdk/share/cmake/wasi-sdk.cmake
cmake --build build
```

## VSCode Extension

Before you begin, make sure your VSCode is opened in the `vscode/` directory.

First, install npm dependencies:

```bash
npm install
```

Then, run the following command to start a watch build of the extension:

```bash
npm run watch
```

Finally, open the "Run and Debug" view in VSCode and run the "Launch Extension"
configuration to start the extension in a new VSCode window.
