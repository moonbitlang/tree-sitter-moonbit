/**
 * @file Mbtq grammar for tree-sitter
 * @author Haoxiang Fei <feihaoxiang@idea.edu.cn>
 * @license Apache-2.0
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const base = require('../grammar.js');

module.exports = grammar(base, {
  name: 'mbtq',

  rules: {
    _simple_expression: $ => choice(
      base.grammar.rules._simple_expression,
      $.quotation_expression_expander,
    ),

    simple_pattern: $ => choice(
      base.grammar.rules.simple_pattern,
      $.quotation_pattern_expander,
    ),

    type: $ => choice(
      base.grammar.rules.type,
      $.quotation_type_expander,
    ),

    literal: $ => choice(
      base.grammar.rules.literal,
      $.quotation_literal_expander,
    ),

    string_literal: $ => choice(
      base.grammar.rules.string_literal,
      $.quotation_string_expander,
    ),

    quotation_variable: $ => $._lowercase_identifier,

    quotation_expression_expander: $ => seq(
      '$', 'exp', ':', $.quotation_variable,
    ),

    quotation_pattern_expander: $ => seq(
      '$', 'pat', ':', $.quotation_variable,
    ),

    quotation_lowercase_identifier_expander: $ => seq(
      '$', 'id', ':', $.quotation_variable,
    ),

    quotation_uppercase_identifier_expander: $ => seq(
      '$', 'Id', ':', $.quotation_variable,
    ),

    quotation_type_expander: $ => seq(
      '$', 'ty', ':', $.quotation_variable,
    ),

    quotation_literal_expander: $ => seq(
      '$', 'lit', ':', $.quotation_variable,
    ),

    quotation_string_expander: $ => seq(
      '$', 'str', ':', $.quotation_variable,
    ),

    _lowercase_identifier: $ => choice(
      $.quotation_lowercase_identifier_expander,
      $.lowercase_identifier,
    ),

    _uppercase_identifier: $ => choice(
      $.quotation_uppercase_identifier_expander,
      $.uppercase_identifier,
    ),
  },
});
