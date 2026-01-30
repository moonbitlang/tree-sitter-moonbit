/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "moonpkg",

  extras: ($) => [/\s/, $.line_comment, $.block_comment],

  rules: {
    source_file: ($) => repeat($._statement),

    _statement: ($) =>
      seq(
        choice($.import_statement, $.assign_statement, $.apply_statement),
        optional(";")
      ),

    // Import statement: import { "pkg1", "pkg2" as @alias } [for "test"|"wbtest"]
    import_statement: ($) =>
      choice($._import_modern, $._import_legacy),

    _import_modern: ($) =>
      seq(
        "import",
        $.import_list,
        optional($.import_for_clause)
      ),

    _import_legacy: ($) =>
      seq(
        "import",
        $.import_kind,
        $.import_list
      ),

    import_list: ($) =>
      seq(
        "{",
        optional(
          seq(
            $.import_item,
            repeat(seq(",", $.import_item)),
            optional(",")
          )
        ),
        "}"
      ),

    import_item: ($) =>
      seq(
        field("path", $.string),
        optional(seq("as", field("alias", $.package_name)))
      ),

    import_for_clause: ($) =>
      seq("for", field("kind", $.string)),

    import_kind: ($) =>
      field("kind", $.string),

    package_name: (_) =>
      token(seq("@", /[a-zA-Z_][a-zA-Z0-9_]*/)),

    // Assignment statement: name = expr
    assign_statement: ($) =>
      seq(
        field("name", $.identifier),
        "=",
        field("value", $._expression)
      ),

    // Apply statement: name(label: expr, ...)
    apply_statement: ($) =>
      seq(
        field("name", $.identifier),
        $.argument_list
      ),

    argument_list: ($) =>
      seq(
        "(",
        optional(
          seq(
            $.argument,
            repeat(seq(",", $.argument)),
            optional(",")
          )
        ),
        ")"
      ),

    argument: ($) =>
      seq(
        field("label", choice($.identifier, $.string)),
        ":",
        field("value", $._expression)
      ),

    // Expressions
    _expression: ($) =>
      choice(
        $.true,
        $.false,
        $.string,
        $.integer,
        $.array,
        $.object
      ),

    true: (_) => "true",
    false: (_) => "false",

    string: (_) =>
      token(
        seq(
          '"',
          repeat(
            choice(
              /[^"\\]+/,
              seq("\\", /./),
            )
          ),
          '"'
        )
      ),

    integer: (_) => token(/[0-9]+/),

    array: ($) =>
      seq(
        "[",
        optional(
          seq(
            $._expression,
            repeat(seq(",", $._expression)),
            optional(",")
          )
        ),
        "]"
      ),

    object: ($) =>
      seq(
        "{",
        optional(
          seq(
            $.object_entry,
            repeat(seq(",", $.object_entry)),
            optional(",")
          )
        ),
        "}"
      ),

    object_entry: ($) =>
      seq(
        field("key", choice($.string, $.identifier)),
        ":",
        field("value", $._expression)
      ),

    identifier: (_) => /[a-zA-Z_][a-zA-Z0-9_-]*/,

    // Comments
    line_comment: (_) =>
      token(seq("//", /[^\r\n]*/)),

    block_comment: (_) =>
      token(seq("/*", /[^*]*\*+([^/*][^*]*\*+)*/, "/")),
  },
});
