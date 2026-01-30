# Contributing to tree-sitter-moonbit

## Development Workflow

### Generated Files — Do Not Commit

The following files are **auto-generated** by `tree-sitter generate` and should **not** be included in pull requests:

- `src/parser.c`
- `src/grammar.json`
- `src/node-types.json`
- `grammars/quotation/src/parser.c`
- `grammars/quotation/src/grammar.json`
- `grammars/quotation/src/node-types.json`

CI automatically regenerates and commits these files to `main` after PRs are merged.

### What to Include in PRs

Only commit changes to:

- `grammar.js` — the grammar definition
- `queries/*.scm` — syntax highlighting, tags, etc.
- `test/corpus/*.txt` — test cases
- `tree-sitter.json` — configuration
- Documentation files (`README.md`, `AGENTS.md`, etc.)

### Testing Changes

Before submitting a PR:

```bash
# Regenerate the parser (for local testing only)
python3 scripts/generate.py

# Run tests
tree-sitter test

# Test against downstream repos (optional)
git clone https://github.com/moonbitlang/core.git
tree-sitter parse 'core/**/*.mbt' --quiet --stat
```

### Code Style

- Follow existing patterns in `grammar.js`
- Add test cases for new syntax in `test/corpus/`
- Update highlight queries if adding new keywords
