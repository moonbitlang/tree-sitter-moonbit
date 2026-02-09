;; Packages

(package_identifier) @module

;; Variables

(value_declaration (lowercase_identifier) @variable)
(qualified_identifier (lowercase_identifier) @variable)
(qualified_identifier (dot_lowercase_identifier) @variable)

;; Constructors

(constructor (uppercase_identifier) @constructor)

;; Constants

(const_declaration (uppercase_identifier) @constant)

;; Types

(qualified_type_identifier) @type

(type_declaration (identifier) @type.definition)
(struct_declaration (identifier) @type.definition)
(enum_declaration (identifier) @type.definition)
(error_type_declaration (identifier) @type.definition)
(trait_declaration (identifier) @type.definition)
(type_alias_targets (identifier) @type.definition)
(type_alias_targets (dot_identifier) @type.definition)
(type_alias_target (identifier) @type.definition)
(trait_alias_targets (identifier) @type.definition)
(trait_alias_targets (dot_identifier) @type.definition)
(trait_alias_target (identifier) @type.definition)

;; Builtin types

((qualified_type_identifier) @type.builtin
 (#any-of? @type.builtin
           "Unit"
           "Bool"
           "Byte"
           "Int16"
           "UInt16"
           "Int"
           "UInt"
           "Int64"
           "UInt64"
           "Float"
           "Double"
           "FixedArray"
           "Array"
           "Bytes"
           "String"
           "Error"
           "Self"))

((qualified_type_identifier) @type.builtin
 (#any-of? @type.builtin
           "Eq"
           "Compare"
           "Hash"
           "Show"
           "Default"
           "ToJson"
           "FromJson"))

;; Fields

(struct_field_declaration (lowercase_identifier) @variable.member)

;; Attributes

(attribute) @attribute

;; Functions

(function_declaration (lowercase_identifier) @function)
(method_declaration (lowercase_identifier) @function.method)
(trait_method_declaration (lowercase_identifier) @function)
(function_alias_targets (lowercase_identifier) @function)
(function_alias_targets (dot_lowercase_identifier) @function)
(function_alias_target (lowercase_identifier) @function)

;; Parameters

(parameter_label (lowercase_identifier) @variable.parameter)
(optional_parameter_label (lowercase_identifier) @variable.parameter)

;; Operators

[
  "=" "->" "!" "?" "+" "::"
] @operator

;; Keywords

(mutability) @keyword.modifier

[
  "struct" "enum" "type" "trait" "typealias" "traitalias"
] @keyword.type

[
  "pub" "priv" "readonly" "all" "open" "extern"
] @keyword.modifier

[
  "let" "const" "as"
] @keyword

[ "package" "import" ] @keyword.import

[ "fn" "impl" "fnalias" ] @keyword.function

"async" @keyword.coroutine

"for" @keyword.repeat

;; Delimiters

[
  ";"
  ","
] @punctuation.delimiter

":" @punctuation.delimiter
"::" @punctuation.delimiter

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
(char_literal) @character

;; Comments

(comment) @comment @spell

;; Errors

(ERROR) @error
