declare module "*.wasm" {
  const content: Uint8Array;
  export default content;
}

declare module "*.worker.ts?path" {
  const path: string;
  export default path;
}
