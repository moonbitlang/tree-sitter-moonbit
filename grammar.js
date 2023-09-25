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
  multiplicative_operators = ['*', '/', '*=', '/=', '%'],
  additive_operators = ['+', '-', '+=', '-='],
  comparative_operators = ['>', '>=', '<=', '<', '==', '!='],

  terminator = choice('\n', ';', '\0')

module.exports = grammar({
  name: 'moonbit',

  extras: $ => [
    $.comment,
    /\s/
  ],

  externals: $ => [
    $.float_literal
  ],

  word: $ => $.lowercase_identifier,

  rules: {
    structure: $ => repeat(seq($.structure_item, terminator)),

    structure_item: $ => choice(
      $.type_defintion,
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

    type_defintion: $ => seq(
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
      repeat(seq($.struct_filed_declaration, terminator)),
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
      repeat(seq($.enum_constructor, terminator)),
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
      repeat(seq($.interface_method_declaration, terminator)),
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
      /[0-9][0-9_]*/,
      /0[xX][0-9a-fA-F_]+/,
      /0[oO][0-7_]+/,
      /0[bB][01_]+/,
    )),

    // integerPart = /[0-9][_0-9]*/,
    // decimalPart = /[_0-9]+/,
    // exponentPart = /[eE][0-9][_0-9]*/,
    // float_literal: _ => /[0-9][_0-9]*\.[_0-9]*([eE][0-9][_0-9]*)?/,

    char_literal: $ => seq(
      '\'',
      choice(
        $.escape_seqence,
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
      $.unescaped_string_fragment,
      $.escape_seqence
    ),

    unescaped_string_fragment: _ => token.immediate(/[^"\\]/),

    escape_seqence: _ => token.immediate(/\\[ntb\\]/),

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
      repeat(seq($.statement_expression, terminator)),
      '}',
    ),

    nonempty_block_expression: $ => seq(
      '{',
      repeat1(seq($.statement_expression, terminator)),
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
      repeat(seq($.case_clause, terminator)),
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

    uppercase_identifier: _ => /[A-Z][_\p{XID_Continue}]*/,
    colon_colon_uppercase_identifier: _ => /::[A-Z][_\p{XID_Continue}]*/,
    lowercase_identifier: _ => /[_a-z\u00AA\u00B5\u00BA\u00C0-\u00D6\u00D8-\u00F6\u00F8-\u02C1\u02C6-\u02D1\u02E0-\u02E4\u02EC\u02EE\u0370-\u0374\u0376\u0377\u037B-\u037D\u037F\u0386\u0388-\u038A\u038C\u038E-\u03A1\u03A3-\u03F5\u03F7-\u0481\u048A-\u052F\u0531-\u0556\u0559\u0560-\u0588\u05D0-\u05EA\u05EF-\u05F2\u0620-\u064A\u066E\u066F\u0671-\u06D3\u06D5\u06E5\u06E6\u06EE\u06EF\u06FA-\u06FC\u06FF\u0710\u0712-\u072F\u074D-\u07A5\u07B1\u07CA-\u07EA\u07F4\u07F5\u07FA\u0800-\u0815\u081A\u0824\u0828\u0840-\u0858\u0860-\u086A\u0870-\u0887\u0889-\u088E\u08A0-\u08C9\u0904-\u0939\u093D\u0950\u0958-\u0961\u0971-\u0980\u0985-\u098C\u098F\u0990\u0993-\u09A8\u09AA-\u09B0\u09B2\u09B6-\u09B9\u09BD\u09CE\u09DC\u09DD\u09DF-\u09E1\u09F0\u09F1\u09FC\u0A05-\u0A0A\u0A0F\u0A10\u0A13-\u0A28\u0A2A-\u0A30\u0A32\u0A33\u0A35\u0A36\u0A38\u0A39\u0A59-\u0A5C\u0A5E\u0A72-\u0A74\u0A85-\u0A8D\u0A8F-\u0A91\u0A93-\u0AA8\u0AAA-\u0AB0\u0AB2\u0AB3\u0AB5-\u0AB9\u0ABD\u0AD0\u0AE0\u0AE1\u0AF9\u0B05-\u0B0C\u0B0F\u0B10\u0B13-\u0B28\u0B2A-\u0B30\u0B32\u0B33\u0B35-\u0B39\u0B3D\u0B5C\u0B5D\u0B5F-\u0B61\u0B71\u0B83\u0B85-\u0B8A\u0B8E-\u0B90\u0B92-\u0B95\u0B99\u0B9A\u0B9C\u0B9E\u0B9F\u0BA3\u0BA4\u0BA8-\u0BAA\u0BAE-\u0BB9\u0BD0\u0C05-\u0C0C\u0C0E-\u0C10\u0C12-\u0C28\u0C2A-\u0C39\u0C3D\u0C58-\u0C5A\u0C5D\u0C60\u0C61\u0C80\u0C85-\u0C8C\u0C8E-\u0C90\u0C92-\u0CA8\u0CAA-\u0CB3\u0CB5-\u0CB9\u0CBD\u0CDD\u0CDE\u0CE0\u0CE1\u0CF1\u0CF2\u0D04-\u0D0C\u0D0E-\u0D10\u0D12-\u0D3A\u0D3D\u0D4E\u0D54-\u0D56\u0D5F-\u0D61\u0D7A-\u0D7F\u0D85-\u0D96\u0D9A-\u0DB1\u0DB3-\u0DBB\u0DBD\u0DC0-\u0DC6\u0E01-\u0E30\u0E32\u0E40-\u0E46\u0E81\u0E82\u0E84\u0E86-\u0E8A\u0E8C-\u0EA3\u0EA5\u0EA7-\u0EB0\u0EB2\u0EBD\u0EC0-\u0EC4\u0EC6\u0EDC-\u0EDF\u0F00\u0F40-\u0F47\u0F49-\u0F6C\u0F88-\u0F8C\u1000-\u102A\u103F\u1050-\u1055\u105A-\u105D\u1061\u1065\u1066\u106E-\u1070\u1075-\u1081\u108E\u10A0-\u10C5\u10C7\u10CD\u10D0-\u10FA\u10FC-\u1248\u124A-\u124D\u1250-\u1256\u1258\u125A-\u125D\u1260-\u1288\u128A-\u128D\u1290-\u12B0\u12B2-\u12B5\u12B8-\u12BE\u12C0\u12C2-\u12C5\u12C8-\u12D6\u12D8-\u1310\u1312-\u1315\u1318-\u135A\u1380-\u138F\u13A0-\u13F5\u13F8-\u13FD\u1401-\u166C\u166F-\u167F\u1681-\u169A\u16A0-\u16EA\u16EE-\u16F8\u1700-\u1711\u171F-\u1731\u1740-\u1751\u1760-\u176C\u176E-\u1770\u1780-\u17B3\u17D7\u17DC\u1820-\u1878\u1880-\u18A8\u18AA\u18B0-\u18F5\u1900-\u191E\u1950-\u196D\u1970-\u1974\u1980-\u19AB\u19B0-\u19C9\u1A00-\u1A16\u1A20-\u1A54\u1AA7\u1B05-\u1B33\u1B45-\u1B4C\u1B83-\u1BA0\u1BAE\u1BAF\u1BBA-\u1BE5\u1C00-\u1C23\u1C4D-\u1C4F\u1C5A-\u1C7D\u1C80-\u1C88\u1C90-\u1CBA\u1CBD-\u1CBF\u1CE9-\u1CEC\u1CEE-\u1CF3\u1CF5\u1CF6\u1CFA\u1D00-\u1DBF\u1E00-\u1F15\u1F18-\u1F1D\u1F20-\u1F45\u1F48-\u1F4D\u1F50-\u1F57\u1F59\u1F5B\u1F5D\u1F5F-\u1F7D\u1F80-\u1FB4\u1FB6-\u1FBC\u1FBE\u1FC2-\u1FC4\u1FC6-\u1FCC\u1FD0-\u1FD3\u1FD6-\u1FDB\u1FE0-\u1FEC\u1FF2-\u1FF4\u1FF6-\u1FFC\u2071\u207F\u2090-\u209C\u2102\u2107\u210A-\u2113\u2115\u2118-\u211D\u2124\u2126\u2128\u212A-\u2139\u213C-\u213F\u2145-\u2149\u214E\u2160-\u2188\u2C00-\u2CE4\u2CEB-\u2CEE\u2CF2\u2CF3\u2D00-\u2D25\u2D27\u2D2D\u2D30-\u2D67\u2D6F\u2D80-\u2D96\u2DA0-\u2DA6\u2DA8-\u2DAE\u2DB0-\u2DB6\u2DB8-\u2DBE\u2DC0-\u2DC6\u2DC8-\u2DCE\u2DD0-\u2DD6\u2DD8-\u2DDE\u3005-\u3007\u3021-\u3029\u3031-\u3035\u3038-\u303C\u3041-\u3096\u309D-\u309F\u30A1-\u30FA\u30FC-\u30FF\u3105-\u312F\u3131-\u318E\u31A0-\u31BF\u31F0-\u31FF\u3400-\u4DBF\u4E00-\uA48C\uA4D0-\uA4FD\uA500-\uA60C\uA610-\uA61F\uA62A\uA62B\uA640-\uA66E\uA67F-\uA69D\uA6A0-\uA6EF\uA717-\uA71F\uA722-\uA788\uA78B-\uA7CA\uA7D0\uA7D1\uA7D3\uA7D5-\uA7D9\uA7F2-\uA801\uA803-\uA805\uA807-\uA80A\uA80C-\uA822\uA840-\uA873\uA882-\uA8B3\uA8F2-\uA8F7\uA8FB\uA8FD\uA8FE\uA90A-\uA925\uA930-\uA946\uA960-\uA97C\uA984-\uA9B2\uA9CF\uA9E0-\uA9E4\uA9E6-\uA9EF\uA9FA-\uA9FE\uAA00-\uAA28\uAA40-\uAA42\uAA44-\uAA4B\uAA60-\uAA76\uAA7A\uAA7E-\uAAAF\uAAB1\uAAB5\uAAB6\uAAB9-\uAABD\uAAC0\uAAC2\uAADB-\uAADD\uAAE0-\uAAEA\uAAF2-\uAAF4\uAB01-\uAB06\uAB09-\uAB0E\uAB11-\uAB16\uAB20-\uAB26\uAB28-\uAB2E\uAB30-\uAB5A\uAB5C-\uAB69\uAB70-\uABE2\uAC00-\uD7A3\uD7B0-\uD7C6\uD7CB-\uD7FB\uF900-\uFA6D\uFA70-\uFAD9\uFB00-\uFB06\uFB13-\uFB17\uFB1D\uFB1F-\uFB28\uFB2A-\uFB36\uFB38-\uFB3C\uFB3E\uFB40\uFB41\uFB43\uFB44\uFB46-\uFBB1\uFBD3-\uFC5D\uFC64-\uFD3D\uFD50-\uFD8F\uFD92-\uFDC7\uFDF0-\uFDF9\uFE71\uFE73\uFE77\uFE79\uFE7B\uFE7D\uFE7F-\uFEFC\uFF21-\uFF3A\uFF41-\uFF5A\uFF66-\uFF9D\uFFA0-\uFFBE\uFFC2-\uFFC7\uFFCA-\uFFCF\uFFD2-\uFFD7\uFFDA-\uFFDC\U00010000-\U0001000B\U0001000D-\U00010026\U00010028-\U0001003A\U0001003C\U0001003D\U0001003F-\U0001004D\U00010050-\U0001005D\U00010080-\U000100FA\U00010140-\U00010174\U00010280-\U0001029C\U000102A0-\U000102D0\U00010300-\U0001031F\U0001032D-\U0001034A\U00010350-\U00010375\U00010380-\U0001039D\U000103A0-\U000103C3\U000103C8-\U000103CF\U000103D1-\U000103D5\U00010400-\U0001049D\U000104B0-\U000104D3\U000104D8-\U000104FB\U00010500-\U00010527\U00010530-\U00010563\U00010570-\U0001057A\U0001057C-\U0001058A\U0001058C-\U00010592\U00010594\U00010595\U00010597-\U000105A1\U000105A3-\U000105B1\U000105B3-\U000105B9\U000105BB\U000105BC\U00010600-\U00010736\U00010740-\U00010755\U00010760-\U00010767\U00010780-\U00010785\U00010787-\U000107B0\U000107B2-\U000107BA\U00010800-\U00010805\U00010808\U0001080A-\U00010835\U00010837\U00010838\U0001083C\U0001083F-\U00010855\U00010860-\U00010876\U00010880-\U0001089E\U000108E0-\U000108F2\U000108F4\U000108F5\U00010900-\U00010915\U00010920-\U00010939\U00010980-\U000109B7\U000109BE\U000109BF\U00010A00\U00010A10-\U00010A13\U00010A15-\U00010A17\U00010A19-\U00010A35\U00010A60-\U00010A7C\U00010A80-\U00010A9C\U00010AC0-\U00010AC7\U00010AC9-\U00010AE4\U00010B00-\U00010B35\U00010B40-\U00010B55\U00010B60-\U00010B72\U00010B80-\U00010B91\U00010C00-\U00010C48\U00010C80-\U00010CB2\U00010CC0-\U00010CF2\U00010D00-\U00010D23\U00010E80-\U00010EA9\U00010EB0\U00010EB1\U00010F00-\U00010F1C\U00010F27\U00010F30-\U00010F45\U00010F70-\U00010F81\U00010FB0-\U00010FC4\U00010FE0-\U00010FF6\U00011003-\U00011037\U00011071\U00011072\U00011075\U00011083-\U000110AF\U000110D0-\U000110E8\U00011103-\U00011126\U00011144\U00011147\U00011150-\U00011172\U00011176\U00011183-\U000111B2\U000111C1-\U000111C4\U000111DA\U000111DC\U00011200-\U00011211\U00011213-\U0001122B\U0001123F\U00011240\U00011280-\U00011286\U00011288\U0001128A-\U0001128D\U0001128F-\U0001129D\U0001129F-\U000112A8\U000112B0-\U000112DE\U00011305-\U0001130C\U0001130F\U00011310\U00011313-\U00011328\U0001132A-\U00011330\U00011332\U00011333\U00011335-\U00011339\U0001133D\U00011350\U0001135D-\U00011361\U00011400-\U00011434\U00011447-\U0001144A\U0001145F-\U00011461\U00011480-\U000114AF\U000114C4\U000114C5\U000114C7\U00011580-\U000115AE\U000115D8-\U000115DB\U00011600-\U0001162F\U00011644\U00011680-\U000116AA\U000116B8\U00011700-\U0001171A\U00011740-\U00011746\U00011800-\U0001182B\U000118A0-\U000118DF\U000118FF-\U00011906\U00011909\U0001190C-\U00011913\U00011915\U00011916\U00011918-\U0001192F\U0001193F\U00011941\U000119A0-\U000119A7\U000119AA-\U000119D0\U000119E1\U000119E3\U00011A00\U00011A0B-\U00011A32\U00011A3A\U00011A50\U00011A5C-\U00011A89\U00011A9D\U00011AB0-\U00011AF8\U00011C00-\U00011C08\U00011C0A-\U00011C2E\U00011C40\U00011C72-\U00011C8F\U00011D00-\U00011D06\U00011D08\U00011D09\U00011D0B-\U00011D30\U00011D46\U00011D60-\U00011D65\U00011D67\U00011D68\U00011D6A-\U00011D89\U00011D98\U00011EE0-\U00011EF2\U00011F02\U00011F04-\U00011F10\U00011F12-\U00011F33\U00011FB0\U00012000-\U00012399\U00012400-\U0001246E\U00012480-\U00012543\U00012F90-\U00012FF0\U00013000-\U0001342F\U00013441-\U00013446\U00014400-\U00014646\U00016800-\U00016A38\U00016A40-\U00016A5E\U00016A70-\U00016ABE\U00016AD0-\U00016AED\U00016B00-\U00016B2F\U00016B40-\U00016B43\U00016B63-\U00016B77\U00016B7D-\U00016B8F\U00016E40-\U00016E7F\U00016F00-\U00016F4A\U00016F50\U00016F93-\U00016F9F\U00016FE0\U00016FE1\U00016FE3\U00017000-\U000187F7\U00018800-\U00018CD5\U00018D00-\U00018D08\U0001AFF0-\U0001AFF3\U0001AFF5-\U0001AFFB\U0001AFFD\U0001AFFE\U0001B000-\U0001B122\U0001B132\U0001B150-\U0001B152\U0001B155\U0001B164-\U0001B167\U0001B170-\U0001B2FB\U0001BC00-\U0001BC6A\U0001BC70-\U0001BC7C\U0001BC80-\U0001BC88\U0001BC90-\U0001BC99\U0001D400-\U0001D454\U0001D456-\U0001D49C\U0001D49E\U0001D49F\U0001D4A2\U0001D4A5\U0001D4A6\U0001D4A9-\U0001D4AC\U0001D4AE-\U0001D4B9\U0001D4BB\U0001D4BD-\U0001D4C3\U0001D4C5-\U0001D505\U0001D507-\U0001D50A\U0001D50D-\U0001D514\U0001D516-\U0001D51C\U0001D51E-\U0001D539\U0001D53B-\U0001D53E\U0001D540-\U0001D544\U0001D546\U0001D54A-\U0001D550\U0001D552-\U0001D6A5\U0001D6A8-\U0001D6C0\U0001D6C2-\U0001D6DA\U0001D6DC-\U0001D6FA\U0001D6FC-\U0001D714\U0001D716-\U0001D734\U0001D736-\U0001D74E\U0001D750-\U0001D76E\U0001D770-\U0001D788\U0001D78A-\U0001D7A8\U0001D7AA-\U0001D7C2\U0001D7C4-\U0001D7CB\U0001DF00-\U0001DF1E\U0001DF25-\U0001DF2A\U0001E030-\U0001E06D\U0001E100-\U0001E12C\U0001E137-\U0001E13D\U0001E14E\U0001E290-\U0001E2AD\U0001E2C0-\U0001E2EB\U0001E4D0-\U0001E4EB\U0001E7E0-\U0001E7E6\U0001E7E8-\U0001E7EB\U0001E7ED\U0001E7EE\U0001E7F0-\U0001E7FE\U0001E800-\U0001E8C4\U0001E900-\U0001E943\U0001E94B\U0001EE00-\U0001EE03\U0001EE05-\U0001EE1F\U0001EE21\U0001EE22\U0001EE24\U0001EE27\U0001EE29-\U0001EE32\U0001EE34-\U0001EE37\U0001EE39\U0001EE3B\U0001EE42\U0001EE47\U0001EE49\U0001EE4B\U0001EE4D-\U0001EE4F\U0001EE51\U0001EE52\U0001EE54\U0001EE57\U0001EE59\U0001EE5B\U0001EE5D\U0001EE5F\U0001EE61\U0001EE62\U0001EE64\U0001EE67-\U0001EE6A\U0001EE6C-\U0001EE72\U0001EE74-\U0001EE77\U0001EE79-\U0001EE7C\U0001EE7E\U0001EE80-\U0001EE89\U0001EE8B-\U0001EE9B\U0001EEA1-\U0001EEA3\U0001EEA5-\U0001EEA9\U0001EEAB-\U0001EEBB\U00020000-\U0002A6DF\U0002A700-\U0002B739\U0002B740-\U0002B81D\U0002B820-\U0002CEA1\U0002CEB0-\U0002EBE0\U0002F800-\U0002FA1D\U00030000-\U0003134A\U00031350-\U000323AF][_\p{XID_Continue}]*/,
    colon_colon_lowercase_identifier: _ => /::[_a-z\u00AA\u00B5\u00BA\u00C0-\u00D6\u00D8-\u00F6\u00F8-\u02C1\u02C6-\u02D1\u02E0-\u02E4\u02EC\u02EE\u0370-\u0374\u0376\u0377\u037B-\u037D\u037F\u0386\u0388-\u038A\u038C\u038E-\u03A1\u03A3-\u03F5\u03F7-\u0481\u048A-\u052F\u0531-\u0556\u0559\u0560-\u0588\u05D0-\u05EA\u05EF-\u05F2\u0620-\u064A\u066E\u066F\u0671-\u06D3\u06D5\u06E5\u06E6\u06EE\u06EF\u06FA-\u06FC\u06FF\u0710\u0712-\u072F\u074D-\u07A5\u07B1\u07CA-\u07EA\u07F4\u07F5\u07FA\u0800-\u0815\u081A\u0824\u0828\u0840-\u0858\u0860-\u086A\u0870-\u0887\u0889-\u088E\u08A0-\u08C9\u0904-\u0939\u093D\u0950\u0958-\u0961\u0971-\u0980\u0985-\u098C\u098F\u0990\u0993-\u09A8\u09AA-\u09B0\u09B2\u09B6-\u09B9\u09BD\u09CE\u09DC\u09DD\u09DF-\u09E1\u09F0\u09F1\u09FC\u0A05-\u0A0A\u0A0F\u0A10\u0A13-\u0A28\u0A2A-\u0A30\u0A32\u0A33\u0A35\u0A36\u0A38\u0A39\u0A59-\u0A5C\u0A5E\u0A72-\u0A74\u0A85-\u0A8D\u0A8F-\u0A91\u0A93-\u0AA8\u0AAA-\u0AB0\u0AB2\u0AB3\u0AB5-\u0AB9\u0ABD\u0AD0\u0AE0\u0AE1\u0AF9\u0B05-\u0B0C\u0B0F\u0B10\u0B13-\u0B28\u0B2A-\u0B30\u0B32\u0B33\u0B35-\u0B39\u0B3D\u0B5C\u0B5D\u0B5F-\u0B61\u0B71\u0B83\u0B85-\u0B8A\u0B8E-\u0B90\u0B92-\u0B95\u0B99\u0B9A\u0B9C\u0B9E\u0B9F\u0BA3\u0BA4\u0BA8-\u0BAA\u0BAE-\u0BB9\u0BD0\u0C05-\u0C0C\u0C0E-\u0C10\u0C12-\u0C28\u0C2A-\u0C39\u0C3D\u0C58-\u0C5A\u0C5D\u0C60\u0C61\u0C80\u0C85-\u0C8C\u0C8E-\u0C90\u0C92-\u0CA8\u0CAA-\u0CB3\u0CB5-\u0CB9\u0CBD\u0CDD\u0CDE\u0CE0\u0CE1\u0CF1\u0CF2\u0D04-\u0D0C\u0D0E-\u0D10\u0D12-\u0D3A\u0D3D\u0D4E\u0D54-\u0D56\u0D5F-\u0D61\u0D7A-\u0D7F\u0D85-\u0D96\u0D9A-\u0DB1\u0DB3-\u0DBB\u0DBD\u0DC0-\u0DC6\u0E01-\u0E30\u0E32\u0E40-\u0E46\u0E81\u0E82\u0E84\u0E86-\u0E8A\u0E8C-\u0EA3\u0EA5\u0EA7-\u0EB0\u0EB2\u0EBD\u0EC0-\u0EC4\u0EC6\u0EDC-\u0EDF\u0F00\u0F40-\u0F47\u0F49-\u0F6C\u0F88-\u0F8C\u1000-\u102A\u103F\u1050-\u1055\u105A-\u105D\u1061\u1065\u1066\u106E-\u1070\u1075-\u1081\u108E\u10A0-\u10C5\u10C7\u10CD\u10D0-\u10FA\u10FC-\u1248\u124A-\u124D\u1250-\u1256\u1258\u125A-\u125D\u1260-\u1288\u128A-\u128D\u1290-\u12B0\u12B2-\u12B5\u12B8-\u12BE\u12C0\u12C2-\u12C5\u12C8-\u12D6\u12D8-\u1310\u1312-\u1315\u1318-\u135A\u1380-\u138F\u13A0-\u13F5\u13F8-\u13FD\u1401-\u166C\u166F-\u167F\u1681-\u169A\u16A0-\u16EA\u16EE-\u16F8\u1700-\u1711\u171F-\u1731\u1740-\u1751\u1760-\u176C\u176E-\u1770\u1780-\u17B3\u17D7\u17DC\u1820-\u1878\u1880-\u18A8\u18AA\u18B0-\u18F5\u1900-\u191E\u1950-\u196D\u1970-\u1974\u1980-\u19AB\u19B0-\u19C9\u1A00-\u1A16\u1A20-\u1A54\u1AA7\u1B05-\u1B33\u1B45-\u1B4C\u1B83-\u1BA0\u1BAE\u1BAF\u1BBA-\u1BE5\u1C00-\u1C23\u1C4D-\u1C4F\u1C5A-\u1C7D\u1C80-\u1C88\u1C90-\u1CBA\u1CBD-\u1CBF\u1CE9-\u1CEC\u1CEE-\u1CF3\u1CF5\u1CF6\u1CFA\u1D00-\u1DBF\u1E00-\u1F15\u1F18-\u1F1D\u1F20-\u1F45\u1F48-\u1F4D\u1F50-\u1F57\u1F59\u1F5B\u1F5D\u1F5F-\u1F7D\u1F80-\u1FB4\u1FB6-\u1FBC\u1FBE\u1FC2-\u1FC4\u1FC6-\u1FCC\u1FD0-\u1FD3\u1FD6-\u1FDB\u1FE0-\u1FEC\u1FF2-\u1FF4\u1FF6-\u1FFC\u2071\u207F\u2090-\u209C\u2102\u2107\u210A-\u2113\u2115\u2118-\u211D\u2124\u2126\u2128\u212A-\u2139\u213C-\u213F\u2145-\u2149\u214E\u2160-\u2188\u2C00-\u2CE4\u2CEB-\u2CEE\u2CF2\u2CF3\u2D00-\u2D25\u2D27\u2D2D\u2D30-\u2D67\u2D6F\u2D80-\u2D96\u2DA0-\u2DA6\u2DA8-\u2DAE\u2DB0-\u2DB6\u2DB8-\u2DBE\u2DC0-\u2DC6\u2DC8-\u2DCE\u2DD0-\u2DD6\u2DD8-\u2DDE\u3005-\u3007\u3021-\u3029\u3031-\u3035\u3038-\u303C\u3041-\u3096\u309D-\u309F\u30A1-\u30FA\u30FC-\u30FF\u3105-\u312F\u3131-\u318E\u31A0-\u31BF\u31F0-\u31FF\u3400-\u4DBF\u4E00-\uA48C\uA4D0-\uA4FD\uA500-\uA60C\uA610-\uA61F\uA62A\uA62B\uA640-\uA66E\uA67F-\uA69D\uA6A0-\uA6EF\uA717-\uA71F\uA722-\uA788\uA78B-\uA7CA\uA7D0\uA7D1\uA7D3\uA7D5-\uA7D9\uA7F2-\uA801\uA803-\uA805\uA807-\uA80A\uA80C-\uA822\uA840-\uA873\uA882-\uA8B3\uA8F2-\uA8F7\uA8FB\uA8FD\uA8FE\uA90A-\uA925\uA930-\uA946\uA960-\uA97C\uA984-\uA9B2\uA9CF\uA9E0-\uA9E4\uA9E6-\uA9EF\uA9FA-\uA9FE\uAA00-\uAA28\uAA40-\uAA42\uAA44-\uAA4B\uAA60-\uAA76\uAA7A\uAA7E-\uAAAF\uAAB1\uAAB5\uAAB6\uAAB9-\uAABD\uAAC0\uAAC2\uAADB-\uAADD\uAAE0-\uAAEA\uAAF2-\uAAF4\uAB01-\uAB06\uAB09-\uAB0E\uAB11-\uAB16\uAB20-\uAB26\uAB28-\uAB2E\uAB30-\uAB5A\uAB5C-\uAB69\uAB70-\uABE2\uAC00-\uD7A3\uD7B0-\uD7C6\uD7CB-\uD7FB\uF900-\uFA6D\uFA70-\uFAD9\uFB00-\uFB06\uFB13-\uFB17\uFB1D\uFB1F-\uFB28\uFB2A-\uFB36\uFB38-\uFB3C\uFB3E\uFB40\uFB41\uFB43\uFB44\uFB46-\uFBB1\uFBD3-\uFC5D\uFC64-\uFD3D\uFD50-\uFD8F\uFD92-\uFDC7\uFDF0-\uFDF9\uFE71\uFE73\uFE77\uFE79\uFE7B\uFE7D\uFE7F-\uFEFC\uFF21-\uFF3A\uFF41-\uFF5A\uFF66-\uFF9D\uFFA0-\uFFBE\uFFC2-\uFFC7\uFFCA-\uFFCF\uFFD2-\uFFD7\uFFDA-\uFFDC\U00010000-\U0001000B\U0001000D-\U00010026\U00010028-\U0001003A\U0001003C\U0001003D\U0001003F-\U0001004D\U00010050-\U0001005D\U00010080-\U000100FA\U00010140-\U00010174\U00010280-\U0001029C\U000102A0-\U000102D0\U00010300-\U0001031F\U0001032D-\U0001034A\U00010350-\U00010375\U00010380-\U0001039D\U000103A0-\U000103C3\U000103C8-\U000103CF\U000103D1-\U000103D5\U00010400-\U0001049D\U000104B0-\U000104D3\U000104D8-\U000104FB\U00010500-\U00010527\U00010530-\U00010563\U00010570-\U0001057A\U0001057C-\U0001058A\U0001058C-\U00010592\U00010594\U00010595\U00010597-\U000105A1\U000105A3-\U000105B1\U000105B3-\U000105B9\U000105BB\U000105BC\U00010600-\U00010736\U00010740-\U00010755\U00010760-\U00010767\U00010780-\U00010785\U00010787-\U000107B0\U000107B2-\U000107BA\U00010800-\U00010805\U00010808\U0001080A-\U00010835\U00010837\U00010838\U0001083C\U0001083F-\U00010855\U00010860-\U00010876\U00010880-\U0001089E\U000108E0-\U000108F2\U000108F4\U000108F5\U00010900-\U00010915\U00010920-\U00010939\U00010980-\U000109B7\U000109BE\U000109BF\U00010A00\U00010A10-\U00010A13\U00010A15-\U00010A17\U00010A19-\U00010A35\U00010A60-\U00010A7C\U00010A80-\U00010A9C\U00010AC0-\U00010AC7\U00010AC9-\U00010AE4\U00010B00-\U00010B35\U00010B40-\U00010B55\U00010B60-\U00010B72\U00010B80-\U00010B91\U00010C00-\U00010C48\U00010C80-\U00010CB2\U00010CC0-\U00010CF2\U00010D00-\U00010D23\U00010E80-\U00010EA9\U00010EB0\U00010EB1\U00010F00-\U00010F1C\U00010F27\U00010F30-\U00010F45\U00010F70-\U00010F81\U00010FB0-\U00010FC4\U00010FE0-\U00010FF6\U00011003-\U00011037\U00011071\U00011072\U00011075\U00011083-\U000110AF\U000110D0-\U000110E8\U00011103-\U00011126\U00011144\U00011147\U00011150-\U00011172\U00011176\U00011183-\U000111B2\U000111C1-\U000111C4\U000111DA\U000111DC\U00011200-\U00011211\U00011213-\U0001122B\U0001123F\U00011240\U00011280-\U00011286\U00011288\U0001128A-\U0001128D\U0001128F-\U0001129D\U0001129F-\U000112A8\U000112B0-\U000112DE\U00011305-\U0001130C\U0001130F\U00011310\U00011313-\U00011328\U0001132A-\U00011330\U00011332\U00011333\U00011335-\U00011339\U0001133D\U00011350\U0001135D-\U00011361\U00011400-\U00011434\U00011447-\U0001144A\U0001145F-\U00011461\U00011480-\U000114AF\U000114C4\U000114C5\U000114C7\U00011580-\U000115AE\U000115D8-\U000115DB\U00011600-\U0001162F\U00011644\U00011680-\U000116AA\U000116B8\U00011700-\U0001171A\U00011740-\U00011746\U00011800-\U0001182B\U000118A0-\U000118DF\U000118FF-\U00011906\U00011909\U0001190C-\U00011913\U00011915\U00011916\U00011918-\U0001192F\U0001193F\U00011941\U000119A0-\U000119A7\U000119AA-\U000119D0\U000119E1\U000119E3\U00011A00\U00011A0B-\U00011A32\U00011A3A\U00011A50\U00011A5C-\U00011A89\U00011A9D\U00011AB0-\U00011AF8\U00011C00-\U00011C08\U00011C0A-\U00011C2E\U00011C40\U00011C72-\U00011C8F\U00011D00-\U00011D06\U00011D08\U00011D09\U00011D0B-\U00011D30\U00011D46\U00011D60-\U00011D65\U00011D67\U00011D68\U00011D6A-\U00011D89\U00011D98\U00011EE0-\U00011EF2\U00011F02\U00011F04-\U00011F10\U00011F12-\U00011F33\U00011FB0\U00012000-\U00012399\U00012400-\U0001246E\U00012480-\U00012543\U00012F90-\U00012FF0\U00013000-\U0001342F\U00013441-\U00013446\U00014400-\U00014646\U00016800-\U00016A38\U00016A40-\U00016A5E\U00016A70-\U00016ABE\U00016AD0-\U00016AED\U00016B00-\U00016B2F\U00016B40-\U00016B43\U00016B63-\U00016B77\U00016B7D-\U00016B8F\U00016E40-\U00016E7F\U00016F00-\U00016F4A\U00016F50\U00016F93-\U00016F9F\U00016FE0\U00016FE1\U00016FE3\U00017000-\U000187F7\U00018800-\U00018CD5\U00018D00-\U00018D08\U0001AFF0-\U0001AFF3\U0001AFF5-\U0001AFFB\U0001AFFD\U0001AFFE\U0001B000-\U0001B122\U0001B132\U0001B150-\U0001B152\U0001B155\U0001B164-\U0001B167\U0001B170-\U0001B2FB\U0001BC00-\U0001BC6A\U0001BC70-\U0001BC7C\U0001BC80-\U0001BC88\U0001BC90-\U0001BC99\U0001D400-\U0001D454\U0001D456-\U0001D49C\U0001D49E\U0001D49F\U0001D4A2\U0001D4A5\U0001D4A6\U0001D4A9-\U0001D4AC\U0001D4AE-\U0001D4B9\U0001D4BB\U0001D4BD-\U0001D4C3\U0001D4C5-\U0001D505\U0001D507-\U0001D50A\U0001D50D-\U0001D514\U0001D516-\U0001D51C\U0001D51E-\U0001D539\U0001D53B-\U0001D53E\U0001D540-\U0001D544\U0001D546\U0001D54A-\U0001D550\U0001D552-\U0001D6A5\U0001D6A8-\U0001D6C0\U0001D6C2-\U0001D6DA\U0001D6DC-\U0001D6FA\U0001D6FC-\U0001D714\U0001D716-\U0001D734\U0001D736-\U0001D74E\U0001D750-\U0001D76E\U0001D770-\U0001D788\U0001D78A-\U0001D7A8\U0001D7AA-\U0001D7C2\U0001D7C4-\U0001D7CB\U0001DF00-\U0001DF1E\U0001DF25-\U0001DF2A\U0001E030-\U0001E06D\U0001E100-\U0001E12C\U0001E137-\U0001E13D\U0001E14E\U0001E290-\U0001E2AD\U0001E2C0-\U0001E2EB\U0001E4D0-\U0001E4EB\U0001E7E0-\U0001E7E6\U0001E7E8-\U0001E7EB\U0001E7ED\U0001E7EE\U0001E7F0-\U0001E7FE\U0001E800-\U0001E8C4\U0001E900-\U0001E943\U0001E94B\U0001EE00-\U0001EE03\U0001EE05-\U0001EE1F\U0001EE21\U0001EE22\U0001EE24\U0001EE27\U0001EE29-\U0001EE32\U0001EE34-\U0001EE37\U0001EE39\U0001EE3B\U0001EE42\U0001EE47\U0001EE49\U0001EE4B\U0001EE4D-\U0001EE4F\U0001EE51\U0001EE52\U0001EE54\U0001EE57\U0001EE59\U0001EE5B\U0001EE5D\U0001EE5F\U0001EE61\U0001EE62\U0001EE64\U0001EE67-\U0001EE6A\U0001EE6C-\U0001EE72\U0001EE74-\U0001EE77\U0001EE79-\U0001EE7C\U0001EE7E\U0001EE80-\U0001EE89\U0001EE8B-\U0001EE9B\U0001EEA1-\U0001EEA3\U0001EEA5-\U0001EEA9\U0001EEAB-\U0001EEBB\U00020000-\U0002A6DF\U0002A700-\U0002B739\U0002B740-\U0002B81D\U0002B820-\U0002CEA1\U0002CEB0-\U0002EBE0\U0002F800-\U0002FA1D\U00030000-\U0003134A\U00031350-\U000323AF][_\p{XID_Continue}]*/,
    identifier: _ => /[_\p{XID_Start}][_\p{XID_Continue}]*/,
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

    comment: _ => /\/\/.*/
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
function commaList(rule) {
  return optional(commaList1(rule))
}