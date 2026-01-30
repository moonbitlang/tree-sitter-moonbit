# Agent Notes

See [CONTRIBUTING.md](CONTRIBUTING.md) for full details. Key rules:

1. **Edit**: `grammar.js`, `queries/*.scm`, `test/corpus/*.txt`
2. **Don't commit**: `src/parser.c`, `src/grammar.json`, `src/node-types.json`, `grammars/quotation/src/*`
3. **Test**: `python3 scripts/generate.py && tree-sitter test`
4. **CI auto-generates** parser files after merge — don't include them in PRs.
