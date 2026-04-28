/**
 * @file MoonBit predicate grammar for tree-sitter
 * @author MoonBit Language Team <support@moonbitlang.com>
 * @license Apache-2.0
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const shift_operators = ["<<", ">>"];

module.exports = grammar({
  name: "moonbit_mbtp",

  extras: ($) => [$.comment, $.block_comment, /\s/, $._scanner_reset],

  externals: ($) => [
    $._scanner_reset,
    $._automatic_semicolon,
    ";",
    "#|",
    "$|",
    $._double_literal,
    "for",
    $.error_sentinel,
  ],

  word: ($) => $.lowercase_identifier,

  conflicts: ($) => [
    [$.lemma_nonsequence_expression, $.mbtp_term_atom],
  ],

  rules: {
    structure: ($) => list($._semicolon, $.mbtp_declaration),

    mbtp_declaration: ($) =>
      choice(
        $.predicate_definition,
        $.logic_function_definition,
        $.lemma_definition
      ),

    predicate_definition: ($) =>
      seq(
        optional($.attributes),
        optional("pub"),
        token(prec(1, "predicate")),
        optional(seq(field("receiver", $.uppercase_identifier), "::")),
        field("name", $._lowercase_identifier),
        field("parameters", $.mbtp_parameter_list),
        field("body", $.mbtp_predicate_body)
      ),

    logic_function_definition: ($) =>
      seq(
        optional($.attributes),
        optional("pub"),
        "fn",
        optional(seq(field("receiver", $.uppercase_identifier), "::")),
        field("name", $._lowercase_identifier),
        field("parameters", $.mbtp_parameter_list),
        "->",
        field("return_type", $.mbtp_type),
        choice(
          field("body", $.mbtp_logic_block_expression),
          seq("=", field("stub", $.string_literal))
        )
      ),

    lemma_definition: ($) =>
      seq(
        optional($.attributes),
        optional("pub"),
        token(prec(1, "lemma")),
        field("name", $._lowercase_identifier),
        field("parameters", $.mbtp_parameter_list),
        optional(field("where", $.mbtp_where_clause)),
        field("body", $.lemma_block_expression)
      ),

    mbtp_where_clause: ($) =>
      seq("where", "{", list(",", $.mbtp_where_field), "}"),

    mbtp_where_field: ($) =>
      seq(
        field("name", $._lowercase_identifier),
        ":",
        field("value", $.mbtp_expression)
      ),

    mbtp_parameter_list: ($) => seq("(", list(",", $.mbtp_parameter), ")"),

    mbtp_parameter: ($) =>
      seq(
        field("name", $._lowercase_identifier),
        ":",
        field("type", $.mbtp_type)
      ),

    mbtp_parameter_decl: ($) =>
      choice(
        seq("_", optional(seq(":", $.mbtp_type))),
        seq($._lowercase_identifier, optional(seq(":", $.mbtp_type)))
      ),

    mbtp_arrow_parameter: ($) =>
      choice(
        seq($._lowercase_identifier, ":", $.mbtp_type),
        seq("_", ":", $.mbtp_type)
      ),

    mbtp_logic_block_expression: ($) =>
      prec(1, seq("{", field("body", $._mbtp_logic_expression), "}")),

    _mbtp_logic_expression: ($) => $._mbtp_logic_or_expression,

    _mbtp_logic_or_expression: ($) =>
      choice(
        prec.left(
          2,
          seq($._mbtp_logic_or_expression, "||", $._mbtp_logic_and_expression)
        ),
        $._mbtp_logic_and_expression
      ),

    _mbtp_logic_and_expression: ($) =>
      choice(
        prec.left(
          3,
          seq($._mbtp_logic_and_expression, "&&", $._mbtp_logic_not_expression)
        ),
        $._mbtp_logic_not_expression
      ),

    _mbtp_logic_not_expression: ($) =>
      choice(prec(4, seq("!", $._mbtp_logic_not_expression)), $.mbtp_expression),

    lemma_block_expression: ($) => seq("{", optional($.lemma_sequence_expression), "}"),

    lemma_sequence_expression: ($) =>
      choice(
        $.lemma_nonsequence_expression,
        seq($.lemma_nonsequence_expression, $._semicolon),
        seq(
          $.lemma_nonsequence_expression,
          $._semicolon,
          $.lemma_sequence_expression
        )
      ),

    lemma_nonsequence_expression: ($) =>
      choice(
        $.lemma_unit_expression,
        $.lemma_proof_assert_expression,
        $.lemma_if_expression,
        $.lemma_match_expression,
        $.mbtp_expression
      ),

    lemma_unit_expression: (_) => seq("(", ")"),

    lemma_proof_assert_expression: ($) =>
      seq(token(prec(1, "proof_assert")), $.mbtp_term),

    lemma_if_expression: ($) =>
      seq(
        "if",
        field("condition", $.mbtp_term),
        field("consequence", $.lemma_block_expression),
        optional(seq("else", field("alternative", $.lemma_block_expression)))
      ),

    lemma_match_expression: ($) =>
      prec(
        1,
        seq(
          "match",
          field("value", $.mbtp_expression),
          "{",
          list($._semicolon, $.lemma_match_case),
          "}"
        )
      ),

    lemma_match_case: ($) =>
      seq(
        field("pattern", $.mbtp_pattern),
        "=>",
        field(
          "body",
          choice($.lemma_block_expression, prec(1, $.lemma_nonsequence_expression))
        )
      ),

    mbtp_predicate_body: ($) => seq("{", field("body", $.mbtp_term), "}"),

    mbtp_term: ($) => $.mbtp_implies_term,

    mbtp_implies_term: ($) =>
      choice(
        prec.right(1, seq($.mbtp_or_term, "→", field("right", $.mbtp_implies_term))),
        $.mbtp_or_term
      ),

    mbtp_or_term: ($) =>
      choice(
        prec.left(2, seq($.mbtp_or_term, "||", $.mbtp_and_term)),
        $.mbtp_and_term
      ),

    mbtp_and_term: ($) =>
      choice(
        prec.left(3, seq($.mbtp_and_term, "&&", $.mbtp_not_term)),
        $.mbtp_not_term
      ),

    mbtp_not_term: ($) =>
      choice(
        prec(4, seq("!", $.mbtp_not_term)),
        $.mbtp_quantified_term,
        $.mbtp_term_atom
      ),

    mbtp_quantified_term: ($) =>
      seq(
        field("quantifier", choice("∀", "∃")),
        field("binder", $._lowercase_identifier),
        ":",
        field("type", $.mbtp_type),
        ",",
        field("body", $.mbtp_term)
      ),

    mbtp_term_atom: ($) =>
      choice(prec(-1, seq("(", $.mbtp_term, ")")), seq("{", $.mbtp_term, "}"), $.mbtp_expression),

    mbtp_expression: ($) =>
      choice(
        $.mbtp_lambda_expression,
        $.mbtp_binary_expression,
        prec(-1, $._mbtp_simple_expression)
      ),

    mbtp_expression_no_match: ($) =>
      choice(
        $.mbtp_lambda_expression,
        $.mbtp_binary_expression_no_match,
        prec(-1, $._mbtp_simple_expression_no_match)
      ),

    _mbtp_simple_expression: ($) =>
      choice(
        $.mbtp_atomic_expression,
        $.mbtp_unary_expression,
        $.mbtp_apply_expression,
        $.mbtp_array_access_expression,
        $.mbtp_dot_apply_expression,
        $.mbtp_field_expression,
        $.mbtp_method_expression,
        $.mbtp_tuple_expression,
        $.mbtp_parenthesized_expression
      ),

    _mbtp_simple_expression_no_match: ($) =>
      choice(
        $.mbtp_atomic_expression_no_match,
        $.mbtp_unary_expression_no_match,
        $.mbtp_apply_expression_no_match,
        $.mbtp_array_access_expression_no_match,
        $.mbtp_dot_apply_expression_no_match,
        $.mbtp_field_expression_no_match,
        $.mbtp_method_expression,
        $.mbtp_tuple_expression_no_match,
        $.mbtp_parenthesized_expression_no_match
      ),

    mbtp_lambda_expression: ($) =>
      choice($.mbtp_arrow_function_expression, $.mbtp_anonymous_function_expression),

    mbtp_arrow_function_expression: ($) =>
      choice(
        seq(
          "(",
          list(",", $.mbtp_arrow_parameter),
          ")",
          "=>",
          choice($.mbtp_expression_no_match, $.mbtp_logic_block_expression)
        ),
        seq(
          choice($._lowercase_identifier, "_"),
          "=>",
          choice($.mbtp_expression_no_match, $.mbtp_logic_block_expression)
        )
      ),

    mbtp_anonymous_function_expression: ($) =>
      seq(
        "fn",
        "(",
        list(",", $.mbtp_parameter_decl),
        ")",
        optional(seq("->", $.mbtp_type)),
        $.mbtp_logic_block_expression
      ),

    mbtp_binary_expression: ($) =>
      binaryExpression($, $._mbtp_simple_expression, $.mbtp_binary_expression),

    mbtp_binary_expression_no_match: ($) =>
      binaryExpression(
        $,
        $._mbtp_simple_expression_no_match,
        $.mbtp_binary_expression_no_match
      ),

    mbtp_unary_expression: ($) =>
      prec(8, seq(choice("-", "!"), $._mbtp_simple_expression)),

    mbtp_unary_expression_no_match: ($) =>
      prec(8, seq(choice("-", "!"), $._mbtp_simple_expression_no_match)),

    mbtp_apply_expression: ($) =>
      prec.left(9, seq($._mbtp_simple_expression, "(", list(",", $.mbtp_expression), ")")),

    mbtp_apply_expression_no_match: ($) =>
      prec.left(
        9,
        seq($._mbtp_simple_expression_no_match, "(", list(",", $.mbtp_expression), ")")
      ),

    mbtp_array_access_expression: ($) =>
      prec.left(9, seq($._mbtp_simple_expression, "[", $.mbtp_expression, "]")),

    mbtp_array_access_expression_no_match: ($) =>
      prec.left(
        9,
        seq($._mbtp_simple_expression_no_match, "[", $.mbtp_expression, "]")
      ),

    mbtp_dot_apply_expression: ($) =>
      prec.left(
        9,
        seq(
          $._mbtp_simple_expression,
          $.dot_lowercase_identifier,
          "(",
          list(",", $.mbtp_expression),
          ")"
        )
      ),

    mbtp_dot_apply_expression_no_match: ($) =>
      prec.left(
        9,
        seq(
          $._mbtp_simple_expression_no_match,
          $.dot_lowercase_identifier,
          "(",
          list(",", $.mbtp_expression),
          ")"
        )
      ),

    mbtp_field_expression: ($) =>
      prec.left(
        9,
        seq(
          $._mbtp_simple_expression,
          choice(
            $.dot_lowercase_identifier,
            $.dot_uppercase_identifier,
            seq(".", /[0-9]+/)
          )
        )
      ),

    mbtp_field_expression_no_match: ($) =>
      prec.left(
        9,
        seq(
          $._mbtp_simple_expression_no_match,
          choice(
            $.dot_lowercase_identifier,
            $.dot_uppercase_identifier,
            seq(".", /[0-9]+/)
          )
        )
      ),

    mbtp_method_expression: ($) =>
      seq(field("type", $.uppercase_identifier), "::", field("method", $._lowercase_identifier)),

    mbtp_atomic_expression: ($) =>
      choice(
        $.mbtp_literal_expression,
        $.mbtp_identifier_expression,
        $.mbtp_match_expression
      ),

    mbtp_atomic_expression_no_match: ($) =>
      choice($.mbtp_literal_expression, $.mbtp_identifier_expression),

    mbtp_match_expression: ($) =>
      seq(
        "match",
        field("value", $.mbtp_expression),
        "{",
        list($._semicolon, $.mbtp_match_case),
        "}"
      ),

    mbtp_match_case: ($) =>
      seq(field("pattern", $.mbtp_pattern), "=>", field("body", $.mbtp_term)),

    mbtp_identifier_expression: ($) => $.mbtp_value_path,

    mbtp_literal_expression: ($) => $.literal,

    mbtp_tuple_expression: ($) =>
      seq("(", $.mbtp_expression, ",", list1(",", $.mbtp_expression), ")"),

    mbtp_tuple_expression_no_match: ($) =>
      seq(
        "(",
        $.mbtp_expression_no_match,
        ",",
        list1(",", $.mbtp_expression_no_match),
        ")"
      ),

    mbtp_parenthesized_expression: ($) =>
      prec(1, seq("(", choice($.mbtp_expression, $.mbtp_quantified_term), ")")),

    mbtp_parenthesized_expression_no_match: ($) =>
      prec(1, seq("(", $.mbtp_expression_no_match, ")")),

    mbtp_pattern: ($) =>
      choice(
        "_",
        $._lowercase_identifier,
        $.mbtp_pattern_constructor,
        seq($.mbtp_pattern_constructor, "(", list1(",", $.mbtp_pattern), ")"),
        seq("(", list1(",", $.mbtp_pattern), ")")
      ),

    mbtp_pattern_constructor: ($) =>
      choice($.uppercase_identifier, seq($.package_identifier, $.dot_uppercase_identifier)),

    mbtp_type: ($) => choice($.mbtp_function_type, $.mbtp_non_function_type),

    mbtp_function_type: ($) =>
      choice(
        seq("(", ")", "->", $.mbtp_type),
        seq("(", $.mbtp_type, ")", "->", $.mbtp_type),
        seq("(", $.mbtp_type, ",", list1(",", $.mbtp_type), ")", "->", $.mbtp_type)
      ),

    mbtp_non_function_type: ($) =>
      choice(
        $.mbtp_applied_type,
        $.mbtp_tuple_type,
        $.mbtp_parenthesized_type,
        $.mbtp_type_path,
        "_"
      ),

    mbtp_tuple_type: ($) => seq("(", $.mbtp_type, ",", list1(",", $.mbtp_type), ")"),

    mbtp_parenthesized_type: ($) => seq("(", $.mbtp_type, ")"),

    mbtp_applied_type: ($) => seq($.mbtp_type_path, "[", list1(",", $.mbtp_type), "]"),

    mbtp_type_path: ($) =>
      choice(
        $.identifier,
        seq($.identifier, repeat1($.dot_identifier)),
        seq($.package_identifier, $.dot_identifier, repeat($.dot_identifier))
      ),

    mbtp_value_path: ($) => choice($.identifier, seq($.package_identifier, $.dot_identifier)),

    interpolator: ($) => seq("\\{", $.mbtp_expression, "}"),

    literal: ($) =>
      choice(
        $.boolean_literal,
        $.double_literal,
        $.float_literal,
        $.integer_literal,
        $.byte_literal,
        $.byte_escape_literal,
        $.char_literal,
        $.string_literal,
        $.bytes_literal,
        $.regex_literal,
        $.multiline_string_literal
      ),

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

    float_literal: ($) => seq($._double_literal, token.immediate("F")),

    double_literal: ($) => $._double_literal,

    byte_literal: ($) =>
      seq("b'", choice($.escape_sequence, token.immediate(/[^']/)), "'"),

    byte_escape_literal: (_) => token(choice(/\\x[0-9a-fA-F]{1,2}/, /\\o[0-7]{1,3}/)),

    char_literal: ($) =>
      seq("'", choice($.escape_sequence, token.immediate(/[^']/)), "'"),

    string_literal: ($) => seq('"', repeat($.string_fragment), '"'),

    bytes_literal: ($) => seq('b"', repeat($.string_fragment), '"'),

    regex_literal: ($) => seq('re"', repeat($.string_fragment), '"'),

    string_fragment: ($) => choice($.unescaped_string_fragment, $.escape_sequence),

    unescaped_string_fragment: (_) =>
      choice(
        token.immediate(prec(1, /\\[^ntbrf'"\\{]/)),
        token.immediate(prec(1, /[^"\\]+/))
      ),

    escape_sequence: (_) =>
      choice(
        token.immediate(/\\[ntbrf'"\\]/),
        token.immediate(/\\o[0-7]{1,3}/),
        token.immediate(/\\x[0-9a-fA-F]{1,2}/),
        token.immediate(/\\x\{[0-9a-fA-F]+\}/),
        token.immediate(/\\u[0-9a-fA-F]{4}/),
        token.immediate(/\\u\{[0-9a-fA-F]+\}/)
      ),

    multiline_string_content: (_) => /[^\n]*/,

    multiline_string_fragment: ($) => seq("#|", $.multiline_string_content),

    multiline_interpolation_content: ($) =>
      choice(
        token.immediate(prec(1, /\\[^{]/)),
        token.immediate(prec(1, /[^\n\\]+/)),
        $.interpolator
      ),

    multiline_interpolation_fragment: ($) => seq("$|", repeat($.multiline_interpolation_content)),

    multiline_string_literal: ($) =>
      prec.left(repeat1(choice($.multiline_string_fragment, $.multiline_interpolation_fragment))),

    uppercase_identifier: (_) => /[\p{Uppercase_Letter}][_\p{XID_Continue}]*/v,

    _uppercase_identifier: ($) => $.uppercase_identifier,

    lowercase_identifier: (_) => /[_[\p{XID_Start}--\p{Uppercase_Letter}]][_\p{XID_Continue}]*/v,

    _lowercase_identifier: ($) => $.lowercase_identifier,

    identifier: ($) => choice($._uppercase_identifier, $._lowercase_identifier),

    _semicolon: ($) => choice($._automatic_semicolon, ";"),

    dot_identifier: ($) => choice($.dot_lowercase_identifier, $.dot_uppercase_identifier),

    dot_lowercase_identifier: (_) => /\.[_[\p{XID_Start}--\p{Uppercase_Letter}]][_\p{XID_Continue}]*/v,

    dot_uppercase_identifier: (_) => /\.[\p{Uppercase_Letter}][_\p{XID_Continue}]*/v,

    package_identifier: (_) => /@[_\p{XID_Start}\/][_\p{XID_Continue}\/]*/v,

    comment: (_) => /\/\/.*/,

    block_comment: (_) => token(seq("/*", /[^*]*\*+([^/*][^*]*\*+)*/, "/")),

    attribute_properties: ($) => seq("(", list(",", $.attribute_property), ")"),

    attribute_property: ($) =>
      choice(
        seq($._lowercase_identifier, "=", $.attribute_expression),
        $.attribute_expression
      ),

    attribute_expression: ($) =>
      choice(
        $._lowercase_identifier,
        $._uppercase_identifier,
        seq($._lowercase_identifier, $.dot_lowercase_identifier),
        seq($._lowercase_identifier, $.attribute_properties),
        seq($._lowercase_identifier, $.dot_lowercase_identifier, $.attribute_properties),
        seq($._uppercase_identifier, $.attribute_properties),
        $.string_literal
      ),

    attribute: ($) => seq("#", $.attribute_expression),

    attributes: ($) => repeat1($.attribute),
  },
});

/**
 * @param {RuleBuilder<RuleSet>} $
 * @param {Rule} simple
 * @param {Rule} recursive
 * @returns {Rule}
 */
function binaryExpression($, simple, recursive) {
  const operand = choice(simple, recursive);
  const table = [
    [7, choice("*", "/", "%")],
    [6, choice("+", "-")],
    [5, choice(...shift_operators)],
    [4, choice(">", ">=", "<=", "<", "==", "!=")],
    [3, "&"],
    [2, "^"],
    [1, "|"],
  ];

  return choice(
    ...table.map(([precedence, operator]) =>
      prec.left(precedence, seq(operand, operator, operand))
    )
  );
}

/**
 * @param {RuleOrLiteral} separator
 * @param {Rule} rule
 * @returns {Rule}
 */
function list(separator, rule) {
  return optional(list1(separator, rule));
}

/**
 * @param {RuleOrLiteral} separator
 * @param {Rule} rule
 * @returns {SeqRule}
 */
function list1(separator, rule) {
  return seq(rule, repeat(seq(separator, rule)), optional(separator));
}
