/**
 * @file MoonBit predicate grammar for tree-sitter
 * @author MoonBit Language Team <support@moonbitlang.com>
 * @license Apache-2.0
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const base = require("../../grammar.js");
const shift_operators = ["<<", ">>"];

module.exports = grammar(base, {
  name: "moonbit_mbtp",

  conflicts: ($) => [
    [$.optional_label, $.qualified_identifier],
    [$.positional_parameter, $.qualified_identifier],
    [$.unit_expression, $.parameters],
    [$.qualified_identifier, $.arrow_function_expression],
    [$.positional_parameter, $.identifier],
    [$.optional_label, $.identifier],
    [$._simple_expression, $.positional_parameter],
    [$._simple_type, $.positional_parameter],
    [$._simple_expression, $.arrow_function_expression],
    [$._simple_pattern, $.lexmatch_simple_pattern],
    [$.mbtp_term_atom, $.mbtp_parenthesized_expression],
    [$.mbtp_logic_block_expression, $.mbtp_term_atom],
    [$.lemma_match_expression, $.mbtp_match_expression],
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
        "predicate",
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
        "lemma",
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
      seq(field("name", $._lowercase_identifier), ":", field("type", $.mbtp_type)),

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
      prec(
        1,
        seq(
          "{",
          field("body", $._mbtp_logic_expression),
          "}"
        )
      ),

    _mbtp_logic_expression: ($) => $._mbtp_logic_or_expression,

    _mbtp_logic_or_expression: ($) =>
      choice(
        prec.left(2, seq($._mbtp_logic_or_expression, "||", $._mbtp_logic_and_expression)),
        $._mbtp_logic_and_expression
      ),

    _mbtp_logic_and_expression: ($) =>
      choice(
        prec.left(3, seq($._mbtp_logic_and_expression, "&&", $._mbtp_logic_not_expression)),
        $._mbtp_logic_not_expression
      ),

    _mbtp_logic_not_expression: ($) =>
      choice(
        prec(4, seq("!", $._mbtp_logic_not_expression)),
        $.mbtp_expression
      ),

    lemma_block_expression: ($) =>
      seq("{", optional($.lemma_sequence_expression), "}"),

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

    lemma_proof_assert_expression: ($) => seq("proof_assert", $.mbtp_term),

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
        prec.right(
          1,
          seq($.mbtp_or_term, "→", field("right", $.mbtp_implies_term))
        ),
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
      choice(
        prec(-1, seq("(", $.mbtp_term, ")")),
        seq("{", $.mbtp_term, "}"),
        $.mbtp_expression
      ),

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

    mbtp_binary_expression: ($) => {
      const operand = choice($._mbtp_simple_expression, $.mbtp_binary_expression);
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
          prec.left(
            precedence,
            seq(operand, operator, operand)
          )
        )
      );
    },

    mbtp_binary_expression_no_match: ($) => {
      const operand = choice(
        $._mbtp_simple_expression_no_match,
        $.mbtp_binary_expression_no_match
      );
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
          prec.left(
            precedence,
            seq(operand, operator, operand)
          )
        )
      );
    },

    mbtp_unary_expression: ($) =>
      prec(8, seq(choice("-", "!"), $._mbtp_simple_expression)),

    mbtp_unary_expression_no_match: ($) =>
      prec(8, seq(choice("-", "!"), $._mbtp_simple_expression_no_match)),

    mbtp_apply_expression: ($) =>
      prec.left(
        9,
        seq($._mbtp_simple_expression, "(", list(",", $.mbtp_expression), ")")
      ),

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
      choice(
        $.mbtp_literal_expression,
        $.mbtp_identifier_expression
      ),

    mbtp_match_expression: ($) =>
      seq(
        "match",
        field("value", $.mbtp_expression),
        "{",
        list($._semicolon, $.mbtp_match_case),
        "}"
      ),

    mbtp_match_case: ($) =>
      seq(
        field("pattern", $.mbtp_pattern),
        "=>",
        field("body", $.mbtp_term)
      ),

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
        seq(
          $.mbtp_pattern_constructor,
          "(",
          list1(",", $.mbtp_pattern),
          ")"
        ),
        seq("(", list1(",", $.mbtp_pattern), ")")
      ),

    mbtp_pattern_constructor: ($) =>
      choice(
        $.uppercase_identifier,
        seq($.package_identifier, $.dot_uppercase_identifier)
      ),

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

    mbtp_tuple_type: ($) =>
      seq("(", $.mbtp_type, ",", list1(",", $.mbtp_type), ")"),

    mbtp_parenthesized_type: ($) => seq("(", $.mbtp_type, ")"),

    mbtp_applied_type: ($) =>
      seq($.mbtp_type_path, "[", list1(",", $.mbtp_type), "]"),

    mbtp_type_path: ($) =>
      choice(
        $.identifier,
        seq($.identifier, repeat1($.dot_identifier)),
        seq($.package_identifier, $.dot_identifier, repeat($.dot_identifier))
      ),

    mbtp_value_path: ($) =>
      choice(
        $.identifier,
        seq($.package_identifier, $.dot_identifier)
      ),
  },
});

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
