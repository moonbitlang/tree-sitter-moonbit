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

# PR 250 CI Follow-Up: Reverse Range And For-In Loop State

## Goal

Address the remaining PR #250 CI failures in `test-core` and `test-async` after
rebasing onto current `main`.

## Accepted Design

Extend the existing MoonBit grammar in place:

- accept `>=..` as a reverse inclusive range operator beside the already
  supported reverse exclusive `>..` operator, keeping it as one lexical token
  to match the compiler parser;
- extend `for_in_expression` with the same loop-state alternatives as compiler
  `foreach_optional_loop_vars(EXPR)`: empty, `; init`, and `; init ; update`.
  The state binders keep full expression RHSs, matching `for_binders(EXPR)`.

Keep the existing named node surfaces. The new syntax should parse into the
existing `range_expression`, `for_in_expression`, and `for_binder` nodes.

Implementation note: use inline high-precedence lexical tokens for `>..` and
`>=..` so query highlighting can still match the operator strings; model the
for-in loop state tail as one optional `; init_binders` followed by an optional
`; update_binders`, reusing the existing `for_binder` node for both binder
groups. The separators use the existing semicolon token so explicit semicolons
and ASI line breaks both work. This matches the compiler parser shape without
adding dynamic precedence or additional named nodes.

## Target Files And Surfaces

- `grammar.js`: add the `>=..` operator and extend the optional `for-in` loop
  state tail.
- `test/corpus/for.txt`: add corpus coverage for reverse inclusive ranges and
  `for-in` loops with both init and update binders.
- Generated parser artifacts under `src/` and `grammars/quotation/src/` are
  refreshed with `scripts/generate.py`.

## API And Interface Diff

No new named tree-sitter node types are introduced.

Accepted syntax additions:

- `lhs >=.. rhs`
- `for binder in expr; state = init; state = update { ... }`
- `for k, v in expr; state = init; state = update { ... }`
- newline-separated `for ... in expr` loop-state binders accepted via ASI

## Open Questions

None for this follow-up. The failing CI logs point directly at these two grammar
surfaces.

## Next Implementation Step

Refresh generated parser artifacts, extend the `for.txt` corpus, and run the
local/CI-equivalent parse validations.

## Validation Plan

- Run `python3 scripts/generate.py`.
- Run `tree-sitter test`.
- Run `npm run lint`.
- Parse local `~/Workspace/moonbit/core` tracked `.mbt`/`.mbti` files.
- Parse local `~/Workspace/moonbit/async` tracked `.mbt` files.
- Push to #250 and watch GitHub PR checks.

# PR 250 Codex Review Follow-Up: For-In Iterable And ASI

## Goal

Address the two automated Codex review comments on PR #250 without expanding
the scope beyond `for_in_expression`.

## Accepted Design

Restore full expression parsing after `in` in `for_in_expression`, matching the
MoonBit compiler parser's `foreach_header(expr)` behavior. This keeps pipe
expressions such as `for x in xs |> filter() { ... }` valid.

Keep the optional for-in loop-state tail, but allow the first state-binder list
to be empty after an inserted automatic semicolon. This matches the compiler
parser's `series_with_follow` behavior where `for x in xs` followed by a line
break and body `{` does not require a loop-state binder.

## Target Files And Surfaces

- `grammar.js`: change the for-in iterable back to `$._expression` and relax
  the first optional state-binder list from non-empty to optional.
- `test/corpus/for.txt`: add corpus coverage for pipe iterable expressions and
  for-in bodies whose opening brace is on the next line.
- Generated parser artifacts under `src/` and `grammars/quotation/src/` are
  refreshed with `scripts/generate.py`.

## API And Interface Diff

No new named tree-sitter node types are introduced.

Accepted/recovered syntax covered by this follow-up:

- `for x in xs |> filter() { ... }`
- `for x in xs` followed by a newline and `{ ... }`

## Open Questions

None. Both Codex comments were reproduced locally with the current PR head.

## Next Implementation Step

Patch `for_in_expression`, extend the `for.txt` corpus, regenerate artifacts,
and re-run the same PR #250 validation sweep.

## Validation Plan

- Run `python3 scripts/generate.py`.
- Run `tree-sitter test`.
- Run `npm run lint`.
- Parse local `~/Workspace/moonbit/core` tracked `.mbt`/`.mbti` files.
- Parse local `~/Workspace/moonbit/async` tracked `.mbt` files.
- Push to #250 and verify GitHub PR checks.
