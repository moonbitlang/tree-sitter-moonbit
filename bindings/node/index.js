const root = require("path").join(__dirname, "..", "..");

module.exports =
  typeof process.versions.bun === "string"
    // Support `bun build --compile` by being statically analyzable enough to find the .node file at build-time
    ? require(`../../prebuilds/${process.platform}-${process.arch}/tree-sitter-moonbit.node`)
    : require("node-gyp-build")(root);

try {
  module.exports.nodeTypeInfo = require("../../src/node-types.json");
} catch (_) {}

try {
  module.exports.moonbit_interface.nodeTypeInfo = require("../../grammars/interface/src/node-types.json");
} catch (_) {}

try {
  module.exports.moonbit_package.nodeTypeInfo = require("../../grammars/package/src/node-types.json");
} catch (_) {}
