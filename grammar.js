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
  };
const TYPE_PREC = {
  option: 19,
  error: 18,
  arrow: 17,
};
const multiplicative_operators = ['*', '/', '%'];
const additive_operators = ['+', '-'];
const shift_operators = ['<<', '>>'];
const comparative_operators = ['>', '>=', '<=', '<', '==', '!='];

module.exports = grammar({
  name: 'moonbit',

  extras: $ => [
    $.comment,
    /\s/,
    $._scanner_reset,
  ],

  externals: $ => [
    $._scanner_reset,
    $._automatic_semicolon,
    ';',
    '#|',
    '$|',
    $.float_literal,
    'for',
    $.error_sentinel,
  ],

  word: $ => $._lowercase_identifier,

  rules: {
    structure: $ => list($._semicolon, $.structure_item),

    structure_item: $ => choice(
      $.type_definition,
      $.error_type_definition,
      $.struct_definition,
      $.enum_definition,
      $.value_definition,
      $.const_definition,
      $.function_definition,
      $.test_definition,
      $.trait_definition,
      $.impl_definition,
      $.type_alias_definition,
      $.trait_alias_definition,
      $.function_alias_definition,
    ),

    visibility: $ => choice(
      'priv',
      seq('pub', optional($.pub_attribute)),
    ),

    pub_attribute: _ => seq('(', choice('readonly', 'all', 'open'), ')'),

    derive_item: $ => $.type_name,

    derive_directive: $ => seq(
      'derive',
      '(',
      list(',', $.derive_item),
      ')',
    ),

    type_definition: $ => seq(
      optional($.attributes),
      optional($.visibility),
      optional('extern'),
      'type',
      $.identifier,
      optional($.type_parameters),
      optional($.type),
      optional($.derive_directive),
    ),

    error_type_definition: $ => seq(
      optional($.attributes),
      optional($.visibility),
      optional('extern'),
      'type',
      '!',
      $.identifier,
      optional(choice(
        $.type,
        seq(
          '{',
          list($._semicolon, $.enum_constructor),
          '}',
        ),
      )),
      optional($.derive_directive),
    ),

    type_alias_target: $ => seq(
      $.identifier, optional($.type_parameters),
    ),

    type_alias_targets: $ => choice(
      seq($.identifier, optional($.type_parameters), '=', $.type),
      seq($.package_identifier, $.dot_identifier, optional($.type_parameters)),
      seq($.package_identifier, '.(', list(',', $.type_alias_target), ')'),
    ),

    type_alias_definition: $ => seq(
      optional($.attributes),
      optional($.visibility),
      'typealias',
      $.type_alias_targets,
    ),

    struct_definition: $ => seq(
      optional($.attributes),
      optional($.visibility),
      'struct',
      $.identifier,
      optional($.type_parameters),
      '{',
      list($._semicolon, $.struct_field_declaration),
      '}',
      optional($.derive_directive),
    ),

    struct_field_declaration: $ => seq(
      optional($.visibility),
      optional($.mutability),
      $.lowercase_identifier,
      ':',
      $.type,
    ),

    enum_definition: $ => seq(
      optional($.attributes),
      optional($.visibility),
      'enum',
      $.identifier,
      optional($.type_parameters),
      '{',
      list($._semicolon, $.enum_constructor),
      '}',
      optional($.derive_directive),
    ),

    enum_constructor_payload: $ => choice(
      seq(
        '(',
        list1(',', $.constructor_parameter),
        ')',
      ),
      seq(
        '=',
        $.integer_literal,
      ),
    ),

    enum_constructor: $ => seq(
      $.uppercase_identifier,
      optional($.enum_constructor_payload),
    ),

    constructor_parameter: $ => choice(
      seq(optional('mut'), $.type),
      seq(optional('mut'), $.label, ':', $.type),
    ),

    value_definition: $ => seq(
      optional($.attributes),
      optional($.visibility),
      'let',
      $.lowercase_identifier,
      optional($.type_annotation),
      '=',
      $.expression,
    ),

    const_definition: $ => seq(
      optional($.attributes),
      optional($.pub),
      'const',
      $.uppercase_identifier,
      optional($.type_annotation),
      '=',
      $.expression,
    ),

    external_linkage: $ => seq(
      'extern',
      $.string_literal,
    ),

    external_source: $ => choice(
      $.string_literal,
      seq($.string_literal, $.string_literal),
      $.multiline_string_literal,
    ),

    function_definition: $ => seq(
      optional($.attributes),
      optional($.visibility),
      optional($.external_linkage),
      optional('async'),
      'fn',
      optional($.type_parameters),
      $.function_identifier,
      optional('!'),
      optional($.parameters),
      optional($.return_type),
      choice(
        $.block_expression,
        seq('=', $.external_source),
      ),
    ),

    test_definition: $ => seq(
      optional($.attributes),
      'test',
      optional($.string_literal),
      optional($.parameters),
      $.block_expression,
    ),

    trait_definition: $ => seq(
      optional($.attributes),
      optional($.visibility),
      'trait',
      $.identifier,
      optional($.super_trait_declaration),
      '{',
      list($._semicolon, $.trait_method_declaration),
      '}',
    ),

    super_trait_declaration: $ => seq(
      ':',
      plusList($.qualified_type_identifier),
    ),

    trait_method_parameter: $ => choice(
      $.type,
      seq(
        $.label,
        $.type_annotation,
      ),
    ),

    trait_method_declaration: $ => seq(
      optional('async'),
      $.function_identifier,
      optional('!'),
      optional($.type_parameters),
      '(',
      list(',', $.trait_method_parameter),
      ')',
      optional($.return_type),
      optional($.trait_method_default_annotation),
    ),

    trait_method_default_annotation: _ => seq('=', '_'),

    trait_alias_target: $ => seq(
      $.identifier, optional($.type_parameters),
    ),

    trait_alias_targets: $ => choice(
      seq($.identifier, optional($.type_parameters), '=', $.type),
      seq($.package_identifier, $.dot_identifier, optional($.type_parameters)),
      seq($.package_identifier, '.(', list(',', $.trait_alias_target), optional(','), ')'),
    ),

    trait_alias_definition: $ => seq(
      optional($.attributes),
      optional($.visibility),
      'traitalias',
      $.trait_alias_targets,
    ),

    function_alias_target: $ => choice(
      $.lowercase_identifier,
      seq($.lowercase_identifier, 'as', $.lowercase_identifier),
    ),

    function_alias_targets: $ => choice(
      seq($.lowercase_identifier, '=', $.qualified_identifier),
      $.function_alias_target,
      seq($.package_identifier, $.dot_lowercase_identifier),
      seq($.package_identifier, $.dot_lowercase_identifier, 'as', $.lowercase_identifier),
      seq($.type_name, '::', $.lowercase_identifier),
      seq($.type_name, '::', $.lowercase_identifier, 'as', $.lowercase_identifier),
      seq('(', list1(',', $.function_alias_target), ')'),
      seq($.package_identifier, '.(', list(',', $.function_alias_target), ')'),
      seq($.type_name, '::', '(', list(',', $.function_alias_target), ')'),
    ),

    function_alias_definition: $ => seq(
      optional($.attributes),
      optional($.visibility),
      'fnalias',
      $.function_alias_targets,
    ),

    impl_definition: $ => seq(
      optional($.attributes),
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
      optional('!'),
      $.parameters,
      optional($.return_type),
      choice(
        $.block_expression,
        seq('=', $.external_source),
      ),
    ),

    expression: $ => choice(
      $.if_expression,
      $.while_expression,
      $.loop_expression,
      $.match_expression,
      $.for_expression,
      $.for_in_expression,
      $.try_expression,
      $.try_question_expression,
      $.compound_expression,
    ),

    compound_expression: $ => choice(
      $.range_expression,
      $.postfix_expression,
      $.simple_expression,
      $.binary_expression,
    ),

    postfix_expression: $ => choice(
      $.as_expression,
      $.is_expression,
    ),

    simple_expression: $ => choice(
      $.atomic_expression,
      $.qualified_identifier,
      $.unary_expression,
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
      '_',
      $.quotation_expression_expander,
    ),

    atomic_expression: $ => choice(
      $.string_interpolation,
      $.literal,
    ),

    string_interpolation: $ => seq(
      '"',
      repeat($.string_fragment),
      $.interpolator,
      repeat(choice(
        $.string_fragment,
        $.interpolator,
      )),
      '"',
    ),

    interpolator: $ => seq(
      '\\{',
      $.expression,
      '}',
    ),

    literal: $ => choice(
      $.boolean_literal,
      $.float_literal,
      $.integer_literal,
      $.byte_literal,
      $.char_literal,
      $.string_literal,
      $.bytes_literal,
      $.multiline_string_literal,
      $.quotation_literal_expander,
    ),

    boolean_literal: _ => choice('true', 'false'),

    integer_literal: _ => token(choice(
      /[0-9][0-9_]*(UL|U|L|N)?/,
      /0[xX][0-9a-fA-F_]+(UL|U|L|N)?/,
      /0[oO][0-7_]+(UL|U|L|N)?/,
      /0[bB][01_]+(UL|U|L|N)?/,
    )),

    // integerPart = /[0-9][_0-9]*/,
    // decimalPart = /[_0-9]+/,
    // exponentPart = /[eE][0-9][_0-9]*/,
    // float_literal: _ => /[0-9][_0-9]*\.[_0-9]*([eE][0-9][_0-9]*)?/,

    byte_literal: $ => seq(
      'b\'',
      choice(
        $.escape_sequence,
        token.immediate(/[^']/),
      ),
      '\'',
    ),

    char_literal: $ => seq(
      '\'',
      choice(
        $.escape_sequence,
        token.immediate(/[^']/),
      ),
      '\'',
    ),

    string_literal: $ => choice(
      seq(
        '"',
        repeat($.string_fragment),
        '"',
      ),
      $.quotation_string_expander,
    ),

    bytes_literal: $ => seq(
      'b"',
      repeat($.string_fragment),
      '"',
    ),

    string_fragment: $ => choice(
      $.unescaped_string_fragment,
      $.escape_sequence,
    ),

    unescaped_string_fragment: _ => choice(
      token.immediate(prec(1, /\\[^ntbr'"\\{]/)),
      token.immediate(prec(1, /[^"\\]+/)),
    ),

    escape_sequence: _ => choice(
      // \n, \t, \b, \r, \", \\
      token.immediate(/\\[ntbr'"\\]/),
      // octal
      token.immediate(/\\o[0-7]{1,3}/),
      // hex
      token.immediate(/\\x[0-9a-fA-F]{1,2}/),
      token.immediate(/\\x\{[0-9a-fA-F]+\}/),
      // unicode
      token.immediate(/\\u[0-9a-fA-F]{4}/),
      token.immediate(/\\u\{[0-9a-fA-F]+\}/),
    ),

    multiline_string_content: _ => /[^\n]*/,

    multiline_string_fragment: $ => seq('#|', $.multiline_string_content),

    multiline_interpolation_content: $ => choice(
      token.immediate(prec(1, /\\[^{]/)),
      token.immediate(prec(1, /[^\n\\]+/)),
      $.interpolator,
    ),

    multiline_interpolation_fragment: $ => seq(
      '$|',
      repeat($.multiline_interpolation_content),
    ),

    multiline_string_literal: $ => prec.left(repeat1(choice(
      $.multiline_string_fragment,
      $.multiline_interpolation_fragment,
    ))),

    unary_expression: $ => prec(PREC.unary, seq(
      choice('-', '+'),
      $.simple_expression,
    )),

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
        [PREC.pipe, '|>'],
      ];

      return choice(...table.map(([precedence, operator]) =>
        // @ts-ignore
        prec.left(precedence, seq(
          $.compound_expression,
          // @ts-ignore
          operator,
          $.compound_expression,
        )),
      ));
    },

    struct_expression: $ => choice(
      seq(
        '{',
        choice(
          seq($.labeled_expression_pun, ',', list(',', $.struct_field_expression)),
          seq($.labeled_expression, optional(',')),
          seq($.labeled_expression, ',', list1(',', $.struct_field_expression)),
        ),
        '}',
      ),
      seq($.type_name, '::', '{', list(',', $.struct_field_expression), '}'),
      seq(
        optional(seq($.type_name, '::')),
        '{',
        '..',
        $.expression,
        '}',
      ),
      seq(
        optional(seq($.type_name, '::')),
        '{',
        '..',
        $.expression,
        ',',
        list(',', $.struct_field_expression),
        '}',
      ),
    ),

    struct_field_expression: $ => choice(
      $.labeled_expression,
      $.labeled_expression_pun,
    ),

    labeled_expression: $ => seq($.lowercase_identifier, ':', $.expression),

    labeled_expression_pun: $ => $.lowercase_identifier,

    block_expression: $ => seq(
      '{',
      list($._semicolon, $.statement_expression),
      '}',
    ),

    nonempty_block_expression: $ => seq(
      '{',
      list1($._semicolon, $.statement_expression),
      '}',
    ),

    anonymous_lambda_expression: $ => seq(
      optional('async'),
      'fn',
      optional('!'),
      $.parameters,
      optional($.return_type),
      $.block_expression,
    ),

    anonymous_matrix_lambda_expression: $ => seq(
      optional('async'),
      'fn',
      optional('!'),
      '{',
      list($._semicolon, $.matrix_case_clause),
      '}',
    ),

    pattern_guard: $ => seq(
      'if',
      $.expression,
    ),

    matrix_case_clause: $ => seq(
      list1(',', $.pattern),
      optional($.pattern_guard),
      '=>',
      $.statement_expression,
    ),

    constructor_expression: $ => choice(
      $.uppercase_identifier,
      seq($.package_identifier, $.dot_uppercase_identifier),
      seq($.type_name, '::', $.uppercase_identifier),
    ),

    labelled_argument: $ => seq(
      $.lowercase_identifier, '=', $.expression,
    ),

    forwarded_labelled_argument: $ => $.label,

    optional_argument: $ => seq(
      $.optional_label, '=', $.expression,
    ),

    forwarded_optional_argument: $ => seq(
      $.optional_label,
    ),

    argument: $ => choice(
      $.expression,
      $.labelled_argument,
      $.forwarded_labelled_argument,
      $.optional_argument,
      $.forwarded_optional_argument,
    ),

    apply_operator: $ => choice(
      '!',
      '!!',
      '?',
    ),

    arguments: $ => seq(
      '(',
      list(',', $.argument),
      ')',
    ),

    apply_expression: $ => prec(PREC.apply, choice(
      seq(
        $.lowercase_identifier,
        '?',
        $.arguments,
      ),
      seq(
        $.simple_expression,
        optional($.apply_operator),
        $.arguments,
      )),
    ),

    array_access_expression: $ => prec(PREC.access, seq(
      $.simple_expression,
      '[',
      choice($.expression, seq(optional($.expression), ':', optional($.expression))),
      ']',
    )),

    dot_apply_expression: $ => prec(PREC.apply, seq(
      $.simple_expression,
      $.dot_identifier,
      '(',
      list(',', $.argument),
      ')',
    )),

    dot_dot_apply_expression: $ => prec(PREC.apply, seq(
      $.simple_expression,
      $.dot_dot_identifier,
      '(',
      list(',', $.argument),
      ')',
    )),

    access_expression: $ => prec(PREC.access, seq(
      $.simple_expression,
      $.accessor,
    )),

    accessor: $ => choice(
      $.dot_identifier,
      seq('.', /[0-9]+/),
    ),

    method_expression: $ => seq(
      $.type_name,
      '::',
      $.lowercase_identifier,
    ),

    unit_expression: _ => seq('(', ')'),

    tuple_expression: $ => seq(
      '(',
      list1(',', $.expression),
      ')',
    ),

    constraint_expression: $ => seq(
      '(',
      $.expression,
      ':',
      $.type,
      ')',
    ),

    array_expression: $ => seq(
      '[',
      list(',', seq(optional('..'), $.expression)),
      ']',
    ),

    map_expression: $ => seq(
      '{',
      list(',', $.map_element_expression),
      '}',
    ),

    map_element_key: $ => choice(
      $.literal,
      seq('-', choice($.integer_literal, $.float_literal)),
    ),

    map_element_expression: $ => seq(
      $.map_element_key, ':', $.expression,
    ),

    as_expression: $ => seq(
      $.simple_expression, 'as', $.type_name,
    ),

    is_expression: $ => seq(
      $.simple_expression,
      'is',
      choice(
        $.range_pattern,
        $.simple_pattern,
      ),
    ),

    match_expression: $ => seq(
      'match',
      $.compound_expression,
      '{',
      list($._semicolon, $.case_clause),
      '}',
    ),

    case_clause: $ => seq(
      $.pattern,
      optional($.pattern_guard),
      '=>',
      $.statement_expression,
    ),

    break_expression: $ => seq(
      'break', optional($.label), strictList(',', $.expression),
    ),

    continue_expression: $ => seq(
      'continue', optional($.label), strictList(',', $.expression),
    ),

    try_expression: $ => seq(
      'try',
      $.expression,
      $.try_catch_clause,
      optional($.try_else_clause),
    ),

    try_question_expression: $ => seq(
      'try',
      '?',
      $.expression,
    ),

    try_catch_clause: $ => seq(
      optional(
        seq(
          'catch',
          optional('!'),
        ),
      ),
      '{',
      list($._semicolon, $.case_clause),
      '}',
    ),

    try_else_clause: $ => seq(
      'else',
      '{',
      list($._semicolon, $.case_clause),
      '}',
    ),

    if_expression: $ => seq(
      'if',
      $.compound_expression,
      $.block_expression,
      optional($.else_clause),
    ),

    else_clause: $ => seq(
      'else',
      choice(
        $.block_expression,
        $.if_expression,
      ),
    ),

    statement_expression: $ => choice(
      $.struct_definition,
      $.enum_definition,
      $.type_definition,
      $.let_expression,
      $.let_mut_expression,
      $.guard_expression,
      $.guard_let_expression,
      $.assign_expression,
      $.named_lambda_expression,
      $.named_matrix_expression,
      $.break_expression,
      $.continue_expression,
      $.return_expression,
      $.raise_expression,
      $.expression,
      $.unfinished,
    ),

    unfinished: _ => '...',

    let_expression: $ => seq(
      'let',
      $.pattern,
      optional($.type_annotation),
      '=',
      $.expression,
    ),

    let_mut_expression: $ => seq(
      'let',
      'mut',
      $.lowercase_identifier,
      optional($.type_annotation),
      '=',
      $.expression,
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
      optional($.guard_let_else_expression),
    ),

    guard_let_else_expression: $ => seq(
      'else',
      '{',
      list($._semicolon, $.case_clause),
      '}',
    ),

    assign_operator: $ => choice(
      '=',
      '+=',
      '-=',
      '*=',
      '/=',
      '%=',
    ),

    assign_expression: $ => seq($.left_value, $.assign_operator, $.expression),

    left_value: $ => choice(
      $.qualified_identifier,
      $.access_expression,
      $.array_access_expression,
    ),

    named_lambda_expression: $ => seq(
      optional('async'),
      'fn',
      $.lowercase_identifier,
      optional('!'),
      $.parameters,
      optional($.return_type),
      $.block_expression,
    ),

    named_matrix_expression: $ => seq(
      optional('async'),
      'fn',
      $.lowercase_identifier,
      optional('!'),
      '{',
      list($._semicolon, $.matrix_case_clause),
      '}',
    ),

    loop_label: $ => seq($.label, ':'),

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
      strictList1(',', $.expression),
      '{',
      list($._semicolon, $.matrix_case_clause),
      '}',
    ),

    for_binder: $ => seq(
      $.lowercase_identifier,
      '=',
      $.expression,
    ),

    for_expression: $ => choice(
      seq(
        optional($.loop_label),
        'for',
        strictList(',', $.for_binder),
        $._semicolon,
        optional($.compound_expression),
        $._semicolon,
        strictList(',', $.for_binder),
        $.block_expression,
        optional($.else_clause),
      ),
      seq(
        optional($.loop_label),
        'for',
        strictList(',', $.for_binder),
        $.block_expression,
        optional($.else_clause),
      ),
    ),

    for_in_expression: $ => seq(
      optional($.loop_label),
      'for',
      strictList(',', $.lowercase_identifier),
      'in',
      $.expression,
      $.block_expression,
      optional($.else_clause),
    ),

    range_expression: $ => seq(
      $.simple_expression,
      choice('..<', '..='),
      $.simple_expression,
    ),

    return_expression: $ => seq('return', optional($.expression)),

    raise_expression: $ => seq('raise', optional($.expression)),

    // Patterns

    pattern: $ => choice(
      $.simple_pattern,
      $.range_pattern,
      $.as_pattern,
      $.or_pattern,
    ),

    as_pattern: $ => prec(PREC.as_pattern, seq(
      $.pattern,
      'as',
      $.lowercase_identifier,
    )),

    or_pattern: $ => prec.right(PREC.or_pattern, seq($.pattern, '|', $.pattern)),

    simple_pattern: $ => choice(
      '_',
      '..',
      seq('(', $.pattern, ')'),
      $.literal,
      seq('-', $.integer_literal),
      seq('-', $.float_literal),
      $.lowercase_identifier,
      $.constructor_pattern,
      $.tuple_pattern,
      $.constraint_pattern,
      $.array_pattern,
      $.struct_pattern,
      $.map_pattern,
      $.empty_struct_or_map_pattern,
      $.quotation_pattern_expander,
    ),

    constructor_pattern_argument: $ => choice(
      seq($.lowercase_identifier, '=', $.pattern),
      $.label,
      $.pattern,
    ),

    constructor_pattern: $ => prec(PREC.apply, seq(
      $.constructor_expression,
      optional(seq(
        '(',
        list(',', $.constructor_pattern_argument),
        ')',
      )),
    )),

    tuple_pattern: $ => seq(
      '(',
      $.pattern,
      ',',
      list1(',', $.pattern),
      ')',
    ),

    constraint_pattern: $ => seq('(', $.pattern, ':', $.type, ')'),

    array_pattern: $ => seq('[', list(',', $.array_sub_pattern), ']'),

    array_sub_pattern: $ => choice(
      seq('..', $.qualified_identifier),
      seq('..', $.constructor_expression),
      seq('..', $.string_literal),
      seq('..', $.bytes_literal),
      $.pattern,
    ),

    struct_pattern: $ => seq(
      '{',
      list1(',', $.struct_field_pattern),
      optional('..'),
      '}',
    ),

    struct_field_pattern: $ => choice(
      $.labeled_pattern,
      $.labeled_pattern_pun,
    ),

    labeled_pattern: $ => seq($.lowercase_identifier, ':', $.pattern),

    labeled_pattern_pun: $ => $.lowercase_identifier,

    map_pattern: $ => seq(
      '{',
      list1(',', $.map_element_pattern),
      optional('..'),
      '}',
    ),

    map_element_pattern: $ => seq(
      $.map_element_key,
      optional('?'),
      ':',
      $.pattern,
    ),

    empty_struct_or_map_pattern: _ => seq('{', '}'),

    range_pattern: $ => seq(
      $.simple_pattern,
      choice('..<', '..='),
      $.simple_pattern,
    ),

    type: $ => choice(
      $.tuple_type,
      $.function_type,
      $.apply_type,
      $.option_type,
      $.trait_object_type,
      $.any,
      $.quotation_type_expander,
    ),

    tuple_type: $ => seq('(', list(',', $.type), ')'),

    function_type: $ => prec.right(TYPE_PREC.arrow, seq(
      optional('async'),
      '(',
      list(',', $.type),
      ')',
      $.return_type,
    )),

    apply_type: $ => seq($.qualified_type_identifier, optional($.type_arguments)),

    option_type: $ => prec(TYPE_PREC.option, seq($.type, '?')),

    trait_object_type: $ => seq('&', $.type),

    type_arguments: $ => seq(
      '[',
      list1(',', $.type),
      ']',
    ),

    type_parameters: $ => seq(
      '[',
      list1(',', $.type_identifier),
      ']',
    ),

    type_annotation: $ => seq(':', $.type),

    type_with_error: $ => prec(TYPE_PREC.error, seq($.type, '!', optional($.type))),

    return_type: $ => seq('->', choice($.type, $.type_with_error)),

    label: $ => seq($.lowercase_identifier, '~'),

    optional_label: $ => seq($.lowercase_identifier, '?'),

    positional_parameter: $ => seq(
      $.lowercase_identifier,
      optional($.type_annotation),
    ),

    labelled_parameter: $ => seq(
      $.label,
      optional($.type_annotation),
    ),

    optional_parameter: $ => seq(
      $.optional_label,
      optional($.type_annotation),
    ),

    optional_parameter_with_default: $ => seq(
      $.label,
      optional($.type_annotation),
      '=',
      $.expression,
    ),

    parameter: $ => choice(
      $.positional_parameter,
      $.labelled_parameter,
      $.optional_parameter,
      $.optional_parameter_with_default,
    ),

    parameters: $ => seq(
      '(',
      list(',', $.parameter),
      ')',
    ),

    any: _ => '_',
    mutability: _ => 'mut',
    pub: _ => 'pub',

    // Identifiers
    _uppercase_identifier: _ => /[\p{Uppercase_Letter}][_\p{XID_Continue}]*/v,

    uppercase_identifier: $ => choice(
      $.quotation_uppercase_identifier_expander,
      $._uppercase_identifier,
    ),

    _lowercase_identifier: _ => /[_[\p{XID_Start}--\p{Uppercase_Letter}]][_\p{XID_Continue}]*/v,

    lowercase_identifier: $ => choice(
      $.quotation_lowercase_identifier_expander,
      $._lowercase_identifier,
    ),

    identifier: $ => choice(
      $.uppercase_identifier,
      $.lowercase_identifier,
    ),

    _semicolon: $ => choice($._automatic_semicolon, ';'),

    dot_identifier: $ => choice(
      $.dot_lowercase_identifier,
      $.dot_uppercase_identifier,
    ),

    dot_lowercase_identifier: _ => /\.[_[\p{XID_Start}--\p{Uppercase_Letter}]][_\p{XID_Continue}]*/v,

    dot_uppercase_identifier: _ => /\.[\p{Uppercase_Letter}][_\p{XID_Continue}]*/v,

    dot_dot_identifier: $ => seq('..', /[_\p{XID_Start}][_\p{XID_Continue}]*/v),

    package_identifier: _ => /@[_\p{XID_Start}\/][_\p{XID_Continue}\/]*/v,

    qualified_identifier: $ => choice(
      $.lowercase_identifier,
      seq($.package_identifier, $.dot_lowercase_identifier),
    ),

    qualified_type_identifier: $ => choice(
      $.identifier,
      seq($.package_identifier, $.dot_identifier),
    ),

    type_name: $ => choice(
      $.qualified_type_identifier,
      seq('&', $.qualified_type_identifier),
    ),

    function_identifier: $ => choice(
      $.lowercase_identifier,
      seq($.type_name, '::', $.lowercase_identifier),
    ),

    type_identifier: $ => choice(
      $.identifier,
      seq($.identifier, ':', $.constraints),
    ),

    constraints: $ => list1('+', $.constraint),

    constraint: $ => $.qualified_type_identifier,

    comment: _ => /\/\/.*/,

    attribute_properties: $ => seq(
      '(',
      list(',', $.attribute_property),
      ')',
    ),

    attribute_property: $ => choice(
      seq($.lowercase_identifier, '=', $.attribute_expression),
      $.attribute_expression,
    ),

    attribute_expression: $ => choice(
      $.lowercase_identifier,
      seq($.lowercase_identifier, $.dot_lowercase_identifier),
      seq($.lowercase_identifier, $.attribute_properties),
      seq($.lowercase_identifier, $.dot_lowercase_identifier, $.attribute_properties),
      $.string_literal,
    ),

    attribute: $ => seq('#', $.attribute_expression),

    attributes: $ => repeat1($.attribute),

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
 *
 * @param {RuleOrLiteral} separator
 * @param {Rule} rule
 * @returns {SeqRule}
 */
function list1(separator, rule) {
  return seq(
    rule,
    repeat(seq(separator, choice(rule, '$...'))),
    optional(separator),
  );
}

/**
 * @param {RuleOrLiteral} separator
 * @param {Rule} rule
 * @returns {Rule}
 */
function strictList(separator, rule) {
  return optional(strictList1(separator, rule));
}

/**
 * @param {RuleOrLiteral} separator
 * @param {Rule} rule
 * @returns {SeqRule}
 */
function strictList1(separator, rule) {
  return seq(
    rule,
    repeat(seq(separator, choice(rule, '$...'))),
  );
}

/**
 *
 * @param {Rule} rule
 *
 * @returns {ChoiceRule}
 */
function plusList(rule) {
  return optional(plusList1(rule));
}


/**
 *
 * @param {Rule} rule
 *
 * @returns {SeqRule}
 */
function plusList1(rule) {
  return seq(
    rule,
    repeat(seq('+', rule)),
    // no trailing separator
  );
}
