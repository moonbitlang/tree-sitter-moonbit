/**
 * @file Tree-sitter grammar for MoonBit Interface
 * @author Haoxiang Fei <feihaoxiang@idea.edu.cn>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

/**
 *
 * @param {RuleOrLiteral} separator
 * @param {Rule} rule
 * @returns {SeqRule}
 */
function list1(separator, rule) {
  return seq(rule, repeat(seq(separator, rule)), optional(separator));
}

/**
 * @param {RuleOrLiteral} separator
 * @param {Rule} rule
 * @returns {Rule}
 */
function list(separator, rule) {
  return optional(list1(separator, rule));
}

const TYPE_PREC = {
  option: 19,
  error: 18,
  arrow: 17,
};

module.exports = grammar({
  name: "moonbit_interface",

  extras: ($) => [$.comment, /\s/],

  rules: {
    signature: ($) => list($.semicolon, $.signature_item),

    signature_item: ($) =>
      choice(
        $.package_declaration,
        $.import_declaration,
        $.function_declaration,
        $.function_alias_declaration,
        $.method_declarations,
        $.impl_for_type_declaration,
        $.default_impl_declaration,
        $.value_declaration,
        $.const_declaration,
        $.type_declaration,
        $.struct_declaration,
        $.enum_declaration,
        $.error_type_declaration,
        $.type_alias_declaration,
        $.trait_declaration,
        $.trait_alias_declaration
      ),

    comment: (_) => /\/\/[^\n]*/,

    semicolon: (_) => choice("\n", "\0", ";"),

    boolean_literal: (_) => choice("true", "false"),

    integer_literal: (_) =>
      token(
        choice(
          /[0-9][0-9_]*(UL|U|L|N)?/,
          /0[xX][0-9a-fA-F_]+(UL|U|L|N)?/,
          /0[oO][0-7_]+(UL|U|L|N)?/,
          /0[bB][01_]+(UL|U|L|N)?/
        )
      ),

    float_literal: (_) =>
      token(
        choice(
          /0\.[0-9_]*([eE][+-]?[0-9_]*)?/,
          /0[0-9_]+\.[0-9_]*([eE][+-]?[0-9_]*)?/,
          /0[xX][0-9a-fA-F_]*\.[0-9a-fA-F_]*([pP][+-]?[0-9a-fA-F_]*)?/,
          /[1-9][0-9_]*\.[0-9_]*([eE][+-]?[0-9_]*)?/
        )
      ),

    byte_literal: ($) =>
      seq("b'", choice($.escape_sequence, token.immediate(/[^']/)), "'"),

    char_literal: ($) =>
      seq("'", choice($.escape_sequence, token.immediate(/[^']/)), "'"),

    string_literal: ($) => seq('"', repeat($.string_fragment), '"'),

    bytes_literal: ($) => seq('b"', repeat($.string_fragment), '"'),

    string_fragment: ($) =>
      choice($.unescaped_string_fragment, $.escape_sequence),

    unescaped_string_fragment: (_) =>
      choice(
        token.immediate(prec(1, /\\[^ntbr'"\\{]/)),
        token.immediate(prec(1, /[^"\\]+/))
      ),

    escape_sequence: (_) =>
      choice(
        // \n, \t, \b, \r, \", \\
        token.immediate(/\\[ntbr'"\\]/),
        // octal
        token.immediate(/\\o[0-7]{1,3}/),
        // hex
        token.immediate(/\\x[0-9a-fA-F]{1,2}/),
        token.immediate(/\\x\{[0-9a-fA-F]+\}/),
        // unicode
        token.immediate(/\\u[0-9a-fA-F]{4}/),
        token.immediate(/\\u\{[0-9a-fA-F]+\}/)
      ),

    literal: ($) =>
      choice(
        $.boolean_literal,
        $.float_literal,
        seq("-", $.float_literal),
        $.integer_literal,
        seq("-", $.integer_literal),
        $.byte_literal,
        $.char_literal,
        $.string_literal,
        $.bytes_literal
      ),

    uppercase_identifier: (_) => /[\p{Uppercase_Letter}][_\p{XID_Continue}]*/v,

    lowercase_identifier: (_) =>
      /[_[\p{XID_Start}--\p{Uppercase_Letter}]][_\p{XID_Continue}]*/v,

    identifier: ($) => choice($.uppercase_identifier, $.lowercase_identifier),

    dot_lowercase_identifier: (_) =>
      /\.[_[\p{XID_Start}--\p{Uppercase_Letter}]][_\p{XID_Continue}]*/v,

    dot_uppercase_identifier: (_) =>
      /\.[\p{Uppercase_Letter}][_\p{XID_Continue}]*/v,

    dot_identifier: ($) =>
      choice($.dot_lowercase_identifier, $.dot_uppercase_identifier),

    package_identifier: (_) => /@[_\p{XID_Start}\/][_\p{XID_Continue}\/]*/v,

    qualified_identifier: ($) =>
      choice(
        $.lowercase_identifier,
        seq($.package_identifier, $.dot_lowercase_identifier)
      ),

    qualified_type_identifier: ($) =>
      choice($.identifier, seq($.package_identifier, $.dot_identifier)),

    package_declaration: ($) => seq("package", $.string_literal),

    import_declaration: ($) =>
      seq(
        "import",
        choice(
          $.string_literal,
          seq("(", list($.semicolon, $.string_literal), ")")
        )
      ),

    tuple_type: ($) => seq("(", list(",", $.type), ")"),

    function_type: ($) =>
      prec.right(
        TYPE_PREC.arrow,
        seq(optional("async"), "(", list(",", $.type), ")", $.return_type)
      ),

    apply_type: ($) => seq($.qualified_type_identifier, $.type_arguments),

    option_type: ($) => prec(TYPE_PREC.option, seq($.type, "?")),

    trait_object_type: ($) => seq("&", $.type),

    type: ($) =>
      choice(
        $.qualified_type_identifier,
        $.tuple_type,
        $.function_type,
        $.apply_type,
        $.option_type,
        $.trait_object_type
      ),

    type_arguments: ($) => seq("[", list1(",", $.type), "]"),

    type_name: ($) =>
      choice(
        $.qualified_type_identifier,
        seq("&", $.qualified_type_identifier)
      ),

    type_constraints: ($) => list1("+", $.type_constraint),

    type_constraint: ($) => $.qualified_type_identifier,

    type_parameter: ($) =>
      choice($.identifier, seq($.identifier, ":", $.type_constraints)),

    type_parameters: ($) => seq("[", list1(",", $.type_parameter), "]"),

    attribute_properties: ($) => seq("(", list(",", $.attribute_property), ")"),

    attribute_property: ($) =>
      choice(
        seq($.lowercase_identifier, "=", $.attribute_expression),
        $.attribute_expression
      ),

    attribute_expression: ($) =>
      choice(
        $.lowercase_identifier,
        seq($.lowercase_identifier, $.dot_lowercase_identifier),
        seq($.lowercase_identifier, $.attribute_properties),
        seq(
          $.lowercase_identifier,
          $.dot_lowercase_identifier,
          $.attribute_properties
        ),
        $.string_literal
      ),

    attribute: ($) => seq("#", $.attribute_expression),

    attributes: ($) => repeat1($.attribute),

    type_with_error: ($) =>
      prec(TYPE_PREC.error, seq($.type, "!", optional($.type))),

    return_type: ($) => seq("->", choice($.type, $.type_with_error)),

    pub_attribute: (_) => seq("(", choice("readonly", "all", "open"), ")"),

    visibility: ($) => choice("priv", seq("pub", optional($.pub_attribute))),

    mutability: (_) => "mut",

    type_annotation: ($) => seq(":", $.type),

    function_positional_parameter_identifier: ($) => $.uppercase_identifier,

    function_positional_parameter_qualified_type_identifier: ($) =>
      choice(
        alias($.function_positional_parameter_identifier, $.identifier),
        seq($.package_identifier, $.dot_identifier)
      ),

    function_positional_parameter_option_type: ($) =>
      prec(
        TYPE_PREC.option,
        seq(alias($.function_positional_parameter, $.type), "?")
      ),

    function_positional_parameter: ($) =>
      choice(
        alias(
          $.function_positional_parameter_qualified_type_identifier,
          $.qualified_type_identifier
        ),
        $.tuple_type,
        $.function_type,
        $.apply_type,
        alias($.function_positional_parameter_option_type, $.option_type),
        $.trait_object_type
      ),

    default_value: (_) => seq("=", choice("..", "_")),

    parameter_label: ($) => seq($.lowercase_identifier, "~"),

    optional_parameter_label: ($) => seq($.lowercase_identifier, "?"),

    function_labeled_parameter: ($) =>
      seq($.parameter_label, $.type_annotation, optional($.default_value)),

    function_optional_parameter: ($) =>
      seq($.optional_parameter_label, $.type_annotation),

    function_parameter_option_type: ($) =>
      prec(TYPE_PREC.option, seq($.lowercase_identifier, "?")),

    function_parameter_type: ($) =>
      choice(alias($.function_parameter_option_type, $.option_type)),

    function_parameter: ($) =>
      choice(
        $.lowercase_identifier,
        alias($.function_parameter_type, $.type),
        alias($.function_positional_parameter, $.type),
        $.function_labeled_parameter,
        $.function_optional_parameter
      ),

    function_parameters: ($) => seq("(", list(",", $.function_parameter), ")"),

    function_declaration: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        optional("async"),
        "fn",
        $.lowercase_identifier,
        optional("!"),
        optional($.type_parameters),
        optional($.function_parameters),
        optional($.return_type)
      ),

    function_alias_target: ($) =>
      choice(
        $.lowercase_identifier,
        seq($.lowercase_identifier, "as", $.lowercase_identifier)
      ),

    function_alias_targets: ($) =>
      choice(
        seq($.lowercase_identifier, "=", $.qualified_identifier),
        $.function_alias_target,
        seq($.package_identifier, $.dot_lowercase_identifier),
        seq(
          $.package_identifier,
          $.dot_lowercase_identifier,
          "as",
          $.lowercase_identifier
        ),
        seq("(", list1(",", $.function_alias_target), ")"),
        seq($.package_identifier, ".(", list(",", $.function_alias_target), ")")
      ),

    function_alias_declaration: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        "fnalias",
        $.function_alias_targets
      ),

    method_declaration: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        optional("async"),
        $.lowercase_identifier,
        optional("!"),
        optional($.type_parameters),
        optional($.function_parameters),
        optional($.return_type)
      ),

    method_declarations: ($) =>
      seq(
        "impl",
        $.type_name,
        "{",
        list($.semicolon, $.method_declaration),
        "}"
      ),

    impl_for_type_declaration: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        "impl",
        optional($.type_parameters),
        $.type_name,
        "for",
        $.type
      ),

    function_identifier: ($) =>
      choice(
        $.lowercase_identifier,
        seq($.type_name, "::", $.lowercase_identifier)
      ),

    default_impl_declaration: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        "impl",
        $.function_identifier,
        optional($.type_parameters)
      ),

    type_declaration: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        optional("extern"),
        "type",
        $.identifier,
        optional($.type_parameters),
        optional($.type)
      ),

    error_type_declaration: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        optional("extern"),
        "type",
        "!",
        $.identifier,
        optional(
          choice($.type, seq("{", list($.semicolon, $.constructor), "}"))
        )
      ),

    type_alias_target: ($) => seq($.identifier, optional($.type_parameters)),

    type_alias_targets: ($) =>
      choice(
        seq($.identifier, optional($.type_parameters), "=", $.type),
        seq(
          $.package_identifier,
          $.dot_identifier,
          optional($.type_parameters)
        ),
        seq($.package_identifier, ".(", list(",", $.type_alias_target), ")")
      ),

    type_alias_declaration: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        "typealias",
        $.type_alias_targets
      ),

    struct_declaration: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        "struct",
        $.identifier,
        optional($.type_parameters),
        "{",
        list($.semicolon, $.struct_field_declaration),
        "}"
      ),

    struct_field_declaration: ($) =>
      seq(
        optional($.visibility),
        optional($.mutability),
        $.lowercase_identifier,
        $.type_annotation
      ),

    enum_declaration: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        "enum",
        $.identifier,
        optional($.type_parameters),
        "{",
        list($.semicolon, $.constructor),
        "}"
      ),

    constructor_positional_parameter: ($) =>
      seq(optional($.mutability), $.type),

    constructor_labeled_parameter: ($) =>
      seq(
        optional($.mutability),
        $.lowercase_identifier,
        "~",
        $.type_annotation
      ),

    constructor_parameter: ($) =>
      choice(
        $.constructor_positional_parameter,
        $.constructor_labeled_parameter
      ),

    constructor_payload: ($) =>
      seq("(", list1(",", $.constructor_parameter), ")"),

    constructor_tag_value: ($) => seq("=", $.integer_literal),

    constructor: ($) =>
      seq(
        $.uppercase_identifier,
        optional($.constructor_payload),
        optional($.constructor_tag_value)
      ),

    value_declaration: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        "let",
        $.lowercase_identifier,
        optional($.type_annotation)
      ),

    const_declaration: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        "const",
        $.uppercase_identifier,
        optional($.type_annotation),
        "=",
        $.literal
      ),

    trait_method_positional_parameter: ($) => $.type,

    trait_method_labeled_parameter: ($) =>
      seq($.lowercase_identifier, "~", $.type_annotation),

    trait_method_parameter: ($) =>
      choice(
        $.trait_method_positional_parameter,
        $.trait_method_labeled_parameter
      ),

    trait_method_declaration: ($) =>
      seq(
        optional("async"),
        $.lowercase_identifier,
        optional("!"),
        optional($.type_parameters),
        "(",
        list(",", $.trait_method_parameter),
        ")",
        optional($.return_type)
      ),

    super_trait_declaration: ($) =>
      seq(":", list("+", $.qualified_type_identifier)),

    trait_declaration: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        "trait",
        $.identifier,
        optional($.super_trait_declaration),
        "{",
        list($.semicolon, $.trait_method_declaration),
        "}"
      ),

    trait_alias_target: ($) => seq($.identifier, optional($.type_parameters)),

    trait_alias_targets: ($) =>
      choice(
        seq($.identifier, optional($.type_parameters), "=", $.type),
        seq(
          $.package_identifier,
          $.dot_identifier,
          optional($.type_parameters)
        ),
        seq(
          $.package_identifier,
          ".(",
          list(",", $.trait_alias_target),
          optional(","),
          ")"
        )
      ),

    trait_alias_declaration: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        "traitalias",
        $.trait_alias_targets
      ),
  },
});
