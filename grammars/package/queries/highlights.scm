;; Keywords

[ "import" "as" ] @keyword.import
"for" @keyword.repeat

;; Identifiers

(assign_statement (identifier) @property)
(apply_statement (identifier) @function)
(argument_label (identifier) @property)

;; Package aliases

(package_alias) @module

;; Operators

[ "=" ] @operator

;; Delimiters

[
  ";"
  ","
] @punctuation.delimiter

":" @punctuation.delimiter

[
  "(" ")"
  "{" "}"
  "[" "]"
] @punctuation.bracket

;; Literals

(string_literal) @string
(escape_sequence) @string.escape
(integer_literal) @number
(float_literal) @number.float
(boolean_literal) @boolean

(map_entry (string_literal) @property)

;; Errors

(ERROR) @error
