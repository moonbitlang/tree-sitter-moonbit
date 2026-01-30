/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const multiplicative_operators = ["*", "/", "%"];
const additive_operators = ["+", "-"];
const shift_operators = ["<<", ">>"];
const comparative_operators = [">", ">=", "<=", "<", "==", "!="];

module.exports = grammar({
  name: "moonbit",

  extras: ($) => [$.comment, /\s/, $._scanner_reset],

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

  supertypes: ($) => [
    $._expression,
    $._statement_expression,
    $._structure_item,
    $._type,
    $._pattern,
  ],

  precedences: ($) => [
    [
      $.apply_expression,
      $.access_expression,
      $.unary_expression,
      "multiplicative",
      "additive",
      "shift",
      "comparative",
      "bitwise_and",
      "bitwise_xor",
      "bitwise_or",
      $.is_expression,
      "and",
      "or",
      "pipe",
    ],
    [$.range_pattern, $.is_expression],
    [$.dot_apply_expression, $.accessor, $.range_expression],
    [$.dot_dot_apply_expression, $.unary_expression],
    [$.array_access_expression, $.unary_expression],
    [$.unary_expression, $.range_expression],
    [$.unary_expression, $.as_expression],
    [$.or_pattern, $.as_pattern],
    [$.lexmatch_or_pattern, $.lexmatch_as_pattern],
  ],

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
  ],

  rules: {
    structure: ($) => list($._semicolon, $._structure_item),

    _structure_item: ($) =>
      choice(
        $.using_declaration,
        $.type_definition,
        $.error_type_definition,
        $.struct_definition,
        $.tuple_struct_definition,
        $.enum_definition,
        $.value_definition,
        $.const_definition,
        $.function_definition,
        $.test_definition,
        $.trait_definition,
        $.impl_definition,
        $.type_alias_definition,
        $.trait_alias_definition,
        $.function_alias_definition
      ),

    visibility: ($) => choice("priv", seq("pub", optional($.pub_attribute))),

    pub_attribute: (_) => seq("(", choice("readonly", "all", "open"), ")"),

    derive_item: ($) => seq($.type_name, optional($.arguments)),

    derive_directive: ($) => seq("derive", "(", list(",", $.derive_item), ")"),

    type_definition: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        optional("extern"),
        "type",
        $.identifier,
        optional($.type_parameters),
        optional(seq("=", $._type)),
        optional($.derive_directive)
      ),

    error_type_definition: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        optional("extern"),
        choice(seq("type", "!"), "suberror"),
        $.identifier,
        optional(
          choice($._type, seq("{", list($._semicolon, $.enum_constructor), "}"))
        ),
        optional($.derive_directive)
      ),

    type_alias_target: ($) =>
      choice($.identifier, seq($.identifier, "as", $.identifier)),

    type_alias_targets: ($) =>
      choice(
        seq($._type, "as", $.identifier, optional($.type_parameters)),
        seq($._type, "=", $._type),
        seq($.package_identifier, $.dot_identifier),
        seq($.dot_identifier),
        seq($.package_identifier, ".(", list(",", $.type_alias_target), ")")
      ),

    type_alias_definition: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        "typealias",
        $.type_alias_targets
      ),

    struct_definition: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        "struct",
        $.identifier,
        optional($.type_parameters),
        "{",
        list($._semicolon, $.struct_field_declaration),
        "}",
        optional($.derive_directive)
      ),

    tuple_struct_definition: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        "struct",
        $.identifier,
        optional($.type_parameters),
        "(",
        list(",", $._type),
        ")",
        optional($.derive_directive)
      ),

    struct_field_declaration: ($) =>
      seq(
        optional($.visibility),
        optional($.mutability),
        $._lowercase_identifier,
        ":",
        $._type
      ),

    enum_definition: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        "enum",
        $.identifier,
        optional($.type_parameters),
        "{",
        list($._semicolon, $.enum_constructor),
        "}",
        optional($.derive_directive)
      ),

    enum_constructor_payload: ($) =>
      choice(
        seq("(", list1(",", $.constructor_parameter), ")"),
        seq("=", $.integer_literal)
      ),

    enum_constructor: ($) =>
      seq($._uppercase_identifier, optional($.enum_constructor_payload)),

    constructor_parameter: ($) =>
      choice(
        seq(optional("mut"), $._type),
        seq(optional("mut"), $.label, ":", $._type)
      ),

    value_definition: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        "let",
        $._lowercase_identifier,
        optional($.type_annotation),
        "=",
        $._expression
      ),

    const_definition: ($) =>
      seq(
        optional($.attributes),
        optional($.pub),
        "const",
        $._uppercase_identifier,
        optional($.type_annotation),
        "=",
        $._expression
      ),

    external_linkage: ($) => seq("extern", $.string_literal),

    external_source: ($) =>
      choice(
        $.string_literal,
        seq($.string_literal, $.string_literal),
        $.multiline_string_literal
      ),

    function_definition: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        optional($.external_linkage),
        optional("async"),
        "fn",
        optional($.type_parameters),
        $.function_identifier,
        optional("!"),
        optional($.parameters),
        optional(choice(seq("->", $.return_type), $.error_annotation)),
        choice($.block_expression, seq("=", $.external_source))
      ),

    test_definition: ($) =>
      seq(
        optional($.attributes),
        optional("async"),
        "test",
        optional($.string_literal),
        optional($.parameters),
        $.block_expression
      ),

    trait_definition: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        "trait",
        $.identifier,
        optional($.super_trait_declaration),
        "{",
        list($._semicolon, $.trait_method_declaration),
        "}"
      ),

    super_trait_declaration: ($) =>
      seq(":", plusList($.qualified_type_identifier)),

    trait_method_parameter: ($) => choice($._type, $.parameter),

    trait_method_declaration: ($) =>
      seq(
        optional($.attributes),
        optional("async"),
        $.function_identifier,
        optional("!"),
        optional($.type_parameters),
        "(",
        list(",", $.trait_method_parameter),
        ")",
        optional(seq("->", $.return_type)),
        optional($.trait_method_default_annotation)
      ),

    trait_method_default_annotation: (_) => seq("=", "_"),

    trait_alias_target: ($) =>
      choice($.identifier, seq($.identifier, "as", $.identifier)),

    trait_alias_targets: ($) =>
      choice(
        seq($._type, "as", $.identifier, optional($.type_parameters)),
        seq($._type, "=", $._type),
        seq($.package_identifier, $.dot_identifier),
        seq($.dot_identifier),
        seq($.package_identifier, ".(", list(",", $.trait_alias_target), ")")
      ),

    trait_alias_definition: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        "traitalias",
        $.trait_alias_targets
      ),

    function_alias_target: ($) =>
      choice(
        $._lowercase_identifier,
        seq($._lowercase_identifier, "as", $._lowercase_identifier)
      ),

    function_alias_targets: ($) =>
      choice(
        seq($._lowercase_identifier, "=", $.qualified_identifier),
        $.function_alias_target,
        seq($.package_identifier, $.dot_lowercase_identifier),
        seq(
          $.package_identifier,
          $.dot_lowercase_identifier,
          "as",
          $._lowercase_identifier
        ),
        seq($.type_name, "::", $._lowercase_identifier),
        seq(
          $.type_name,
          "::",
          $._lowercase_identifier,
          "as",
          $._lowercase_identifier
        ),
        seq("(", list1(",", $.function_alias_target), ")"),
        seq(
          $.package_identifier,
          ".(",
          list(",", $.function_alias_target),
          ")"
        ),
        seq($.type_name, "::", "(", list(",", $.function_alias_target), ")")
      ),

    function_alias_definition: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        "fnalias",
        $.function_alias_targets
      ),

    using_target: ($) =>
      choice(
        seq("type", $._type, optional(seq("as", $.identifier))),
        seq("trait", $.qualified_type_identifier, optional(seq("as", $.identifier))),
        $._lowercase_identifier
      ),

    using_targets: ($) =>
      choice(
        seq($.package_identifier, "{", list(",", $.using_target), "}"),
        seq($.type_name, "::", "{", list(",", $.using_target), "}")
      ),

    using_declaration: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        "using",
        $.using_targets
      ),

    impl_definition: ($) =>
      seq(
        optional($.attributes),
        optional($.visibility),
        "impl",
        optional($.type_parameters),
        $.type_name,
        optional(seq("for", $._type)),
        "with",
        $.function_identifier,
        optional("!"),
        $.parameters,
        optional(seq("->", $.return_type)),
        choice($.block_expression, seq("=", $.external_source))
      ),

    _complex_expression: ($) =>
      choice(
        $.if_expression,
        $.while_expression,
        $.loop_expression,
        $.match_expression,
        $.lexmatch_expression,
        $.for_expression,
        $.for_in_expression,
        $.try_catch_expression,
        $.try_expression,
        $.arrow_function_expression
      ),

    _arrow_function_body: ($) =>
      choice(
        $._expression,
        $.raise_expression,
        $.assign_expression,
        $.unfinished
      ),

    arrow_function_expression: ($) =>
      choice(
        seq($.parameters, "=>", $._arrow_function_body),
        seq($._lowercase_identifier, "=>", $._arrow_function_body),
        seq("_", "=>", $._arrow_function_body)
      ),

    _expression: ($) => choice($._complex_expression, $._simple_expression),

    _simple_expression: ($) =>
      choice(
        $.atomic_expression,
        $.qualified_identifier,
        $.unary_expression,
        $.struct_expression,
        alias($.nonempty_block_expression, $.block_expression),
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
        $.parenthesized_expression,
        $.constraint_expression,
        $.array_expression,
        $.map_expression,
        $.as_expression,
        $.is_expression,
        $.range_expression,
        $.binary_expression,
        $.lexmatch_test_expression,
        "_"
      ),

    atomic_expression: ($) => choice($.string_interpolation, $.literal),

    string_interpolation: ($) =>
      seq(
        '"',
        repeat($.string_fragment),
        $.interpolator,
        repeat(choice($.string_fragment, $.interpolator)),
        '"'
      ),

    interpolator: ($) => seq("\\{", $._expression, "}"),

    literal: ($) =>
      choice(
        $.boolean_literal,
        $.double_literal,
        $.float_literal,
        $.integer_literal,
        $.byte_literal,
        $.char_literal,
        $.string_literal,
        $.bytes_literal,
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

    // integerPart = /[0-9][_0-9]*/,
    // decimalPart = /[_0-9]+/,
    // exponentPart = /[eE][0-9][_0-9]*/,
    // float_literal: _ => /[0-9][_0-9]*\.[_0-9]*([eE][0-9][_0-9]*)?/,

    float_literal: ($) => seq($._double_literal, token.immediate("F")),

    double_literal: ($) => $._double_literal,

    byte_literal: ($) =>
      seq("b'", choice($.escape_sequence, token.immediate(/[^']/)), "'"),

    char_literal: ($) =>
      seq("'", choice($.escape_sequence, token.immediate(/[^']/)), "'"),

    string_literal: ($) => choice(seq('"', repeat($.string_fragment), '"')),

    bytes_literal: ($) => seq('b"', repeat($.string_fragment), '"'),

    string_fragment: ($) =>
      choice($.unescaped_string_fragment, $.escape_sequence),

    unescaped_string_fragment: (_) =>
      choice(
        token.immediate(prec(1, /\\[^ntbrf'"\\{]/)),
        token.immediate(prec(1, /[^"\\]+/))
      ),

    escape_sequence: (_) =>
      choice(
        // \n, \t, \b, \r, \f, \", \\
        token.immediate(/\\[ntbrf'"\\]/),
        // octal
        token.immediate(/\\o[0-7]{1,3}/),
        // hex
        token.immediate(/\\x[0-9a-fA-F]{1,2}/),
        token.immediate(/\\x\{[0-9a-fA-F]+\}/),
        // unicode
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

    multiline_interpolation_fragment: ($) =>
      seq("$|", repeat($.multiline_interpolation_content)),

    multiline_string_literal: ($) =>
      prec.left(
        repeat1(
          choice(
            $.multiline_string_fragment,
            $.multiline_interpolation_fragment
          )
        )
      ),

    unary_expression: ($) =>
      seq(choice("-", "+", "!", "not"), $._simple_expression),

    binary_expression: ($) => {
      /**
       * @type {[string, RuleOrLiteral][]}
       */
      const table = [
        ["multiplicative", choice(...multiplicative_operators)],
        ["additive", choice(...additive_operators)],
        ["shift", choice(...shift_operators)],
        ["comparative", choice(...comparative_operators)],
        ["bitwise_and", "&"],
        ["bitwise_xor", "^"],
        ["bitwise_or", "|"],
        ["and", "&&"],
        ["or", "||"],
        ["pipe", "|>"],
      ];

      return choice(
        ...table.map(([precedence, operator]) =>
          prec.left(
            precedence,
            seq($._simple_expression, operator, $._simple_expression)
          )
        )
      );
    },

    struct_expression: ($) =>
      choice(
        seq(
          "{",
          choice(
            seq(
              $.labeled_expression_pun,
              ",",
              list(",", $.struct_field_expression)
            ),
            seq($.labeled_expression, optional(",")),
            seq(
              $.labeled_expression,
              ",",
              list1(",", $.struct_field_expression)
            )
          ),
          "}"
        ),
        seq($.type_name, "::", "{", list(",", $.struct_field_expression), "}"),
        seq(optional(seq($.type_name, "::")), "{", "..", $._expression, "}"),
        seq(
          optional(seq($.type_name, "::")),
          "{",
          "..",
          $._expression,
          ",",
          list(",", $.struct_field_expression),
          "}"
        )
      ),

    struct_field_expression: ($) =>
      choice($.labeled_expression, $.labeled_expression_pun),

    labeled_expression: ($) => seq($._lowercase_identifier, ":", $._expression),

    labeled_expression_pun: ($) => $._lowercase_identifier,

    block_expression: ($) =>
      seq("{", list($._semicolon, $._statement_expression), "}"),

    nonempty_block_expression: ($) =>
      seq("{", list1($._semicolon, $._statement_expression), "}"),

    anonymous_lambda_expression: ($) =>
      seq(
        optional("async"),
        "fn",
        optional("!"),
        $.parameters,
        optional(seq("->", $.return_type)),
        $.block_expression
      ),

    anonymous_matrix_lambda_expression: ($) =>
      seq(
        optional("async"),
        "fn",
        optional("!"),
        "{",
        list($._semicolon, $.matrix_case_clause),
        "}"
      ),

    pattern_guard: ($) => seq("if", $._expression),

    matrix_case_clause: ($) =>
      seq(
        list1(",", $._pattern),
        optional($.pattern_guard),
        "=>",
        $._statement_expression
      ),

    constructor_expression: ($) =>
      choice(
        $._uppercase_identifier,
        seq($.package_identifier, $.dot_uppercase_identifier),
        seq($.type_name, "::", $._uppercase_identifier)
      ),

    labelled_argument: ($) => seq($._lowercase_identifier, "=", $._expression),

    forwarded_labelled_argument: ($) => $.label,

    optional_argument: ($) => seq($.optional_label, "=", $._expression),

    forwarded_optional_argument: ($) => seq($.optional_label),

    argument: ($) =>
      choice(
        $._expression,
        $.labelled_argument,
        $.forwarded_labelled_argument,
        $.optional_argument,
        $.forwarded_optional_argument
      ),

    apply_operator: ($) => choice("!", "!!", "?"),

    arguments: ($) => seq("(", list(",", $.argument), ")"),

    apply_expression: ($) =>
      prec.right(
        seq($._simple_expression, optional($.apply_operator), $.arguments)
      ),

    array_access_expression: ($) =>
      seq(
        $._simple_expression,
        "[",
        choice(
          $._expression,
          seq(optional($._expression), ":", optional($._expression))
        ),
        "]"
      ),

    dot_apply_expression: ($) =>
      seq(
        $._simple_expression,
        $.dot_identifier,
        "(",
        list(",", $.argument),
        ")"
      ),

    dot_dot_apply_expression: ($) =>
      seq(
        $._simple_expression,
        $.dot_dot_identifier,
        "(",
        list(",", $.argument),
        ")"
      ),

    access_expression: ($) => seq($._simple_expression, $.accessor),

    accessor: ($) => choice($.dot_identifier, seq(".", /[0-9]+/)),

    method_expression: ($) => seq($.type_name, "::", $._lowercase_identifier),

    unit_expression: (_) => seq("(", ")"),

    tuple_expression: ($) =>
      choice(
        seq(
          "(",
          $._expression,
          repeat1(seq(",", $._expression)),
          optional(","),
          ")"
        ),
        seq("(", $._expression, ",", ")")
      ),

    parenthesized_expression: ($) => seq("(", $._expression, ")"),

    constraint_expression: ($) => seq("(", $._expression, ":", $._type, ")"),

    array_expression: ($) =>
      seq("[", list(",", seq(optional(".."), $._expression)), "]"),

    map_expression: ($) => seq("{", list(",", $.map_element_expression), "}"),

    map_element_key: ($) =>
      choice(
        $.literal,
        seq("-", choice($.integer_literal, $.double_literal, $.float_literal))
      ),

    map_element_expression: ($) => seq($.map_element_key, ":", $._expression),

    as_expression: ($) => seq($._simple_expression, "as", $.type_name),

    is_expression: ($) =>
      seq(
        $._simple_expression,
        "is",
        choice($.range_pattern, $._simple_pattern)
      ),

    match_expression: ($) =>
      seq(
        "match",
        $._simple_expression,
        "{",
        list($._semicolon, $.case_clause),
        "}"
      ),

    lexmatch_expression: ($) =>
      seq(
        "lexmatch",
        $._simple_expression,
        optional(seq("using", "longest")),
        "{",
        list($._semicolon, $.lexmatch_case_clause),
        "}"
      ),

    lexmatch_test_expression: ($) =>
      prec.right(
        -1,
        seq($._simple_expression, "lexmatch?", $.lexmatch_pattern)
      ),

    case_clause: ($) =>
      seq($._pattern, optional($.pattern_guard), "=>", $._statement_expression),

    lexmatch_case_clause: ($) =>
      seq(
        $.lexmatch_pattern,
        optional($.pattern_guard),
        "=>",
        $._statement_expression
      ),

    break_expression: ($) =>
      seq("break", optional($.label), strictList(",", $._expression)),

    continue_expression: ($) =>
      seq("continue", optional($.label), strictList(",", $._expression)),

    try_catch_expression: ($) =>
      seq(
        optional("try"),
        $._simple_expression,
        $.try_catch_clause,
        optional($.try_else_clause)
      ),

    try_expression: ($) => seq("try", choice("!", "?"), $._simple_expression),

    try_catch_clause: ($) =>
      seq(
        seq("catch", optional("!")),
        "{",
        list($._semicolon, $.case_clause),
        "}",
        optional($.noraise_clause)
      ),

    noraise_clause: ($) =>
      seq("noraise", "{", list($._semicolon, $.case_clause), "}"),

    try_else_clause: ($) =>
      seq("else", "{", list($._semicolon, $.case_clause), "}"),

    if_expression: ($) =>
      seq(
        "if",
        $._simple_expression,
        $.block_expression,
        optional($.else_clause)
      ),

    else_clause: ($) =>
      seq("else", choice($.block_expression, $.if_expression)),

    _statement_expression: ($) =>
      choice(
        $.struct_definition,
        $.enum_definition,
        $.type_definition,
        $.let_expression,
        $.letrec_expression,
        $.and_expression,
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
        $.defer_expression,
        $._expression,
        $.unfinished
      ),

    defer_expression: ($) => seq("defer", $._expression),

    unfinished: (_) => "...",

    let_expression: ($) =>
      seq("let", $._pattern, optional($.type_annotation), "=", $._expression),

    letrec_expression: ($) =>
      seq(
        "letrec",
        $._pattern,
        optional($.type_annotation),
        "=",
        $._expression
      ),

    and_expression: ($) =>
      seq("and", $._pattern, optional($.type_annotation), "=", $._expression),

    let_mut_expression: ($) =>
      seq(
        "let",
        "mut",
        $._lowercase_identifier,
        optional($.type_annotation),
        "=",
        $._expression
      ),

    guard_expression: ($) =>
      seq("guard", $._simple_expression, optional($.guard_else_expression)),

    guard_else_expression: ($) => seq("else", $.block_expression),

    guard_let_expression: ($) =>
      seq(
        "guard",
        "let",
        $._pattern,
        "=",
        $._simple_expression,
        optional($.guard_let_else_expression)
      ),

    guard_let_else_expression: ($) =>
      seq("else", "{", list($._semicolon, $.case_clause), "}"),

    assign_operator: ($) => choice("=", "+=", "-=", "*=", "/=", "%="),

    assign_expression: ($) =>
      seq($.left_value, $.assign_operator, $._expression),

    left_value: ($) =>
      choice(
        $.qualified_identifier,
        $.access_expression,
        $.array_access_expression
      ),

    named_lambda_expression: ($) =>
      seq(
        optional("async"),
        "fn",
        $._lowercase_identifier,
        optional("!"),
        $.parameters,
        optional(choice(seq("->", $.return_type), $.error_annotation)),
        $.block_expression
      ),

    named_matrix_expression: ($) =>
      seq(
        optional("async"),
        "fn",
        $._lowercase_identifier,
        optional("!"),
        "{",
        list($._semicolon, $.matrix_case_clause),
        "}"
      ),

    loop_label: ($) => seq($.label, ":"),

    while_expression: ($) =>
      seq(
        optional($.loop_label),
        "while",
        $._simple_expression,
        $.block_expression,
        optional($.else_clause)
      ),

    loop_expression: ($) =>
      seq(
        optional($.loop_label),
        "loop",
        strictList1(",", $._expression),
        "{",
        list($._semicolon, $.matrix_case_clause),
        "}"
      ),

    for_binder: ($) => seq($._lowercase_identifier, "=", $._expression),

    for_expression: ($) =>
      choice(
        seq(
          optional($.loop_label),
          "for",
          strictList(",", $.for_binder),
          $._semicolon,
          optional($._expression),
          $._semicolon,
          strictList(",", $.for_binder),
          $.block_expression,
          optional($.else_clause)
        ),
        seq(
          optional($.loop_label),
          "for",
          strictList(",", $.for_binder),
          $.block_expression,
          optional($.else_clause)
        )
      ),

    for_in_expression: ($) =>
      seq(
        optional($.loop_label),
        "for",
        strictList(",", $._lowercase_identifier),
        "in",
        $._expression,
        $.block_expression,
        optional($.else_clause)
      ),

    range_expression: ($) =>
      prec.left(
        seq(
          $._simple_expression,
          choice("..<", "..=", "..<=", "..>", "..>="),
          $._simple_expression
        )
      ),

    return_expression: ($) => seq("return", optional($._expression)),

    raise_expression: ($) => seq("raise", $._expression),

    // Patterns

    _pattern: ($) =>
      choice($._simple_pattern, $.range_pattern, $.as_pattern, $.or_pattern),

    as_pattern: ($) => seq($._pattern, "as", $._lowercase_identifier),

    or_pattern: ($) => prec.right(seq($._pattern, "|", $._pattern)),

    _simple_pattern: ($) =>
      choice(
        "..",
        $.parenthesized_pattern,
        $.atomic_pattern,
        $._lowercase_identifier,
        $.constructor_pattern,
        $.tuple_pattern,
        $.constraint_pattern,
        $.array_pattern,
        $.struct_pattern,
        $.map_pattern,
        $.empty_struct_or_map_pattern,
        $.any_pattern
      ),

    parenthesized_pattern: ($) => seq("(", $._pattern, ")"),

    atomic_pattern: ($) =>
      choice(
        $.literal,
        seq("-", $.integer_literal),
        seq("-", $.double_literal),
        seq("-", $.float_literal)
      ),

    any_pattern: (_) => "_",

    constructor_pattern_argument: ($) =>
      choice(
        seq($._lowercase_identifier, "=", $._pattern),
        $.label,
        $._pattern
      ),

    constructor_pattern: ($) =>
      prec.right(
        seq(
          $.constructor_expression,
          optional(seq("(", list(",", $.constructor_pattern_argument), ")"))
        )
      ),

    tuple_pattern: ($) =>
      seq("(", $._pattern, ",", list1(",", $._pattern), ")"),

    constraint_pattern: ($) => seq("(", $._pattern, ":", $._type, ")"),

    array_pattern: ($) => seq("[", list(",", $.array_sub_pattern), "]"),

    bitstring_pattern: ($) => seq(/[ui]\d+(le|be)?/, "(", $._pattern, ")"),

    lexmatch_pattern: ($) =>
      choice(
        $.lexmatch_or_pattern,
        $.lexmatch_as_pattern,
        $.lexmatch_range_pattern,
        $.lexmatch_sequence_pattern,
        $.lexmatch_simple_pattern
      ),

    lexmatch_sequence_pattern: ($) =>
      prec.right(
        1,
        seq($.lexmatch_simple_pattern, repeat1($.lexmatch_simple_pattern))
      ),

    lexmatch_or_pattern: ($) =>
      prec.right(0, seq($.lexmatch_pattern, "|", $.lexmatch_pattern)),

    lexmatch_as_pattern: ($) =>
      prec.right(0, seq($.lexmatch_pattern, "as", $._lowercase_identifier)),

    lexmatch_range_pattern: ($) =>
      prec.left(
        2,
        seq(
          $.lexmatch_simple_pattern,
          choice("..<", "..="),
          $.lexmatch_simple_pattern
        )
      ),

    lexmatch_simple_pattern: ($) =>
      choice(
        $.lexmatch_parenthesized_pattern,
        $.atomic_pattern,
        $._lowercase_identifier,
        $.constructor_pattern,
        $.lexmatch_tuple_pattern,
        $.constraint_pattern,
        $.array_pattern,
        $.any_pattern
      ),

    lexmatch_tuple_pattern: ($) =>
      seq("(", $.lexmatch_pattern, ",", list1(",", $.lexmatch_pattern), ")"),

    lexmatch_parenthesized_pattern: ($) =>
      seq("(", $.lexmatch_pattern, ")"),

    array_sub_pattern: ($) =>
      choice(
        seq("..", $.qualified_identifier),
        seq("..", $.constructor_expression),
        seq("..", $.string_literal),
        seq("..", $.bytes_literal),
        $.bitstring_pattern,
        $._pattern
      ),

    struct_pattern: ($) =>
      seq("{", list1(",", $.struct_field_pattern), optional(".."), "}"),

    struct_field_pattern: ($) =>
      choice($.labeled_pattern, $.labeled_pattern_pun),

    labeled_pattern: ($) => seq($._lowercase_identifier, ":", $._pattern),

    labeled_pattern_pun: ($) => $._lowercase_identifier,

    map_pattern: ($) =>
      seq("{", list1(",", $.map_element_pattern), optional(".."), "}"),

    map_element_pattern: ($) =>
      seq($.map_element_key, optional("?"), ":", $._pattern),

    empty_struct_or_map_pattern: (_) => seq("{", "}"),

    range_pattern: ($) =>
      seq($._simple_pattern, choice("..<", "..="), $._simple_pattern),

    _type: ($) => choice($._simple_type, $.function_type),

    tuple_type: ($) =>
      seq("(", $._type, repeat1(seq(",", $._type)), optional(","), ")"),

    function_type: ($) =>
      seq(
        optional("async"),
        "(",
        list(",", $._type),
        ")",
        seq("->", $.return_type)
      ),

    _simple_type: ($) =>
      choice(
        $.qualified_type_identifier,
        $.option_type,
        $.apply_type,
        $.tuple_type,
        $.trait_object_type,
        $.parenthesized_type,
        "_"
      ),

    parenthesized_type: ($) => seq("(", $._type, ")"),

    apply_type: ($) => seq($.qualified_type_identifier, $.type_arguments),

    option_type: ($) => seq($._simple_type, "?"),

    trait_object_type: ($) => seq("&", $.qualified_type_identifier),

    type_arguments: ($) => seq("[", list1(",", $._type), "]"),

    type_parameters: ($) => seq("[", list1(",", $.type_identifier), "]"),

    type_annotation: ($) => seq(":", $._type),

    error_annotation: ($) =>
      choice("raise", "noraise", seq("raise", $._type), seq("raise", "?")),

    return_type: ($) =>
      choice(
        $._type,
        seq($._simple_type, "!"),
        seq($._simple_type, "!", $._type),
        seq($._simple_type, "?", $._type),
        seq($._simple_type, $.error_annotation)
      ),

    label: ($) => seq($._lowercase_identifier, "~"),

    optional_label: ($) => seq($._lowercase_identifier, "?"),

    positional_parameter: ($) =>
      seq(choice($._lowercase_identifier, "_"), optional($.type_annotation)),

    labelled_parameter: ($) => seq($.label, optional($.type_annotation)),

    optional_parameter: ($) =>
      seq($.optional_label, optional($.type_annotation)),

    optional_parameter_with_default: ($) =>
      seq(
        choice($.label, $.optional_label),
        optional($.type_annotation),
        "=",
        $._expression
      ),

    parameter: ($) =>
      choice(
        $.positional_parameter,
        $.labelled_parameter,
        $.optional_parameter,
        $.optional_parameter_with_default
      ),

    parameters: ($) => seq("(", list(",", $.parameter), ")"),

    any: (_) => "_",
    mutability: (_) => "mut",
    pub: (_) => "pub",

    // Identifiers
    uppercase_identifier: (_) => /[\p{Uppercase_Letter}][_\p{XID_Continue}]*/v,

    _uppercase_identifier: ($) => $.uppercase_identifier,

    lowercase_identifier: (_) =>
      /[_[\p{XID_Start}--\p{Uppercase_Letter}]][_\p{XID_Continue}]*/v,

    _lowercase_identifier: ($) => $.lowercase_identifier,

    identifier: ($) => choice($._uppercase_identifier, $._lowercase_identifier),

    _semicolon: ($) => choice($._automatic_semicolon, ";"),

    dot_identifier: ($) =>
      choice($.dot_lowercase_identifier, $.dot_uppercase_identifier),

    dot_lowercase_identifier: (_) =>
      /\.[_[\p{XID_Start}--\p{Uppercase_Letter}]][_\p{XID_Continue}]*/v,

    dot_uppercase_identifier: (_) =>
      /\.[\p{Uppercase_Letter}][_\p{XID_Continue}]*/v,

    dot_dot_identifier: ($) =>
      seq("..", /[_\p{XID_Start}][_\p{XID_Continue}]*/v),

    package_identifier: (_) => /@[_\p{XID_Start}\/][_\p{XID_Continue}\/]*/v,

    qualified_identifier: ($) =>
      choice(
        $._lowercase_identifier,
        seq($.package_identifier, $.dot_lowercase_identifier)
      ),

    qualified_type_identifier: ($) =>
      choice($.identifier, seq($.package_identifier, $.dot_identifier)),

    type_name: ($) =>
      choice(
        $.qualified_type_identifier,
        seq("&", $.qualified_type_identifier)
      ),

    function_identifier: ($) =>
      choice(
        $._lowercase_identifier,
        seq($.type_name, "::", $._lowercase_identifier)
      ),

    type_identifier: ($) =>
      choice($.identifier, seq($.identifier, ":", $.constraints)),

    constraints: ($) => list1("+", $.constraint),

    constraint: ($) => $.qualified_type_identifier,

    comment: (_) => /\/\/.*/,

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
        seq(
          $._lowercase_identifier,
          $.dot_lowercase_identifier,
          $.attribute_properties
        ),
        seq($._uppercase_identifier, $.attribute_properties),
        $.string_literal
      ),

    attribute: ($) => seq("#", $.attribute_expression),

    attributes: ($) => repeat1($.attribute),
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
  return seq(rule, repeat(seq(separator, rule)), optional(separator));
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
  return seq(rule, repeat(seq(separator, choice(rule, "$..."))));
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
    repeat(seq("+", rule))
    // no trailing separator
  );
}
