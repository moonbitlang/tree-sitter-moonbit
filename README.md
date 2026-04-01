# tree-sitter-moonbit

A [tree-sitter][] grammar for [MoonBit](https://www.moonbitlang.com).

This repo contains grammars for MoonBit source/interface files, `moon.pkg`
package configuration files, and MoonBit predicate files (`.mbtp`).

[tree-sitter]: https://github.com/tree-sitter/tree-sitter

## Development notes

- Primary source files: `grammar.js`, `queries/*.scm`, and `test/corpus/*`.
- Generated files: `src/grammar.json`, `src/node-types.json`, `src/parser.c`, and
  `grammars/{mbtp,quotation}/src/{grammar.json,node-types.json,parser.c}` are
  produced by `scripts/generate.py` (see `.github/workflows/test.yml`).
- Avoid editing generated files by hand. Only regenerate when you intend to update
  parser artifacts, and expect large diffs.

### Subgrammars

- `grammar.js`: main MoonBit grammar for `.mbt`, `.mbti`, and `moon.pkg`.
- `grammars/mbtp/grammar.js`: MoonBit predicate grammar for `.mbtp`.
- `grammars/quotation/grammar.js`: quoted MoonBit grammar.

### Downstream repos (core/async)

For development and validating grammar changes, you'll typically want local checkouts of:

- `moonbitlang/core`
- `moonbitlang/async`

CI clones these repos and parses `**/*.mbt` and `**/*.mbti` (see `.github/workflows/test.yml`). If you hit cache lock permission errors locally, set `XDG_CACHE_HOME` (e.g. `XDG_CACHE_HOME=/tmp/xdg-cache`).
