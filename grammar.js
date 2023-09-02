/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: 'moonbit',

  rules: {
    structure: $ => list($.structure_item, ';'),

    structure_item: $ => choice(
      $.function_definition,
      $.type_defintion
    ),

    function_definition: $ => seq(
      'func',
      $.identifier,
      optional($.parameters),
      optional($.retuern_type),
      $.block_expression
    ),

    type_defintion: $ => seq(
       optional($.visibility),
       "type",
       $.identifier,
       optional($.type_parameters)
    ),

    type_parameters: $ => seq(
      '[',
      list1($.identifier, ','),
      ']'
    ),

    type_annotation: $ => seq(':', $.type),
    retuern_type : $ => seq('->', $.type),

    parameter : $ => seq($.identifier, optional($.type_annotation)),

    parameters: $ => seq('(', list($.parameter, ',') ,')'),

    type: $ => 'Int',

    block_expression: $ => seq(
      '{',
      list($.statement_expression, ';'),
      '}',
    ),

    statement_expression: $ => 'return',

    identifier: $ => /[a-zA-Z]+/,

    visibility: $ => choice(
      'priv',
      seq('pub', optional($.pub_attr))
    ),

    pub_attr: $ => seq('(', 'readonly', ')')
  }
})

/**
 * Creates a rule to match one list of rules ended with the ender, the last ender may be omitted
 *
 * @param {RuleOrLiteral} rule
 * @param {RuleOrLiteral} end - The ender
 * @returns {SeqRule}
 */

function list1(rule, end) {
  return seq(rule, repeat(seq(end, rule)), optional(end))
}

/**
 * Creates a rule to match zero or one list of rules ended with the ender, the last ender may be omitted
 *
 * @param {RuleOrLiteral} rule
 * @param {RuleOrLiteral} end - The ender
 * @returns {ChoiceRule}
 */

function list(rule, end) {
  return optional(list1(rule, end))
}
