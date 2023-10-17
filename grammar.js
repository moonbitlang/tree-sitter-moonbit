/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const
  PREC = {
    apply: 19,
    access: 18,
    power: 17,
    unary: 16,
    multiplicative: 15,
    additive: 14,
    comparative: 13,
    and: 12,
    or: 11,
    orPattern: 10,
    asPattern: 9,
  },
  power_operator = '**',
  multiplicative_operators = ['*', '/', '%'],
  additive_operators = ['+', '-'],
  comparative_operators = ['>', '>=', '<=', '<', '==', '!='],

  terminator = choice('\n', ';', '\0')

module.exports = grammar({
  name: 'moonbit',

  extras: $ => [
    $.comment,
    $.docstring,
    /\s/
  ],

  externals: $ => [
    $.float_literal
  ],

  word: $ => $.lowercase_identifier,

  rules: {
    structure: $ => semiList($.structure_item),

    structure_item: $ => choice(
      $.type_definition,
      $.struct_definition,
      $.enum_definition,
      $.value_definition,
      $.function_definition,
      $.interface_definition
    ),

    visibility: $ => choice(
      'priv',
      seq('pub', optional($.pub_attribute))
    ),

    pub_attribute: _ => seq('(', 'readonly', ')'),

    type_definition: $ => seq(
      optional($.visibility),
      'type',
      $.identifier,
      optional($.type_parameters)
    ),

    struct_definition: $ => seq(
      optional($.visibility),
      'struct',
      $.identifier,
      optional($.type_parameters),
      '{',
      semiList($.struct_filed_declaration),
      '}'
    ),

    struct_filed_declaration: $ => seq(
      optional($.visibility),
      optional($.mutability),
      $.lowercase_identifier,
      ':',
      $.type
    ),

    enum_definition: $ => seq(
      optional($.visibility),
      'enum',
      $.identifier,
      optional($.type_parameters),
      '{',
      semiList($.enum_constructor),
      '}'
    ),

    enum_constructor: $ => seq(
      $.uppercase_identifier,
      optional(seq(
        '(',
        commaList1($.type),
        ')'
      ))
    ),

    value_definition: $ => seq(
      optional($.pub),
      'let',
      $.lowercase_identifier,
      optional($.type_annotation),
      '=',
      $.expression
    ),

    function_definition: $ => seq(
      optional($.pub),
      'func',
      $.function_identifier,
      optional($.type_parameters),
      optional($.parameters),
      optional($.return_type),
      choice(
        $.block_expression,
        seq('=', $.string_literal, $.string_literal)
      )
    ),

    interface_definition: $ => seq(
      optional($.pub),
      'interface',
      $.identifier,
      '{',
      semiList($.interface_method_declaration),
      '}'
    ),

    interface_method_declaration: $ => seq(
      $.function_identifier,
      optional($.type_parameters),
      '(',
      commaList($.type),
      ')',
      optional($.return_type)
    ),

    expression: $ => choice(
      $.simple_expression,
      $.if_expression,
      $.match_expression
    ),

    simple_expression: $ => choice(
      $.atomic_expression,
      $.qualified_identifier,
      $.unary_expression,
      $.binary_expression,
      $.struct_expression,
      $.nonempty_block_expression,
      $.anonymous_lambda_expression,
      $.constructor_expression,
      $.apply_expression,
      $.array_access_expression,
      $.dot_apply_expression,
      $.access_expression,
      $.method_expression,
      $.unit_expression,
      $.tuple_expression,
      $.constraint_expression,
      $.array_expression,
      '_'
    ),

    atomic_expression: $ => choice(
      $.string_interpolation,
      $.literal
    ),

    string_interpolation: $ => seq(
      '"',
      repeat($.string_fragement),
      $.interpolator,
      repeat(choice(
        $.string_fragement,
        $.interpolator
      )),
      '"'
    ),

    interpolator: $ => seq(
      '\\(',
      $.expression,
      ')'
    ),

    literal: $ => choice(
      $.boolean_literal,
      $.float_literal,
      $.integer_literal,
      $.char_literal,
      $.string_literal
    ),

    boolean_literal: _ => choice('true', 'false'),

    integer_literal: _ => token(choice(
      /[0-9][0-9_]*L?/,
      /0[xX][0-9a-fA-F_]+L?/,
      /0[oO][0-7_]+L?/,
      /0[bB][01_]+L?/,
    )),

    // integerPart = /[0-9][_0-9]*/,
    // decimalPart = /[_0-9]+/,
    // exponentPart = /[eE][0-9][_0-9]*/,
    // float_literal: _ => /[0-9][_0-9]*\.[_0-9]*([eE][0-9][_0-9]*)?/,

    char_literal: $ => seq(
      '\'',
      choice(
        $.escape_sequence,
        token.immediate(/[^']/)
      ),
      '\''
    ),

    string_literal: $ => seq(
      '"',
      repeat($.string_fragement),
      '"'
    ),

    string_fragement: $ => choice(
      $.unescaped_string_fragement,
      $.escape_sequence
    ),

    unescaped_string_fragement: _ => token.immediate(/[^"\\]+/),

    escape_sequence: _ => token.immediate(/\\[ntb"\\]/),

    unary_expression: $ => prec(PREC.unary, seq(
      choice('-', '+'),
      $.expression
    )),

    binary_expression: $ => {
      const table = [
        [PREC.multiplicative, choice(...multiplicative_operators)],
        [PREC.additive, choice(...additive_operators)],
        [PREC.comparative, choice(...comparative_operators)],
        [PREC.and, '&&'],
        [PREC.or, '||']
      ]
      const power_expression = prec.right(PREC.power, seq($.expression, power_operator, $.expression))
      return choice(power_expression, ...table.map(([precedence, operator]) =>
        //@ts-ignore
        prec.left(precedence, seq(
          $.expression,
          //@ts-ignore
          operator,
          $.expression
        ))
      ))
    },

    struct_expression: $ => choice(
      seq('{', optional($.struct_field_expression), '}'),
      seq('{', '..', $.expression, '}'),
      seq('{', '..', $.expression, ',', optional($.struct_field_expression), '}')
    ),

    struct_field_expression: $ => choice(
      seq($.labeled_expression_pun, ',', commaList($.struct_filed_expression)),
      seq($.labeled_expression, optional(',')),
      seq($.labeled_expression, ',', commaList1($.struct_filed_expression)),
    ),

    struct_filed_expression: $ => choice(
      $.labeled_expression,
      $.labeled_expression_pun
    ),

    labeled_expression: $ => seq($.lowercase_identifier, ':', $.expression),

    labeled_expression_pun: $ => $.lowercase_identifier,

    block_expression: $ => seq(
      '{',
      semiList($.statement_expression),
      '}',
    ),

    nonempty_block_expression: $ => seq(
      '{',
      semiList1($.statement_expression),
      '}'
    ),

    anonymous_lambda_expression: $ => seq(
      'fn',
      $.parameters,
      optional($.return_type),
      $.block_expression
    ),

    constructor_expression: $ => choice(
      $.uppercase_identifier,
      seq($.qualified_type_identifier, $.colon_colon_uppercase_identifier)
    ),

    apply_expression: $ => prec(PREC.apply, seq(
      $.simple_expression,
      '(',
      commaList($.expression),
      ')'
    )),

    array_access_expression: $ => prec(PREC.access, seq(
      $.simple_expression,
      '[',
      $.expression,
      ']'
    )),

    dot_apply_expression: $ => prec(PREC.apply, seq(
      $.simple_expression,
      $.dot_identifier,
      '(',
      commaList($.expression),
      ')'
    )),

    access_expression: $ => prec(PREC.access, seq(
      $.simple_expression,
      $.accessor
    )),

    accessor: $ => choice(
      $.dot_identifier,
      /\.[0-9]+/
    ),

    method_expression: $ => seq(
      $.expression,
      $.colon_colon_lowercase_identifier
    ),

    unit_expression: _ => seq('(', ')'),

    tuple_expression: $ => seq(
      '(',
      commaList1($.expression),
      ')'
    ),

    constraint_expression: $ => seq(
      '(',
      $.expression,
      ':',
      $.type,
      ')'
    ),

    array_expression: $ => seq(
      '[',
      commaList($.expression),
      ']'
    ),

    match_expression: $ => seq(
      'match',
      $.simple_expression,
      '{',
      semiList($.case_clause),
      '}'
    ),

    case_clause: $ => seq($.pattern, '=>', $.expression),

    if_expression: $ => seq(
      'if',
      $.simple_expression,
      $.block_expression,
      optional($.else_clause)
    ),

    else_clause: $ => seq(
      'else',
      choice(
        $.block_expression,
        $.if_expression
      )
    ),

    statement_expression: $ => choice(
      $.let_expression,
      $.shorthand_let_expression,
      $.var_expression,
      $.assign_expression,
      $.named_lambda_expression,
      $.while_expression,
      'break',
      'continue',
      $.return_expression,
      $.expression
    ),

    let_expression: $ => seq(
      'let',
      $.pattern,
      optional($.type_annotation),
      '=',
      $.expression
    ),

    shorthand_let_expression: $ => seq(
      $.shorthand_let_pattern,
      ':=',
      $.expression
    ),

    shorthand_let_pattern: $ => choice('_', $.lowercase_identifier),

    var_expression: $ => seq(
      'var',
      $.lowercase_identifier,
      optional($.type_annotation),
      '=',
      $.expression
    ),

    assign_expression: $ => seq($.left_value, '=', $.expression),

    left_value: $ => choice(
      $.qualified_identifier,
      $.access_expression,
      $.array_access_expression
    ),

    named_lambda_expression: $ => seq(
      'fn',
      $.lowercase_identifier,
      $.parameters,
      optional($.return_type),
      $.block_expression
    ),

    while_expression: $ => seq(
      'while',
      $.simple_expression,
      $.block_expression
    ),

    return_expression: $ => seq('return', optional($.expression)),

    // Patterns

    pattern: $ => choice(
      $.simple_pattern,
      $.as_pattern,
      $.or_pattern
    ),

    as_pattern: $ => prec(PREC.asPattern, seq(
      $.pattern,
      'as',
      $.lowercase_identifier
    )),

    or_pattern: $ => prec.right(PREC.orPattern, seq($.pattern, '|', $.pattern)),

    simple_pattern: $ => choice(
      '_',
      seq('(', $.pattern, ')'),
      $.literal,
      $.lowercase_identifier,
      $.constructor_pattern,
      $.tuple_pattern,
      $.constraint_pattern,
      $.array_pattern,
      $.struct_pattern
    ),

    constructor_pattern: $ => seq(
      $.constructor_expression,
      optional(seq(
        '(',
        commaList1($.pattern),
        ')'
      ))
    ),

    tuple_pattern: $ => seq(
      '(',
      $.pattern,
      ',',
      commaList1($.pattern),
      ')'
    ),

    constraint_pattern: $ => seq('(', $.pattern, ':', $.type, ')'),

    array_pattern: $ => seq('[', optional($.array_sub_pattern), ']'),

    array_sub_pattern: $ => choice(
      $.dotdot_pattern,
      commaList1($.pattern),
      seq($.dotdot_pattern, commaList1($.pattern)),
      seq(commaList1($.pattern), $.dotdot_pattern)
    ),

    dotdot_pattern: _ => seq('..', optional(',')),

    struct_pattern: $ => seq('{', optional($.struct_filed_pattern), '}'),

    struct_filed_pattern: $ => choice(
      commaList1($.filed_single_pattern),
      seq(commaList1($.filed_single_pattern), $.dotdot_pattern)
    ),

    filed_single_pattern: $ => choice(
      $.labeled_pattern,
      $.labeled_pattern_pun
    ),

    labeled_pattern: $ => seq($.lowercase_identifier, ':', $.pattern),

    labeled_pattern_pun: $ => $.lowercase_identifier,

    type: $ => choice(
      $.tuple_type,
      $.function_type,
      $.apply_type,
      $.any
    ),

    tuple_type: $ => seq('(', commaList($.type), ')'),

    function_type: $ => seq('(', commaList($.type), ')', '->', $.type),

    apply_type: $ => seq($.qualified_type_identifier, optional($.type_arguments)),

    type_arguments: $ => seq(
      '[',
      commaList1($.type),
      ']'
    ),

    type_parameters: $ => seq(
      '[',
      commaList1($.type_identifier),
      ']'
    ),

    type_annotation: $ => seq(':', $.type),

    return_type: $ => seq('->', $.type),

    parameter: $ => seq($.lowercase_identifier, optional($.type_annotation)),

    parameters: $ => seq(
      '(',
      commaList($.parameter),
      ')'
    ),

    any: _ => '_',
    mutability: _ => 'mut',
    pub: _ => 'pub',

    // Identifiers
    uppercase_identifier: _ => /[\p{Uppercase_Letter}][_\p{XID_Continue}]*/,
    colon_colon_uppercase_identifier: _ => /::[\p{Uppercase_Letter}][_\p{XID_Continue}]*/,
    lowercase_identifier: _ => /[_[\p{XID_Start}--\p{Uppercase_Letter}]][_\p{XID_Continue}]*/v,
    colon_colon_lowercase_identifier: _ => /::[_[\p{XID_Start}--\p{Uppercase_Letter}]][_\p{XID_Continue}]*/v,
    identifier: $ => choice(
      $.uppercase_identifier,
      $.lowercase_identifier,
    ),
    dot_identifier: _ => /\.[_\p{XID_Start}][_\p{XID_Continue}]*/,
    package_identifier: _ => /@[_\p{XID_Start}][_\p{XID_Continue}]*/,

    qualified_identifier: $ => choice(
      $.lowercase_identifier,
      seq($.package_identifier, $.dot_identifier)
    ),
    qualified_type_identifier: $ => choice(
      $.identifier,
      seq($.package_identifier, $.dot_identifier)
    ),

    function_identifier: $ => choice(
      $.lowercase_identifier,
      seq($.qualified_type_identifier, $.colon_colon_lowercase_identifier)
    ),

    type_identifier: $ => choice(
      $.identifier,
      seq($.identifier, ':', $.constraints)
    ),

    constraints: $ => sepBy1('+', $.constraint),

    constraint: $ => $.qualified_type_identifier,

    comment: _ => /\/\/[^/].*/,

    docstring: _ => /\/\/\/.*/,
  }
})

/**
 *
 * @param {RuleOrLiteral} seprator
 * @param {Rule} rule
 * @returns {SeqRule}
 */

function sepBy1(seprator, rule) {
  return seq(
    rule,
    repeat(seq(seprator, rule))
  )
}

/**
 *
 * @param {Rule} rule
 *
 * @return {SeqRule}
 *
 */
function commaList1(rule) {
  return seq(
    rule,
    repeat(seq(',', rule)),
    optional(',')
  );
}

/**
 *
 * @param {Rule} rule
 *
 * @return {ChoiceRule}
 *
 */
function semiList(rule) {
  return optional(semiList1(rule))
}

/**
 *
 * @param {Rule} rule
 *
 * @return {SeqRule}
 *
 */
function semiList1(rule) {
  return seq(
    rule,
    repeat(seq(terminator, rule)),
    optional(terminator)
  );
}

/**
 *
 * @param {Rule} rule
 *
 * @return {ChoiceRule}
 *
 */
function commaList(rule) {
  return optional(commaList1(rule))
}