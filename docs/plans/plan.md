# Conditional Template Writing Operator

## Goal

Support parsing MoonBit's conditional template writing operator `<?`.

## Accepted Design

Reuse the existing `append_expression` tree-sitter node for both unconditional
template writing (`<+`) and conditional template writing (`<?`). This keeps the
syntax tree shape stable while allowing the new operator token.

The conditional `<?` form accepts a simple expression on the left-hand side so
calls such as `logger.info(...) <? { ... }` parse correctly. The existing `<+`
form keeps its current `left_value` left-hand side to avoid expanding unrelated
syntax.

## Target Files And Surfaces

- `grammar.js`: add a `<?` branch to `append_expression` with a simple
  expression left-hand side.
- `src/scanner.c`: allow a line break before `<?` just like `<+` by suppressing
  automatic semicolon insertion.
- `queries/highlights.scm`: classify `<?` as an operator.
- `test/corpus/expression.txt`: add parsing coverage for conditional template
  writing with string, multiline, and object/map literal RHS forms.
- `test/highlight/operator.mbt`: add highlight coverage for `<?`.
- Generated parser artifacts under `src/` and `grammars/quotation/src/` after
  running `scripts/generate.py`.

## API And Interface Diff

No new named tree-sitter node type is introduced. Existing consumers of
`append_expression` continue to see the same node shape for template writing
expressions.

Accepted operator shapes:

- `<+`: `left_value <+ _simple_expression`
- `<?`: `_simple_expression <? _simple_expression`

## Open Questions

`xlog` also uses newer MoonBit syntax such as `pub impl ... with fn ...` that is
outside this change. The validation pass should distinguish remaining parse
errors from `<?` support.

## Next Implementation Step

Update the `<?` grammar branch to accept expression-valued left-hand sides,
refresh corpus tests, then regenerate parser artifacts.

## Validation Plan

- Run `python3 scripts/generate.py`.
- Run `python3 scripts/test.py`.
- Parse the `xlog` project under `~/Workspace/moonbit/log/xlog` and confirm
  `<?` no longer causes parse errors, while recording any unrelated remaining
  errors.
