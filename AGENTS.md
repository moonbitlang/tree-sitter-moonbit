# Agent Notes

This repo uses generated parser artifacts. Follow these guidelines:

## Edit manually
- `grammar.js`
- `queries/*.scm`
- `test/corpus/*`
- `README.md`

## Generated (do not edit by hand)
- `src/grammar.json`
- `src/node-types.json`
- `src/parser.c`
- `grammars/quotation/src/grammar.json`
- `grammars/quotation/src/node-types.json`
- `grammars/quotation/src/parser.c`

## Regeneration
- Run `python3 scripts/generate.py` only when you intend to update the generated
  parser artifacts.
- CI runs `scripts/generate.py` (see `.github/workflows/test.yml`), so avoid
  committing generated file updates unless they are explicitly needed.

## Dev dependency repos
CI validates this grammar against the latest `moonbitlang/core` and `moonbitlang/async`
sources (see `.github/workflows/test.yml`). Having local checkouts of those repos is
helpful when iterating on grammar changes and reproducing downstream failures.
