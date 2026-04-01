;; Declarations

(predicate_definition name: (lowercase_identifier) @function)
(logic_function_definition name: (lowercase_identifier) @function)
(logic_function_definition receiver: (uppercase_identifier) @type)
(lemma_definition name: (lowercase_identifier) @function)

;; Parameters and binders

(mbtp_parameter name: (lowercase_identifier) @variable.parameter)
(mbtp_where_field name: (lowercase_identifier) @label)
(mbtp_quantified_term binder: (lowercase_identifier) @variable.parameter)
(mbtp_arrow_parameter (lowercase_identifier) @variable.parameter)
(mbtp_parameter_decl (lowercase_identifier) @variable.parameter)

;; Identifiers and types

(mbtp_identifier_expression (mbtp_value_path (identifier (lowercase_identifier)) @variable))
(mbtp_identifier_expression (mbtp_value_path (identifier (uppercase_identifier)) @constant))
(mbtp_pattern_constructor (uppercase_identifier) @constructor)
(mbtp_pattern_constructor (dot_uppercase_identifier) @constructor)
(mbtp_type_path (identifier) @type)

;; Keywords and operators

[
  "predicate"
  "lemma"
  "where"
  "proof_assert"
  "fn"
] @keyword.function

[
  "if"
  "else"
  "match"
] @keyword.conditional

[
  "pub"
] @keyword.modifier

[
  "∀"
  "∃"
  "→"
  "=>"
  "->"
  "!"
  "+"
  "-"
  "*"
  "/"
  "%"
  "<"
  "<="
  ">"
  ">="
  "<<"
  ">>"
  "=="
  "!="
  "&&"
  "||"
  "&"
  "^"
  "|"
] @operator

[
  "(" ")"
  "{"
  "}"
  "["
  "]"
] @punctuation.bracket

[
  ","
  ":"
  "::"
  ";"
] @punctuation.delimiter

;; Literals and comments

(string_literal) @string
(integer_literal) @number
(float_literal) @number.float
(double_literal) @number.float
(boolean_literal) @boolean
(char_literal) @character
(comment) @comment @spell
(block_comment) @comment @spell
