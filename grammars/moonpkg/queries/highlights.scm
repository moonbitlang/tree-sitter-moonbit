; Keywords
"import" @keyword
"for" @keyword
"as" @keyword

; Booleans
(true) @constant.builtin
(false) @constant.builtin

; Literals
(string) @string
(integer) @number

; Package name alias
(package_name) @namespace

; Identifiers
(identifier) @variable

; Labels/Keys
(argument
  label: (identifier) @property)
(argument
  label: (string) @property)
(object_entry
  key: (identifier) @property)
(object_entry
  key: (string) @property)

; Function/Apply names
(apply_statement
  name: (identifier) @function)

; Assignment names
(assign_statement
  name: (identifier) @variable)

; Import paths
(import_item
  path: (string) @string.special)
(import_for_clause
  kind: (string) @string.special)
(import_kind
  kind: (string) @string.special)

; Comments
(line_comment) @comment
(block_comment) @comment

; Punctuation
"=" @operator
":" @punctuation.delimiter
"," @punctuation.delimiter
";" @punctuation.delimiter
"{" @punctuation.bracket
"}" @punctuation.bracket
"[" @punctuation.bracket
"]" @punctuation.bracket
"(" @punctuation.bracket
")" @punctuation.bracket
