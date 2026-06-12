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
- Generated parser artifacts under `src/` and `grammars/quotation/src/` are
  refreshed only for local validation and intentionally not committed to the PR.

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

# CI Follow-Up: Impl Method `fn` Header

## Goal

Address PR CI failures in `test-core` and `test-async` caused by current
MoonBit code using `impl ... with fn method(...)` syntax.

## Accepted Design

Extend the existing `impl_definition` method header to accept an optional `fn`
token after `with`, matching the already-supported trait method header style.
Keep the existing `impl_definition` node shape and keep the `function_identifier`
node unchanged so highlighting, textobjects, and tags queries continue to work.

Supported impl method header forms after this follow-up:

- Existing: `impl Trait for Type with method(...) { ... }`
- New: `impl Trait for Type with fn method(...) { ... }`
- New with type parameters after `fn`:
  `impl Trait for Type with fn[T] method(...) { ... }`

## Target Files And Surfaces

- `grammar.js`: allow optional `fn` and optional type parameters after `with`
  in `impl_definition`.
- `test/corpus/impl.txt`: add parse coverage for block bodies, external-source
  bodies, visibility/type-parameter combinations, and `fn[T]` method headers.

## API And Interface Diff

No new named tree-sitter node type is introduced. Existing consumers still read
`impl_definition` with a direct `function_identifier` child.

## Open Questions

The failed `fuzz` job appears unrelated to grammar parsing: its log shows the
setup action failing because a `tree-sitter` directory already exists. Re-run CI
after pushing the grammar fix to distinguish transient/action failure from
parser issues.

## Next Implementation Step

Patch `impl_definition`, extend corpus coverage, regenerate locally, and parse
the local `core` and `async` checkouts to confirm the CI failures are gone.

## Validation Plan

- Run `python3 scripts/generate.py`.
- Run `python3 scripts/test.py`.
- Run `npm run lint`.
- Parse local `~/Workspace/moonbit/core/**/*.mbt` and
  `~/Workspace/moonbit/async/**/*.mbt` with the regenerated parser.
