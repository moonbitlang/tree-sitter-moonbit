# tree-sitter-moonbit

A [tree-sitter][] grammar for [MoonBit](https://www.moonbitlang.com).

[tree-sitter]: https://github.com/tree-sitter/tree-sitter

## Development notes

- Primary source files: `grammar.js`, `queries/*.scm`, and `test/corpus/*`.
- Generated files: `src/grammar.json`, `src/node-types.json`, `src/parser.c`, and
  `grammars/quotation/src/{grammar.json,node-types.json,parser.c}` are produced by
  `scripts/generate.py` (see `.github/workflows/test.yml`).
- Avoid editing generated files by hand. Only regenerate when you intend to update
  parser artifacts, and expect large diffs.
