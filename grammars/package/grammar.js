/**
 * @file Tree-sitter grammar for MoonBit Package (moon.pkg)
 * @author Moonbit Language Team <support@moonbitlang.com>
 * @license Apache-2.0
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

/**
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

module.exports = grammar({
  name: "moonbit_package",

  extras: (_) => [/\s/, /\/\/.*/],

  rules: {
    source_file: ($) => list($.semicolon, $.statement),

    semicolon: (_) => choice("\n", "\0", ";"),

    statement: ($) =>
      choice($.import_statement, $.assign_statement, $.apply_statement),

    // import { "path/to/pkg" [@alias], ... } [for "test"]
    import_statement: ($) =>
      seq(
        "import",
        "{",
        list(",", $.import_item),
        "}",
        optional($.import_for_clause)
      ),

    import_item: ($) =>
      seq(
        $.string_literal,
        optional(
          choice(
            $.package_alias,
            seq("as", $.package_alias)
          )
        )
      ),

    package_alias: (_) => /@[_\p{XID_Start}][_\p{XID_Continue}]*/v,

    import_for_clause: ($) => seq("for", $.string_literal),

    // name = expr
    assign_statement: ($) =>
      seq($.identifier, "=", $.expression),

    // name(label: value, ...)
    apply_statement: ($) =>
      seq($.identifier, "(", list(",", $.labeled_argument), ")"),

    labeled_argument: ($) =>
      seq($.argument_label, ":", $.expression),

    argument_label: ($) =>
      choice($.identifier, $.string_literal),

    expression: ($) =>
      choice(
        $.string_literal,
        $.integer_literal,
        $.float_literal,
        $.boolean_literal,
        $.array_expression,
        $.map_expression
      ),

    array_expression: ($) => seq("[", list(",", $.expression), "]"),

    map_expression: ($) => seq("{", list(",", $.map_entry), "}"),

    map_entry: ($) => seq($.string_literal, ":", $.expression),

    boolean_literal: (_) => choice("true", "false"),

    integer_literal: (_) =>
      token(
        choice(
          /[0-9][0-9_]*/,
          /0[xX][0-9a-fA-F_]+/,
          /0[oO][0-7_]+/,
          /0[bB][01_]+/
        )
      ),

    float_literal: (_) =>
      token(
        choice(
          /[0-9][0-9_]*\.[0-9_]*([eE][+-]?[0-9_]*)?/,
          /\.[0-9_]+([eE][+-]?[0-9_]*)?/
        )
      ),

    string_literal: ($) => seq('"', repeat($.string_fragment), '"'),

    string_fragment: ($) =>
      choice($.unescaped_string_fragment, $.escape_sequence),

    unescaped_string_fragment: (_) =>
      choice(
        token.immediate(prec(1, /\\[^ntbr'"\\]/)),
        token.immediate(prec(1, /[^"\\]+/))
      ),

    escape_sequence: (_) =>
      choice(
        token.immediate(/\\[ntbr'"\\]/),
        token.immediate(/\\x[0-9a-fA-F]{1,2}/),
        token.immediate(/\\u[0-9a-fA-F]{4}/),
        token.immediate(/\\u\{[0-9a-fA-F]+\}/)
      ),

    identifier: (_) => /[_\p{XID_Start}][_\p{XID_Continue}]*/v,
  },
});
