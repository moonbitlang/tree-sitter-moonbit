/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const
  PREC = {
    apply: 19,
    access: 18,
    unwrap: 18,
    unary: 17,
    multiplicative: 16,
    additive: 15,
    comparative: 14,
    and: 13,
    or: 12,
    pipe: 11,
    orPattern: 10,
    asPattern: 9,
  },
  multiplicative_operators = ['*', '/', '%'],
  additive_operators = ['+', '-'],
  comparative_operators = ['>', '>=', '<=', '<', '==', '!='],
  assignment_operators = ['=', '+=', '-=', '*=', '/='],

  terminator = choice('\n', ';', '\0')

module.exports = grammar({
  name: 'moonbit',

  extras: $ => [
    $.comment,
    $.docstring,
    /\s/
  ],

  externals: $ => [
    $.float_literal,
    $.comment,
    $.docstring,
    $.pipe_operator,
    $.dot_operator,
    $.colon,
    $.colon_colon,
    $.question_operator,
    $.derive,
    $.dot_dot,
    $.multiline_string_separator,
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
      $.test_definition,
      $.trait_definition,
      $.impl_definition,
    ),

    visibility: $ => choice(
      'priv',
      seq('pub', optional($.pub_attribute))
    ),

    pub_attribute: _ => seq('(', 'readonly', ')'),

    derive_item: $ => $.qualified_type_identifier,

    derive: _ => 'derive',

    derive_directive: $ => seq(
      $.derive,
      '(',
      commaList($.derive_item),
      ')',
    ),

    type_definition: $ => seq(
      optional($.visibility),
      'type',
      $.identifier,
      optional($.type_parameters),
      optional($.type),
      optional($.derive_directive),
    ),

    struct_definition: $ => seq(
      optional($.visibility),
      'struct',
      $.identifier,
      optional($.type_parameters),
      '{',
      semiList($.struct_field_declaration),
      '}',
      optional($.derive_directive),
    ),

    struct_field_declaration: $ => seq(
      optional($.visibility),
      optional($.mutability),
      $.lowercase_identifier,
      $.colon,
      $.type
    ),

    enum_definition: $ => seq(
      optional($.visibility),
      'enum',
      $.identifier,
      optional($.type_parameters),
      '{',
      semiList($.enum_constructor),
      '}',
      optional($.derive_directive),
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
      'fn',
      $.function_identifier,
      optional($.type_parameters),
      optional($.parameters),
      optional($.return_type),
      $.block_expression,
    ),

    test_definition: $ => seq(
      'test',
      optional($.string_literal),
      $.block_expression
    ),

    trait_definition: $ => seq(
      optional($.pub),
      'trait',
      $.identifier,
      optional($.super_trait_declaration),
      '{',
      semiList($.trait_method_declaration),
      '}'
    ),

    super_trait_declaration: $ => seq(
      $.colon,
      plusList($.identifier),
    ),

    trait_method_declaration: $ => seq(
      $.function_identifier,
      '(',
      commaList($.type),
      ')',
      $.return_type,
    ),

    impl_definition: $ => seq(
      'impl',
      $.qualified_type_identifier,
      $.colon_colon,
      $.function_identifier,
      $.parameters,
      optional($.return_type),
      $.block_expression,
    ),

    expression: $ => choice(
      $.simple_expression,
      $.if_expression,
      $.loop_expression,
      $.match_expression,
      $.for_expression,
    ),

    unwrap_expression: $ => prec(PREC.unwrap, seq(
      $.simple_expression,
      $.question_operator
    )),

    simple_expression: $ => choice(
      $.atomic_expression,
      $.qualified_identifier,
      $.unary_expression,
      $.binary_expression,
      $.struct_expression,
      $.nonempty_block_expression,
      $.anonymous_lambda_expression,
      $.anonymous_matrix_lambda_expression,
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
      $.unwrap_expression,
      '_'
    ),

    atomic_expression: $ => choice(
      $.string_interpolation,
      $.literal
    ),

    string_interpolation: $ => seq(
      '"',
      repeat($.string_fragment),
      $.interpolator,
      repeat(choice(
        $.string_fragment,
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
      $.byte_literal,
      $.char_literal,
      $.string_literal,
      $.multiline_string_literal,
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

    byte_literal: $ => seq(
      'b\'',
      choice(
        $.escape_sequence,
        token.immediate(/[^']/)
      ),
      '\''
    ),

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
      repeat($.string_fragment),
      '"'
    ),

    string_fragment: $ => choice(
      $.unescaped_string_fragment,
      $.escape_sequence
    ),

    unescaped_string_fragment: _ => choice(
      token.immediate(/\\[^ntb"\\]/),
      token.immediate(/[^"\\]+/),
    ),

    escape_sequence: _ => choice(
      // \n, \t, \b, \", \\
      token.immediate(/\\[ntb"\\]/),
      // octal
      token.immediate(/\\o[0-7]{1,3}/),
      // hex
      token.immediate(/\\x[0-9a-fA-F]{1,2}/),
      token.immediate(/\\x{[0-9a-fA-F]+}/),
      // unicode
      token.immediate(/\\u[0-9a-fA-F]{4}/),
      token.immediate(/\\u{[0-9a-fA-F]+}/),
    ),

    multiline_string_separator: _ => /#\|/,

    multiline_string_fragment: $ => seq($.multiline_string_separator, /[^\n]*/),

    multiline_string_literal: $ => seq(
      $.multiline_string_fragment,
      repeat($.multiline_string_fragment),
    ),

    unary_expression: $ => prec(PREC.unary, seq(
      choice('-', '+'),
      $.expression
    )),

    pipe_operator: _ => '|>',

    binary_expression: $ => {
      const table = [
        [PREC.multiplicative, choice(...multiplicative_operators)],
        [PREC.additive, choice(...additive_operators)],
        [PREC.comparative, choice(...comparative_operators)],
        [PREC.and, '&&'],
        [PREC.or, '||'],
        [PREC.pipe, $.pipe_operator],
      ]

      return choice(...table.map(([precedence, operator]) =>
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
      $.struct_array_expression,
      $.struct_brace_expression,
    ),

    struct_array_expression: $ => seq(
      seq($.qualified_type_identifier, $.colon_colon),
      $.array_expression,
    ),

    struct_brace_expression: $ => seq(
      optional(seq($.qualified_type_identifier, $.colon_colon)),
      choice(
        seq('{', optional($.struct_field_expressions), '}'),
        seq('{', $.dot_dot, $.expression, '}'),
        seq('{', $.dot_dot, $.expression, ',', optional($.struct_field_expressions), '}'),
      ),
    ),

    struct_field_expressions: $ => choice(
      seq($.labeled_expression_pun, ',', commaList($.struct_field_expression)),
      seq($.labeled_expression, optional(',')),
      seq($.labeled_expression, ',', commaList1($.struct_field_expression)),
    ),

    struct_field_expression: $ => choice(
      $.labeled_expression,
      $.labeled_expression_pun
    ),

    labeled_expression: $ => seq($.lowercase_identifier, $.colon, $.expression),

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

    anonymous_matrix_lambda_expression: $ => seq(
      'fn',
      '{',
      semiList($.matrix_case_clause),
      '}',
    ),

    matrix_case_clause: $ => seq(
      $.pattern,
      optional(seq(',', $.pattern)),
      '=>',
      $.case_clause_body,
    ),

    constructor_expression: $ => choice(
      $.uppercase_identifier,
      seq($.qualified_type_identifier, $.colon_colon, $.uppercase_identifier)
    ),

    apply_expression: $ => prec(PREC.apply, seq(
      $.simple_expression,
      '(',
      commaList(seq(optional(seq($.labeled_identifier, '=')), $.expression)),
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
      commaList(seq(optional(seq($.labeled_identifier, '=')), $.expression)),
      ')'
    )),

    access_expression: $ => prec(PREC.access, seq(
      $.simple_expression,
      $.accessor
    )),

    accessor: $ => choice(
      $.dot_identifier,
      seq($.dot_operator, /[0-9]+/)
    ),

    method_expression: $ => seq(
      $.qualified_type_identifier,
      $.colon_colon,
      $.lowercase_identifier
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
      $.colon,
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

    case_clause: $ => seq(
      $.pattern,
      '=>',
      $.case_clause_body,
    ),

    case_clause_body: $ => choice(
      $.assign_expression,
      $.while_expression,
      seq('break', commaList($.expression)),
      seq('continue', commaList($.expression)),
      $.return_expression,
      $.expression,
    ),

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
      $.let_mut_expression,
      $.assign_expression,
      $.named_lambda_expression,
      $.named_matrix_expression,
      $.while_expression,
      seq('break', commaList($.expression)),
      seq('continue', commaList($.expression)),
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

    let_mut_expression: $ => seq(
      'let',
      'mut',
      $.lowercase_identifier,
      optional($.type_annotation),
      '=',
      $.expression
    ),

    assign_expression: $ => seq($.left_value, choice(...assignment_operators), $.expression),

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

    named_matrix_expression: $ => seq(
      'fn',
      $.lowercase_identifier,
      '{',
      semiList($.matrix_case_clause),
      '}',
    ),

    while_expression: $ => seq(
      'while',
      $.simple_expression,
      $.block_expression
    ),

    loop_expression: $ => seq(
      'loop',
      $.simple_expression,
      optional(seq(',', $.simple_expression)),
      '{',
      semiList($.matrix_case_clause),
      '}',
    ),

    for_binder: $ => seq(
      $.lowercase_identifier,
      '=',
      $.expression
    ),

    for_expression: $ => seq(
      'for',
      commaStrictList($.for_binder),
      optional(seq(
        ';',
        optional($.simple_expression),
        ';',
        commaStrictList($.for_binder)
      )),
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

    constraint_pattern: $ => seq('(', $.pattern, $.colon, $.type, ')'),

    array_pattern: $ => seq('[', optional($.array_sub_pattern), ']'),

    array_sub_pattern: $ => choice(
      $.dotdot_pattern,
      commaList1($.pattern),
      seq($.dotdot_pattern, commaList1($.pattern)),
      seq(commaList1($.pattern), $.dotdot_pattern)
    ),

    dotdot_pattern: $ => seq($.dot_dot, optional(',')),

    struct_pattern: $ => seq('{', optional($.struct_field_pattern), '}'),

    struct_field_pattern: $ => choice(
      commaList1($.field_single_pattern),
      seq(commaList1($.field_single_pattern), $.dotdot_pattern)
    ),

    field_single_pattern: $ => choice(
      $.labeled_pattern,
      $.labeled_pattern_pun
    ),

    labeled_pattern: $ => seq($.lowercase_identifier, $.colon, $.pattern),

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

    type_annotation: $ => seq($.colon, $.type),

    return_type: $ => seq('->', $.type),

    parameter: $ => seq(
      choice($.lowercase_identifier, $.labeled_identifier),
      optional($.type_annotation),
      optional(seq('=', $.expression)),
    ),

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
    lowercase_identifier: _ => /[_[\p{XID_Start}--\p{Uppercase_Letter}]][_\p{XID_Continue}]*/v,
    identifier: $ => choice(
      $.uppercase_identifier,
      $.lowercase_identifier,
    ),

    dot_operator: _ => '.',

    // colon_colon: _ => '::',

    dot_identifier: $ => seq($.dot_operator, /[_\p{XID_Start}][_\p{XID_Continue}]*/),

    package_identifier: _ => /@[_\p{XID_Start}][_\p{XID_Continue}]*/,

    labeled_identifier: $ => /~[_\p{XID_Start}][_\p{XID_Continue}]*/,

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
      seq($.qualified_type_identifier, $.colon_colon, $.lowercase_identifier)
    ),

    type_identifier: $ => choice(
      $.identifier,
      seq($.identifier, $.colon, $.constraints)
    ),

    constraints: $ => sepBy1('+', $.constraint),

    constraint: $ => $.qualified_type_identifier,

    comment: _ => /\/\/[^/].*/,

    docstring: _ => /\/\/\/.*/,
  }
})

/**
 *
 * @param {RuleOrLiteral} separator
 * @param {Rule} rule
 * @returns {SeqRule}
 */

function sepBy1(separator, rule) {
  return seq(
    rule,
    repeat(seq(separator, rule))
  )
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
 * @param {Rule} rule
 *
 * @return {ChoiceRule}
 */
function commaStrictList(rule) {
  return optional(commaStrictList1(rule))
}

/**
 * @param {Rule} rule
 *
 * @return {SeqRule}
 */
function commaStrictList1(rule) {
  return seq(
    rule,
    repeat(seq(',', rule)),
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
function plusList(rule) {
  return optional(plusList1(rule))
}


/**
 *
 * @param {Rule} rule
 *
 * @return {SeqRule}
 *
 */
function plusList1(rule) {
  return seq(
    rule,
    repeat(seq('+', rule)),
    // no trailing separator
  );
}
