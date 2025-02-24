/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const
  PREC = {
    apply: 19,
    access: 18,
    unary: 17,
    multiplicative: 16,
    additive: 15,
    shift: 14,
    comparative: 13,
    bitwise_and: 12,
    bitwise_xor: 11,
    bitwise_or: 10,
    and: 9,
    or: 8,
    pipe: 7,
    or_pattern: 6,
    as_pattern: 5,
  },
  TYPE_PREC = {
    option: 19,
    error: 18,
    arrow: 17,
  },
  multiplicative_operators = ['*', '/', '%'],
  additive_operators = ['+', '-'],
  shift_operators = ['<<', '>>'],
  comparative_operators = ['>', '>=', '<=', '<', '==', '!='],
  assignment_operators = ['=', '+=', '-=', '*=', '/=', '%='],

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
    $.dot,
    $.colon,
    $.colon_colon,
    $.question_operator,
    $.derive,
    $.dot_dot,
    $.multiline_string_separator,
    $.dot_dot_lt,
    $.dot_dot_eq,
    $.is,
  ],

  word: $ => $.lowercase_identifier,

  rules: {
    structure: $ => semiList($.structure_item),

    structure_item: $ => choice(
      $.type_definition,
      $.error_type_definition,
      $.type_alias_definition,
      $.struct_definition,
      $.enum_definition,
      $.value_definition,
      $.const_definition,
      $.function_definition,
      $.test_definition,
      $.trait_definition,
      $.impl_definition,
    ),

    visibility: $ => choice(
      'priv',
      seq('pub', optional($.pub_attribute))
    ),

    pub_attribute: _ => seq('(', choice('readonly', 'all', 'open'), ')'),

    derive_item: $ => $.type_name,

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

    error_type_definition: $ => seq(
      optional($.visibility),
      'type',
      '!',
      $.identifier,
      optional(choice(
        $.type,
        seq(
          '{',
          semiList($.enum_constructor),
          '}',
        )
      )),
      optional($.derive_directive),
    ),

    type_alias_definition: $ => seq(
      optional($.visibility),
      'typealias',
      $.identifier,
      optional($.type_parameters),
      '=',
      $.type,
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
        commaList1(choice($.type, seq($.parameter_label, $.colon, $.type))),
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

    const_definition: $ => seq(
      optional($.pub),
      'const',
      $.uppercase_identifier,
      optional($.type_annotation),
      '=',
      $.expression
    ),

    external_linkage: $ => seq(
      'extern',
      $.string_literal
    ),

    external_source: $ => choice(
      $.string_literal,
      seq($.string_literal, $.string_literal),
      $.multiline_string_literal,
    ),

    function_definition: $ => seq(
      optional($.visibility),
      optional($.external_linkage),
      optional('async'),
      'fn',
      $.function_identifier,
      optional('!'),
      optional($.type_parameters),
      optional($.parameters),
      optional($.return_type),
      choice(
        $.block_expression,
        seq('=', $.external_source)
      )
    ),

    test_definition: $ => seq(
      'test',
      optional($.string_literal),
      optional($.parameters),
      $.block_expression
    ),

    trait_definition: $ => seq(
      optional($.visibility),
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

    trait_method_parameter: $ => choice(
      $.type,
      seq(
        $.parameter_label,
        $.type_annotation,
      ),
    ),

    trait_method_declaration: $ => seq(
      $.function_identifier,
      '(',
      commaList($.trait_method_parameter),
      ')',
      $.return_type,
    ),

    impl_definition: $ => seq(
      optional($.visibility),
      'impl',
      optional($.type_parameters),
      $.type_name,
      optional(seq(
        'for',
        $.type,
      )),
      'with',
      $.function_identifier,
      $.parameters,
      optional($.return_type),
      $.block_expression,
    ),

    expression: $ => choice(
      $.if_expression,
      $.loop_expression,
      $.match_expression,
      $.for_expression,
      $.for_in_expression,
      $.try_expression,
      $.pipeline_expression,
    ),

    pipeline_expression: $ => choice(
      seq($.pipeline_expression, $.pipe_operator, $.compound_expression),
      $.compound_expression,
    ),

    compound_expression: $ => choice(
      $.range_expression,
      $.postfix_expression,
      $.simple_expression,
    ),

    postfix_expression: $ => choice(
      $.as_expression,
      $.is_expression,
    ),

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
      $.dot_dot_apply_expression,
      $.access_expression,
      $.method_expression,
      $.unit_expression,
      $.tuple_expression,
      $.constraint_expression,
      $.array_expression,
      $.map_expression,
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
      '\\{',
      $.expression,
      '}'
    ),

    literal: $ => choice(
      $.boolean_literal,
      $.float_literal,
      $.integer_literal,
      $.bigint_literal,
      $.byte_literal,
      $.char_literal,
      $.string_literal,
      $.bytes_literal,
      $.multiline_string_literal,
    ),

    boolean_literal: _ => choice('true', 'false'),

    integer_literal: _ => token(choice(
      /[0-9][0-9_]*U?L?/,
      /0[xX][0-9a-fA-F_]+U?L?/,
      /0[oO][0-7_]+U?L?/,
      /0[bB][01_]+U?L?/,
    )),

    bigint_literal: _ => token(choice(
      /[0-9][0-9_]*N/,
      /0[xX][0-9a-fA-F_]+N/,
      /0[oO][0-7_]+N/,
      /0[bB][01_]+N/,
    )),

    // integerPart = /[0-9][_0-9]*/,
    // decimalPart = /[_0-9]+/,
    // exponentPart = /[eE][0-9][_0-9]*/,
    // float_literal: _ => /[0-9][_0-9]*\.[_0-9]*([eE][0-9][_0-9]*)?/,

    byte_literal: $ => seq(
      'b\'',
      choice(
        $.byte_char_escape_sequence,
        token.immediate(/[^']/)
      ),
      '\''
    ),

    char_literal: $ => seq(
      '\'',
      choice(
        $.byte_char_escape_sequence,
        token.immediate(/[^']/)
      ),
      '\''
    ),

    byte_char_escape_sequence: _ => choice(
      // \n, \t, \b, \r, \', \\
      token.immediate(/\\[ntbr'\\]/),
      // octal
      token.immediate(/\\o[0-7]{1,3}/),
      // hex
      token.immediate(/\\x[0-9a-fA-F]{1,2}/),
      token.immediate(/\\x\{[0-9a-fA-F]+\}/),
      // unicode
      token.immediate(/\\u[0-9a-fA-F]{4}/),
      token.immediate(/\\u\{[0-9a-fA-F]+\}/),
    ),

    string_literal: $ => seq(
      '"',
      repeat($.string_fragment),
      '"'
    ),

    bytes_literal: $ => seq(
      'b"',
      repeat($.string_fragment),
      '"'
    ),

    string_fragment: $ => choice(
      $.unescaped_string_fragment,
      $.escape_sequence
    ),

    unescaped_string_fragment: _ => choice(
      token.immediate(/\\[^ntbr"\\{]/),
      token.immediate(/[^"\\]+/),
    ),

    escape_sequence: _ => choice(
      // \n, \t, \b, \r, \", \\
      token.immediate(/\\[ntbr"\\]/),
      // octal
      token.immediate(/\\o[0-7]{1,3}/),
      // hex
      token.immediate(/\\x[0-9a-fA-F]{1,2}/),
      token.immediate(/\\x\{[0-9a-fA-F]+\}/),
      // unicode
      token.immediate(/\\u[0-9a-fA-F]{4}/),
      token.immediate(/\\u\{[0-9a-fA-F]+\}/),
    ),

    multiline_string_separator: _ => /#\|/,

    multiline_string_content: _ => /[^\n]*/,

    multiline_string_fragment: $ => seq($.multiline_string_separator, $.multiline_string_content),

    multiline_string_literal: $ => seq(
      $.multiline_string_fragment,
      repeat($.multiline_string_fragment),
    ),

    unary_expression: $ => prec(PREC.unary, seq(
      choice('-', '+'),
      $.simple_expression
    )),

    pipe_operator: _ => '|>',

    binary_expression: $ => {
      const table = [
        [PREC.multiplicative, choice(...multiplicative_operators)],
        [PREC.additive, choice(...additive_operators)],
        [PREC.shift, choice(...shift_operators)],
        [PREC.comparative, choice(...comparative_operators)],
        [PREC.bitwise_and, '&'],
        [PREC.bitwise_xor, '^'],
        [PREC.bitwise_or, '|'],
        [PREC.and, '&&'],
        [PREC.or, '||'],
        [PREC.pipe, $.pipe_operator],
      ]

      return choice(...table.map(([precedence, operator]) =>
        //@ts-ignore
        prec.left(precedence, seq(
          $.simple_expression,
          //@ts-ignore
          operator,
          $.simple_expression
        ))
      ))
    },

    struct_expression: $ => seq(
      optional(seq($.qualified_type_identifier, $.colon_colon)),
      choice(
        seq('{', $.struct_field_expressions, '}'),
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
      optional('async'),
      'fn',
      optional('!'),
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
      commaList1($.pattern),
      '=>',
      $.statement_expression,
    ),

    constructor_expression: $ => choice(
      $.uppercase_identifier,
      seq($.qualified_type_identifier, $.colon_colon, $.uppercase_identifier)
    ),

    argument_label: $ => seq(
      $.simple_expression,
      optional($.question_operator),
      '='
    ),

    argument_pun: $ => seq(
      $.simple_expression,
      choice('~', $.question_operator)
    ),

    argument: $ => choice(
      seq(
        optional($.argument_label),
        $.expression
      ),
      $.argument_pun,
    ),

    apply_operator: $ => choice(
      '!',
      '!!',
      $.question_operator
    ),

    apply_expression: $ => prec(PREC.apply, seq(
      $.simple_expression,
      optional($.apply_operator),
      '(',
      commaList($.argument),
      ')'
    )),

    array_access_expression: $ => prec(PREC.access, seq(
      $.simple_expression,
      '[',
      choice($.expression, seq(optional($.expression), $.colon, optional($.expression))),
      ']'
    )),

    dot_apply_expression: $ => prec(PREC.apply, seq(
      $.simple_expression,
      $.dot_identifier,
      '(',
      commaList($.argument),
      ')'
    )),

    dot_dot_apply_expression: $ => prec(PREC.apply, seq(
      $.simple_expression,
      $.dot_dot_identifier,
      '(',
      commaList($.argument),
      ')'
    )),

    access_expression: $ => prec(PREC.access, seq(
      $.simple_expression,
      $.accessor
    )),

    accessor: $ => choice(
      $.dot_identifier,
      seq($.dot, /[0-9]+/)
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

    map_expression: $ => seq(
      '{',
      commaList($.map_element_expression),
      '}'
    ),

    map_element_key: $ => choice(
      $.literal,
      seq('-', choice($.integer_literal, $.float_literal)),
    ),

    map_element_expression: $ => seq(
      $.map_element_key, $.colon, $.expression,
    ),

    as_expression: $ => seq(
      $.simple_expression, 'as', $.type_name
    ),

    is_expression: $ => seq(
      $.simple_expression,
      $.is,
      choice(
        $.range_pattern,
        $.simple_pattern,
      )
    ),

    match_expression: $ => seq(
      'match',
      $.compound_expression,
      '{',
      semiList($.case_clause),
      '}'
    ),

    case_clause: $ => seq(
      $.pattern,
      '=>',
      $.statement_expression,
    ),

    break_expression: $ => seq(
      'break', optional($.parameter_label), commaList($.expression)
    ),

    continue_expression: $ => seq(
      'continue', optional($.parameter_label), commaList($.expression)
    ),

    try_expression: $ => seq(
      'try',
      $.expression,
      'catch',
      '{',
      semiList($.case_clause),
      '}',
      optional($.else_clause)
    ),

    if_expression: $ => seq(
      'if',
      $.compound_expression,
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
      $.struct_definition,
      $.let_expression,
      $.let_mut_expression,
      $.guard_expression,
      $.guard_let_expression,
      $.assign_expression,
      $.named_lambda_expression,
      $.named_matrix_expression,
      $.while_expression,
      $.break_expression,
      $.continue_expression,
      $.return_expression,
      $.raise_expression,
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

    guard_expression: $ => seq(
      'guard',
      $.compound_expression,
      optional($.guard_else_expression),
    ),

    guard_else_expression: $ => seq(
      'else',
      $.block_expression,
    ),

    guard_let_expression: $ => seq(
      'guard',
      'let',
      $.pattern,
      '=',
      $.simple_expression,
      optional($.guard_let_else_expression)
    ),

    guard_let_else_expression: $ => seq(
      'else',
      '{',
      semiList($.case_clause),
      '}'
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

    loop_label: $ => seq(
      $.lowercase_identifier,
      '~:'
    ),

    while_expression: $ => seq(
      optional($.loop_label),
      'while',
      $.compound_expression,
      $.block_expression,
      optional($.else_clause),
    ),

    loop_expression: $ => seq(
      optional($.loop_label),
      'loop',
      commaStrictList1($.expression),
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
      optional($.loop_label),
      'for',
      commaStrictList($.for_binder),
      optional(seq(
        terminator,
        optional($.compound_expression),
        terminator,
        commaStrictList($.for_binder)
      )),
      $.block_expression,
      optional($.else_clause),
    ),

    for_in_expression: $ => seq(
      optional($.loop_label),
      'for',
      commaStrictList($.lowercase_identifier),
      'in',
      $.expression,
      $.block_expression,
      optional($.else_clause),
    ),

    range_expression: $ => seq(
      $.simple_expression,
      choice($.dot_dot_lt, $.dot_dot_eq),
      $.simple_expression
    ),

    return_expression: $ => seq('return', optional($.expression)),

    raise_expression: $ => seq('raise', optional($.expression)),

    // Patterns

    pattern: $ => choice(
      $.simple_pattern,
      $.range_pattern,
      $.as_pattern,
      $.or_pattern
    ),

    as_pattern: $ => prec(PREC.as_pattern, seq(
      $.pattern,
      'as',
      $.lowercase_identifier
    )),

    or_pattern: $ => prec.right(PREC.or_pattern, seq($.pattern, '|', $.pattern)),

    simple_pattern: $ => choice(
      '_',
      $.dot_dot,
      seq('(', $.pattern, ')'),
      $.literal,
      $.lowercase_identifier,
      $.constructor_pattern,
      $.tuple_pattern,
      $.constraint_pattern,
      $.array_pattern,
      $.struct_pattern,
      $.map_pattern,
      $.empty_struct_or_map_pattern,
    ),

    constructor_pattern_argument: $ => choice(
      seq($.lowercase_identifier, '=', $.pattern),
      $.parameter_label,
      $.pattern,
    ),

    constructor_pattern: $ => prec(PREC.apply, seq(
      $.constructor_expression,
      optional(seq(
        '(',
        commaList($.constructor_pattern_argument),
        ')'
      ))
    )),

    tuple_pattern: $ => seq(
      '(',
      $.pattern,
      ',',
      commaList1($.pattern),
      ')'
    ),

    constraint_pattern: $ => seq('(', $.pattern, $.colon, $.type, ')'),

    array_pattern: $ => seq('[', commaList($.array_sub_pattern), ']'),

    array_sub_pattern: $ => choice(
      seq($.dot_dot, $.qualified_identifier),
      seq($.dot_dot, $.string_literal),
      $.pattern,
    ),

    struct_pattern: $ => seq(
      '{',
      commaList1($.struct_field_pattern),
      optional($.dot_dot),
      '}'
    ),

    struct_field_pattern: $ => choice(
      $.labeled_pattern,
      $.labeled_pattern_pun
    ),

    labeled_pattern: $ => seq($.lowercase_identifier, $.colon, $.pattern),

    labeled_pattern_pun: $ => $.lowercase_identifier,

    map_pattern: $ => seq(
      '{',
      commaList1($.map_element_pattern),
      optional($.dot_dot),
      '}',
    ),

    map_element_pattern: $ => seq(
      $.map_element_key,
      optional($.question_operator),
      $.colon,
      $.pattern
    ),

    empty_struct_or_map_pattern: _ => seq('{', '}'),

    range_pattern: $ => seq(
      $.simple_pattern,
      choice($.dot_dot_lt, $.dot_dot_eq),
      $.simple_pattern
    ),

    type: $ => choice(
      $.tuple_type,
      $.function_type,
      $.apply_type,
      $.option_type,
      $.trait_object_type,
      $.any
    ),

    tuple_type: $ => seq('(', commaList($.type), ')'),

    function_type: $ => prec.right(TYPE_PREC.arrow, seq(
      optional('async'),
      '(',
      commaList($.type),
      ')',
      $.return_type
    )),

    apply_type: $ => seq($.qualified_type_identifier, optional($.type_arguments)),

    option_type: $ => prec(TYPE_PREC.option, seq($.type, $.question_operator)),

    trait_object_type: $ => seq('&', $.type),

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

    type_with_error: $ => prec(TYPE_PREC.error, seq($.type, '!', optional($.type))),

    return_type: $ => seq('->', choice($.type, $.type_with_error)),

    parameter_label: $ => seq(
      $.lowercase_identifier,
      '~',
    ),

    optional_parameter_label: $ => seq(
      $.lowercase_identifier,
      $.question_operator
    ),

    parameter: $ => seq(
      choice(
        $.optional_parameter_label,
        $.parameter_label,
        $.lowercase_identifier,
      ),
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

    dot: _ => '.',

    dot_dot: _ => '..',

    dot_dot_lt: _ => '..<',

    dot_dot_eq: _ => '..=',

    colon: _ => ':',
    // colon_colon: _ => '::',

    dot_identifier: $ => seq($.dot, /[_\p{XID_Start}][_\p{XID_Continue}]*/),

    dot_dot_identifier: $ => seq($.dot_dot, /[_\p{XID_Start}][_\p{XID_Continue}]*/),

    package_identifier: _ => /@[_\p{XID_Start}/][_\p{XID_Continue}/]*/,

    qualified_identifier: $ => choice(
      $.lowercase_identifier,
      seq($.package_identifier, $.dot_identifier)
    ),

    qualified_type_identifier: $ => choice(
      $.identifier,
      seq($.package_identifier, $.dot_identifier)
    ),

    type_name: $ => choice(
      $.qualified_type_identifier,
      seq('&', $.qualified_type_identifier)
    ),

    function_identifier: $ => choice(
      $.lowercase_identifier,
      seq($.type_name, $.colon_colon, $.lowercase_identifier)
    ),

    type_identifier: $ => choice(
      $.identifier,
      seq($.identifier, $.colon, $.constraints)
    ),

    constraints: $ => sepBy1('+', $.constraint),

    constraint: $ => $.qualified_type_identifier,

    comment: _ => /\/\/.*/,

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
