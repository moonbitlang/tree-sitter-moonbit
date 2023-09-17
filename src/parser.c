#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 661
#define LARGE_STATE_COUNT 11
#define SYMBOL_COUNT 183
#define ALIAS_COUNT 0
#define TOKEN_COUNT 76
#define EXTERNAL_TOKEN_COUNT 1
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 9
#define PRODUCTION_ID_COUNT 1

enum {
  sym_lowercase_identifier = 1,
  anon_sym_LF = 2,
  anon_sym_SEMI = 3,
  anon_sym_ = 4,
  anon_sym_priv = 5,
  anon_sym_pub = 6,
  anon_sym_LPAREN = 7,
  anon_sym_readonly = 8,
  anon_sym_RPAREN = 9,
  anon_sym_type = 10,
  anon_sym_struct = 11,
  anon_sym_LBRACE = 12,
  anon_sym_RBRACE = 13,
  anon_sym_COLON = 14,
  anon_sym_enum = 15,
  anon_sym_COMMA = 16,
  anon_sym_let = 17,
  anon_sym_EQ = 18,
  anon_sym_func = 19,
  anon_sym_interface = 20,
  anon_sym__ = 21,
  anon_sym_DQUOTE = 22,
  anon_sym_BSLASH_LPAREN = 23,
  anon_sym_true = 24,
  anon_sym_false = 25,
  sym_integer_literal = 26,
  anon_sym_SQUOTE = 27,
  aux_sym_char_literal_token1 = 28,
  sym_unescaped_string_fragment = 29,
  sym_escape_seqence = 30,
  anon_sym_DASH = 31,
  anon_sym_PLUS = 32,
  anon_sym_STAR_STAR = 33,
  anon_sym_STAR = 34,
  anon_sym_SLASH = 35,
  anon_sym_STAR_EQ = 36,
  anon_sym_SLASH_EQ = 37,
  anon_sym_PERCENT = 38,
  anon_sym_PLUS_EQ = 39,
  anon_sym_DASH_EQ = 40,
  anon_sym_GT = 41,
  anon_sym_GT_EQ = 42,
  anon_sym_LT_EQ = 43,
  anon_sym_LT = 44,
  anon_sym_EQ_EQ = 45,
  anon_sym_BANG_EQ = 46,
  anon_sym_AMP_AMP = 47,
  anon_sym_PIPE_PIPE = 48,
  anon_sym_DOT_DOT = 49,
  anon_sym_fn = 50,
  anon_sym_LBRACK = 51,
  anon_sym_RBRACK = 52,
  aux_sym_accessor_token1 = 53,
  anon_sym_match = 54,
  anon_sym_EQ_GT = 55,
  anon_sym_if = 56,
  anon_sym_else = 57,
  anon_sym_break = 58,
  anon_sym_continue = 59,
  anon_sym_COLON_EQ = 60,
  anon_sym_var = 61,
  anon_sym_while = 62,
  anon_sym_return = 63,
  anon_sym_as = 64,
  anon_sym_PIPE = 65,
  anon_sym_DASH_GT = 66,
  sym_mutability = 67,
  sym_uppercase_identifier = 68,
  sym_colon_colon_uppercase_identifier = 69,
  sym_colon_colon_lowercase_identifier = 70,
  sym_identifier = 71,
  sym_dot_identifier = 72,
  sym_package_identifier = 73,
  sym_comment = 74,
  sym_float_literal = 75,
  sym_structure = 76,
  sym_structure_item = 77,
  sym_visibility = 78,
  sym_pub_attribute = 79,
  sym_type_defintion = 80,
  sym_struct_definition = 81,
  sym_struct_filed_declaration = 82,
  sym_enum_definition = 83,
  sym_enum_constructor = 84,
  sym_value_definition = 85,
  sym_function_definition = 86,
  sym_interface_definition = 87,
  sym_interface_method_declaration = 88,
  sym_expression = 89,
  sym_simple_expression = 90,
  sym_atomic_expression = 91,
  sym_string_interpolation = 92,
  sym_interpolator = 93,
  sym_literal = 94,
  sym_boolean_literal = 95,
  sym_char_literal = 96,
  sym_string_literal = 97,
  sym_string_fragement = 98,
  sym_unary_expression = 99,
  sym_binary_expression = 100,
  sym_struct_expression = 101,
  sym_struct_field_expression = 102,
  sym_struct_filed_expression = 103,
  sym_labeled_expression = 104,
  sym_labeled_expression_pun = 105,
  sym_block_expression = 106,
  sym_nonempty_block_expression = 107,
  sym_anonymous_lambda_expression = 108,
  sym_constructor_expression = 109,
  sym_apply_expression = 110,
  sym_array_access_expression = 111,
  sym_dot_apply_expression = 112,
  sym_access_expression = 113,
  sym_accessor = 114,
  sym_method_expression = 115,
  sym_unit_expression = 116,
  sym_tuple_expression = 117,
  sym_constraint_expression = 118,
  sym_array_expression = 119,
  sym_match_expression = 120,
  sym_case_clause = 121,
  sym_if_expression = 122,
  sym_else_clause = 123,
  sym_statement_expression = 124,
  sym_let_expression = 125,
  sym_shorthand_let_expression = 126,
  sym_shorthand_let_pattern = 127,
  sym_var_expression = 128,
  sym_assign_expression = 129,
  sym_left_value = 130,
  sym_named_lambda_expression = 131,
  sym_while_expression = 132,
  sym_return_expression = 133,
  sym_pattern = 134,
  sym_as_pattern = 135,
  sym_or_pattern = 136,
  sym_simple_pattern = 137,
  sym_constructor_pattern = 138,
  sym_tuple_pattern = 139,
  sym_constraint_pattern = 140,
  sym_array_pattern = 141,
  sym_array_sub_pattern = 142,
  sym_dotdot_pattern = 143,
  sym_struct_pattern = 144,
  sym_struct_filed_pattern = 145,
  sym_filed_single_pattern = 146,
  sym_labeled_pattern = 147,
  sym_labeled_pattern_pun = 148,
  sym_type = 149,
  sym_tuple_type = 150,
  sym_function_type = 151,
  sym_apply_type = 152,
  sym_type_arguments = 153,
  sym_type_parameters = 154,
  sym_type_annotation = 155,
  sym_retuern_type = 156,
  sym_parameter = 157,
  sym_parameters = 158,
  sym_any = 159,
  sym_pub = 160,
  sym_qualified_identifier = 161,
  sym_qualified_type_identifier = 162,
  sym_function_identifier = 163,
  sym_type_identifier = 164,
  sym_constraints = 165,
  sym_constraint = 166,
  aux_sym_structure_repeat1 = 167,
  aux_sym_struct_definition_repeat1 = 168,
  aux_sym_enum_definition_repeat1 = 169,
  aux_sym_enum_constructor_repeat1 = 170,
  aux_sym_interface_definition_repeat1 = 171,
  aux_sym_string_interpolation_repeat1 = 172,
  aux_sym_string_interpolation_repeat2 = 173,
  aux_sym_struct_field_expression_repeat1 = 174,
  aux_sym_block_expression_repeat1 = 175,
  aux_sym_apply_expression_repeat1 = 176,
  aux_sym_match_expression_repeat1 = 177,
  aux_sym_constructor_pattern_repeat1 = 178,
  aux_sym_struct_filed_pattern_repeat1 = 179,
  aux_sym_type_parameters_repeat1 = 180,
  aux_sym_parameters_repeat1 = 181,
  aux_sym_constraints_repeat1 = 182,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_lowercase_identifier] = "lowercase_identifier",
  [anon_sym_LF] = "\n",
  [anon_sym_SEMI] = ";",
  [anon_sym_] = " ",
  [anon_sym_priv] = "priv",
  [anon_sym_pub] = "pub",
  [anon_sym_LPAREN] = "(",
  [anon_sym_readonly] = "readonly",
  [anon_sym_RPAREN] = ")",
  [anon_sym_type] = "type",
  [anon_sym_struct] = "struct",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_COLON] = ":",
  [anon_sym_enum] = "enum",
  [anon_sym_COMMA] = ",",
  [anon_sym_let] = "let",
  [anon_sym_EQ] = "=",
  [anon_sym_func] = "func",
  [anon_sym_interface] = "interface",
  [anon_sym__] = "_",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_BSLASH_LPAREN] = "\\(",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_integer_literal] = "integer_literal",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_char_literal_token1] = "char_literal_token1",
  [sym_unescaped_string_fragment] = "unescaped_string_fragment",
  [sym_escape_seqence] = "escape_seqence",
  [anon_sym_DASH] = "-",
  [anon_sym_PLUS] = "+",
  [anon_sym_STAR_STAR] = "**",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_STAR_EQ] = "*=",
  [anon_sym_SLASH_EQ] = "/=",
  [anon_sym_PERCENT] = "%",
  [anon_sym_PLUS_EQ] = "+=",
  [anon_sym_DASH_EQ] = "-=",
  [anon_sym_GT] = ">",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_LT] = "<",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_BANG_EQ] = "!=",
  [anon_sym_AMP_AMP] = "&&",
  [anon_sym_PIPE_PIPE] = "||",
  [anon_sym_DOT_DOT] = "..",
  [anon_sym_fn] = "fn",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [aux_sym_accessor_token1] = "accessor_token1",
  [anon_sym_match] = "match",
  [anon_sym_EQ_GT] = "=>",
  [anon_sym_if] = "if",
  [anon_sym_else] = "else",
  [anon_sym_break] = "break",
  [anon_sym_continue] = "continue",
  [anon_sym_COLON_EQ] = ":=",
  [anon_sym_var] = "var",
  [anon_sym_while] = "while",
  [anon_sym_return] = "return",
  [anon_sym_as] = "as",
  [anon_sym_PIPE] = "|",
  [anon_sym_DASH_GT] = "->",
  [sym_mutability] = "mutability",
  [sym_uppercase_identifier] = "uppercase_identifier",
  [sym_colon_colon_uppercase_identifier] = "colon_colon_uppercase_identifier",
  [sym_colon_colon_lowercase_identifier] = "colon_colon_lowercase_identifier",
  [sym_identifier] = "identifier",
  [sym_dot_identifier] = "dot_identifier",
  [sym_package_identifier] = "package_identifier",
  [sym_comment] = "comment",
  [sym_float_literal] = "float_literal",
  [sym_structure] = "structure",
  [sym_structure_item] = "structure_item",
  [sym_visibility] = "visibility",
  [sym_pub_attribute] = "pub_attribute",
  [sym_type_defintion] = "type_defintion",
  [sym_struct_definition] = "struct_definition",
  [sym_struct_filed_declaration] = "struct_filed_declaration",
  [sym_enum_definition] = "enum_definition",
  [sym_enum_constructor] = "enum_constructor",
  [sym_value_definition] = "value_definition",
  [sym_function_definition] = "function_definition",
  [sym_interface_definition] = "interface_definition",
  [sym_interface_method_declaration] = "interface_method_declaration",
  [sym_expression] = "expression",
  [sym_simple_expression] = "simple_expression",
  [sym_atomic_expression] = "atomic_expression",
  [sym_string_interpolation] = "string_interpolation",
  [sym_interpolator] = "interpolator",
  [sym_literal] = "literal",
  [sym_boolean_literal] = "boolean_literal",
  [sym_char_literal] = "char_literal",
  [sym_string_literal] = "string_literal",
  [sym_string_fragement] = "string_fragement",
  [sym_unary_expression] = "unary_expression",
  [sym_binary_expression] = "binary_expression",
  [sym_struct_expression] = "struct_expression",
  [sym_struct_field_expression] = "struct_field_expression",
  [sym_struct_filed_expression] = "struct_filed_expression",
  [sym_labeled_expression] = "labeled_expression",
  [sym_labeled_expression_pun] = "labeled_expression_pun",
  [sym_block_expression] = "block_expression",
  [sym_nonempty_block_expression] = "nonempty_block_expression",
  [sym_anonymous_lambda_expression] = "anonymous_lambda_expression",
  [sym_constructor_expression] = "constructor_expression",
  [sym_apply_expression] = "apply_expression",
  [sym_array_access_expression] = "array_access_expression",
  [sym_dot_apply_expression] = "dot_apply_expression",
  [sym_access_expression] = "access_expression",
  [sym_accessor] = "accessor",
  [sym_method_expression] = "method_expression",
  [sym_unit_expression] = "unit_expression",
  [sym_tuple_expression] = "tuple_expression",
  [sym_constraint_expression] = "constraint_expression",
  [sym_array_expression] = "array_expression",
  [sym_match_expression] = "match_expression",
  [sym_case_clause] = "case_clause",
  [sym_if_expression] = "if_expression",
  [sym_else_clause] = "else_clause",
  [sym_statement_expression] = "statement_expression",
  [sym_let_expression] = "let_expression",
  [sym_shorthand_let_expression] = "shorthand_let_expression",
  [sym_shorthand_let_pattern] = "shorthand_let_pattern",
  [sym_var_expression] = "var_expression",
  [sym_assign_expression] = "assign_expression",
  [sym_left_value] = "left_value",
  [sym_named_lambda_expression] = "named_lambda_expression",
  [sym_while_expression] = "while_expression",
  [sym_return_expression] = "return_expression",
  [sym_pattern] = "pattern",
  [sym_as_pattern] = "as_pattern",
  [sym_or_pattern] = "or_pattern",
  [sym_simple_pattern] = "simple_pattern",
  [sym_constructor_pattern] = "constructor_pattern",
  [sym_tuple_pattern] = "tuple_pattern",
  [sym_constraint_pattern] = "constraint_pattern",
  [sym_array_pattern] = "array_pattern",
  [sym_array_sub_pattern] = "array_sub_pattern",
  [sym_dotdot_pattern] = "dotdot_pattern",
  [sym_struct_pattern] = "struct_pattern",
  [sym_struct_filed_pattern] = "struct_filed_pattern",
  [sym_filed_single_pattern] = "filed_single_pattern",
  [sym_labeled_pattern] = "labeled_pattern",
  [sym_labeled_pattern_pun] = "labeled_pattern_pun",
  [sym_type] = "type",
  [sym_tuple_type] = "tuple_type",
  [sym_function_type] = "function_type",
  [sym_apply_type] = "apply_type",
  [sym_type_arguments] = "type_arguments",
  [sym_type_parameters] = "type_parameters",
  [sym_type_annotation] = "type_annotation",
  [sym_retuern_type] = "retuern_type",
  [sym_parameter] = "parameter",
  [sym_parameters] = "parameters",
  [sym_any] = "any",
  [sym_pub] = "pub",
  [sym_qualified_identifier] = "qualified_identifier",
  [sym_qualified_type_identifier] = "qualified_type_identifier",
  [sym_function_identifier] = "function_identifier",
  [sym_type_identifier] = "type_identifier",
  [sym_constraints] = "constraints",
  [sym_constraint] = "constraint",
  [aux_sym_structure_repeat1] = "structure_repeat1",
  [aux_sym_struct_definition_repeat1] = "struct_definition_repeat1",
  [aux_sym_enum_definition_repeat1] = "enum_definition_repeat1",
  [aux_sym_enum_constructor_repeat1] = "enum_constructor_repeat1",
  [aux_sym_interface_definition_repeat1] = "interface_definition_repeat1",
  [aux_sym_string_interpolation_repeat1] = "string_interpolation_repeat1",
  [aux_sym_string_interpolation_repeat2] = "string_interpolation_repeat2",
  [aux_sym_struct_field_expression_repeat1] = "struct_field_expression_repeat1",
  [aux_sym_block_expression_repeat1] = "block_expression_repeat1",
  [aux_sym_apply_expression_repeat1] = "apply_expression_repeat1",
  [aux_sym_match_expression_repeat1] = "match_expression_repeat1",
  [aux_sym_constructor_pattern_repeat1] = "constructor_pattern_repeat1",
  [aux_sym_struct_filed_pattern_repeat1] = "struct_filed_pattern_repeat1",
  [aux_sym_type_parameters_repeat1] = "type_parameters_repeat1",
  [aux_sym_parameters_repeat1] = "parameters_repeat1",
  [aux_sym_constraints_repeat1] = "constraints_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_lowercase_identifier] = sym_lowercase_identifier,
  [anon_sym_LF] = anon_sym_LF,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_] = anon_sym_,
  [anon_sym_priv] = anon_sym_priv,
  [anon_sym_pub] = anon_sym_pub,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_readonly] = anon_sym_readonly,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_type] = anon_sym_type,
  [anon_sym_struct] = anon_sym_struct,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_enum] = anon_sym_enum,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_func] = anon_sym_func,
  [anon_sym_interface] = anon_sym_interface,
  [anon_sym__] = anon_sym__,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_BSLASH_LPAREN] = anon_sym_BSLASH_LPAREN,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_integer_literal] = sym_integer_literal,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_char_literal_token1] = aux_sym_char_literal_token1,
  [sym_unescaped_string_fragment] = sym_unescaped_string_fragment,
  [sym_escape_seqence] = sym_escape_seqence,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_STAR_STAR] = anon_sym_STAR_STAR,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_STAR_EQ] = anon_sym_STAR_EQ,
  [anon_sym_SLASH_EQ] = anon_sym_SLASH_EQ,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_PLUS_EQ] = anon_sym_PLUS_EQ,
  [anon_sym_DASH_EQ] = anon_sym_DASH_EQ,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_BANG_EQ] = anon_sym_BANG_EQ,
  [anon_sym_AMP_AMP] = anon_sym_AMP_AMP,
  [anon_sym_PIPE_PIPE] = anon_sym_PIPE_PIPE,
  [anon_sym_DOT_DOT] = anon_sym_DOT_DOT,
  [anon_sym_fn] = anon_sym_fn,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [aux_sym_accessor_token1] = aux_sym_accessor_token1,
  [anon_sym_match] = anon_sym_match,
  [anon_sym_EQ_GT] = anon_sym_EQ_GT,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_break] = anon_sym_break,
  [anon_sym_continue] = anon_sym_continue,
  [anon_sym_COLON_EQ] = anon_sym_COLON_EQ,
  [anon_sym_var] = anon_sym_var,
  [anon_sym_while] = anon_sym_while,
  [anon_sym_return] = anon_sym_return,
  [anon_sym_as] = anon_sym_as,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [sym_mutability] = sym_mutability,
  [sym_uppercase_identifier] = sym_uppercase_identifier,
  [sym_colon_colon_uppercase_identifier] = sym_colon_colon_uppercase_identifier,
  [sym_colon_colon_lowercase_identifier] = sym_colon_colon_lowercase_identifier,
  [sym_identifier] = sym_identifier,
  [sym_dot_identifier] = sym_dot_identifier,
  [sym_package_identifier] = sym_package_identifier,
  [sym_comment] = sym_comment,
  [sym_float_literal] = sym_float_literal,
  [sym_structure] = sym_structure,
  [sym_structure_item] = sym_structure_item,
  [sym_visibility] = sym_visibility,
  [sym_pub_attribute] = sym_pub_attribute,
  [sym_type_defintion] = sym_type_defintion,
  [sym_struct_definition] = sym_struct_definition,
  [sym_struct_filed_declaration] = sym_struct_filed_declaration,
  [sym_enum_definition] = sym_enum_definition,
  [sym_enum_constructor] = sym_enum_constructor,
  [sym_value_definition] = sym_value_definition,
  [sym_function_definition] = sym_function_definition,
  [sym_interface_definition] = sym_interface_definition,
  [sym_interface_method_declaration] = sym_interface_method_declaration,
  [sym_expression] = sym_expression,
  [sym_simple_expression] = sym_simple_expression,
  [sym_atomic_expression] = sym_atomic_expression,
  [sym_string_interpolation] = sym_string_interpolation,
  [sym_interpolator] = sym_interpolator,
  [sym_literal] = sym_literal,
  [sym_boolean_literal] = sym_boolean_literal,
  [sym_char_literal] = sym_char_literal,
  [sym_string_literal] = sym_string_literal,
  [sym_string_fragement] = sym_string_fragement,
  [sym_unary_expression] = sym_unary_expression,
  [sym_binary_expression] = sym_binary_expression,
  [sym_struct_expression] = sym_struct_expression,
  [sym_struct_field_expression] = sym_struct_field_expression,
  [sym_struct_filed_expression] = sym_struct_filed_expression,
  [sym_labeled_expression] = sym_labeled_expression,
  [sym_labeled_expression_pun] = sym_labeled_expression_pun,
  [sym_block_expression] = sym_block_expression,
  [sym_nonempty_block_expression] = sym_nonempty_block_expression,
  [sym_anonymous_lambda_expression] = sym_anonymous_lambda_expression,
  [sym_constructor_expression] = sym_constructor_expression,
  [sym_apply_expression] = sym_apply_expression,
  [sym_array_access_expression] = sym_array_access_expression,
  [sym_dot_apply_expression] = sym_dot_apply_expression,
  [sym_access_expression] = sym_access_expression,
  [sym_accessor] = sym_accessor,
  [sym_method_expression] = sym_method_expression,
  [sym_unit_expression] = sym_unit_expression,
  [sym_tuple_expression] = sym_tuple_expression,
  [sym_constraint_expression] = sym_constraint_expression,
  [sym_array_expression] = sym_array_expression,
  [sym_match_expression] = sym_match_expression,
  [sym_case_clause] = sym_case_clause,
  [sym_if_expression] = sym_if_expression,
  [sym_else_clause] = sym_else_clause,
  [sym_statement_expression] = sym_statement_expression,
  [sym_let_expression] = sym_let_expression,
  [sym_shorthand_let_expression] = sym_shorthand_let_expression,
  [sym_shorthand_let_pattern] = sym_shorthand_let_pattern,
  [sym_var_expression] = sym_var_expression,
  [sym_assign_expression] = sym_assign_expression,
  [sym_left_value] = sym_left_value,
  [sym_named_lambda_expression] = sym_named_lambda_expression,
  [sym_while_expression] = sym_while_expression,
  [sym_return_expression] = sym_return_expression,
  [sym_pattern] = sym_pattern,
  [sym_as_pattern] = sym_as_pattern,
  [sym_or_pattern] = sym_or_pattern,
  [sym_simple_pattern] = sym_simple_pattern,
  [sym_constructor_pattern] = sym_constructor_pattern,
  [sym_tuple_pattern] = sym_tuple_pattern,
  [sym_constraint_pattern] = sym_constraint_pattern,
  [sym_array_pattern] = sym_array_pattern,
  [sym_array_sub_pattern] = sym_array_sub_pattern,
  [sym_dotdot_pattern] = sym_dotdot_pattern,
  [sym_struct_pattern] = sym_struct_pattern,
  [sym_struct_filed_pattern] = sym_struct_filed_pattern,
  [sym_filed_single_pattern] = sym_filed_single_pattern,
  [sym_labeled_pattern] = sym_labeled_pattern,
  [sym_labeled_pattern_pun] = sym_labeled_pattern_pun,
  [sym_type] = sym_type,
  [sym_tuple_type] = sym_tuple_type,
  [sym_function_type] = sym_function_type,
  [sym_apply_type] = sym_apply_type,
  [sym_type_arguments] = sym_type_arguments,
  [sym_type_parameters] = sym_type_parameters,
  [sym_type_annotation] = sym_type_annotation,
  [sym_retuern_type] = sym_retuern_type,
  [sym_parameter] = sym_parameter,
  [sym_parameters] = sym_parameters,
  [sym_any] = sym_any,
  [sym_pub] = sym_pub,
  [sym_qualified_identifier] = sym_qualified_identifier,
  [sym_qualified_type_identifier] = sym_qualified_type_identifier,
  [sym_function_identifier] = sym_function_identifier,
  [sym_type_identifier] = sym_type_identifier,
  [sym_constraints] = sym_constraints,
  [sym_constraint] = sym_constraint,
  [aux_sym_structure_repeat1] = aux_sym_structure_repeat1,
  [aux_sym_struct_definition_repeat1] = aux_sym_struct_definition_repeat1,
  [aux_sym_enum_definition_repeat1] = aux_sym_enum_definition_repeat1,
  [aux_sym_enum_constructor_repeat1] = aux_sym_enum_constructor_repeat1,
  [aux_sym_interface_definition_repeat1] = aux_sym_interface_definition_repeat1,
  [aux_sym_string_interpolation_repeat1] = aux_sym_string_interpolation_repeat1,
  [aux_sym_string_interpolation_repeat2] = aux_sym_string_interpolation_repeat2,
  [aux_sym_struct_field_expression_repeat1] = aux_sym_struct_field_expression_repeat1,
  [aux_sym_block_expression_repeat1] = aux_sym_block_expression_repeat1,
  [aux_sym_apply_expression_repeat1] = aux_sym_apply_expression_repeat1,
  [aux_sym_match_expression_repeat1] = aux_sym_match_expression_repeat1,
  [aux_sym_constructor_pattern_repeat1] = aux_sym_constructor_pattern_repeat1,
  [aux_sym_struct_filed_pattern_repeat1] = aux_sym_struct_filed_pattern_repeat1,
  [aux_sym_type_parameters_repeat1] = aux_sym_type_parameters_repeat1,
  [aux_sym_parameters_repeat1] = aux_sym_parameters_repeat1,
  [aux_sym_constraints_repeat1] = aux_sym_constraints_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_lowercase_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_priv] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pub] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_readonly] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_type] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_struct] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_enum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_let] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_func] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_interface] = {
    .visible = true,
    .named = false,
  },
  [anon_sym__] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASH_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [sym_integer_literal] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_char_literal_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_unescaped_string_fragment] = {
    .visible = true,
    .named = true,
  },
  [sym_escape_seqence] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fn] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_accessor_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_match] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_else] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_break] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_continue] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_var] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_while] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_return] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_as] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [sym_mutability] = {
    .visible = true,
    .named = true,
  },
  [sym_uppercase_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_colon_colon_uppercase_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_colon_colon_lowercase_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_dot_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_package_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_float_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_structure] = {
    .visible = true,
    .named = true,
  },
  [sym_structure_item] = {
    .visible = true,
    .named = true,
  },
  [sym_visibility] = {
    .visible = true,
    .named = true,
  },
  [sym_pub_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_type_defintion] = {
    .visible = true,
    .named = true,
  },
  [sym_struct_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_struct_filed_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_enum_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_enum_constructor] = {
    .visible = true,
    .named = true,
  },
  [sym_value_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_function_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_interface_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_interface_method_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_simple_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_atomic_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_string_interpolation] = {
    .visible = true,
    .named = true,
  },
  [sym_interpolator] = {
    .visible = true,
    .named = true,
  },
  [sym_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_char_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_string_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_string_fragement] = {
    .visible = true,
    .named = true,
  },
  [sym_unary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_struct_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_struct_field_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_struct_filed_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_labeled_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_labeled_expression_pun] = {
    .visible = true,
    .named = true,
  },
  [sym_block_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_nonempty_block_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_anonymous_lambda_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_constructor_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_apply_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_array_access_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_dot_apply_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_access_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_accessor] = {
    .visible = true,
    .named = true,
  },
  [sym_method_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_unit_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_tuple_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_constraint_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_array_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_match_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_case_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_if_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_else_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_statement_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_let_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_shorthand_let_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_shorthand_let_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_var_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_assign_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_left_value] = {
    .visible = true,
    .named = true,
  },
  [sym_named_lambda_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_while_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_return_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_as_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_or_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_simple_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_constructor_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_tuple_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_constraint_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_array_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_array_sub_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_dotdot_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_struct_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_struct_filed_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_filed_single_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_labeled_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_labeled_pattern_pun] = {
    .visible = true,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym_tuple_type] = {
    .visible = true,
    .named = true,
  },
  [sym_function_type] = {
    .visible = true,
    .named = true,
  },
  [sym_apply_type] = {
    .visible = true,
    .named = true,
  },
  [sym_type_arguments] = {
    .visible = true,
    .named = true,
  },
  [sym_type_parameters] = {
    .visible = true,
    .named = true,
  },
  [sym_type_annotation] = {
    .visible = true,
    .named = true,
  },
  [sym_retuern_type] = {
    .visible = true,
    .named = true,
  },
  [sym_parameter] = {
    .visible = true,
    .named = true,
  },
  [sym_parameters] = {
    .visible = true,
    .named = true,
  },
  [sym_any] = {
    .visible = true,
    .named = true,
  },
  [sym_pub] = {
    .visible = true,
    .named = true,
  },
  [sym_qualified_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_qualified_type_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_function_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_type_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_constraints] = {
    .visible = true,
    .named = true,
  },
  [sym_constraint] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_structure_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_struct_definition_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_enum_definition_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_enum_constructor_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_interface_definition_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_interpolation_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_interpolation_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_struct_field_expression_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_block_expression_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_apply_expression_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_match_expression_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_constructor_pattern_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_struct_filed_pattern_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_type_parameters_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_parameters_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_constraints_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 2,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 4,
  [9] = 7,
  [10] = 6,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 12,
  [18] = 16,
  [19] = 19,
  [20] = 13,
  [21] = 19,
  [22] = 22,
  [23] = 15,
  [24] = 24,
  [25] = 24,
  [26] = 14,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 27,
  [31] = 28,
  [32] = 32,
  [33] = 29,
  [34] = 22,
  [35] = 32,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 37,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 44,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 42,
  [55] = 55,
  [56] = 55,
  [57] = 57,
  [58] = 58,
  [59] = 52,
  [60] = 57,
  [61] = 47,
  [62] = 46,
  [63] = 63,
  [64] = 64,
  [65] = 49,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 36,
  [70] = 63,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 80,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 85,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 129,
  [130] = 130,
  [131] = 131,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 139,
  [140] = 140,
  [141] = 141,
  [142] = 142,
  [143] = 143,
  [144] = 144,
  [145] = 145,
  [146] = 146,
  [147] = 147,
  [148] = 148,
  [149] = 149,
  [150] = 150,
  [151] = 151,
  [152] = 152,
  [153] = 153,
  [154] = 154,
  [155] = 87,
  [156] = 156,
  [157] = 88,
  [158] = 158,
  [159] = 159,
  [160] = 89,
  [161] = 99,
  [162] = 120,
  [163] = 93,
  [164] = 115,
  [165] = 134,
  [166] = 153,
  [167] = 151,
  [168] = 101,
  [169] = 72,
  [170] = 142,
  [171] = 113,
  [172] = 135,
  [173] = 109,
  [174] = 107,
  [175] = 118,
  [176] = 136,
  [177] = 112,
  [178] = 137,
  [179] = 139,
  [180] = 140,
  [181] = 181,
  [182] = 141,
  [183] = 104,
  [184] = 131,
  [185] = 146,
  [186] = 143,
  [187] = 144,
  [188] = 77,
  [189] = 123,
  [190] = 106,
  [191] = 130,
  [192] = 129,
  [193] = 116,
  [194] = 117,
  [195] = 78,
  [196] = 73,
  [197] = 147,
  [198] = 148,
  [199] = 125,
  [200] = 149,
  [201] = 181,
  [202] = 128,
  [203] = 127,
  [204] = 114,
  [205] = 152,
  [206] = 105,
  [207] = 126,
  [208] = 100,
  [209] = 111,
  [210] = 210,
  [211] = 145,
  [212] = 212,
  [213] = 122,
  [214] = 74,
  [215] = 75,
  [216] = 124,
  [217] = 121,
  [218] = 132,
  [219] = 76,
  [220] = 119,
  [221] = 103,
  [222] = 222,
  [223] = 222,
  [224] = 224,
  [225] = 224,
  [226] = 226,
  [227] = 227,
  [228] = 228,
  [229] = 229,
  [230] = 230,
  [231] = 231,
  [232] = 232,
  [233] = 233,
  [234] = 234,
  [235] = 235,
  [236] = 235,
  [237] = 237,
  [238] = 238,
  [239] = 230,
  [240] = 240,
  [241] = 231,
  [242] = 242,
  [243] = 243,
  [244] = 244,
  [245] = 245,
  [246] = 245,
  [247] = 247,
  [248] = 248,
  [249] = 248,
  [250] = 250,
  [251] = 251,
  [252] = 252,
  [253] = 253,
  [254] = 254,
  [255] = 255,
  [256] = 256,
  [257] = 257,
  [258] = 258,
  [259] = 259,
  [260] = 260,
  [261] = 261,
  [262] = 262,
  [263] = 263,
  [264] = 264,
  [265] = 265,
  [266] = 266,
  [267] = 261,
  [268] = 257,
  [269] = 269,
  [270] = 270,
  [271] = 262,
  [272] = 265,
  [273] = 273,
  [274] = 266,
  [275] = 275,
  [276] = 276,
  [277] = 277,
  [278] = 278,
  [279] = 275,
  [280] = 280,
  [281] = 281,
  [282] = 282,
  [283] = 283,
  [284] = 284,
  [285] = 285,
  [286] = 286,
  [287] = 284,
  [288] = 288,
  [289] = 289,
  [290] = 290,
  [291] = 291,
  [292] = 292,
  [293] = 293,
  [294] = 294,
  [295] = 295,
  [296] = 296,
  [297] = 297,
  [298] = 296,
  [299] = 299,
  [300] = 300,
  [301] = 293,
  [302] = 302,
  [303] = 303,
  [304] = 303,
  [305] = 305,
  [306] = 305,
  [307] = 307,
  [308] = 308,
  [309] = 277,
  [310] = 310,
  [311] = 311,
  [312] = 312,
  [313] = 313,
  [314] = 314,
  [315] = 315,
  [316] = 316,
  [317] = 317,
  [318] = 318,
  [319] = 319,
  [320] = 320,
  [321] = 321,
  [322] = 322,
  [323] = 323,
  [324] = 324,
  [325] = 325,
  [326] = 326,
  [327] = 327,
  [328] = 328,
  [329] = 329,
  [330] = 330,
  [331] = 331,
  [332] = 332,
  [333] = 333,
  [334] = 334,
  [335] = 332,
  [336] = 336,
  [337] = 333,
  [338] = 338,
  [339] = 339,
  [340] = 340,
  [341] = 341,
  [342] = 342,
  [343] = 343,
  [344] = 344,
  [345] = 331,
  [346] = 344,
  [347] = 330,
  [348] = 341,
  [349] = 349,
  [350] = 350,
  [351] = 351,
  [352] = 352,
  [353] = 353,
  [354] = 354,
  [355] = 355,
  [356] = 356,
  [357] = 357,
  [358] = 339,
  [359] = 359,
  [360] = 360,
  [361] = 361,
  [362] = 362,
  [363] = 363,
  [364] = 364,
  [365] = 365,
  [366] = 366,
  [367] = 367,
  [368] = 368,
  [369] = 369,
  [370] = 370,
  [371] = 371,
  [372] = 372,
  [373] = 373,
  [374] = 374,
  [375] = 371,
  [376] = 376,
  [377] = 377,
  [378] = 376,
  [379] = 379,
  [380] = 380,
  [381] = 381,
  [382] = 382,
  [383] = 383,
  [384] = 384,
  [385] = 385,
  [386] = 366,
  [387] = 387,
  [388] = 388,
  [389] = 389,
  [390] = 390,
  [391] = 391,
  [392] = 392,
  [393] = 393,
  [394] = 394,
  [395] = 395,
  [396] = 396,
  [397] = 397,
  [398] = 398,
  [399] = 399,
  [400] = 400,
  [401] = 401,
  [402] = 402,
  [403] = 403,
  [404] = 404,
  [405] = 314,
  [406] = 406,
  [407] = 407,
  [408] = 408,
  [409] = 409,
  [410] = 410,
  [411] = 411,
  [412] = 412,
  [413] = 413,
  [414] = 414,
  [415] = 415,
  [416] = 353,
  [417] = 355,
  [418] = 418,
  [419] = 419,
  [420] = 420,
  [421] = 354,
  [422] = 422,
  [423] = 423,
  [424] = 410,
  [425] = 425,
  [426] = 426,
  [427] = 313,
  [428] = 407,
  [429] = 429,
  [430] = 430,
  [431] = 431,
  [432] = 432,
  [433] = 433,
  [434] = 434,
  [435] = 435,
  [436] = 436,
  [437] = 437,
  [438] = 349,
  [439] = 439,
  [440] = 440,
  [441] = 441,
  [442] = 442,
  [443] = 443,
  [444] = 444,
  [445] = 445,
  [446] = 446,
  [447] = 447,
  [448] = 448,
  [449] = 449,
  [450] = 450,
  [451] = 451,
  [452] = 452,
  [453] = 453,
  [454] = 454,
  [455] = 448,
  [456] = 456,
  [457] = 457,
  [458] = 458,
  [459] = 459,
  [460] = 460,
  [461] = 461,
  [462] = 462,
  [463] = 463,
  [464] = 464,
  [465] = 465,
  [466] = 466,
  [467] = 467,
  [468] = 418,
  [469] = 469,
  [470] = 470,
  [471] = 471,
  [472] = 472,
  [473] = 473,
  [474] = 445,
  [475] = 475,
  [476] = 476,
  [477] = 477,
  [478] = 478,
  [479] = 479,
  [480] = 480,
  [481] = 457,
  [482] = 482,
  [483] = 483,
  [484] = 484,
  [485] = 485,
  [486] = 486,
  [487] = 487,
  [488] = 488,
  [489] = 489,
  [490] = 490,
  [491] = 491,
  [492] = 492,
  [493] = 493,
  [494] = 494,
  [495] = 495,
  [496] = 484,
  [497] = 497,
  [498] = 498,
  [499] = 486,
  [500] = 500,
  [501] = 490,
  [502] = 494,
  [503] = 373,
  [504] = 374,
  [505] = 505,
  [506] = 506,
  [507] = 507,
  [508] = 508,
  [509] = 509,
  [510] = 510,
  [511] = 498,
  [512] = 512,
  [513] = 422,
  [514] = 514,
  [515] = 515,
  [516] = 393,
  [517] = 517,
  [518] = 518,
  [519] = 519,
  [520] = 520,
  [521] = 521,
  [522] = 522,
  [523] = 523,
  [524] = 524,
  [525] = 525,
  [526] = 526,
  [527] = 527,
  [528] = 528,
  [529] = 529,
  [530] = 530,
  [531] = 531,
  [532] = 532,
  [533] = 533,
  [534] = 534,
  [535] = 535,
  [536] = 536,
  [537] = 443,
  [538] = 525,
  [539] = 539,
  [540] = 540,
  [541] = 541,
  [542] = 542,
  [543] = 543,
  [544] = 388,
  [545] = 545,
  [546] = 529,
  [547] = 437,
  [548] = 531,
  [549] = 549,
  [550] = 550,
  [551] = 359,
  [552] = 254,
  [553] = 553,
  [554] = 392,
  [555] = 555,
  [556] = 402,
  [557] = 385,
  [558] = 558,
  [559] = 559,
  [560] = 560,
  [561] = 561,
  [562] = 562,
  [563] = 563,
  [564] = 564,
  [565] = 565,
  [566] = 566,
  [567] = 400,
  [568] = 568,
  [569] = 404,
  [570] = 570,
  [571] = 571,
  [572] = 572,
  [573] = 573,
  [574] = 574,
  [575] = 575,
  [576] = 515,
  [577] = 577,
  [578] = 578,
  [579] = 579,
  [580] = 580,
  [581] = 573,
  [582] = 582,
  [583] = 574,
  [584] = 584,
  [585] = 585,
  [586] = 578,
  [587] = 587,
  [588] = 588,
  [589] = 589,
  [590] = 590,
  [591] = 591,
  [592] = 256,
  [593] = 593,
  [594] = 587,
  [595] = 595,
  [596] = 596,
  [597] = 597,
  [598] = 598,
  [599] = 599,
  [600] = 600,
  [601] = 601,
  [602] = 602,
  [603] = 603,
  [604] = 604,
  [605] = 605,
  [606] = 606,
  [607] = 607,
  [608] = 608,
  [609] = 603,
  [610] = 610,
  [611] = 608,
  [612] = 612,
  [613] = 613,
  [614] = 614,
  [615] = 615,
  [616] = 616,
  [617] = 617,
  [618] = 618,
  [619] = 619,
  [620] = 620,
  [621] = 621,
  [622] = 622,
  [623] = 623,
  [624] = 624,
  [625] = 625,
  [626] = 626,
  [627] = 627,
  [628] = 628,
  [629] = 629,
  [630] = 630,
  [631] = 631,
  [632] = 632,
  [633] = 633,
  [634] = 634,
  [635] = 635,
  [636] = 636,
  [637] = 637,
  [638] = 638,
  [639] = 639,
  [640] = 618,
  [641] = 641,
  [642] = 642,
  [643] = 643,
  [644] = 644,
  [645] = 632,
  [646] = 644,
  [647] = 647,
  [648] = 635,
  [649] = 649,
  [650] = 650,
  [651] = 605,
  [652] = 652,
  [653] = 653,
  [654] = 654,
  [655] = 655,
  [656] = 656,
  [657] = 657,
  [658] = 658,
  [659] = 659,
  [660] = 660,
};

static inline bool sym_lowercase_identifier_character_set_1(int32_t c) {
  return (c < 43646
    ? (c < 4238
      ? (c < 2741
        ? (c < 2042
          ? (c < 1015
            ? (c < 750
              ? (c < 216
                ? (c < 181
                  ? (c < 170
                    ? (c >= 'a' && c <= 'z')
                    : c <= 170)
                  : (c <= 181 || (c < 192
                    ? c == 186
                    : c <= 214)))
                : (c <= 246 || (c < 736
                  ? (c < 710
                    ? (c >= 248 && c <= 705)
                    : c <= 721)
                  : (c <= 740 || c == 748))))
              : (c <= 750 || (c < 902
                ? (c < 891
                  ? (c < 886
                    ? (c >= 880 && c <= 884)
                    : c <= 887)
                  : (c <= 893 || c == 895))
                : (c <= 902 || (c < 910
                  ? (c < 908
                    ? (c >= 904 && c <= 906)
                    : c <= 908)
                  : (c <= 929 || (c >= 931 && c <= 1013)))))))
            : (c <= 1153 || (c < 1765
              ? (c < 1519
                ? (c < 1369
                  ? (c < 1329
                    ? (c >= 1162 && c <= 1327)
                    : c <= 1366)
                  : (c <= 1369 || (c < 1488
                    ? (c >= 1376 && c <= 1416)
                    : c <= 1514)))
                : (c <= 1522 || (c < 1649
                  ? (c < 1646
                    ? (c >= 1568 && c <= 1610)
                    : c <= 1647)
                  : (c <= 1747 || c == 1749))))
              : (c <= 1766 || (c < 1810
                ? (c < 1791
                  ? (c < 1786
                    ? (c >= 1774 && c <= 1775)
                    : c <= 1788)
                  : (c <= 1791 || c == 1808))
                : (c <= 1839 || (c < 1994
                  ? (c < 1969
                    ? (c >= 1869 && c <= 1957)
                    : c <= 1969)
                  : (c <= 2026 || (c >= 2036 && c <= 2037)))))))))
          : (c <= 2042 || (c < 2493
            ? (c < 2365
              ? (c < 2144
                ? (c < 2084
                  ? (c < 2074
                    ? (c >= 2048 && c <= 2069)
                    : c <= 2074)
                  : (c <= 2084 || (c < 2112
                    ? c == 2088
                    : c <= 2136)))
                : (c <= 2154 || (c < 2208
                  ? (c < 2185
                    ? (c >= 2160 && c <= 2183)
                    : c <= 2190)
                  : (c <= 2249 || (c >= 2308 && c <= 2361)))))
              : (c <= 2365 || (c < 2447
                ? (c < 2417
                  ? (c < 2392
                    ? c == 2384
                    : c <= 2401)
                  : (c <= 2432 || (c >= 2437 && c <= 2444)))
                : (c <= 2448 || (c < 2482
                  ? (c < 2474
                    ? (c >= 2451 && c <= 2472)
                    : c <= 2480)
                  : (c <= 2482 || (c >= 2486 && c <= 2489)))))))
            : (c <= 2493 || (c < 2613
              ? (c < 2565
                ? (c < 2527
                  ? (c < 2524
                    ? c == 2510
                    : c <= 2525)
                  : (c <= 2529 || (c < 2556
                    ? (c >= 2544 && c <= 2545)
                    : c <= 2556)))
                : (c <= 2570 || (c < 2602
                  ? (c < 2579
                    ? (c >= 2575 && c <= 2576)
                    : c <= 2600)
                  : (c <= 2608 || (c >= 2610 && c <= 2611)))))
              : (c <= 2614 || (c < 2693
                ? (c < 2654
                  ? (c < 2649
                    ? (c >= 2616 && c <= 2617)
                    : c <= 2652)
                  : (c <= 2654 || (c >= 2674 && c <= 2676)))
                : (c <= 2701 || (c < 2730
                  ? (c < 2707
                    ? (c >= 2703 && c <= 2705)
                    : c <= 2728)
                  : (c <= 2736 || (c >= 2738 && c <= 2739)))))))))))
        : (c <= 2745 || (c < 3296
          ? (c < 2974
            ? (c < 2877
              ? (c < 2831
                ? (c < 2784
                  ? (c < 2768
                    ? c == 2749
                    : c <= 2768)
                  : (c <= 2785 || (c < 2821
                    ? c == 2809
                    : c <= 2828)))
                : (c <= 2832 || (c < 2866
                  ? (c < 2858
                    ? (c >= 2835 && c <= 2856)
                    : c <= 2864)
                  : (c <= 2867 || (c >= 2869 && c <= 2873)))))
              : (c <= 2877 || (c < 2949
                ? (c < 2929
                  ? (c < 2911
                    ? (c >= 2908 && c <= 2909)
                    : c <= 2913)
                  : (c <= 2929 || c == 2947))
                : (c <= 2954 || (c < 2969
                  ? (c < 2962
                    ? (c >= 2958 && c <= 2960)
                    : c <= 2965)
                  : (c <= 2970 || c == 2972))))))
            : (c <= 2975 || (c < 3165
              ? (c < 3086
                ? (c < 2990
                  ? (c < 2984
                    ? (c >= 2979 && c <= 2980)
                    : c <= 2986)
                  : (c <= 3001 || (c < 3077
                    ? c == 3024
                    : c <= 3084)))
                : (c <= 3088 || (c < 3133
                  ? (c < 3114
                    ? (c >= 3090 && c <= 3112)
                    : c <= 3129)
                  : (c <= 3133 || (c >= 3160 && c <= 3162)))))
              : (c <= 3165 || (c < 3218
                ? (c < 3205
                  ? (c < 3200
                    ? (c >= 3168 && c <= 3169)
                    : c <= 3200)
                  : (c <= 3212 || (c >= 3214 && c <= 3216)))
                : (c <= 3240 || (c < 3261
                  ? (c < 3253
                    ? (c >= 3242 && c <= 3251)
                    : c <= 3257)
                  : (c <= 3261 || (c >= 3293 && c <= 3294)))))))))
          : (c <= 3297 || (c < 3724
            ? (c < 3482
              ? (c < 3406
                ? (c < 3342
                  ? (c < 3332
                    ? (c >= 3313 && c <= 3314)
                    : c <= 3340)
                  : (c <= 3344 || (c < 3389
                    ? (c >= 3346 && c <= 3386)
                    : c <= 3389)))
                : (c <= 3406 || (c < 3450
                  ? (c < 3423
                    ? (c >= 3412 && c <= 3414)
                    : c <= 3425)
                  : (c <= 3455 || (c >= 3461 && c <= 3478)))))
              : (c <= 3505 || (c < 3634
                ? (c < 3520
                  ? (c < 3517
                    ? (c >= 3507 && c <= 3515)
                    : c <= 3517)
                  : (c <= 3526 || (c >= 3585 && c <= 3632)))
                : (c <= 3634 || (c < 3716
                  ? (c < 3713
                    ? (c >= 3648 && c <= 3654)
                    : c <= 3714)
                  : (c <= 3716 || (c >= 3718 && c <= 3722)))))))
            : (c <= 3747 || (c < 3913
              ? (c < 3776
                ? (c < 3762
                  ? (c < 3751
                    ? c == 3749
                    : c <= 3760)
                  : (c <= 3762 || c == 3773))
                : (c <= 3780 || (c < 3840
                  ? (c < 3804
                    ? c == 3782
                    : c <= 3807)
                  : (c <= 3840 || (c >= 3904 && c <= 3911)))))
              : (c <= 3948 || (c < 4186
                ? (c < 4159
                  ? (c < 4096
                    ? (c >= 3976 && c <= 3980)
                    : c <= 4138)
                  : (c <= 4159 || (c >= 4176 && c <= 4181)))
                : (c <= 4189 || (c < 4206
                  ? (c < 4197
                    ? c == 4193
                    : c <= 4198)
                  : (c <= 4208 || (c >= 4213 && c <= 4225)))))))))))))
      : (c <= 4238 || (c < 8182
        ? (c < 6480
          ? (c < 4992
            ? (c < 4746
              ? (c < 4682
                ? (c < 4301
                  ? (c < 4295
                    ? (c >= 4256 && c <= 4293)
                    : c <= 4295)
                  : (c <= 4301 || (c < 4348
                    ? (c >= 4304 && c <= 4346)
                    : c <= 4680)))
                : (c <= 4685 || (c < 4698
                  ? (c < 4696
                    ? (c >= 4688 && c <= 4694)
                    : c <= 4696)
                  : (c <= 4701 || (c >= 4704 && c <= 4744)))))
              : (c <= 4749 || (c < 4802
                ? (c < 4792
                  ? (c < 4786
                    ? (c >= 4752 && c <= 4784)
                    : c <= 4789)
                  : (c <= 4798 || c == 4800))
                : (c <= 4805 || (c < 4882
                  ? (c < 4824
                    ? (c >= 4808 && c <= 4822)
                    : c <= 4880)
                  : (c <= 4885 || (c >= 4888 && c <= 4954)))))))
            : (c <= 5007 || (c < 5984
              ? (c < 5792
                ? (c < 5121
                  ? (c < 5112
                    ? (c >= 5024 && c <= 5109)
                    : c <= 5117)
                  : (c <= 5740 || (c < 5761
                    ? (c >= 5743 && c <= 5759)
                    : c <= 5786)))
                : (c <= 5866 || (c < 5919
                  ? (c < 5888
                    ? (c >= 5870 && c <= 5880)
                    : c <= 5905)
                  : (c <= 5937 || (c >= 5952 && c <= 5969)))))
              : (c <= 5996 || (c < 6176
                ? (c < 6103
                  ? (c < 6016
                    ? (c >= 5998 && c <= 6000)
                    : c <= 6067)
                  : (c <= 6103 || c == 6108))
                : (c <= 6264 || (c < 6320
                  ? (c < 6314
                    ? (c >= 6272 && c <= 6312)
                    : c <= 6314)
                  : (c <= 6389 || (c >= 6400 && c <= 6430)))))))))
          : (c <= 6509 || (c < 7418
            ? (c < 7098
              ? (c < 6823
                ? (c < 6576
                  ? (c < 6528
                    ? (c >= 6512 && c <= 6516)
                    : c <= 6571)
                  : (c <= 6601 || (c < 6688
                    ? (c >= 6656 && c <= 6678)
                    : c <= 6740)))
                : (c <= 6823 || (c < 7043
                  ? (c < 6981
                    ? (c >= 6917 && c <= 6963)
                    : c <= 6988)
                  : (c <= 7072 || (c >= 7086 && c <= 7087)))))
              : (c <= 7141 || (c < 7312
                ? (c < 7258
                  ? (c < 7245
                    ? (c >= 7168 && c <= 7203)
                    : c <= 7247)
                  : (c <= 7293 || (c >= 7296 && c <= 7304)))
                : (c <= 7354 || (c < 7406
                  ? (c < 7401
                    ? (c >= 7357 && c <= 7359)
                    : c <= 7404)
                  : (c <= 7411 || (c >= 7413 && c <= 7414)))))))
            : (c <= 7418 || (c < 8031
              ? (c < 8008
                ? (c < 7960
                  ? (c < 7680
                    ? (c >= 7424 && c <= 7615)
                    : c <= 7957)
                  : (c <= 7965 || (c >= 7968 && c <= 8005)))
                : (c <= 8013 || (c < 8027
                  ? (c < 8025
                    ? (c >= 8016 && c <= 8023)
                    : c <= 8025)
                  : (c <= 8027 || c == 8029))))
              : (c <= 8061 || (c < 8134
                ? (c < 8126
                  ? (c < 8118
                    ? (c >= 8064 && c <= 8116)
                    : c <= 8124)
                  : (c <= 8126 || (c >= 8130 && c <= 8132)))
                : (c <= 8140 || (c < 8160
                  ? (c < 8150
                    ? (c >= 8144 && c <= 8147)
                    : c <= 8155)
                  : (c <= 8172 || (c >= 8178 && c <= 8180)))))))))))
        : (c <= 8188 || (c < 12549
          ? (c < 11559
            ? (c < 8488
              ? (c < 8458
                ? (c < 8336
                  ? (c < 8319
                    ? c == 8305
                    : c <= 8319)
                  : (c <= 8348 || (c < 8455
                    ? c == 8450
                    : c <= 8455)))
                : (c <= 8467 || (c < 8484
                  ? (c < 8472
                    ? c == 8469
                    : c <= 8477)
                  : (c <= 8484 || c == 8486))))
              : (c <= 8488 || (c < 8544
                ? (c < 8517
                  ? (c < 8508
                    ? (c >= 8490 && c <= 8505)
                    : c <= 8511)
                  : (c <= 8521 || c == 8526))
                : (c <= 8584 || (c < 11506
                  ? (c < 11499
                    ? (c >= 11264 && c <= 11492)
                    : c <= 11502)
                  : (c <= 11507 || (c >= 11520 && c <= 11557)))))))
            : (c <= 11559 || (c < 11728
              ? (c < 11688
                ? (c < 11631
                  ? (c < 11568
                    ? c == 11565
                    : c <= 11623)
                  : (c <= 11631 || (c < 11680
                    ? (c >= 11648 && c <= 11670)
                    : c <= 11686)))
                : (c <= 11694 || (c < 11712
                  ? (c < 11704
                    ? (c >= 11696 && c <= 11702)
                    : c <= 11710)
                  : (c <= 11718 || (c >= 11720 && c <= 11726)))))
              : (c <= 11734 || (c < 12344
                ? (c < 12321
                  ? (c < 12293
                    ? (c >= 11736 && c <= 11742)
                    : c <= 12295)
                  : (c <= 12329 || (c >= 12337 && c <= 12341)))
                : (c <= 12348 || (c < 12449
                  ? (c < 12445
                    ? (c >= 12353 && c <= 12438)
                    : c <= 12447)
                  : (c <= 12538 || (c >= 12540 && c <= 12543)))))))))
          : (c <= 12591 || (c < 43015
            ? (c < 42623
              ? (c < 42192
                ? (c < 12784
                  ? (c < 12704
                    ? (c >= 12593 && c <= 12686)
                    : c <= 12735)
                  : (c <= 12799 || (c < 19968
                    ? (c >= 13312 && c <= 19903)
                    : c <= 42124)))
                : (c <= 42237 || (c < 42538
                  ? (c < 42512
                    ? (c >= 42240 && c <= 42508)
                    : c <= 42527)
                  : (c <= 42539 || (c >= 42560 && c <= 42606)))))
              : (c <= 42653 || (c < 42960
                ? (c < 42786
                  ? (c < 42775
                    ? (c >= 42656 && c <= 42735)
                    : c <= 42783)
                  : (c <= 42888 || (c >= 42891 && c <= 42954)))
                : (c <= 42961 || (c < 42994
                  ? (c < 42965
                    ? c == 42963
                    : c <= 42969)
                  : (c <= 43009 || (c >= 43011 && c <= 43013)))))))
            : (c <= 43018 || (c < 43396
              ? (c < 43259
                ? (c < 43138
                  ? (c < 43072
                    ? (c >= 43020 && c <= 43042)
                    : c <= 43123)
                  : (c <= 43187 || (c >= 43250 && c <= 43255)))
                : (c <= 43259 || (c < 43312
                  ? (c < 43274
                    ? (c >= 43261 && c <= 43262)
                    : c <= 43301)
                  : (c <= 43334 || (c >= 43360 && c <= 43388)))))
              : (c <= 43442 || (c < 43520
                ? (c < 43494
                  ? (c < 43488
                    ? c == 43471
                    : c <= 43492)
                  : (c <= 43503 || (c >= 43514 && c <= 43518)))
                : (c <= 43560 || (c < 43616
                  ? (c < 43588
                    ? (c >= 43584 && c <= 43586)
                    : c <= 43595)
                  : (c <= 43638 || c == 43642))))))))))))))
    : (c <= 43695 || (c < 71236
      ? (c < 67424
        ? (c < 65149
          ? (c < 64112
            ? (c < 43793
              ? (c < 43739
                ? (c < 43705
                  ? (c < 43701
                    ? c == 43697
                    : c <= 43702)
                  : (c <= 43709 || (c < 43714
                    ? c == 43712
                    : c <= 43714)))
                : (c <= 43741 || (c < 43777
                  ? (c < 43762
                    ? (c >= 43744 && c <= 43754)
                    : c <= 43764)
                  : (c <= 43782 || (c >= 43785 && c <= 43790)))))
              : (c <= 43798 || (c < 43888
                ? (c < 43824
                  ? (c < 43816
                    ? (c >= 43808 && c <= 43814)
                    : c <= 43822)
                  : (c <= 43866 || (c >= 43868 && c <= 43881)))
                : (c <= 44002 || (c < 55243
                  ? (c < 55216
                    ? (c >= 44032 && c <= 55203)
                    : c <= 55238)
                  : (c <= 55291 || (c >= 63744 && c <= 64109)))))))
            : (c <= 64217 || (c < 64467
              ? (c < 64312
                ? (c < 64285
                  ? (c < 64275
                    ? (c >= 64256 && c <= 64262)
                    : c <= 64279)
                  : (c <= 64285 || (c < 64298
                    ? (c >= 64287 && c <= 64296)
                    : c <= 64310)))
                : (c <= 64316 || (c < 64323
                  ? (c < 64320
                    ? c == 64318
                    : c <= 64321)
                  : (c <= 64324 || (c >= 64326 && c <= 64433)))))
              : (c <= 64605 || (c < 65137
                ? (c < 64914
                  ? (c < 64848
                    ? (c >= 64612 && c <= 64829)
                    : c <= 64911)
                  : (c <= 64967 || (c >= 65008 && c <= 65017)))
                : (c <= 65137 || (c < 65145
                  ? (c < 65143
                    ? c == 65139
                    : c <= 65143)
                  : (c <= 65145 || c == 65147))))))))
          : (c <= 65149 || (c < 66349
            ? (c < 65549
              ? (c < 65474
                ? (c < 65345
                  ? (c < 65313
                    ? (c >= 65151 && c <= 65276)
                    : c <= 65338)
                  : (c <= 65370 || (c < 65440
                    ? (c >= 65382 && c <= 65437)
                    : c <= 65470)))
                : (c <= 65479 || (c < 65498
                  ? (c < 65490
                    ? (c >= 65482 && c <= 65487)
                    : c <= 65495)
                  : (c <= 65500 || (c >= 65536 && c <= 65547)))))
              : (c <= 65574 || (c < 65664
                ? (c < 65599
                  ? (c < 65596
                    ? (c >= 65576 && c <= 65594)
                    : c <= 65597)
                  : (c <= 65613 || (c >= 65616 && c <= 65629)))
                : (c <= 65786 || (c < 66208
                  ? (c < 66176
                    ? (c >= 65856 && c <= 65908)
                    : c <= 66204)
                  : (c <= 66256 || (c >= 66304 && c <= 66335)))))))
            : (c <= 66378 || (c < 66928
              ? (c < 66560
                ? (c < 66464
                  ? (c < 66432
                    ? (c >= 66384 && c <= 66421)
                    : c <= 66461)
                  : (c <= 66499 || (c < 66513
                    ? (c >= 66504 && c <= 66511)
                    : c <= 66517)))
                : (c <= 66717 || (c < 66816
                  ? (c < 66776
                    ? (c >= 66736 && c <= 66771)
                    : c <= 66811)
                  : (c <= 66855 || (c >= 66864 && c <= 66915)))))
              : (c <= 66938 || (c < 66979
                ? (c < 66964
                  ? (c < 66956
                    ? (c >= 66940 && c <= 66954)
                    : c <= 66962)
                  : (c <= 66965 || (c >= 66967 && c <= 66977)))
                : (c <= 66993 || (c < 67072
                  ? (c < 67003
                    ? (c >= 66995 && c <= 67001)
                    : c <= 67004)
                  : (c <= 67382 || (c >= 67392 && c <= 67413)))))))))))
        : (c <= 67431 || (c < 69635
          ? (c < 68121
            ? (c < 67712
              ? (c < 67594
                ? (c < 67506
                  ? (c < 67463
                    ? (c >= 67456 && c <= 67461)
                    : c <= 67504)
                  : (c <= 67514 || (c < 67592
                    ? (c >= 67584 && c <= 67589)
                    : c <= 67592)))
                : (c <= 67637 || (c < 67647
                  ? (c < 67644
                    ? (c >= 67639 && c <= 67640)
                    : c <= 67644)
                  : (c <= 67669 || (c >= 67680 && c <= 67702)))))
              : (c <= 67742 || (c < 67968
                ? (c < 67840
                  ? (c < 67828
                    ? (c >= 67808 && c <= 67826)
                    : c <= 67829)
                  : (c <= 67861 || (c >= 67872 && c <= 67897)))
                : (c <= 68023 || (c < 68112
                  ? (c < 68096
                    ? (c >= 68030 && c <= 68031)
                    : c <= 68096)
                  : (c <= 68115 || (c >= 68117 && c <= 68119)))))))
            : (c <= 68149 || (c < 68800
              ? (c < 68416
                ? (c < 68288
                  ? (c < 68224
                    ? (c >= 68192 && c <= 68220)
                    : c <= 68252)
                  : (c <= 68295 || (c < 68352
                    ? (c >= 68297 && c <= 68324)
                    : c <= 68405)))
                : (c <= 68437 || (c < 68608
                  ? (c < 68480
                    ? (c >= 68448 && c <= 68466)
                    : c <= 68497)
                  : (c <= 68680 || (c >= 68736 && c <= 68786)))))
              : (c <= 68850 || (c < 69415
                ? (c < 69296
                  ? (c < 69248
                    ? (c >= 68864 && c <= 68899)
                    : c <= 69289)
                  : (c <= 69297 || (c >= 69376 && c <= 69404)))
                : (c <= 69415 || (c < 69552
                  ? (c < 69488
                    ? (c >= 69424 && c <= 69445)
                    : c <= 69505)
                  : (c <= 69572 || (c >= 69600 && c <= 69622)))))))))
          : (c <= 69687 || (c < 70303
            ? (c < 70081
              ? (c < 69956
                ? (c < 69763
                  ? (c < 69749
                    ? (c >= 69745 && c <= 69746)
                    : c <= 69749)
                  : (c <= 69807 || (c < 69891
                    ? (c >= 69840 && c <= 69864)
                    : c <= 69926)))
                : (c <= 69956 || (c < 70006
                  ? (c < 69968
                    ? c == 69959
                    : c <= 70002)
                  : (c <= 70006 || (c >= 70019 && c <= 70066)))))
              : (c <= 70084 || (c < 70207
                ? (c < 70144
                  ? (c < 70108
                    ? c == 70106
                    : c <= 70108)
                  : (c <= 70161 || (c >= 70163 && c <= 70187)))
                : (c <= 70208 || (c < 70282
                  ? (c < 70280
                    ? (c >= 70272 && c <= 70278)
                    : c <= 70280)
                  : (c <= 70285 || (c >= 70287 && c <= 70301)))))))
            : (c <= 70312 || (c < 70493
              ? (c < 70442
                ? (c < 70415
                  ? (c < 70405
                    ? (c >= 70320 && c <= 70366)
                    : c <= 70412)
                  : (c <= 70416 || (c >= 70419 && c <= 70440)))
                : (c <= 70448 || (c < 70461
                  ? (c < 70453
                    ? (c >= 70450 && c <= 70451)
                    : c <= 70457)
                  : (c <= 70461 || c == 70480))))
              : (c <= 70497 || (c < 70852
                ? (c < 70751
                  ? (c < 70727
                    ? (c >= 70656 && c <= 70708)
                    : c <= 70730)
                  : (c <= 70753 || (c >= 70784 && c <= 70831)))
                : (c <= 70853 || (c < 71128
                  ? (c < 71040
                    ? c == 70855
                    : c <= 71086)
                  : (c <= 71131 || (c >= 71168 && c <= 71215)))))))))))))
      : (c <= 71236 || (c < 119973
        ? (c < 73728
          ? (c < 72272
            ? (c < 71960
              ? (c < 71840
                ? (c < 71424
                  ? (c < 71352
                    ? (c >= 71296 && c <= 71338)
                    : c <= 71352)
                  : (c <= 71450 || (c < 71680
                    ? (c >= 71488 && c <= 71494)
                    : c <= 71723)))
                : (c <= 71903 || (c < 71948
                  ? (c < 71945
                    ? (c >= 71935 && c <= 71942)
                    : c <= 71945)
                  : (c <= 71955 || (c >= 71957 && c <= 71958)))))
              : (c <= 71983 || (c < 72161
                ? (c < 72096
                  ? (c < 72001
                    ? c == 71999
                    : c <= 72001)
                  : (c <= 72103 || (c >= 72106 && c <= 72144)))
                : (c <= 72161 || (c < 72203
                  ? (c < 72192
                    ? c == 72163
                    : c <= 72192)
                  : (c <= 72242 || c == 72250))))))
            : (c <= 72272 || (c < 73030
              ? (c < 72768
                ? (c < 72368
                  ? (c < 72349
                    ? (c >= 72284 && c <= 72329)
                    : c <= 72349)
                  : (c <= 72440 || (c < 72714
                    ? (c >= 72704 && c <= 72712)
                    : c <= 72750)))
                : (c <= 72768 || (c < 72968
                  ? (c < 72960
                    ? (c >= 72818 && c <= 72847)
                    : c <= 72966)
                  : (c <= 72969 || (c >= 72971 && c <= 73008)))))
              : (c <= 73030 || (c < 73440
                ? (c < 73066
                  ? (c < 73063
                    ? (c >= 73056 && c <= 73061)
                    : c <= 73064)
                  : (c <= 73097 || c == 73112))
                : (c <= 73458 || (c < 73490
                  ? (c < 73476
                    ? c == 73474
                    : c <= 73488)
                  : (c <= 73523 || c == 73648))))))))
          : (c <= 74649 || (c < 94208
            ? (c < 92928
              ? (c < 82944
                ? (c < 77712
                  ? (c < 74880
                    ? (c >= 74752 && c <= 74862)
                    : c <= 75075)
                  : (c <= 77808 || (c < 78913
                    ? (c >= 77824 && c <= 78895)
                    : c <= 78918)))
                : (c <= 83526 || (c < 92784
                  ? (c < 92736
                    ? (c >= 92160 && c <= 92728)
                    : c <= 92766)
                  : (c <= 92862 || (c >= 92880 && c <= 92909)))))
              : (c <= 92975 || (c < 93952
                ? (c < 93053
                  ? (c < 93027
                    ? (c >= 92992 && c <= 92995)
                    : c <= 93047)
                  : (c <= 93071 || (c >= 93760 && c <= 93823)))
                : (c <= 94026 || (c < 94176
                  ? (c < 94099
                    ? c == 94032
                    : c <= 94111)
                  : (c <= 94177 || c == 94179))))))
            : (c <= 100343 || (c < 110948
              ? (c < 110589
                ? (c < 110576
                  ? (c < 101632
                    ? (c >= 100352 && c <= 101589)
                    : c <= 101640)
                  : (c <= 110579 || (c >= 110581 && c <= 110587)))
                : (c <= 110590 || (c < 110928
                  ? (c < 110898
                    ? (c >= 110592 && c <= 110882)
                    : c <= 110898)
                  : (c <= 110930 || c == 110933))))
              : (c <= 110951 || (c < 113808
                ? (c < 113776
                  ? (c < 113664
                    ? (c >= 110960 && c <= 111355)
                    : c <= 113770)
                  : (c <= 113788 || (c >= 113792 && c <= 113800)))
                : (c <= 113817 || (c < 119966
                  ? (c < 119894
                    ? (c >= 119808 && c <= 119892)
                    : c <= 119964)
                  : (c <= 119967 || c == 119970))))))))))
        : (c <= 119974 || (c < 126464
          ? (c < 120656
            ? (c < 120128
              ? (c < 120071
                ? (c < 119995
                  ? (c < 119982
                    ? (c >= 119977 && c <= 119980)
                    : c <= 119993)
                  : (c <= 119995 || (c < 120005
                    ? (c >= 119997 && c <= 120003)
                    : c <= 120069)))
                : (c <= 120074 || (c < 120094
                  ? (c < 120086
                    ? (c >= 120077 && c <= 120084)
                    : c <= 120092)
                  : (c <= 120121 || (c >= 120123 && c <= 120126)))))
              : (c <= 120132 || (c < 120514
                ? (c < 120146
                  ? (c < 120138
                    ? c == 120134
                    : c <= 120144)
                  : (c <= 120485 || (c >= 120488 && c <= 120512)))
                : (c <= 120538 || (c < 120598
                  ? (c < 120572
                    ? (c >= 120540 && c <= 120570)
                    : c <= 120596)
                  : (c <= 120628 || (c >= 120630 && c <= 120654)))))))
            : (c <= 120686 || (c < 123536
              ? (c < 122661
                ? (c < 120746
                  ? (c < 120714
                    ? (c >= 120688 && c <= 120712)
                    : c <= 120744)
                  : (c <= 120770 || (c < 122624
                    ? (c >= 120772 && c <= 120779)
                    : c <= 122654)))
                : (c <= 122666 || (c < 123191
                  ? (c < 123136
                    ? (c >= 122928 && c <= 122989)
                    : c <= 123180)
                  : (c <= 123197 || c == 123214))))
              : (c <= 123565 || (c < 124909
                ? (c < 124896
                  ? (c < 124112
                    ? (c >= 123584 && c <= 123627)
                    : c <= 124139)
                  : (c <= 124902 || (c >= 124904 && c <= 124907)))
                : (c <= 124910 || (c < 125184
                  ? (c < 124928
                    ? (c >= 124912 && c <= 124926)
                    : c <= 125124)
                  : (c <= 125251 || c == 125259))))))))
          : (c <= 126467 || (c < 126561
            ? (c < 126537
              ? (c < 126516
                ? (c < 126500
                  ? (c < 126497
                    ? (c >= 126469 && c <= 126495)
                    : c <= 126498)
                  : (c <= 126500 || (c < 126505
                    ? c == 126503
                    : c <= 126514)))
                : (c <= 126519 || (c < 126530
                  ? (c < 126523
                    ? c == 126521
                    : c <= 126523)
                  : (c <= 126530 || c == 126535))))
              : (c <= 126537 || (c < 126551
                ? (c < 126545
                  ? (c < 126541
                    ? c == 126539
                    : c <= 126543)
                  : (c <= 126546 || c == 126548))
                : (c <= 126551 || (c < 126557
                  ? (c < 126555
                    ? c == 126553
                    : c <= 126555)
                  : (c <= 126557 || c == 126559))))))
            : (c <= 126562 || (c < 126629
              ? (c < 126585
                ? (c < 126572
                  ? (c < 126567
                    ? c == 126564
                    : c <= 126570)
                  : (c <= 126578 || (c >= 126580 && c <= 126583)))
                : (c <= 126588 || (c < 126603
                  ? (c < 126592
                    ? c == 126590
                    : c <= 126601)
                  : (c <= 126619 || (c >= 126625 && c <= 126627)))))
              : (c <= 126633 || (c < 178208
                ? (c < 173824
                  ? (c < 131072
                    ? (c >= 126635 && c <= 126651)
                    : c <= 173791)
                  : (c <= 177977 || (c >= 177984 && c <= 178205)))
                : (c <= 183969 || (c < 196608
                  ? (c < 194560
                    ? (c >= 183984 && c <= 191456)
                    : c <= 195101)
                  : (c <= 201546 || (c >= 201552 && c <= 205743)))))))))))))))));
}

static inline bool sym_lowercase_identifier_character_set_2(int32_t c) {
  return (c < 110898
    ? (c < 73490
      ? (c < 73474
        ? (c >= 70207 && c <= 70208)
        : (c <= 73474 || (c >= 73476 && c <= 73488)))
      : (c <= 73523 || (c < 78913
        ? c == 78895
        : c <= 78918)))
    : (c <= 110898 || (c < 124112
      ? (c < 122661
        ? c == 110933
        : (c <= 122666 || (c >= 122928 && c <= 122989)))
      : (c <= 124139 || (c < 201552
        ? c == 177977
        : c <= 205743)))));
}

static inline bool sym_lowercase_identifier_character_set_3(int32_t c) {
  return (c < 43520
    ? (c < 4197
      ? (c < 2730
        ? (c < 2036
          ? (c < 1015
            ? (c < 750
              ? (c < 216
                ? (c < 181
                  ? (c < 170
                    ? (c >= 'a' && c <= 'z')
                    : c <= 170)
                  : (c <= 181 || (c < 192
                    ? c == 186
                    : c <= 214)))
                : (c <= 246 || (c < 736
                  ? (c < 710
                    ? (c >= 248 && c <= 705)
                    : c <= 721)
                  : (c <= 740 || c == 748))))
              : (c <= 750 || (c < 902
                ? (c < 891
                  ? (c < 886
                    ? (c >= 880 && c <= 884)
                    : c <= 887)
                  : (c <= 893 || c == 895))
                : (c <= 902 || (c < 910
                  ? (c < 908
                    ? (c >= 904 && c <= 906)
                    : c <= 908)
                  : (c <= 929 || (c >= 931 && c <= 1013)))))))
            : (c <= 1153 || (c < 1749
              ? (c < 1488
                ? (c < 1369
                  ? (c < 1329
                    ? (c >= 1162 && c <= 1327)
                    : c <= 1366)
                  : (c <= 1369 || (c >= 1376 && c <= 1416)))
                : (c <= 1514 || (c < 1646
                  ? (c < 1568
                    ? (c >= 1519 && c <= 1522)
                    : c <= 1610)
                  : (c <= 1647 || (c >= 1649 && c <= 1747)))))
              : (c <= 1749 || (c < 1808
                ? (c < 1786
                  ? (c < 1774
                    ? (c >= 1765 && c <= 1766)
                    : c <= 1775)
                  : (c <= 1788 || c == 1791))
                : (c <= 1808 || (c < 1969
                  ? (c < 1869
                    ? (c >= 1810 && c <= 1839)
                    : c <= 1957)
                  : (c <= 1969 || (c >= 1994 && c <= 2026)))))))))
          : (c <= 2037 || (c < 2486
            ? (c < 2308
              ? (c < 2112
                ? (c < 2074
                  ? (c < 2048
                    ? c == 2042
                    : c <= 2069)
                  : (c <= 2074 || (c < 2088
                    ? c == 2084
                    : c <= 2088)))
                : (c <= 2136 || (c < 2185
                  ? (c < 2160
                    ? (c >= 2144 && c <= 2154)
                    : c <= 2183)
                  : (c <= 2190 || (c >= 2208 && c <= 2249)))))
              : (c <= 2361 || (c < 2437
                ? (c < 2392
                  ? (c < 2384
                    ? c == 2365
                    : c <= 2384)
                  : (c <= 2401 || (c >= 2417 && c <= 2432)))
                : (c <= 2444 || (c < 2474
                  ? (c < 2451
                    ? (c >= 2447 && c <= 2448)
                    : c <= 2472)
                  : (c <= 2480 || c == 2482))))))
            : (c <= 2489 || (c < 2602
              ? (c < 2544
                ? (c < 2524
                  ? (c < 2510
                    ? c == 2493
                    : c <= 2510)
                  : (c <= 2525 || (c >= 2527 && c <= 2529)))
                : (c <= 2545 || (c < 2575
                  ? (c < 2565
                    ? c == 2556
                    : c <= 2570)
                  : (c <= 2576 || (c >= 2579 && c <= 2600)))))
              : (c <= 2608 || (c < 2654
                ? (c < 2616
                  ? (c < 2613
                    ? (c >= 2610 && c <= 2611)
                    : c <= 2614)
                  : (c <= 2617 || (c >= 2649 && c <= 2652)))
                : (c <= 2654 || (c < 2703
                  ? (c < 2693
                    ? (c >= 2674 && c <= 2676)
                    : c <= 2701)
                  : (c <= 2705 || (c >= 2707 && c <= 2728)))))))))))
        : (c <= 2736 || (c < 3253
          ? (c < 2969
            ? (c < 2866
              ? (c < 2809
                ? (c < 2749
                  ? (c < 2741
                    ? (c >= 2738 && c <= 2739)
                    : c <= 2745)
                  : (c <= 2749 || (c < 2784
                    ? c == 2768
                    : c <= 2785)))
                : (c <= 2809 || (c < 2835
                  ? (c < 2831
                    ? (c >= 2821 && c <= 2828)
                    : c <= 2832)
                  : (c <= 2856 || (c >= 2858 && c <= 2864)))))
              : (c <= 2867 || (c < 2929
                ? (c < 2908
                  ? (c < 2877
                    ? (c >= 2869 && c <= 2873)
                    : c <= 2877)
                  : (c <= 2909 || (c >= 2911 && c <= 2913)))
                : (c <= 2929 || (c < 2958
                  ? (c < 2949
                    ? c == 2947
                    : c <= 2954)
                  : (c <= 2960 || (c >= 2962 && c <= 2965)))))))
            : (c <= 2970 || (c < 3114
              ? (c < 2990
                ? (c < 2979
                  ? (c < 2974
                    ? c == 2972
                    : c <= 2975)
                  : (c <= 2980 || (c >= 2984 && c <= 2986)))
                : (c <= 3001 || (c < 3086
                  ? (c < 3077
                    ? c == 3024
                    : c <= 3084)
                  : (c <= 3088 || (c >= 3090 && c <= 3112)))))
              : (c <= 3129 || (c < 3200
                ? (c < 3165
                  ? (c < 3160
                    ? c == 3133
                    : c <= 3162)
                  : (c <= 3165 || (c >= 3168 && c <= 3169)))
                : (c <= 3200 || (c < 3218
                  ? (c < 3214
                    ? (c >= 3205 && c <= 3212)
                    : c <= 3216)
                  : (c <= 3240 || (c >= 3242 && c <= 3251)))))))))
          : (c <= 3257 || (c < 3713
            ? (c < 3423
              ? (c < 3342
                ? (c < 3296
                  ? (c < 3293
                    ? c == 3261
                    : c <= 3294)
                  : (c <= 3297 || (c < 3332
                    ? (c >= 3313 && c <= 3314)
                    : c <= 3340)))
                : (c <= 3344 || (c < 3406
                  ? (c < 3389
                    ? (c >= 3346 && c <= 3386)
                    : c <= 3389)
                  : (c <= 3406 || (c >= 3412 && c <= 3414)))))
              : (c <= 3425 || (c < 3517
                ? (c < 3482
                  ? (c < 3461
                    ? (c >= 3450 && c <= 3455)
                    : c <= 3478)
                  : (c <= 3505 || (c >= 3507 && c <= 3515)))
                : (c <= 3517 || (c < 3634
                  ? (c < 3585
                    ? (c >= 3520 && c <= 3526)
                    : c <= 3632)
                  : (c <= 3634 || (c >= 3648 && c <= 3654)))))))
            : (c <= 3714 || (c < 3804
              ? (c < 3751
                ? (c < 3724
                  ? (c < 3718
                    ? c == 3716
                    : c <= 3722)
                  : (c <= 3747 || c == 3749))
                : (c <= 3760 || (c < 3776
                  ? (c < 3773
                    ? c == 3762
                    : c <= 3773)
                  : (c <= 3780 || c == 3782))))
              : (c <= 3807 || (c < 4096
                ? (c < 3913
                  ? (c < 3904
                    ? c == 3840
                    : c <= 3911)
                  : (c <= 3948 || (c >= 3976 && c <= 3980)))
                : (c <= 4138 || (c < 4186
                  ? (c < 4176
                    ? c == 4159
                    : c <= 4181)
                  : (c <= 4189 || c == 4193))))))))))))
      : (c <= 4198 || (c < 8144
        ? (c < 6272
          ? (c < 4824
            ? (c < 4696
              ? (c < 4301
                ? (c < 4238
                  ? (c < 4213
                    ? (c >= 4206 && c <= 4208)
                    : c <= 4225)
                  : (c <= 4238 || (c < 4295
                    ? (c >= 4256 && c <= 4293)
                    : c <= 4295)))
                : (c <= 4301 || (c < 4682
                  ? (c < 4348
                    ? (c >= 4304 && c <= 4346)
                    : c <= 4680)
                  : (c <= 4685 || (c >= 4688 && c <= 4694)))))
              : (c <= 4696 || (c < 4786
                ? (c < 4746
                  ? (c < 4704
                    ? (c >= 4698 && c <= 4701)
                    : c <= 4744)
                  : (c <= 4749 || (c >= 4752 && c <= 4784)))
                : (c <= 4789 || (c < 4802
                  ? (c < 4800
                    ? (c >= 4792 && c <= 4798)
                    : c <= 4800)
                  : (c <= 4805 || (c >= 4808 && c <= 4822)))))))
            : (c <= 4880 || (c < 5870
              ? (c < 5112
                ? (c < 4992
                  ? (c < 4888
                    ? (c >= 4882 && c <= 4885)
                    : c <= 4954)
                  : (c <= 5007 || (c >= 5024 && c <= 5109)))
                : (c <= 5117 || (c < 5761
                  ? (c < 5743
                    ? (c >= 5121 && c <= 5740)
                    : c <= 5759)
                  : (c <= 5786 || (c >= 5792 && c <= 5866)))))
              : (c <= 5880 || (c < 5998
                ? (c < 5952
                  ? (c < 5919
                    ? (c >= 5888 && c <= 5905)
                    : c <= 5937)
                  : (c <= 5969 || (c >= 5984 && c <= 5996)))
                : (c <= 6000 || (c < 6108
                  ? (c < 6103
                    ? (c >= 6016 && c <= 6067)
                    : c <= 6103)
                  : (c <= 6108 || (c >= 6176 && c <= 6264)))))))))
          : (c <= 6312 || (c < 7357
            ? (c < 6917
              ? (c < 6528
                ? (c < 6400
                  ? (c < 6320
                    ? c == 6314
                    : c <= 6389)
                  : (c <= 6430 || (c < 6512
                    ? (c >= 6480 && c <= 6509)
                    : c <= 6516)))
                : (c <= 6571 || (c < 6688
                  ? (c < 6656
                    ? (c >= 6576 && c <= 6601)
                    : c <= 6678)
                  : (c <= 6740 || c == 6823))))
              : (c <= 6963 || (c < 7168
                ? (c < 7086
                  ? (c < 7043
                    ? (c >= 6981 && c <= 6988)
                    : c <= 7072)
                  : (c <= 7087 || (c >= 7098 && c <= 7141)))
                : (c <= 7203 || (c < 7296
                  ? (c < 7258
                    ? (c >= 7245 && c <= 7247)
                    : c <= 7293)
                  : (c <= 7304 || (c >= 7312 && c <= 7354)))))))
            : (c <= 7359 || (c < 8016
              ? (c < 7424
                ? (c < 7413
                  ? (c < 7406
                    ? (c >= 7401 && c <= 7404)
                    : c <= 7411)
                  : (c <= 7414 || c == 7418))
                : (c <= 7615 || (c < 7968
                  ? (c < 7960
                    ? (c >= 7680 && c <= 7957)
                    : c <= 7965)
                  : (c <= 8005 || (c >= 8008 && c <= 8013)))))
              : (c <= 8023 || (c < 8064
                ? (c < 8029
                  ? (c < 8027
                    ? c == 8025
                    : c <= 8027)
                  : (c <= 8029 || (c >= 8031 && c <= 8061)))
                : (c <= 8116 || (c < 8130
                  ? (c < 8126
                    ? (c >= 8118 && c <= 8124)
                    : c <= 8126)
                  : (c <= 8132 || (c >= 8134 && c <= 8140)))))))))))
        : (c <= 8147 || (c < 12344
          ? (c < 11264
            ? (c < 8469
              ? (c < 8319
                ? (c < 8178
                  ? (c < 8160
                    ? (c >= 8150 && c <= 8155)
                    : c <= 8172)
                  : (c <= 8180 || (c < 8305
                    ? (c >= 8182 && c <= 8188)
                    : c <= 8305)))
                : (c <= 8319 || (c < 8455
                  ? (c < 8450
                    ? (c >= 8336 && c <= 8348)
                    : c <= 8450)
                  : (c <= 8455 || (c >= 8458 && c <= 8467)))))
              : (c <= 8469 || (c < 8490
                ? (c < 8486
                  ? (c < 8484
                    ? (c >= 8472 && c <= 8477)
                    : c <= 8484)
                  : (c <= 8486 || c == 8488))
                : (c <= 8505 || (c < 8526
                  ? (c < 8517
                    ? (c >= 8508 && c <= 8511)
                    : c <= 8521)
                  : (c <= 8526 || (c >= 8544 && c <= 8584)))))))
            : (c <= 11492 || (c < 11688
              ? (c < 11565
                ? (c < 11520
                  ? (c < 11506
                    ? (c >= 11499 && c <= 11502)
                    : c <= 11507)
                  : (c <= 11557 || c == 11559))
                : (c <= 11565 || (c < 11648
                  ? (c < 11631
                    ? (c >= 11568 && c <= 11623)
                    : c <= 11631)
                  : (c <= 11670 || (c >= 11680 && c <= 11686)))))
              : (c <= 11694 || (c < 11728
                ? (c < 11712
                  ? (c < 11704
                    ? (c >= 11696 && c <= 11702)
                    : c <= 11710)
                  : (c <= 11718 || (c >= 11720 && c <= 11726)))
                : (c <= 11734 || (c < 12321
                  ? (c < 12293
                    ? (c >= 11736 && c <= 11742)
                    : c <= 12295)
                  : (c <= 12329 || (c >= 12337 && c <= 12341)))))))))
          : (c <= 12348 || (c < 42960
            ? (c < 42192
              ? (c < 12593
                ? (c < 12449
                  ? (c < 12445
                    ? (c >= 12353 && c <= 12438)
                    : c <= 12447)
                  : (c <= 12538 || (c < 12549
                    ? (c >= 12540 && c <= 12543)
                    : c <= 12591)))
                : (c <= 12686 || (c < 13312
                  ? (c < 12784
                    ? (c >= 12704 && c <= 12735)
                    : c <= 12799)
                  : (c <= 19903 || (c >= 19968 && c <= 42124)))))
              : (c <= 42237 || (c < 42623
                ? (c < 42538
                  ? (c < 42512
                    ? (c >= 42240 && c <= 42508)
                    : c <= 42527)
                  : (c <= 42539 || (c >= 42560 && c <= 42606)))
                : (c <= 42653 || (c < 42786
                  ? (c < 42775
                    ? (c >= 42656 && c <= 42735)
                    : c <= 42783)
                  : (c <= 42888 || (c >= 42891 && c <= 42954)))))))
            : (c <= 42961 || (c < 43259
              ? (c < 43015
                ? (c < 42994
                  ? (c < 42965
                    ? c == 42963
                    : c <= 42969)
                  : (c <= 43009 || (c >= 43011 && c <= 43013)))
                : (c <= 43018 || (c < 43138
                  ? (c < 43072
                    ? (c >= 43020 && c <= 43042)
                    : c <= 43123)
                  : (c <= 43187 || (c >= 43250 && c <= 43255)))))
              : (c <= 43259 || (c < 43396
                ? (c < 43312
                  ? (c < 43274
                    ? (c >= 43261 && c <= 43262)
                    : c <= 43301)
                  : (c <= 43334 || (c >= 43360 && c <= 43388)))
                : (c <= 43442 || (c < 43494
                  ? (c < 43488
                    ? c == 43471
                    : c <= 43492)
                  : (c <= 43503 || (c >= 43514 && c <= 43518)))))))))))))))
    : (c <= 43560 || (c < 70751
      ? (c < 66964
        ? (c < 65008
          ? (c < 43888
            ? (c < 43739
              ? (c < 43697
                ? (c < 43616
                  ? (c < 43588
                    ? (c >= 43584 && c <= 43586)
                    : c <= 43595)
                  : (c <= 43638 || (c < 43646
                    ? c == 43642
                    : c <= 43695)))
                : (c <= 43697 || (c < 43712
                  ? (c < 43705
                    ? (c >= 43701 && c <= 43702)
                    : c <= 43709)
                  : (c <= 43712 || c == 43714))))
              : (c <= 43741 || (c < 43793
                ? (c < 43777
                  ? (c < 43762
                    ? (c >= 43744 && c <= 43754)
                    : c <= 43764)
                  : (c <= 43782 || (c >= 43785 && c <= 43790)))
                : (c <= 43798 || (c < 43824
                  ? (c < 43816
                    ? (c >= 43808 && c <= 43814)
                    : c <= 43822)
                  : (c <= 43866 || (c >= 43868 && c <= 43881)))))))
            : (c <= 44002 || (c < 64298
              ? (c < 64112
                ? (c < 55243
                  ? (c < 55216
                    ? (c >= 44032 && c <= 55203)
                    : c <= 55238)
                  : (c <= 55291 || (c >= 63744 && c <= 64109)))
                : (c <= 64217 || (c < 64285
                  ? (c < 64275
                    ? (c >= 64256 && c <= 64262)
                    : c <= 64279)
                  : (c <= 64285 || (c >= 64287 && c <= 64296)))))
              : (c <= 64310 || (c < 64326
                ? (c < 64320
                  ? (c < 64318
                    ? (c >= 64312 && c <= 64316)
                    : c <= 64318)
                  : (c <= 64321 || (c >= 64323 && c <= 64324)))
                : (c <= 64433 || (c < 64848
                  ? (c < 64612
                    ? (c >= 64467 && c <= 64605)
                    : c <= 64829)
                  : (c <= 64911 || (c >= 64914 && c <= 64967)))))))))
          : (c <= 65017 || (c < 65616
            ? (c < 65440
              ? (c < 65149
                ? (c < 65143
                  ? (c < 65139
                    ? c == 65137
                    : c <= 65139)
                  : (c <= 65143 || (c < 65147
                    ? c == 65145
                    : c <= 65147)))
                : (c <= 65149 || (c < 65345
                  ? (c < 65313
                    ? (c >= 65151 && c <= 65276)
                    : c <= 65338)
                  : (c <= 65370 || (c >= 65382 && c <= 65437)))))
              : (c <= 65470 || (c < 65536
                ? (c < 65490
                  ? (c < 65482
                    ? (c >= 65474 && c <= 65479)
                    : c <= 65487)
                  : (c <= 65495 || (c >= 65498 && c <= 65500)))
                : (c <= 65547 || (c < 65596
                  ? (c < 65576
                    ? (c >= 65549 && c <= 65574)
                    : c <= 65594)
                  : (c <= 65597 || (c >= 65599 && c <= 65613)))))))
            : (c <= 65629 || (c < 66504
              ? (c < 66304
                ? (c < 66176
                  ? (c < 65856
                    ? (c >= 65664 && c <= 65786)
                    : c <= 65908)
                  : (c <= 66204 || (c >= 66208 && c <= 66256)))
                : (c <= 66335 || (c < 66432
                  ? (c < 66384
                    ? (c >= 66349 && c <= 66378)
                    : c <= 66421)
                  : (c <= 66461 || (c >= 66464 && c <= 66499)))))
              : (c <= 66511 || (c < 66816
                ? (c < 66736
                  ? (c < 66560
                    ? (c >= 66513 && c <= 66517)
                    : c <= 66717)
                  : (c <= 66771 || (c >= 66776 && c <= 66811)))
                : (c <= 66855 || (c < 66940
                  ? (c < 66928
                    ? (c >= 66864 && c <= 66915)
                    : c <= 66938)
                  : (c <= 66954 || (c >= 66956 && c <= 66962)))))))))))
        : (c <= 66965 || (c < 69248
          ? (c < 67840
            ? (c < 67584
              ? (c < 67392
                ? (c < 66995
                  ? (c < 66979
                    ? (c >= 66967 && c <= 66977)
                    : c <= 66993)
                  : (c <= 67001 || (c < 67072
                    ? (c >= 67003 && c <= 67004)
                    : c <= 67382)))
                : (c <= 67413 || (c < 67463
                  ? (c < 67456
                    ? (c >= 67424 && c <= 67431)
                    : c <= 67461)
                  : (c <= 67504 || (c >= 67506 && c <= 67514)))))
              : (c <= 67589 || (c < 67647
                ? (c < 67639
                  ? (c < 67594
                    ? c == 67592
                    : c <= 67637)
                  : (c <= 67640 || c == 67644))
                : (c <= 67669 || (c < 67808
                  ? (c < 67712
                    ? (c >= 67680 && c <= 67702)
                    : c <= 67742)
                  : (c <= 67826 || (c >= 67828 && c <= 67829)))))))
            : (c <= 67861 || (c < 68288
              ? (c < 68112
                ? (c < 68030
                  ? (c < 67968
                    ? (c >= 67872 && c <= 67897)
                    : c <= 68023)
                  : (c <= 68031 || c == 68096))
                : (c <= 68115 || (c < 68192
                  ? (c < 68121
                    ? (c >= 68117 && c <= 68119)
                    : c <= 68149)
                  : (c <= 68220 || (c >= 68224 && c <= 68252)))))
              : (c <= 68295 || (c < 68480
                ? (c < 68416
                  ? (c < 68352
                    ? (c >= 68297 && c <= 68324)
                    : c <= 68405)
                  : (c <= 68437 || (c >= 68448 && c <= 68466)))
                : (c <= 68497 || (c < 68800
                  ? (c < 68736
                    ? (c >= 68608 && c <= 68680)
                    : c <= 68786)
                  : (c <= 68850 || (c >= 68864 && c <= 68899)))))))))
          : (c <= 69289 || (c < 70108
            ? (c < 69763
              ? (c < 69552
                ? (c < 69415
                  ? (c < 69376
                    ? (c >= 69296 && c <= 69297)
                    : c <= 69404)
                  : (c <= 69415 || (c < 69488
                    ? (c >= 69424 && c <= 69445)
                    : c <= 69505)))
                : (c <= 69572 || (c < 69745
                  ? (c < 69635
                    ? (c >= 69600 && c <= 69622)
                    : c <= 69687)
                  : (c <= 69746 || c == 69749))))
              : (c <= 69807 || (c < 69968
                ? (c < 69956
                  ? (c < 69891
                    ? (c >= 69840 && c <= 69864)
                    : c <= 69926)
                  : (c <= 69956 || c == 69959))
                : (c <= 70002 || (c < 70081
                  ? (c < 70019
                    ? c == 70006
                    : c <= 70066)
                  : (c <= 70084 || c == 70106))))))
            : (c <= 70108 || (c < 70415
              ? (c < 70282
                ? (c < 70272
                  ? (c < 70163
                    ? (c >= 70144 && c <= 70161)
                    : c <= 70187)
                  : (c <= 70278 || c == 70280))
                : (c <= 70285 || (c < 70320
                  ? (c < 70303
                    ? (c >= 70287 && c <= 70301)
                    : c <= 70312)
                  : (c <= 70366 || (c >= 70405 && c <= 70412)))))
              : (c <= 70416 || (c < 70461
                ? (c < 70450
                  ? (c < 70442
                    ? (c >= 70419 && c <= 70440)
                    : c <= 70448)
                  : (c <= 70451 || (c >= 70453 && c <= 70457)))
                : (c <= 70461 || (c < 70656
                  ? (c < 70493
                    ? c == 70480
                    : c <= 70497)
                  : (c <= 70708 || (c >= 70727 && c <= 70730)))))))))))))
      : (c <= 70753 || (c < 119966
        ? (c < 73063
          ? (c < 72096
            ? (c < 71488
              ? (c < 71168
                ? (c < 70855
                  ? (c < 70852
                    ? (c >= 70784 && c <= 70831)
                    : c <= 70853)
                  : (c <= 70855 || (c < 71128
                    ? (c >= 71040 && c <= 71086)
                    : c <= 71131)))
                : (c <= 71215 || (c < 71352
                  ? (c < 71296
                    ? c == 71236
                    : c <= 71338)
                  : (c <= 71352 || (c >= 71424 && c <= 71450)))))
              : (c <= 71494 || (c < 71948
                ? (c < 71935
                  ? (c < 71840
                    ? (c >= 71680 && c <= 71723)
                    : c <= 71903)
                  : (c <= 71942 || c == 71945))
                : (c <= 71955 || (c < 71999
                  ? (c < 71960
                    ? (c >= 71957 && c <= 71958)
                    : c <= 71983)
                  : (c <= 71999 || c == 72001))))))
            : (c <= 72103 || (c < 72368
              ? (c < 72203
                ? (c < 72163
                  ? (c < 72161
                    ? (c >= 72106 && c <= 72144)
                    : c <= 72161)
                  : (c <= 72163 || c == 72192))
                : (c <= 72242 || (c < 72284
                  ? (c < 72272
                    ? c == 72250
                    : c <= 72272)
                  : (c <= 72329 || c == 72349))))
              : (c <= 72440 || (c < 72960
                ? (c < 72768
                  ? (c < 72714
                    ? (c >= 72704 && c <= 72712)
                    : c <= 72750)
                  : (c <= 72768 || (c >= 72818 && c <= 72847)))
                : (c <= 72966 || (c < 73030
                  ? (c < 72971
                    ? (c >= 72968 && c <= 72969)
                    : c <= 73008)
                  : (c <= 73030 || (c >= 73056 && c <= 73061)))))))))
          : (c <= 73064 || (c < 94032
            ? (c < 92160
              ? (c < 74752
                ? (c < 73440
                  ? (c < 73112
                    ? (c >= 73066 && c <= 73097)
                    : c <= 73112)
                  : (c <= 73458 || (c < 73728
                    ? c == 73648
                    : c <= 74649)))
                : (c <= 74862 || (c < 77824
                  ? (c < 77712
                    ? (c >= 74880 && c <= 75075)
                    : c <= 77808)
                  : (c <= 78894 || (c >= 82944 && c <= 83526)))))
              : (c <= 92728 || (c < 92992
                ? (c < 92880
                  ? (c < 92784
                    ? (c >= 92736 && c <= 92766)
                    : c <= 92862)
                  : (c <= 92909 || (c >= 92928 && c <= 92975)))
                : (c <= 92995 || (c < 93760
                  ? (c < 93053
                    ? (c >= 93027 && c <= 93047)
                    : c <= 93071)
                  : (c <= 93823 || (c >= 93952 && c <= 94026)))))))
            : (c <= 94032 || (c < 110592
              ? (c < 100352
                ? (c < 94179
                  ? (c < 94176
                    ? (c >= 94099 && c <= 94111)
                    : c <= 94177)
                  : (c <= 94179 || (c >= 94208 && c <= 100343)))
                : (c <= 101589 || (c < 110581
                  ? (c < 110576
                    ? (c >= 101632 && c <= 101640)
                    : c <= 110579)
                  : (c <= 110587 || (c >= 110589 && c <= 110590)))))
              : (c <= 110882 || (c < 113776
                ? (c < 110960
                  ? (c < 110948
                    ? (c >= 110928 && c <= 110930)
                    : c <= 110951)
                  : (c <= 111355 || (c >= 113664 && c <= 113770)))
                : (c <= 113788 || (c < 119808
                  ? (c < 113808
                    ? (c >= 113792 && c <= 113800)
                    : c <= 113817)
                  : (c <= 119892 || (c >= 119894 && c <= 119964)))))))))))
        : (c <= 119967 || (c < 126464
          ? (c < 120598
            ? (c < 120094
              ? (c < 119997
                ? (c < 119977
                  ? (c < 119973
                    ? c == 119970
                    : c <= 119974)
                  : (c <= 119980 || (c < 119995
                    ? (c >= 119982 && c <= 119993)
                    : c <= 119995)))
                : (c <= 120003 || (c < 120077
                  ? (c < 120071
                    ? (c >= 120005 && c <= 120069)
                    : c <= 120074)
                  : (c <= 120084 || (c >= 120086 && c <= 120092)))))
              : (c <= 120121 || (c < 120146
                ? (c < 120134
                  ? (c < 120128
                    ? (c >= 120123 && c <= 120126)
                    : c <= 120132)
                  : (c <= 120134 || (c >= 120138 && c <= 120144)))
                : (c <= 120485 || (c < 120540
                  ? (c < 120514
                    ? (c >= 120488 && c <= 120512)
                    : c <= 120538)
                  : (c <= 120570 || (c >= 120572 && c <= 120596)))))))
            : (c <= 120628 || (c < 123214
              ? (c < 120746
                ? (c < 120688
                  ? (c < 120656
                    ? (c >= 120630 && c <= 120654)
                    : c <= 120686)
                  : (c <= 120712 || (c >= 120714 && c <= 120744)))
                : (c <= 120770 || (c < 123136
                  ? (c < 122624
                    ? (c >= 120772 && c <= 120779)
                    : c <= 122654)
                  : (c <= 123180 || (c >= 123191 && c <= 123197)))))
              : (c <= 123214 || (c < 124909
                ? (c < 124896
                  ? (c < 123584
                    ? (c >= 123536 && c <= 123565)
                    : c <= 123627)
                  : (c <= 124902 || (c >= 124904 && c <= 124907)))
                : (c <= 124910 || (c < 125184
                  ? (c < 124928
                    ? (c >= 124912 && c <= 124926)
                    : c <= 125124)
                  : (c <= 125251 || c == 125259))))))))
          : (c <= 126467 || (c < 126559
            ? (c < 126535
              ? (c < 126505
                ? (c < 126500
                  ? (c < 126497
                    ? (c >= 126469 && c <= 126495)
                    : c <= 126498)
                  : (c <= 126500 || c == 126503))
                : (c <= 126514 || (c < 126523
                  ? (c < 126521
                    ? (c >= 126516 && c <= 126519)
                    : c <= 126521)
                  : (c <= 126523 || c == 126530))))
              : (c <= 126535 || (c < 126548
                ? (c < 126541
                  ? (c < 126539
                    ? c == 126537
                    : c <= 126539)
                  : (c <= 126543 || (c >= 126545 && c <= 126546)))
                : (c <= 126548 || (c < 126555
                  ? (c < 126553
                    ? c == 126551
                    : c <= 126553)
                  : (c <= 126555 || c == 126557))))))
            : (c <= 126559 || (c < 126625
              ? (c < 126580
                ? (c < 126567
                  ? (c < 126564
                    ? (c >= 126561 && c <= 126562)
                    : c <= 126564)
                  : (c <= 126570 || (c >= 126572 && c <= 126578)))
                : (c <= 126583 || (c < 126592
                  ? (c < 126590
                    ? (c >= 126585 && c <= 126588)
                    : c <= 126590)
                  : (c <= 126601 || (c >= 126603 && c <= 126619)))))
              : (c <= 126627 || (c < 177984
                ? (c < 131072
                  ? (c < 126635
                    ? (c >= 126629 && c <= 126633)
                    : c <= 126651)
                  : (c <= 173791 || (c >= 173824 && c <= 177976)))
                : (c <= 178205 || (c < 194560
                  ? (c < 183984
                    ? (c >= 178208 && c <= 183969)
                    : c <= 191456)
                  : (c <= 195101 || (c >= 196608 && c <= 201546)))))))))))))))));
}

static inline bool sym_lowercase_identifier_character_set_4(int32_t c) {
  return (c < 43646
    ? (c < 4213
      ? (c < 2738
        ? (c < 2036
          ? (c < 931
            ? (c < 748
              ? (c < 192
                ? (c < 170
                  ? (c < 'a'
                    ? c == '_'
                    : c <= 'z')
                  : (c <= 170 || (c < 186
                    ? c == 181
                    : c <= 186)))
                : (c <= 214 || (c < 710
                  ? (c < 248
                    ? (c >= 216 && c <= 246)
                    : c <= 705)
                  : (c <= 721 || (c >= 736 && c <= 740)))))
              : (c <= 748 || (c < 895
                ? (c < 886
                  ? (c < 880
                    ? c == 750
                    : c <= 884)
                  : (c <= 887 || (c >= 891 && c <= 893)))
                : (c <= 895 || (c < 908
                  ? (c < 904
                    ? c == 902
                    : c <= 906)
                  : (c <= 908 || (c >= 910 && c <= 929)))))))
            : (c <= 1013 || (c < 1749
              ? (c < 1488
                ? (c < 1329
                  ? (c < 1162
                    ? (c >= 1015 && c <= 1153)
                    : c <= 1327)
                  : (c <= 1366 || (c < 1376
                    ? c == 1369
                    : c <= 1416)))
                : (c <= 1514 || (c < 1646
                  ? (c < 1568
                    ? (c >= 1519 && c <= 1522)
                    : c <= 1610)
                  : (c <= 1647 || (c >= 1649 && c <= 1747)))))
              : (c <= 1749 || (c < 1808
                ? (c < 1786
                  ? (c < 1774
                    ? (c >= 1765 && c <= 1766)
                    : c <= 1775)
                  : (c <= 1788 || c == 1791))
                : (c <= 1808 || (c < 1969
                  ? (c < 1869
                    ? (c >= 1810 && c <= 1839)
                    : c <= 1957)
                  : (c <= 1969 || (c >= 1994 && c <= 2026)))))))))
          : (c <= 2037 || (c < 2486
            ? (c < 2308
              ? (c < 2112
                ? (c < 2074
                  ? (c < 2048
                    ? c == 2042
                    : c <= 2069)
                  : (c <= 2074 || (c < 2088
                    ? c == 2084
                    : c <= 2088)))
                : (c <= 2136 || (c < 2185
                  ? (c < 2160
                    ? (c >= 2144 && c <= 2154)
                    : c <= 2183)
                  : (c <= 2190 || (c >= 2208 && c <= 2249)))))
              : (c <= 2361 || (c < 2437
                ? (c < 2392
                  ? (c < 2384
                    ? c == 2365
                    : c <= 2384)
                  : (c <= 2401 || (c >= 2417 && c <= 2432)))
                : (c <= 2444 || (c < 2474
                  ? (c < 2451
                    ? (c >= 2447 && c <= 2448)
                    : c <= 2472)
                  : (c <= 2480 || c == 2482))))))
            : (c <= 2489 || (c < 2610
              ? (c < 2556
                ? (c < 2524
                  ? (c < 2510
                    ? c == 2493
                    : c <= 2510)
                  : (c <= 2525 || (c < 2544
                    ? (c >= 2527 && c <= 2529)
                    : c <= 2545)))
                : (c <= 2556 || (c < 2579
                  ? (c < 2575
                    ? (c >= 2565 && c <= 2570)
                    : c <= 2576)
                  : (c <= 2600 || (c >= 2602 && c <= 2608)))))
              : (c <= 2611 || (c < 2674
                ? (c < 2649
                  ? (c < 2616
                    ? (c >= 2613 && c <= 2614)
                    : c <= 2617)
                  : (c <= 2652 || c == 2654))
                : (c <= 2676 || (c < 2707
                  ? (c < 2703
                    ? (c >= 2693 && c <= 2701)
                    : c <= 2705)
                  : (c <= 2728 || (c >= 2730 && c <= 2736)))))))))))
        : (c <= 2739 || (c < 3293
          ? (c < 2972
            ? (c < 2869
              ? (c < 2821
                ? (c < 2768
                  ? (c < 2749
                    ? (c >= 2741 && c <= 2745)
                    : c <= 2749)
                  : (c <= 2768 || (c < 2809
                    ? (c >= 2784 && c <= 2785)
                    : c <= 2809)))
                : (c <= 2828 || (c < 2858
                  ? (c < 2835
                    ? (c >= 2831 && c <= 2832)
                    : c <= 2856)
                  : (c <= 2864 || (c >= 2866 && c <= 2867)))))
              : (c <= 2873 || (c < 2947
                ? (c < 2911
                  ? (c < 2908
                    ? c == 2877
                    : c <= 2909)
                  : (c <= 2913 || c == 2929))
                : (c <= 2947 || (c < 2962
                  ? (c < 2958
                    ? (c >= 2949 && c <= 2954)
                    : c <= 2960)
                  : (c <= 2965 || (c >= 2969 && c <= 2970)))))))
            : (c <= 2972 || (c < 3160
              ? (c < 3077
                ? (c < 2984
                  ? (c < 2979
                    ? (c >= 2974 && c <= 2975)
                    : c <= 2980)
                  : (c <= 2986 || (c < 3024
                    ? (c >= 2990 && c <= 3001)
                    : c <= 3024)))
                : (c <= 3084 || (c < 3114
                  ? (c < 3090
                    ? (c >= 3086 && c <= 3088)
                    : c <= 3112)
                  : (c <= 3129 || c == 3133))))
              : (c <= 3162 || (c < 3214
                ? (c < 3200
                  ? (c < 3168
                    ? c == 3165
                    : c <= 3169)
                  : (c <= 3200 || (c >= 3205 && c <= 3212)))
                : (c <= 3216 || (c < 3253
                  ? (c < 3242
                    ? (c >= 3218 && c <= 3240)
                    : c <= 3251)
                  : (c <= 3257 || c == 3261))))))))
          : (c <= 3294 || (c < 3718
            ? (c < 3461
              ? (c < 3389
                ? (c < 3332
                  ? (c < 3313
                    ? (c >= 3296 && c <= 3297)
                    : c <= 3314)
                  : (c <= 3340 || (c < 3346
                    ? (c >= 3342 && c <= 3344)
                    : c <= 3386)))
                : (c <= 3389 || (c < 3423
                  ? (c < 3412
                    ? c == 3406
                    : c <= 3414)
                  : (c <= 3425 || (c >= 3450 && c <= 3455)))))
              : (c <= 3478 || (c < 3585
                ? (c < 3517
                  ? (c < 3507
                    ? (c >= 3482 && c <= 3505)
                    : c <= 3515)
                  : (c <= 3517 || (c >= 3520 && c <= 3526)))
                : (c <= 3632 || (c < 3713
                  ? (c < 3648
                    ? c == 3634
                    : c <= 3654)
                  : (c <= 3714 || c == 3716))))))
            : (c <= 3722 || (c < 3904
              ? (c < 3773
                ? (c < 3751
                  ? (c < 3749
                    ? (c >= 3724 && c <= 3747)
                    : c <= 3749)
                  : (c <= 3760 || c == 3762))
                : (c <= 3773 || (c < 3804
                  ? (c < 3782
                    ? (c >= 3776 && c <= 3780)
                    : c <= 3782)
                  : (c <= 3807 || c == 3840))))
              : (c <= 3911 || (c < 4176
                ? (c < 4096
                  ? (c < 3976
                    ? (c >= 3913 && c <= 3948)
                    : c <= 3980)
                  : (c <= 4138 || c == 4159))
                : (c <= 4181 || (c < 4197
                  ? (c < 4193
                    ? (c >= 4186 && c <= 4189)
                    : c <= 4193)
                  : (c <= 4198 || (c >= 4206 && c <= 4208)))))))))))))
      : (c <= 4225 || (c < 8182
        ? (c < 6400
          ? (c < 4888
            ? (c < 4704
              ? (c < 4348
                ? (c < 4295
                  ? (c < 4256
                    ? c == 4238
                    : c <= 4293)
                  : (c <= 4295 || (c < 4304
                    ? c == 4301
                    : c <= 4346)))
                : (c <= 4680 || (c < 4696
                  ? (c < 4688
                    ? (c >= 4682 && c <= 4685)
                    : c <= 4694)
                  : (c <= 4696 || (c >= 4698 && c <= 4701)))))
              : (c <= 4744 || (c < 4800
                ? (c < 4786
                  ? (c < 4752
                    ? (c >= 4746 && c <= 4749)
                    : c <= 4784)
                  : (c <= 4789 || (c >= 4792 && c <= 4798)))
                : (c <= 4800 || (c < 4824
                  ? (c < 4808
                    ? (c >= 4802 && c <= 4805)
                    : c <= 4822)
                  : (c <= 4880 || (c >= 4882 && c <= 4885)))))))
            : (c <= 4954 || (c < 5952
              ? (c < 5761
                ? (c < 5112
                  ? (c < 5024
                    ? (c >= 4992 && c <= 5007)
                    : c <= 5109)
                  : (c <= 5117 || (c < 5743
                    ? (c >= 5121 && c <= 5740)
                    : c <= 5759)))
                : (c <= 5786 || (c < 5888
                  ? (c < 5870
                    ? (c >= 5792 && c <= 5866)
                    : c <= 5880)
                  : (c <= 5905 || (c >= 5919 && c <= 5937)))))
              : (c <= 5969 || (c < 6108
                ? (c < 6016
                  ? (c < 5998
                    ? (c >= 5984 && c <= 5996)
                    : c <= 6000)
                  : (c <= 6067 || c == 6103))
                : (c <= 6108 || (c < 6314
                  ? (c < 6272
                    ? (c >= 6176 && c <= 6264)
                    : c <= 6312)
                  : (c <= 6314 || (c >= 6320 && c <= 6389)))))))))
          : (c <= 6430 || (c < 7413
            ? (c < 7086
              ? (c < 6688
                ? (c < 6528
                  ? (c < 6512
                    ? (c >= 6480 && c <= 6509)
                    : c <= 6516)
                  : (c <= 6571 || (c < 6656
                    ? (c >= 6576 && c <= 6601)
                    : c <= 6678)))
                : (c <= 6740 || (c < 6981
                  ? (c < 6917
                    ? c == 6823
                    : c <= 6963)
                  : (c <= 6988 || (c >= 7043 && c <= 7072)))))
              : (c <= 7087 || (c < 7296
                ? (c < 7245
                  ? (c < 7168
                    ? (c >= 7098 && c <= 7141)
                    : c <= 7203)
                  : (c <= 7247 || (c >= 7258 && c <= 7293)))
                : (c <= 7304 || (c < 7401
                  ? (c < 7357
                    ? (c >= 7312 && c <= 7354)
                    : c <= 7359)
                  : (c <= 7404 || (c >= 7406 && c <= 7411)))))))
            : (c <= 7414 || (c < 8031
              ? (c < 8008
                ? (c < 7680
                  ? (c < 7424
                    ? c == 7418
                    : c <= 7615)
                  : (c <= 7957 || (c < 7968
                    ? (c >= 7960 && c <= 7965)
                    : c <= 8005)))
                : (c <= 8013 || (c < 8027
                  ? (c < 8025
                    ? (c >= 8016 && c <= 8023)
                    : c <= 8025)
                  : (c <= 8027 || c == 8029))))
              : (c <= 8061 || (c < 8134
                ? (c < 8126
                  ? (c < 8118
                    ? (c >= 8064 && c <= 8116)
                    : c <= 8124)
                  : (c <= 8126 || (c >= 8130 && c <= 8132)))
                : (c <= 8140 || (c < 8160
                  ? (c < 8150
                    ? (c >= 8144 && c <= 8147)
                    : c <= 8155)
                  : (c <= 8172 || (c >= 8178 && c <= 8180)))))))))))
        : (c <= 8188 || (c < 12549
          ? (c < 11559
            ? (c < 8488
              ? (c < 8458
                ? (c < 8336
                  ? (c < 8319
                    ? c == 8305
                    : c <= 8319)
                  : (c <= 8348 || (c < 8455
                    ? c == 8450
                    : c <= 8455)))
                : (c <= 8467 || (c < 8484
                  ? (c < 8472
                    ? c == 8469
                    : c <= 8477)
                  : (c <= 8484 || c == 8486))))
              : (c <= 8488 || (c < 8544
                ? (c < 8517
                  ? (c < 8508
                    ? (c >= 8490 && c <= 8505)
                    : c <= 8511)
                  : (c <= 8521 || c == 8526))
                : (c <= 8584 || (c < 11506
                  ? (c < 11499
                    ? (c >= 11264 && c <= 11492)
                    : c <= 11502)
                  : (c <= 11507 || (c >= 11520 && c <= 11557)))))))
            : (c <= 11559 || (c < 11728
              ? (c < 11688
                ? (c < 11631
                  ? (c < 11568
                    ? c == 11565
                    : c <= 11623)
                  : (c <= 11631 || (c < 11680
                    ? (c >= 11648 && c <= 11670)
                    : c <= 11686)))
                : (c <= 11694 || (c < 11712
                  ? (c < 11704
                    ? (c >= 11696 && c <= 11702)
                    : c <= 11710)
                  : (c <= 11718 || (c >= 11720 && c <= 11726)))))
              : (c <= 11734 || (c < 12344
                ? (c < 12321
                  ? (c < 12293
                    ? (c >= 11736 && c <= 11742)
                    : c <= 12295)
                  : (c <= 12329 || (c >= 12337 && c <= 12341)))
                : (c <= 12348 || (c < 12449
                  ? (c < 12445
                    ? (c >= 12353 && c <= 12438)
                    : c <= 12447)
                  : (c <= 12538 || (c >= 12540 && c <= 12543)))))))))
          : (c <= 12591 || (c < 43015
            ? (c < 42623
              ? (c < 42192
                ? (c < 12784
                  ? (c < 12704
                    ? (c >= 12593 && c <= 12686)
                    : c <= 12735)
                  : (c <= 12799 || (c < 19968
                    ? (c >= 13312 && c <= 19903)
                    : c <= 42124)))
                : (c <= 42237 || (c < 42538
                  ? (c < 42512
                    ? (c >= 42240 && c <= 42508)
                    : c <= 42527)
                  : (c <= 42539 || (c >= 42560 && c <= 42606)))))
              : (c <= 42653 || (c < 42960
                ? (c < 42786
                  ? (c < 42775
                    ? (c >= 42656 && c <= 42735)
                    : c <= 42783)
                  : (c <= 42888 || (c >= 42891 && c <= 42954)))
                : (c <= 42961 || (c < 42994
                  ? (c < 42965
                    ? c == 42963
                    : c <= 42969)
                  : (c <= 43009 || (c >= 43011 && c <= 43013)))))))
            : (c <= 43018 || (c < 43396
              ? (c < 43259
                ? (c < 43138
                  ? (c < 43072
                    ? (c >= 43020 && c <= 43042)
                    : c <= 43123)
                  : (c <= 43187 || (c >= 43250 && c <= 43255)))
                : (c <= 43259 || (c < 43312
                  ? (c < 43274
                    ? (c >= 43261 && c <= 43262)
                    : c <= 43301)
                  : (c <= 43334 || (c >= 43360 && c <= 43388)))))
              : (c <= 43442 || (c < 43520
                ? (c < 43494
                  ? (c < 43488
                    ? c == 43471
                    : c <= 43492)
                  : (c <= 43503 || (c >= 43514 && c <= 43518)))
                : (c <= 43560 || (c < 43616
                  ? (c < 43588
                    ? (c >= 43584 && c <= 43586)
                    : c <= 43595)
                  : (c <= 43638 || c == 43642))))))))))))))
    : (c <= 43695 || (c < 71236
      ? (c < 67424
        ? (c < 65149
          ? (c < 64112
            ? (c < 43793
              ? (c < 43739
                ? (c < 43705
                  ? (c < 43701
                    ? c == 43697
                    : c <= 43702)
                  : (c <= 43709 || (c < 43714
                    ? c == 43712
                    : c <= 43714)))
                : (c <= 43741 || (c < 43777
                  ? (c < 43762
                    ? (c >= 43744 && c <= 43754)
                    : c <= 43764)
                  : (c <= 43782 || (c >= 43785 && c <= 43790)))))
              : (c <= 43798 || (c < 43888
                ? (c < 43824
                  ? (c < 43816
                    ? (c >= 43808 && c <= 43814)
                    : c <= 43822)
                  : (c <= 43866 || (c >= 43868 && c <= 43881)))
                : (c <= 44002 || (c < 55243
                  ? (c < 55216
                    ? (c >= 44032 && c <= 55203)
                    : c <= 55238)
                  : (c <= 55291 || (c >= 63744 && c <= 64109)))))))
            : (c <= 64217 || (c < 64467
              ? (c < 64312
                ? (c < 64285
                  ? (c < 64275
                    ? (c >= 64256 && c <= 64262)
                    : c <= 64279)
                  : (c <= 64285 || (c < 64298
                    ? (c >= 64287 && c <= 64296)
                    : c <= 64310)))
                : (c <= 64316 || (c < 64323
                  ? (c < 64320
                    ? c == 64318
                    : c <= 64321)
                  : (c <= 64324 || (c >= 64326 && c <= 64433)))))
              : (c <= 64605 || (c < 65137
                ? (c < 64914
                  ? (c < 64848
                    ? (c >= 64612 && c <= 64829)
                    : c <= 64911)
                  : (c <= 64967 || (c >= 65008 && c <= 65017)))
                : (c <= 65137 || (c < 65145
                  ? (c < 65143
                    ? c == 65139
                    : c <= 65143)
                  : (c <= 65145 || c == 65147))))))))
          : (c <= 65149 || (c < 66349
            ? (c < 65549
              ? (c < 65474
                ? (c < 65345
                  ? (c < 65313
                    ? (c >= 65151 && c <= 65276)
                    : c <= 65338)
                  : (c <= 65370 || (c < 65440
                    ? (c >= 65382 && c <= 65437)
                    : c <= 65470)))
                : (c <= 65479 || (c < 65498
                  ? (c < 65490
                    ? (c >= 65482 && c <= 65487)
                    : c <= 65495)
                  : (c <= 65500 || (c >= 65536 && c <= 65547)))))
              : (c <= 65574 || (c < 65664
                ? (c < 65599
                  ? (c < 65596
                    ? (c >= 65576 && c <= 65594)
                    : c <= 65597)
                  : (c <= 65613 || (c >= 65616 && c <= 65629)))
                : (c <= 65786 || (c < 66208
                  ? (c < 66176
                    ? (c >= 65856 && c <= 65908)
                    : c <= 66204)
                  : (c <= 66256 || (c >= 66304 && c <= 66335)))))))
            : (c <= 66378 || (c < 66928
              ? (c < 66560
                ? (c < 66464
                  ? (c < 66432
                    ? (c >= 66384 && c <= 66421)
                    : c <= 66461)
                  : (c <= 66499 || (c < 66513
                    ? (c >= 66504 && c <= 66511)
                    : c <= 66517)))
                : (c <= 66717 || (c < 66816
                  ? (c < 66776
                    ? (c >= 66736 && c <= 66771)
                    : c <= 66811)
                  : (c <= 66855 || (c >= 66864 && c <= 66915)))))
              : (c <= 66938 || (c < 66979
                ? (c < 66964
                  ? (c < 66956
                    ? (c >= 66940 && c <= 66954)
                    : c <= 66962)
                  : (c <= 66965 || (c >= 66967 && c <= 66977)))
                : (c <= 66993 || (c < 67072
                  ? (c < 67003
                    ? (c >= 66995 && c <= 67001)
                    : c <= 67004)
                  : (c <= 67382 || (c >= 67392 && c <= 67413)))))))))))
        : (c <= 67431 || (c < 69635
          ? (c < 68121
            ? (c < 67712
              ? (c < 67594
                ? (c < 67506
                  ? (c < 67463
                    ? (c >= 67456 && c <= 67461)
                    : c <= 67504)
                  : (c <= 67514 || (c < 67592
                    ? (c >= 67584 && c <= 67589)
                    : c <= 67592)))
                : (c <= 67637 || (c < 67647
                  ? (c < 67644
                    ? (c >= 67639 && c <= 67640)
                    : c <= 67644)
                  : (c <= 67669 || (c >= 67680 && c <= 67702)))))
              : (c <= 67742 || (c < 67968
                ? (c < 67840
                  ? (c < 67828
                    ? (c >= 67808 && c <= 67826)
                    : c <= 67829)
                  : (c <= 67861 || (c >= 67872 && c <= 67897)))
                : (c <= 68023 || (c < 68112
                  ? (c < 68096
                    ? (c >= 68030 && c <= 68031)
                    : c <= 68096)
                  : (c <= 68115 || (c >= 68117 && c <= 68119)))))))
            : (c <= 68149 || (c < 68800
              ? (c < 68416
                ? (c < 68288
                  ? (c < 68224
                    ? (c >= 68192 && c <= 68220)
                    : c <= 68252)
                  : (c <= 68295 || (c < 68352
                    ? (c >= 68297 && c <= 68324)
                    : c <= 68405)))
                : (c <= 68437 || (c < 68608
                  ? (c < 68480
                    ? (c >= 68448 && c <= 68466)
                    : c <= 68497)
                  : (c <= 68680 || (c >= 68736 && c <= 68786)))))
              : (c <= 68850 || (c < 69415
                ? (c < 69296
                  ? (c < 69248
                    ? (c >= 68864 && c <= 68899)
                    : c <= 69289)
                  : (c <= 69297 || (c >= 69376 && c <= 69404)))
                : (c <= 69415 || (c < 69552
                  ? (c < 69488
                    ? (c >= 69424 && c <= 69445)
                    : c <= 69505)
                  : (c <= 69572 || (c >= 69600 && c <= 69622)))))))))
          : (c <= 69687 || (c < 70303
            ? (c < 70081
              ? (c < 69956
                ? (c < 69763
                  ? (c < 69749
                    ? (c >= 69745 && c <= 69746)
                    : c <= 69749)
                  : (c <= 69807 || (c < 69891
                    ? (c >= 69840 && c <= 69864)
                    : c <= 69926)))
                : (c <= 69956 || (c < 70006
                  ? (c < 69968
                    ? c == 69959
                    : c <= 70002)
                  : (c <= 70006 || (c >= 70019 && c <= 70066)))))
              : (c <= 70084 || (c < 70207
                ? (c < 70144
                  ? (c < 70108
                    ? c == 70106
                    : c <= 70108)
                  : (c <= 70161 || (c >= 70163 && c <= 70187)))
                : (c <= 70208 || (c < 70282
                  ? (c < 70280
                    ? (c >= 70272 && c <= 70278)
                    : c <= 70280)
                  : (c <= 70285 || (c >= 70287 && c <= 70301)))))))
            : (c <= 70312 || (c < 70493
              ? (c < 70442
                ? (c < 70415
                  ? (c < 70405
                    ? (c >= 70320 && c <= 70366)
                    : c <= 70412)
                  : (c <= 70416 || (c >= 70419 && c <= 70440)))
                : (c <= 70448 || (c < 70461
                  ? (c < 70453
                    ? (c >= 70450 && c <= 70451)
                    : c <= 70457)
                  : (c <= 70461 || c == 70480))))
              : (c <= 70497 || (c < 70852
                ? (c < 70751
                  ? (c < 70727
                    ? (c >= 70656 && c <= 70708)
                    : c <= 70730)
                  : (c <= 70753 || (c >= 70784 && c <= 70831)))
                : (c <= 70853 || (c < 71128
                  ? (c < 71040
                    ? c == 70855
                    : c <= 71086)
                  : (c <= 71131 || (c >= 71168 && c <= 71215)))))))))))))
      : (c <= 71236 || (c < 119973
        ? (c < 73728
          ? (c < 72272
            ? (c < 71960
              ? (c < 71840
                ? (c < 71424
                  ? (c < 71352
                    ? (c >= 71296 && c <= 71338)
                    : c <= 71352)
                  : (c <= 71450 || (c < 71680
                    ? (c >= 71488 && c <= 71494)
                    : c <= 71723)))
                : (c <= 71903 || (c < 71948
                  ? (c < 71945
                    ? (c >= 71935 && c <= 71942)
                    : c <= 71945)
                  : (c <= 71955 || (c >= 71957 && c <= 71958)))))
              : (c <= 71983 || (c < 72161
                ? (c < 72096
                  ? (c < 72001
                    ? c == 71999
                    : c <= 72001)
                  : (c <= 72103 || (c >= 72106 && c <= 72144)))
                : (c <= 72161 || (c < 72203
                  ? (c < 72192
                    ? c == 72163
                    : c <= 72192)
                  : (c <= 72242 || c == 72250))))))
            : (c <= 72272 || (c < 73030
              ? (c < 72768
                ? (c < 72368
                  ? (c < 72349
                    ? (c >= 72284 && c <= 72329)
                    : c <= 72349)
                  : (c <= 72440 || (c < 72714
                    ? (c >= 72704 && c <= 72712)
                    : c <= 72750)))
                : (c <= 72768 || (c < 72968
                  ? (c < 72960
                    ? (c >= 72818 && c <= 72847)
                    : c <= 72966)
                  : (c <= 72969 || (c >= 72971 && c <= 73008)))))
              : (c <= 73030 || (c < 73440
                ? (c < 73066
                  ? (c < 73063
                    ? (c >= 73056 && c <= 73061)
                    : c <= 73064)
                  : (c <= 73097 || c == 73112))
                : (c <= 73458 || (c < 73490
                  ? (c < 73476
                    ? c == 73474
                    : c <= 73488)
                  : (c <= 73523 || c == 73648))))))))
          : (c <= 74649 || (c < 94208
            ? (c < 92928
              ? (c < 82944
                ? (c < 77712
                  ? (c < 74880
                    ? (c >= 74752 && c <= 74862)
                    : c <= 75075)
                  : (c <= 77808 || (c < 78913
                    ? (c >= 77824 && c <= 78895)
                    : c <= 78918)))
                : (c <= 83526 || (c < 92784
                  ? (c < 92736
                    ? (c >= 92160 && c <= 92728)
                    : c <= 92766)
                  : (c <= 92862 || (c >= 92880 && c <= 92909)))))
              : (c <= 92975 || (c < 93952
                ? (c < 93053
                  ? (c < 93027
                    ? (c >= 92992 && c <= 92995)
                    : c <= 93047)
                  : (c <= 93071 || (c >= 93760 && c <= 93823)))
                : (c <= 94026 || (c < 94176
                  ? (c < 94099
                    ? c == 94032
                    : c <= 94111)
                  : (c <= 94177 || c == 94179))))))
            : (c <= 100343 || (c < 110948
              ? (c < 110589
                ? (c < 110576
                  ? (c < 101632
                    ? (c >= 100352 && c <= 101589)
                    : c <= 101640)
                  : (c <= 110579 || (c >= 110581 && c <= 110587)))
                : (c <= 110590 || (c < 110928
                  ? (c < 110898
                    ? (c >= 110592 && c <= 110882)
                    : c <= 110898)
                  : (c <= 110930 || c == 110933))))
              : (c <= 110951 || (c < 113808
                ? (c < 113776
                  ? (c < 113664
                    ? (c >= 110960 && c <= 111355)
                    : c <= 113770)
                  : (c <= 113788 || (c >= 113792 && c <= 113800)))
                : (c <= 113817 || (c < 119966
                  ? (c < 119894
                    ? (c >= 119808 && c <= 119892)
                    : c <= 119964)
                  : (c <= 119967 || c == 119970))))))))))
        : (c <= 119974 || (c < 126464
          ? (c < 120656
            ? (c < 120128
              ? (c < 120071
                ? (c < 119995
                  ? (c < 119982
                    ? (c >= 119977 && c <= 119980)
                    : c <= 119993)
                  : (c <= 119995 || (c < 120005
                    ? (c >= 119997 && c <= 120003)
                    : c <= 120069)))
                : (c <= 120074 || (c < 120094
                  ? (c < 120086
                    ? (c >= 120077 && c <= 120084)
                    : c <= 120092)
                  : (c <= 120121 || (c >= 120123 && c <= 120126)))))
              : (c <= 120132 || (c < 120514
                ? (c < 120146
                  ? (c < 120138
                    ? c == 120134
                    : c <= 120144)
                  : (c <= 120485 || (c >= 120488 && c <= 120512)))
                : (c <= 120538 || (c < 120598
                  ? (c < 120572
                    ? (c >= 120540 && c <= 120570)
                    : c <= 120596)
                  : (c <= 120628 || (c >= 120630 && c <= 120654)))))))
            : (c <= 120686 || (c < 123536
              ? (c < 122661
                ? (c < 120746
                  ? (c < 120714
                    ? (c >= 120688 && c <= 120712)
                    : c <= 120744)
                  : (c <= 120770 || (c < 122624
                    ? (c >= 120772 && c <= 120779)
                    : c <= 122654)))
                : (c <= 122666 || (c < 123191
                  ? (c < 123136
                    ? (c >= 122928 && c <= 122989)
                    : c <= 123180)
                  : (c <= 123197 || c == 123214))))
              : (c <= 123565 || (c < 124909
                ? (c < 124896
                  ? (c < 124112
                    ? (c >= 123584 && c <= 123627)
                    : c <= 124139)
                  : (c <= 124902 || (c >= 124904 && c <= 124907)))
                : (c <= 124910 || (c < 125184
                  ? (c < 124928
                    ? (c >= 124912 && c <= 124926)
                    : c <= 125124)
                  : (c <= 125251 || c == 125259))))))))
          : (c <= 126467 || (c < 126561
            ? (c < 126537
              ? (c < 126516
                ? (c < 126500
                  ? (c < 126497
                    ? (c >= 126469 && c <= 126495)
                    : c <= 126498)
                  : (c <= 126500 || (c < 126505
                    ? c == 126503
                    : c <= 126514)))
                : (c <= 126519 || (c < 126530
                  ? (c < 126523
                    ? c == 126521
                    : c <= 126523)
                  : (c <= 126530 || c == 126535))))
              : (c <= 126537 || (c < 126551
                ? (c < 126545
                  ? (c < 126541
                    ? c == 126539
                    : c <= 126543)
                  : (c <= 126546 || c == 126548))
                : (c <= 126551 || (c < 126557
                  ? (c < 126555
                    ? c == 126553
                    : c <= 126555)
                  : (c <= 126557 || c == 126559))))))
            : (c <= 126562 || (c < 126629
              ? (c < 126585
                ? (c < 126572
                  ? (c < 126567
                    ? c == 126564
                    : c <= 126570)
                  : (c <= 126578 || (c >= 126580 && c <= 126583)))
                : (c <= 126588 || (c < 126603
                  ? (c < 126592
                    ? c == 126590
                    : c <= 126601)
                  : (c <= 126619 || (c >= 126625 && c <= 126627)))))
              : (c <= 126633 || (c < 178208
                ? (c < 173824
                  ? (c < 131072
                    ? (c >= 126635 && c <= 126651)
                    : c <= 173791)
                  : (c <= 177977 || (c >= 177984 && c <= 178205)))
                : (c <= 183969 || (c < 196608
                  ? (c < 194560
                    ? (c >= 183984 && c <= 191456)
                    : c <= 195101)
                  : (c <= 201546 || (c >= 201552 && c <= 205743)))))))))))))))));
}

static inline bool sym_lowercase_identifier_character_set_5(int32_t c) {
  return (c < 43514
    ? (c < 4193
      ? (c < 2707
        ? (c < 1994
          ? (c < 931
            ? (c < 748
              ? (c < 192
                ? (c < 170
                  ? (c < 'a'
                    ? c == '_'
                    : c <= 'z')
                  : (c <= 170 || (c < 186
                    ? c == 181
                    : c <= 186)))
                : (c <= 214 || (c < 710
                  ? (c < 248
                    ? (c >= 216 && c <= 246)
                    : c <= 705)
                  : (c <= 721 || (c >= 736 && c <= 740)))))
              : (c <= 748 || (c < 895
                ? (c < 886
                  ? (c < 880
                    ? c == 750
                    : c <= 884)
                  : (c <= 887 || (c >= 891 && c <= 893)))
                : (c <= 895 || (c < 908
                  ? (c < 904
                    ? c == 902
                    : c <= 906)
                  : (c <= 908 || (c >= 910 && c <= 929)))))))
            : (c <= 1013 || (c < 1649
              ? (c < 1376
                ? (c < 1329
                  ? (c < 1162
                    ? (c >= 1015 && c <= 1153)
                    : c <= 1327)
                  : (c <= 1366 || c == 1369))
                : (c <= 1416 || (c < 1568
                  ? (c < 1519
                    ? (c >= 1488 && c <= 1514)
                    : c <= 1522)
                  : (c <= 1610 || (c >= 1646 && c <= 1647)))))
              : (c <= 1747 || (c < 1791
                ? (c < 1774
                  ? (c < 1765
                    ? c == 1749
                    : c <= 1766)
                  : (c <= 1775 || (c >= 1786 && c <= 1788)))
                : (c <= 1791 || (c < 1869
                  ? (c < 1810
                    ? c == 1808
                    : c <= 1839)
                  : (c <= 1957 || c == 1969))))))))
          : (c <= 2026 || (c < 2482
            ? (c < 2208
              ? (c < 2088
                ? (c < 2048
                  ? (c < 2042
                    ? (c >= 2036 && c <= 2037)
                    : c <= 2042)
                  : (c <= 2069 || (c < 2084
                    ? c == 2074
                    : c <= 2084)))
                : (c <= 2088 || (c < 2160
                  ? (c < 2144
                    ? (c >= 2112 && c <= 2136)
                    : c <= 2154)
                  : (c <= 2183 || (c >= 2185 && c <= 2190)))))
              : (c <= 2249 || (c < 2417
                ? (c < 2384
                  ? (c < 2365
                    ? (c >= 2308 && c <= 2361)
                    : c <= 2365)
                  : (c <= 2384 || (c >= 2392 && c <= 2401)))
                : (c <= 2432 || (c < 2451
                  ? (c < 2447
                    ? (c >= 2437 && c <= 2444)
                    : c <= 2448)
                  : (c <= 2472 || (c >= 2474 && c <= 2480)))))))
            : (c <= 2482 || (c < 2579
              ? (c < 2527
                ? (c < 2510
                  ? (c < 2493
                    ? (c >= 2486 && c <= 2489)
                    : c <= 2493)
                  : (c <= 2510 || (c >= 2524 && c <= 2525)))
                : (c <= 2529 || (c < 2565
                  ? (c < 2556
                    ? (c >= 2544 && c <= 2545)
                    : c <= 2556)
                  : (c <= 2570 || (c >= 2575 && c <= 2576)))))
              : (c <= 2600 || (c < 2649
                ? (c < 2613
                  ? (c < 2610
                    ? (c >= 2602 && c <= 2608)
                    : c <= 2611)
                  : (c <= 2614 || (c >= 2616 && c <= 2617)))
                : (c <= 2652 || (c < 2693
                  ? (c < 2674
                    ? c == 2654
                    : c <= 2676)
                  : (c <= 2701 || (c >= 2703 && c <= 2705)))))))))))
        : (c <= 2728 || (c < 3242
          ? (c < 2962
            ? (c < 2858
              ? (c < 2784
                ? (c < 2741
                  ? (c < 2738
                    ? (c >= 2730 && c <= 2736)
                    : c <= 2739)
                  : (c <= 2745 || (c < 2768
                    ? c == 2749
                    : c <= 2768)))
                : (c <= 2785 || (c < 2831
                  ? (c < 2821
                    ? c == 2809
                    : c <= 2828)
                  : (c <= 2832 || (c >= 2835 && c <= 2856)))))
              : (c <= 2864 || (c < 2911
                ? (c < 2877
                  ? (c < 2869
                    ? (c >= 2866 && c <= 2867)
                    : c <= 2873)
                  : (c <= 2877 || (c >= 2908 && c <= 2909)))
                : (c <= 2913 || (c < 2949
                  ? (c < 2947
                    ? c == 2929
                    : c <= 2947)
                  : (c <= 2954 || (c >= 2958 && c <= 2960)))))))
            : (c <= 2965 || (c < 3090
              ? (c < 2984
                ? (c < 2974
                  ? (c < 2972
                    ? (c >= 2969 && c <= 2970)
                    : c <= 2972)
                  : (c <= 2975 || (c >= 2979 && c <= 2980)))
                : (c <= 2986 || (c < 3077
                  ? (c < 3024
                    ? (c >= 2990 && c <= 3001)
                    : c <= 3024)
                  : (c <= 3084 || (c >= 3086 && c <= 3088)))))
              : (c <= 3112 || (c < 3168
                ? (c < 3160
                  ? (c < 3133
                    ? (c >= 3114 && c <= 3129)
                    : c <= 3133)
                  : (c <= 3162 || c == 3165))
                : (c <= 3169 || (c < 3214
                  ? (c < 3205
                    ? c == 3200
                    : c <= 3212)
                  : (c <= 3216 || (c >= 3218 && c <= 3240)))))))))
          : (c <= 3251 || (c < 3648
            ? (c < 3412
              ? (c < 3332
                ? (c < 3293
                  ? (c < 3261
                    ? (c >= 3253 && c <= 3257)
                    : c <= 3261)
                  : (c <= 3294 || (c < 3313
                    ? (c >= 3296 && c <= 3297)
                    : c <= 3314)))
                : (c <= 3340 || (c < 3389
                  ? (c < 3346
                    ? (c >= 3342 && c <= 3344)
                    : c <= 3386)
                  : (c <= 3389 || c == 3406))))
              : (c <= 3414 || (c < 3507
                ? (c < 3461
                  ? (c < 3450
                    ? (c >= 3423 && c <= 3425)
                    : c <= 3455)
                  : (c <= 3478 || (c >= 3482 && c <= 3505)))
                : (c <= 3515 || (c < 3585
                  ? (c < 3520
                    ? c == 3517
                    : c <= 3526)
                  : (c <= 3632 || c == 3634))))))
            : (c <= 3654 || (c < 3782
              ? (c < 3749
                ? (c < 3718
                  ? (c < 3716
                    ? (c >= 3713 && c <= 3714)
                    : c <= 3716)
                  : (c <= 3722 || (c >= 3724 && c <= 3747)))
                : (c <= 3749 || (c < 3773
                  ? (c < 3762
                    ? (c >= 3751 && c <= 3760)
                    : c <= 3762)
                  : (c <= 3773 || (c >= 3776 && c <= 3780)))))
              : (c <= 3782 || (c < 3976
                ? (c < 3904
                  ? (c < 3840
                    ? (c >= 3804 && c <= 3807)
                    : c <= 3840)
                  : (c <= 3911 || (c >= 3913 && c <= 3948)))
                : (c <= 3980 || (c < 4176
                  ? (c < 4159
                    ? (c >= 4096 && c <= 4138)
                    : c <= 4159)
                  : (c <= 4181 || (c >= 4186 && c <= 4189)))))))))))))
      : (c <= 4193 || (c < 8134
        ? (c < 6176
          ? (c < 4808
            ? (c < 4688
              ? (c < 4295
                ? (c < 4213
                  ? (c < 4206
                    ? (c >= 4197 && c <= 4198)
                    : c <= 4208)
                  : (c <= 4225 || (c < 4256
                    ? c == 4238
                    : c <= 4293)))
                : (c <= 4295 || (c < 4348
                  ? (c < 4304
                    ? c == 4301
                    : c <= 4346)
                  : (c <= 4680 || (c >= 4682 && c <= 4685)))))
              : (c <= 4694 || (c < 4752
                ? (c < 4704
                  ? (c < 4698
                    ? c == 4696
                    : c <= 4701)
                  : (c <= 4744 || (c >= 4746 && c <= 4749)))
                : (c <= 4784 || (c < 4800
                  ? (c < 4792
                    ? (c >= 4786 && c <= 4789)
                    : c <= 4798)
                  : (c <= 4800 || (c >= 4802 && c <= 4805)))))))
            : (c <= 4822 || (c < 5792
              ? (c < 5024
                ? (c < 4888
                  ? (c < 4882
                    ? (c >= 4824 && c <= 4880)
                    : c <= 4885)
                  : (c <= 4954 || (c >= 4992 && c <= 5007)))
                : (c <= 5109 || (c < 5743
                  ? (c < 5121
                    ? (c >= 5112 && c <= 5117)
                    : c <= 5740)
                  : (c <= 5759 || (c >= 5761 && c <= 5786)))))
              : (c <= 5866 || (c < 5984
                ? (c < 5919
                  ? (c < 5888
                    ? (c >= 5870 && c <= 5880)
                    : c <= 5905)
                  : (c <= 5937 || (c >= 5952 && c <= 5969)))
                : (c <= 5996 || (c < 6103
                  ? (c < 6016
                    ? (c >= 5998 && c <= 6000)
                    : c <= 6067)
                  : (c <= 6103 || c == 6108))))))))
          : (c <= 6264 || (c < 7312
            ? (c < 6823
              ? (c < 6512
                ? (c < 6320
                  ? (c < 6314
                    ? (c >= 6272 && c <= 6312)
                    : c <= 6314)
                  : (c <= 6389 || (c < 6480
                    ? (c >= 6400 && c <= 6430)
                    : c <= 6509)))
                : (c <= 6516 || (c < 6656
                  ? (c < 6576
                    ? (c >= 6528 && c <= 6571)
                    : c <= 6601)
                  : (c <= 6678 || (c >= 6688 && c <= 6740)))))
              : (c <= 6823 || (c < 7098
                ? (c < 7043
                  ? (c < 6981
                    ? (c >= 6917 && c <= 6963)
                    : c <= 6988)
                  : (c <= 7072 || (c >= 7086 && c <= 7087)))
                : (c <= 7141 || (c < 7258
                  ? (c < 7245
                    ? (c >= 7168 && c <= 7203)
                    : c <= 7247)
                  : (c <= 7293 || (c >= 7296 && c <= 7304)))))))
            : (c <= 7354 || (c < 8008
              ? (c < 7418
                ? (c < 7406
                  ? (c < 7401
                    ? (c >= 7357 && c <= 7359)
                    : c <= 7404)
                  : (c <= 7411 || (c >= 7413 && c <= 7414)))
                : (c <= 7418 || (c < 7960
                  ? (c < 7680
                    ? (c >= 7424 && c <= 7615)
                    : c <= 7957)
                  : (c <= 7965 || (c >= 7968 && c <= 8005)))))
              : (c <= 8013 || (c < 8031
                ? (c < 8027
                  ? (c < 8025
                    ? (c >= 8016 && c <= 8023)
                    : c <= 8025)
                  : (c <= 8027 || c == 8029))
                : (c <= 8061 || (c < 8126
                  ? (c < 8118
                    ? (c >= 8064 && c <= 8116)
                    : c <= 8124)
                  : (c <= 8126 || (c >= 8130 && c <= 8132)))))))))))
        : (c <= 8140 || (c < 12337
          ? (c < 8544
            ? (c < 8458
              ? (c < 8305
                ? (c < 8160
                  ? (c < 8150
                    ? (c >= 8144 && c <= 8147)
                    : c <= 8155)
                  : (c <= 8172 || (c < 8182
                    ? (c >= 8178 && c <= 8180)
                    : c <= 8188)))
                : (c <= 8305 || (c < 8450
                  ? (c < 8336
                    ? c == 8319
                    : c <= 8348)
                  : (c <= 8450 || c == 8455))))
              : (c <= 8467 || (c < 8488
                ? (c < 8484
                  ? (c < 8472
                    ? c == 8469
                    : c <= 8477)
                  : (c <= 8484 || c == 8486))
                : (c <= 8488 || (c < 8517
                  ? (c < 8508
                    ? (c >= 8490 && c <= 8505)
                    : c <= 8511)
                  : (c <= 8521 || c == 8526))))))
            : (c <= 8584 || (c < 11680
              ? (c < 11559
                ? (c < 11506
                  ? (c < 11499
                    ? (c >= 11264 && c <= 11492)
                    : c <= 11502)
                  : (c <= 11507 || (c >= 11520 && c <= 11557)))
                : (c <= 11559 || (c < 11631
                  ? (c < 11568
                    ? c == 11565
                    : c <= 11623)
                  : (c <= 11631 || (c >= 11648 && c <= 11670)))))
              : (c <= 11686 || (c < 11720
                ? (c < 11704
                  ? (c < 11696
                    ? (c >= 11688 && c <= 11694)
                    : c <= 11702)
                  : (c <= 11710 || (c >= 11712 && c <= 11718)))
                : (c <= 11726 || (c < 12293
                  ? (c < 11736
                    ? (c >= 11728 && c <= 11734)
                    : c <= 11742)
                  : (c <= 12295 || (c >= 12321 && c <= 12329)))))))))
          : (c <= 12341 || (c < 42891
            ? (c < 19968
              ? (c < 12549
                ? (c < 12445
                  ? (c < 12353
                    ? (c >= 12344 && c <= 12348)
                    : c <= 12438)
                  : (c <= 12447 || (c < 12540
                    ? (c >= 12449 && c <= 12538)
                    : c <= 12543)))
                : (c <= 12591 || (c < 12784
                  ? (c < 12704
                    ? (c >= 12593 && c <= 12686)
                    : c <= 12735)
                  : (c <= 12799 || (c >= 13312 && c <= 19903)))))
              : (c <= 42124 || (c < 42560
                ? (c < 42512
                  ? (c < 42240
                    ? (c >= 42192 && c <= 42237)
                    : c <= 42508)
                  : (c <= 42527 || (c >= 42538 && c <= 42539)))
                : (c <= 42606 || (c < 42775
                  ? (c < 42656
                    ? (c >= 42623 && c <= 42653)
                    : c <= 42735)
                  : (c <= 42783 || (c >= 42786 && c <= 42888)))))))
            : (c <= 42954 || (c < 43250
              ? (c < 43011
                ? (c < 42965
                  ? (c < 42963
                    ? (c >= 42960 && c <= 42961)
                    : c <= 42963)
                  : (c <= 42969 || (c >= 42994 && c <= 43009)))
                : (c <= 43013 || (c < 43072
                  ? (c < 43020
                    ? (c >= 43015 && c <= 43018)
                    : c <= 43042)
                  : (c <= 43123 || (c >= 43138 && c <= 43187)))))
              : (c <= 43255 || (c < 43360
                ? (c < 43274
                  ? (c < 43261
                    ? c == 43259
                    : c <= 43262)
                  : (c <= 43301 || (c >= 43312 && c <= 43334)))
                : (c <= 43388 || (c < 43488
                  ? (c < 43471
                    ? (c >= 43396 && c <= 43442)
                    : c <= 43471)
                  : (c <= 43492 || (c >= 43494 && c <= 43503)))))))))))))))
    : (c <= 43518 || (c < 70727
      ? (c < 66956
        ? (c < 64914
          ? (c < 43868
            ? (c < 43714
              ? (c < 43646
                ? (c < 43588
                  ? (c < 43584
                    ? (c >= 43520 && c <= 43560)
                    : c <= 43586)
                  : (c <= 43595 || (c < 43642
                    ? (c >= 43616 && c <= 43638)
                    : c <= 43642)))
                : (c <= 43695 || (c < 43705
                  ? (c < 43701
                    ? c == 43697
                    : c <= 43702)
                  : (c <= 43709 || c == 43712))))
              : (c <= 43714 || (c < 43785
                ? (c < 43762
                  ? (c < 43744
                    ? (c >= 43739 && c <= 43741)
                    : c <= 43754)
                  : (c <= 43764 || (c >= 43777 && c <= 43782)))
                : (c <= 43790 || (c < 43816
                  ? (c < 43808
                    ? (c >= 43793 && c <= 43798)
                    : c <= 43814)
                  : (c <= 43822 || (c >= 43824 && c <= 43866)))))))
            : (c <= 43881 || (c < 64287
              ? (c < 63744
                ? (c < 55216
                  ? (c < 44032
                    ? (c >= 43888 && c <= 44002)
                    : c <= 55203)
                  : (c <= 55238 || (c >= 55243 && c <= 55291)))
                : (c <= 64109 || (c < 64275
                  ? (c < 64256
                    ? (c >= 64112 && c <= 64217)
                    : c <= 64262)
                  : (c <= 64279 || c == 64285))))
              : (c <= 64296 || (c < 64323
                ? (c < 64318
                  ? (c < 64312
                    ? (c >= 64298 && c <= 64310)
                    : c <= 64316)
                  : (c <= 64318 || (c >= 64320 && c <= 64321)))
                : (c <= 64324 || (c < 64612
                  ? (c < 64467
                    ? (c >= 64326 && c <= 64433)
                    : c <= 64605)
                  : (c <= 64829 || (c >= 64848 && c <= 64911)))))))))
          : (c <= 64967 || (c < 65599
            ? (c < 65382
              ? (c < 65147
                ? (c < 65139
                  ? (c < 65137
                    ? (c >= 65008 && c <= 65017)
                    : c <= 65137)
                  : (c <= 65139 || (c < 65145
                    ? c == 65143
                    : c <= 65145)))
                : (c <= 65147 || (c < 65313
                  ? (c < 65151
                    ? c == 65149
                    : c <= 65276)
                  : (c <= 65338 || (c >= 65345 && c <= 65370)))))
              : (c <= 65437 || (c < 65498
                ? (c < 65482
                  ? (c < 65474
                    ? (c >= 65440 && c <= 65470)
                    : c <= 65479)
                  : (c <= 65487 || (c >= 65490 && c <= 65495)))
                : (c <= 65500 || (c < 65576
                  ? (c < 65549
                    ? (c >= 65536 && c <= 65547)
                    : c <= 65574)
                  : (c <= 65594 || (c >= 65596 && c <= 65597)))))))
            : (c <= 65613 || (c < 66464
              ? (c < 66208
                ? (c < 65856
                  ? (c < 65664
                    ? (c >= 65616 && c <= 65629)
                    : c <= 65786)
                  : (c <= 65908 || (c >= 66176 && c <= 66204)))
                : (c <= 66256 || (c < 66384
                  ? (c < 66349
                    ? (c >= 66304 && c <= 66335)
                    : c <= 66378)
                  : (c <= 66421 || (c >= 66432 && c <= 66461)))))
              : (c <= 66499 || (c < 66776
                ? (c < 66560
                  ? (c < 66513
                    ? (c >= 66504 && c <= 66511)
                    : c <= 66517)
                  : (c <= 66717 || (c >= 66736 && c <= 66771)))
                : (c <= 66811 || (c < 66928
                  ? (c < 66864
                    ? (c >= 66816 && c <= 66855)
                    : c <= 66915)
                  : (c <= 66938 || (c >= 66940 && c <= 66954)))))))))))
        : (c <= 66962 || (c < 68864
          ? (c < 67828
            ? (c < 67506
              ? (c < 67072
                ? (c < 66979
                  ? (c < 66967
                    ? (c >= 66964 && c <= 66965)
                    : c <= 66977)
                  : (c <= 66993 || (c < 67003
                    ? (c >= 66995 && c <= 67001)
                    : c <= 67004)))
                : (c <= 67382 || (c < 67456
                  ? (c < 67424
                    ? (c >= 67392 && c <= 67413)
                    : c <= 67431)
                  : (c <= 67461 || (c >= 67463 && c <= 67504)))))
              : (c <= 67514 || (c < 67644
                ? (c < 67594
                  ? (c < 67592
                    ? (c >= 67584 && c <= 67589)
                    : c <= 67592)
                  : (c <= 67637 || (c >= 67639 && c <= 67640)))
                : (c <= 67644 || (c < 67712
                  ? (c < 67680
                    ? (c >= 67647 && c <= 67669)
                    : c <= 67702)
                  : (c <= 67742 || (c >= 67808 && c <= 67826)))))))
            : (c <= 67829 || (c < 68224
              ? (c < 68096
                ? (c < 67968
                  ? (c < 67872
                    ? (c >= 67840 && c <= 67861)
                    : c <= 67897)
                  : (c <= 68023 || (c >= 68030 && c <= 68031)))
                : (c <= 68096 || (c < 68121
                  ? (c < 68117
                    ? (c >= 68112 && c <= 68115)
                    : c <= 68119)
                  : (c <= 68149 || (c >= 68192 && c <= 68220)))))
              : (c <= 68252 || (c < 68448
                ? (c < 68352
                  ? (c < 68297
                    ? (c >= 68288 && c <= 68295)
                    : c <= 68324)
                  : (c <= 68405 || (c >= 68416 && c <= 68437)))
                : (c <= 68466 || (c < 68736
                  ? (c < 68608
                    ? (c >= 68480 && c <= 68497)
                    : c <= 68680)
                  : (c <= 68786 || (c >= 68800 && c <= 68850)))))))))
          : (c <= 68899 || (c < 70106
            ? (c < 69749
              ? (c < 69488
                ? (c < 69376
                  ? (c < 69296
                    ? (c >= 69248 && c <= 69289)
                    : c <= 69297)
                  : (c <= 69404 || (c < 69424
                    ? c == 69415
                    : c <= 69445)))
                : (c <= 69505 || (c < 69635
                  ? (c < 69600
                    ? (c >= 69552 && c <= 69572)
                    : c <= 69622)
                  : (c <= 69687 || (c >= 69745 && c <= 69746)))))
              : (c <= 69749 || (c < 69959
                ? (c < 69891
                  ? (c < 69840
                    ? (c >= 69763 && c <= 69807)
                    : c <= 69864)
                  : (c <= 69926 || c == 69956))
                : (c <= 69959 || (c < 70019
                  ? (c < 70006
                    ? (c >= 69968 && c <= 70002)
                    : c <= 70006)
                  : (c <= 70066 || (c >= 70081 && c <= 70084)))))))
            : (c <= 70106 || (c < 70405
              ? (c < 70280
                ? (c < 70163
                  ? (c < 70144
                    ? c == 70108
                    : c <= 70161)
                  : (c <= 70187 || (c >= 70272 && c <= 70278)))
                : (c <= 70280 || (c < 70303
                  ? (c < 70287
                    ? (c >= 70282 && c <= 70285)
                    : c <= 70301)
                  : (c <= 70312 || (c >= 70320 && c <= 70366)))))
              : (c <= 70412 || (c < 70453
                ? (c < 70442
                  ? (c < 70419
                    ? (c >= 70415 && c <= 70416)
                    : c <= 70440)
                  : (c <= 70448 || (c >= 70450 && c <= 70451)))
                : (c <= 70457 || (c < 70493
                  ? (c < 70480
                    ? c == 70461
                    : c <= 70480)
                  : (c <= 70497 || (c >= 70656 && c <= 70708)))))))))))))
      : (c <= 70730 || (c < 119894
        ? (c < 73056
          ? (c < 72001
            ? (c < 71424
              ? (c < 71128
                ? (c < 70852
                  ? (c < 70784
                    ? (c >= 70751 && c <= 70753)
                    : c <= 70831)
                  : (c <= 70853 || (c < 71040
                    ? c == 70855
                    : c <= 71086)))
                : (c <= 71131 || (c < 71296
                  ? (c < 71236
                    ? (c >= 71168 && c <= 71215)
                    : c <= 71236)
                  : (c <= 71338 || c == 71352))))
              : (c <= 71450 || (c < 71945
                ? (c < 71840
                  ? (c < 71680
                    ? (c >= 71488 && c <= 71494)
                    : c <= 71723)
                  : (c <= 71903 || (c >= 71935 && c <= 71942)))
                : (c <= 71945 || (c < 71960
                  ? (c < 71957
                    ? (c >= 71948 && c <= 71955)
                    : c <= 71958)
                  : (c <= 71983 || c == 71999))))))
            : (c <= 72001 || (c < 72349
              ? (c < 72192
                ? (c < 72161
                  ? (c < 72106
                    ? (c >= 72096 && c <= 72103)
                    : c <= 72144)
                  : (c <= 72161 || c == 72163))
                : (c <= 72192 || (c < 72272
                  ? (c < 72250
                    ? (c >= 72203 && c <= 72242)
                    : c <= 72250)
                  : (c <= 72272 || (c >= 72284 && c <= 72329)))))
              : (c <= 72349 || (c < 72818
                ? (c < 72714
                  ? (c < 72704
                    ? (c >= 72368 && c <= 72440)
                    : c <= 72712)
                  : (c <= 72750 || c == 72768))
                : (c <= 72847 || (c < 72971
                  ? (c < 72968
                    ? (c >= 72960 && c <= 72966)
                    : c <= 72969)
                  : (c <= 73008 || c == 73030))))))))
          : (c <= 73061 || (c < 93952
            ? (c < 82944
              ? (c < 73728
                ? (c < 73112
                  ? (c < 73066
                    ? (c >= 73063 && c <= 73064)
                    : c <= 73097)
                  : (c <= 73112 || (c < 73648
                    ? (c >= 73440 && c <= 73458)
                    : c <= 73648)))
                : (c <= 74649 || (c < 77712
                  ? (c < 74880
                    ? (c >= 74752 && c <= 74862)
                    : c <= 75075)
                  : (c <= 77808 || (c >= 77824 && c <= 78894)))))
              : (c <= 83526 || (c < 92928
                ? (c < 92784
                  ? (c < 92736
                    ? (c >= 92160 && c <= 92728)
                    : c <= 92766)
                  : (c <= 92862 || (c >= 92880 && c <= 92909)))
                : (c <= 92975 || (c < 93053
                  ? (c < 93027
                    ? (c >= 92992 && c <= 92995)
                    : c <= 93047)
                  : (c <= 93071 || (c >= 93760 && c <= 93823)))))))
            : (c <= 94026 || (c < 110589
              ? (c < 94208
                ? (c < 94176
                  ? (c < 94099
                    ? c == 94032
                    : c <= 94111)
                  : (c <= 94177 || c == 94179))
                : (c <= 100343 || (c < 110576
                  ? (c < 101632
                    ? (c >= 100352 && c <= 101589)
                    : c <= 101640)
                  : (c <= 110579 || (c >= 110581 && c <= 110587)))))
              : (c <= 110590 || (c < 113664
                ? (c < 110948
                  ? (c < 110928
                    ? (c >= 110592 && c <= 110882)
                    : c <= 110930)
                  : (c <= 110951 || (c >= 110960 && c <= 111355)))
                : (c <= 113770 || (c < 113808
                  ? (c < 113792
                    ? (c >= 113776 && c <= 113788)
                    : c <= 113800)
                  : (c <= 113817 || (c >= 119808 && c <= 119892)))))))))))
        : (c <= 119964 || (c < 125259
          ? (c < 120572
            ? (c < 120086
              ? (c < 119995
                ? (c < 119973
                  ? (c < 119970
                    ? (c >= 119966 && c <= 119967)
                    : c <= 119970)
                  : (c <= 119974 || (c < 119982
                    ? (c >= 119977 && c <= 119980)
                    : c <= 119993)))
                : (c <= 119995 || (c < 120071
                  ? (c < 120005
                    ? (c >= 119997 && c <= 120003)
                    : c <= 120069)
                  : (c <= 120074 || (c >= 120077 && c <= 120084)))))
              : (c <= 120092 || (c < 120138
                ? (c < 120128
                  ? (c < 120123
                    ? (c >= 120094 && c <= 120121)
                    : c <= 120126)
                  : (c <= 120132 || c == 120134))
                : (c <= 120144 || (c < 120514
                  ? (c < 120488
                    ? (c >= 120146 && c <= 120485)
                    : c <= 120512)
                  : (c <= 120538 || (c >= 120540 && c <= 120570)))))))
            : (c <= 120596 || (c < 123191
              ? (c < 120714
                ? (c < 120656
                  ? (c < 120630
                    ? (c >= 120598 && c <= 120628)
                    : c <= 120654)
                  : (c <= 120686 || (c >= 120688 && c <= 120712)))
                : (c <= 120744 || (c < 122624
                  ? (c < 120772
                    ? (c >= 120746 && c <= 120770)
                    : c <= 120779)
                  : (c <= 122654 || (c >= 123136 && c <= 123180)))))
              : (c <= 123197 || (c < 124904
                ? (c < 123584
                  ? (c < 123536
                    ? c == 123214
                    : c <= 123565)
                  : (c <= 123627 || (c >= 124896 && c <= 124902)))
                : (c <= 124907 || (c < 124928
                  ? (c < 124912
                    ? (c >= 124909 && c <= 124910)
                    : c <= 124926)
                  : (c <= 125124 || (c >= 125184 && c <= 125251)))))))))
          : (c <= 125259 || (c < 126559
            ? (c < 126535
              ? (c < 126505
                ? (c < 126497
                  ? (c < 126469
                    ? (c >= 126464 && c <= 126467)
                    : c <= 126495)
                  : (c <= 126498 || (c < 126503
                    ? c == 126500
                    : c <= 126503)))
                : (c <= 126514 || (c < 126523
                  ? (c < 126521
                    ? (c >= 126516 && c <= 126519)
                    : c <= 126521)
                  : (c <= 126523 || c == 126530))))
              : (c <= 126535 || (c < 126548
                ? (c < 126541
                  ? (c < 126539
                    ? c == 126537
                    : c <= 126539)
                  : (c <= 126543 || (c >= 126545 && c <= 126546)))
                : (c <= 126548 || (c < 126555
                  ? (c < 126553
                    ? c == 126551
                    : c <= 126553)
                  : (c <= 126555 || c == 126557))))))
            : (c <= 126559 || (c < 126625
              ? (c < 126580
                ? (c < 126567
                  ? (c < 126564
                    ? (c >= 126561 && c <= 126562)
                    : c <= 126564)
                  : (c <= 126570 || (c >= 126572 && c <= 126578)))
                : (c <= 126583 || (c < 126592
                  ? (c < 126590
                    ? (c >= 126585 && c <= 126588)
                    : c <= 126590)
                  : (c <= 126601 || (c >= 126603 && c <= 126619)))))
              : (c <= 126627 || (c < 177984
                ? (c < 131072
                  ? (c < 126635
                    ? (c >= 126629 && c <= 126633)
                    : c <= 126651)
                  : (c <= 173791 || (c >= 173824 && c <= 177976)))
                : (c <= 178205 || (c < 194560
                  ? (c < 183984
                    ? (c >= 178208 && c <= 183969)
                    : c <= 191456)
                  : (c <= 195101 || (c >= 196608 && c <= 201546)))))))))))))))));
}

static inline bool sym_lowercase_identifier_character_set_6(int32_t c) {
  return (c < 43616
    ? (c < 3782
      ? (c < 2748
        ? (c < 2045
          ? (c < 1015
            ? (c < 710
              ? (c < 181
                ? (c < '_'
                  ? (c < 'A'
                    ? (c >= '0' && c <= '9')
                    : c <= 'Z')
                  : (c <= '_' || (c < 170
                    ? (c >= 'a' && c <= 'z')
                    : c <= 170)))
                : (c <= 181 || (c < 192
                  ? (c < 186
                    ? c == 183
                    : c <= 186)
                  : (c <= 214 || (c < 248
                    ? (c >= 216 && c <= 246)
                    : c <= 705)))))
              : (c <= 721 || (c < 891
                ? (c < 750
                  ? (c < 748
                    ? (c >= 736 && c <= 740)
                    : c <= 748)
                  : (c <= 750 || (c < 886
                    ? (c >= 768 && c <= 884)
                    : c <= 887)))
                : (c <= 893 || (c < 908
                  ? (c < 902
                    ? c == 895
                    : c <= 906)
                  : (c <= 908 || (c < 931
                    ? (c >= 910 && c <= 929)
                    : c <= 1013)))))))
            : (c <= 1153 || (c < 1519
              ? (c < 1425
                ? (c < 1329
                  ? (c < 1162
                    ? (c >= 1155 && c <= 1159)
                    : c <= 1327)
                  : (c <= 1366 || (c < 1376
                    ? c == 1369
                    : c <= 1416)))
                : (c <= 1469 || (c < 1476
                  ? (c < 1473
                    ? c == 1471
                    : c <= 1474)
                  : (c <= 1477 || (c < 1488
                    ? c == 1479
                    : c <= 1514)))))
              : (c <= 1522 || (c < 1770
                ? (c < 1646
                  ? (c < 1568
                    ? (c >= 1552 && c <= 1562)
                    : c <= 1641)
                  : (c <= 1747 || (c < 1759
                    ? (c >= 1749 && c <= 1756)
                    : c <= 1768)))
                : (c <= 1788 || (c < 1869
                  ? (c < 1808
                    ? c == 1791
                    : c <= 1866)
                  : (c <= 1969 || (c < 2042
                    ? (c >= 1984 && c <= 2037)
                    : c <= 2042)))))))))
          : (c <= 2045 || (c < 2558
            ? (c < 2451
              ? (c < 2200
                ? (c < 2144
                  ? (c < 2112
                    ? (c >= 2048 && c <= 2093)
                    : c <= 2139)
                  : (c <= 2154 || (c < 2185
                    ? (c >= 2160 && c <= 2183)
                    : c <= 2190)))
                : (c <= 2273 || (c < 2417
                  ? (c < 2406
                    ? (c >= 2275 && c <= 2403)
                    : c <= 2415)
                  : (c <= 2435 || (c < 2447
                    ? (c >= 2437 && c <= 2444)
                    : c <= 2448)))))
              : (c <= 2472 || (c < 2507
                ? (c < 2486
                  ? (c < 2482
                    ? (c >= 2474 && c <= 2480)
                    : c <= 2482)
                  : (c <= 2489 || (c < 2503
                    ? (c >= 2492 && c <= 2500)
                    : c <= 2504)))
                : (c <= 2510 || (c < 2527
                  ? (c < 2524
                    ? c == 2519
                    : c <= 2525)
                  : (c <= 2531 || (c < 2556
                    ? (c >= 2534 && c <= 2545)
                    : c <= 2556)))))))
            : (c <= 2558 || (c < 2635
              ? (c < 2610
                ? (c < 2575
                  ? (c < 2565
                    ? (c >= 2561 && c <= 2563)
                    : c <= 2570)
                  : (c <= 2576 || (c < 2602
                    ? (c >= 2579 && c <= 2600)
                    : c <= 2608)))
                : (c <= 2611 || (c < 2620
                  ? (c < 2616
                    ? (c >= 2613 && c <= 2614)
                    : c <= 2617)
                  : (c <= 2620 || (c < 2631
                    ? (c >= 2622 && c <= 2626)
                    : c <= 2632)))))
              : (c <= 2637 || (c < 2693
                ? (c < 2654
                  ? (c < 2649
                    ? c == 2641
                    : c <= 2652)
                  : (c <= 2654 || (c < 2689
                    ? (c >= 2662 && c <= 2677)
                    : c <= 2691)))
                : (c <= 2701 || (c < 2730
                  ? (c < 2707
                    ? (c >= 2703 && c <= 2705)
                    : c <= 2728)
                  : (c <= 2736 || (c < 2741
                    ? (c >= 2738 && c <= 2739)
                    : c <= 2745)))))))))))
        : (c <= 2757 || (c < 3168
          ? (c < 2958
            ? (c < 2866
              ? (c < 2809
                ? (c < 2768
                  ? (c < 2763
                    ? (c >= 2759 && c <= 2761)
                    : c <= 2765)
                  : (c <= 2768 || (c < 2790
                    ? (c >= 2784 && c <= 2787)
                    : c <= 2799)))
                : (c <= 2815 || (c < 2831
                  ? (c < 2821
                    ? (c >= 2817 && c <= 2819)
                    : c <= 2828)
                  : (c <= 2832 || (c < 2858
                    ? (c >= 2835 && c <= 2856)
                    : c <= 2864)))))
              : (c <= 2867 || (c < 2908
                ? (c < 2887
                  ? (c < 2876
                    ? (c >= 2869 && c <= 2873)
                    : c <= 2884)
                  : (c <= 2888 || (c < 2901
                    ? (c >= 2891 && c <= 2893)
                    : c <= 2903)))
                : (c <= 2909 || (c < 2929
                  ? (c < 2918
                    ? (c >= 2911 && c <= 2915)
                    : c <= 2927)
                  : (c <= 2929 || (c < 2949
                    ? (c >= 2946 && c <= 2947)
                    : c <= 2954)))))))
            : (c <= 2960 || (c < 3031
              ? (c < 2984
                ? (c < 2972
                  ? (c < 2969
                    ? (c >= 2962 && c <= 2965)
                    : c <= 2970)
                  : (c <= 2972 || (c < 2979
                    ? (c >= 2974 && c <= 2975)
                    : c <= 2980)))
                : (c <= 2986 || (c < 3014
                  ? (c < 3006
                    ? (c >= 2990 && c <= 3001)
                    : c <= 3010)
                  : (c <= 3016 || (c < 3024
                    ? (c >= 3018 && c <= 3021)
                    : c <= 3024)))))
              : (c <= 3031 || (c < 3132
                ? (c < 3086
                  ? (c < 3072
                    ? (c >= 3046 && c <= 3055)
                    : c <= 3084)
                  : (c <= 3088 || (c < 3114
                    ? (c >= 3090 && c <= 3112)
                    : c <= 3129)))
                : (c <= 3140 || (c < 3157
                  ? (c < 3146
                    ? (c >= 3142 && c <= 3144)
                    : c <= 3149)
                  : (c <= 3158 || (c < 3165
                    ? (c >= 3160 && c <= 3162)
                    : c <= 3165)))))))))
          : (c <= 3171 || (c < 3450
            ? (c < 3293
              ? (c < 3242
                ? (c < 3205
                  ? (c < 3200
                    ? (c >= 3174 && c <= 3183)
                    : c <= 3203)
                  : (c <= 3212 || (c < 3218
                    ? (c >= 3214 && c <= 3216)
                    : c <= 3240)))
                : (c <= 3251 || (c < 3270
                  ? (c < 3260
                    ? (c >= 3253 && c <= 3257)
                    : c <= 3268)
                  : (c <= 3272 || (c < 3285
                    ? (c >= 3274 && c <= 3277)
                    : c <= 3286)))))
              : (c <= 3294 || (c < 3346
                ? (c < 3313
                  ? (c < 3302
                    ? (c >= 3296 && c <= 3299)
                    : c <= 3311)
                  : (c <= 3314 || (c < 3342
                    ? (c >= 3328 && c <= 3340)
                    : c <= 3344)))
                : (c <= 3396 || (c < 3412
                  ? (c < 3402
                    ? (c >= 3398 && c <= 3400)
                    : c <= 3406)
                  : (c <= 3415 || (c < 3430
                    ? (c >= 3423 && c <= 3427)
                    : c <= 3439)))))))
            : (c <= 3455 || (c < 3570
              ? (c < 3520
                ? (c < 3482
                  ? (c < 3461
                    ? (c >= 3457 && c <= 3459)
                    : c <= 3478)
                  : (c <= 3505 || (c < 3517
                    ? (c >= 3507 && c <= 3515)
                    : c <= 3517)))
                : (c <= 3526 || (c < 3542
                  ? (c < 3535
                    ? c == 3530
                    : c <= 3540)
                  : (c <= 3542 || (c < 3558
                    ? (c >= 3544 && c <= 3551)
                    : c <= 3567)))))
              : (c <= 3571 || (c < 3718
                ? (c < 3664
                  ? (c < 3648
                    ? (c >= 3585 && c <= 3642)
                    : c <= 3662)
                  : (c <= 3673 || (c < 3716
                    ? (c >= 3713 && c <= 3714)
                    : c <= 3716)))
                : (c <= 3722 || (c < 3751
                  ? (c < 3749
                    ? (c >= 3724 && c <= 3747)
                    : c <= 3749)
                  : (c <= 3773 || (c >= 3776 && c <= 3780)))))))))))))
      : (c <= 3782 || (c < 8025
        ? (c < 5888
          ? (c < 4688
            ? (c < 3953
              ? (c < 3872
                ? (c < 3804
                  ? (c < 3792
                    ? (c >= 3784 && c <= 3789)
                    : c <= 3801)
                  : (c <= 3807 || (c < 3864
                    ? c == 3840
                    : c <= 3865)))
                : (c <= 3881 || (c < 3897
                  ? (c < 3895
                    ? c == 3893
                    : c <= 3895)
                  : (c <= 3897 || (c < 3913
                    ? (c >= 3902 && c <= 3911)
                    : c <= 3948)))))
              : (c <= 3972 || (c < 4256
                ? (c < 4038
                  ? (c < 3993
                    ? (c >= 3974 && c <= 3991)
                    : c <= 4028)
                  : (c <= 4038 || (c < 4176
                    ? (c >= 4096 && c <= 4169)
                    : c <= 4253)))
                : (c <= 4293 || (c < 4304
                  ? (c < 4301
                    ? c == 4295
                    : c <= 4301)
                  : (c <= 4346 || (c < 4682
                    ? (c >= 4348 && c <= 4680)
                    : c <= 4685)))))))
            : (c <= 4694 || (c < 4882
              ? (c < 4786
                ? (c < 4704
                  ? (c < 4698
                    ? c == 4696
                    : c <= 4701)
                  : (c <= 4744 || (c < 4752
                    ? (c >= 4746 && c <= 4749)
                    : c <= 4784)))
                : (c <= 4789 || (c < 4802
                  ? (c < 4800
                    ? (c >= 4792 && c <= 4798)
                    : c <= 4800)
                  : (c <= 4805 || (c < 4824
                    ? (c >= 4808 && c <= 4822)
                    : c <= 4880)))))
              : (c <= 4885 || (c < 5112
                ? (c < 4969
                  ? (c < 4957
                    ? (c >= 4888 && c <= 4954)
                    : c <= 4959)
                  : (c <= 4977 || (c < 5024
                    ? (c >= 4992 && c <= 5007)
                    : c <= 5109)))
                : (c <= 5117 || (c < 5761
                  ? (c < 5743
                    ? (c >= 5121 && c <= 5740)
                    : c <= 5759)
                  : (c <= 5786 || (c < 5870
                    ? (c >= 5792 && c <= 5866)
                    : c <= 5880)))))))))
          : (c <= 5909 || (c < 6688
            ? (c < 6176
              ? (c < 6016
                ? (c < 5984
                  ? (c < 5952
                    ? (c >= 5919 && c <= 5940)
                    : c <= 5971)
                  : (c <= 5996 || (c < 6002
                    ? (c >= 5998 && c <= 6000)
                    : c <= 6003)))
                : (c <= 6099 || (c < 6112
                  ? (c < 6108
                    ? c == 6103
                    : c <= 6109)
                  : (c <= 6121 || (c < 6159
                    ? (c >= 6155 && c <= 6157)
                    : c <= 6169)))))
              : (c <= 6264 || (c < 6470
                ? (c < 6400
                  ? (c < 6320
                    ? (c >= 6272 && c <= 6314)
                    : c <= 6389)
                  : (c <= 6430 || (c < 6448
                    ? (c >= 6432 && c <= 6443)
                    : c <= 6459)))
                : (c <= 6509 || (c < 6576
                  ? (c < 6528
                    ? (c >= 6512 && c <= 6516)
                    : c <= 6571)
                  : (c <= 6601 || (c < 6656
                    ? (c >= 6608 && c <= 6618)
                    : c <= 6683)))))))
            : (c <= 6750 || (c < 7232
              ? (c < 6847
                ? (c < 6800
                  ? (c < 6783
                    ? (c >= 6752 && c <= 6780)
                    : c <= 6793)
                  : (c <= 6809 || (c < 6832
                    ? c == 6823
                    : c <= 6845)))
                : (c <= 6862 || (c < 7019
                  ? (c < 6992
                    ? (c >= 6912 && c <= 6988)
                    : c <= 7001)
                  : (c <= 7027 || (c < 7168
                    ? (c >= 7040 && c <= 7155)
                    : c <= 7223)))))
              : (c <= 7241 || (c < 7380
                ? (c < 7312
                  ? (c < 7296
                    ? (c >= 7245 && c <= 7293)
                    : c <= 7304)
                  : (c <= 7354 || (c < 7376
                    ? (c >= 7357 && c <= 7359)
                    : c <= 7378)))
                : (c <= 7418 || (c < 7968
                  ? (c < 7960
                    ? (c >= 7424 && c <= 7957)
                    : c <= 7965)
                  : (c <= 8005 || (c < 8016
                    ? (c >= 8008 && c <= 8013)
                    : c <= 8023)))))))))))
        : (c <= 8025 || (c < 11720
          ? (c < 8458
            ? (c < 8178
              ? (c < 8126
                ? (c < 8031
                  ? (c < 8029
                    ? c == 8027
                    : c <= 8029)
                  : (c <= 8061 || (c < 8118
                    ? (c >= 8064 && c <= 8116)
                    : c <= 8124)))
                : (c <= 8126 || (c < 8144
                  ? (c < 8134
                    ? (c >= 8130 && c <= 8132)
                    : c <= 8140)
                  : (c <= 8147 || (c < 8160
                    ? (c >= 8150 && c <= 8155)
                    : c <= 8172)))))
              : (c <= 8180 || (c < 8336
                ? (c < 8276
                  ? (c < 8255
                    ? (c >= 8182 && c <= 8188)
                    : c <= 8256)
                  : (c <= 8276 || (c < 8319
                    ? c == 8305
                    : c <= 8319)))
                : (c <= 8348 || (c < 8421
                  ? (c < 8417
                    ? (c >= 8400 && c <= 8412)
                    : c <= 8417)
                  : (c <= 8432 || (c < 8455
                    ? c == 8450
                    : c <= 8455)))))))
            : (c <= 8467 || (c < 11499
              ? (c < 8490
                ? (c < 8484
                  ? (c < 8472
                    ? c == 8469
                    : c <= 8477)
                  : (c <= 8484 || (c < 8488
                    ? c == 8486
                    : c <= 8488)))
                : (c <= 8505 || (c < 8526
                  ? (c < 8517
                    ? (c >= 8508 && c <= 8511)
                    : c <= 8521)
                  : (c <= 8526 || (c < 11264
                    ? (c >= 8544 && c <= 8584)
                    : c <= 11492)))))
              : (c <= 11507 || (c < 11647
                ? (c < 11565
                  ? (c < 11559
                    ? (c >= 11520 && c <= 11557)
                    : c <= 11559)
                  : (c <= 11565 || (c < 11631
                    ? (c >= 11568 && c <= 11623)
                    : c <= 11631)))
                : (c <= 11670 || (c < 11696
                  ? (c < 11688
                    ? (c >= 11680 && c <= 11686)
                    : c <= 11694)
                  : (c <= 11702 || (c < 11712
                    ? (c >= 11704 && c <= 11710)
                    : c <= 11718)))))))))
          : (c <= 11726 || (c < 42623
            ? (c < 12540
              ? (c < 12337
                ? (c < 11744
                  ? (c < 11736
                    ? (c >= 11728 && c <= 11734)
                    : c <= 11742)
                  : (c <= 11775 || (c < 12321
                    ? (c >= 12293 && c <= 12295)
                    : c <= 12335)))
                : (c <= 12341 || (c < 12441
                  ? (c < 12353
                    ? (c >= 12344 && c <= 12348)
                    : c <= 12438)
                  : (c <= 12442 || (c < 12449
                    ? (c >= 12445 && c <= 12447)
                    : c <= 12538)))))
              : (c <= 12543 || (c < 19968
                ? (c < 12704
                  ? (c < 12593
                    ? (c >= 12549 && c <= 12591)
                    : c <= 12686)
                  : (c <= 12735 || (c < 13312
                    ? (c >= 12784 && c <= 12799)
                    : c <= 19903)))
                : (c <= 42124 || (c < 42512
                  ? (c < 42240
                    ? (c >= 42192 && c <= 42237)
                    : c <= 42508)
                  : (c <= 42539 || (c < 42612
                    ? (c >= 42560 && c <= 42607)
                    : c <= 42621)))))))
            : (c <= 42737 || (c < 43232
              ? (c < 42965
                ? (c < 42891
                  ? (c < 42786
                    ? (c >= 42775 && c <= 42783)
                    : c <= 42888)
                  : (c <= 42954 || (c < 42963
                    ? (c >= 42960 && c <= 42961)
                    : c <= 42963)))
                : (c <= 42969 || (c < 43072
                  ? (c < 43052
                    ? (c >= 42994 && c <= 43047)
                    : c <= 43052)
                  : (c <= 43123 || (c < 43216
                    ? (c >= 43136 && c <= 43205)
                    : c <= 43225)))))
              : (c <= 43255 || (c < 43471
                ? (c < 43312
                  ? (c < 43261
                    ? c == 43259
                    : c <= 43309)
                  : (c <= 43347 || (c < 43392
                    ? (c >= 43360 && c <= 43388)
                    : c <= 43456)))
                : (c <= 43481 || (c < 43584
                  ? (c < 43520
                    ? (c >= 43488 && c <= 43518)
                    : c <= 43574)
                  : (c <= 43597 || (c >= 43600 && c <= 43609)))))))))))))))
    : (c <= 43638 || (c < 71453
      ? (c < 67639
        ? (c < 65345
          ? (c < 64312
            ? (c < 43888
              ? (c < 43785
                ? (c < 43744
                  ? (c < 43739
                    ? (c >= 43642 && c <= 43714)
                    : c <= 43741)
                  : (c <= 43759 || (c < 43777
                    ? (c >= 43762 && c <= 43766)
                    : c <= 43782)))
                : (c <= 43790 || (c < 43816
                  ? (c < 43808
                    ? (c >= 43793 && c <= 43798)
                    : c <= 43814)
                  : (c <= 43822 || (c < 43868
                    ? (c >= 43824 && c <= 43866)
                    : c <= 43881)))))
              : (c <= 44010 || (c < 63744
                ? (c < 44032
                  ? (c < 44016
                    ? (c >= 44012 && c <= 44013)
                    : c <= 44025)
                  : (c <= 55203 || (c < 55243
                    ? (c >= 55216 && c <= 55238)
                    : c <= 55291)))
                : (c <= 64109 || (c < 64275
                  ? (c < 64256
                    ? (c >= 64112 && c <= 64217)
                    : c <= 64262)
                  : (c <= 64279 || (c < 64298
                    ? (c >= 64285 && c <= 64296)
                    : c <= 64310)))))))
            : (c <= 64316 || (c < 65075
              ? (c < 64612
                ? (c < 64323
                  ? (c < 64320
                    ? c == 64318
                    : c <= 64321)
                  : (c <= 64324 || (c < 64467
                    ? (c >= 64326 && c <= 64433)
                    : c <= 64605)))
                : (c <= 64829 || (c < 65008
                  ? (c < 64914
                    ? (c >= 64848 && c <= 64911)
                    : c <= 64967)
                  : (c <= 65017 || (c < 65056
                    ? (c >= 65024 && c <= 65039)
                    : c <= 65071)))))
              : (c <= 65076 || (c < 65147
                ? (c < 65139
                  ? (c < 65137
                    ? (c >= 65101 && c <= 65103)
                    : c <= 65137)
                  : (c <= 65139 || (c < 65145
                    ? c == 65143
                    : c <= 65145)))
                : (c <= 65147 || (c < 65296
                  ? (c < 65151
                    ? c == 65149
                    : c <= 65276)
                  : (c <= 65305 || (c < 65343
                    ? (c >= 65313 && c <= 65338)
                    : c <= 65343)))))))))
          : (c <= 65370 || (c < 66513
            ? (c < 65664
              ? (c < 65536
                ? (c < 65482
                  ? (c < 65474
                    ? (c >= 65382 && c <= 65470)
                    : c <= 65479)
                  : (c <= 65487 || (c < 65498
                    ? (c >= 65490 && c <= 65495)
                    : c <= 65500)))
                : (c <= 65547 || (c < 65596
                  ? (c < 65576
                    ? (c >= 65549 && c <= 65574)
                    : c <= 65594)
                  : (c <= 65597 || (c < 65616
                    ? (c >= 65599 && c <= 65613)
                    : c <= 65629)))))
              : (c <= 65786 || (c < 66304
                ? (c < 66176
                  ? (c < 66045
                    ? (c >= 65856 && c <= 65908)
                    : c <= 66045)
                  : (c <= 66204 || (c < 66272
                    ? (c >= 66208 && c <= 66256)
                    : c <= 66272)))
                : (c <= 66335 || (c < 66432
                  ? (c < 66384
                    ? (c >= 66349 && c <= 66378)
                    : c <= 66426)
                  : (c <= 66461 || (c < 66504
                    ? (c >= 66464 && c <= 66499)
                    : c <= 66511)))))))
            : (c <= 66517 || (c < 66979
              ? (c < 66864
                ? (c < 66736
                  ? (c < 66720
                    ? (c >= 66560 && c <= 66717)
                    : c <= 66729)
                  : (c <= 66771 || (c < 66816
                    ? (c >= 66776 && c <= 66811)
                    : c <= 66855)))
                : (c <= 66915 || (c < 66956
                  ? (c < 66940
                    ? (c >= 66928 && c <= 66938)
                    : c <= 66954)
                  : (c <= 66962 || (c < 66967
                    ? (c >= 66964 && c <= 66965)
                    : c <= 66977)))))
              : (c <= 66993 || (c < 67456
                ? (c < 67072
                  ? (c < 67003
                    ? (c >= 66995 && c <= 67001)
                    : c <= 67004)
                  : (c <= 67382 || (c < 67424
                    ? (c >= 67392 && c <= 67413)
                    : c <= 67431)))
                : (c <= 67461 || (c < 67584
                  ? (c < 67506
                    ? (c >= 67463 && c <= 67504)
                    : c <= 67514)
                  : (c <= 67589 || (c < 67594
                    ? c == 67592
                    : c <= 67637)))))))))))
        : (c <= 67640 || (c < 69956
          ? (c < 68448
            ? (c < 68101
              ? (c < 67828
                ? (c < 67680
                  ? (c < 67647
                    ? c == 67644
                    : c <= 67669)
                  : (c <= 67702 || (c < 67808
                    ? (c >= 67712 && c <= 67742)
                    : c <= 67826)))
                : (c <= 67829 || (c < 67968
                  ? (c < 67872
                    ? (c >= 67840 && c <= 67861)
                    : c <= 67897)
                  : (c <= 68023 || (c < 68096
                    ? (c >= 68030 && c <= 68031)
                    : c <= 68099)))))
              : (c <= 68102 || (c < 68192
                ? (c < 68121
                  ? (c < 68117
                    ? (c >= 68108 && c <= 68115)
                    : c <= 68119)
                  : (c <= 68149 || (c < 68159
                    ? (c >= 68152 && c <= 68154)
                    : c <= 68159)))
                : (c <= 68220 || (c < 68297
                  ? (c < 68288
                    ? (c >= 68224 && c <= 68252)
                    : c <= 68295)
                  : (c <= 68326 || (c < 68416
                    ? (c >= 68352 && c <= 68405)
                    : c <= 68437)))))))
            : (c <= 68466 || (c < 69424
              ? (c < 68912
                ? (c < 68736
                  ? (c < 68608
                    ? (c >= 68480 && c <= 68497)
                    : c <= 68680)
                  : (c <= 68786 || (c < 68864
                    ? (c >= 68800 && c <= 68850)
                    : c <= 68903)))
                : (c <= 68921 || (c < 69296
                  ? (c < 69291
                    ? (c >= 69248 && c <= 69289)
                    : c <= 69292)
                  : (c <= 69297 || (c < 69415
                    ? (c >= 69376 && c <= 69404)
                    : c <= 69415)))))
              : (c <= 69456 || (c < 69759
                ? (c < 69600
                  ? (c < 69552
                    ? (c >= 69488 && c <= 69509)
                    : c <= 69572)
                  : (c <= 69622 || (c < 69734
                    ? (c >= 69632 && c <= 69702)
                    : c <= 69749)))
                : (c <= 69818 || (c < 69872
                  ? (c < 69840
                    ? c == 69826
                    : c <= 69864)
                  : (c <= 69881 || (c < 69942
                    ? (c >= 69888 && c <= 69940)
                    : c <= 69951)))))))))
          : (c <= 69959 || (c < 70459
            ? (c < 70282
              ? (c < 70108
                ? (c < 70016
                  ? (c < 70006
                    ? (c >= 69968 && c <= 70003)
                    : c <= 70006)
                  : (c <= 70084 || (c < 70094
                    ? (c >= 70089 && c <= 70092)
                    : c <= 70106)))
                : (c <= 70108 || (c < 70206
                  ? (c < 70163
                    ? (c >= 70144 && c <= 70161)
                    : c <= 70199)
                  : (c <= 70206 || (c < 70280
                    ? (c >= 70272 && c <= 70278)
                    : c <= 70280)))))
              : (c <= 70285 || (c < 70405
                ? (c < 70320
                  ? (c < 70303
                    ? (c >= 70287 && c <= 70301)
                    : c <= 70312)
                  : (c <= 70378 || (c < 70400
                    ? (c >= 70384 && c <= 70393)
                    : c <= 70403)))
                : (c <= 70412 || (c < 70442
                  ? (c < 70419
                    ? (c >= 70415 && c <= 70416)
                    : c <= 70440)
                  : (c <= 70448 || (c < 70453
                    ? (c >= 70450 && c <= 70451)
                    : c <= 70457)))))))
            : (c <= 70468 || (c < 70855
              ? (c < 70502
                ? (c < 70480
                  ? (c < 70475
                    ? (c >= 70471 && c <= 70472)
                    : c <= 70477)
                  : (c <= 70480 || (c < 70493
                    ? c == 70487
                    : c <= 70499)))
                : (c <= 70508 || (c < 70736
                  ? (c < 70656
                    ? (c >= 70512 && c <= 70516)
                    : c <= 70730)
                  : (c <= 70745 || (c < 70784
                    ? (c >= 70750 && c <= 70753)
                    : c <= 70853)))))
              : (c <= 70855 || (c < 71236
                ? (c < 71096
                  ? (c < 71040
                    ? (c >= 70864 && c <= 70873)
                    : c <= 71093)
                  : (c <= 71104 || (c < 71168
                    ? (c >= 71128 && c <= 71133)
                    : c <= 71232)))
                : (c <= 71236 || (c < 71360
                  ? (c < 71296
                    ? (c >= 71248 && c <= 71257)
                    : c <= 71352)
                  : (c <= 71369 || (c >= 71424 && c <= 71450)))))))))))))
      : (c <= 71467 || (c < 119973
        ? (c < 77824
          ? (c < 72760
            ? (c < 72016
              ? (c < 71945
                ? (c < 71680
                  ? (c < 71488
                    ? (c >= 71472 && c <= 71481)
                    : c <= 71494)
                  : (c <= 71738 || (c < 71935
                    ? (c >= 71840 && c <= 71913)
                    : c <= 71942)))
                : (c <= 71945 || (c < 71960
                  ? (c < 71957
                    ? (c >= 71948 && c <= 71955)
                    : c <= 71958)
                  : (c <= 71989 || (c < 71995
                    ? (c >= 71991 && c <= 71992)
                    : c <= 72003)))))
              : (c <= 72025 || (c < 72263
                ? (c < 72154
                  ? (c < 72106
                    ? (c >= 72096 && c <= 72103)
                    : c <= 72151)
                  : (c <= 72161 || (c < 72192
                    ? (c >= 72163 && c <= 72164)
                    : c <= 72254)))
                : (c <= 72263 || (c < 72368
                  ? (c < 72349
                    ? (c >= 72272 && c <= 72345)
                    : c <= 72349)
                  : (c <= 72440 || (c < 72714
                    ? (c >= 72704 && c <= 72712)
                    : c <= 72758)))))))
            : (c <= 72768 || (c < 73056
              ? (c < 72968
                ? (c < 72850
                  ? (c < 72818
                    ? (c >= 72784 && c <= 72793)
                    : c <= 72847)
                  : (c <= 72871 || (c < 72960
                    ? (c >= 72873 && c <= 72886)
                    : c <= 72966)))
                : (c <= 72969 || (c < 73020
                  ? (c < 73018
                    ? (c >= 72971 && c <= 73014)
                    : c <= 73018)
                  : (c <= 73021 || (c < 73040
                    ? (c >= 73023 && c <= 73031)
                    : c <= 73049)))))
              : (c <= 73061 || (c < 73440
                ? (c < 73104
                  ? (c < 73066
                    ? (c >= 73063 && c <= 73064)
                    : c <= 73102)
                  : (c <= 73105 || (c < 73120
                    ? (c >= 73107 && c <= 73112)
                    : c <= 73129)))
                : (c <= 73462 || (c < 74752
                  ? (c < 73728
                    ? c == 73648
                    : c <= 74649)
                  : (c <= 74862 || (c < 77712
                    ? (c >= 74880 && c <= 75075)
                    : c <= 77808)))))))))
          : (c <= 78894 || (c < 110576
            ? (c < 93027
              ? (c < 92864
                ? (c < 92736
                  ? (c < 92160
                    ? (c >= 82944 && c <= 83526)
                    : c <= 92728)
                  : (c <= 92766 || (c < 92784
                    ? (c >= 92768 && c <= 92777)
                    : c <= 92862)))
                : (c <= 92873 || (c < 92928
                  ? (c < 92912
                    ? (c >= 92880 && c <= 92909)
                    : c <= 92916)
                  : (c <= 92982 || (c < 93008
                    ? (c >= 92992 && c <= 92995)
                    : c <= 93017)))))
              : (c <= 93047 || (c < 94176
                ? (c < 93952
                  ? (c < 93760
                    ? (c >= 93053 && c <= 93071)
                    : c <= 93823)
                  : (c <= 94026 || (c < 94095
                    ? (c >= 94031 && c <= 94087)
                    : c <= 94111)))
                : (c <= 94177 || (c < 94208
                  ? (c < 94192
                    ? (c >= 94179 && c <= 94180)
                    : c <= 94193)
                  : (c <= 100343 || (c < 101632
                    ? (c >= 100352 && c <= 101589)
                    : c <= 101640)))))))
            : (c <= 110579 || (c < 118528
              ? (c < 110960
                ? (c < 110592
                  ? (c < 110589
                    ? (c >= 110581 && c <= 110587)
                    : c <= 110590)
                  : (c <= 110882 || (c < 110948
                    ? (c >= 110928 && c <= 110930)
                    : c <= 110951)))
                : (c <= 111355 || (c < 113792
                  ? (c < 113776
                    ? (c >= 113664 && c <= 113770)
                    : c <= 113788)
                  : (c <= 113800 || (c < 113821
                    ? (c >= 113808 && c <= 113817)
                    : c <= 113822)))))
              : (c <= 118573 || (c < 119210
                ? (c < 119149
                  ? (c < 119141
                    ? (c >= 118576 && c <= 118598)
                    : c <= 119145)
                  : (c <= 119154 || (c < 119173
                    ? (c >= 119163 && c <= 119170)
                    : c <= 119179)))
                : (c <= 119213 || (c < 119894
                  ? (c < 119808
                    ? (c >= 119362 && c <= 119364)
                    : c <= 119892)
                  : (c <= 119964 || (c < 119970
                    ? (c >= 119966 && c <= 119967)
                    : c <= 119970)))))))))))
        : (c <= 119974 || (c < 124912
          ? (c < 120746
            ? (c < 120134
              ? (c < 120071
                ? (c < 119995
                  ? (c < 119982
                    ? (c >= 119977 && c <= 119980)
                    : c <= 119993)
                  : (c <= 119995 || (c < 120005
                    ? (c >= 119997 && c <= 120003)
                    : c <= 120069)))
                : (c <= 120074 || (c < 120094
                  ? (c < 120086
                    ? (c >= 120077 && c <= 120084)
                    : c <= 120092)
                  : (c <= 120121 || (c < 120128
                    ? (c >= 120123 && c <= 120126)
                    : c <= 120132)))))
              : (c <= 120134 || (c < 120572
                ? (c < 120488
                  ? (c < 120146
                    ? (c >= 120138 && c <= 120144)
                    : c <= 120485)
                  : (c <= 120512 || (c < 120540
                    ? (c >= 120514 && c <= 120538)
                    : c <= 120570)))
                : (c <= 120596 || (c < 120656
                  ? (c < 120630
                    ? (c >= 120598 && c <= 120628)
                    : c <= 120654)
                  : (c <= 120686 || (c < 120714
                    ? (c >= 120688 && c <= 120712)
                    : c <= 120744)))))))
            : (c <= 120770 || (c < 122907
              ? (c < 121476
                ? (c < 121344
                  ? (c < 120782
                    ? (c >= 120772 && c <= 120779)
                    : c <= 120831)
                  : (c <= 121398 || (c < 121461
                    ? (c >= 121403 && c <= 121452)
                    : c <= 121461)))
                : (c <= 121476 || (c < 122624
                  ? (c < 121505
                    ? (c >= 121499 && c <= 121503)
                    : c <= 121519)
                  : (c <= 122654 || (c < 122888
                    ? (c >= 122880 && c <= 122886)
                    : c <= 122904)))))
              : (c <= 122913 || (c < 123214
                ? (c < 123136
                  ? (c < 122918
                    ? (c >= 122915 && c <= 122916)
                    : c <= 122922)
                  : (c <= 123180 || (c < 123200
                    ? (c >= 123184 && c <= 123197)
                    : c <= 123209)))
                : (c <= 123214 || (c < 124896
                  ? (c < 123584
                    ? (c >= 123536 && c <= 123566)
                    : c <= 123641)
                  : (c <= 124902 || (c < 124909
                    ? (c >= 124904 && c <= 124907)
                    : c <= 124910)))))))))
          : (c <= 124926 || (c < 126557
            ? (c < 126521
              ? (c < 126469
                ? (c < 125184
                  ? (c < 125136
                    ? (c >= 124928 && c <= 125124)
                    : c <= 125142)
                  : (c <= 125259 || (c < 126464
                    ? (c >= 125264 && c <= 125273)
                    : c <= 126467)))
                : (c <= 126495 || (c < 126503
                  ? (c < 126500
                    ? (c >= 126497 && c <= 126498)
                    : c <= 126500)
                  : (c <= 126503 || (c < 126516
                    ? (c >= 126505 && c <= 126514)
                    : c <= 126519)))))
              : (c <= 126521 || (c < 126541
                ? (c < 126535
                  ? (c < 126530
                    ? c == 126523
                    : c <= 126530)
                  : (c <= 126535 || (c < 126539
                    ? c == 126537
                    : c <= 126539)))
                : (c <= 126543 || (c < 126551
                  ? (c < 126548
                    ? (c >= 126545 && c <= 126546)
                    : c <= 126548)
                  : (c <= 126551 || (c < 126555
                    ? c == 126553
                    : c <= 126555)))))))
            : (c <= 126557 || (c < 126629
              ? (c < 126580
                ? (c < 126564
                  ? (c < 126561
                    ? c == 126559
                    : c <= 126562)
                  : (c <= 126564 || (c < 126572
                    ? (c >= 126567 && c <= 126570)
                    : c <= 126578)))
                : (c <= 126583 || (c < 126592
                  ? (c < 126590
                    ? (c >= 126585 && c <= 126588)
                    : c <= 126590)
                  : (c <= 126601 || (c < 126625
                    ? (c >= 126603 && c <= 126619)
                    : c <= 126627)))))
              : (c <= 126633 || (c < 178208
                ? (c < 131072
                  ? (c < 130032
                    ? (c >= 126635 && c <= 126651)
                    : c <= 130041)
                  : (c <= 173791 || (c < 177984
                    ? (c >= 173824 && c <= 177976)
                    : c <= 178205)))
                : (c <= 183969 || (c < 196608
                  ? (c < 194560
                    ? (c >= 183984 && c <= 191456)
                    : c <= 195101)
                  : (c <= 201546 || (c >= 917760 && c <= 917999)))))))))))))))));
}

static inline bool sym_identifier_character_set_1(int32_t c) {
  return (c < 43514
    ? (c < 4193
      ? (c < 2707
        ? (c < 1994
          ? (c < 931
            ? (c < 748
              ? (c < 192
                ? (c < 170
                  ? (c < 'a'
                    ? (c >= 'A' && c <= 'Z')
                    : c <= 'z')
                  : (c <= 170 || (c < 186
                    ? c == 181
                    : c <= 186)))
                : (c <= 214 || (c < 710
                  ? (c < 248
                    ? (c >= 216 && c <= 246)
                    : c <= 705)
                  : (c <= 721 || (c >= 736 && c <= 740)))))
              : (c <= 748 || (c < 895
                ? (c < 886
                  ? (c < 880
                    ? c == 750
                    : c <= 884)
                  : (c <= 887 || (c >= 891 && c <= 893)))
                : (c <= 895 || (c < 908
                  ? (c < 904
                    ? c == 902
                    : c <= 906)
                  : (c <= 908 || (c >= 910 && c <= 929)))))))
            : (c <= 1013 || (c < 1649
              ? (c < 1376
                ? (c < 1329
                  ? (c < 1162
                    ? (c >= 1015 && c <= 1153)
                    : c <= 1327)
                  : (c <= 1366 || c == 1369))
                : (c <= 1416 || (c < 1568
                  ? (c < 1519
                    ? (c >= 1488 && c <= 1514)
                    : c <= 1522)
                  : (c <= 1610 || (c >= 1646 && c <= 1647)))))
              : (c <= 1747 || (c < 1791
                ? (c < 1774
                  ? (c < 1765
                    ? c == 1749
                    : c <= 1766)
                  : (c <= 1775 || (c >= 1786 && c <= 1788)))
                : (c <= 1791 || (c < 1869
                  ? (c < 1810
                    ? c == 1808
                    : c <= 1839)
                  : (c <= 1957 || c == 1969))))))))
          : (c <= 2026 || (c < 2482
            ? (c < 2208
              ? (c < 2088
                ? (c < 2048
                  ? (c < 2042
                    ? (c >= 2036 && c <= 2037)
                    : c <= 2042)
                  : (c <= 2069 || (c < 2084
                    ? c == 2074
                    : c <= 2084)))
                : (c <= 2088 || (c < 2160
                  ? (c < 2144
                    ? (c >= 2112 && c <= 2136)
                    : c <= 2154)
                  : (c <= 2183 || (c >= 2185 && c <= 2190)))))
              : (c <= 2249 || (c < 2417
                ? (c < 2384
                  ? (c < 2365
                    ? (c >= 2308 && c <= 2361)
                    : c <= 2365)
                  : (c <= 2384 || (c >= 2392 && c <= 2401)))
                : (c <= 2432 || (c < 2451
                  ? (c < 2447
                    ? (c >= 2437 && c <= 2444)
                    : c <= 2448)
                  : (c <= 2472 || (c >= 2474 && c <= 2480)))))))
            : (c <= 2482 || (c < 2579
              ? (c < 2527
                ? (c < 2510
                  ? (c < 2493
                    ? (c >= 2486 && c <= 2489)
                    : c <= 2493)
                  : (c <= 2510 || (c >= 2524 && c <= 2525)))
                : (c <= 2529 || (c < 2565
                  ? (c < 2556
                    ? (c >= 2544 && c <= 2545)
                    : c <= 2556)
                  : (c <= 2570 || (c >= 2575 && c <= 2576)))))
              : (c <= 2600 || (c < 2649
                ? (c < 2613
                  ? (c < 2610
                    ? (c >= 2602 && c <= 2608)
                    : c <= 2611)
                  : (c <= 2614 || (c >= 2616 && c <= 2617)))
                : (c <= 2652 || (c < 2693
                  ? (c < 2674
                    ? c == 2654
                    : c <= 2676)
                  : (c <= 2701 || (c >= 2703 && c <= 2705)))))))))))
        : (c <= 2728 || (c < 3242
          ? (c < 2962
            ? (c < 2858
              ? (c < 2784
                ? (c < 2741
                  ? (c < 2738
                    ? (c >= 2730 && c <= 2736)
                    : c <= 2739)
                  : (c <= 2745 || (c < 2768
                    ? c == 2749
                    : c <= 2768)))
                : (c <= 2785 || (c < 2831
                  ? (c < 2821
                    ? c == 2809
                    : c <= 2828)
                  : (c <= 2832 || (c >= 2835 && c <= 2856)))))
              : (c <= 2864 || (c < 2911
                ? (c < 2877
                  ? (c < 2869
                    ? (c >= 2866 && c <= 2867)
                    : c <= 2873)
                  : (c <= 2877 || (c >= 2908 && c <= 2909)))
                : (c <= 2913 || (c < 2949
                  ? (c < 2947
                    ? c == 2929
                    : c <= 2947)
                  : (c <= 2954 || (c >= 2958 && c <= 2960)))))))
            : (c <= 2965 || (c < 3090
              ? (c < 2984
                ? (c < 2974
                  ? (c < 2972
                    ? (c >= 2969 && c <= 2970)
                    : c <= 2972)
                  : (c <= 2975 || (c >= 2979 && c <= 2980)))
                : (c <= 2986 || (c < 3077
                  ? (c < 3024
                    ? (c >= 2990 && c <= 3001)
                    : c <= 3024)
                  : (c <= 3084 || (c >= 3086 && c <= 3088)))))
              : (c <= 3112 || (c < 3168
                ? (c < 3160
                  ? (c < 3133
                    ? (c >= 3114 && c <= 3129)
                    : c <= 3133)
                  : (c <= 3162 || c == 3165))
                : (c <= 3169 || (c < 3214
                  ? (c < 3205
                    ? c == 3200
                    : c <= 3212)
                  : (c <= 3216 || (c >= 3218 && c <= 3240)))))))))
          : (c <= 3251 || (c < 3648
            ? (c < 3412
              ? (c < 3332
                ? (c < 3293
                  ? (c < 3261
                    ? (c >= 3253 && c <= 3257)
                    : c <= 3261)
                  : (c <= 3294 || (c < 3313
                    ? (c >= 3296 && c <= 3297)
                    : c <= 3314)))
                : (c <= 3340 || (c < 3389
                  ? (c < 3346
                    ? (c >= 3342 && c <= 3344)
                    : c <= 3386)
                  : (c <= 3389 || c == 3406))))
              : (c <= 3414 || (c < 3507
                ? (c < 3461
                  ? (c < 3450
                    ? (c >= 3423 && c <= 3425)
                    : c <= 3455)
                  : (c <= 3478 || (c >= 3482 && c <= 3505)))
                : (c <= 3515 || (c < 3585
                  ? (c < 3520
                    ? c == 3517
                    : c <= 3526)
                  : (c <= 3632 || c == 3634))))))
            : (c <= 3654 || (c < 3782
              ? (c < 3749
                ? (c < 3718
                  ? (c < 3716
                    ? (c >= 3713 && c <= 3714)
                    : c <= 3716)
                  : (c <= 3722 || (c >= 3724 && c <= 3747)))
                : (c <= 3749 || (c < 3773
                  ? (c < 3762
                    ? (c >= 3751 && c <= 3760)
                    : c <= 3762)
                  : (c <= 3773 || (c >= 3776 && c <= 3780)))))
              : (c <= 3782 || (c < 3976
                ? (c < 3904
                  ? (c < 3840
                    ? (c >= 3804 && c <= 3807)
                    : c <= 3840)
                  : (c <= 3911 || (c >= 3913 && c <= 3948)))
                : (c <= 3980 || (c < 4176
                  ? (c < 4159
                    ? (c >= 4096 && c <= 4138)
                    : c <= 4159)
                  : (c <= 4181 || (c >= 4186 && c <= 4189)))))))))))))
      : (c <= 4193 || (c < 8134
        ? (c < 6176
          ? (c < 4808
            ? (c < 4688
              ? (c < 4295
                ? (c < 4213
                  ? (c < 4206
                    ? (c >= 4197 && c <= 4198)
                    : c <= 4208)
                  : (c <= 4225 || (c < 4256
                    ? c == 4238
                    : c <= 4293)))
                : (c <= 4295 || (c < 4348
                  ? (c < 4304
                    ? c == 4301
                    : c <= 4346)
                  : (c <= 4680 || (c >= 4682 && c <= 4685)))))
              : (c <= 4694 || (c < 4752
                ? (c < 4704
                  ? (c < 4698
                    ? c == 4696
                    : c <= 4701)
                  : (c <= 4744 || (c >= 4746 && c <= 4749)))
                : (c <= 4784 || (c < 4800
                  ? (c < 4792
                    ? (c >= 4786 && c <= 4789)
                    : c <= 4798)
                  : (c <= 4800 || (c >= 4802 && c <= 4805)))))))
            : (c <= 4822 || (c < 5792
              ? (c < 5024
                ? (c < 4888
                  ? (c < 4882
                    ? (c >= 4824 && c <= 4880)
                    : c <= 4885)
                  : (c <= 4954 || (c >= 4992 && c <= 5007)))
                : (c <= 5109 || (c < 5743
                  ? (c < 5121
                    ? (c >= 5112 && c <= 5117)
                    : c <= 5740)
                  : (c <= 5759 || (c >= 5761 && c <= 5786)))))
              : (c <= 5866 || (c < 5984
                ? (c < 5919
                  ? (c < 5888
                    ? (c >= 5870 && c <= 5880)
                    : c <= 5905)
                  : (c <= 5937 || (c >= 5952 && c <= 5969)))
                : (c <= 5996 || (c < 6103
                  ? (c < 6016
                    ? (c >= 5998 && c <= 6000)
                    : c <= 6067)
                  : (c <= 6103 || c == 6108))))))))
          : (c <= 6264 || (c < 7312
            ? (c < 6823
              ? (c < 6512
                ? (c < 6320
                  ? (c < 6314
                    ? (c >= 6272 && c <= 6312)
                    : c <= 6314)
                  : (c <= 6389 || (c < 6480
                    ? (c >= 6400 && c <= 6430)
                    : c <= 6509)))
                : (c <= 6516 || (c < 6656
                  ? (c < 6576
                    ? (c >= 6528 && c <= 6571)
                    : c <= 6601)
                  : (c <= 6678 || (c >= 6688 && c <= 6740)))))
              : (c <= 6823 || (c < 7098
                ? (c < 7043
                  ? (c < 6981
                    ? (c >= 6917 && c <= 6963)
                    : c <= 6988)
                  : (c <= 7072 || (c >= 7086 && c <= 7087)))
                : (c <= 7141 || (c < 7258
                  ? (c < 7245
                    ? (c >= 7168 && c <= 7203)
                    : c <= 7247)
                  : (c <= 7293 || (c >= 7296 && c <= 7304)))))))
            : (c <= 7354 || (c < 8008
              ? (c < 7418
                ? (c < 7406
                  ? (c < 7401
                    ? (c >= 7357 && c <= 7359)
                    : c <= 7404)
                  : (c <= 7411 || (c >= 7413 && c <= 7414)))
                : (c <= 7418 || (c < 7960
                  ? (c < 7680
                    ? (c >= 7424 && c <= 7615)
                    : c <= 7957)
                  : (c <= 7965 || (c >= 7968 && c <= 8005)))))
              : (c <= 8013 || (c < 8031
                ? (c < 8027
                  ? (c < 8025
                    ? (c >= 8016 && c <= 8023)
                    : c <= 8025)
                  : (c <= 8027 || c == 8029))
                : (c <= 8061 || (c < 8126
                  ? (c < 8118
                    ? (c >= 8064 && c <= 8116)
                    : c <= 8124)
                  : (c <= 8126 || (c >= 8130 && c <= 8132)))))))))))
        : (c <= 8140 || (c < 12337
          ? (c < 8544
            ? (c < 8458
              ? (c < 8305
                ? (c < 8160
                  ? (c < 8150
                    ? (c >= 8144 && c <= 8147)
                    : c <= 8155)
                  : (c <= 8172 || (c < 8182
                    ? (c >= 8178 && c <= 8180)
                    : c <= 8188)))
                : (c <= 8305 || (c < 8450
                  ? (c < 8336
                    ? c == 8319
                    : c <= 8348)
                  : (c <= 8450 || c == 8455))))
              : (c <= 8467 || (c < 8488
                ? (c < 8484
                  ? (c < 8472
                    ? c == 8469
                    : c <= 8477)
                  : (c <= 8484 || c == 8486))
                : (c <= 8488 || (c < 8517
                  ? (c < 8508
                    ? (c >= 8490 && c <= 8505)
                    : c <= 8511)
                  : (c <= 8521 || c == 8526))))))
            : (c <= 8584 || (c < 11680
              ? (c < 11559
                ? (c < 11506
                  ? (c < 11499
                    ? (c >= 11264 && c <= 11492)
                    : c <= 11502)
                  : (c <= 11507 || (c >= 11520 && c <= 11557)))
                : (c <= 11559 || (c < 11631
                  ? (c < 11568
                    ? c == 11565
                    : c <= 11623)
                  : (c <= 11631 || (c >= 11648 && c <= 11670)))))
              : (c <= 11686 || (c < 11720
                ? (c < 11704
                  ? (c < 11696
                    ? (c >= 11688 && c <= 11694)
                    : c <= 11702)
                  : (c <= 11710 || (c >= 11712 && c <= 11718)))
                : (c <= 11726 || (c < 12293
                  ? (c < 11736
                    ? (c >= 11728 && c <= 11734)
                    : c <= 11742)
                  : (c <= 12295 || (c >= 12321 && c <= 12329)))))))))
          : (c <= 12341 || (c < 42891
            ? (c < 19968
              ? (c < 12549
                ? (c < 12445
                  ? (c < 12353
                    ? (c >= 12344 && c <= 12348)
                    : c <= 12438)
                  : (c <= 12447 || (c < 12540
                    ? (c >= 12449 && c <= 12538)
                    : c <= 12543)))
                : (c <= 12591 || (c < 12784
                  ? (c < 12704
                    ? (c >= 12593 && c <= 12686)
                    : c <= 12735)
                  : (c <= 12799 || (c >= 13312 && c <= 19903)))))
              : (c <= 42124 || (c < 42560
                ? (c < 42512
                  ? (c < 42240
                    ? (c >= 42192 && c <= 42237)
                    : c <= 42508)
                  : (c <= 42527 || (c >= 42538 && c <= 42539)))
                : (c <= 42606 || (c < 42775
                  ? (c < 42656
                    ? (c >= 42623 && c <= 42653)
                    : c <= 42735)
                  : (c <= 42783 || (c >= 42786 && c <= 42888)))))))
            : (c <= 42954 || (c < 43250
              ? (c < 43011
                ? (c < 42965
                  ? (c < 42963
                    ? (c >= 42960 && c <= 42961)
                    : c <= 42963)
                  : (c <= 42969 || (c >= 42994 && c <= 43009)))
                : (c <= 43013 || (c < 43072
                  ? (c < 43020
                    ? (c >= 43015 && c <= 43018)
                    : c <= 43042)
                  : (c <= 43123 || (c >= 43138 && c <= 43187)))))
              : (c <= 43255 || (c < 43360
                ? (c < 43274
                  ? (c < 43261
                    ? c == 43259
                    : c <= 43262)
                  : (c <= 43301 || (c >= 43312 && c <= 43334)))
                : (c <= 43388 || (c < 43488
                  ? (c < 43471
                    ? (c >= 43396 && c <= 43442)
                    : c <= 43471)
                  : (c <= 43492 || (c >= 43494 && c <= 43503)))))))))))))))
    : (c <= 43518 || (c < 70727
      ? (c < 66956
        ? (c < 64914
          ? (c < 43868
            ? (c < 43714
              ? (c < 43646
                ? (c < 43588
                  ? (c < 43584
                    ? (c >= 43520 && c <= 43560)
                    : c <= 43586)
                  : (c <= 43595 || (c < 43642
                    ? (c >= 43616 && c <= 43638)
                    : c <= 43642)))
                : (c <= 43695 || (c < 43705
                  ? (c < 43701
                    ? c == 43697
                    : c <= 43702)
                  : (c <= 43709 || c == 43712))))
              : (c <= 43714 || (c < 43785
                ? (c < 43762
                  ? (c < 43744
                    ? (c >= 43739 && c <= 43741)
                    : c <= 43754)
                  : (c <= 43764 || (c >= 43777 && c <= 43782)))
                : (c <= 43790 || (c < 43816
                  ? (c < 43808
                    ? (c >= 43793 && c <= 43798)
                    : c <= 43814)
                  : (c <= 43822 || (c >= 43824 && c <= 43866)))))))
            : (c <= 43881 || (c < 64287
              ? (c < 63744
                ? (c < 55216
                  ? (c < 44032
                    ? (c >= 43888 && c <= 44002)
                    : c <= 55203)
                  : (c <= 55238 || (c >= 55243 && c <= 55291)))
                : (c <= 64109 || (c < 64275
                  ? (c < 64256
                    ? (c >= 64112 && c <= 64217)
                    : c <= 64262)
                  : (c <= 64279 || c == 64285))))
              : (c <= 64296 || (c < 64323
                ? (c < 64318
                  ? (c < 64312
                    ? (c >= 64298 && c <= 64310)
                    : c <= 64316)
                  : (c <= 64318 || (c >= 64320 && c <= 64321)))
                : (c <= 64324 || (c < 64612
                  ? (c < 64467
                    ? (c >= 64326 && c <= 64433)
                    : c <= 64605)
                  : (c <= 64829 || (c >= 64848 && c <= 64911)))))))))
          : (c <= 64967 || (c < 65599
            ? (c < 65382
              ? (c < 65147
                ? (c < 65139
                  ? (c < 65137
                    ? (c >= 65008 && c <= 65017)
                    : c <= 65137)
                  : (c <= 65139 || (c < 65145
                    ? c == 65143
                    : c <= 65145)))
                : (c <= 65147 || (c < 65313
                  ? (c < 65151
                    ? c == 65149
                    : c <= 65276)
                  : (c <= 65338 || (c >= 65345 && c <= 65370)))))
              : (c <= 65437 || (c < 65498
                ? (c < 65482
                  ? (c < 65474
                    ? (c >= 65440 && c <= 65470)
                    : c <= 65479)
                  : (c <= 65487 || (c >= 65490 && c <= 65495)))
                : (c <= 65500 || (c < 65576
                  ? (c < 65549
                    ? (c >= 65536 && c <= 65547)
                    : c <= 65574)
                  : (c <= 65594 || (c >= 65596 && c <= 65597)))))))
            : (c <= 65613 || (c < 66464
              ? (c < 66208
                ? (c < 65856
                  ? (c < 65664
                    ? (c >= 65616 && c <= 65629)
                    : c <= 65786)
                  : (c <= 65908 || (c >= 66176 && c <= 66204)))
                : (c <= 66256 || (c < 66384
                  ? (c < 66349
                    ? (c >= 66304 && c <= 66335)
                    : c <= 66378)
                  : (c <= 66421 || (c >= 66432 && c <= 66461)))))
              : (c <= 66499 || (c < 66776
                ? (c < 66560
                  ? (c < 66513
                    ? (c >= 66504 && c <= 66511)
                    : c <= 66517)
                  : (c <= 66717 || (c >= 66736 && c <= 66771)))
                : (c <= 66811 || (c < 66928
                  ? (c < 66864
                    ? (c >= 66816 && c <= 66855)
                    : c <= 66915)
                  : (c <= 66938 || (c >= 66940 && c <= 66954)))))))))))
        : (c <= 66962 || (c < 68864
          ? (c < 67828
            ? (c < 67506
              ? (c < 67072
                ? (c < 66979
                  ? (c < 66967
                    ? (c >= 66964 && c <= 66965)
                    : c <= 66977)
                  : (c <= 66993 || (c < 67003
                    ? (c >= 66995 && c <= 67001)
                    : c <= 67004)))
                : (c <= 67382 || (c < 67456
                  ? (c < 67424
                    ? (c >= 67392 && c <= 67413)
                    : c <= 67431)
                  : (c <= 67461 || (c >= 67463 && c <= 67504)))))
              : (c <= 67514 || (c < 67644
                ? (c < 67594
                  ? (c < 67592
                    ? (c >= 67584 && c <= 67589)
                    : c <= 67592)
                  : (c <= 67637 || (c >= 67639 && c <= 67640)))
                : (c <= 67644 || (c < 67712
                  ? (c < 67680
                    ? (c >= 67647 && c <= 67669)
                    : c <= 67702)
                  : (c <= 67742 || (c >= 67808 && c <= 67826)))))))
            : (c <= 67829 || (c < 68224
              ? (c < 68096
                ? (c < 67968
                  ? (c < 67872
                    ? (c >= 67840 && c <= 67861)
                    : c <= 67897)
                  : (c <= 68023 || (c >= 68030 && c <= 68031)))
                : (c <= 68096 || (c < 68121
                  ? (c < 68117
                    ? (c >= 68112 && c <= 68115)
                    : c <= 68119)
                  : (c <= 68149 || (c >= 68192 && c <= 68220)))))
              : (c <= 68252 || (c < 68448
                ? (c < 68352
                  ? (c < 68297
                    ? (c >= 68288 && c <= 68295)
                    : c <= 68324)
                  : (c <= 68405 || (c >= 68416 && c <= 68437)))
                : (c <= 68466 || (c < 68736
                  ? (c < 68608
                    ? (c >= 68480 && c <= 68497)
                    : c <= 68680)
                  : (c <= 68786 || (c >= 68800 && c <= 68850)))))))))
          : (c <= 68899 || (c < 70106
            ? (c < 69749
              ? (c < 69488
                ? (c < 69376
                  ? (c < 69296
                    ? (c >= 69248 && c <= 69289)
                    : c <= 69297)
                  : (c <= 69404 || (c < 69424
                    ? c == 69415
                    : c <= 69445)))
                : (c <= 69505 || (c < 69635
                  ? (c < 69600
                    ? (c >= 69552 && c <= 69572)
                    : c <= 69622)
                  : (c <= 69687 || (c >= 69745 && c <= 69746)))))
              : (c <= 69749 || (c < 69959
                ? (c < 69891
                  ? (c < 69840
                    ? (c >= 69763 && c <= 69807)
                    : c <= 69864)
                  : (c <= 69926 || c == 69956))
                : (c <= 69959 || (c < 70019
                  ? (c < 70006
                    ? (c >= 69968 && c <= 70002)
                    : c <= 70006)
                  : (c <= 70066 || (c >= 70081 && c <= 70084)))))))
            : (c <= 70106 || (c < 70405
              ? (c < 70280
                ? (c < 70163
                  ? (c < 70144
                    ? c == 70108
                    : c <= 70161)
                  : (c <= 70187 || (c >= 70272 && c <= 70278)))
                : (c <= 70280 || (c < 70303
                  ? (c < 70287
                    ? (c >= 70282 && c <= 70285)
                    : c <= 70301)
                  : (c <= 70312 || (c >= 70320 && c <= 70366)))))
              : (c <= 70412 || (c < 70453
                ? (c < 70442
                  ? (c < 70419
                    ? (c >= 70415 && c <= 70416)
                    : c <= 70440)
                  : (c <= 70448 || (c >= 70450 && c <= 70451)))
                : (c <= 70457 || (c < 70493
                  ? (c < 70480
                    ? c == 70461
                    : c <= 70480)
                  : (c <= 70497 || (c >= 70656 && c <= 70708)))))))))))))
      : (c <= 70730 || (c < 119894
        ? (c < 73056
          ? (c < 72001
            ? (c < 71424
              ? (c < 71128
                ? (c < 70852
                  ? (c < 70784
                    ? (c >= 70751 && c <= 70753)
                    : c <= 70831)
                  : (c <= 70853 || (c < 71040
                    ? c == 70855
                    : c <= 71086)))
                : (c <= 71131 || (c < 71296
                  ? (c < 71236
                    ? (c >= 71168 && c <= 71215)
                    : c <= 71236)
                  : (c <= 71338 || c == 71352))))
              : (c <= 71450 || (c < 71945
                ? (c < 71840
                  ? (c < 71680
                    ? (c >= 71488 && c <= 71494)
                    : c <= 71723)
                  : (c <= 71903 || (c >= 71935 && c <= 71942)))
                : (c <= 71945 || (c < 71960
                  ? (c < 71957
                    ? (c >= 71948 && c <= 71955)
                    : c <= 71958)
                  : (c <= 71983 || c == 71999))))))
            : (c <= 72001 || (c < 72349
              ? (c < 72192
                ? (c < 72161
                  ? (c < 72106
                    ? (c >= 72096 && c <= 72103)
                    : c <= 72144)
                  : (c <= 72161 || c == 72163))
                : (c <= 72192 || (c < 72272
                  ? (c < 72250
                    ? (c >= 72203 && c <= 72242)
                    : c <= 72250)
                  : (c <= 72272 || (c >= 72284 && c <= 72329)))))
              : (c <= 72349 || (c < 72818
                ? (c < 72714
                  ? (c < 72704
                    ? (c >= 72368 && c <= 72440)
                    : c <= 72712)
                  : (c <= 72750 || c == 72768))
                : (c <= 72847 || (c < 72971
                  ? (c < 72968
                    ? (c >= 72960 && c <= 72966)
                    : c <= 72969)
                  : (c <= 73008 || c == 73030))))))))
          : (c <= 73061 || (c < 93952
            ? (c < 82944
              ? (c < 73728
                ? (c < 73112
                  ? (c < 73066
                    ? (c >= 73063 && c <= 73064)
                    : c <= 73097)
                  : (c <= 73112 || (c < 73648
                    ? (c >= 73440 && c <= 73458)
                    : c <= 73648)))
                : (c <= 74649 || (c < 77712
                  ? (c < 74880
                    ? (c >= 74752 && c <= 74862)
                    : c <= 75075)
                  : (c <= 77808 || (c >= 77824 && c <= 78894)))))
              : (c <= 83526 || (c < 92928
                ? (c < 92784
                  ? (c < 92736
                    ? (c >= 92160 && c <= 92728)
                    : c <= 92766)
                  : (c <= 92862 || (c >= 92880 && c <= 92909)))
                : (c <= 92975 || (c < 93053
                  ? (c < 93027
                    ? (c >= 92992 && c <= 92995)
                    : c <= 93047)
                  : (c <= 93071 || (c >= 93760 && c <= 93823)))))))
            : (c <= 94026 || (c < 110589
              ? (c < 94208
                ? (c < 94176
                  ? (c < 94099
                    ? c == 94032
                    : c <= 94111)
                  : (c <= 94177 || c == 94179))
                : (c <= 100343 || (c < 110576
                  ? (c < 101632
                    ? (c >= 100352 && c <= 101589)
                    : c <= 101640)
                  : (c <= 110579 || (c >= 110581 && c <= 110587)))))
              : (c <= 110590 || (c < 113664
                ? (c < 110948
                  ? (c < 110928
                    ? (c >= 110592 && c <= 110882)
                    : c <= 110930)
                  : (c <= 110951 || (c >= 110960 && c <= 111355)))
                : (c <= 113770 || (c < 113808
                  ? (c < 113792
                    ? (c >= 113776 && c <= 113788)
                    : c <= 113800)
                  : (c <= 113817 || (c >= 119808 && c <= 119892)))))))))))
        : (c <= 119964 || (c < 125259
          ? (c < 120572
            ? (c < 120086
              ? (c < 119995
                ? (c < 119973
                  ? (c < 119970
                    ? (c >= 119966 && c <= 119967)
                    : c <= 119970)
                  : (c <= 119974 || (c < 119982
                    ? (c >= 119977 && c <= 119980)
                    : c <= 119993)))
                : (c <= 119995 || (c < 120071
                  ? (c < 120005
                    ? (c >= 119997 && c <= 120003)
                    : c <= 120069)
                  : (c <= 120074 || (c >= 120077 && c <= 120084)))))
              : (c <= 120092 || (c < 120138
                ? (c < 120128
                  ? (c < 120123
                    ? (c >= 120094 && c <= 120121)
                    : c <= 120126)
                  : (c <= 120132 || c == 120134))
                : (c <= 120144 || (c < 120514
                  ? (c < 120488
                    ? (c >= 120146 && c <= 120485)
                    : c <= 120512)
                  : (c <= 120538 || (c >= 120540 && c <= 120570)))))))
            : (c <= 120596 || (c < 123191
              ? (c < 120714
                ? (c < 120656
                  ? (c < 120630
                    ? (c >= 120598 && c <= 120628)
                    : c <= 120654)
                  : (c <= 120686 || (c >= 120688 && c <= 120712)))
                : (c <= 120744 || (c < 122624
                  ? (c < 120772
                    ? (c >= 120746 && c <= 120770)
                    : c <= 120779)
                  : (c <= 122654 || (c >= 123136 && c <= 123180)))))
              : (c <= 123197 || (c < 124904
                ? (c < 123584
                  ? (c < 123536
                    ? c == 123214
                    : c <= 123565)
                  : (c <= 123627 || (c >= 124896 && c <= 124902)))
                : (c <= 124907 || (c < 124928
                  ? (c < 124912
                    ? (c >= 124909 && c <= 124910)
                    : c <= 124926)
                  : (c <= 125124 || (c >= 125184 && c <= 125251)))))))))
          : (c <= 125259 || (c < 126559
            ? (c < 126535
              ? (c < 126505
                ? (c < 126497
                  ? (c < 126469
                    ? (c >= 126464 && c <= 126467)
                    : c <= 126495)
                  : (c <= 126498 || (c < 126503
                    ? c == 126500
                    : c <= 126503)))
                : (c <= 126514 || (c < 126523
                  ? (c < 126521
                    ? (c >= 126516 && c <= 126519)
                    : c <= 126521)
                  : (c <= 126523 || c == 126530))))
              : (c <= 126535 || (c < 126548
                ? (c < 126541
                  ? (c < 126539
                    ? c == 126537
                    : c <= 126539)
                  : (c <= 126543 || (c >= 126545 && c <= 126546)))
                : (c <= 126548 || (c < 126555
                  ? (c < 126553
                    ? c == 126551
                    : c <= 126553)
                  : (c <= 126555 || c == 126557))))))
            : (c <= 126559 || (c < 126625
              ? (c < 126580
                ? (c < 126567
                  ? (c < 126564
                    ? (c >= 126561 && c <= 126562)
                    : c <= 126564)
                  : (c <= 126570 || (c >= 126572 && c <= 126578)))
                : (c <= 126583 || (c < 126592
                  ? (c < 126590
                    ? (c >= 126585 && c <= 126588)
                    : c <= 126590)
                  : (c <= 126601 || (c >= 126603 && c <= 126619)))))
              : (c <= 126627 || (c < 177984
                ? (c < 131072
                  ? (c < 126635
                    ? (c >= 126629 && c <= 126633)
                    : c <= 126651)
                  : (c <= 173791 || (c >= 173824 && c <= 177976)))
                : (c <= 178205 || (c < 194560
                  ? (c < 183984
                    ? (c >= 178208 && c <= 183969)
                    : c <= 191456)
                  : (c <= 195101 || (c >= 196608 && c <= 201546)))))))))))))))));
}

static inline bool sym_dot_identifier_character_set_1(int32_t c) {
  return (c < 43514
    ? (c < 4193
      ? (c < 2707
        ? (c < 1994
          ? (c < 910
            ? (c < 736
              ? (c < 186
                ? (c < 'a'
                  ? (c < '_'
                    ? (c >= 'A' && c <= 'Z')
                    : c <= '_')
                  : (c <= 'z' || (c < 181
                    ? c == 170
                    : c <= 181)))
                : (c <= 186 || (c < 248
                  ? (c < 216
                    ? (c >= 192 && c <= 214)
                    : c <= 246)
                  : (c <= 705 || (c >= 710 && c <= 721)))))
              : (c <= 740 || (c < 891
                ? (c < 880
                  ? (c < 750
                    ? c == 748
                    : c <= 750)
                  : (c <= 884 || (c >= 886 && c <= 887)))
                : (c <= 893 || (c < 904
                  ? (c < 902
                    ? c == 895
                    : c <= 902)
                  : (c <= 906 || c == 908))))))
            : (c <= 929 || (c < 1649
              ? (c < 1376
                ? (c < 1162
                  ? (c < 1015
                    ? (c >= 931 && c <= 1013)
                    : c <= 1153)
                  : (c <= 1327 || (c < 1369
                    ? (c >= 1329 && c <= 1366)
                    : c <= 1369)))
                : (c <= 1416 || (c < 1568
                  ? (c < 1519
                    ? (c >= 1488 && c <= 1514)
                    : c <= 1522)
                  : (c <= 1610 || (c >= 1646 && c <= 1647)))))
              : (c <= 1747 || (c < 1791
                ? (c < 1774
                  ? (c < 1765
                    ? c == 1749
                    : c <= 1766)
                  : (c <= 1775 || (c >= 1786 && c <= 1788)))
                : (c <= 1791 || (c < 1869
                  ? (c < 1810
                    ? c == 1808
                    : c <= 1839)
                  : (c <= 1957 || c == 1969))))))))
          : (c <= 2026 || (c < 2482
            ? (c < 2208
              ? (c < 2088
                ? (c < 2048
                  ? (c < 2042
                    ? (c >= 2036 && c <= 2037)
                    : c <= 2042)
                  : (c <= 2069 || (c < 2084
                    ? c == 2074
                    : c <= 2084)))
                : (c <= 2088 || (c < 2160
                  ? (c < 2144
                    ? (c >= 2112 && c <= 2136)
                    : c <= 2154)
                  : (c <= 2183 || (c >= 2185 && c <= 2190)))))
              : (c <= 2249 || (c < 2417
                ? (c < 2384
                  ? (c < 2365
                    ? (c >= 2308 && c <= 2361)
                    : c <= 2365)
                  : (c <= 2384 || (c >= 2392 && c <= 2401)))
                : (c <= 2432 || (c < 2451
                  ? (c < 2447
                    ? (c >= 2437 && c <= 2444)
                    : c <= 2448)
                  : (c <= 2472 || (c >= 2474 && c <= 2480)))))))
            : (c <= 2482 || (c < 2579
              ? (c < 2527
                ? (c < 2510
                  ? (c < 2493
                    ? (c >= 2486 && c <= 2489)
                    : c <= 2493)
                  : (c <= 2510 || (c >= 2524 && c <= 2525)))
                : (c <= 2529 || (c < 2565
                  ? (c < 2556
                    ? (c >= 2544 && c <= 2545)
                    : c <= 2556)
                  : (c <= 2570 || (c >= 2575 && c <= 2576)))))
              : (c <= 2600 || (c < 2649
                ? (c < 2613
                  ? (c < 2610
                    ? (c >= 2602 && c <= 2608)
                    : c <= 2611)
                  : (c <= 2614 || (c >= 2616 && c <= 2617)))
                : (c <= 2652 || (c < 2693
                  ? (c < 2674
                    ? c == 2654
                    : c <= 2676)
                  : (c <= 2701 || (c >= 2703 && c <= 2705)))))))))))
        : (c <= 2728 || (c < 3242
          ? (c < 2962
            ? (c < 2858
              ? (c < 2784
                ? (c < 2741
                  ? (c < 2738
                    ? (c >= 2730 && c <= 2736)
                    : c <= 2739)
                  : (c <= 2745 || (c < 2768
                    ? c == 2749
                    : c <= 2768)))
                : (c <= 2785 || (c < 2831
                  ? (c < 2821
                    ? c == 2809
                    : c <= 2828)
                  : (c <= 2832 || (c >= 2835 && c <= 2856)))))
              : (c <= 2864 || (c < 2911
                ? (c < 2877
                  ? (c < 2869
                    ? (c >= 2866 && c <= 2867)
                    : c <= 2873)
                  : (c <= 2877 || (c >= 2908 && c <= 2909)))
                : (c <= 2913 || (c < 2949
                  ? (c < 2947
                    ? c == 2929
                    : c <= 2947)
                  : (c <= 2954 || (c >= 2958 && c <= 2960)))))))
            : (c <= 2965 || (c < 3090
              ? (c < 2984
                ? (c < 2974
                  ? (c < 2972
                    ? (c >= 2969 && c <= 2970)
                    : c <= 2972)
                  : (c <= 2975 || (c >= 2979 && c <= 2980)))
                : (c <= 2986 || (c < 3077
                  ? (c < 3024
                    ? (c >= 2990 && c <= 3001)
                    : c <= 3024)
                  : (c <= 3084 || (c >= 3086 && c <= 3088)))))
              : (c <= 3112 || (c < 3168
                ? (c < 3160
                  ? (c < 3133
                    ? (c >= 3114 && c <= 3129)
                    : c <= 3133)
                  : (c <= 3162 || c == 3165))
                : (c <= 3169 || (c < 3214
                  ? (c < 3205
                    ? c == 3200
                    : c <= 3212)
                  : (c <= 3216 || (c >= 3218 && c <= 3240)))))))))
          : (c <= 3251 || (c < 3648
            ? (c < 3412
              ? (c < 3332
                ? (c < 3293
                  ? (c < 3261
                    ? (c >= 3253 && c <= 3257)
                    : c <= 3261)
                  : (c <= 3294 || (c < 3313
                    ? (c >= 3296 && c <= 3297)
                    : c <= 3314)))
                : (c <= 3340 || (c < 3389
                  ? (c < 3346
                    ? (c >= 3342 && c <= 3344)
                    : c <= 3386)
                  : (c <= 3389 || c == 3406))))
              : (c <= 3414 || (c < 3507
                ? (c < 3461
                  ? (c < 3450
                    ? (c >= 3423 && c <= 3425)
                    : c <= 3455)
                  : (c <= 3478 || (c >= 3482 && c <= 3505)))
                : (c <= 3515 || (c < 3585
                  ? (c < 3520
                    ? c == 3517
                    : c <= 3526)
                  : (c <= 3632 || c == 3634))))))
            : (c <= 3654 || (c < 3782
              ? (c < 3749
                ? (c < 3718
                  ? (c < 3716
                    ? (c >= 3713 && c <= 3714)
                    : c <= 3716)
                  : (c <= 3722 || (c >= 3724 && c <= 3747)))
                : (c <= 3749 || (c < 3773
                  ? (c < 3762
                    ? (c >= 3751 && c <= 3760)
                    : c <= 3762)
                  : (c <= 3773 || (c >= 3776 && c <= 3780)))))
              : (c <= 3782 || (c < 3976
                ? (c < 3904
                  ? (c < 3840
                    ? (c >= 3804 && c <= 3807)
                    : c <= 3840)
                  : (c <= 3911 || (c >= 3913 && c <= 3948)))
                : (c <= 3980 || (c < 4176
                  ? (c < 4159
                    ? (c >= 4096 && c <= 4138)
                    : c <= 4159)
                  : (c <= 4181 || (c >= 4186 && c <= 4189)))))))))))))
      : (c <= 4193 || (c < 8134
        ? (c < 6176
          ? (c < 4808
            ? (c < 4688
              ? (c < 4295
                ? (c < 4213
                  ? (c < 4206
                    ? (c >= 4197 && c <= 4198)
                    : c <= 4208)
                  : (c <= 4225 || (c < 4256
                    ? c == 4238
                    : c <= 4293)))
                : (c <= 4295 || (c < 4348
                  ? (c < 4304
                    ? c == 4301
                    : c <= 4346)
                  : (c <= 4680 || (c >= 4682 && c <= 4685)))))
              : (c <= 4694 || (c < 4752
                ? (c < 4704
                  ? (c < 4698
                    ? c == 4696
                    : c <= 4701)
                  : (c <= 4744 || (c >= 4746 && c <= 4749)))
                : (c <= 4784 || (c < 4800
                  ? (c < 4792
                    ? (c >= 4786 && c <= 4789)
                    : c <= 4798)
                  : (c <= 4800 || (c >= 4802 && c <= 4805)))))))
            : (c <= 4822 || (c < 5792
              ? (c < 5024
                ? (c < 4888
                  ? (c < 4882
                    ? (c >= 4824 && c <= 4880)
                    : c <= 4885)
                  : (c <= 4954 || (c >= 4992 && c <= 5007)))
                : (c <= 5109 || (c < 5743
                  ? (c < 5121
                    ? (c >= 5112 && c <= 5117)
                    : c <= 5740)
                  : (c <= 5759 || (c >= 5761 && c <= 5786)))))
              : (c <= 5866 || (c < 5984
                ? (c < 5919
                  ? (c < 5888
                    ? (c >= 5870 && c <= 5880)
                    : c <= 5905)
                  : (c <= 5937 || (c >= 5952 && c <= 5969)))
                : (c <= 5996 || (c < 6103
                  ? (c < 6016
                    ? (c >= 5998 && c <= 6000)
                    : c <= 6067)
                  : (c <= 6103 || c == 6108))))))))
          : (c <= 6264 || (c < 7312
            ? (c < 6823
              ? (c < 6512
                ? (c < 6320
                  ? (c < 6314
                    ? (c >= 6272 && c <= 6312)
                    : c <= 6314)
                  : (c <= 6389 || (c < 6480
                    ? (c >= 6400 && c <= 6430)
                    : c <= 6509)))
                : (c <= 6516 || (c < 6656
                  ? (c < 6576
                    ? (c >= 6528 && c <= 6571)
                    : c <= 6601)
                  : (c <= 6678 || (c >= 6688 && c <= 6740)))))
              : (c <= 6823 || (c < 7098
                ? (c < 7043
                  ? (c < 6981
                    ? (c >= 6917 && c <= 6963)
                    : c <= 6988)
                  : (c <= 7072 || (c >= 7086 && c <= 7087)))
                : (c <= 7141 || (c < 7258
                  ? (c < 7245
                    ? (c >= 7168 && c <= 7203)
                    : c <= 7247)
                  : (c <= 7293 || (c >= 7296 && c <= 7304)))))))
            : (c <= 7354 || (c < 8008
              ? (c < 7418
                ? (c < 7406
                  ? (c < 7401
                    ? (c >= 7357 && c <= 7359)
                    : c <= 7404)
                  : (c <= 7411 || (c >= 7413 && c <= 7414)))
                : (c <= 7418 || (c < 7960
                  ? (c < 7680
                    ? (c >= 7424 && c <= 7615)
                    : c <= 7957)
                  : (c <= 7965 || (c >= 7968 && c <= 8005)))))
              : (c <= 8013 || (c < 8031
                ? (c < 8027
                  ? (c < 8025
                    ? (c >= 8016 && c <= 8023)
                    : c <= 8025)
                  : (c <= 8027 || c == 8029))
                : (c <= 8061 || (c < 8126
                  ? (c < 8118
                    ? (c >= 8064 && c <= 8116)
                    : c <= 8124)
                  : (c <= 8126 || (c >= 8130 && c <= 8132)))))))))))
        : (c <= 8140 || (c < 12337
          ? (c < 8544
            ? (c < 8458
              ? (c < 8305
                ? (c < 8160
                  ? (c < 8150
                    ? (c >= 8144 && c <= 8147)
                    : c <= 8155)
                  : (c <= 8172 || (c < 8182
                    ? (c >= 8178 && c <= 8180)
                    : c <= 8188)))
                : (c <= 8305 || (c < 8450
                  ? (c < 8336
                    ? c == 8319
                    : c <= 8348)
                  : (c <= 8450 || c == 8455))))
              : (c <= 8467 || (c < 8488
                ? (c < 8484
                  ? (c < 8472
                    ? c == 8469
                    : c <= 8477)
                  : (c <= 8484 || c == 8486))
                : (c <= 8488 || (c < 8517
                  ? (c < 8508
                    ? (c >= 8490 && c <= 8505)
                    : c <= 8511)
                  : (c <= 8521 || c == 8526))))))
            : (c <= 8584 || (c < 11680
              ? (c < 11559
                ? (c < 11506
                  ? (c < 11499
                    ? (c >= 11264 && c <= 11492)
                    : c <= 11502)
                  : (c <= 11507 || (c >= 11520 && c <= 11557)))
                : (c <= 11559 || (c < 11631
                  ? (c < 11568
                    ? c == 11565
                    : c <= 11623)
                  : (c <= 11631 || (c >= 11648 && c <= 11670)))))
              : (c <= 11686 || (c < 11720
                ? (c < 11704
                  ? (c < 11696
                    ? (c >= 11688 && c <= 11694)
                    : c <= 11702)
                  : (c <= 11710 || (c >= 11712 && c <= 11718)))
                : (c <= 11726 || (c < 12293
                  ? (c < 11736
                    ? (c >= 11728 && c <= 11734)
                    : c <= 11742)
                  : (c <= 12295 || (c >= 12321 && c <= 12329)))))))))
          : (c <= 12341 || (c < 42891
            ? (c < 19968
              ? (c < 12549
                ? (c < 12445
                  ? (c < 12353
                    ? (c >= 12344 && c <= 12348)
                    : c <= 12438)
                  : (c <= 12447 || (c < 12540
                    ? (c >= 12449 && c <= 12538)
                    : c <= 12543)))
                : (c <= 12591 || (c < 12784
                  ? (c < 12704
                    ? (c >= 12593 && c <= 12686)
                    : c <= 12735)
                  : (c <= 12799 || (c >= 13312 && c <= 19903)))))
              : (c <= 42124 || (c < 42560
                ? (c < 42512
                  ? (c < 42240
                    ? (c >= 42192 && c <= 42237)
                    : c <= 42508)
                  : (c <= 42527 || (c >= 42538 && c <= 42539)))
                : (c <= 42606 || (c < 42775
                  ? (c < 42656
                    ? (c >= 42623 && c <= 42653)
                    : c <= 42735)
                  : (c <= 42783 || (c >= 42786 && c <= 42888)))))))
            : (c <= 42954 || (c < 43250
              ? (c < 43011
                ? (c < 42965
                  ? (c < 42963
                    ? (c >= 42960 && c <= 42961)
                    : c <= 42963)
                  : (c <= 42969 || (c >= 42994 && c <= 43009)))
                : (c <= 43013 || (c < 43072
                  ? (c < 43020
                    ? (c >= 43015 && c <= 43018)
                    : c <= 43042)
                  : (c <= 43123 || (c >= 43138 && c <= 43187)))))
              : (c <= 43255 || (c < 43360
                ? (c < 43274
                  ? (c < 43261
                    ? c == 43259
                    : c <= 43262)
                  : (c <= 43301 || (c >= 43312 && c <= 43334)))
                : (c <= 43388 || (c < 43488
                  ? (c < 43471
                    ? (c >= 43396 && c <= 43442)
                    : c <= 43471)
                  : (c <= 43492 || (c >= 43494 && c <= 43503)))))))))))))))
    : (c <= 43518 || (c < 70727
      ? (c < 66956
        ? (c < 64914
          ? (c < 43868
            ? (c < 43714
              ? (c < 43646
                ? (c < 43588
                  ? (c < 43584
                    ? (c >= 43520 && c <= 43560)
                    : c <= 43586)
                  : (c <= 43595 || (c < 43642
                    ? (c >= 43616 && c <= 43638)
                    : c <= 43642)))
                : (c <= 43695 || (c < 43705
                  ? (c < 43701
                    ? c == 43697
                    : c <= 43702)
                  : (c <= 43709 || c == 43712))))
              : (c <= 43714 || (c < 43785
                ? (c < 43762
                  ? (c < 43744
                    ? (c >= 43739 && c <= 43741)
                    : c <= 43754)
                  : (c <= 43764 || (c >= 43777 && c <= 43782)))
                : (c <= 43790 || (c < 43816
                  ? (c < 43808
                    ? (c >= 43793 && c <= 43798)
                    : c <= 43814)
                  : (c <= 43822 || (c >= 43824 && c <= 43866)))))))
            : (c <= 43881 || (c < 64287
              ? (c < 63744
                ? (c < 55216
                  ? (c < 44032
                    ? (c >= 43888 && c <= 44002)
                    : c <= 55203)
                  : (c <= 55238 || (c >= 55243 && c <= 55291)))
                : (c <= 64109 || (c < 64275
                  ? (c < 64256
                    ? (c >= 64112 && c <= 64217)
                    : c <= 64262)
                  : (c <= 64279 || c == 64285))))
              : (c <= 64296 || (c < 64323
                ? (c < 64318
                  ? (c < 64312
                    ? (c >= 64298 && c <= 64310)
                    : c <= 64316)
                  : (c <= 64318 || (c >= 64320 && c <= 64321)))
                : (c <= 64324 || (c < 64612
                  ? (c < 64467
                    ? (c >= 64326 && c <= 64433)
                    : c <= 64605)
                  : (c <= 64829 || (c >= 64848 && c <= 64911)))))))))
          : (c <= 64967 || (c < 65599
            ? (c < 65382
              ? (c < 65147
                ? (c < 65139
                  ? (c < 65137
                    ? (c >= 65008 && c <= 65017)
                    : c <= 65137)
                  : (c <= 65139 || (c < 65145
                    ? c == 65143
                    : c <= 65145)))
                : (c <= 65147 || (c < 65313
                  ? (c < 65151
                    ? c == 65149
                    : c <= 65276)
                  : (c <= 65338 || (c >= 65345 && c <= 65370)))))
              : (c <= 65437 || (c < 65498
                ? (c < 65482
                  ? (c < 65474
                    ? (c >= 65440 && c <= 65470)
                    : c <= 65479)
                  : (c <= 65487 || (c >= 65490 && c <= 65495)))
                : (c <= 65500 || (c < 65576
                  ? (c < 65549
                    ? (c >= 65536 && c <= 65547)
                    : c <= 65574)
                  : (c <= 65594 || (c >= 65596 && c <= 65597)))))))
            : (c <= 65613 || (c < 66464
              ? (c < 66208
                ? (c < 65856
                  ? (c < 65664
                    ? (c >= 65616 && c <= 65629)
                    : c <= 65786)
                  : (c <= 65908 || (c >= 66176 && c <= 66204)))
                : (c <= 66256 || (c < 66384
                  ? (c < 66349
                    ? (c >= 66304 && c <= 66335)
                    : c <= 66378)
                  : (c <= 66421 || (c >= 66432 && c <= 66461)))))
              : (c <= 66499 || (c < 66776
                ? (c < 66560
                  ? (c < 66513
                    ? (c >= 66504 && c <= 66511)
                    : c <= 66517)
                  : (c <= 66717 || (c >= 66736 && c <= 66771)))
                : (c <= 66811 || (c < 66928
                  ? (c < 66864
                    ? (c >= 66816 && c <= 66855)
                    : c <= 66915)
                  : (c <= 66938 || (c >= 66940 && c <= 66954)))))))))))
        : (c <= 66962 || (c < 68864
          ? (c < 67828
            ? (c < 67506
              ? (c < 67072
                ? (c < 66979
                  ? (c < 66967
                    ? (c >= 66964 && c <= 66965)
                    : c <= 66977)
                  : (c <= 66993 || (c < 67003
                    ? (c >= 66995 && c <= 67001)
                    : c <= 67004)))
                : (c <= 67382 || (c < 67456
                  ? (c < 67424
                    ? (c >= 67392 && c <= 67413)
                    : c <= 67431)
                  : (c <= 67461 || (c >= 67463 && c <= 67504)))))
              : (c <= 67514 || (c < 67644
                ? (c < 67594
                  ? (c < 67592
                    ? (c >= 67584 && c <= 67589)
                    : c <= 67592)
                  : (c <= 67637 || (c >= 67639 && c <= 67640)))
                : (c <= 67644 || (c < 67712
                  ? (c < 67680
                    ? (c >= 67647 && c <= 67669)
                    : c <= 67702)
                  : (c <= 67742 || (c >= 67808 && c <= 67826)))))))
            : (c <= 67829 || (c < 68224
              ? (c < 68096
                ? (c < 67968
                  ? (c < 67872
                    ? (c >= 67840 && c <= 67861)
                    : c <= 67897)
                  : (c <= 68023 || (c >= 68030 && c <= 68031)))
                : (c <= 68096 || (c < 68121
                  ? (c < 68117
                    ? (c >= 68112 && c <= 68115)
                    : c <= 68119)
                  : (c <= 68149 || (c >= 68192 && c <= 68220)))))
              : (c <= 68252 || (c < 68448
                ? (c < 68352
                  ? (c < 68297
                    ? (c >= 68288 && c <= 68295)
                    : c <= 68324)
                  : (c <= 68405 || (c >= 68416 && c <= 68437)))
                : (c <= 68466 || (c < 68736
                  ? (c < 68608
                    ? (c >= 68480 && c <= 68497)
                    : c <= 68680)
                  : (c <= 68786 || (c >= 68800 && c <= 68850)))))))))
          : (c <= 68899 || (c < 70106
            ? (c < 69749
              ? (c < 69488
                ? (c < 69376
                  ? (c < 69296
                    ? (c >= 69248 && c <= 69289)
                    : c <= 69297)
                  : (c <= 69404 || (c < 69424
                    ? c == 69415
                    : c <= 69445)))
                : (c <= 69505 || (c < 69635
                  ? (c < 69600
                    ? (c >= 69552 && c <= 69572)
                    : c <= 69622)
                  : (c <= 69687 || (c >= 69745 && c <= 69746)))))
              : (c <= 69749 || (c < 69959
                ? (c < 69891
                  ? (c < 69840
                    ? (c >= 69763 && c <= 69807)
                    : c <= 69864)
                  : (c <= 69926 || c == 69956))
                : (c <= 69959 || (c < 70019
                  ? (c < 70006
                    ? (c >= 69968 && c <= 70002)
                    : c <= 70006)
                  : (c <= 70066 || (c >= 70081 && c <= 70084)))))))
            : (c <= 70106 || (c < 70405
              ? (c < 70280
                ? (c < 70163
                  ? (c < 70144
                    ? c == 70108
                    : c <= 70161)
                  : (c <= 70187 || (c >= 70272 && c <= 70278)))
                : (c <= 70280 || (c < 70303
                  ? (c < 70287
                    ? (c >= 70282 && c <= 70285)
                    : c <= 70301)
                  : (c <= 70312 || (c >= 70320 && c <= 70366)))))
              : (c <= 70412 || (c < 70453
                ? (c < 70442
                  ? (c < 70419
                    ? (c >= 70415 && c <= 70416)
                    : c <= 70440)
                  : (c <= 70448 || (c >= 70450 && c <= 70451)))
                : (c <= 70457 || (c < 70493
                  ? (c < 70480
                    ? c == 70461
                    : c <= 70480)
                  : (c <= 70497 || (c >= 70656 && c <= 70708)))))))))))))
      : (c <= 70730 || (c < 119894
        ? (c < 73056
          ? (c < 72001
            ? (c < 71424
              ? (c < 71128
                ? (c < 70852
                  ? (c < 70784
                    ? (c >= 70751 && c <= 70753)
                    : c <= 70831)
                  : (c <= 70853 || (c < 71040
                    ? c == 70855
                    : c <= 71086)))
                : (c <= 71131 || (c < 71296
                  ? (c < 71236
                    ? (c >= 71168 && c <= 71215)
                    : c <= 71236)
                  : (c <= 71338 || c == 71352))))
              : (c <= 71450 || (c < 71945
                ? (c < 71840
                  ? (c < 71680
                    ? (c >= 71488 && c <= 71494)
                    : c <= 71723)
                  : (c <= 71903 || (c >= 71935 && c <= 71942)))
                : (c <= 71945 || (c < 71960
                  ? (c < 71957
                    ? (c >= 71948 && c <= 71955)
                    : c <= 71958)
                  : (c <= 71983 || c == 71999))))))
            : (c <= 72001 || (c < 72349
              ? (c < 72192
                ? (c < 72161
                  ? (c < 72106
                    ? (c >= 72096 && c <= 72103)
                    : c <= 72144)
                  : (c <= 72161 || c == 72163))
                : (c <= 72192 || (c < 72272
                  ? (c < 72250
                    ? (c >= 72203 && c <= 72242)
                    : c <= 72250)
                  : (c <= 72272 || (c >= 72284 && c <= 72329)))))
              : (c <= 72349 || (c < 72818
                ? (c < 72714
                  ? (c < 72704
                    ? (c >= 72368 && c <= 72440)
                    : c <= 72712)
                  : (c <= 72750 || c == 72768))
                : (c <= 72847 || (c < 72971
                  ? (c < 72968
                    ? (c >= 72960 && c <= 72966)
                    : c <= 72969)
                  : (c <= 73008 || c == 73030))))))))
          : (c <= 73061 || (c < 93952
            ? (c < 82944
              ? (c < 73728
                ? (c < 73112
                  ? (c < 73066
                    ? (c >= 73063 && c <= 73064)
                    : c <= 73097)
                  : (c <= 73112 || (c < 73648
                    ? (c >= 73440 && c <= 73458)
                    : c <= 73648)))
                : (c <= 74649 || (c < 77712
                  ? (c < 74880
                    ? (c >= 74752 && c <= 74862)
                    : c <= 75075)
                  : (c <= 77808 || (c >= 77824 && c <= 78894)))))
              : (c <= 83526 || (c < 92928
                ? (c < 92784
                  ? (c < 92736
                    ? (c >= 92160 && c <= 92728)
                    : c <= 92766)
                  : (c <= 92862 || (c >= 92880 && c <= 92909)))
                : (c <= 92975 || (c < 93053
                  ? (c < 93027
                    ? (c >= 92992 && c <= 92995)
                    : c <= 93047)
                  : (c <= 93071 || (c >= 93760 && c <= 93823)))))))
            : (c <= 94026 || (c < 110589
              ? (c < 94208
                ? (c < 94176
                  ? (c < 94099
                    ? c == 94032
                    : c <= 94111)
                  : (c <= 94177 || c == 94179))
                : (c <= 100343 || (c < 110576
                  ? (c < 101632
                    ? (c >= 100352 && c <= 101589)
                    : c <= 101640)
                  : (c <= 110579 || (c >= 110581 && c <= 110587)))))
              : (c <= 110590 || (c < 113664
                ? (c < 110948
                  ? (c < 110928
                    ? (c >= 110592 && c <= 110882)
                    : c <= 110930)
                  : (c <= 110951 || (c >= 110960 && c <= 111355)))
                : (c <= 113770 || (c < 113808
                  ? (c < 113792
                    ? (c >= 113776 && c <= 113788)
                    : c <= 113800)
                  : (c <= 113817 || (c >= 119808 && c <= 119892)))))))))))
        : (c <= 119964 || (c < 125259
          ? (c < 120572
            ? (c < 120086
              ? (c < 119995
                ? (c < 119973
                  ? (c < 119970
                    ? (c >= 119966 && c <= 119967)
                    : c <= 119970)
                  : (c <= 119974 || (c < 119982
                    ? (c >= 119977 && c <= 119980)
                    : c <= 119993)))
                : (c <= 119995 || (c < 120071
                  ? (c < 120005
                    ? (c >= 119997 && c <= 120003)
                    : c <= 120069)
                  : (c <= 120074 || (c >= 120077 && c <= 120084)))))
              : (c <= 120092 || (c < 120138
                ? (c < 120128
                  ? (c < 120123
                    ? (c >= 120094 && c <= 120121)
                    : c <= 120126)
                  : (c <= 120132 || c == 120134))
                : (c <= 120144 || (c < 120514
                  ? (c < 120488
                    ? (c >= 120146 && c <= 120485)
                    : c <= 120512)
                  : (c <= 120538 || (c >= 120540 && c <= 120570)))))))
            : (c <= 120596 || (c < 123191
              ? (c < 120714
                ? (c < 120656
                  ? (c < 120630
                    ? (c >= 120598 && c <= 120628)
                    : c <= 120654)
                  : (c <= 120686 || (c >= 120688 && c <= 120712)))
                : (c <= 120744 || (c < 122624
                  ? (c < 120772
                    ? (c >= 120746 && c <= 120770)
                    : c <= 120779)
                  : (c <= 122654 || (c >= 123136 && c <= 123180)))))
              : (c <= 123197 || (c < 124904
                ? (c < 123584
                  ? (c < 123536
                    ? c == 123214
                    : c <= 123565)
                  : (c <= 123627 || (c >= 124896 && c <= 124902)))
                : (c <= 124907 || (c < 124928
                  ? (c < 124912
                    ? (c >= 124909 && c <= 124910)
                    : c <= 124926)
                  : (c <= 125124 || (c >= 125184 && c <= 125251)))))))))
          : (c <= 125259 || (c < 126559
            ? (c < 126535
              ? (c < 126505
                ? (c < 126497
                  ? (c < 126469
                    ? (c >= 126464 && c <= 126467)
                    : c <= 126495)
                  : (c <= 126498 || (c < 126503
                    ? c == 126500
                    : c <= 126503)))
                : (c <= 126514 || (c < 126523
                  ? (c < 126521
                    ? (c >= 126516 && c <= 126519)
                    : c <= 126521)
                  : (c <= 126523 || c == 126530))))
              : (c <= 126535 || (c < 126548
                ? (c < 126541
                  ? (c < 126539
                    ? c == 126537
                    : c <= 126539)
                  : (c <= 126543 || (c >= 126545 && c <= 126546)))
                : (c <= 126548 || (c < 126555
                  ? (c < 126553
                    ? c == 126551
                    : c <= 126553)
                  : (c <= 126555 || c == 126557))))))
            : (c <= 126559 || (c < 126625
              ? (c < 126580
                ? (c < 126567
                  ? (c < 126564
                    ? (c >= 126561 && c <= 126562)
                    : c <= 126564)
                  : (c <= 126570 || (c >= 126572 && c <= 126578)))
                : (c <= 126583 || (c < 126592
                  ? (c < 126590
                    ? (c >= 126585 && c <= 126588)
                    : c <= 126590)
                  : (c <= 126601 || (c >= 126603 && c <= 126619)))))
              : (c <= 126627 || (c < 177984
                ? (c < 131072
                  ? (c < 126635
                    ? (c >= 126629 && c <= 126633)
                    : c <= 126651)
                  : (c <= 173791 || (c >= 173824 && c <= 177976)))
                : (c <= 178205 || (c < 194560
                  ? (c < 183984
                    ? (c >= 178208 && c <= 183969)
                    : c <= 191456)
                  : (c <= 195101 || (c >= 196608 && c <= 201546)))))))))))))))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(34);
      if (lookahead == 0) ADVANCE(37);
      if (lookahead == '!') ADVANCE(20);
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '%') ADVANCE(75);
      if (lookahead == '&') ADVANCE(7);
      if (lookahead == '\'') ADVANCE(60);
      if (lookahead == '(') ADVANCE(38);
      if (lookahead == ')') ADVANCE(39);
      if (lookahead == '*') ADVANCE(71);
      if (lookahead == '+') ADVANCE(69);
      if (lookahead == ',') ADVANCE(46);
      if (lookahead == '-') ADVANCE(68);
      if (lookahead == '.') ADVANCE(13);
      if (lookahead == '/') ADVANCE(72);
      if (lookahead == '0') ADVANCE(55);
      if (lookahead == ':') ADVANCE(44);
      if (lookahead == ';') ADVANCE(36);
      if (lookahead == '<') ADVANCE(81);
      if (lookahead == '=') ADVANCE(49);
      if (lookahead == '>') ADVANCE(78);
      if (lookahead == '@') ADVANCE(30);
      if (lookahead == '[') ADVANCE(87);
      if (lookahead == '\\') ADVANCE(11);
      if (lookahead == ']') ADVANCE(88);
      if (lookahead == '_') ADVANCE(51);
      if (lookahead == '{') ADVANCE(40);
      if (lookahead == '|') ADVANCE(93);
      if (lookahead == '}') ADVANCE(41);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(32)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(58);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(95);
      if (sym_lowercase_identifier_character_set_1(lookahead)) ADVANCE(97);
      END_STATE();
    case 1:
      if (lookahead == 0) ADVANCE(37);
      if (lookahead == '\n') ADVANCE(35);
      if (lookahead == '!') ADVANCE(20);
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '%') ADVANCE(75);
      if (lookahead == '&') ADVANCE(7);
      if (lookahead == '\'') ADVANCE(60);
      if (lookahead == '(') ADVANCE(38);
      if (lookahead == '*') ADVANCE(71);
      if (lookahead == '+') ADVANCE(69);
      if (lookahead == ',') ADVANCE(46);
      if (lookahead == '-') ADVANCE(67);
      if (lookahead == '.') ADVANCE(27);
      if (lookahead == '/') ADVANCE(72);
      if (lookahead == '0') ADVANCE(55);
      if (lookahead == ':') ADVANCE(44);
      if (lookahead == ';') ADVANCE(36);
      if (lookahead == '<') ADVANCE(81);
      if (lookahead == '=') ADVANCE(48);
      if (lookahead == '>') ADVANCE(78);
      if (lookahead == '@') ADVANCE(30);
      if (lookahead == '[') ADVANCE(87);
      if (lookahead == '_') ADVANCE(51);
      if (lookahead == '{') ADVANCE(40);
      if (lookahead == '|') ADVANCE(24);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(58);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(95);
      if (sym_lowercase_identifier_character_set_2(lookahead)) ADVANCE(97);
      if (sym_lowercase_identifier_character_set_3(lookahead)) ADVANCE(97);
      END_STATE();
    case 2:
      if (lookahead == 0) ADVANCE(37);
      if (lookahead == '\n') ADVANCE(35);
      if (lookahead == '!') ADVANCE(20);
      if (lookahead == '%') ADVANCE(75);
      if (lookahead == '&') ADVANCE(7);
      if (lookahead == '(') ADVANCE(38);
      if (lookahead == '*') ADVANCE(71);
      if (lookahead == '+') ADVANCE(69);
      if (lookahead == '-') ADVANCE(67);
      if (lookahead == '.') ADVANCE(27);
      if (lookahead == '/') ADVANCE(72);
      if (lookahead == ':') ADVANCE(19);
      if (lookahead == ';') ADVANCE(36);
      if (lookahead == '<') ADVANCE(81);
      if (lookahead == '=') ADVANCE(21);
      if (lookahead == '>') ADVANCE(78);
      if (lookahead == '[') ADVANCE(87);
      if (lookahead == '|') ADVANCE(24);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (sym_lowercase_identifier_character_set_4(lookahead)) ADVANCE(97);
      END_STATE();
    case 3:
      if (lookahead == 0) ADVANCE(37);
      if (lookahead == '\n') ADVANCE(35);
      if (lookahead == '-') ADVANCE(22);
      if (lookahead == '/') ADVANCE(14);
      if (lookahead == ';') ADVANCE(36);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      END_STATE();
    case 4:
      if (lookahead == '!') ADVANCE(20);
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '%') ADVANCE(75);
      if (lookahead == '&') ADVANCE(7);
      if (lookahead == '\'') ADVANCE(60);
      if (lookahead == '(') ADVANCE(38);
      if (lookahead == ')') ADVANCE(39);
      if (lookahead == '*') ADVANCE(71);
      if (lookahead == '+') ADVANCE(69);
      if (lookahead == ',') ADVANCE(46);
      if (lookahead == '-') ADVANCE(67);
      if (lookahead == '.') ADVANCE(13);
      if (lookahead == '/') ADVANCE(72);
      if (lookahead == '0') ADVANCE(55);
      if (lookahead == ':') ADVANCE(43);
      if (lookahead == '<') ADVANCE(81);
      if (lookahead == '=') ADVANCE(48);
      if (lookahead == '>') ADVANCE(78);
      if (lookahead == '@') ADVANCE(30);
      if (lookahead == '[') ADVANCE(87);
      if (lookahead == ']') ADVANCE(88);
      if (lookahead == '_') ADVANCE(51);
      if (lookahead == '{') ADVANCE(40);
      if (lookahead == '|') ADVANCE(24);
      if (lookahead == '}') ADVANCE(41);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(58);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(95);
      if (sym_lowercase_identifier_character_set_2(lookahead)) ADVANCE(97);
      if (sym_lowercase_identifier_character_set_3(lookahead)) ADVANCE(97);
      END_STATE();
    case 5:
      if (lookahead == '!') ADVANCE(20);
      if (lookahead == '%') ADVANCE(75);
      if (lookahead == '&') ADVANCE(7);
      if (lookahead == '(') ADVANCE(38);
      if (lookahead == ')') ADVANCE(39);
      if (lookahead == '*') ADVANCE(71);
      if (lookahead == '+') ADVANCE(69);
      if (lookahead == ',') ADVANCE(46);
      if (lookahead == '-') ADVANCE(67);
      if (lookahead == '.') ADVANCE(27);
      if (lookahead == '/') ADVANCE(72);
      if (lookahead == ':') ADVANCE(45);
      if (lookahead == '<') ADVANCE(81);
      if (lookahead == '=') ADVANCE(21);
      if (lookahead == '>') ADVANCE(78);
      if (lookahead == '[') ADVANCE(87);
      if (lookahead == ']') ADVANCE(88);
      if (lookahead == '{') ADVANCE(40);
      if (lookahead == '|') ADVANCE(24);
      if (lookahead == '}') ADVANCE(41);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (sym_lowercase_identifier_character_set_4(lookahead)) ADVANCE(97);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '\\') ADVANCE(11);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(64);
      if (lookahead != 0) ADVANCE(64);
      END_STATE();
    case 7:
      if (lookahead == '&') ADVANCE(84);
      END_STATE();
    case 8:
      if (lookahead == '(') ADVANCE(38);
      if (lookahead == ')') ADVANCE(39);
      if (lookahead == ',') ADVANCE(46);
      if (lookahead == '-') ADVANCE(22);
      if (lookahead == '/') ADVANCE(14);
      if (lookahead == '=') ADVANCE(47);
      if (lookahead == '@') ADVANCE(30);
      if (lookahead == '[') ADVANCE(87);
      if (lookahead == ']') ADVANCE(88);
      if (lookahead == '_') ADVANCE(52);
      if (lookahead == '{') ADVANCE(40);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (sym_identifier_character_set_1(lookahead)) ADVANCE(99);
      END_STATE();
    case 9:
      if (lookahead == '(') ADVANCE(38);
      if (lookahead == ')') ADVANCE(39);
      if (lookahead == ',') ADVANCE(46);
      if (lookahead == '.') ADVANCE(12);
      if (lookahead == '/') ADVANCE(14);
      if (lookahead == ':') ADVANCE(42);
      if (lookahead == '=') ADVANCE(50);
      if (lookahead == ']') ADVANCE(88);
      if (lookahead == '|') ADVANCE(92);
      if (lookahead == '}') ADVANCE(41);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(9)
      if (sym_lowercase_identifier_character_set_4(lookahead)) ADVANCE(97);
      END_STATE();
    case 10:
      if (lookahead == '(') ADVANCE(54);
      END_STATE();
    case 11:
      if (lookahead == '(') ADVANCE(54);
      if (lookahead == '\\' ||
          lookahead == 'b' ||
          lookahead == 'n' ||
          lookahead == 't') ADVANCE(66);
      END_STATE();
    case 12:
      if (lookahead == '.') ADVANCE(86);
      END_STATE();
    case 13:
      if (lookahead == '.') ADVANCE(86);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      if (sym_dot_identifier_character_set_1(lookahead)) ADVANCE(100);
      END_STATE();
    case 14:
      if (lookahead == '/') ADVANCE(102);
      END_STATE();
    case 15:
      if (lookahead == '/') ADVANCE(14);
      if (lookahead == ':') ADVANCE(42);
      if (lookahead == '=') ADVANCE(47);
      if (lookahead == '|') ADVANCE(92);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(15)
      if (sym_lowercase_identifier_character_set_4(lookahead)) ADVANCE(97);
      END_STATE();
    case 16:
      if (lookahead == '/') ADVANCE(14);
      if (lookahead == '=') ADVANCE(23);
      if (lookahead == '|') ADVANCE(92);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(16)
      if (sym_lowercase_identifier_character_set_4(lookahead)) ADVANCE(97);
      END_STATE();
    case 17:
      if (lookahead == '/') ADVANCE(14);
      if (lookahead == '@') ADVANCE(30);
      if (lookahead == ']') ADVANCE(88);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(17)
      if (sym_dot_identifier_character_set_1(lookahead)) ADVANCE(99);
      END_STATE();
    case 18:
      if (lookahead == '/') ADVANCE(62);
      if (lookahead == '\\') ADVANCE(63);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(61);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(61);
      END_STATE();
    case 19:
      if (lookahead == ':') ADVANCE(31);
      END_STATE();
    case 20:
      if (lookahead == '=') ADVANCE(83);
      END_STATE();
    case 21:
      if (lookahead == '=') ADVANCE(82);
      END_STATE();
    case 22:
      if (lookahead == '>') ADVANCE(94);
      END_STATE();
    case 23:
      if (lookahead == '>') ADVANCE(90);
      END_STATE();
    case 24:
      if (lookahead == '|') ADVANCE(85);
      END_STATE();
    case 25:
      if (lookahead == '0' ||
          lookahead == '1' ||
          lookahead == '_') ADVANCE(56);
      END_STATE();
    case 26:
      if (('0' <= lookahead && lookahead <= '7') ||
          lookahead == '_') ADVANCE(57);
      END_STATE();
    case 27:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      if (sym_dot_identifier_character_set_1(lookahead)) ADVANCE(100);
      END_STATE();
    case 28:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(59);
      END_STATE();
    case 29:
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(96);
      if (sym_lowercase_identifier_character_set_4(lookahead)) ADVANCE(98);
      END_STATE();
    case 30:
      if (sym_dot_identifier_character_set_1(lookahead)) ADVANCE(101);
      END_STATE();
    case 31:
      if (sym_lowercase_identifier_character_set_4(lookahead)) ADVANCE(98);
      END_STATE();
    case 32:
      if (eof) ADVANCE(34);
      if (lookahead == 0) ADVANCE(37);
      if (lookahead == '!') ADVANCE(20);
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '%') ADVANCE(75);
      if (lookahead == '&') ADVANCE(7);
      if (lookahead == '\'') ADVANCE(60);
      if (lookahead == '(') ADVANCE(38);
      if (lookahead == ')') ADVANCE(39);
      if (lookahead == '*') ADVANCE(71);
      if (lookahead == '+') ADVANCE(69);
      if (lookahead == ',') ADVANCE(46);
      if (lookahead == '-') ADVANCE(68);
      if (lookahead == '.') ADVANCE(13);
      if (lookahead == '/') ADVANCE(72);
      if (lookahead == '0') ADVANCE(55);
      if (lookahead == ':') ADVANCE(44);
      if (lookahead == ';') ADVANCE(36);
      if (lookahead == '<') ADVANCE(81);
      if (lookahead == '=') ADVANCE(49);
      if (lookahead == '>') ADVANCE(78);
      if (lookahead == '@') ADVANCE(30);
      if (lookahead == '[') ADVANCE(87);
      if (lookahead == '\\') ADVANCE(10);
      if (lookahead == ']') ADVANCE(88);
      if (lookahead == '_') ADVANCE(51);
      if (lookahead == '{') ADVANCE(40);
      if (lookahead == '|') ADVANCE(93);
      if (lookahead == '}') ADVANCE(41);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(32)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(58);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(95);
      if (sym_lowercase_identifier_character_set_1(lookahead)) ADVANCE(97);
      END_STATE();
    case 33:
      if (eof) ADVANCE(34);
      if (lookahead == '!') ADVANCE(20);
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '%') ADVANCE(75);
      if (lookahead == '&') ADVANCE(7);
      if (lookahead == '(') ADVANCE(38);
      if (lookahead == ')') ADVANCE(39);
      if (lookahead == '*') ADVANCE(71);
      if (lookahead == '+') ADVANCE(69);
      if (lookahead == ',') ADVANCE(46);
      if (lookahead == '-') ADVANCE(67);
      if (lookahead == '.') ADVANCE(13);
      if (lookahead == '/') ADVANCE(72);
      if (lookahead == ':') ADVANCE(45);
      if (lookahead == '<') ADVANCE(81);
      if (lookahead == '=') ADVANCE(49);
      if (lookahead == '>') ADVANCE(78);
      if (lookahead == '@') ADVANCE(30);
      if (lookahead == '[') ADVANCE(87);
      if (lookahead == ']') ADVANCE(88);
      if (lookahead == '{') ADVANCE(40);
      if (lookahead == '|') ADVANCE(93);
      if (lookahead == '}') ADVANCE(41);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(33)
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(99);
      if (sym_lowercase_identifier_character_set_2(lookahead)) ADVANCE(97);
      if (sym_lowercase_identifier_character_set_5(lookahead)) ADVANCE(97);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(35);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ':') ADVANCE(29);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ':') ADVANCE(29);
      if (lookahead == '=') ADVANCE(91);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ':') ADVANCE(31);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(82);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(82);
      if (lookahead == '>') ADVANCE(90);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '>') ADVANCE(90);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym__);
      if (sym_lowercase_identifier_character_set_6(lookahead)) ADVANCE(97);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym__);
      if (sym_lowercase_identifier_character_set_6(lookahead)) ADVANCE(99);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_BSLASH_LPAREN);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(25);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(26);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(58);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '0' ||
          lookahead == '1' ||
          lookahead == '_') ADVANCE(56);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_integer_literal);
      if (('0' <= lookahead && lookahead <= '7') ||
          lookahead == '_') ADVANCE(57);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_integer_literal);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(58);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_integer_literal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(59);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(aux_sym_char_literal_token1);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(aux_sym_char_literal_token1);
      if (lookahead == '/') ADVANCE(102);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(aux_sym_char_literal_token1);
      if (lookahead == '\\' ||
          lookahead == 'b' ||
          lookahead == 'n' ||
          lookahead == 't') ADVANCE(66);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_unescaped_string_fragment);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_unescaped_string_fragment);
      if (lookahead == '/') ADVANCE(102);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_escape_seqence);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '=') ADVANCE(77);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '=') ADVANCE(77);
      if (lookahead == '>') ADVANCE(94);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '=') ADVANCE(76);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_STAR_STAR);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(70);
      if (lookahead == '=') ADVANCE(73);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '/') ADVANCE(102);
      if (lookahead == '=') ADVANCE(74);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_STAR_EQ);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_SLASH_EQ);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_PLUS_EQ);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_DASH_EQ);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(79);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(80);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_DOT_DOT);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(aux_sym_accessor_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_COLON_EQ);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '|') ADVANCE(85);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_uppercase_identifier);
      if (sym_lowercase_identifier_character_set_6(lookahead)) ADVANCE(95);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_colon_colon_uppercase_identifier);
      if (sym_lowercase_identifier_character_set_6(lookahead)) ADVANCE(96);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_lowercase_identifier);
      if (sym_lowercase_identifier_character_set_6(lookahead)) ADVANCE(97);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_colon_colon_lowercase_identifier);
      if (sym_lowercase_identifier_character_set_6(lookahead)) ADVANCE(98);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_identifier);
      if (sym_lowercase_identifier_character_set_6(lookahead)) ADVANCE(99);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_dot_identifier);
      if (sym_lowercase_identifier_character_set_6(lookahead)) ADVANCE(100);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_package_identifier);
      if (sym_lowercase_identifier_character_set_6(lookahead)) ADVANCE(101);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(102);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == 'a') ADVANCE(1);
      if (lookahead == 'b') ADVANCE(2);
      if (lookahead == 'c') ADVANCE(3);
      if (lookahead == 'e') ADVANCE(4);
      if (lookahead == 'f') ADVANCE(5);
      if (lookahead == 'i') ADVANCE(6);
      if (lookahead == 'l') ADVANCE(7);
      if (lookahead == 'm') ADVANCE(8);
      if (lookahead == 'p') ADVANCE(9);
      if (lookahead == 'r') ADVANCE(10);
      if (lookahead == 's') ADVANCE(11);
      if (lookahead == 't') ADVANCE(12);
      if (lookahead == 'v') ADVANCE(13);
      if (lookahead == 'w') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 's') ADVANCE(15);
      END_STATE();
    case 2:
      if (lookahead == 'r') ADVANCE(16);
      END_STATE();
    case 3:
      if (lookahead == 'o') ADVANCE(17);
      END_STATE();
    case 4:
      if (lookahead == 'l') ADVANCE(18);
      if (lookahead == 'n') ADVANCE(19);
      END_STATE();
    case 5:
      if (lookahead == 'a') ADVANCE(20);
      if (lookahead == 'n') ADVANCE(21);
      if (lookahead == 'u') ADVANCE(22);
      END_STATE();
    case 6:
      if (lookahead == 'f') ADVANCE(23);
      if (lookahead == 'n') ADVANCE(24);
      END_STATE();
    case 7:
      if (lookahead == 'e') ADVANCE(25);
      END_STATE();
    case 8:
      if (lookahead == 'a') ADVANCE(26);
      if (lookahead == 'u') ADVANCE(27);
      END_STATE();
    case 9:
      if (lookahead == 'r') ADVANCE(28);
      if (lookahead == 'u') ADVANCE(29);
      END_STATE();
    case 10:
      if (lookahead == 'e') ADVANCE(30);
      END_STATE();
    case 11:
      if (lookahead == 't') ADVANCE(31);
      END_STATE();
    case 12:
      if (lookahead == 'r') ADVANCE(32);
      if (lookahead == 'y') ADVANCE(33);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(34);
      END_STATE();
    case 14:
      if (lookahead == 'h') ADVANCE(35);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_as);
      END_STATE();
    case 16:
      if (lookahead == 'e') ADVANCE(36);
      END_STATE();
    case 17:
      if (lookahead == 'n') ADVANCE(37);
      END_STATE();
    case 18:
      if (lookahead == 's') ADVANCE(38);
      END_STATE();
    case 19:
      if (lookahead == 'u') ADVANCE(39);
      END_STATE();
    case 20:
      if (lookahead == 'l') ADVANCE(40);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_fn);
      END_STATE();
    case 22:
      if (lookahead == 'n') ADVANCE(41);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 24:
      if (lookahead == 't') ADVANCE(42);
      END_STATE();
    case 25:
      if (lookahead == 't') ADVANCE(43);
      END_STATE();
    case 26:
      if (lookahead == 't') ADVANCE(44);
      END_STATE();
    case 27:
      if (lookahead == 't') ADVANCE(45);
      END_STATE();
    case 28:
      if (lookahead == 'i') ADVANCE(46);
      END_STATE();
    case 29:
      if (lookahead == 'b') ADVANCE(47);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(48);
      if (lookahead == 't') ADVANCE(49);
      END_STATE();
    case 31:
      if (lookahead == 'r') ADVANCE(50);
      END_STATE();
    case 32:
      if (lookahead == 'u') ADVANCE(51);
      END_STATE();
    case 33:
      if (lookahead == 'p') ADVANCE(52);
      END_STATE();
    case 34:
      if (lookahead == 'r') ADVANCE(53);
      END_STATE();
    case 35:
      if (lookahead == 'i') ADVANCE(54);
      END_STATE();
    case 36:
      if (lookahead == 'a') ADVANCE(55);
      END_STATE();
    case 37:
      if (lookahead == 't') ADVANCE(56);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(57);
      END_STATE();
    case 39:
      if (lookahead == 'm') ADVANCE(58);
      END_STATE();
    case 40:
      if (lookahead == 's') ADVANCE(59);
      END_STATE();
    case 41:
      if (lookahead == 'c') ADVANCE(60);
      END_STATE();
    case 42:
      if (lookahead == 'e') ADVANCE(61);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 44:
      if (lookahead == 'c') ADVANCE(62);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_mutability);
      END_STATE();
    case 46:
      if (lookahead == 'v') ADVANCE(63);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_pub);
      END_STATE();
    case 48:
      if (lookahead == 'd') ADVANCE(64);
      END_STATE();
    case 49:
      if (lookahead == 'u') ADVANCE(65);
      END_STATE();
    case 50:
      if (lookahead == 'u') ADVANCE(66);
      END_STATE();
    case 51:
      if (lookahead == 'e') ADVANCE(67);
      END_STATE();
    case 52:
      if (lookahead == 'e') ADVANCE(68);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_var);
      END_STATE();
    case 54:
      if (lookahead == 'l') ADVANCE(69);
      END_STATE();
    case 55:
      if (lookahead == 'k') ADVANCE(70);
      END_STATE();
    case 56:
      if (lookahead == 'i') ADVANCE(71);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_enum);
      END_STATE();
    case 59:
      if (lookahead == 'e') ADVANCE(72);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_func);
      END_STATE();
    case 61:
      if (lookahead == 'r') ADVANCE(73);
      END_STATE();
    case 62:
      if (lookahead == 'h') ADVANCE(74);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_priv);
      END_STATE();
    case 64:
      if (lookahead == 'o') ADVANCE(75);
      END_STATE();
    case 65:
      if (lookahead == 'r') ADVANCE(76);
      END_STATE();
    case 66:
      if (lookahead == 'c') ADVANCE(77);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_type);
      END_STATE();
    case 69:
      if (lookahead == 'e') ADVANCE(78);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_break);
      END_STATE();
    case 71:
      if (lookahead == 'n') ADVANCE(79);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 73:
      if (lookahead == 'f') ADVANCE(80);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_match);
      END_STATE();
    case 75:
      if (lookahead == 'n') ADVANCE(81);
      END_STATE();
    case 76:
      if (lookahead == 'n') ADVANCE(82);
      END_STATE();
    case 77:
      if (lookahead == 't') ADVANCE(83);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 79:
      if (lookahead == 'u') ADVANCE(84);
      END_STATE();
    case 80:
      if (lookahead == 'a') ADVANCE(85);
      END_STATE();
    case 81:
      if (lookahead == 'l') ADVANCE(86);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_struct);
      END_STATE();
    case 84:
      if (lookahead == 'e') ADVANCE(87);
      END_STATE();
    case 85:
      if (lookahead == 'c') ADVANCE(88);
      END_STATE();
    case 86:
      if (lookahead == 'y') ADVANCE(89);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_continue);
      END_STATE();
    case 88:
      if (lookahead == 'e') ADVANCE(90);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_readonly);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_interface);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 33},
  [2] = {.lex_state = 4, .external_lex_state = 1},
  [3] = {.lex_state = 4, .external_lex_state = 1},
  [4] = {.lex_state = 4, .external_lex_state = 1},
  [5] = {.lex_state = 4, .external_lex_state = 1},
  [6] = {.lex_state = 4, .external_lex_state = 1},
  [7] = {.lex_state = 4, .external_lex_state = 1},
  [8] = {.lex_state = 4, .external_lex_state = 1},
  [9] = {.lex_state = 4, .external_lex_state = 1},
  [10] = {.lex_state = 4, .external_lex_state = 1},
  [11] = {.lex_state = 1, .external_lex_state = 1},
  [12] = {.lex_state = 4, .external_lex_state = 1},
  [13] = {.lex_state = 4, .external_lex_state = 1},
  [14] = {.lex_state = 4, .external_lex_state = 1},
  [15] = {.lex_state = 4, .external_lex_state = 1},
  [16] = {.lex_state = 4, .external_lex_state = 1},
  [17] = {.lex_state = 4, .external_lex_state = 1},
  [18] = {.lex_state = 4, .external_lex_state = 1},
  [19] = {.lex_state = 4, .external_lex_state = 1},
  [20] = {.lex_state = 4, .external_lex_state = 1},
  [21] = {.lex_state = 4, .external_lex_state = 1},
  [22] = {.lex_state = 4, .external_lex_state = 1},
  [23] = {.lex_state = 4, .external_lex_state = 1},
  [24] = {.lex_state = 4, .external_lex_state = 1},
  [25] = {.lex_state = 4, .external_lex_state = 1},
  [26] = {.lex_state = 4, .external_lex_state = 1},
  [27] = {.lex_state = 4, .external_lex_state = 1},
  [28] = {.lex_state = 4, .external_lex_state = 1},
  [29] = {.lex_state = 4, .external_lex_state = 1},
  [30] = {.lex_state = 4, .external_lex_state = 1},
  [31] = {.lex_state = 4, .external_lex_state = 1},
  [32] = {.lex_state = 4, .external_lex_state = 1},
  [33] = {.lex_state = 4, .external_lex_state = 1},
  [34] = {.lex_state = 4, .external_lex_state = 1},
  [35] = {.lex_state = 4, .external_lex_state = 1},
  [36] = {.lex_state = 4, .external_lex_state = 1},
  [37] = {.lex_state = 4, .external_lex_state = 1},
  [38] = {.lex_state = 4, .external_lex_state = 1},
  [39] = {.lex_state = 4, .external_lex_state = 1},
  [40] = {.lex_state = 4, .external_lex_state = 1},
  [41] = {.lex_state = 4, .external_lex_state = 1},
  [42] = {.lex_state = 4, .external_lex_state = 1},
  [43] = {.lex_state = 4, .external_lex_state = 1},
  [44] = {.lex_state = 4, .external_lex_state = 1},
  [45] = {.lex_state = 4, .external_lex_state = 1},
  [46] = {.lex_state = 4, .external_lex_state = 1},
  [47] = {.lex_state = 4, .external_lex_state = 1},
  [48] = {.lex_state = 4, .external_lex_state = 1},
  [49] = {.lex_state = 4, .external_lex_state = 1},
  [50] = {.lex_state = 4, .external_lex_state = 1},
  [51] = {.lex_state = 4, .external_lex_state = 1},
  [52] = {.lex_state = 4, .external_lex_state = 1},
  [53] = {.lex_state = 4, .external_lex_state = 1},
  [54] = {.lex_state = 4, .external_lex_state = 1},
  [55] = {.lex_state = 4, .external_lex_state = 1},
  [56] = {.lex_state = 4, .external_lex_state = 1},
  [57] = {.lex_state = 4, .external_lex_state = 1},
  [58] = {.lex_state = 4, .external_lex_state = 1},
  [59] = {.lex_state = 4, .external_lex_state = 1},
  [60] = {.lex_state = 4, .external_lex_state = 1},
  [61] = {.lex_state = 4, .external_lex_state = 1},
  [62] = {.lex_state = 4, .external_lex_state = 1},
  [63] = {.lex_state = 4, .external_lex_state = 1},
  [64] = {.lex_state = 4, .external_lex_state = 1},
  [65] = {.lex_state = 4, .external_lex_state = 1},
  [66] = {.lex_state = 4, .external_lex_state = 1},
  [67] = {.lex_state = 4, .external_lex_state = 1},
  [68] = {.lex_state = 4, .external_lex_state = 1},
  [69] = {.lex_state = 4, .external_lex_state = 1},
  [70] = {.lex_state = 4, .external_lex_state = 1},
  [71] = {.lex_state = 4, .external_lex_state = 1},
  [72] = {.lex_state = 33},
  [73] = {.lex_state = 33},
  [74] = {.lex_state = 33},
  [75] = {.lex_state = 33},
  [76] = {.lex_state = 33},
  [77] = {.lex_state = 33},
  [78] = {.lex_state = 33},
  [79] = {.lex_state = 4, .external_lex_state = 1},
  [80] = {.lex_state = 4, .external_lex_state = 1},
  [81] = {.lex_state = 4, .external_lex_state = 1},
  [82] = {.lex_state = 4, .external_lex_state = 1},
  [83] = {.lex_state = 4, .external_lex_state = 1},
  [84] = {.lex_state = 4, .external_lex_state = 1},
  [85] = {.lex_state = 4, .external_lex_state = 1},
  [86] = {.lex_state = 4, .external_lex_state = 1},
  [87] = {.lex_state = 5},
  [88] = {.lex_state = 4},
  [89] = {.lex_state = 5},
  [90] = {.lex_state = 4, .external_lex_state = 1},
  [91] = {.lex_state = 4, .external_lex_state = 1},
  [92] = {.lex_state = 4, .external_lex_state = 1},
  [93] = {.lex_state = 5},
  [94] = {.lex_state = 1},
  [95] = {.lex_state = 4, .external_lex_state = 1},
  [96] = {.lex_state = 4, .external_lex_state = 1},
  [97] = {.lex_state = 4, .external_lex_state = 1},
  [98] = {.lex_state = 4, .external_lex_state = 1},
  [99] = {.lex_state = 4},
  [100] = {.lex_state = 4},
  [101] = {.lex_state = 4},
  [102] = {.lex_state = 4, .external_lex_state = 1},
  [103] = {.lex_state = 4},
  [104] = {.lex_state = 4},
  [105] = {.lex_state = 4},
  [106] = {.lex_state = 4},
  [107] = {.lex_state = 4},
  [108] = {.lex_state = 4, .external_lex_state = 1},
  [109] = {.lex_state = 4},
  [110] = {.lex_state = 4, .external_lex_state = 1},
  [111] = {.lex_state = 4},
  [112] = {.lex_state = 4},
  [113] = {.lex_state = 4},
  [114] = {.lex_state = 4},
  [115] = {.lex_state = 4},
  [116] = {.lex_state = 4},
  [117] = {.lex_state = 4},
  [118] = {.lex_state = 4},
  [119] = {.lex_state = 4},
  [120] = {.lex_state = 4},
  [121] = {.lex_state = 4},
  [122] = {.lex_state = 4},
  [123] = {.lex_state = 4},
  [124] = {.lex_state = 4},
  [125] = {.lex_state = 4},
  [126] = {.lex_state = 4},
  [127] = {.lex_state = 4},
  [128] = {.lex_state = 4},
  [129] = {.lex_state = 4},
  [130] = {.lex_state = 4},
  [131] = {.lex_state = 4},
  [132] = {.lex_state = 4},
  [133] = {.lex_state = 4, .external_lex_state = 1},
  [134] = {.lex_state = 4},
  [135] = {.lex_state = 4},
  [136] = {.lex_state = 4},
  [137] = {.lex_state = 4},
  [138] = {.lex_state = 4, .external_lex_state = 1},
  [139] = {.lex_state = 4},
  [140] = {.lex_state = 4},
  [141] = {.lex_state = 4},
  [142] = {.lex_state = 4},
  [143] = {.lex_state = 4},
  [144] = {.lex_state = 4},
  [145] = {.lex_state = 4},
  [146] = {.lex_state = 4},
  [147] = {.lex_state = 4},
  [148] = {.lex_state = 4},
  [149] = {.lex_state = 4},
  [150] = {.lex_state = 4, .external_lex_state = 1},
  [151] = {.lex_state = 4},
  [152] = {.lex_state = 4},
  [153] = {.lex_state = 4},
  [154] = {.lex_state = 4, .external_lex_state = 1},
  [155] = {.lex_state = 2},
  [156] = {.lex_state = 1},
  [157] = {.lex_state = 1},
  [158] = {.lex_state = 1},
  [159] = {.lex_state = 1},
  [160] = {.lex_state = 2},
  [161] = {.lex_state = 1},
  [162] = {.lex_state = 1},
  [163] = {.lex_state = 2},
  [164] = {.lex_state = 1},
  [165] = {.lex_state = 1},
  [166] = {.lex_state = 1},
  [167] = {.lex_state = 1},
  [168] = {.lex_state = 1},
  [169] = {.lex_state = 1},
  [170] = {.lex_state = 1},
  [171] = {.lex_state = 1},
  [172] = {.lex_state = 1},
  [173] = {.lex_state = 1},
  [174] = {.lex_state = 1},
  [175] = {.lex_state = 1},
  [176] = {.lex_state = 1},
  [177] = {.lex_state = 1},
  [178] = {.lex_state = 1},
  [179] = {.lex_state = 1},
  [180] = {.lex_state = 1},
  [181] = {.lex_state = 4},
  [182] = {.lex_state = 1},
  [183] = {.lex_state = 1},
  [184] = {.lex_state = 1},
  [185] = {.lex_state = 1},
  [186] = {.lex_state = 1},
  [187] = {.lex_state = 1},
  [188] = {.lex_state = 1},
  [189] = {.lex_state = 1},
  [190] = {.lex_state = 1},
  [191] = {.lex_state = 1},
  [192] = {.lex_state = 1},
  [193] = {.lex_state = 1},
  [194] = {.lex_state = 1},
  [195] = {.lex_state = 1},
  [196] = {.lex_state = 1},
  [197] = {.lex_state = 1},
  [198] = {.lex_state = 1},
  [199] = {.lex_state = 1},
  [200] = {.lex_state = 1},
  [201] = {.lex_state = 4},
  [202] = {.lex_state = 1},
  [203] = {.lex_state = 1},
  [204] = {.lex_state = 1},
  [205] = {.lex_state = 1},
  [206] = {.lex_state = 1},
  [207] = {.lex_state = 1},
  [208] = {.lex_state = 1},
  [209] = {.lex_state = 1},
  [210] = {.lex_state = 4},
  [211] = {.lex_state = 1},
  [212] = {.lex_state = 4, .external_lex_state = 1},
  [213] = {.lex_state = 1},
  [214] = {.lex_state = 1},
  [215] = {.lex_state = 1},
  [216] = {.lex_state = 1},
  [217] = {.lex_state = 1},
  [218] = {.lex_state = 1},
  [219] = {.lex_state = 1},
  [220] = {.lex_state = 1},
  [221] = {.lex_state = 1},
  [222] = {.lex_state = 4},
  [223] = {.lex_state = 4},
  [224] = {.lex_state = 4},
  [225] = {.lex_state = 4},
  [226] = {.lex_state = 1},
  [227] = {.lex_state = 1},
  [228] = {.lex_state = 1},
  [229] = {.lex_state = 4},
  [230] = {.lex_state = 4},
  [231] = {.lex_state = 4},
  [232] = {.lex_state = 1},
  [233] = {.lex_state = 1},
  [234] = {.lex_state = 1},
  [235] = {.lex_state = 4},
  [236] = {.lex_state = 4},
  [237] = {.lex_state = 1},
  [238] = {.lex_state = 1},
  [239] = {.lex_state = 4},
  [240] = {.lex_state = 1},
  [241] = {.lex_state = 4},
  [242] = {.lex_state = 1},
  [243] = {.lex_state = 1},
  [244] = {.lex_state = 1},
  [245] = {.lex_state = 4},
  [246] = {.lex_state = 4},
  [247] = {.lex_state = 4},
  [248] = {.lex_state = 4},
  [249] = {.lex_state = 4},
  [250] = {.lex_state = 4},
  [251] = {.lex_state = 4},
  [252] = {.lex_state = 33},
  [253] = {.lex_state = 33},
  [254] = {.lex_state = 4, .external_lex_state = 1},
  [255] = {.lex_state = 4, .external_lex_state = 1},
  [256] = {.lex_state = 4, .external_lex_state = 1},
  [257] = {.lex_state = 8},
  [258] = {.lex_state = 8},
  [259] = {.lex_state = 8},
  [260] = {.lex_state = 8},
  [261] = {.lex_state = 8},
  [262] = {.lex_state = 8},
  [263] = {.lex_state = 9},
  [264] = {.lex_state = 8},
  [265] = {.lex_state = 8},
  [266] = {.lex_state = 8},
  [267] = {.lex_state = 8},
  [268] = {.lex_state = 8},
  [269] = {.lex_state = 8},
  [270] = {.lex_state = 8},
  [271] = {.lex_state = 8},
  [272] = {.lex_state = 8},
  [273] = {.lex_state = 8},
  [274] = {.lex_state = 8},
  [275] = {.lex_state = 8},
  [276] = {.lex_state = 9},
  [277] = {.lex_state = 8},
  [278] = {.lex_state = 8},
  [279] = {.lex_state = 8},
  [280] = {.lex_state = 9},
  [281] = {.lex_state = 8},
  [282] = {.lex_state = 8},
  [283] = {.lex_state = 9},
  [284] = {.lex_state = 8},
  [285] = {.lex_state = 9},
  [286] = {.lex_state = 9},
  [287] = {.lex_state = 8},
  [288] = {.lex_state = 9},
  [289] = {.lex_state = 9},
  [290] = {.lex_state = 9},
  [291] = {.lex_state = 8},
  [292] = {.lex_state = 9},
  [293] = {.lex_state = 8},
  [294] = {.lex_state = 9},
  [295] = {.lex_state = 9},
  [296] = {.lex_state = 8},
  [297] = {.lex_state = 9},
  [298] = {.lex_state = 8},
  [299] = {.lex_state = 9},
  [300] = {.lex_state = 8},
  [301] = {.lex_state = 8},
  [302] = {.lex_state = 9},
  [303] = {.lex_state = 8},
  [304] = {.lex_state = 8},
  [305] = {.lex_state = 8},
  [306] = {.lex_state = 8},
  [307] = {.lex_state = 9},
  [308] = {.lex_state = 8},
  [309] = {.lex_state = 8},
  [310] = {.lex_state = 8},
  [311] = {.lex_state = 9},
  [312] = {.lex_state = 8},
  [313] = {.lex_state = 4},
  [314] = {.lex_state = 4},
  [315] = {.lex_state = 8},
  [316] = {.lex_state = 33},
  [317] = {.lex_state = 33},
  [318] = {.lex_state = 33},
  [319] = {.lex_state = 33},
  [320] = {.lex_state = 33},
  [321] = {.lex_state = 33},
  [322] = {.lex_state = 33},
  [323] = {.lex_state = 33},
  [324] = {.lex_state = 33},
  [325] = {.lex_state = 33},
  [326] = {.lex_state = 33},
  [327] = {.lex_state = 33},
  [328] = {.lex_state = 33},
  [329] = {.lex_state = 33},
  [330] = {.lex_state = 6},
  [331] = {.lex_state = 6},
  [332] = {.lex_state = 6},
  [333] = {.lex_state = 6},
  [334] = {.lex_state = 8},
  [335] = {.lex_state = 6},
  [336] = {.lex_state = 8},
  [337] = {.lex_state = 6},
  [338] = {.lex_state = 6},
  [339] = {.lex_state = 4},
  [340] = {.lex_state = 33},
  [341] = {.lex_state = 6},
  [342] = {.lex_state = 33},
  [343] = {.lex_state = 9},
  [344] = {.lex_state = 6},
  [345] = {.lex_state = 6},
  [346] = {.lex_state = 6},
  [347] = {.lex_state = 6},
  [348] = {.lex_state = 6},
  [349] = {.lex_state = 8},
  [350] = {.lex_state = 6},
  [351] = {.lex_state = 9},
  [352] = {.lex_state = 33},
  [353] = {.lex_state = 8},
  [354] = {.lex_state = 8},
  [355] = {.lex_state = 8},
  [356] = {.lex_state = 8},
  [357] = {.lex_state = 0},
  [358] = {.lex_state = 1},
  [359] = {.lex_state = 4},
  [360] = {.lex_state = 1},
  [361] = {.lex_state = 33},
  [362] = {.lex_state = 3},
  [363] = {.lex_state = 33},
  [364] = {.lex_state = 1},
  [365] = {.lex_state = 33},
  [366] = {.lex_state = 6},
  [367] = {.lex_state = 33},
  [368] = {.lex_state = 9},
  [369] = {.lex_state = 8},
  [370] = {.lex_state = 9},
  [371] = {.lex_state = 33},
  [372] = {.lex_state = 33},
  [373] = {.lex_state = 4},
  [374] = {.lex_state = 4},
  [375] = {.lex_state = 33},
  [376] = {.lex_state = 6},
  [377] = {.lex_state = 0},
  [378] = {.lex_state = 6},
  [379] = {.lex_state = 33},
  [380] = {.lex_state = 8},
  [381] = {.lex_state = 8},
  [382] = {.lex_state = 15},
  [383] = {.lex_state = 9},
  [384] = {.lex_state = 9},
  [385] = {.lex_state = 4},
  [386] = {.lex_state = 6},
  [387] = {.lex_state = 8},
  [388] = {.lex_state = 4},
  [389] = {.lex_state = 0},
  [390] = {.lex_state = 33},
  [391] = {.lex_state = 0},
  [392] = {.lex_state = 4},
  [393] = {.lex_state = 4},
  [394] = {.lex_state = 33},
  [395] = {.lex_state = 3},
  [396] = {.lex_state = 3},
  [397] = {.lex_state = 9},
  [398] = {.lex_state = 3},
  [399] = {.lex_state = 3},
  [400] = {.lex_state = 4},
  [401] = {.lex_state = 17},
  [402] = {.lex_state = 4},
  [403] = {.lex_state = 33},
  [404] = {.lex_state = 4},
  [405] = {.lex_state = 1},
  [406] = {.lex_state = 0},
  [407] = {.lex_state = 33},
  [408] = {.lex_state = 0},
  [409] = {.lex_state = 0},
  [410] = {.lex_state = 8},
  [411] = {.lex_state = 33},
  [412] = {.lex_state = 1},
  [413] = {.lex_state = 0},
  [414] = {.lex_state = 0},
  [415] = {.lex_state = 0},
  [416] = {.lex_state = 3},
  [417] = {.lex_state = 3},
  [418] = {.lex_state = 8},
  [419] = {.lex_state = 0},
  [420] = {.lex_state = 0},
  [421] = {.lex_state = 3},
  [422] = {.lex_state = 8},
  [423] = {.lex_state = 6},
  [424] = {.lex_state = 8},
  [425] = {.lex_state = 0},
  [426] = {.lex_state = 0},
  [427] = {.lex_state = 1},
  [428] = {.lex_state = 33},
  [429] = {.lex_state = 0},
  [430] = {.lex_state = 17},
  [431] = {.lex_state = 6},
  [432] = {.lex_state = 8},
  [433] = {.lex_state = 33},
  [434] = {.lex_state = 0},
  [435] = {.lex_state = 0},
  [436] = {.lex_state = 33},
  [437] = {.lex_state = 8},
  [438] = {.lex_state = 3},
  [439] = {.lex_state = 0},
  [440] = {.lex_state = 0},
  [441] = {.lex_state = 33},
  [442] = {.lex_state = 1},
  [443] = {.lex_state = 0},
  [444] = {.lex_state = 8},
  [445] = {.lex_state = 0},
  [446] = {.lex_state = 16},
  [447] = {.lex_state = 1},
  [448] = {.lex_state = 0},
  [449] = {.lex_state = 1},
  [450] = {.lex_state = 33},
  [451] = {.lex_state = 0},
  [452] = {.lex_state = 1},
  [453] = {.lex_state = 0},
  [454] = {.lex_state = 0},
  [455] = {.lex_state = 0},
  [456] = {.lex_state = 33},
  [457] = {.lex_state = 0},
  [458] = {.lex_state = 0},
  [459] = {.lex_state = 0},
  [460] = {.lex_state = 0},
  [461] = {.lex_state = 0},
  [462] = {.lex_state = 1},
  [463] = {.lex_state = 1},
  [464] = {.lex_state = 1},
  [465] = {.lex_state = 1},
  [466] = {.lex_state = 1},
  [467] = {.lex_state = 0},
  [468] = {.lex_state = 1},
  [469] = {.lex_state = 0},
  [470] = {.lex_state = 0},
  [471] = {.lex_state = 1},
  [472] = {.lex_state = 1},
  [473] = {.lex_state = 4},
  [474] = {.lex_state = 0},
  [475] = {.lex_state = 0},
  [476] = {.lex_state = 0},
  [477] = {.lex_state = 4},
  [478] = {.lex_state = 1},
  [479] = {.lex_state = 1},
  [480] = {.lex_state = 1},
  [481] = {.lex_state = 0},
  [482] = {.lex_state = 0},
  [483] = {.lex_state = 1},
  [484] = {.lex_state = 0},
  [485] = {.lex_state = 0},
  [486] = {.lex_state = 0},
  [487] = {.lex_state = 33},
  [488] = {.lex_state = 0},
  [489] = {.lex_state = 1},
  [490] = {.lex_state = 0},
  [491] = {.lex_state = 1},
  [492] = {.lex_state = 0},
  [493] = {.lex_state = 33},
  [494] = {.lex_state = 0},
  [495] = {.lex_state = 8},
  [496] = {.lex_state = 0},
  [497] = {.lex_state = 1},
  [498] = {.lex_state = 17},
  [499] = {.lex_state = 0},
  [500] = {.lex_state = 1},
  [501] = {.lex_state = 0},
  [502] = {.lex_state = 0},
  [503] = {.lex_state = 1},
  [504] = {.lex_state = 1},
  [505] = {.lex_state = 1},
  [506] = {.lex_state = 0},
  [507] = {.lex_state = 1},
  [508] = {.lex_state = 1},
  [509] = {.lex_state = 1},
  [510] = {.lex_state = 0},
  [511] = {.lex_state = 17},
  [512] = {.lex_state = 4},
  [513] = {.lex_state = 1},
  [514] = {.lex_state = 0},
  [515] = {.lex_state = 1},
  [516] = {.lex_state = 1},
  [517] = {.lex_state = 0},
  [518] = {.lex_state = 1},
  [519] = {.lex_state = 0},
  [520] = {.lex_state = 4},
  [521] = {.lex_state = 4},
  [522] = {.lex_state = 0},
  [523] = {.lex_state = 1},
  [524] = {.lex_state = 4},
  [525] = {.lex_state = 0},
  [526] = {.lex_state = 0},
  [527] = {.lex_state = 33},
  [528] = {.lex_state = 8},
  [529] = {.lex_state = 0},
  [530] = {.lex_state = 1},
  [531] = {.lex_state = 17},
  [532] = {.lex_state = 1},
  [533] = {.lex_state = 1},
  [534] = {.lex_state = 0},
  [535] = {.lex_state = 1},
  [536] = {.lex_state = 1},
  [537] = {.lex_state = 0},
  [538] = {.lex_state = 0},
  [539] = {.lex_state = 1},
  [540] = {.lex_state = 0},
  [541] = {.lex_state = 1},
  [542] = {.lex_state = 1},
  [543] = {.lex_state = 1},
  [544] = {.lex_state = 1},
  [545] = {.lex_state = 0},
  [546] = {.lex_state = 0},
  [547] = {.lex_state = 1},
  [548] = {.lex_state = 17},
  [549] = {.lex_state = 0},
  [550] = {.lex_state = 4},
  [551] = {.lex_state = 1},
  [552] = {.lex_state = 0},
  [553] = {.lex_state = 1},
  [554] = {.lex_state = 1},
  [555] = {.lex_state = 1},
  [556] = {.lex_state = 1},
  [557] = {.lex_state = 1},
  [558] = {.lex_state = 8},
  [559] = {.lex_state = 1},
  [560] = {.lex_state = 1},
  [561] = {.lex_state = 4},
  [562] = {.lex_state = 1},
  [563] = {.lex_state = 1},
  [564] = {.lex_state = 0},
  [565] = {.lex_state = 33},
  [566] = {.lex_state = 1},
  [567] = {.lex_state = 1},
  [568] = {.lex_state = 1},
  [569] = {.lex_state = 1},
  [570] = {.lex_state = 0},
  [571] = {.lex_state = 0},
  [572] = {.lex_state = 0},
  [573] = {.lex_state = 0},
  [574] = {.lex_state = 18},
  [575] = {.lex_state = 0},
  [576] = {.lex_state = 4},
  [577] = {.lex_state = 0},
  [578] = {.lex_state = 17},
  [579] = {.lex_state = 17},
  [580] = {.lex_state = 0},
  [581] = {.lex_state = 0},
  [582] = {.lex_state = 0},
  [583] = {.lex_state = 18},
  [584] = {.lex_state = 0},
  [585] = {.lex_state = 0},
  [586] = {.lex_state = 17},
  [587] = {.lex_state = 0},
  [588] = {.lex_state = 0},
  [589] = {.lex_state = 0},
  [590] = {.lex_state = 0},
  [591] = {.lex_state = 0},
  [592] = {.lex_state = 0},
  [593] = {.lex_state = 0},
  [594] = {.lex_state = 0},
  [595] = {.lex_state = 33},
  [596] = {.lex_state = 0},
  [597] = {.lex_state = 0},
  [598] = {.lex_state = 0},
  [599] = {.lex_state = 33},
  [600] = {.lex_state = 0},
  [601] = {.lex_state = 0},
  [602] = {.lex_state = 0},
  [603] = {.lex_state = 0},
  [604] = {.lex_state = 33},
  [605] = {.lex_state = 0},
  [606] = {.lex_state = 0},
  [607] = {.lex_state = 0},
  [608] = {.lex_state = 0},
  [609] = {.lex_state = 0},
  [610] = {.lex_state = 0},
  [611] = {.lex_state = 0},
  [612] = {.lex_state = 0},
  [613] = {.lex_state = 0},
  [614] = {.lex_state = 33},
  [615] = {.lex_state = 0},
  [616] = {.lex_state = 0},
  [617] = {.lex_state = 0},
  [618] = {.lex_state = 0},
  [619] = {.lex_state = 0},
  [620] = {.lex_state = 0},
  [621] = {.lex_state = 33},
  [622] = {.lex_state = 4},
  [623] = {.lex_state = 0},
  [624] = {.lex_state = 4},
  [625] = {.lex_state = 33},
  [626] = {.lex_state = 0},
  [627] = {.lex_state = 0},
  [628] = {.lex_state = 0},
  [629] = {.lex_state = 0},
  [630] = {.lex_state = 0},
  [631] = {.lex_state = 17},
  [632] = {.lex_state = 0},
  [633] = {.lex_state = 17},
  [634] = {.lex_state = 4},
  [635] = {.lex_state = 0},
  [636] = {.lex_state = 17},
  [637] = {.lex_state = 17},
  [638] = {.lex_state = 0},
  [639] = {.lex_state = 0},
  [640] = {.lex_state = 0},
  [641] = {.lex_state = 4},
  [642] = {.lex_state = 0},
  [643] = {.lex_state = 0},
  [644] = {.lex_state = 0},
  [645] = {.lex_state = 0},
  [646] = {.lex_state = 0},
  [647] = {.lex_state = 33},
  [648] = {.lex_state = 0},
  [649] = {.lex_state = 0},
  [650] = {.lex_state = 0},
  [651] = {.lex_state = 0},
  [652] = {.lex_state = 17},
  [653] = {.lex_state = 4},
  [654] = {.lex_state = 33},
  [655] = {.lex_state = 0},
  [656] = {.lex_state = 0},
  [657] = {.lex_state = 17},
  [658] = {.lex_state = 33},
  [659] = {.lex_state = 17},
  [660] = {.lex_state = 17},
};

enum {
  ts_external_token_float_literal = 0,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_float_literal] = sym_float_literal,
};

static const bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_float_literal] = true,
  },
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_lowercase_identifier] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_] = ACTIONS(1),
    [anon_sym_priv] = ACTIONS(1),
    [anon_sym_pub] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_readonly] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_type] = ACTIONS(1),
    [anon_sym_struct] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_enum] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_func] = ACTIONS(1),
    [anon_sym_interface] = ACTIONS(1),
    [anon_sym__] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_BSLASH_LPAREN] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [sym_integer_literal] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [sym_escape_seqence] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_STAR_STAR] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_STAR_EQ] = ACTIONS(1),
    [anon_sym_SLASH_EQ] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_PLUS_EQ] = ACTIONS(1),
    [anon_sym_DASH_EQ] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_AMP_AMP] = ACTIONS(1),
    [anon_sym_PIPE_PIPE] = ACTIONS(1),
    [anon_sym_DOT_DOT] = ACTIONS(1),
    [anon_sym_fn] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [aux_sym_accessor_token1] = ACTIONS(1),
    [anon_sym_match] = ACTIONS(1),
    [anon_sym_EQ_GT] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_break] = ACTIONS(1),
    [anon_sym_continue] = ACTIONS(1),
    [anon_sym_COLON_EQ] = ACTIONS(1),
    [anon_sym_var] = ACTIONS(1),
    [anon_sym_while] = ACTIONS(1),
    [anon_sym_return] = ACTIONS(1),
    [anon_sym_as] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [sym_mutability] = ACTIONS(1),
    [sym_uppercase_identifier] = ACTIONS(1),
    [sym_colon_colon_uppercase_identifier] = ACTIONS(1),
    [sym_colon_colon_lowercase_identifier] = ACTIONS(1),
    [sym_dot_identifier] = ACTIONS(1),
    [sym_package_identifier] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [sym_float_literal] = ACTIONS(1),
  },
  [1] = {
    [sym_structure] = STATE(656),
    [sym_structure_item] = STATE(449),
    [sym_visibility] = STATE(450),
    [sym_type_defintion] = STATE(452),
    [sym_struct_definition] = STATE(452),
    [sym_enum_definition] = STATE(452),
    [sym_value_definition] = STATE(452),
    [sym_function_definition] = STATE(452),
    [sym_interface_definition] = STATE(452),
    [sym_pub] = STATE(456),
    [aux_sym_structure_repeat1] = STATE(252),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_priv] = ACTIONS(7),
    [anon_sym_pub] = ACTIONS(9),
    [anon_sym_type] = ACTIONS(11),
    [anon_sym_struct] = ACTIONS(13),
    [anon_sym_enum] = ACTIONS(15),
    [anon_sym_let] = ACTIONS(17),
    [anon_sym_func] = ACTIONS(19),
    [anon_sym_interface] = ACTIONS(21),
    [sym_comment] = ACTIONS(3),
  },
  [2] = {
    [sym_expression] = STATE(244),
    [sym_simple_expression] = STATE(161),
    [sym_atomic_expression] = STATE(218),
    [sym_string_interpolation] = STATE(164),
    [sym_literal] = STATE(164),
    [sym_boolean_literal] = STATE(219),
    [sym_char_literal] = STATE(219),
    [sym_string_literal] = STATE(219),
    [sym_unary_expression] = STATE(218),
    [sym_binary_expression] = STATE(218),
    [sym_struct_expression] = STATE(218),
    [sym_struct_field_expression] = STATE(603),
    [sym_labeled_expression] = STATE(593),
    [sym_labeled_expression_pun] = STATE(617),
    [sym_nonempty_block_expression] = STATE(218),
    [sym_anonymous_lambda_expression] = STATE(218),
    [sym_constructor_expression] = STATE(218),
    [sym_apply_expression] = STATE(218),
    [sym_array_access_expression] = STATE(158),
    [sym_dot_apply_expression] = STATE(218),
    [sym_access_expression] = STATE(218),
    [sym_method_expression] = STATE(218),
    [sym_unit_expression] = STATE(218),
    [sym_tuple_expression] = STATE(218),
    [sym_constraint_expression] = STATE(218),
    [sym_array_expression] = STATE(218),
    [sym_match_expression] = STATE(204),
    [sym_if_expression] = STATE(204),
    [sym_statement_expression] = STATE(568),
    [sym_let_expression] = STATE(566),
    [sym_shorthand_let_expression] = STATE(566),
    [sym_shorthand_let_pattern] = STATE(613),
    [sym_var_expression] = STATE(566),
    [sym_assign_expression] = STATE(566),
    [sym_left_value] = STATE(653),
    [sym_named_lambda_expression] = STATE(566),
    [sym_while_expression] = STATE(566),
    [sym_return_expression] = STATE(566),
    [sym_qualified_identifier] = STATE(158),
    [sym_qualified_type_identifier] = STATE(651),
    [aux_sym_block_expression_repeat1] = STATE(4),
    [sym_lowercase_identifier] = ACTIONS(23),
    [anon_sym_LPAREN] = ACTIONS(25),
    [anon_sym_LBRACE] = ACTIONS(27),
    [anon_sym_RBRACE] = ACTIONS(29),
    [anon_sym_let] = ACTIONS(31),
    [anon_sym__] = ACTIONS(33),
    [anon_sym_DQUOTE] = ACTIONS(35),
    [anon_sym_true] = ACTIONS(37),
    [anon_sym_false] = ACTIONS(37),
    [sym_integer_literal] = ACTIONS(39),
    [anon_sym_SQUOTE] = ACTIONS(41),
    [anon_sym_DASH] = ACTIONS(43),
    [anon_sym_PLUS] = ACTIONS(43),
    [anon_sym_DOT_DOT] = ACTIONS(45),
    [anon_sym_fn] = ACTIONS(47),
    [anon_sym_LBRACK] = ACTIONS(49),
    [anon_sym_match] = ACTIONS(51),
    [anon_sym_if] = ACTIONS(53),
    [anon_sym_break] = ACTIONS(55),
    [anon_sym_continue] = ACTIONS(55),
    [anon_sym_var] = ACTIONS(57),
    [anon_sym_while] = ACTIONS(59),
    [anon_sym_return] = ACTIONS(61),
    [sym_uppercase_identifier] = ACTIONS(63),
    [sym_identifier] = ACTIONS(65),
    [sym_package_identifier] = ACTIONS(67),
    [sym_comment] = ACTIONS(3),
    [sym_float_literal] = ACTIONS(39),
  },
  [3] = {
    [sym_expression] = STATE(244),
    [sym_simple_expression] = STATE(161),
    [sym_atomic_expression] = STATE(218),
    [sym_string_interpolation] = STATE(164),
    [sym_literal] = STATE(164),
    [sym_boolean_literal] = STATE(219),
    [sym_char_literal] = STATE(219),
    [sym_string_literal] = STATE(219),
    [sym_unary_expression] = STATE(218),
    [sym_binary_expression] = STATE(218),
    [sym_struct_expression] = STATE(218),
    [sym_struct_field_expression] = STATE(609),
    [sym_labeled_expression] = STATE(593),
    [sym_labeled_expression_pun] = STATE(617),
    [sym_nonempty_block_expression] = STATE(218),
    [sym_anonymous_lambda_expression] = STATE(218),
    [sym_constructor_expression] = STATE(218),
    [sym_apply_expression] = STATE(218),
    [sym_array_access_expression] = STATE(158),
    [sym_dot_apply_expression] = STATE(218),
    [sym_access_expression] = STATE(218),
    [sym_method_expression] = STATE(218),
    [sym_unit_expression] = STATE(218),
    [sym_tuple_expression] = STATE(218),
    [sym_constraint_expression] = STATE(218),
    [sym_array_expression] = STATE(218),
    [sym_match_expression] = STATE(204),
    [sym_if_expression] = STATE(204),
    [sym_statement_expression] = STATE(568),
    [sym_let_expression] = STATE(566),
    [sym_shorthand_let_expression] = STATE(566),
    [sym_shorthand_let_pattern] = STATE(613),
    [sym_var_expression] = STATE(566),
    [sym_assign_expression] = STATE(566),
    [sym_left_value] = STATE(653),
    [sym_named_lambda_expression] = STATE(566),
    [sym_while_expression] = STATE(566),
    [sym_return_expression] = STATE(566),
    [sym_qualified_identifier] = STATE(158),
    [sym_qualified_type_identifier] = STATE(651),
    [aux_sym_block_expression_repeat1] = STATE(8),
    [sym_lowercase_identifier] = ACTIONS(23),
    [anon_sym_LPAREN] = ACTIONS(25),
    [anon_sym_LBRACE] = ACTIONS(27),
    [anon_sym_RBRACE] = ACTIONS(69),
    [anon_sym_let] = ACTIONS(31),
    [anon_sym__] = ACTIONS(33),
    [anon_sym_DQUOTE] = ACTIONS(35),
    [anon_sym_true] = ACTIONS(37),
    [anon_sym_false] = ACTIONS(37),
    [sym_integer_literal] = ACTIONS(39),
    [anon_sym_SQUOTE] = ACTIONS(41),
    [anon_sym_DASH] = ACTIONS(43),
    [anon_sym_PLUS] = ACTIONS(43),
    [anon_sym_DOT_DOT] = ACTIONS(71),
    [anon_sym_fn] = ACTIONS(47),
    [anon_sym_LBRACK] = ACTIONS(49),
    [anon_sym_match] = ACTIONS(51),
    [anon_sym_if] = ACTIONS(53),
    [anon_sym_break] = ACTIONS(55),
    [anon_sym_continue] = ACTIONS(55),
    [anon_sym_var] = ACTIONS(57),
    [anon_sym_while] = ACTIONS(59),
    [anon_sym_return] = ACTIONS(61),
    [sym_uppercase_identifier] = ACTIONS(63),
    [sym_identifier] = ACTIONS(65),
    [sym_package_identifier] = ACTIONS(67),
    [sym_comment] = ACTIONS(3),
    [sym_float_literal] = ACTIONS(39),
  },
  [4] = {
    [sym_expression] = STATE(244),
    [sym_simple_expression] = STATE(161),
    [sym_atomic_expression] = STATE(218),
    [sym_string_interpolation] = STATE(164),
    [sym_literal] = STATE(164),
    [sym_boolean_literal] = STATE(219),
    [sym_char_literal] = STATE(219),
    [sym_string_literal] = STATE(219),
    [sym_unary_expression] = STATE(218),
    [sym_binary_expression] = STATE(218),
    [sym_struct_expression] = STATE(218),
    [sym_nonempty_block_expression] = STATE(218),
    [sym_anonymous_lambda_expression] = STATE(218),
    [sym_constructor_expression] = STATE(218),
    [sym_apply_expression] = STATE(218),
    [sym_array_access_expression] = STATE(158),
    [sym_dot_apply_expression] = STATE(218),
    [sym_access_expression] = STATE(218),
    [sym_method_expression] = STATE(218),
    [sym_unit_expression] = STATE(218),
    [sym_tuple_expression] = STATE(218),
    [sym_constraint_expression] = STATE(218),
    [sym_array_expression] = STATE(218),
    [sym_match_expression] = STATE(204),
    [sym_if_expression] = STATE(204),
    [sym_statement_expression] = STATE(568),
    [sym_let_expression] = STATE(566),
    [sym_shorthand_let_expression] = STATE(566),
    [sym_shorthand_let_pattern] = STATE(613),
    [sym_var_expression] = STATE(566),
    [sym_assign_expression] = STATE(566),
    [sym_left_value] = STATE(653),
    [sym_named_lambda_expression] = STATE(566),
    [sym_while_expression] = STATE(566),
    [sym_return_expression] = STATE(566),
    [sym_qualified_identifier] = STATE(158),
    [sym_qualified_type_identifier] = STATE(651),
    [aux_sym_block_expression_repeat1] = STATE(5),
    [sym_lowercase_identifier] = ACTIONS(73),
    [anon_sym_LPAREN] = ACTIONS(25),
    [anon_sym_LBRACE] = ACTIONS(27),
    [anon_sym_RBRACE] = ACTIONS(75),
    [anon_sym_let] = ACTIONS(31),
    [anon_sym__] = ACTIONS(33),
    [anon_sym_DQUOTE] = ACTIONS(35),
    [anon_sym_true] = ACTIONS(37),
    [anon_sym_false] = ACTIONS(37),
    [sym_integer_literal] = ACTIONS(39),
    [anon_sym_SQUOTE] = ACTIONS(41),
    [anon_sym_DASH] = ACTIONS(43),
    [anon_sym_PLUS] = ACTIONS(43),
    [anon_sym_fn] = ACTIONS(47),
    [anon_sym_LBRACK] = ACTIONS(49),
    [anon_sym_match] = ACTIONS(51),
    [anon_sym_if] = ACTIONS(53),
    [anon_sym_break] = ACTIONS(55),
    [anon_sym_continue] = ACTIONS(55),
    [anon_sym_var] = ACTIONS(57),
    [anon_sym_while] = ACTIONS(59),
    [anon_sym_return] = ACTIONS(61),
    [sym_uppercase_identifier] = ACTIONS(63),
    [sym_identifier] = ACTIONS(65),
    [sym_package_identifier] = ACTIONS(67),
    [sym_comment] = ACTIONS(3),
    [sym_float_literal] = ACTIONS(39),
  },
  [5] = {
    [sym_expression] = STATE(244),
    [sym_simple_expression] = STATE(161),
    [sym_atomic_expression] = STATE(218),
    [sym_string_interpolation] = STATE(164),
    [sym_literal] = STATE(164),
    [sym_boolean_literal] = STATE(219),
    [sym_char_literal] = STATE(219),
    [sym_string_literal] = STATE(219),
    [sym_unary_expression] = STATE(218),
    [sym_binary_expression] = STATE(218),
    [sym_struct_expression] = STATE(218),
    [sym_nonempty_block_expression] = STATE(218),
    [sym_anonymous_lambda_expression] = STATE(218),
    [sym_constructor_expression] = STATE(218),
    [sym_apply_expression] = STATE(218),
    [sym_array_access_expression] = STATE(158),
    [sym_dot_apply_expression] = STATE(218),
    [sym_access_expression] = STATE(218),
    [sym_method_expression] = STATE(218),
    [sym_unit_expression] = STATE(218),
    [sym_tuple_expression] = STATE(218),
    [sym_constraint_expression] = STATE(218),
    [sym_array_expression] = STATE(218),
    [sym_match_expression] = STATE(204),
    [sym_if_expression] = STATE(204),
    [sym_statement_expression] = STATE(568),
    [sym_let_expression] = STATE(566),
    [sym_shorthand_let_expression] = STATE(566),
    [sym_shorthand_let_pattern] = STATE(613),
    [sym_var_expression] = STATE(566),
    [sym_assign_expression] = STATE(566),
    [sym_left_value] = STATE(653),
    [sym_named_lambda_expression] = STATE(566),
    [sym_while_expression] = STATE(566),
    [sym_return_expression] = STATE(566),
    [sym_qualified_identifier] = STATE(158),
    [sym_qualified_type_identifier] = STATE(651),
    [aux_sym_block_expression_repeat1] = STATE(5),
    [sym_lowercase_identifier] = ACTIONS(77),
    [anon_sym_LPAREN] = ACTIONS(80),
    [anon_sym_LBRACE] = ACTIONS(83),
    [anon_sym_RBRACE] = ACTIONS(86),
    [anon_sym_let] = ACTIONS(88),
    [anon_sym__] = ACTIONS(91),
    [anon_sym_DQUOTE] = ACTIONS(94),
    [anon_sym_true] = ACTIONS(97),
    [anon_sym_false] = ACTIONS(97),
    [sym_integer_literal] = ACTIONS(100),
    [anon_sym_SQUOTE] = ACTIONS(103),
    [anon_sym_DASH] = ACTIONS(106),
    [anon_sym_PLUS] = ACTIONS(106),
    [anon_sym_fn] = ACTIONS(109),
    [anon_sym_LBRACK] = ACTIONS(112),
    [anon_sym_match] = ACTIONS(115),
    [anon_sym_if] = ACTIONS(118),
    [anon_sym_break] = ACTIONS(121),
    [anon_sym_continue] = ACTIONS(121),
    [anon_sym_var] = ACTIONS(124),
    [anon_sym_while] = ACTIONS(127),
    [anon_sym_return] = ACTIONS(130),
    [sym_uppercase_identifier] = ACTIONS(133),
    [sym_identifier] = ACTIONS(136),
    [sym_package_identifier] = ACTIONS(139),
    [sym_comment] = ACTIONS(3),
    [sym_float_literal] = ACTIONS(100),
  },
  [6] = {
    [sym_expression] = STATE(244),
    [sym_simple_expression] = STATE(161),
    [sym_atomic_expression] = STATE(218),
    [sym_string_interpolation] = STATE(164),
    [sym_literal] = STATE(164),
    [sym_boolean_literal] = STATE(219),
    [sym_char_literal] = STATE(219),
    [sym_string_literal] = STATE(219),
    [sym_unary_expression] = STATE(218),
    [sym_binary_expression] = STATE(218),
    [sym_struct_expression] = STATE(218),
    [sym_nonempty_block_expression] = STATE(218),
    [sym_anonymous_lambda_expression] = STATE(218),
    [sym_constructor_expression] = STATE(218),
    [sym_apply_expression] = STATE(218),
    [sym_array_access_expression] = STATE(158),
    [sym_dot_apply_expression] = STATE(218),
    [sym_access_expression] = STATE(218),
    [sym_method_expression] = STATE(218),
    [sym_unit_expression] = STATE(218),
    [sym_tuple_expression] = STATE(218),
    [sym_constraint_expression] = STATE(218),
    [sym_array_expression] = STATE(218),
    [sym_match_expression] = STATE(204),
    [sym_if_expression] = STATE(204),
    [sym_statement_expression] = STATE(568),
    [sym_let_expression] = STATE(566),
    [sym_shorthand_let_expression] = STATE(566),
    [sym_shorthand_let_pattern] = STATE(613),
    [sym_var_expression] = STATE(566),
    [sym_assign_expression] = STATE(566),
    [sym_left_value] = STATE(653),
    [sym_named_lambda_expression] = STATE(566),
    [sym_while_expression] = STATE(566),
    [sym_return_expression] = STATE(566),
    [sym_qualified_identifier] = STATE(158),
    [sym_qualified_type_identifier] = STATE(651),
    [aux_sym_block_expression_repeat1] = STATE(7),
    [sym_lowercase_identifier] = ACTIONS(73),
    [anon_sym_LPAREN] = ACTIONS(25),
    [anon_sym_LBRACE] = ACTIONS(27),
    [anon_sym_RBRACE] = ACTIONS(142),
    [anon_sym_let] = ACTIONS(31),
    [anon_sym__] = ACTIONS(33),
    [anon_sym_DQUOTE] = ACTIONS(35),
    [anon_sym_true] = ACTIONS(37),
    [anon_sym_false] = ACTIONS(37),
    [sym_integer_literal] = ACTIONS(39),
    [anon_sym_SQUOTE] = ACTIONS(41),
    [anon_sym_DASH] = ACTIONS(43),
    [anon_sym_PLUS] = ACTIONS(43),
    [anon_sym_fn] = ACTIONS(47),
    [anon_sym_LBRACK] = ACTIONS(49),
    [anon_sym_match] = ACTIONS(51),
    [anon_sym_if] = ACTIONS(53),
    [anon_sym_break] = ACTIONS(55),
    [anon_sym_continue] = ACTIONS(55),
    [anon_sym_var] = ACTIONS(57),
    [anon_sym_while] = ACTIONS(59),
    [anon_sym_return] = ACTIONS(61),
    [sym_uppercase_identifier] = ACTIONS(63),
    [sym_identifier] = ACTIONS(65),
    [sym_package_identifier] = ACTIONS(67),
    [sym_comment] = ACTIONS(3),
    [sym_float_literal] = ACTIONS(39),
  },
  [7] = {
    [sym_expression] = STATE(244),
    [sym_simple_expression] = STATE(161),
    [sym_atomic_expression] = STATE(218),
    [sym_string_interpolation] = STATE(164),
    [sym_literal] = STATE(164),
    [sym_boolean_literal] = STATE(219),
    [sym_char_literal] = STATE(219),
    [sym_string_literal] = STATE(219),
    [sym_unary_expression] = STATE(218),
    [sym_binary_expression] = STATE(218),
    [sym_struct_expression] = STATE(218),
    [sym_nonempty_block_expression] = STATE(218),
    [sym_anonymous_lambda_expression] = STATE(218),
    [sym_constructor_expression] = STATE(218),
    [sym_apply_expression] = STATE(218),
    [sym_array_access_expression] = STATE(158),
    [sym_dot_apply_expression] = STATE(218),
    [sym_access_expression] = STATE(218),
    [sym_method_expression] = STATE(218),
    [sym_unit_expression] = STATE(218),
    [sym_tuple_expression] = STATE(218),
    [sym_constraint_expression] = STATE(218),
    [sym_array_expression] = STATE(218),
    [sym_match_expression] = STATE(204),
    [sym_if_expression] = STATE(204),
    [sym_statement_expression] = STATE(568),
    [sym_let_expression] = STATE(566),
    [sym_shorthand_let_expression] = STATE(566),
    [sym_shorthand_let_pattern] = STATE(613),
    [sym_var_expression] = STATE(566),
    [sym_assign_expression] = STATE(566),
    [sym_left_value] = STATE(653),
    [sym_named_lambda_expression] = STATE(566),
    [sym_while_expression] = STATE(566),
    [sym_return_expression] = STATE(566),
    [sym_qualified_identifier] = STATE(158),
    [sym_qualified_type_identifier] = STATE(651),
    [aux_sym_block_expression_repeat1] = STATE(5),
    [sym_lowercase_identifier] = ACTIONS(73),
    [anon_sym_LPAREN] = ACTIONS(25),
    [anon_sym_LBRACE] = ACTIONS(27),
    [anon_sym_RBRACE] = ACTIONS(144),
    [anon_sym_let] = ACTIONS(31),
    [anon_sym__] = ACTIONS(33),
    [anon_sym_DQUOTE] = ACTIONS(35),
    [anon_sym_true] = ACTIONS(37),
    [anon_sym_false] = ACTIONS(37),
    [sym_integer_literal] = ACTIONS(39),
    [anon_sym_SQUOTE] = ACTIONS(41),
    [anon_sym_DASH] = ACTIONS(43),
    [anon_sym_PLUS] = ACTIONS(43),
    [anon_sym_fn] = ACTIONS(47),
    [anon_sym_LBRACK] = ACTIONS(49),
    [anon_sym_match] = ACTIONS(51),
    [anon_sym_if] = ACTIONS(53),
    [anon_sym_break] = ACTIONS(55),
    [anon_sym_continue] = ACTIONS(55),
    [anon_sym_var] = ACTIONS(57),
    [anon_sym_while] = ACTIONS(59),
    [anon_sym_return] = ACTIONS(61),
    [sym_uppercase_identifier] = ACTIONS(63),
    [sym_identifier] = ACTIONS(65),
    [sym_package_identifier] = ACTIONS(67),
    [sym_comment] = ACTIONS(3),
    [sym_float_literal] = ACTIONS(39),
  },
  [8] = {
    [sym_expression] = STATE(244),
    [sym_simple_expression] = STATE(161),
    [sym_atomic_expression] = STATE(218),
    [sym_string_interpolation] = STATE(164),
    [sym_literal] = STATE(164),
    [sym_boolean_literal] = STATE(219),
    [sym_char_literal] = STATE(219),
    [sym_string_literal] = STATE(219),
    [sym_unary_expression] = STATE(218),
    [sym_binary_expression] = STATE(218),
    [sym_struct_expression] = STATE(218),
    [sym_nonempty_block_expression] = STATE(218),
    [sym_anonymous_lambda_expression] = STATE(218),
    [sym_constructor_expression] = STATE(218),
    [sym_apply_expression] = STATE(218),
    [sym_array_access_expression] = STATE(158),
    [sym_dot_apply_expression] = STATE(218),
    [sym_access_expression] = STATE(218),
    [sym_method_expression] = STATE(218),
    [sym_unit_expression] = STATE(218),
    [sym_tuple_expression] = STATE(218),
    [sym_constraint_expression] = STATE(218),
    [sym_array_expression] = STATE(218),
    [sym_match_expression] = STATE(204),
    [sym_if_expression] = STATE(204),
    [sym_statement_expression] = STATE(568),
    [sym_let_expression] = STATE(566),
    [sym_shorthand_let_expression] = STATE(566),
    [sym_shorthand_let_pattern] = STATE(613),
    [sym_var_expression] = STATE(566),
    [sym_assign_expression] = STATE(566),
    [sym_left_value] = STATE(653),
    [sym_named_lambda_expression] = STATE(566),
    [sym_while_expression] = STATE(566),
    [sym_return_expression] = STATE(566),
    [sym_qualified_identifier] = STATE(158),
    [sym_qualified_type_identifier] = STATE(651),
    [aux_sym_block_expression_repeat1] = STATE(5),
    [sym_lowercase_identifier] = ACTIONS(73),
    [anon_sym_LPAREN] = ACTIONS(25),
    [anon_sym_LBRACE] = ACTIONS(27),
    [anon_sym_RBRACE] = ACTIONS(146),
    [anon_sym_let] = ACTIONS(31),
    [anon_sym__] = ACTIONS(33),
    [anon_sym_DQUOTE] = ACTIONS(35),
    [anon_sym_true] = ACTIONS(37),
    [anon_sym_false] = ACTIONS(37),
    [sym_integer_literal] = ACTIONS(39),
    [anon_sym_SQUOTE] = ACTIONS(41),
    [anon_sym_DASH] = ACTIONS(43),
    [anon_sym_PLUS] = ACTIONS(43),
    [anon_sym_fn] = ACTIONS(47),
    [anon_sym_LBRACK] = ACTIONS(49),
    [anon_sym_match] = ACTIONS(51),
    [anon_sym_if] = ACTIONS(53),
    [anon_sym_break] = ACTIONS(55),
    [anon_sym_continue] = ACTIONS(55),
    [anon_sym_var] = ACTIONS(57),
    [anon_sym_while] = ACTIONS(59),
    [anon_sym_return] = ACTIONS(61),
    [sym_uppercase_identifier] = ACTIONS(63),
    [sym_identifier] = ACTIONS(65),
    [sym_package_identifier] = ACTIONS(67),
    [sym_comment] = ACTIONS(3),
    [sym_float_literal] = ACTIONS(39),
  },
  [9] = {
    [sym_expression] = STATE(244),
    [sym_simple_expression] = STATE(161),
    [sym_atomic_expression] = STATE(218),
    [sym_string_interpolation] = STATE(164),
    [sym_literal] = STATE(164),
    [sym_boolean_literal] = STATE(219),
    [sym_char_literal] = STATE(219),
    [sym_string_literal] = STATE(219),
    [sym_unary_expression] = STATE(218),
    [sym_binary_expression] = STATE(218),
    [sym_struct_expression] = STATE(218),
    [sym_nonempty_block_expression] = STATE(218),
    [sym_anonymous_lambda_expression] = STATE(218),
    [sym_constructor_expression] = STATE(218),
    [sym_apply_expression] = STATE(218),
    [sym_array_access_expression] = STATE(158),
    [sym_dot_apply_expression] = STATE(218),
    [sym_access_expression] = STATE(218),
    [sym_method_expression] = STATE(218),
    [sym_unit_expression] = STATE(218),
    [sym_tuple_expression] = STATE(218),
    [sym_constraint_expression] = STATE(218),
    [sym_array_expression] = STATE(218),
    [sym_match_expression] = STATE(204),
    [sym_if_expression] = STATE(204),
    [sym_statement_expression] = STATE(568),
    [sym_let_expression] = STATE(566),
    [sym_shorthand_let_expression] = STATE(566),
    [sym_shorthand_let_pattern] = STATE(613),
    [sym_var_expression] = STATE(566),
    [sym_assign_expression] = STATE(566),
    [sym_left_value] = STATE(653),
    [sym_named_lambda_expression] = STATE(566),
    [sym_while_expression] = STATE(566),
    [sym_return_expression] = STATE(566),
    [sym_qualified_identifier] = STATE(158),
    [sym_qualified_type_identifier] = STATE(651),
    [aux_sym_block_expression_repeat1] = STATE(5),
    [sym_lowercase_identifier] = ACTIONS(73),
    [anon_sym_LPAREN] = ACTIONS(25),
    [anon_sym_LBRACE] = ACTIONS(27),
    [anon_sym_RBRACE] = ACTIONS(148),
    [anon_sym_let] = ACTIONS(31),
    [anon_sym__] = ACTIONS(33),
    [anon_sym_DQUOTE] = ACTIONS(35),
    [anon_sym_true] = ACTIONS(37),
    [anon_sym_false] = ACTIONS(37),
    [sym_integer_literal] = ACTIONS(39),
    [anon_sym_SQUOTE] = ACTIONS(41),
    [anon_sym_DASH] = ACTIONS(43),
    [anon_sym_PLUS] = ACTIONS(43),
    [anon_sym_fn] = ACTIONS(47),
    [anon_sym_LBRACK] = ACTIONS(49),
    [anon_sym_match] = ACTIONS(51),
    [anon_sym_if] = ACTIONS(53),
    [anon_sym_break] = ACTIONS(55),
    [anon_sym_continue] = ACTIONS(55),
    [anon_sym_var] = ACTIONS(57),
    [anon_sym_while] = ACTIONS(59),
    [anon_sym_return] = ACTIONS(61),
    [sym_uppercase_identifier] = ACTIONS(63),
    [sym_identifier] = ACTIONS(65),
    [sym_package_identifier] = ACTIONS(67),
    [sym_comment] = ACTIONS(3),
    [sym_float_literal] = ACTIONS(39),
  },
  [10] = {
    [sym_expression] = STATE(244),
    [sym_simple_expression] = STATE(161),
    [sym_atomic_expression] = STATE(218),
    [sym_string_interpolation] = STATE(164),
    [sym_literal] = STATE(164),
    [sym_boolean_literal] = STATE(219),
    [sym_char_literal] = STATE(219),
    [sym_string_literal] = STATE(219),
    [sym_unary_expression] = STATE(218),
    [sym_binary_expression] = STATE(218),
    [sym_struct_expression] = STATE(218),
    [sym_nonempty_block_expression] = STATE(218),
    [sym_anonymous_lambda_expression] = STATE(218),
    [sym_constructor_expression] = STATE(218),
    [sym_apply_expression] = STATE(218),
    [sym_array_access_expression] = STATE(158),
    [sym_dot_apply_expression] = STATE(218),
    [sym_access_expression] = STATE(218),
    [sym_method_expression] = STATE(218),
    [sym_unit_expression] = STATE(218),
    [sym_tuple_expression] = STATE(218),
    [sym_constraint_expression] = STATE(218),
    [sym_array_expression] = STATE(218),
    [sym_match_expression] = STATE(204),
    [sym_if_expression] = STATE(204),
    [sym_statement_expression] = STATE(568),
    [sym_let_expression] = STATE(566),
    [sym_shorthand_let_expression] = STATE(566),
    [sym_shorthand_let_pattern] = STATE(613),
    [sym_var_expression] = STATE(566),
    [sym_assign_expression] = STATE(566),
    [sym_left_value] = STATE(653),
    [sym_named_lambda_expression] = STATE(566),
    [sym_while_expression] = STATE(566),
    [sym_return_expression] = STATE(566),
    [sym_qualified_identifier] = STATE(158),
    [sym_qualified_type_identifier] = STATE(651),
    [aux_sym_block_expression_repeat1] = STATE(9),
    [sym_lowercase_identifier] = ACTIONS(73),
    [anon_sym_LPAREN] = ACTIONS(25),
    [anon_sym_LBRACE] = ACTIONS(27),
    [anon_sym_RBRACE] = ACTIONS(150),
    [anon_sym_let] = ACTIONS(31),
    [anon_sym__] = ACTIONS(33),
    [anon_sym_DQUOTE] = ACTIONS(35),
    [anon_sym_true] = ACTIONS(37),
    [anon_sym_false] = ACTIONS(37),
    [sym_integer_literal] = ACTIONS(39),
    [anon_sym_SQUOTE] = ACTIONS(41),
    [anon_sym_DASH] = ACTIONS(43),
    [anon_sym_PLUS] = ACTIONS(43),
    [anon_sym_fn] = ACTIONS(47),
    [anon_sym_LBRACK] = ACTIONS(49),
    [anon_sym_match] = ACTIONS(51),
    [anon_sym_if] = ACTIONS(53),
    [anon_sym_break] = ACTIONS(55),
    [anon_sym_continue] = ACTIONS(55),
    [anon_sym_var] = ACTIONS(57),
    [anon_sym_while] = ACTIONS(59),
    [anon_sym_return] = ACTIONS(61),
    [sym_uppercase_identifier] = ACTIONS(63),
    [sym_identifier] = ACTIONS(65),
    [sym_package_identifier] = ACTIONS(67),
    [sym_comment] = ACTIONS(3),
    [sym_float_literal] = ACTIONS(39),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 27,
    ACTIONS(39), 1,
      sym_float_literal,
    ACTIONS(51), 1,
      anon_sym_match,
    ACTIONS(53), 1,
      anon_sym_if,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(152), 1,
      sym_lowercase_identifier,
    ACTIONS(154), 1,
      anon_sym_LF,
    ACTIONS(158), 1,
      anon_sym_LPAREN,
    ACTIONS(160), 1,
      anon_sym_LBRACE,
    ACTIONS(162), 1,
      anon_sym__,
    ACTIONS(164), 1,
      anon_sym_DQUOTE,
    ACTIONS(166), 1,
      sym_integer_literal,
    ACTIONS(168), 1,
      anon_sym_SQUOTE,
    ACTIONS(172), 1,
      anon_sym_fn,
    ACTIONS(174), 1,
      anon_sym_LBRACK,
    ACTIONS(176), 1,
      sym_uppercase_identifier,
    ACTIONS(178), 1,
      sym_package_identifier,
    ACTIONS(180), 1,
      sym_comment,
    STATE(161), 1,
      sym_simple_expression,
    STATE(240), 1,
      sym_expression,
    STATE(651), 1,
      sym_qualified_type_identifier,
    ACTIONS(37), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(156), 2,
      anon_sym_SEMI,
      anon_sym_,
    ACTIONS(170), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(164), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(204), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(219), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(218), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [105] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(204), 1,
      anon_sym_RBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    STATE(99), 1,
      sym_simple_expression,
    STATE(241), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [204] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(214), 1,
      anon_sym_RPAREN,
    STATE(99), 1,
      sym_simple_expression,
    STATE(229), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [303] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(216), 1,
      anon_sym_RPAREN,
    STATE(99), 1,
      sym_simple_expression,
    STATE(229), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [402] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(218), 1,
      anon_sym_RPAREN,
    STATE(99), 1,
      sym_simple_expression,
    STATE(229), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [501] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(220), 1,
      anon_sym_RPAREN,
    STATE(99), 1,
      sym_simple_expression,
    STATE(225), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [600] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(222), 1,
      anon_sym_RBRACK,
    STATE(99), 1,
      sym_simple_expression,
    STATE(231), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [699] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(224), 1,
      anon_sym_RPAREN,
    STATE(99), 1,
      sym_simple_expression,
    STATE(224), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [798] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(226), 1,
      anon_sym_RPAREN,
    STATE(99), 1,
      sym_simple_expression,
    STATE(229), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [897] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(228), 1,
      anon_sym_RPAREN,
    STATE(99), 1,
      sym_simple_expression,
    STATE(229), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [996] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(230), 1,
      anon_sym_RPAREN,
    STATE(99), 1,
      sym_simple_expression,
    STATE(229), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [1095] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(232), 1,
      anon_sym_RPAREN,
    STATE(99), 1,
      sym_simple_expression,
    STATE(239), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [1194] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(234), 1,
      anon_sym_RPAREN,
    STATE(99), 1,
      sym_simple_expression,
    STATE(229), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [1293] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(236), 1,
      anon_sym_RBRACK,
    STATE(99), 1,
      sym_simple_expression,
    STATE(229), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [1392] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(238), 1,
      anon_sym_RBRACK,
    STATE(99), 1,
      sym_simple_expression,
    STATE(229), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [1491] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(240), 1,
      anon_sym_RPAREN,
    STATE(99), 1,
      sym_simple_expression,
    STATE(229), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [1590] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(242), 1,
      anon_sym_RPAREN,
    STATE(99), 1,
      sym_simple_expression,
    STATE(229), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [1689] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(244), 1,
      anon_sym_RBRACK,
    STATE(99), 1,
      sym_simple_expression,
    STATE(229), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [1788] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(246), 1,
      anon_sym_RPAREN,
    STATE(99), 1,
      sym_simple_expression,
    STATE(236), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [1887] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(248), 1,
      anon_sym_RPAREN,
    STATE(99), 1,
      sym_simple_expression,
    STATE(229), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [1986] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(250), 1,
      anon_sym_RBRACK,
    STATE(99), 1,
      sym_simple_expression,
    STATE(229), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [2085] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(252), 1,
      anon_sym_RPAREN,
    STATE(99), 1,
      sym_simple_expression,
    STATE(229), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [2184] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(254), 1,
      anon_sym_RPAREN,
    STATE(99), 1,
      sym_simple_expression,
    STATE(235), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [2283] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(256), 1,
      anon_sym_RPAREN,
    STATE(99), 1,
      sym_simple_expression,
    STATE(230), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [2382] = 25,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    ACTIONS(258), 1,
      anon_sym_RPAREN,
    STATE(99), 1,
      sym_simple_expression,
    STATE(229), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [2481] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    STATE(99), 1,
      sym_simple_expression,
    STATE(248), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [2577] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    STATE(99), 1,
      sym_simple_expression,
    STATE(246), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [2673] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_LBRACE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      anon_sym_SQUOTE,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
    ACTIONS(51), 1,
      anon_sym_match,
    ACTIONS(53), 1,
      anon_sym_if,
    ACTIONS(63), 1,
      sym_uppercase_identifier,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(67), 1,
      sym_package_identifier,
    ACTIONS(152), 1,
      sym_lowercase_identifier,
    ACTIONS(162), 1,
      anon_sym__,
    ACTIONS(172), 1,
      anon_sym_fn,
    STATE(161), 1,
      sym_simple_expression,
    STATE(227), 1,
      sym_expression,
    STATE(651), 1,
      sym_qualified_type_identifier,
    ACTIONS(37), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(43), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(164), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(204), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(219), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(218), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [2769] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_LBRACE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      anon_sym_SQUOTE,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
    ACTIONS(51), 1,
      anon_sym_match,
    ACTIONS(53), 1,
      anon_sym_if,
    ACTIONS(63), 1,
      sym_uppercase_identifier,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(67), 1,
      sym_package_identifier,
    ACTIONS(152), 1,
      sym_lowercase_identifier,
    ACTIONS(162), 1,
      anon_sym__,
    ACTIONS(172), 1,
      anon_sym_fn,
    STATE(161), 1,
      sym_simple_expression,
    STATE(228), 1,
      sym_expression,
    STATE(651), 1,
      sym_qualified_type_identifier,
    ACTIONS(37), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(43), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(164), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(204), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(219), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(218), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [2865] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    STATE(99), 1,
      sym_simple_expression,
    STATE(250), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [2961] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    STATE(99), 1,
      sym_simple_expression,
    STATE(245), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [3057] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    STATE(223), 1,
      sym_simple_expression,
    STATE(251), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [3153] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_LBRACE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      anon_sym_SQUOTE,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
    ACTIONS(51), 1,
      anon_sym_match,
    ACTIONS(53), 1,
      anon_sym_if,
    ACTIONS(63), 1,
      sym_uppercase_identifier,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(67), 1,
      sym_package_identifier,
    ACTIONS(152), 1,
      sym_lowercase_identifier,
    ACTIONS(162), 1,
      anon_sym__,
    ACTIONS(172), 1,
      anon_sym_fn,
    STATE(161), 1,
      sym_simple_expression,
    STATE(233), 1,
      sym_expression,
    STATE(651), 1,
      sym_qualified_type_identifier,
    ACTIONS(37), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(43), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(164), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(204), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(219), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(218), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [3249] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_LBRACE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      anon_sym_SQUOTE,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
    ACTIONS(51), 1,
      anon_sym_match,
    ACTIONS(53), 1,
      anon_sym_if,
    ACTIONS(63), 1,
      sym_uppercase_identifier,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(67), 1,
      sym_package_identifier,
    ACTIONS(152), 1,
      sym_lowercase_identifier,
    ACTIONS(162), 1,
      anon_sym__,
    ACTIONS(172), 1,
      anon_sym_fn,
    STATE(161), 1,
      sym_simple_expression,
    STATE(180), 1,
      sym_expression,
    STATE(651), 1,
      sym_qualified_type_identifier,
    ACTIONS(37), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(43), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(164), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(204), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(219), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(218), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [3345] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    STATE(99), 1,
      sym_simple_expression,
    STATE(140), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [3441] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    STATE(99), 1,
      sym_simple_expression,
    STATE(141), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [3537] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_LBRACE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      anon_sym_SQUOTE,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
    ACTIONS(51), 1,
      anon_sym_match,
    ACTIONS(53), 1,
      anon_sym_if,
    ACTIONS(63), 1,
      sym_uppercase_identifier,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(67), 1,
      sym_package_identifier,
    ACTIONS(152), 1,
      sym_lowercase_identifier,
    ACTIONS(162), 1,
      anon_sym__,
    ACTIONS(172), 1,
      anon_sym_fn,
    STATE(161), 1,
      sym_simple_expression,
    STATE(172), 1,
      sym_expression,
    STATE(651), 1,
      sym_qualified_type_identifier,
    ACTIONS(37), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(43), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(164), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(204), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(219), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(218), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [3633] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_LBRACE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      anon_sym_SQUOTE,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
    ACTIONS(51), 1,
      anon_sym_match,
    ACTIONS(53), 1,
      anon_sym_if,
    ACTIONS(63), 1,
      sym_uppercase_identifier,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(67), 1,
      sym_package_identifier,
    ACTIONS(152), 1,
      sym_lowercase_identifier,
    ACTIONS(162), 1,
      anon_sym__,
    ACTIONS(172), 1,
      anon_sym_fn,
    STATE(161), 1,
      sym_simple_expression,
    STATE(242), 1,
      sym_expression,
    STATE(651), 1,
      sym_qualified_type_identifier,
    ACTIONS(37), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(43), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(164), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(204), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(219), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(218), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [3729] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_LBRACE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      anon_sym_SQUOTE,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
    ACTIONS(51), 1,
      anon_sym_match,
    ACTIONS(53), 1,
      anon_sym_if,
    ACTIONS(63), 1,
      sym_uppercase_identifier,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(67), 1,
      sym_package_identifier,
    ACTIONS(152), 1,
      sym_lowercase_identifier,
    ACTIONS(162), 1,
      anon_sym__,
    ACTIONS(172), 1,
      anon_sym_fn,
    STATE(161), 1,
      sym_simple_expression,
    STATE(176), 1,
      sym_expression,
    STATE(651), 1,
      sym_qualified_type_identifier,
    ACTIONS(37), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(43), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(164), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(204), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(219), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(218), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [3825] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    STATE(99), 1,
      sym_simple_expression,
    STATE(229), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [3921] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_LBRACE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      anon_sym_SQUOTE,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
    ACTIONS(51), 1,
      anon_sym_match,
    ACTIONS(53), 1,
      anon_sym_if,
    ACTIONS(63), 1,
      sym_uppercase_identifier,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(67), 1,
      sym_package_identifier,
    ACTIONS(152), 1,
      sym_lowercase_identifier,
    ACTIONS(162), 1,
      anon_sym__,
    ACTIONS(172), 1,
      anon_sym_fn,
    STATE(161), 1,
      sym_simple_expression,
    STATE(238), 1,
      sym_expression,
    STATE(651), 1,
      sym_qualified_type_identifier,
    ACTIONS(37), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(43), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(164), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(204), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(219), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(218), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [4017] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_LBRACE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      anon_sym_SQUOTE,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
    ACTIONS(51), 1,
      anon_sym_match,
    ACTIONS(53), 1,
      anon_sym_if,
    ACTIONS(63), 1,
      sym_uppercase_identifier,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(67), 1,
      sym_package_identifier,
    ACTIONS(152), 1,
      sym_lowercase_identifier,
    ACTIONS(162), 1,
      anon_sym__,
    ACTIONS(172), 1,
      anon_sym_fn,
    STATE(161), 1,
      sym_simple_expression,
    STATE(175), 1,
      sym_expression,
    STATE(651), 1,
      sym_qualified_type_identifier,
    ACTIONS(37), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(43), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(164), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(204), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(219), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(218), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [4113] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    STATE(99), 1,
      sym_simple_expression,
    STATE(247), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [4209] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    STATE(222), 1,
      sym_simple_expression,
    STATE(251), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [4305] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    STATE(201), 1,
      sym_simple_expression,
    STATE(251), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [4401] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    STATE(181), 1,
      sym_simple_expression,
    STATE(251), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [4497] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_LBRACE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      anon_sym_SQUOTE,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
    ACTIONS(51), 1,
      anon_sym_match,
    ACTIONS(53), 1,
      anon_sym_if,
    ACTIONS(63), 1,
      sym_uppercase_identifier,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(67), 1,
      sym_package_identifier,
    ACTIONS(152), 1,
      sym_lowercase_identifier,
    ACTIONS(162), 1,
      anon_sym__,
    ACTIONS(172), 1,
      anon_sym_fn,
    STATE(161), 1,
      sym_simple_expression,
    STATE(179), 1,
      sym_expression,
    STATE(651), 1,
      sym_qualified_type_identifier,
    ACTIONS(37), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(43), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(164), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(204), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(219), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(218), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [4593] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_LBRACE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      anon_sym_SQUOTE,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
    ACTIONS(51), 1,
      anon_sym_match,
    ACTIONS(53), 1,
      anon_sym_if,
    ACTIONS(63), 1,
      sym_uppercase_identifier,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(67), 1,
      sym_package_identifier,
    ACTIONS(152), 1,
      sym_lowercase_identifier,
    ACTIONS(162), 1,
      anon_sym__,
    ACTIONS(172), 1,
      anon_sym_fn,
    STATE(161), 1,
      sym_simple_expression,
    STATE(226), 1,
      sym_expression,
    STATE(651), 1,
      sym_qualified_type_identifier,
    ACTIONS(37), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(43), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(164), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(204), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(219), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(218), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [4689] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    STATE(99), 1,
      sym_simple_expression,
    STATE(118), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [4785] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    STATE(99), 1,
      sym_simple_expression,
    STATE(139), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [4881] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    STATE(99), 1,
      sym_simple_expression,
    STATE(135), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [4977] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_LBRACE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      anon_sym_SQUOTE,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
    ACTIONS(51), 1,
      anon_sym_match,
    ACTIONS(53), 1,
      anon_sym_if,
    ACTIONS(63), 1,
      sym_uppercase_identifier,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(67), 1,
      sym_package_identifier,
    ACTIONS(152), 1,
      sym_lowercase_identifier,
    ACTIONS(162), 1,
      anon_sym__,
    ACTIONS(172), 1,
      anon_sym_fn,
    STATE(161), 1,
      sym_simple_expression,
    STATE(182), 1,
      sym_expression,
    STATE(651), 1,
      sym_qualified_type_identifier,
    ACTIONS(37), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(43), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(164), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(204), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(219), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(218), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [5073] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_LBRACE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      anon_sym_SQUOTE,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
    ACTIONS(51), 1,
      anon_sym_match,
    ACTIONS(53), 1,
      anon_sym_if,
    ACTIONS(63), 1,
      sym_uppercase_identifier,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(67), 1,
      sym_package_identifier,
    ACTIONS(152), 1,
      sym_lowercase_identifier,
    ACTIONS(162), 1,
      anon_sym__,
    ACTIONS(172), 1,
      anon_sym_fn,
    STATE(161), 1,
      sym_simple_expression,
    STATE(178), 1,
      sym_expression,
    STATE(651), 1,
      sym_qualified_type_identifier,
    ACTIONS(37), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(43), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(164), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(204), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(219), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(218), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [5169] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    STATE(210), 1,
      sym_simple_expression,
    STATE(251), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [5265] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    STATE(99), 1,
      sym_simple_expression,
    STATE(136), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [5361] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_LBRACE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      anon_sym_SQUOTE,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
    ACTIONS(51), 1,
      anon_sym_match,
    ACTIONS(53), 1,
      anon_sym_if,
    ACTIONS(63), 1,
      sym_uppercase_identifier,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(67), 1,
      sym_package_identifier,
    ACTIONS(152), 1,
      sym_lowercase_identifier,
    ACTIONS(162), 1,
      anon_sym__,
    ACTIONS(172), 1,
      anon_sym_fn,
    STATE(161), 1,
      sym_simple_expression,
    STATE(234), 1,
      sym_expression,
    STATE(651), 1,
      sym_qualified_type_identifier,
    ACTIONS(37), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(43), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(164), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(204), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(219), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(218), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [5457] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_LBRACE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      anon_sym_SQUOTE,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
    ACTIONS(51), 1,
      anon_sym_match,
    ACTIONS(53), 1,
      anon_sym_if,
    ACTIONS(63), 1,
      sym_uppercase_identifier,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(67), 1,
      sym_package_identifier,
    ACTIONS(152), 1,
      sym_lowercase_identifier,
    ACTIONS(162), 1,
      anon_sym__,
    ACTIONS(172), 1,
      anon_sym_fn,
    STATE(161), 1,
      sym_simple_expression,
    STATE(237), 1,
      sym_expression,
    STATE(651), 1,
      sym_qualified_type_identifier,
    ACTIONS(37), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(43), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(164), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(204), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(219), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(218), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [5553] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_LBRACE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      anon_sym_SQUOTE,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
    ACTIONS(51), 1,
      anon_sym_match,
    ACTIONS(53), 1,
      anon_sym_if,
    ACTIONS(63), 1,
      sym_uppercase_identifier,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(67), 1,
      sym_package_identifier,
    ACTIONS(152), 1,
      sym_lowercase_identifier,
    ACTIONS(162), 1,
      anon_sym__,
    ACTIONS(172), 1,
      anon_sym_fn,
    STATE(161), 1,
      sym_simple_expression,
    STATE(232), 1,
      sym_expression,
    STATE(651), 1,
      sym_qualified_type_identifier,
    ACTIONS(37), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(43), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(164), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(204), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(219), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(218), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [5649] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    STATE(99), 1,
      sym_simple_expression,
    STATE(249), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [5745] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(182), 1,
      sym_lowercase_identifier,
    ACTIONS(184), 1,
      anon_sym_LPAREN,
    ACTIONS(186), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 1,
      anon_sym__,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(200), 1,
      anon_sym_fn,
    ACTIONS(202), 1,
      anon_sym_LBRACK,
    ACTIONS(206), 1,
      anon_sym_match,
    ACTIONS(208), 1,
      anon_sym_if,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(212), 1,
      sym_package_identifier,
    STATE(99), 1,
      sym_simple_expression,
    STATE(137), 1,
      sym_expression,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(198), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(114), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(115), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(132), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [5841] = 24,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_LBRACE,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      anon_sym_SQUOTE,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
    ACTIONS(51), 1,
      anon_sym_match,
    ACTIONS(53), 1,
      anon_sym_if,
    ACTIONS(63), 1,
      sym_uppercase_identifier,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(67), 1,
      sym_package_identifier,
    ACTIONS(152), 1,
      sym_lowercase_identifier,
    ACTIONS(162), 1,
      anon_sym__,
    ACTIONS(172), 1,
      anon_sym_fn,
    STATE(161), 1,
      sym_simple_expression,
    STATE(243), 1,
      sym_expression,
    STATE(651), 1,
      sym_qualified_type_identifier,
    ACTIONS(37), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(39), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(43), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(164), 2,
      sym_string_interpolation,
      sym_literal,
    STATE(204), 2,
      sym_match_expression,
      sym_if_expression,
    STATE(219), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(218), 17,
      sym_atomic_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_struct_expression,
      sym_nonempty_block_expression,
      sym_anonymous_lambda_expression,
      sym_constructor_expression,
      sym_apply_expression,
      sym_array_access_expression,
      sym_dot_apply_expression,
      sym_access_expression,
      sym_method_expression,
      sym_unit_expression,
      sym_tuple_expression,
      sym_constraint_expression,
      sym_array_expression,
      sym_qualified_identifier,
  [5937] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(262), 9,
      anon_sym_COLON,
      anon_sym_EQ,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_PIPE,
    ACTIONS(260), 26,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_DQUOTE,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DOT_DOT,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      anon_sym_EQ_GT,
      anon_sym_as,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [5980] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(266), 9,
      anon_sym_COLON,
      anon_sym_EQ,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_PIPE,
    ACTIONS(264), 26,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_DQUOTE,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DOT_DOT,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      anon_sym_EQ_GT,
      anon_sym_as,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [6023] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(270), 9,
      anon_sym_COLON,
      anon_sym_EQ,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_PIPE,
    ACTIONS(268), 25,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DOT_DOT,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      anon_sym_EQ_GT,
      anon_sym_as,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [6065] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(274), 9,
      anon_sym_COLON,
      anon_sym_EQ,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_PIPE,
    ACTIONS(272), 25,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DOT_DOT,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      anon_sym_EQ_GT,
      anon_sym_as,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [6107] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(278), 9,
      anon_sym_COLON,
      anon_sym_EQ,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_PIPE,
    ACTIONS(276), 25,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DOT_DOT,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      anon_sym_EQ_GT,
      anon_sym_as,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [6149] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(282), 9,
      anon_sym_COLON,
      anon_sym_EQ,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_PIPE,
    ACTIONS(280), 25,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DOT_DOT,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      anon_sym_EQ_GT,
      anon_sym_as,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [6191] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(286), 9,
      anon_sym_COLON,
      anon_sym_EQ,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_PIPE,
    ACTIONS(284), 25,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DOT_DOT,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      anon_sym_EQ_GT,
      anon_sym_as,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [6233] = 22,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(296), 1,
      anon_sym_DOT_DOT,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(300), 1,
      anon_sym_RBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    STATE(95), 1,
      sym_dotdot_pattern,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(343), 1,
      sym_pattern,
    STATE(605), 1,
      sym_qualified_type_identifier,
    STATE(620), 1,
      sym_array_sub_pattern,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [6312] = 21,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(304), 1,
      anon_sym_RBRACE,
    STATE(83), 1,
      aux_sym_match_expression_repeat1,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(446), 1,
      sym_pattern,
    STATE(447), 1,
      sym_case_clause,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [6388] = 21,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(306), 1,
      anon_sym_DOT_DOT,
    ACTIONS(308), 1,
      anon_sym_RBRACK,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(351), 1,
      sym_pattern,
    STATE(605), 1,
      sym_qualified_type_identifier,
    STATE(649), 1,
      sym_dotdot_pattern,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [6464] = 21,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(310), 1,
      anon_sym_RBRACE,
    STATE(83), 1,
      aux_sym_match_expression_repeat1,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(446), 1,
      sym_pattern,
    STATE(447), 1,
      sym_case_clause,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [6540] = 21,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(315), 1,
      anon_sym_LPAREN,
    ACTIONS(318), 1,
      anon_sym_LBRACE,
    ACTIONS(321), 1,
      anon_sym_RBRACE,
    ACTIONS(323), 1,
      anon_sym_DQUOTE,
    ACTIONS(332), 1,
      anon_sym_SQUOTE,
    ACTIONS(335), 1,
      anon_sym_LBRACK,
    ACTIONS(338), 1,
      sym_uppercase_identifier,
    ACTIONS(341), 1,
      sym_identifier,
    ACTIONS(344), 1,
      sym_package_identifier,
    STATE(83), 1,
      aux_sym_match_expression_repeat1,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(446), 1,
      sym_pattern,
    STATE(447), 1,
      sym_case_clause,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(312), 2,
      anon_sym__,
      sym_lowercase_identifier,
    ACTIONS(326), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(329), 2,
      sym_float_literal,
      sym_integer_literal,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [6616] = 21,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(306), 1,
      anon_sym_DOT_DOT,
    ACTIONS(347), 1,
      anon_sym_RBRACK,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(351), 1,
      sym_pattern,
    STATE(605), 1,
      sym_qualified_type_identifier,
    STATE(627), 1,
      sym_dotdot_pattern,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [6692] = 21,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(349), 1,
      anon_sym_RBRACE,
    STATE(80), 1,
      aux_sym_match_expression_repeat1,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(446), 1,
      sym_pattern,
    STATE(447), 1,
      sym_case_clause,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [6768] = 21,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(351), 1,
      anon_sym_RBRACE,
    STATE(82), 1,
      aux_sym_match_expression_repeat1,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(446), 1,
      sym_pattern,
    STATE(447), 1,
      sym_case_clause,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [6844] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(357), 1,
      anon_sym_else,
    STATE(124), 1,
      sym_else_clause,
    ACTIONS(355), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(353), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [6887] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(363), 1,
      sym_colon_colon_uppercase_identifier,
    ACTIONS(361), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(359), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [6927] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(367), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(365), 23,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      anon_sym_else,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [6965] = 19,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(347), 1,
      anon_sym_RBRACK,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(351), 1,
      sym_pattern,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [7035] = 19,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(369), 1,
      anon_sym_RPAREN,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(351), 1,
      sym_pattern,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [7105] = 19,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(371), 1,
      anon_sym_RPAREN,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(351), 1,
      sym_pattern,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [7175] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(375), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(373), 23,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      anon_sym_else,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [7213] = 6,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(377), 1,
      anon_sym_LF,
    ACTIONS(381), 1,
      anon_sym_COLON,
    ACTIONS(383), 1,
      anon_sym_COMMA,
    ACTIONS(385), 1,
      anon_sym_COLON_EQ,
    ACTIONS(379), 26,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_EQ,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [7257] = 19,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(387), 1,
      anon_sym_RBRACK,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(383), 1,
      sym_pattern,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [7327] = 19,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(389), 1,
      anon_sym_RBRACK,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(351), 1,
      sym_pattern,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [7397] = 19,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(391), 1,
      anon_sym_RPAREN,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(351), 1,
      sym_pattern,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [7467] = 19,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(393), 1,
      anon_sym_RPAREN,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(351), 1,
      sym_pattern,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [7537] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(395), 1,
      anon_sym_LPAREN,
    ACTIONS(401), 1,
      anon_sym_LBRACK,
    ACTIONS(403), 1,
      aux_sym_accessor_token1,
    ACTIONS(405), 1,
      sym_dot_identifier,
    STATE(117), 1,
      sym_accessor,
    ACTIONS(399), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(397), 18,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_RBRACK,
      sym_colon_colon_lowercase_identifier,
  [7585] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(409), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(407), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [7622] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(413), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(411), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [7659] = 18,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(397), 1,
      sym_pattern,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [7726] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(417), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(415), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [7763] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(421), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(419), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [7800] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(425), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(423), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [7837] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(429), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(427), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [7874] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(433), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(431), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [7911] = 18,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(382), 1,
      sym_pattern,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [7978] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(437), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(435), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8015] = 18,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(368), 1,
      sym_pattern,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [8082] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(441), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(439), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8119] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(445), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(443), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8156] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(449), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(447), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8193] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(399), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(397), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8230] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(453), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(451), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8267] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(455), 1,
      anon_sym_LPAREN,
    ACTIONS(459), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(457), 21,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8306] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(463), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(461), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8343] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(467), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(465), 21,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8382] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(473), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(471), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8419] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(477), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(475), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8456] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(481), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(479), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8493] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(379), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(377), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8530] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(485), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(483), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8567] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(489), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(487), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8604] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(493), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(491), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8641] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(497), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(495), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8678] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(501), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(499), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8715] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(505), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(503), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8752] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(459), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(457), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8789] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(509), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(507), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8826] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(513), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(511), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8863] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(517), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(515), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [8900] = 18,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(370), 1,
      sym_pattern,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [8967] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(521), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(519), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [9004] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(525), 1,
      anon_sym_COLON,
    ACTIONS(539), 1,
      anon_sym_AMP_AMP,
    ACTIONS(527), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(529), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(533), 2,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(535), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(531), 3,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(537), 4,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(523), 11,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [9057] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(525), 1,
      anon_sym_COLON,
    ACTIONS(527), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(529), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(533), 2,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(535), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(531), 3,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(537), 4,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(523), 12,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [9108] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(527), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(529), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(533), 2,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(525), 3,
      anon_sym_COLON,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(531), 3,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(523), 16,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [9155] = 18,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(289), 1,
      sym_pattern,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [9222] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(525), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(523), 21,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [9261] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(525), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(523), 21,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [9300] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(529), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(531), 3,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(525), 5,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(523), 18,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [9343] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(543), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(541), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [9380] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(547), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(545), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [9417] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(551), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(549), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [9454] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(555), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(553), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [9491] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(559), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(557), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [9528] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(563), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(561), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [9565] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(567), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(565), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [9602] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(571), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(569), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [9639] = 18,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(384), 1,
      sym_pattern,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [9706] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(575), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(573), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [9743] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(579), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(577), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [9780] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(583), 7,
      anon_sym_COLON,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(581), 22,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [9817] = 18,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(196), 1,
      anon_sym_SQUOTE,
    ACTIONS(210), 1,
      sym_uppercase_identifier,
    ACTIONS(290), 1,
      anon_sym_LPAREN,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      sym_package_identifier,
    STATE(263), 1,
      sym_constructor_expression,
    STATE(351), 1,
      sym_pattern,
    STATE(605), 1,
      sym_qualified_type_identifier,
    ACTIONS(192), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(194), 2,
      sym_float_literal,
      sym_integer_literal,
    ACTIONS(288), 2,
      anon_sym__,
      sym_lowercase_identifier,
    STATE(76), 3,
      sym_boolean_literal,
      sym_char_literal,
      sym_string_literal,
    STATE(302), 3,
      sym_as_pattern,
      sym_or_pattern,
      sym_simple_pattern,
    STATE(276), 6,
      sym_literal,
      sym_constructor_pattern,
      sym_tuple_pattern,
      sym_constraint_pattern,
      sym_array_pattern,
      sym_struct_pattern,
  [9884] = 5,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(353), 1,
      anon_sym_LF,
    ACTIONS(585), 1,
      anon_sym_else,
    STATE(216), 1,
      sym_else_clause,
    ACTIONS(355), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [9924] = 4,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(377), 1,
      anon_sym_LF,
    ACTIONS(385), 1,
      anon_sym_COLON_EQ,
    ACTIONS(379), 26,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_EQ,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [9962] = 4,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(359), 1,
      anon_sym_LF,
    ACTIONS(587), 1,
      sym_colon_colon_uppercase_identifier,
    ACTIONS(361), 26,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_EQ,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10000] = 4,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(515), 1,
      anon_sym_LF,
    ACTIONS(589), 1,
      anon_sym_EQ,
    ACTIONS(517), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10037] = 4,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(385), 1,
      anon_sym_COLON_EQ,
    ACTIONS(515), 1,
      anon_sym_LF,
    ACTIONS(517), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10074] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(365), 1,
      anon_sym_LF,
    ACTIONS(367), 26,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      anon_sym_else,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10109] = 8,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(397), 1,
      anon_sym_LF,
    ACTIONS(591), 1,
      anon_sym_LPAREN,
    ACTIONS(593), 1,
      anon_sym_LBRACK,
    ACTIONS(595), 1,
      aux_sym_accessor_token1,
    ACTIONS(597), 1,
      sym_dot_identifier,
    STATE(194), 1,
      sym_accessor,
    ACTIONS(399), 21,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      sym_colon_colon_lowercase_identifier,
  [10154] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(475), 1,
      anon_sym_LF,
    ACTIONS(477), 26,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_EQ,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10189] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(373), 1,
      anon_sym_LF,
    ACTIONS(375), 26,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      anon_sym_else,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10224] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(451), 1,
      anon_sym_LF,
    ACTIONS(453), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10258] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(519), 1,
      anon_sym_LF,
    ACTIONS(521), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10292] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(581), 1,
      anon_sym_LF,
    ACTIONS(583), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10326] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(573), 1,
      anon_sym_LF,
    ACTIONS(575), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10360] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(411), 1,
      anon_sym_LF,
    ACTIONS(413), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10394] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(260), 1,
      anon_sym_LF,
    ACTIONS(262), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10428] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(541), 1,
      anon_sym_LF,
    ACTIONS(543), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10462] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(447), 1,
      anon_sym_LF,
    ACTIONS(449), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10496] = 8,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(523), 1,
      anon_sym_LF,
    ACTIONS(601), 1,
      anon_sym_STAR_STAR,
    ACTIONS(607), 1,
      anon_sym_AMP_AMP,
    ACTIONS(599), 4,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(603), 5,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(605), 6,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(525), 8,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10540] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(435), 1,
      anon_sym_LF,
    ACTIONS(437), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10574] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(431), 1,
      anon_sym_LF,
    ACTIONS(433), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10608] = 4,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(465), 1,
      anon_sym_LF,
    ACTIONS(601), 1,
      anon_sym_STAR_STAR,
    ACTIONS(467), 24,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10644] = 7,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(523), 1,
      anon_sym_LF,
    ACTIONS(601), 1,
      anon_sym_STAR_STAR,
    ACTIONS(599), 4,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(603), 5,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(605), 6,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(525), 9,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10686] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(443), 1,
      anon_sym_LF,
    ACTIONS(445), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10720] = 6,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(523), 1,
      anon_sym_LF,
    ACTIONS(601), 1,
      anon_sym_STAR_STAR,
    ACTIONS(599), 4,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(603), 5,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(525), 15,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10760] = 4,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(523), 1,
      anon_sym_LF,
    ACTIONS(601), 1,
      anon_sym_STAR_STAR,
    ACTIONS(525), 24,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10796] = 4,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(523), 1,
      anon_sym_LF,
    ACTIONS(601), 1,
      anon_sym_STAR_STAR,
    ACTIONS(525), 24,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10832] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(395), 1,
      anon_sym_LPAREN,
    ACTIONS(401), 1,
      anon_sym_LBRACK,
    ACTIONS(403), 1,
      aux_sym_accessor_token1,
    ACTIONS(405), 1,
      sym_dot_identifier,
    ACTIONS(609), 1,
      anon_sym_LBRACE,
    STATE(117), 1,
      sym_accessor,
    STATE(155), 1,
      sym_block_expression,
    ACTIONS(399), 6,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(397), 13,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      sym_colon_colon_lowercase_identifier,
  [10880] = 5,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(523), 1,
      anon_sym_LF,
    ACTIONS(601), 1,
      anon_sym_STAR_STAR,
    ACTIONS(603), 5,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(525), 19,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10918] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(419), 1,
      anon_sym_LF,
    ACTIONS(421), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10952] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(511), 1,
      anon_sym_LF,
    ACTIONS(513), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [10986] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(557), 1,
      anon_sym_LF,
    ACTIONS(559), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11020] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(545), 1,
      anon_sym_LF,
    ACTIONS(547), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11054] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(549), 1,
      anon_sym_LF,
    ACTIONS(551), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11088] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(280), 1,
      anon_sym_LF,
    ACTIONS(282), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11122] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(483), 1,
      anon_sym_LF,
    ACTIONS(485), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11156] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(427), 1,
      anon_sym_LF,
    ACTIONS(429), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11190] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(507), 1,
      anon_sym_LF,
    ACTIONS(509), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11224] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(457), 1,
      anon_sym_LF,
    ACTIONS(459), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11258] = 4,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(457), 1,
      anon_sym_LF,
    ACTIONS(611), 1,
      anon_sym_LPAREN,
    ACTIONS(459), 24,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11294] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(461), 1,
      anon_sym_LF,
    ACTIONS(463), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11328] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(284), 1,
      anon_sym_LF,
    ACTIONS(286), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11362] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(264), 1,
      anon_sym_LF,
    ACTIONS(266), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11396] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(561), 1,
      anon_sym_LF,
    ACTIONS(563), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11430] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(565), 1,
      anon_sym_LF,
    ACTIONS(567), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11464] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(491), 1,
      anon_sym_LF,
    ACTIONS(493), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11498] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(569), 1,
      anon_sym_LF,
    ACTIONS(571), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11532] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(395), 1,
      anon_sym_LPAREN,
    ACTIONS(401), 1,
      anon_sym_LBRACK,
    ACTIONS(403), 1,
      aux_sym_accessor_token1,
    ACTIONS(405), 1,
      sym_dot_identifier,
    ACTIONS(613), 1,
      anon_sym_LBRACE,
    STATE(87), 1,
      sym_block_expression,
    STATE(117), 1,
      sym_accessor,
    ACTIONS(399), 6,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(397), 13,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      sym_colon_colon_lowercase_identifier,
  [11580] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(503), 1,
      anon_sym_LF,
    ACTIONS(505), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11614] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(499), 1,
      anon_sym_LF,
    ACTIONS(501), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11648] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(397), 1,
      anon_sym_LF,
    ACTIONS(399), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11682] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(577), 1,
      anon_sym_LF,
    ACTIONS(579), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11716] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(423), 1,
      anon_sym_LF,
    ACTIONS(425), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11750] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(495), 1,
      anon_sym_LF,
    ACTIONS(497), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11784] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(407), 1,
      anon_sym_LF,
    ACTIONS(409), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11818] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(439), 1,
      anon_sym_LF,
    ACTIONS(441), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11852] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(395), 1,
      anon_sym_LPAREN,
    ACTIONS(401), 1,
      anon_sym_LBRACK,
    ACTIONS(403), 1,
      aux_sym_accessor_token1,
    ACTIONS(405), 1,
      sym_dot_identifier,
    ACTIONS(609), 1,
      anon_sym_LBRACE,
    STATE(117), 1,
      sym_accessor,
    STATE(442), 1,
      sym_block_expression,
    ACTIONS(399), 6,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(397), 13,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      sym_colon_colon_lowercase_identifier,
  [11900] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(553), 1,
      anon_sym_LF,
    ACTIONS(555), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [11934] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(86), 12,
      sym_float_literal,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_DQUOTE,
      sym_integer_literal,
      anon_sym_SQUOTE,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_LBRACK,
      sym_uppercase_identifier,
      sym_package_identifier,
    ACTIONS(615), 14,
      anon_sym_let,
      anon_sym__,
      anon_sym_true,
      anon_sym_false,
      anon_sym_fn,
      anon_sym_match,
      anon_sym_if,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_var,
      anon_sym_while,
      anon_sym_return,
      sym_lowercase_identifier,
      sym_identifier,
  [11968] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(377), 1,
      anon_sym_LF,
    ACTIONS(379), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [12002] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(268), 1,
      anon_sym_LF,
    ACTIONS(270), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [12036] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(272), 1,
      anon_sym_LF,
    ACTIONS(274), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [12070] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(487), 1,
      anon_sym_LF,
    ACTIONS(489), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [12104] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(479), 1,
      anon_sym_LF,
    ACTIONS(481), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [12138] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(515), 1,
      anon_sym_LF,
    ACTIONS(517), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [12172] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(276), 1,
      anon_sym_LF,
    ACTIONS(278), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [12206] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(471), 1,
      anon_sym_LF,
    ACTIONS(473), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [12240] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(415), 1,
      anon_sym_LF,
    ACTIONS(417), 25,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LPAREN,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_LBRACK,
      aux_sym_accessor_token1,
      sym_colon_colon_lowercase_identifier,
      sym_dot_identifier,
  [12274] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(395), 1,
      anon_sym_LPAREN,
    ACTIONS(401), 1,
      anon_sym_LBRACK,
    ACTIONS(403), 1,
      aux_sym_accessor_token1,
    ACTIONS(405), 1,
      sym_dot_identifier,
    ACTIONS(617), 1,
      anon_sym_LBRACE,
    STATE(117), 1,
      sym_accessor,
    ACTIONS(399), 6,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(397), 13,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      sym_colon_colon_lowercase_identifier,
  [12319] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(395), 1,
      anon_sym_LPAREN,
    ACTIONS(401), 1,
      anon_sym_LBRACK,
    ACTIONS(403), 1,
      aux_sym_accessor_token1,
    ACTIONS(405), 1,
      sym_dot_identifier,
    ACTIONS(619), 1,
      anon_sym_LBRACE,
    STATE(117), 1,
      sym_accessor,
    ACTIONS(399), 6,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(397), 13,
      anon_sym_STAR_STAR,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      sym_colon_colon_lowercase_identifier,
  [12364] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(539), 1,
      anon_sym_AMP_AMP,
    ACTIONS(621), 1,
      anon_sym_RPAREN,
    ACTIONS(623), 1,
      anon_sym_COLON,
    ACTIONS(625), 1,
      anon_sym_COMMA,
    ACTIONS(627), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(629), 1,
      sym_colon_colon_lowercase_identifier,
    STATE(486), 1,
      aux_sym_apply_expression_repeat1,
    ACTIONS(527), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(529), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(533), 2,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(535), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(531), 3,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(537), 4,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [12419] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(539), 1,
      anon_sym_AMP_AMP,
    ACTIONS(627), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(629), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(631), 1,
      anon_sym_RPAREN,
    ACTIONS(633), 1,
      anon_sym_COLON,
    ACTIONS(635), 1,
      anon_sym_COMMA,
    STATE(499), 1,
      aux_sym_apply_expression_repeat1,
    ACTIONS(527), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(529), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(533), 2,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(535), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(531), 3,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(537), 4,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [12474] = 10,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(601), 1,
      anon_sym_STAR_STAR,
    ACTIONS(607), 1,
      anon_sym_AMP_AMP,
    ACTIONS(637), 1,
      anon_sym_LF,
    ACTIONS(641), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(643), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(639), 2,
      anon_sym_SEMI,
      anon_sym_,
    ACTIONS(599), 4,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(603), 5,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(605), 6,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [12518] = 10,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(601), 1,
      anon_sym_STAR_STAR,
    ACTIONS(607), 1,
      anon_sym_AMP_AMP,
    ACTIONS(641), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(643), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(645), 1,
      anon_sym_LF,
    ACTIONS(647), 2,
      anon_sym_SEMI,
      anon_sym_,
    ACTIONS(599), 4,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(603), 5,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(605), 6,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [12562] = 10,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(601), 1,
      anon_sym_STAR_STAR,
    ACTIONS(607), 1,
      anon_sym_AMP_AMP,
    ACTIONS(641), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(643), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(649), 1,
      anon_sym_LF,
    ACTIONS(651), 2,
      anon_sym_SEMI,
      anon_sym_,
    ACTIONS(599), 4,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(603), 5,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(605), 6,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [12606] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(539), 1,
      anon_sym_AMP_AMP,
    ACTIONS(627), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(629), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(527), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(529), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(533), 2,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(535), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(531), 3,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(653), 3,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_RBRACK,
    ACTIONS(537), 4,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [12654] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(539), 1,
      anon_sym_AMP_AMP,
    ACTIONS(627), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(629), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(655), 1,
      anon_sym_RPAREN,
    ACTIONS(657), 1,
      anon_sym_COMMA,
    STATE(445), 1,
      aux_sym_apply_expression_repeat1,
    ACTIONS(527), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(529), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(533), 2,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(535), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(531), 3,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(537), 4,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [12706] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(539), 1,
      anon_sym_AMP_AMP,
    ACTIONS(627), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(629), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(659), 1,
      anon_sym_COMMA,
    ACTIONS(661), 1,
      anon_sym_RBRACK,
    STATE(496), 1,
      aux_sym_apply_expression_repeat1,
    ACTIONS(527), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(529), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(533), 2,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(535), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(531), 3,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(537), 4,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [12758] = 10,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(601), 1,
      anon_sym_STAR_STAR,
    ACTIONS(607), 1,
      anon_sym_AMP_AMP,
    ACTIONS(641), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(643), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(663), 1,
      anon_sym_LF,
    ACTIONS(665), 2,
      anon_sym_SEMI,
      anon_sym_,
    ACTIONS(599), 4,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(603), 5,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(605), 6,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [12802] = 10,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(601), 1,
      anon_sym_STAR_STAR,
    ACTIONS(607), 1,
      anon_sym_AMP_AMP,
    ACTIONS(641), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(643), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(667), 1,
      anon_sym_LF,
    ACTIONS(669), 2,
      anon_sym_SEMI,
      anon_sym_,
    ACTIONS(599), 4,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(603), 5,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(605), 6,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [12846] = 10,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(601), 1,
      anon_sym_STAR_STAR,
    ACTIONS(607), 1,
      anon_sym_AMP_AMP,
    ACTIONS(641), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(643), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(671), 1,
      anon_sym_LF,
    ACTIONS(673), 2,
      anon_sym_SEMI,
      anon_sym_,
    ACTIONS(599), 4,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(603), 5,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(605), 6,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [12890] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(539), 1,
      anon_sym_AMP_AMP,
    ACTIONS(627), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(629), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(675), 1,
      anon_sym_RPAREN,
    ACTIONS(677), 1,
      anon_sym_COMMA,
    STATE(455), 1,
      aux_sym_apply_expression_repeat1,
    ACTIONS(527), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(529), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(533), 2,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(535), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(531), 3,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(537), 4,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [12942] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(539), 1,
      anon_sym_AMP_AMP,
    ACTIONS(627), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(629), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(679), 1,
      anon_sym_RPAREN,
    ACTIONS(681), 1,
      anon_sym_COMMA,
    STATE(448), 1,
      aux_sym_apply_expression_repeat1,
    ACTIONS(527), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(529), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(533), 2,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(535), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(531), 3,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(537), 4,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [12994] = 10,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(601), 1,
      anon_sym_STAR_STAR,
    ACTIONS(607), 1,
      anon_sym_AMP_AMP,
    ACTIONS(641), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(643), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(683), 1,
      anon_sym_LF,
    ACTIONS(685), 2,
      anon_sym_SEMI,
      anon_sym_,
    ACTIONS(599), 4,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(603), 5,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(605), 6,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [13038] = 10,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(601), 1,
      anon_sym_STAR_STAR,
    ACTIONS(607), 1,
      anon_sym_AMP_AMP,
    ACTIONS(641), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(643), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(687), 1,
      anon_sym_LF,
    ACTIONS(689), 2,
      anon_sym_SEMI,
      anon_sym_,
    ACTIONS(599), 4,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(603), 5,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(605), 6,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [13082] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(539), 1,
      anon_sym_AMP_AMP,
    ACTIONS(627), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(629), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(691), 1,
      anon_sym_RPAREN,
    ACTIONS(693), 1,
      anon_sym_COMMA,
    STATE(474), 1,
      aux_sym_apply_expression_repeat1,
    ACTIONS(527), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(529), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(533), 2,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(535), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(531), 3,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(537), 4,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [13134] = 10,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(601), 1,
      anon_sym_STAR_STAR,
    ACTIONS(607), 1,
      anon_sym_AMP_AMP,
    ACTIONS(641), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(643), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(695), 1,
      anon_sym_LF,
    ACTIONS(697), 2,
      anon_sym_SEMI,
      anon_sym_,
    ACTIONS(599), 4,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(603), 5,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(605), 6,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [13178] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(539), 1,
      anon_sym_AMP_AMP,
    ACTIONS(627), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(629), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(699), 1,
      anon_sym_COMMA,
    ACTIONS(701), 1,
      anon_sym_RBRACK,
    STATE(484), 1,
      aux_sym_apply_expression_repeat1,
    ACTIONS(527), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(529), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(533), 2,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(535), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(531), 3,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(537), 4,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [13230] = 10,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(601), 1,
      anon_sym_STAR_STAR,
    ACTIONS(607), 1,
      anon_sym_AMP_AMP,
    ACTIONS(641), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(643), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(703), 1,
      anon_sym_LF,
    ACTIONS(705), 2,
      anon_sym_SEMI,
      anon_sym_,
    ACTIONS(599), 4,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(603), 5,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(605), 6,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [13274] = 10,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(601), 1,
      anon_sym_STAR_STAR,
    ACTIONS(607), 1,
      anon_sym_AMP_AMP,
    ACTIONS(641), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(643), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(707), 1,
      anon_sym_LF,
    ACTIONS(709), 2,
      anon_sym_SEMI,
      anon_sym_,
    ACTIONS(599), 4,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(603), 5,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(605), 6,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [13318] = 10,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(601), 1,
      anon_sym_STAR_STAR,
    ACTIONS(607), 1,
      anon_sym_AMP_AMP,
    ACTIONS(641), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(643), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(711), 1,
      anon_sym_LF,
    ACTIONS(713), 2,
      anon_sym_SEMI,
      anon_sym_,
    ACTIONS(599), 4,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(603), 5,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(605), 6,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [13362] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(539), 1,
      anon_sym_AMP_AMP,
    ACTIONS(627), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(629), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(715), 1,
      anon_sym_RBRACE,
    ACTIONS(717), 1,
      anon_sym_COMMA,
    ACTIONS(527), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(529), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(533), 2,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(535), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(531), 3,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(537), 4,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [13411] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(539), 1,
      anon_sym_AMP_AMP,
    ACTIONS(627), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(629), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(719), 1,
      anon_sym_RBRACE,
    ACTIONS(721), 1,
      anon_sym_COMMA,
    ACTIONS(527), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(529), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(533), 2,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(535), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(531), 3,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(537), 4,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [13460] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(539), 1,
      anon_sym_AMP_AMP,
    ACTIONS(627), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(629), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(527), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(529), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(533), 2,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(535), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(723), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
    ACTIONS(531), 3,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(537), 4,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [13507] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(539), 1,
      anon_sym_AMP_AMP,
    ACTIONS(627), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(629), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(725), 1,
      anon_sym_RBRACK,
    ACTIONS(527), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(529), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(533), 2,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(535), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(531), 3,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(537), 4,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [13553] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(539), 1,
      anon_sym_AMP_AMP,
    ACTIONS(627), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(629), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(727), 1,
      anon_sym_RBRACK,
    ACTIONS(527), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(529), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(533), 2,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(535), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(531), 3,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(537), 4,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [13599] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(539), 1,
      anon_sym_AMP_AMP,
    ACTIONS(627), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(629), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(729), 1,
      anon_sym_RPAREN,
    ACTIONS(527), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(529), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(533), 2,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(535), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(531), 3,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(537), 4,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [13645] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(469), 1,
      anon_sym_STAR_STAR,
    ACTIONS(539), 1,
      anon_sym_AMP_AMP,
    ACTIONS(627), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(629), 1,
      sym_colon_colon_lowercase_identifier,
    ACTIONS(527), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(529), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(533), 2,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
    ACTIONS(535), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(531), 3,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT,
    ACTIONS(537), 4,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [13688] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_priv,
    ACTIONS(9), 1,
      anon_sym_pub,
    ACTIONS(11), 1,
      anon_sym_type,
    ACTIONS(13), 1,
      anon_sym_struct,
    ACTIONS(15), 1,
      anon_sym_enum,
    ACTIONS(17), 1,
      anon_sym_let,
    ACTIONS(19), 1,
      anon_sym_func,
    ACTIONS(21), 1,
      anon_sym_interface,
    ACTIONS(731), 1,
      ts_builtin_sym_end,
    STATE(253), 1,
      aux_sym_structure_repeat1,
    STATE(449), 1,
      sym_structure_item,
    STATE(450), 1,
      sym_visibility,
    STATE(456), 1,
      sym_pub,
    STATE(452), 6,
      sym_type_defintion,
      sym_struct_definition,
      sym_enum_definition,
      sym_value_definition,
      sym_function_definition,
      sym_interface_definition,
  [13739] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(733), 1,
      ts_builtin_sym_end,
    ACTIONS(735), 1,
      anon_sym_priv,
    ACTIONS(738), 1,
      anon_sym_pub,
    ACTIONS(741), 1,
      anon_sym_type,
    ACTIONS(744), 1,
      anon_sym_struct,
    ACTIONS(747), 1,
      anon_sym_enum,
    ACTIONS(750), 1,
      anon_sym_let,
    ACTIONS(753), 1,
      anon_sym_func,
    ACTIONS(756), 1,
      anon_sym_interface,
    STATE(253), 1,
      aux_sym_structure_repeat1,
    STATE(449), 1,
      sym_structure_item,
    STATE(450), 1,
      sym_visibility,
    STATE(456), 1,
      sym_pub,
    STATE(452), 6,
      sym_type_defintion,
      sym_struct_definition,
      sym_enum_definition,
      sym_value_definition,
      sym_function_definition,
      sym_interface_definition,
  [13790] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(763), 1,
      anon_sym_COMMA,
    ACTIONS(759), 5,
      anon_sym__,
      anon_sym_true,
      anon_sym_false,
      sym_lowercase_identifier,
      sym_identifier,
    ACTIONS(761), 10,
      sym_float_literal,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      anon_sym_DQUOTE,
      sym_integer_literal,
      anon_sym_SQUOTE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_uppercase_identifier,
      sym_package_identifier,
  [13816] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(765), 5,
      anon_sym__,
      anon_sym_true,
      anon_sym_false,
      sym_lowercase_identifier,
      sym_identifier,
    ACTIONS(321), 10,
      sym_float_literal,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_DQUOTE,
      sym_integer_literal,
      anon_sym_SQUOTE,
      anon_sym_LBRACK,
      sym_uppercase_identifier,
      sym_package_identifier,
  [13839] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(767), 5,
      anon_sym__,
      anon_sym_true,
      anon_sym_false,
      sym_lowercase_identifier,
      sym_identifier,
    ACTIONS(769), 10,
      sym_float_literal,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      anon_sym_DQUOTE,
      sym_integer_literal,
      anon_sym_SQUOTE,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_uppercase_identifier,
      sym_package_identifier,
  [13862] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    ACTIONS(775), 1,
      anon_sym_RBRACK,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(459), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [13893] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    ACTIONS(777), 1,
      anon_sym_RPAREN,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(545), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [13924] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    ACTIONS(779), 1,
      anon_sym_RPAREN,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(459), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [13955] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    ACTIONS(781), 1,
      anon_sym_RPAREN,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(459), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [13986] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    ACTIONS(783), 1,
      anon_sym_RBRACK,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(459), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14017] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    ACTIONS(785), 1,
      anon_sym_RPAREN,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(525), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14048] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(787), 1,
      anon_sym_LPAREN,
    ACTIONS(791), 1,
      anon_sym_EQ,
    ACTIONS(789), 9,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
      anon_sym_RBRACK,
      anon_sym_EQ_GT,
      anon_sym_as,
      anon_sym_PIPE,
  [14069] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    ACTIONS(793), 1,
      anon_sym_RPAREN,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(476), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14100] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    ACTIONS(795), 1,
      anon_sym_RPAREN,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(459), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14131] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    ACTIONS(797), 1,
      anon_sym_RPAREN,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(459), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14162] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    ACTIONS(799), 1,
      anon_sym_RBRACK,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(459), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14193] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    ACTIONS(801), 1,
      anon_sym_RBRACK,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(459), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14224] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    ACTIONS(803), 1,
      anon_sym_RPAREN,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(459), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14255] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    ACTIONS(805), 1,
      anon_sym_RPAREN,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(459), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14286] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    ACTIONS(807), 1,
      anon_sym_RPAREN,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(538), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14317] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    ACTIONS(809), 1,
      anon_sym_RPAREN,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(459), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14348] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    ACTIONS(811), 1,
      anon_sym_RPAREN,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(459), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14379] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    ACTIONS(813), 1,
      anon_sym_RPAREN,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(459), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14410] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(817), 1,
      anon_sym__,
    ACTIONS(819), 1,
      sym_identifier,
    ACTIONS(821), 1,
      sym_package_identifier,
    STATE(358), 1,
      sym_qualified_type_identifier,
    STATE(515), 1,
      sym_type,
    STATE(504), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14438] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(825), 1,
      anon_sym_EQ,
    ACTIONS(823), 9,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
      anon_sym_RBRACK,
      anon_sym_EQ_GT,
      anon_sym_as,
      anon_sym_PIPE,
  [14456] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(501), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14484] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(817), 1,
      anon_sym__,
    ACTIONS(819), 1,
      sym_identifier,
    ACTIONS(821), 1,
      sym_package_identifier,
    STATE(358), 1,
      sym_qualified_type_identifier,
    STATE(509), 1,
      sym_type,
    STATE(504), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14512] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(576), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14540] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(829), 1,
      anon_sym_EQ,
    ACTIONS(827), 9,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
      anon_sym_RBRACK,
      anon_sym_EQ_GT,
      anon_sym_as,
      anon_sym_PIPE,
  [14558] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(506), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14586] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(655), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14614] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(833), 1,
      anon_sym_EQ,
    ACTIONS(831), 9,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
      anon_sym_RBRACK,
      anon_sym_EQ_GT,
      anon_sym_as,
      anon_sym_PIPE,
  [14632] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(817), 1,
      anon_sym__,
    ACTIONS(819), 1,
      sym_identifier,
    ACTIONS(821), 1,
      sym_package_identifier,
    STATE(358), 1,
      sym_qualified_type_identifier,
    STATE(569), 1,
      sym_type,
    STATE(504), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14660] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(837), 1,
      anon_sym_EQ,
    ACTIONS(835), 9,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
      anon_sym_RBRACK,
      anon_sym_EQ_GT,
      anon_sym_as,
      anon_sym_PIPE,
  [14678] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(841), 1,
      anon_sym_EQ,
    ACTIONS(839), 9,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
      anon_sym_RBRACK,
      anon_sym_EQ_GT,
      anon_sym_as,
      anon_sym_PIPE,
  [14696] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(404), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14724] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(845), 1,
      anon_sym_EQ,
    ACTIONS(843), 9,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
      anon_sym_RBRACK,
      anon_sym_EQ_GT,
      anon_sym_as,
      anon_sym_PIPE,
  [14742] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(849), 1,
      anon_sym_EQ,
    ACTIONS(851), 1,
      anon_sym_PIPE,
    ACTIONS(847), 8,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
      anon_sym_RBRACK,
      anon_sym_EQ_GT,
      anon_sym_as,
  [14762] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(855), 1,
      anon_sym_EQ,
    ACTIONS(853), 9,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
      anon_sym_RBRACK,
      anon_sym_EQ_GT,
      anon_sym_as,
      anon_sym_PIPE,
  [14780] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(550), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14808] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(859), 1,
      anon_sym_EQ,
    ACTIONS(857), 9,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
      anon_sym_RBRACK,
      anon_sym_EQ_GT,
      anon_sym_as,
      anon_sym_PIPE,
  [14826] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(817), 1,
      anon_sym__,
    ACTIONS(819), 1,
      sym_identifier,
    ACTIONS(821), 1,
      sym_package_identifier,
    STATE(358), 1,
      sym_qualified_type_identifier,
    STATE(556), 1,
      sym_type,
    STATE(504), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14854] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(863), 1,
      anon_sym_EQ,
    ACTIONS(861), 9,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
      anon_sym_RBRACK,
      anon_sym_EQ_GT,
      anon_sym_as,
      anon_sym_PIPE,
  [14872] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(867), 1,
      anon_sym_EQ,
    ACTIONS(865), 9,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
      anon_sym_RBRACK,
      anon_sym_EQ_GT,
      anon_sym_as,
      anon_sym_PIPE,
  [14890] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(635), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14918] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(871), 1,
      anon_sym_EQ,
    ACTIONS(869), 9,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
      anon_sym_RBRACK,
      anon_sym_EQ_GT,
      anon_sym_as,
      anon_sym_PIPE,
  [14936] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(648), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [14964] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(875), 1,
      anon_sym_EQ,
    ACTIONS(873), 9,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
      anon_sym_RBRACK,
      anon_sym_EQ_GT,
      anon_sym_as,
      anon_sym_PIPE,
  [14982] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(459), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [15010] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(402), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [15038] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(879), 1,
      anon_sym_EQ,
    ACTIONS(877), 9,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
      anon_sym_RBRACK,
      anon_sym_EQ_GT,
      anon_sym_as,
      anon_sym_PIPE,
  [15056] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(392), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [15084] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(817), 1,
      anon_sym__,
    ACTIONS(819), 1,
      sym_identifier,
    ACTIONS(821), 1,
      sym_package_identifier,
    STATE(358), 1,
      sym_qualified_type_identifier,
    STATE(554), 1,
      sym_type,
    STATE(504), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [15112] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(817), 1,
      anon_sym__,
    ACTIONS(819), 1,
      sym_identifier,
    ACTIONS(821), 1,
      sym_package_identifier,
    STATE(358), 1,
      sym_qualified_type_identifier,
    STATE(544), 1,
      sym_type,
    STATE(504), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [15140] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(388), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [15168] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(883), 1,
      anon_sym_EQ,
    ACTIONS(881), 9,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
      anon_sym_RBRACK,
      anon_sym_EQ_GT,
      anon_sym_as,
      anon_sym_PIPE,
  [15186] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(817), 1,
      anon_sym__,
    ACTIONS(819), 1,
      sym_identifier,
    ACTIONS(821), 1,
      sym_package_identifier,
    STATE(358), 1,
      sym_qualified_type_identifier,
    STATE(464), 1,
      sym_type,
    STATE(504), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [15214] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(771), 1,
      anon_sym_LPAREN,
    ACTIONS(773), 1,
      anon_sym__,
    STATE(339), 1,
      sym_qualified_type_identifier,
    STATE(490), 1,
      sym_type,
    STATE(374), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [15242] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(815), 1,
      anon_sym_LPAREN,
    ACTIONS(817), 1,
      anon_sym__,
    ACTIONS(819), 1,
      sym_identifier,
    ACTIONS(821), 1,
      sym_package_identifier,
    STATE(358), 1,
      sym_qualified_type_identifier,
    STATE(530), 1,
      sym_type,
    STATE(504), 4,
      sym_tuple_type,
      sym_function_type,
      sym_apply_type,
      sym_any,
  [15270] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(887), 1,
      anon_sym_EQ,
    ACTIONS(885), 9,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
      anon_sym_RBRACK,
      anon_sym_EQ_GT,
      anon_sym_as,
      anon_sym_PIPE,
  [15288] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(609), 1,
      anon_sym_LBRACE,
    ACTIONS(889), 1,
      anon_sym_LPAREN,
    ACTIONS(891), 1,
      anon_sym_EQ,
    ACTIONS(893), 1,
      anon_sym_LBRACK,
    ACTIONS(895), 1,
      anon_sym_DASH_GT,
    STATE(336), 1,
      sym_type_parameters,
    STATE(387), 1,
      sym_parameters,
    STATE(561), 1,
      sym_retuern_type,
    STATE(562), 1,
      sym_block_expression,
  [15319] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(897), 9,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_colon_colon_uppercase_identifier,
      sym_colon_colon_lowercase_identifier,
  [15334] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(363), 9,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_EQ,
      anon_sym_PLUS,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_colon_colon_uppercase_identifier,
      sym_colon_colon_lowercase_identifier,
  [15349] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(609), 1,
      anon_sym_LBRACE,
    ACTIONS(889), 1,
      anon_sym_LPAREN,
    ACTIONS(893), 1,
      anon_sym_LBRACK,
    ACTIONS(895), 1,
      anon_sym_DASH_GT,
    ACTIONS(899), 1,
      anon_sym_EQ,
    STATE(334), 1,
      sym_type_parameters,
    STATE(381), 1,
      sym_parameters,
    STATE(508), 1,
      sym_block_expression,
    STATE(512), 1,
      sym_retuern_type,
  [15380] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(733), 9,
      ts_builtin_sym_end,
      anon_sym_priv,
      anon_sym_pub,
      anon_sym_type,
      anon_sym_struct,
      anon_sym_enum,
      anon_sym_let,
      anon_sym_func,
      anon_sym_interface,
  [15395] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(901), 1,
      sym_lowercase_identifier,
    ACTIONS(904), 1,
      anon_sym_RBRACE,
    ACTIONS(906), 1,
      sym_identifier,
    ACTIONS(909), 1,
      sym_package_identifier,
    STATE(317), 1,
      aux_sym_interface_definition_repeat1,
    STATE(534), 1,
      sym_function_identifier,
    STATE(559), 1,
      sym_interface_method_declaration,
    STATE(639), 1,
      sym_qualified_type_identifier,
  [15423] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(912), 1,
      sym_lowercase_identifier,
    ACTIONS(914), 1,
      anon_sym_priv,
    ACTIONS(916), 1,
      anon_sym_pub,
    ACTIONS(918), 1,
      anon_sym_RBRACE,
    ACTIONS(920), 1,
      sym_mutability,
    STATE(326), 1,
      aux_sym_struct_definition_repeat1,
    STATE(535), 1,
      sym_struct_filed_declaration,
    STATE(595), 1,
      sym_visibility,
  [15451] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(922), 1,
      sym_lowercase_identifier,
    ACTIONS(924), 1,
      anon_sym_RBRACE,
    STATE(317), 1,
      aux_sym_interface_definition_repeat1,
    STATE(534), 1,
      sym_function_identifier,
    STATE(559), 1,
      sym_interface_method_declaration,
    STATE(639), 1,
      sym_qualified_type_identifier,
  [15479] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(912), 1,
      sym_lowercase_identifier,
    ACTIONS(914), 1,
      anon_sym_priv,
    ACTIONS(916), 1,
      anon_sym_pub,
    ACTIONS(920), 1,
      sym_mutability,
    ACTIONS(926), 1,
      anon_sym_RBRACE,
    STATE(326), 1,
      aux_sym_struct_definition_repeat1,
    STATE(535), 1,
      sym_struct_filed_declaration,
    STATE(595), 1,
      sym_visibility,
  [15507] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(912), 1,
      sym_lowercase_identifier,
    ACTIONS(914), 1,
      anon_sym_priv,
    ACTIONS(916), 1,
      anon_sym_pub,
    ACTIONS(920), 1,
      sym_mutability,
    ACTIONS(926), 1,
      anon_sym_RBRACE,
    STATE(328), 1,
      aux_sym_struct_definition_repeat1,
    STATE(535), 1,
      sym_struct_filed_declaration,
    STATE(595), 1,
      sym_visibility,
  [15535] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(912), 1,
      sym_lowercase_identifier,
    ACTIONS(914), 1,
      anon_sym_priv,
    ACTIONS(916), 1,
      anon_sym_pub,
    ACTIONS(920), 1,
      sym_mutability,
    ACTIONS(928), 1,
      anon_sym_RBRACE,
    STATE(318), 1,
      aux_sym_struct_definition_repeat1,
    STATE(535), 1,
      sym_struct_filed_declaration,
    STATE(595), 1,
      sym_visibility,
  [15563] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(922), 1,
      sym_lowercase_identifier,
    ACTIONS(930), 1,
      anon_sym_RBRACE,
    STATE(319), 1,
      aux_sym_interface_definition_repeat1,
    STATE(534), 1,
      sym_function_identifier,
    STATE(559), 1,
      sym_interface_method_declaration,
    STATE(639), 1,
      sym_qualified_type_identifier,
  [15591] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(912), 1,
      sym_lowercase_identifier,
    ACTIONS(914), 1,
      anon_sym_priv,
    ACTIONS(916), 1,
      anon_sym_pub,
    ACTIONS(920), 1,
      sym_mutability,
    ACTIONS(932), 1,
      anon_sym_RBRACE,
    STATE(320), 1,
      aux_sym_struct_definition_repeat1,
    STATE(535), 1,
      sym_struct_filed_declaration,
    STATE(595), 1,
      sym_visibility,
  [15619] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(922), 1,
      sym_lowercase_identifier,
    ACTIONS(934), 1,
      anon_sym_RBRACE,
    STATE(329), 1,
      aux_sym_interface_definition_repeat1,
    STATE(534), 1,
      sym_function_identifier,
    STATE(559), 1,
      sym_interface_method_declaration,
    STATE(639), 1,
      sym_qualified_type_identifier,
  [15647] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(936), 1,
      sym_lowercase_identifier,
    ACTIONS(939), 1,
      anon_sym_priv,
    ACTIONS(942), 1,
      anon_sym_pub,
    ACTIONS(945), 1,
      anon_sym_RBRACE,
    ACTIONS(947), 1,
      sym_mutability,
    STATE(326), 1,
      aux_sym_struct_definition_repeat1,
    STATE(535), 1,
      sym_struct_filed_declaration,
    STATE(595), 1,
      sym_visibility,
  [15675] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(950), 1,
      anon_sym_LPAREN,
    STATE(365), 1,
      sym_pub_attribute,
    ACTIONS(952), 3,
      anon_sym_type,
      anon_sym_struct,
      anon_sym_enum,
    ACTIONS(954), 3,
      anon_sym_let,
      anon_sym_func,
      anon_sym_interface,
  [15695] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(912), 1,
      sym_lowercase_identifier,
    ACTIONS(914), 1,
      anon_sym_priv,
    ACTIONS(916), 1,
      anon_sym_pub,
    ACTIONS(920), 1,
      sym_mutability,
    ACTIONS(928), 1,
      anon_sym_RBRACE,
    STATE(326), 1,
      aux_sym_struct_definition_repeat1,
    STATE(535), 1,
      sym_struct_filed_declaration,
    STATE(595), 1,
      sym_visibility,
  [15723] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(922), 1,
      sym_lowercase_identifier,
    ACTIONS(930), 1,
      anon_sym_RBRACE,
    STATE(317), 1,
      aux_sym_interface_definition_repeat1,
    STATE(534), 1,
      sym_function_identifier,
    STATE(559), 1,
      sym_interface_method_declaration,
    STATE(639), 1,
      sym_qualified_type_identifier,
  [15751] = 7,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(956), 1,
      anon_sym_DQUOTE,
    ACTIONS(958), 1,
      anon_sym_BSLASH_LPAREN,
    ACTIONS(960), 1,
      sym_unescaped_string_fragment,
    ACTIONS(962), 1,
      sym_escape_seqence,
    STATE(331), 1,
      sym_interpolator,
    STATE(337), 2,
      sym_string_fragement,
      aux_sym_string_interpolation_repeat1,
  [15774] = 6,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(958), 1,
      anon_sym_BSLASH_LPAREN,
    ACTIONS(960), 1,
      sym_unescaped_string_fragment,
    ACTIONS(962), 1,
      sym_escape_seqence,
    ACTIONS(964), 1,
      anon_sym_DQUOTE,
    STATE(346), 3,
      sym_interpolator,
      sym_string_fragement,
      aux_sym_string_interpolation_repeat2,
  [15795] = 6,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(958), 1,
      anon_sym_BSLASH_LPAREN,
    ACTIONS(960), 1,
      sym_unescaped_string_fragment,
    ACTIONS(962), 1,
      sym_escape_seqence,
    ACTIONS(966), 1,
      anon_sym_DQUOTE,
    STATE(338), 3,
      sym_interpolator,
      sym_string_fragement,
      aux_sym_string_interpolation_repeat2,
  [15816] = 7,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(958), 1,
      anon_sym_BSLASH_LPAREN,
    ACTIONS(960), 1,
      sym_unescaped_string_fragment,
    ACTIONS(962), 1,
      sym_escape_seqence,
    ACTIONS(968), 1,
      anon_sym_DQUOTE,
    STATE(341), 1,
      sym_interpolator,
    STATE(350), 2,
      sym_string_fragement,
      aux_sym_string_interpolation_repeat1,
  [15839] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(609), 1,
      anon_sym_LBRACE,
    ACTIONS(889), 1,
      anon_sym_LPAREN,
    ACTIONS(891), 1,
      anon_sym_EQ,
    ACTIONS(895), 1,
      anon_sym_DASH_GT,
    STATE(387), 1,
      sym_parameters,
    STATE(561), 1,
      sym_retuern_type,
    STATE(562), 1,
      sym_block_expression,
  [15864] = 6,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(958), 1,
      anon_sym_BSLASH_LPAREN,
    ACTIONS(960), 1,
      sym_unescaped_string_fragment,
    ACTIONS(962), 1,
      sym_escape_seqence,
    ACTIONS(970), 1,
      anon_sym_DQUOTE,
    STATE(338), 3,
      sym_interpolator,
      sym_string_fragement,
      aux_sym_string_interpolation_repeat2,
  [15885] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(609), 1,
      anon_sym_LBRACE,
    ACTIONS(889), 1,
      anon_sym_LPAREN,
    ACTIONS(895), 1,
      anon_sym_DASH_GT,
    ACTIONS(972), 1,
      anon_sym_EQ,
    STATE(369), 1,
      sym_parameters,
    STATE(520), 1,
      sym_retuern_type,
    STATE(523), 1,
      sym_block_expression,
  [15910] = 7,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(958), 1,
      anon_sym_BSLASH_LPAREN,
    ACTIONS(960), 1,
      sym_unescaped_string_fragment,
    ACTIONS(962), 1,
      sym_escape_seqence,
    ACTIONS(974), 1,
      anon_sym_DQUOTE,
    STATE(348), 1,
      sym_interpolator,
    STATE(350), 2,
      sym_string_fragement,
      aux_sym_string_interpolation_repeat1,
  [15933] = 6,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(976), 1,
      anon_sym_DQUOTE,
    ACTIONS(978), 1,
      anon_sym_BSLASH_LPAREN,
    ACTIONS(981), 1,
      sym_unescaped_string_fragment,
    ACTIONS(984), 1,
      sym_escape_seqence,
    STATE(338), 3,
      sym_interpolator,
      sym_string_fragement,
      aux_sym_string_interpolation_repeat2,
  [15954] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(989), 1,
      anon_sym_LBRACK,
    STATE(393), 1,
      sym_type_arguments,
    ACTIONS(987), 5,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_EQ,
      anon_sym_RBRACK,
  [15971] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(306), 1,
      anon_sym_DOT_DOT,
    ACTIONS(991), 1,
      sym_lowercase_identifier,
    ACTIONS(993), 1,
      anon_sym_RBRACE,
    STATE(453), 1,
      sym_filed_single_pattern,
    STATE(650), 1,
      sym_dotdot_pattern,
    STATE(488), 2,
      sym_labeled_pattern,
      sym_labeled_pattern_pun,
  [15994] = 6,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(958), 1,
      anon_sym_BSLASH_LPAREN,
    ACTIONS(960), 1,
      sym_unescaped_string_fragment,
    ACTIONS(962), 1,
      sym_escape_seqence,
    ACTIONS(995), 1,
      anon_sym_DQUOTE,
    STATE(332), 3,
      sym_interpolator,
      sym_string_fragement,
      aux_sym_string_interpolation_repeat2,
  [16015] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(306), 1,
      anon_sym_DOT_DOT,
    ACTIONS(991), 1,
      sym_lowercase_identifier,
    ACTIONS(997), 1,
      anon_sym_RBRACE,
    STATE(453), 1,
      sym_filed_single_pattern,
    STATE(628), 1,
      sym_dotdot_pattern,
    STATE(488), 2,
      sym_labeled_pattern,
      sym_labeled_pattern_pun,
  [16038] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(306), 1,
      anon_sym_DOT_DOT,
    ACTIONS(387), 1,
      anon_sym_RBRACK,
    ACTIONS(851), 1,
      anon_sym_PIPE,
    ACTIONS(999), 1,
      anon_sym_COMMA,
    ACTIONS(1001), 1,
      anon_sym_as,
    STATE(357), 1,
      aux_sym_constructor_pattern_repeat1,
    STATE(606), 1,
      sym_dotdot_pattern,
  [16063] = 6,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(958), 1,
      anon_sym_BSLASH_LPAREN,
    ACTIONS(960), 1,
      sym_unescaped_string_fragment,
    ACTIONS(962), 1,
      sym_escape_seqence,
    ACTIONS(995), 1,
      anon_sym_DQUOTE,
    STATE(338), 3,
      sym_interpolator,
      sym_string_fragement,
      aux_sym_string_interpolation_repeat2,
  [16084] = 6,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(958), 1,
      anon_sym_BSLASH_LPAREN,
    ACTIONS(960), 1,
      sym_unescaped_string_fragment,
    ACTIONS(962), 1,
      sym_escape_seqence,
    ACTIONS(1003), 1,
      anon_sym_DQUOTE,
    STATE(344), 3,
      sym_interpolator,
      sym_string_fragement,
      aux_sym_string_interpolation_repeat2,
  [16105] = 6,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(958), 1,
      anon_sym_BSLASH_LPAREN,
    ACTIONS(960), 1,
      sym_unescaped_string_fragment,
    ACTIONS(962), 1,
      sym_escape_seqence,
    ACTIONS(1005), 1,
      anon_sym_DQUOTE,
    STATE(338), 3,
      sym_interpolator,
      sym_string_fragement,
      aux_sym_string_interpolation_repeat2,
  [16126] = 7,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(958), 1,
      anon_sym_BSLASH_LPAREN,
    ACTIONS(960), 1,
      sym_unescaped_string_fragment,
    ACTIONS(962), 1,
      sym_escape_seqence,
    ACTIONS(1007), 1,
      anon_sym_DQUOTE,
    STATE(345), 1,
      sym_interpolator,
    STATE(333), 2,
      sym_string_fragement,
      aux_sym_string_interpolation_repeat1,
  [16149] = 6,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(958), 1,
      anon_sym_BSLASH_LPAREN,
    ACTIONS(960), 1,
      sym_unescaped_string_fragment,
    ACTIONS(962), 1,
      sym_escape_seqence,
    ACTIONS(1005), 1,
      anon_sym_DQUOTE,
    STATE(335), 3,
      sym_interpolator,
      sym_string_fragement,
      aux_sym_string_interpolation_repeat2,
  [16170] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1011), 1,
      anon_sym_DASH_GT,
    ACTIONS(1009), 5,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_EQ,
      anon_sym_RBRACK,
  [16184] = 5,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1015), 1,
      sym_unescaped_string_fragment,
    ACTIONS(1018), 1,
      sym_escape_seqence,
    ACTIONS(1013), 2,
      anon_sym_DQUOTE,
      anon_sym_BSLASH_LPAREN,
    STATE(350), 2,
      sym_string_fragement,
      aux_sym_string_interpolation_repeat1,
  [16202] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(851), 1,
      anon_sym_PIPE,
    ACTIONS(1001), 1,
      anon_sym_as,
    ACTIONS(1021), 4,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
      anon_sym_RBRACK,
  [16218] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(991), 1,
      sym_lowercase_identifier,
    ACTIONS(1023), 1,
      anon_sym_RBRACE,
    STATE(391), 1,
      sym_filed_single_pattern,
    STATE(619), 1,
      sym_struct_filed_pattern,
    STATE(488), 2,
      sym_labeled_pattern,
      sym_labeled_pattern_pun,
  [16238] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1027), 1,
      anon_sym_DASH_GT,
    ACTIONS(1025), 5,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_EQ,
      anon_sym_RBRACK,
  [16252] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1031), 1,
      anon_sym_DASH_GT,
    ACTIONS(1029), 5,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_EQ,
      anon_sym_RBRACK,
  [16266] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1035), 1,
      anon_sym_DASH_GT,
    ACTIONS(1033), 5,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_EQ,
      anon_sym_RBRACK,
  [16280] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1037), 5,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      anon_sym_EQ,
      anon_sym_LBRACK,
      anon_sym_DASH_GT,
  [16291] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(306), 1,
      anon_sym_DOT_DOT,
    ACTIONS(308), 1,
      anon_sym_RBRACK,
    ACTIONS(1039), 1,
      anon_sym_COMMA,
    STATE(389), 1,
      aux_sym_constructor_pattern_repeat1,
    STATE(649), 1,
      sym_dotdot_pattern,
  [16310] = 5,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(987), 1,
      anon_sym_LF,
    ACTIONS(1043), 1,
      anon_sym_LBRACK,
    STATE(516), 1,
      sym_type_arguments,
    ACTIONS(1041), 2,
      anon_sym_SEMI,
      anon_sym_,
  [16327] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1045), 5,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_EQ,
      anon_sym_RBRACK,
  [16338] = 5,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1047), 1,
      anon_sym_LF,
    ACTIONS(1051), 1,
      anon_sym_LBRACK,
    STATE(555), 1,
      sym_type_parameters,
    ACTIONS(1049), 2,
      anon_sym_SEMI,
      anon_sym_,
  [16355] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(922), 1,
      sym_lowercase_identifier,
    STATE(312), 1,
      sym_function_identifier,
    STATE(639), 1,
      sym_qualified_type_identifier,
  [16374] = 5,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1053), 1,
      anon_sym_LF,
    ACTIONS(1057), 1,
      anon_sym_DASH_GT,
    STATE(500), 1,
      sym_retuern_type,
    ACTIONS(1055), 2,
      anon_sym_SEMI,
      anon_sym_,
  [16391] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1059), 5,
      anon_sym_type,
      anon_sym_struct,
      anon_sym_enum,
      sym_mutability,
      sym_lowercase_identifier,
  [16402] = 5,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1051), 1,
      anon_sym_LBRACK,
    ACTIONS(1061), 1,
      anon_sym_LF,
    STATE(483), 1,
      sym_type_parameters,
    ACTIONS(1063), 2,
      anon_sym_SEMI,
      anon_sym_,
  [16419] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1065), 5,
      anon_sym_type,
      anon_sym_struct,
      anon_sym_enum,
      sym_mutability,
      sym_lowercase_identifier,
  [16430] = 5,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(956), 1,
      anon_sym_DQUOTE,
    ACTIONS(960), 1,
      sym_unescaped_string_fragment,
    ACTIONS(962), 1,
      sym_escape_seqence,
    STATE(376), 2,
      sym_string_fragement,
      aux_sym_string_interpolation_repeat1,
  [16447] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1067), 1,
      sym_lowercase_identifier,
    ACTIONS(1069), 1,
      anon_sym_RBRACE,
    STATE(451), 1,
      sym_struct_filed_expression,
    STATE(572), 2,
      sym_labeled_expression,
      sym_labeled_expression_pun,
  [16464] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(851), 1,
      anon_sym_PIPE,
    ACTIONS(1001), 1,
      anon_sym_as,
    ACTIONS(1071), 1,
      anon_sym_RPAREN,
    ACTIONS(1073), 1,
      anon_sym_COMMA,
    STATE(482), 1,
      aux_sym_constructor_pattern_repeat1,
  [16483] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(609), 1,
      anon_sym_LBRACE,
    ACTIONS(895), 1,
      anon_sym_DASH_GT,
    ACTIONS(1075), 1,
      anon_sym_EQ,
    STATE(473), 1,
      sym_retuern_type,
    STATE(479), 1,
      sym_block_expression,
  [16502] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(851), 1,
      anon_sym_PIPE,
    ACTIONS(1001), 1,
      anon_sym_as,
    ACTIONS(1077), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
  [16517] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1067), 1,
      sym_lowercase_identifier,
    ACTIONS(1079), 1,
      anon_sym_RBRACE,
    STATE(593), 1,
      sym_labeled_expression,
    STATE(617), 1,
      sym_labeled_expression_pun,
    STATE(644), 1,
      sym_struct_field_expression,
  [16536] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1081), 5,
      anon_sym_type,
      anon_sym_struct,
      anon_sym_enum,
      sym_mutability,
      sym_lowercase_identifier,
  [16547] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1083), 5,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_EQ,
      anon_sym_RBRACK,
  [16558] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1085), 5,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_EQ,
      anon_sym_RBRACK,
  [16569] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1067), 1,
      sym_lowercase_identifier,
    ACTIONS(1087), 1,
      anon_sym_RBRACE,
    STATE(593), 1,
      sym_labeled_expression,
    STATE(617), 1,
      sym_labeled_expression_pun,
    STATE(646), 1,
      sym_struct_field_expression,
  [16588] = 5,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(960), 1,
      sym_unescaped_string_fragment,
    ACTIONS(962), 1,
      sym_escape_seqence,
    ACTIONS(974), 1,
      anon_sym_DQUOTE,
    STATE(350), 2,
      sym_string_fragement,
      aux_sym_string_interpolation_repeat1,
  [16605] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(306), 1,
      anon_sym_DOT_DOT,
    ACTIONS(993), 1,
      anon_sym_RBRACE,
    ACTIONS(1089), 1,
      anon_sym_COMMA,
    STATE(439), 1,
      aux_sym_struct_filed_pattern_repeat1,
    STATE(650), 1,
      sym_dotdot_pattern,
  [16624] = 5,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(960), 1,
      sym_unescaped_string_fragment,
    ACTIONS(962), 1,
      sym_escape_seqence,
    ACTIONS(968), 1,
      anon_sym_DQUOTE,
    STATE(350), 2,
      sym_string_fragement,
      aux_sym_string_interpolation_repeat1,
  [16641] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(922), 1,
      sym_lowercase_identifier,
    STATE(315), 1,
      sym_function_identifier,
    STATE(639), 1,
      sym_qualified_type_identifier,
  [16660] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1091), 5,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      anon_sym_EQ,
      anon_sym_LBRACK,
      anon_sym_DASH_GT,
  [16671] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(609), 1,
      anon_sym_LBRACE,
    ACTIONS(891), 1,
      anon_sym_EQ,
    ACTIONS(895), 1,
      anon_sym_DASH_GT,
    STATE(561), 1,
      sym_retuern_type,
    STATE(562), 1,
      sym_block_expression,
  [16690] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(851), 1,
      anon_sym_PIPE,
    ACTIONS(1001), 1,
      anon_sym_as,
    ACTIONS(1093), 1,
      anon_sym_COLON,
    ACTIONS(1095), 1,
      anon_sym_EQ,
    STATE(624), 1,
      sym_type_annotation,
  [16709] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(308), 1,
      anon_sym_RBRACK,
    ACTIONS(851), 1,
      anon_sym_PIPE,
    ACTIONS(1001), 1,
      anon_sym_as,
    ACTIONS(1097), 1,
      anon_sym_COMMA,
    STATE(458), 1,
      aux_sym_constructor_pattern_repeat1,
  [16728] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(851), 1,
      anon_sym_PIPE,
    ACTIONS(1001), 1,
      anon_sym_as,
    ACTIONS(1099), 1,
      anon_sym_RPAREN,
    ACTIONS(1101), 1,
      anon_sym_COMMA,
    STATE(461), 1,
      aux_sym_constructor_pattern_repeat1,
  [16747] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1103), 5,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_EQ,
      anon_sym_RBRACK,
  [16758] = 5,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(960), 1,
      sym_unescaped_string_fragment,
    ACTIONS(962), 1,
      sym_escape_seqence,
    ACTIONS(1007), 1,
      anon_sym_DQUOTE,
    STATE(378), 2,
      sym_string_fragement,
      aux_sym_string_interpolation_repeat1,
  [16775] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(609), 1,
      anon_sym_LBRACE,
    ACTIONS(895), 1,
      anon_sym_DASH_GT,
    ACTIONS(972), 1,
      anon_sym_EQ,
    STATE(520), 1,
      sym_retuern_type,
    STATE(523), 1,
      sym_block_expression,
  [16794] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1105), 5,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_EQ,
      anon_sym_RBRACK,
  [16805] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1107), 1,
      anon_sym_COMMA,
    STATE(389), 1,
      aux_sym_constructor_pattern_repeat1,
    ACTIONS(1021), 3,
      anon_sym_RPAREN,
      anon_sym_DOT_DOT,
      anon_sym_RBRACK,
  [16820] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1067), 1,
      sym_lowercase_identifier,
    ACTIONS(1110), 1,
      anon_sym_RBRACE,
    STATE(582), 1,
      sym_struct_filed_expression,
    STATE(572), 2,
      sym_labeled_expression,
      sym_labeled_expression_pun,
  [16837] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(306), 1,
      anon_sym_DOT_DOT,
    ACTIONS(1112), 1,
      anon_sym_RBRACE,
    ACTIONS(1114), 1,
      anon_sym_COMMA,
    STATE(377), 1,
      aux_sym_struct_filed_pattern_repeat1,
    STATE(607), 1,
      sym_dotdot_pattern,
  [16856] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1116), 5,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_EQ,
      anon_sym_RBRACK,
  [16867] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1118), 5,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_EQ,
      anon_sym_RBRACK,
  [16878] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1067), 1,
      sym_lowercase_identifier,
    ACTIONS(1120), 1,
      anon_sym_RBRACE,
    STATE(582), 1,
      sym_struct_filed_expression,
    STATE(572), 2,
      sym_labeled_expression,
      sym_labeled_expression_pun,
  [16895] = 5,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1057), 1,
      anon_sym_DASH_GT,
    ACTIONS(1122), 1,
      anon_sym_LF,
    STATE(563), 1,
      sym_retuern_type,
    ACTIONS(1124), 2,
      anon_sym_SEMI,
      anon_sym_,
  [16912] = 5,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1057), 1,
      anon_sym_DASH_GT,
    ACTIONS(1126), 1,
      anon_sym_LF,
    STATE(466), 1,
      sym_retuern_type,
    ACTIONS(1128), 2,
      anon_sym_SEMI,
      anon_sym_,
  [16929] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(851), 1,
      anon_sym_PIPE,
    ACTIONS(1001), 1,
      anon_sym_as,
    ACTIONS(1130), 1,
      anon_sym_RPAREN,
    ACTIONS(1132), 1,
      anon_sym_COLON,
    ACTIONS(1134), 1,
      anon_sym_COMMA,
  [16948] = 5,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1057), 1,
      anon_sym_DASH_GT,
    ACTIONS(1136), 1,
      anon_sym_LF,
    STATE(497), 1,
      sym_retuern_type,
    ACTIONS(1138), 2,
      anon_sym_SEMI,
      anon_sym_,
  [16965] = 5,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1057), 1,
      anon_sym_DASH_GT,
    ACTIONS(1140), 1,
      anon_sym_LF,
    STATE(489), 1,
      sym_retuern_type,
    ACTIONS(1142), 2,
      anon_sym_SEMI,
      anon_sym_,
  [16982] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1144), 5,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_EQ,
      anon_sym_RBRACK,
  [16993] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(1146), 1,
      sym_identifier,
    STATE(406), 1,
      sym_constraint,
    STATE(517), 1,
      sym_qualified_type_identifier,
    STATE(597), 1,
      sym_constraints,
  [17012] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1148), 5,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_EQ,
      anon_sym_RBRACK,
  [17023] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(945), 1,
      anon_sym_RBRACE,
    ACTIONS(1150), 4,
      anon_sym_priv,
      anon_sym_pub,
      sym_mutability,
      sym_lowercase_identifier,
  [17036] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1152), 5,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_COMMA,
      anon_sym_EQ,
      anon_sym_RBRACK,
  [17047] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(363), 1,
      anon_sym_LF,
    ACTIONS(587), 3,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LBRACK,
  [17059] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1156), 1,
      anon_sym_PLUS,
    STATE(429), 1,
      aux_sym_constraints_repeat1,
    ACTIONS(1154), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [17073] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(613), 1,
      anon_sym_LBRACE,
    ACTIONS(1158), 1,
      anon_sym_if,
    STATE(145), 2,
      sym_block_expression,
      sym_if_expression,
  [17087] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1160), 1,
      anon_sym_RBRACE,
    ACTIONS(1162), 1,
      sym_uppercase_identifier,
    STATE(413), 1,
      aux_sym_enum_definition_repeat1,
    STATE(542), 1,
      sym_enum_constructor,
  [17103] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1166), 1,
      anon_sym_PLUS,
    STATE(409), 1,
      aux_sym_constraints_repeat1,
    ACTIONS(1164), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [17117] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(613), 1,
      anon_sym_LBRACE,
    ACTIONS(895), 1,
      anon_sym_DASH_GT,
    STATE(144), 1,
      sym_block_expression,
    STATE(587), 1,
      sym_retuern_type,
  [17133] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(950), 1,
      anon_sym_LPAREN,
    STATE(365), 1,
      sym_pub_attribute,
    ACTIONS(1081), 2,
      sym_mutability,
      sym_lowercase_identifier,
  [17147] = 4,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1169), 1,
      anon_sym_LF,
    ACTIONS(1173), 1,
      anon_sym_LPAREN,
    ACTIONS(1171), 2,
      anon_sym_SEMI,
      anon_sym_,
  [17161] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1162), 1,
      sym_uppercase_identifier,
    ACTIONS(1175), 1,
      anon_sym_RBRACE,
    STATE(419), 1,
      aux_sym_enum_definition_repeat1,
    STATE(542), 1,
      sym_enum_constructor,
  [17177] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1162), 1,
      sym_uppercase_identifier,
    ACTIONS(1175), 1,
      anon_sym_RBRACE,
    STATE(420), 1,
      aux_sym_enum_definition_repeat1,
    STATE(542), 1,
      sym_enum_constructor,
  [17193] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1093), 1,
      anon_sym_COLON,
    STATE(571), 1,
      sym_type_annotation,
    ACTIONS(1177), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [17207] = 4,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1025), 1,
      anon_sym_LF,
    ACTIONS(1181), 1,
      anon_sym_DASH_GT,
    ACTIONS(1179), 2,
      anon_sym_SEMI,
      anon_sym_,
  [17221] = 4,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1033), 1,
      anon_sym_LF,
    ACTIONS(1185), 1,
      anon_sym_DASH_GT,
    ACTIONS(1183), 2,
      anon_sym_SEMI,
      anon_sym_,
  [17235] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1187), 4,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [17245] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1189), 1,
      anon_sym_RBRACE,
    ACTIONS(1191), 1,
      sym_uppercase_identifier,
    STATE(419), 1,
      aux_sym_enum_definition_repeat1,
    STATE(542), 1,
      sym_enum_constructor,
  [17261] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1162), 1,
      sym_uppercase_identifier,
    ACTIONS(1194), 1,
      anon_sym_RBRACE,
    STATE(419), 1,
      aux_sym_enum_definition_repeat1,
    STATE(542), 1,
      sym_enum_constructor,
  [17277] = 4,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1029), 1,
      anon_sym_LF,
    ACTIONS(1198), 1,
      anon_sym_DASH_GT,
    ACTIONS(1196), 2,
      anon_sym_SEMI,
      anon_sym_,
  [17291] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1200), 4,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [17301] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1204), 1,
      sym_escape_seqence,
    ACTIONS(1202), 3,
      anon_sym_DQUOTE,
      anon_sym_BSLASH_LPAREN,
      sym_unescaped_string_fragment,
  [17313] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(609), 1,
      anon_sym_LBRACE,
    ACTIONS(895), 1,
      anon_sym_DASH_GT,
    STATE(187), 1,
      sym_block_expression,
    STATE(594), 1,
      sym_retuern_type,
  [17329] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1162), 1,
      sym_uppercase_identifier,
    ACTIONS(1194), 1,
      anon_sym_RBRACE,
    STATE(435), 1,
      aux_sym_enum_definition_repeat1,
    STATE(542), 1,
      sym_enum_constructor,
  [17345] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1208), 1,
      anon_sym_COMMA,
    STATE(426), 1,
      aux_sym_enum_constructor_repeat1,
    ACTIONS(1206), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [17359] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(897), 1,
      anon_sym_LF,
    ACTIONS(1211), 3,
      anon_sym_SEMI,
      anon_sym_,
      anon_sym_LBRACK,
  [17371] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(609), 1,
      anon_sym_LBRACE,
    ACTIONS(1213), 1,
      anon_sym_if,
    STATE(211), 2,
      sym_block_expression,
      sym_if_expression,
  [17385] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1156), 1,
      anon_sym_PLUS,
    STATE(409), 1,
      aux_sym_constraints_repeat1,
    ACTIONS(1215), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [17399] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(302), 1,
      sym_package_identifier,
    ACTIONS(1146), 1,
      sym_identifier,
    STATE(485), 1,
      sym_constraint,
    STATE(517), 1,
      sym_qualified_type_identifier,
  [17415] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1219), 1,
      sym_escape_seqence,
    ACTIONS(1217), 3,
      anon_sym_DQUOTE,
      anon_sym_BSLASH_LPAREN,
      sym_unescaped_string_fragment,
  [17427] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(609), 1,
      anon_sym_LBRACE,
    ACTIONS(895), 1,
      anon_sym_DASH_GT,
    STATE(478), 1,
      sym_block_expression,
    STATE(591), 1,
      sym_retuern_type,
  [17443] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1221), 1,
      sym_identifier,
    ACTIONS(904), 3,
      anon_sym_RBRACE,
      sym_lowercase_identifier,
      sym_package_identifier,
  [17455] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1225), 1,
      anon_sym_COLON,
    ACTIONS(1223), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
  [17467] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1162), 1,
      sym_uppercase_identifier,
    ACTIONS(1227), 1,
      anon_sym_RBRACE,
    STATE(419), 1,
      aux_sym_enum_definition_repeat1,
    STATE(542), 1,
      sym_enum_constructor,
  [17483] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(991), 1,
      sym_lowercase_identifier,
    STATE(453), 1,
      sym_filed_single_pattern,
    STATE(488), 2,
      sym_labeled_pattern,
      sym_labeled_pattern_pun,
  [17497] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1229), 4,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [17507] = 4,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1009), 1,
      anon_sym_LF,
    ACTIONS(1233), 1,
      anon_sym_DASH_GT,
    ACTIONS(1231), 2,
      anon_sym_SEMI,
      anon_sym_,
  [17521] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1237), 1,
      anon_sym_COMMA,
    STATE(439), 1,
      aux_sym_struct_filed_pattern_repeat1,
    ACTIONS(1235), 2,
      anon_sym_RBRACE,
      anon_sym_DOT_DOT,
  [17535] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1240), 1,
      anon_sym_COMMA,
    STATE(440), 1,
      aux_sym_apply_expression_repeat1,
    ACTIONS(653), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [17549] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1067), 1,
      sym_lowercase_identifier,
    STATE(582), 1,
      sym_struct_filed_expression,
    STATE(572), 2,
      sym_labeled_expression,
      sym_labeled_expression_pun,
  [17563] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1243), 1,
      anon_sym_LF,
    ACTIONS(1245), 2,
      anon_sym_SEMI,
      anon_sym_,
  [17574] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1247), 1,
      anon_sym_COMMA,
    ACTIONS(1249), 1,
      anon_sym_RBRACK,
    STATE(546), 1,
      aux_sym_type_parameters_repeat1,
  [17587] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1251), 3,
      anon_sym_LBRACE,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [17596] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(226), 1,
      anon_sym_RPAREN,
    ACTIONS(1253), 1,
      anon_sym_COMMA,
    STATE(440), 1,
      aux_sym_apply_expression_repeat1,
  [17609] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(851), 1,
      anon_sym_PIPE,
    ACTIONS(1001), 1,
      anon_sym_as,
    ACTIONS(1255), 1,
      anon_sym_EQ_GT,
  [17622] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1257), 1,
      anon_sym_LF,
    ACTIONS(1259), 2,
      anon_sym_SEMI,
      anon_sym_,
  [17633] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(240), 1,
      anon_sym_RPAREN,
    ACTIONS(1261), 1,
      anon_sym_COMMA,
    STATE(440), 1,
      aux_sym_apply_expression_repeat1,
  [17646] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1263), 1,
      anon_sym_LF,
    ACTIONS(1265), 2,
      anon_sym_SEMI,
      anon_sym_,
  [17657] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1267), 1,
      anon_sym_type,
    ACTIONS(1269), 1,
      anon_sym_struct,
    ACTIONS(1271), 1,
      anon_sym_enum,
  [17670] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1273), 1,
      anon_sym_RBRACE,
    ACTIONS(1275), 1,
      anon_sym_COMMA,
    STATE(540), 1,
      aux_sym_struct_field_expression_repeat1,
  [17683] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1277), 1,
      anon_sym_LF,
    ACTIONS(1279), 2,
      anon_sym_SEMI,
      anon_sym_,
  [17694] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1235), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
  [17703] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1283), 1,
      anon_sym_COLON,
    ACTIONS(1281), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [17714] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(216), 1,
      anon_sym_RPAREN,
    ACTIONS(1285), 1,
      anon_sym_COMMA,
    STATE(440), 1,
      aux_sym_apply_expression_repeat1,
  [17727] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1287), 1,
      anon_sym_let,
    ACTIONS(1289), 1,
      anon_sym_func,
    ACTIONS(1291), 1,
      anon_sym_interface,
  [17740] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(799), 1,
      anon_sym_RBRACK,
    ACTIONS(1293), 1,
      anon_sym_COMMA,
    STATE(426), 1,
      aux_sym_enum_constructor_repeat1,
  [17753] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(347), 1,
      anon_sym_RBRACK,
    ACTIONS(1295), 1,
      anon_sym_COMMA,
    STATE(389), 1,
      aux_sym_constructor_pattern_repeat1,
  [17766] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1206), 3,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [17775] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(803), 1,
      anon_sym_RPAREN,
    ACTIONS(1297), 1,
      anon_sym_COMMA,
    STATE(426), 1,
      aux_sym_enum_constructor_repeat1,
  [17788] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(369), 1,
      anon_sym_RPAREN,
    ACTIONS(1299), 1,
      anon_sym_COMMA,
    STATE(389), 1,
      aux_sym_constructor_pattern_repeat1,
  [17801] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1301), 1,
      anon_sym_LF,
    ACTIONS(1303), 2,
      anon_sym_SEMI,
      anon_sym_,
  [17812] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1305), 1,
      anon_sym_LF,
    ACTIONS(1307), 2,
      anon_sym_SEMI,
      anon_sym_,
  [17823] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1309), 1,
      anon_sym_LF,
    ACTIONS(1311), 2,
      anon_sym_SEMI,
      anon_sym_,
  [17834] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1313), 1,
      anon_sym_LF,
    ACTIONS(1315), 2,
      anon_sym_SEMI,
      anon_sym_,
  [17845] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1140), 1,
      anon_sym_LF,
    ACTIONS(1142), 2,
      anon_sym_SEMI,
      anon_sym_,
  [17856] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(893), 1,
      anon_sym_LBRACK,
    ACTIONS(1317), 1,
      anon_sym_LBRACE,
    STATE(626), 1,
      sym_type_parameters,
  [17869] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1187), 1,
      anon_sym_LF,
    ACTIONS(1319), 2,
      anon_sym_SEMI,
      anon_sym_,
  [17880] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(779), 1,
      anon_sym_RPAREN,
    ACTIONS(1321), 1,
      anon_sym_COMMA,
    STATE(426), 1,
      aux_sym_enum_constructor_repeat1,
  [17893] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(893), 1,
      anon_sym_LBRACK,
    ACTIONS(1323), 1,
      anon_sym_LBRACE,
    STATE(623), 1,
      sym_type_parameters,
  [17906] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1325), 1,
      anon_sym_LF,
    ACTIONS(1327), 2,
      anon_sym_SEMI,
      anon_sym_,
  [17917] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1329), 1,
      anon_sym_LF,
    ACTIONS(1331), 2,
      anon_sym_SEMI,
      anon_sym_,
  [17928] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(609), 1,
      anon_sym_LBRACE,
    ACTIONS(1333), 1,
      anon_sym_EQ,
    STATE(553), 1,
      sym_block_expression,
  [17941] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(230), 1,
      anon_sym_RPAREN,
    ACTIONS(1335), 1,
      anon_sym_COMMA,
    STATE(440), 1,
      aux_sym_apply_expression_repeat1,
  [17954] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1337), 1,
      anon_sym_RBRACE,
    ACTIONS(1339), 1,
      anon_sym_COMMA,
    STATE(475), 1,
      aux_sym_struct_field_expression_repeat1,
  [17967] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(777), 1,
      anon_sym_RPAREN,
    ACTIONS(1342), 1,
      anon_sym_COMMA,
    STATE(549), 1,
      aux_sym_enum_constructor_repeat1,
  [17980] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1093), 1,
      anon_sym_COLON,
    ACTIONS(1344), 1,
      anon_sym_EQ,
    STATE(622), 1,
      sym_type_annotation,
  [17993] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1346), 1,
      anon_sym_LF,
    ACTIONS(1348), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18004] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1350), 1,
      anon_sym_LF,
    ACTIONS(1352), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18015] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1354), 1,
      anon_sym_LF,
    ACTIONS(1356), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18026] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(783), 1,
      anon_sym_RBRACK,
    ACTIONS(1358), 1,
      anon_sym_COMMA,
    STATE(426), 1,
      aux_sym_enum_constructor_repeat1,
  [18039] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(371), 1,
      anon_sym_RPAREN,
    ACTIONS(1360), 1,
      anon_sym_COMMA,
    STATE(389), 1,
      aux_sym_constructor_pattern_repeat1,
  [18052] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1047), 1,
      anon_sym_LF,
    ACTIONS(1049), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18063] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(250), 1,
      anon_sym_RBRACK,
    ACTIONS(1362), 1,
      anon_sym_COMMA,
    STATE(440), 1,
      aux_sym_apply_expression_repeat1,
  [18076] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1164), 3,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_RBRACK,
  [18085] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(214), 1,
      anon_sym_RPAREN,
    ACTIONS(1364), 1,
      anon_sym_COMMA,
    STATE(440), 1,
      aux_sym_apply_expression_repeat1,
  [18098] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1366), 1,
      sym_lowercase_identifier,
    ACTIONS(1368), 1,
      anon_sym_RPAREN,
    STATE(564), 1,
      sym_parameter,
  [18111] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1370), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_DOT_DOT,
  [18120] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1136), 1,
      anon_sym_LF,
    ACTIONS(1138), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18131] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1372), 1,
      anon_sym_COMMA,
    ACTIONS(1374), 1,
      anon_sym_RBRACK,
    STATE(481), 1,
      aux_sym_enum_constructor_repeat1,
  [18144] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1376), 1,
      anon_sym_LF,
    ACTIONS(1378), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18155] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1380), 1,
      anon_sym_RPAREN,
    ACTIONS(1382), 1,
      anon_sym_COMMA,
    STATE(492), 1,
      aux_sym_parameters_repeat1,
  [18168] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1366), 1,
      sym_lowercase_identifier,
    ACTIONS(1385), 1,
      anon_sym_RPAREN,
    STATE(588), 1,
      sym_parameter,
  [18181] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(809), 1,
      anon_sym_RPAREN,
    ACTIONS(1387), 1,
      anon_sym_COMMA,
    STATE(426), 1,
      aux_sym_enum_constructor_repeat1,
  [18194] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1389), 3,
      anon_sym_LBRACE,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [18203] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(244), 1,
      anon_sym_RBRACK,
    ACTIONS(1391), 1,
      anon_sym_COMMA,
    STATE(440), 1,
      aux_sym_apply_expression_repeat1,
  [18216] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1053), 1,
      anon_sym_LF,
    ACTIONS(1055), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18227] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1393), 1,
      anon_sym_RBRACK,
    ACTIONS(1395), 1,
      sym_identifier,
    STATE(570), 1,
      sym_type_identifier,
  [18240] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(228), 1,
      anon_sym_RPAREN,
    ACTIONS(1397), 1,
      anon_sym_COMMA,
    STATE(440), 1,
      aux_sym_apply_expression_repeat1,
  [18253] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1399), 1,
      anon_sym_LF,
    ACTIONS(1401), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18264] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1403), 1,
      anon_sym_COMMA,
    ACTIONS(1405), 1,
      anon_sym_RBRACK,
    STATE(457), 1,
      aux_sym_enum_constructor_repeat1,
  [18277] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(795), 1,
      anon_sym_RPAREN,
    ACTIONS(1407), 1,
      anon_sym_COMMA,
    STATE(426), 1,
      aux_sym_enum_constructor_repeat1,
  [18290] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1083), 1,
      anon_sym_LF,
    ACTIONS(1409), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18301] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1085), 1,
      anon_sym_LF,
    ACTIONS(1411), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18312] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1413), 1,
      anon_sym_LF,
    ACTIONS(1415), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18323] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1417), 1,
      anon_sym_RPAREN,
    ACTIONS(1419), 1,
      anon_sym_COMMA,
    STATE(460), 1,
      aux_sym_enum_constructor_repeat1,
  [18336] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1421), 1,
      anon_sym_LF,
    ACTIONS(1423), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18347] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1425), 1,
      anon_sym_LF,
    ACTIONS(1427), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18358] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1429), 1,
      anon_sym_LF,
    ACTIONS(1431), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18369] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1433), 1,
      anon_sym_COMMA,
    ACTIONS(1436), 1,
      anon_sym_RBRACK,
    STATE(510), 1,
      aux_sym_type_parameters_repeat1,
  [18382] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1395), 1,
      sym_identifier,
    ACTIONS(1438), 1,
      anon_sym_RBRACK,
    STATE(570), 1,
      sym_type_identifier,
  [18395] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(609), 1,
      anon_sym_LBRACE,
    ACTIONS(891), 1,
      anon_sym_EQ,
    STATE(562), 1,
      sym_block_expression,
  [18408] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1200), 1,
      anon_sym_LF,
    ACTIONS(1440), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18419] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(893), 1,
      anon_sym_LBRACK,
    ACTIONS(1442), 1,
      anon_sym_LBRACE,
    STATE(643), 1,
      sym_type_parameters,
  [18432] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1444), 1,
      anon_sym_LF,
    ACTIONS(1446), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18443] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1118), 1,
      anon_sym_LF,
    ACTIONS(1448), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18454] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1450), 3,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_RBRACK,
  [18463] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1452), 1,
      anon_sym_LF,
    ACTIONS(1454), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18474] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(893), 1,
      anon_sym_LBRACK,
    ACTIONS(1456), 1,
      anon_sym_LBRACE,
    STATE(642), 1,
      sym_type_parameters,
  [18487] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(609), 1,
      anon_sym_LBRACE,
    ACTIONS(1075), 1,
      anon_sym_EQ,
    STATE(479), 1,
      sym_block_expression,
  [18500] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1093), 1,
      anon_sym_COLON,
    ACTIONS(1458), 1,
      anon_sym_EQ,
    STATE(641), 1,
      sym_type_annotation,
  [18513] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1460), 1,
      anon_sym_COLON,
    ACTIONS(1462), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [18524] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1464), 1,
      anon_sym_LF,
    ACTIONS(1466), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18535] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1093), 1,
      anon_sym_COLON,
    ACTIONS(1468), 1,
      anon_sym_EQ,
    STATE(634), 1,
      sym_type_annotation,
  [18548] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1470), 1,
      anon_sym_RPAREN,
    ACTIONS(1472), 1,
      anon_sym_COMMA,
    STATE(494), 1,
      aux_sym_enum_constructor_repeat1,
  [18561] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1474), 1,
      anon_sym_RPAREN,
    ACTIONS(1476), 1,
      anon_sym_COMMA,
    STATE(492), 1,
      aux_sym_parameters_repeat1,
  [18574] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1366), 1,
      sym_lowercase_identifier,
    ACTIONS(1474), 1,
      anon_sym_RPAREN,
    STATE(588), 1,
      sym_parameter,
  [18587] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1478), 3,
      anon_sym_LBRACE,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [18596] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1480), 1,
      anon_sym_COMMA,
    ACTIONS(1482), 1,
      anon_sym_RBRACK,
    STATE(510), 1,
      aux_sym_type_parameters_repeat1,
  [18609] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1484), 1,
      anon_sym_LF,
    ACTIONS(1486), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18620] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1395), 1,
      sym_identifier,
    ACTIONS(1482), 1,
      anon_sym_RBRACK,
    STATE(570), 1,
      sym_type_identifier,
  [18633] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1488), 1,
      anon_sym_LF,
    ACTIONS(1490), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18644] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1492), 1,
      anon_sym_LF,
    ACTIONS(1494), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18655] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(893), 1,
      anon_sym_LBRACK,
    ACTIONS(1496), 1,
      anon_sym_LPAREN,
    STATE(612), 1,
      sym_type_parameters,
  [18668] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1498), 1,
      anon_sym_LF,
    ACTIONS(1500), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18679] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1502), 1,
      anon_sym_LF,
    ACTIONS(1504), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18690] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1506), 1,
      anon_sym_COMMA,
    ACTIONS(1508), 1,
      anon_sym_RBRACK,
    STATE(529), 1,
      aux_sym_type_parameters_repeat1,
  [18703] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1510), 1,
      anon_sym_RPAREN,
    ACTIONS(1512), 1,
      anon_sym_COMMA,
    STATE(502), 1,
      aux_sym_enum_constructor_repeat1,
  [18716] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1514), 1,
      anon_sym_LF,
    ACTIONS(1516), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18727] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1110), 1,
      anon_sym_RBRACE,
    ACTIONS(1518), 1,
      anon_sym_COMMA,
    STATE(475), 1,
      aux_sym_struct_field_expression_repeat1,
  [18740] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1520), 1,
      anon_sym_LF,
    ACTIONS(1522), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18751] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1524), 1,
      anon_sym_LF,
    ACTIONS(1526), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18762] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1528), 1,
      anon_sym_LF,
    ACTIONS(1530), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18773] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1105), 1,
      anon_sym_LF,
    ACTIONS(1532), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18784] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(805), 1,
      anon_sym_RPAREN,
    ACTIONS(1534), 1,
      anon_sym_COMMA,
    STATE(469), 1,
      aux_sym_enum_constructor_repeat1,
  [18797] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1536), 1,
      anon_sym_COMMA,
    ACTIONS(1538), 1,
      anon_sym_RBRACK,
    STATE(510), 1,
      aux_sym_type_parameters_repeat1,
  [18810] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1229), 1,
      anon_sym_LF,
    ACTIONS(1540), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18821] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1395), 1,
      sym_identifier,
    ACTIONS(1538), 1,
      anon_sym_RBRACK,
    STATE(570), 1,
      sym_type_identifier,
  [18834] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(805), 1,
      anon_sym_RPAREN,
    ACTIONS(1534), 1,
      anon_sym_COMMA,
    STATE(426), 1,
      aux_sym_enum_constructor_repeat1,
  [18847] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1542), 3,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_EQ,
  [18856] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1045), 1,
      anon_sym_LF,
    ACTIONS(1544), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18867] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1546), 1,
      anon_sym_COMMA,
    ACTIONS(761), 2,
      anon_sym_RBRACE,
      anon_sym_RBRACK,
  [18878] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1548), 1,
      anon_sym_LF,
    ACTIONS(1550), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18889] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1116), 1,
      anon_sym_LF,
    ACTIONS(1552), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18900] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1554), 1,
      anon_sym_LF,
    ACTIONS(1556), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18911] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1148), 1,
      anon_sym_LF,
    ACTIONS(1558), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18922] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1103), 1,
      anon_sym_LF,
    ACTIONS(1560), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18933] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1562), 3,
      anon_sym_LBRACE,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [18942] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1564), 1,
      anon_sym_LF,
    ACTIONS(1566), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18953] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1568), 1,
      anon_sym_LF,
    ACTIONS(1570), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18964] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(609), 1,
      anon_sym_LBRACE,
    ACTIONS(972), 1,
      anon_sym_EQ,
    STATE(523), 1,
      sym_block_expression,
  [18977] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1572), 1,
      anon_sym_LF,
    ACTIONS(1574), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18988] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1126), 1,
      anon_sym_LF,
    ACTIONS(1128), 2,
      anon_sym_SEMI,
      anon_sym_,
  [18999] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1576), 1,
      anon_sym_RPAREN,
    ACTIONS(1578), 1,
      anon_sym_COMMA,
    STATE(526), 1,
      aux_sym_parameters_repeat1,
  [19012] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(889), 1,
      anon_sym_LPAREN,
    ACTIONS(1580), 1,
      sym_lowercase_identifier,
    STATE(424), 1,
      sym_parameters,
  [19025] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(711), 1,
      anon_sym_LF,
    ACTIONS(713), 2,
      anon_sym_SEMI,
      anon_sym_,
  [19036] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1144), 1,
      anon_sym_LF,
    ACTIONS(1582), 2,
      anon_sym_SEMI,
      anon_sym_,
  [19047] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1584), 1,
      anon_sym_LF,
    ACTIONS(1586), 2,
      anon_sym_SEMI,
      anon_sym_,
  [19058] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1152), 1,
      anon_sym_LF,
    ACTIONS(1588), 2,
      anon_sym_SEMI,
      anon_sym_,
  [19069] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1436), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [19077] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1590), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [19085] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1592), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [19093] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(889), 1,
      anon_sym_LPAREN,
    STATE(410), 1,
      sym_parameters,
  [19103] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1594), 1,
      aux_sym_char_literal_token1,
    ACTIONS(1596), 1,
      sym_escape_seqence,
  [19113] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1598), 1,
      anon_sym_DQUOTE,
    STATE(523), 1,
      sym_string_literal,
  [19123] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1444), 2,
      anon_sym_LBRACE,
      anon_sym_EQ,
  [19131] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    STATE(601), 1,
      sym_string_literal,
  [19141] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1395), 1,
      sym_identifier,
    STATE(537), 1,
      sym_type_identifier,
  [19151] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1395), 1,
      sym_identifier,
    STATE(570), 1,
      sym_type_identifier,
  [19161] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1598), 1,
      anon_sym_DQUOTE,
    STATE(491), 1,
      sym_string_literal,
  [19171] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(889), 1,
      anon_sym_LPAREN,
    STATE(424), 1,
      sym_parameters,
  [19181] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1337), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [19189] = 3,
    ACTIONS(180), 1,
      sym_comment,
    ACTIONS(1600), 1,
      aux_sym_char_literal_token1,
    ACTIONS(1602), 1,
      sym_escape_seqence,
  [19199] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    STATE(596), 1,
      sym_string_literal,
  [19209] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1598), 1,
      anon_sym_DQUOTE,
    STATE(553), 1,
      sym_string_literal,
  [19219] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1395), 1,
      sym_identifier,
    STATE(443), 1,
      sym_type_identifier,
  [19229] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(613), 1,
      anon_sym_LBRACE,
    STATE(127), 1,
      sym_block_expression,
  [19239] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1380), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [19247] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1189), 2,
      anon_sym_RBRACE,
      sym_uppercase_identifier,
  [19255] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    STATE(575), 1,
      sym_string_literal,
  [19265] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(609), 1,
      anon_sym_LBRACE,
    STATE(463), 1,
      sym_block_expression,
  [19275] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(769), 2,
      anon_sym_RBRACE,
      anon_sym_RBRACK,
  [19283] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1604), 1,
      anon_sym_RBRACE,
    ACTIONS(1606), 1,
      anon_sym_COMMA,
  [19293] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(609), 1,
      anon_sym_LBRACE,
    STATE(203), 1,
      sym_block_expression,
  [19303] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1608), 1,
      sym_lowercase_identifier,
    ACTIONS(1610), 1,
      sym_mutability,
  [19313] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1598), 1,
      anon_sym_DQUOTE,
    STATE(465), 1,
      sym_string_literal,
  [19323] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1612), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [19331] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(889), 1,
      anon_sym_LPAREN,
    STATE(432), 1,
      sym_parameters,
  [19341] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1366), 1,
      sym_lowercase_identifier,
    STATE(588), 1,
      sym_parameter,
  [19351] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    STATE(585), 1,
      sym_string_literal,
  [19361] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1598), 1,
      anon_sym_DQUOTE,
    STATE(479), 1,
      sym_string_literal,
  [19371] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(294), 1,
      anon_sym_DQUOTE,
    STATE(580), 1,
      sym_string_literal,
  [19381] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1614), 1,
      anon_sym_RBRACE,
  [19388] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1616), 1,
      sym_lowercase_identifier,
  [19395] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1618), 1,
      sym_colon_colon_uppercase_identifier,
  [19402] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(308), 1,
      anon_sym_RBRACK,
  [19409] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(993), 1,
      anon_sym_RBRACE,
  [19416] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1620), 1,
      anon_sym_SQUOTE,
  [19423] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1622), 1,
      anon_sym_RBRACE,
  [19430] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1624), 1,
      anon_sym_LBRACE,
  [19437] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1626), 1,
      anon_sym_SQUOTE,
  [19444] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1628), 1,
      anon_sym_LPAREN,
  [19451] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1630), 1,
      anon_sym_COLON_EQ,
  [19458] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1632), 1,
      sym_lowercase_identifier,
  [19465] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1634), 1,
      anon_sym_COLON,
  [19472] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1636), 1,
      anon_sym_COLON,
  [19479] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1606), 1,
      anon_sym_COMMA,
  [19486] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1638), 1,
      sym_dot_identifier,
  [19493] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1640), 1,
      anon_sym_RBRACE,
  [19500] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1642), 1,
      anon_sym_RBRACK,
  [19507] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1644), 1,
      sym_lowercase_identifier,
  [19514] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1458), 1,
      anon_sym_EQ,
  [19521] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1456), 1,
      anon_sym_LBRACE,
  [19528] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1646), 1,
      anon_sym_EQ,
  [19535] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1648), 1,
      sym_lowercase_identifier,
  [19542] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1442), 1,
      anon_sym_LBRACE,
  [19549] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(389), 1,
      anon_sym_RBRACK,
  [19556] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1650), 1,
      anon_sym_RBRACE,
  [19563] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1652), 1,
      anon_sym_COLON,
  [19570] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1654), 1,
      anon_sym_RPAREN,
  [19577] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1656), 1,
      sym_identifier,
  [19584] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1658), 1,
      sym_dot_identifier,
  [19591] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1660), 1,
      sym_identifier,
  [19598] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1662), 1,
      anon_sym_EQ,
  [19605] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1664), 1,
      anon_sym_RPAREN,
  [19612] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1666), 1,
      sym_identifier,
  [19619] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1668), 1,
      sym_identifier,
  [19626] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1670), 1,
      anon_sym_LBRACE,
  [19633] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1672), 1,
      sym_colon_colon_lowercase_identifier,
  [19640] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1674), 1,
      sym_dot_identifier,
  [19647] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1676), 1,
      anon_sym_EQ,
  [19654] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1678), 1,
      anon_sym_LBRACE,
  [19661] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1680), 1,
      anon_sym_LBRACE,
  [19668] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1682), 1,
      anon_sym_RBRACE,
  [19675] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1684), 1,
      sym_dot_identifier,
  [19682] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1686), 1,
      anon_sym_RBRACE,
  [19689] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1688), 1,
      anon_sym_readonly,
  [19696] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1690), 1,
      anon_sym_RPAREN,
  [19703] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(347), 1,
      anon_sym_RBRACK,
  [19710] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(997), 1,
      anon_sym_RBRACE,
  [19717] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1692), 1,
      sym_colon_colon_uppercase_identifier,
  [19724] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1694), 1,
      sym_identifier,
  [19731] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1696), 1,
      anon_sym_EQ,
  [19738] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1698), 1,
      sym_lowercase_identifier,
  [19745] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1700), 1,
      anon_sym_RPAREN,
  [19752] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1702), 1,
      ts_builtin_sym_end,
  [19759] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1704), 1,
      sym_identifier,
  [19766] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1706), 1,
      sym_lowercase_identifier,
  [19773] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1708), 1,
      sym_identifier,
  [19780] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(1710), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(11)] = 0,
  [SMALL_STATE(12)] = 105,
  [SMALL_STATE(13)] = 204,
  [SMALL_STATE(14)] = 303,
  [SMALL_STATE(15)] = 402,
  [SMALL_STATE(16)] = 501,
  [SMALL_STATE(17)] = 600,
  [SMALL_STATE(18)] = 699,
  [SMALL_STATE(19)] = 798,
  [SMALL_STATE(20)] = 897,
  [SMALL_STATE(21)] = 996,
  [SMALL_STATE(22)] = 1095,
  [SMALL_STATE(23)] = 1194,
  [SMALL_STATE(24)] = 1293,
  [SMALL_STATE(25)] = 1392,
  [SMALL_STATE(26)] = 1491,
  [SMALL_STATE(27)] = 1590,
  [SMALL_STATE(28)] = 1689,
  [SMALL_STATE(29)] = 1788,
  [SMALL_STATE(30)] = 1887,
  [SMALL_STATE(31)] = 1986,
  [SMALL_STATE(32)] = 2085,
  [SMALL_STATE(33)] = 2184,
  [SMALL_STATE(34)] = 2283,
  [SMALL_STATE(35)] = 2382,
  [SMALL_STATE(36)] = 2481,
  [SMALL_STATE(37)] = 2577,
  [SMALL_STATE(38)] = 2673,
  [SMALL_STATE(39)] = 2769,
  [SMALL_STATE(40)] = 2865,
  [SMALL_STATE(41)] = 2961,
  [SMALL_STATE(42)] = 3057,
  [SMALL_STATE(43)] = 3153,
  [SMALL_STATE(44)] = 3249,
  [SMALL_STATE(45)] = 3345,
  [SMALL_STATE(46)] = 3441,
  [SMALL_STATE(47)] = 3537,
  [SMALL_STATE(48)] = 3633,
  [SMALL_STATE(49)] = 3729,
  [SMALL_STATE(50)] = 3825,
  [SMALL_STATE(51)] = 3921,
  [SMALL_STATE(52)] = 4017,
  [SMALL_STATE(53)] = 4113,
  [SMALL_STATE(54)] = 4209,
  [SMALL_STATE(55)] = 4305,
  [SMALL_STATE(56)] = 4401,
  [SMALL_STATE(57)] = 4497,
  [SMALL_STATE(58)] = 4593,
  [SMALL_STATE(59)] = 4689,
  [SMALL_STATE(60)] = 4785,
  [SMALL_STATE(61)] = 4881,
  [SMALL_STATE(62)] = 4977,
  [SMALL_STATE(63)] = 5073,
  [SMALL_STATE(64)] = 5169,
  [SMALL_STATE(65)] = 5265,
  [SMALL_STATE(66)] = 5361,
  [SMALL_STATE(67)] = 5457,
  [SMALL_STATE(68)] = 5553,
  [SMALL_STATE(69)] = 5649,
  [SMALL_STATE(70)] = 5745,
  [SMALL_STATE(71)] = 5841,
  [SMALL_STATE(72)] = 5937,
  [SMALL_STATE(73)] = 5980,
  [SMALL_STATE(74)] = 6023,
  [SMALL_STATE(75)] = 6065,
  [SMALL_STATE(76)] = 6107,
  [SMALL_STATE(77)] = 6149,
  [SMALL_STATE(78)] = 6191,
  [SMALL_STATE(79)] = 6233,
  [SMALL_STATE(80)] = 6312,
  [SMALL_STATE(81)] = 6388,
  [SMALL_STATE(82)] = 6464,
  [SMALL_STATE(83)] = 6540,
  [SMALL_STATE(84)] = 6616,
  [SMALL_STATE(85)] = 6692,
  [SMALL_STATE(86)] = 6768,
  [SMALL_STATE(87)] = 6844,
  [SMALL_STATE(88)] = 6887,
  [SMALL_STATE(89)] = 6927,
  [SMALL_STATE(90)] = 6965,
  [SMALL_STATE(91)] = 7035,
  [SMALL_STATE(92)] = 7105,
  [SMALL_STATE(93)] = 7175,
  [SMALL_STATE(94)] = 7213,
  [SMALL_STATE(95)] = 7257,
  [SMALL_STATE(96)] = 7327,
  [SMALL_STATE(97)] = 7397,
  [SMALL_STATE(98)] = 7467,
  [SMALL_STATE(99)] = 7537,
  [SMALL_STATE(100)] = 7585,
  [SMALL_STATE(101)] = 7622,
  [SMALL_STATE(102)] = 7659,
  [SMALL_STATE(103)] = 7726,
  [SMALL_STATE(104)] = 7763,
  [SMALL_STATE(105)] = 7800,
  [SMALL_STATE(106)] = 7837,
  [SMALL_STATE(107)] = 7874,
  [SMALL_STATE(108)] = 7911,
  [SMALL_STATE(109)] = 7978,
  [SMALL_STATE(110)] = 8015,
  [SMALL_STATE(111)] = 8082,
  [SMALL_STATE(112)] = 8119,
  [SMALL_STATE(113)] = 8156,
  [SMALL_STATE(114)] = 8193,
  [SMALL_STATE(115)] = 8230,
  [SMALL_STATE(116)] = 8267,
  [SMALL_STATE(117)] = 8306,
  [SMALL_STATE(118)] = 8343,
  [SMALL_STATE(119)] = 8382,
  [SMALL_STATE(120)] = 8419,
  [SMALL_STATE(121)] = 8456,
  [SMALL_STATE(122)] = 8493,
  [SMALL_STATE(123)] = 8530,
  [SMALL_STATE(124)] = 8567,
  [SMALL_STATE(125)] = 8604,
  [SMALL_STATE(126)] = 8641,
  [SMALL_STATE(127)] = 8678,
  [SMALL_STATE(128)] = 8715,
  [SMALL_STATE(129)] = 8752,
  [SMALL_STATE(130)] = 8789,
  [SMALL_STATE(131)] = 8826,
  [SMALL_STATE(132)] = 8863,
  [SMALL_STATE(133)] = 8900,
  [SMALL_STATE(134)] = 8967,
  [SMALL_STATE(135)] = 9004,
  [SMALL_STATE(136)] = 9057,
  [SMALL_STATE(137)] = 9108,
  [SMALL_STATE(138)] = 9155,
  [SMALL_STATE(139)] = 9222,
  [SMALL_STATE(140)] = 9261,
  [SMALL_STATE(141)] = 9300,
  [SMALL_STATE(142)] = 9343,
  [SMALL_STATE(143)] = 9380,
  [SMALL_STATE(144)] = 9417,
  [SMALL_STATE(145)] = 9454,
  [SMALL_STATE(146)] = 9491,
  [SMALL_STATE(147)] = 9528,
  [SMALL_STATE(148)] = 9565,
  [SMALL_STATE(149)] = 9602,
  [SMALL_STATE(150)] = 9639,
  [SMALL_STATE(151)] = 9706,
  [SMALL_STATE(152)] = 9743,
  [SMALL_STATE(153)] = 9780,
  [SMALL_STATE(154)] = 9817,
  [SMALL_STATE(155)] = 9884,
  [SMALL_STATE(156)] = 9924,
  [SMALL_STATE(157)] = 9962,
  [SMALL_STATE(158)] = 10000,
  [SMALL_STATE(159)] = 10037,
  [SMALL_STATE(160)] = 10074,
  [SMALL_STATE(161)] = 10109,
  [SMALL_STATE(162)] = 10154,
  [SMALL_STATE(163)] = 10189,
  [SMALL_STATE(164)] = 10224,
  [SMALL_STATE(165)] = 10258,
  [SMALL_STATE(166)] = 10292,
  [SMALL_STATE(167)] = 10326,
  [SMALL_STATE(168)] = 10360,
  [SMALL_STATE(169)] = 10394,
  [SMALL_STATE(170)] = 10428,
  [SMALL_STATE(171)] = 10462,
  [SMALL_STATE(172)] = 10496,
  [SMALL_STATE(173)] = 10540,
  [SMALL_STATE(174)] = 10574,
  [SMALL_STATE(175)] = 10608,
  [SMALL_STATE(176)] = 10644,
  [SMALL_STATE(177)] = 10686,
  [SMALL_STATE(178)] = 10720,
  [SMALL_STATE(179)] = 10760,
  [SMALL_STATE(180)] = 10796,
  [SMALL_STATE(181)] = 10832,
  [SMALL_STATE(182)] = 10880,
  [SMALL_STATE(183)] = 10918,
  [SMALL_STATE(184)] = 10952,
  [SMALL_STATE(185)] = 10986,
  [SMALL_STATE(186)] = 11020,
  [SMALL_STATE(187)] = 11054,
  [SMALL_STATE(188)] = 11088,
  [SMALL_STATE(189)] = 11122,
  [SMALL_STATE(190)] = 11156,
  [SMALL_STATE(191)] = 11190,
  [SMALL_STATE(192)] = 11224,
  [SMALL_STATE(193)] = 11258,
  [SMALL_STATE(194)] = 11294,
  [SMALL_STATE(195)] = 11328,
  [SMALL_STATE(196)] = 11362,
  [SMALL_STATE(197)] = 11396,
  [SMALL_STATE(198)] = 11430,
  [SMALL_STATE(199)] = 11464,
  [SMALL_STATE(200)] = 11498,
  [SMALL_STATE(201)] = 11532,
  [SMALL_STATE(202)] = 11580,
  [SMALL_STATE(203)] = 11614,
  [SMALL_STATE(204)] = 11648,
  [SMALL_STATE(205)] = 11682,
  [SMALL_STATE(206)] = 11716,
  [SMALL_STATE(207)] = 11750,
  [SMALL_STATE(208)] = 11784,
  [SMALL_STATE(209)] = 11818,
  [SMALL_STATE(210)] = 11852,
  [SMALL_STATE(211)] = 11900,
  [SMALL_STATE(212)] = 11934,
  [SMALL_STATE(213)] = 11968,
  [SMALL_STATE(214)] = 12002,
  [SMALL_STATE(215)] = 12036,
  [SMALL_STATE(216)] = 12070,
  [SMALL_STATE(217)] = 12104,
  [SMALL_STATE(218)] = 12138,
  [SMALL_STATE(219)] = 12172,
  [SMALL_STATE(220)] = 12206,
  [SMALL_STATE(221)] = 12240,
  [SMALL_STATE(222)] = 12274,
  [SMALL_STATE(223)] = 12319,
  [SMALL_STATE(224)] = 12364,
  [SMALL_STATE(225)] = 12419,
  [SMALL_STATE(226)] = 12474,
  [SMALL_STATE(227)] = 12518,
  [SMALL_STATE(228)] = 12562,
  [SMALL_STATE(229)] = 12606,
  [SMALL_STATE(230)] = 12654,
  [SMALL_STATE(231)] = 12706,
  [SMALL_STATE(232)] = 12758,
  [SMALL_STATE(233)] = 12802,
  [SMALL_STATE(234)] = 12846,
  [SMALL_STATE(235)] = 12890,
  [SMALL_STATE(236)] = 12942,
  [SMALL_STATE(237)] = 12994,
  [SMALL_STATE(238)] = 13038,
  [SMALL_STATE(239)] = 13082,
  [SMALL_STATE(240)] = 13134,
  [SMALL_STATE(241)] = 13178,
  [SMALL_STATE(242)] = 13230,
  [SMALL_STATE(243)] = 13274,
  [SMALL_STATE(244)] = 13318,
  [SMALL_STATE(245)] = 13362,
  [SMALL_STATE(246)] = 13411,
  [SMALL_STATE(247)] = 13460,
  [SMALL_STATE(248)] = 13507,
  [SMALL_STATE(249)] = 13553,
  [SMALL_STATE(250)] = 13599,
  [SMALL_STATE(251)] = 13645,
  [SMALL_STATE(252)] = 13688,
  [SMALL_STATE(253)] = 13739,
  [SMALL_STATE(254)] = 13790,
  [SMALL_STATE(255)] = 13816,
  [SMALL_STATE(256)] = 13839,
  [SMALL_STATE(257)] = 13862,
  [SMALL_STATE(258)] = 13893,
  [SMALL_STATE(259)] = 13924,
  [SMALL_STATE(260)] = 13955,
  [SMALL_STATE(261)] = 13986,
  [SMALL_STATE(262)] = 14017,
  [SMALL_STATE(263)] = 14048,
  [SMALL_STATE(264)] = 14069,
  [SMALL_STATE(265)] = 14100,
  [SMALL_STATE(266)] = 14131,
  [SMALL_STATE(267)] = 14162,
  [SMALL_STATE(268)] = 14193,
  [SMALL_STATE(269)] = 14224,
  [SMALL_STATE(270)] = 14255,
  [SMALL_STATE(271)] = 14286,
  [SMALL_STATE(272)] = 14317,
  [SMALL_STATE(273)] = 14348,
  [SMALL_STATE(274)] = 14379,
  [SMALL_STATE(275)] = 14410,
  [SMALL_STATE(276)] = 14438,
  [SMALL_STATE(277)] = 14456,
  [SMALL_STATE(278)] = 14484,
  [SMALL_STATE(279)] = 14512,
  [SMALL_STATE(280)] = 14540,
  [SMALL_STATE(281)] = 14558,
  [SMALL_STATE(282)] = 14586,
  [SMALL_STATE(283)] = 14614,
  [SMALL_STATE(284)] = 14632,
  [SMALL_STATE(285)] = 14660,
  [SMALL_STATE(286)] = 14678,
  [SMALL_STATE(287)] = 14696,
  [SMALL_STATE(288)] = 14724,
  [SMALL_STATE(289)] = 14742,
  [SMALL_STATE(290)] = 14762,
  [SMALL_STATE(291)] = 14780,
  [SMALL_STATE(292)] = 14808,
  [SMALL_STATE(293)] = 14826,
  [SMALL_STATE(294)] = 14854,
  [SMALL_STATE(295)] = 14872,
  [SMALL_STATE(296)] = 14890,
  [SMALL_STATE(297)] = 14918,
  [SMALL_STATE(298)] = 14936,
  [SMALL_STATE(299)] = 14964,
  [SMALL_STATE(300)] = 14982,
  [SMALL_STATE(301)] = 15010,
  [SMALL_STATE(302)] = 15038,
  [SMALL_STATE(303)] = 15056,
  [SMALL_STATE(304)] = 15084,
  [SMALL_STATE(305)] = 15112,
  [SMALL_STATE(306)] = 15140,
  [SMALL_STATE(307)] = 15168,
  [SMALL_STATE(308)] = 15186,
  [SMALL_STATE(309)] = 15214,
  [SMALL_STATE(310)] = 15242,
  [SMALL_STATE(311)] = 15270,
  [SMALL_STATE(312)] = 15288,
  [SMALL_STATE(313)] = 15319,
  [SMALL_STATE(314)] = 15334,
  [SMALL_STATE(315)] = 15349,
  [SMALL_STATE(316)] = 15380,
  [SMALL_STATE(317)] = 15395,
  [SMALL_STATE(318)] = 15423,
  [SMALL_STATE(319)] = 15451,
  [SMALL_STATE(320)] = 15479,
  [SMALL_STATE(321)] = 15507,
  [SMALL_STATE(322)] = 15535,
  [SMALL_STATE(323)] = 15563,
  [SMALL_STATE(324)] = 15591,
  [SMALL_STATE(325)] = 15619,
  [SMALL_STATE(326)] = 15647,
  [SMALL_STATE(327)] = 15675,
  [SMALL_STATE(328)] = 15695,
  [SMALL_STATE(329)] = 15723,
  [SMALL_STATE(330)] = 15751,
  [SMALL_STATE(331)] = 15774,
  [SMALL_STATE(332)] = 15795,
  [SMALL_STATE(333)] = 15816,
  [SMALL_STATE(334)] = 15839,
  [SMALL_STATE(335)] = 15864,
  [SMALL_STATE(336)] = 15885,
  [SMALL_STATE(337)] = 15910,
  [SMALL_STATE(338)] = 15933,
  [SMALL_STATE(339)] = 15954,
  [SMALL_STATE(340)] = 15971,
  [SMALL_STATE(341)] = 15994,
  [SMALL_STATE(342)] = 16015,
  [SMALL_STATE(343)] = 16038,
  [SMALL_STATE(344)] = 16063,
  [SMALL_STATE(345)] = 16084,
  [SMALL_STATE(346)] = 16105,
  [SMALL_STATE(347)] = 16126,
  [SMALL_STATE(348)] = 16149,
  [SMALL_STATE(349)] = 16170,
  [SMALL_STATE(350)] = 16184,
  [SMALL_STATE(351)] = 16202,
  [SMALL_STATE(352)] = 16218,
  [SMALL_STATE(353)] = 16238,
  [SMALL_STATE(354)] = 16252,
  [SMALL_STATE(355)] = 16266,
  [SMALL_STATE(356)] = 16280,
  [SMALL_STATE(357)] = 16291,
  [SMALL_STATE(358)] = 16310,
  [SMALL_STATE(359)] = 16327,
  [SMALL_STATE(360)] = 16338,
  [SMALL_STATE(361)] = 16355,
  [SMALL_STATE(362)] = 16374,
  [SMALL_STATE(363)] = 16391,
  [SMALL_STATE(364)] = 16402,
  [SMALL_STATE(365)] = 16419,
  [SMALL_STATE(366)] = 16430,
  [SMALL_STATE(367)] = 16447,
  [SMALL_STATE(368)] = 16464,
  [SMALL_STATE(369)] = 16483,
  [SMALL_STATE(370)] = 16502,
  [SMALL_STATE(371)] = 16517,
  [SMALL_STATE(372)] = 16536,
  [SMALL_STATE(373)] = 16547,
  [SMALL_STATE(374)] = 16558,
  [SMALL_STATE(375)] = 16569,
  [SMALL_STATE(376)] = 16588,
  [SMALL_STATE(377)] = 16605,
  [SMALL_STATE(378)] = 16624,
  [SMALL_STATE(379)] = 16641,
  [SMALL_STATE(380)] = 16660,
  [SMALL_STATE(381)] = 16671,
  [SMALL_STATE(382)] = 16690,
  [SMALL_STATE(383)] = 16709,
  [SMALL_STATE(384)] = 16728,
  [SMALL_STATE(385)] = 16747,
  [SMALL_STATE(386)] = 16758,
  [SMALL_STATE(387)] = 16775,
  [SMALL_STATE(388)] = 16794,
  [SMALL_STATE(389)] = 16805,
  [SMALL_STATE(390)] = 16820,
  [SMALL_STATE(391)] = 16837,
  [SMALL_STATE(392)] = 16856,
  [SMALL_STATE(393)] = 16867,
  [SMALL_STATE(394)] = 16878,
  [SMALL_STATE(395)] = 16895,
  [SMALL_STATE(396)] = 16912,
  [SMALL_STATE(397)] = 16929,
  [SMALL_STATE(398)] = 16948,
  [SMALL_STATE(399)] = 16965,
  [SMALL_STATE(400)] = 16982,
  [SMALL_STATE(401)] = 16993,
  [SMALL_STATE(402)] = 17012,
  [SMALL_STATE(403)] = 17023,
  [SMALL_STATE(404)] = 17036,
  [SMALL_STATE(405)] = 17047,
  [SMALL_STATE(406)] = 17059,
  [SMALL_STATE(407)] = 17073,
  [SMALL_STATE(408)] = 17087,
  [SMALL_STATE(409)] = 17103,
  [SMALL_STATE(410)] = 17117,
  [SMALL_STATE(411)] = 17133,
  [SMALL_STATE(412)] = 17147,
  [SMALL_STATE(413)] = 17161,
  [SMALL_STATE(414)] = 17177,
  [SMALL_STATE(415)] = 17193,
  [SMALL_STATE(416)] = 17207,
  [SMALL_STATE(417)] = 17221,
  [SMALL_STATE(418)] = 17235,
  [SMALL_STATE(419)] = 17245,
  [SMALL_STATE(420)] = 17261,
  [SMALL_STATE(421)] = 17277,
  [SMALL_STATE(422)] = 17291,
  [SMALL_STATE(423)] = 17301,
  [SMALL_STATE(424)] = 17313,
  [SMALL_STATE(425)] = 17329,
  [SMALL_STATE(426)] = 17345,
  [SMALL_STATE(427)] = 17359,
  [SMALL_STATE(428)] = 17371,
  [SMALL_STATE(429)] = 17385,
  [SMALL_STATE(430)] = 17399,
  [SMALL_STATE(431)] = 17415,
  [SMALL_STATE(432)] = 17427,
  [SMALL_STATE(433)] = 17443,
  [SMALL_STATE(434)] = 17455,
  [SMALL_STATE(435)] = 17467,
  [SMALL_STATE(436)] = 17483,
  [SMALL_STATE(437)] = 17497,
  [SMALL_STATE(438)] = 17507,
  [SMALL_STATE(439)] = 17521,
  [SMALL_STATE(440)] = 17535,
  [SMALL_STATE(441)] = 17549,
  [SMALL_STATE(442)] = 17563,
  [SMALL_STATE(443)] = 17574,
  [SMALL_STATE(444)] = 17587,
  [SMALL_STATE(445)] = 17596,
  [SMALL_STATE(446)] = 17609,
  [SMALL_STATE(447)] = 17622,
  [SMALL_STATE(448)] = 17633,
  [SMALL_STATE(449)] = 17646,
  [SMALL_STATE(450)] = 17657,
  [SMALL_STATE(451)] = 17670,
  [SMALL_STATE(452)] = 17683,
  [SMALL_STATE(453)] = 17694,
  [SMALL_STATE(454)] = 17703,
  [SMALL_STATE(455)] = 17714,
  [SMALL_STATE(456)] = 17727,
  [SMALL_STATE(457)] = 17740,
  [SMALL_STATE(458)] = 17753,
  [SMALL_STATE(459)] = 17766,
  [SMALL_STATE(460)] = 17775,
  [SMALL_STATE(461)] = 17788,
  [SMALL_STATE(462)] = 17801,
  [SMALL_STATE(463)] = 17812,
  [SMALL_STATE(464)] = 17823,
  [SMALL_STATE(465)] = 17834,
  [SMALL_STATE(466)] = 17845,
  [SMALL_STATE(467)] = 17856,
  [SMALL_STATE(468)] = 17869,
  [SMALL_STATE(469)] = 17880,
  [SMALL_STATE(470)] = 17893,
  [SMALL_STATE(471)] = 17906,
  [SMALL_STATE(472)] = 17917,
  [SMALL_STATE(473)] = 17928,
  [SMALL_STATE(474)] = 17941,
  [SMALL_STATE(475)] = 17954,
  [SMALL_STATE(476)] = 17967,
  [SMALL_STATE(477)] = 17980,
  [SMALL_STATE(478)] = 17993,
  [SMALL_STATE(479)] = 18004,
  [SMALL_STATE(480)] = 18015,
  [SMALL_STATE(481)] = 18026,
  [SMALL_STATE(482)] = 18039,
  [SMALL_STATE(483)] = 18052,
  [SMALL_STATE(484)] = 18063,
  [SMALL_STATE(485)] = 18076,
  [SMALL_STATE(486)] = 18085,
  [SMALL_STATE(487)] = 18098,
  [SMALL_STATE(488)] = 18111,
  [SMALL_STATE(489)] = 18120,
  [SMALL_STATE(490)] = 18131,
  [SMALL_STATE(491)] = 18144,
  [SMALL_STATE(492)] = 18155,
  [SMALL_STATE(493)] = 18168,
  [SMALL_STATE(494)] = 18181,
  [SMALL_STATE(495)] = 18194,
  [SMALL_STATE(496)] = 18203,
  [SMALL_STATE(497)] = 18216,
  [SMALL_STATE(498)] = 18227,
  [SMALL_STATE(499)] = 18240,
  [SMALL_STATE(500)] = 18253,
  [SMALL_STATE(501)] = 18264,
  [SMALL_STATE(502)] = 18277,
  [SMALL_STATE(503)] = 18290,
  [SMALL_STATE(504)] = 18301,
  [SMALL_STATE(505)] = 18312,
  [SMALL_STATE(506)] = 18323,
  [SMALL_STATE(507)] = 18336,
  [SMALL_STATE(508)] = 18347,
  [SMALL_STATE(509)] = 18358,
  [SMALL_STATE(510)] = 18369,
  [SMALL_STATE(511)] = 18382,
  [SMALL_STATE(512)] = 18395,
  [SMALL_STATE(513)] = 18408,
  [SMALL_STATE(514)] = 18419,
  [SMALL_STATE(515)] = 18432,
  [SMALL_STATE(516)] = 18443,
  [SMALL_STATE(517)] = 18454,
  [SMALL_STATE(518)] = 18463,
  [SMALL_STATE(519)] = 18474,
  [SMALL_STATE(520)] = 18487,
  [SMALL_STATE(521)] = 18500,
  [SMALL_STATE(522)] = 18513,
  [SMALL_STATE(523)] = 18524,
  [SMALL_STATE(524)] = 18535,
  [SMALL_STATE(525)] = 18548,
  [SMALL_STATE(526)] = 18561,
  [SMALL_STATE(527)] = 18574,
  [SMALL_STATE(528)] = 18587,
  [SMALL_STATE(529)] = 18596,
  [SMALL_STATE(530)] = 18609,
  [SMALL_STATE(531)] = 18620,
  [SMALL_STATE(532)] = 18633,
  [SMALL_STATE(533)] = 18644,
  [SMALL_STATE(534)] = 18655,
  [SMALL_STATE(535)] = 18668,
  [SMALL_STATE(536)] = 18679,
  [SMALL_STATE(537)] = 18690,
  [SMALL_STATE(538)] = 18703,
  [SMALL_STATE(539)] = 18716,
  [SMALL_STATE(540)] = 18727,
  [SMALL_STATE(541)] = 18740,
  [SMALL_STATE(542)] = 18751,
  [SMALL_STATE(543)] = 18762,
  [SMALL_STATE(544)] = 18773,
  [SMALL_STATE(545)] = 18784,
  [SMALL_STATE(546)] = 18797,
  [SMALL_STATE(547)] = 18810,
  [SMALL_STATE(548)] = 18821,
  [SMALL_STATE(549)] = 18834,
  [SMALL_STATE(550)] = 18847,
  [SMALL_STATE(551)] = 18856,
  [SMALL_STATE(552)] = 18867,
  [SMALL_STATE(553)] = 18878,
  [SMALL_STATE(554)] = 18889,
  [SMALL_STATE(555)] = 18900,
  [SMALL_STATE(556)] = 18911,
  [SMALL_STATE(557)] = 18922,
  [SMALL_STATE(558)] = 18933,
  [SMALL_STATE(559)] = 18942,
  [SMALL_STATE(560)] = 18953,
  [SMALL_STATE(561)] = 18964,
  [SMALL_STATE(562)] = 18977,
  [SMALL_STATE(563)] = 18988,
  [SMALL_STATE(564)] = 18999,
  [SMALL_STATE(565)] = 19012,
  [SMALL_STATE(566)] = 19025,
  [SMALL_STATE(567)] = 19036,
  [SMALL_STATE(568)] = 19047,
  [SMALL_STATE(569)] = 19058,
  [SMALL_STATE(570)] = 19069,
  [SMALL_STATE(571)] = 19077,
  [SMALL_STATE(572)] = 19085,
  [SMALL_STATE(573)] = 19093,
  [SMALL_STATE(574)] = 19103,
  [SMALL_STATE(575)] = 19113,
  [SMALL_STATE(576)] = 19123,
  [SMALL_STATE(577)] = 19131,
  [SMALL_STATE(578)] = 19141,
  [SMALL_STATE(579)] = 19151,
  [SMALL_STATE(580)] = 19161,
  [SMALL_STATE(581)] = 19171,
  [SMALL_STATE(582)] = 19181,
  [SMALL_STATE(583)] = 19189,
  [SMALL_STATE(584)] = 19199,
  [SMALL_STATE(585)] = 19209,
  [SMALL_STATE(586)] = 19219,
  [SMALL_STATE(587)] = 19229,
  [SMALL_STATE(588)] = 19239,
  [SMALL_STATE(589)] = 19247,
  [SMALL_STATE(590)] = 19255,
  [SMALL_STATE(591)] = 19265,
  [SMALL_STATE(592)] = 19275,
  [SMALL_STATE(593)] = 19283,
  [SMALL_STATE(594)] = 19293,
  [SMALL_STATE(595)] = 19303,
  [SMALL_STATE(596)] = 19313,
  [SMALL_STATE(597)] = 19323,
  [SMALL_STATE(598)] = 19331,
  [SMALL_STATE(599)] = 19341,
  [SMALL_STATE(600)] = 19351,
  [SMALL_STATE(601)] = 19361,
  [SMALL_STATE(602)] = 19371,
  [SMALL_STATE(603)] = 19381,
  [SMALL_STATE(604)] = 19388,
  [SMALL_STATE(605)] = 19395,
  [SMALL_STATE(606)] = 19402,
  [SMALL_STATE(607)] = 19409,
  [SMALL_STATE(608)] = 19416,
  [SMALL_STATE(609)] = 19423,
  [SMALL_STATE(610)] = 19430,
  [SMALL_STATE(611)] = 19437,
  [SMALL_STATE(612)] = 19444,
  [SMALL_STATE(613)] = 19451,
  [SMALL_STATE(614)] = 19458,
  [SMALL_STATE(615)] = 19465,
  [SMALL_STATE(616)] = 19472,
  [SMALL_STATE(617)] = 19479,
  [SMALL_STATE(618)] = 19486,
  [SMALL_STATE(619)] = 19493,
  [SMALL_STATE(620)] = 19500,
  [SMALL_STATE(621)] = 19507,
  [SMALL_STATE(622)] = 19514,
  [SMALL_STATE(623)] = 19521,
  [SMALL_STATE(624)] = 19528,
  [SMALL_STATE(625)] = 19535,
  [SMALL_STATE(626)] = 19542,
  [SMALL_STATE(627)] = 19549,
  [SMALL_STATE(628)] = 19556,
  [SMALL_STATE(629)] = 19563,
  [SMALL_STATE(630)] = 19570,
  [SMALL_STATE(631)] = 19577,
  [SMALL_STATE(632)] = 19584,
  [SMALL_STATE(633)] = 19591,
  [SMALL_STATE(634)] = 19598,
  [SMALL_STATE(635)] = 19605,
  [SMALL_STATE(636)] = 19612,
  [SMALL_STATE(637)] = 19619,
  [SMALL_STATE(638)] = 19626,
  [SMALL_STATE(639)] = 19633,
  [SMALL_STATE(640)] = 19640,
  [SMALL_STATE(641)] = 19647,
  [SMALL_STATE(642)] = 19654,
  [SMALL_STATE(643)] = 19661,
  [SMALL_STATE(644)] = 19668,
  [SMALL_STATE(645)] = 19675,
  [SMALL_STATE(646)] = 19682,
  [SMALL_STATE(647)] = 19689,
  [SMALL_STATE(648)] = 19696,
  [SMALL_STATE(649)] = 19703,
  [SMALL_STATE(650)] = 19710,
  [SMALL_STATE(651)] = 19717,
  [SMALL_STATE(652)] = 19724,
  [SMALL_STATE(653)] = 19731,
  [SMALL_STATE(654)] = 19738,
  [SMALL_STATE(655)] = 19745,
  [SMALL_STATE(656)] = 19752,
  [SMALL_STATE(657)] = 19759,
  [SMALL_STATE(658)] = 19766,
  [SMALL_STATE(659)] = 19773,
  [SMALL_STATE(660)] = 19780,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_structure, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(372),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(327),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(652),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(660),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(659),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(658),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(379),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(657),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(108),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(159),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(330),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(215),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(583),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(565),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(56),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(566),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(654),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [65] = {.entry = {.count = 1, .reusable = false}}, SHIFT(313),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(645),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(156),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [77] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(156),
  [80] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(16),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(2),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_expression_repeat1, 2),
  [88] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(108),
  [91] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(159),
  [94] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(330),
  [97] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(215),
  [100] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(219),
  [103] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(583),
  [106] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(52),
  [109] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(565),
  [112] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(17),
  [115] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(54),
  [118] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(56),
  [121] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(566),
  [124] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(654),
  [127] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(64),
  [130] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(11),
  [133] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(214),
  [136] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(313),
  [139] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(645),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [152] = {.entry = {.count = 1, .reusable = false}}, SHIFT(213),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return_expression, 1),
  [156] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_return_expression, 1),
  [158] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [160] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [162] = {.entry = {.count = 1, .reusable = false}}, SHIFT(218),
  [164] = {.entry = {.count = 1, .reusable = false}}, SHIFT(330),
  [166] = {.entry = {.count = 1, .reusable = false}}, SHIFT(219),
  [168] = {.entry = {.count = 1, .reusable = false}}, SHIFT(583),
  [170] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [172] = {.entry = {.count = 1, .reusable = false}}, SHIFT(581),
  [174] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [176] = {.entry = {.count = 1, .reusable = false}}, SHIFT(214),
  [178] = {.entry = {.count = 1, .reusable = false}}, SHIFT(645),
  [180] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [182] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [188] = {.entry = {.count = 1, .reusable = false}}, SHIFT(132),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(347),
  [192] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(574),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [200] = {.entry = {.count = 1, .reusable = false}}, SHIFT(573),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [206] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [208] = {.entry = {.count = 1, .reusable = false}}, SHIFT(55),
  [210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(632),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 2),
  [262] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 2),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 3),
  [266] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 3),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constructor_expression, 1),
  [270] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constructor_expression, 1),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean_literal, 1),
  [274] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_boolean_literal, 1),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal, 1),
  [278] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_literal, 1),
  [280] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_char_literal, 3),
  [282] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_char_literal, 3),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constructor_expression, 2),
  [286] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constructor_expression, 2),
  [288] = {.entry = {.count = 1, .reusable = false}}, SHIFT(276),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(352),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(386),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(254),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(290),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(640),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(552),
  [308] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array_sub_pattern, 2),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [312] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_match_expression_repeat1, 2), SHIFT_REPEAT(276),
  [315] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_match_expression_repeat1, 2), SHIFT_REPEAT(102),
  [318] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_match_expression_repeat1, 2), SHIFT_REPEAT(352),
  [321] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_match_expression_repeat1, 2),
  [323] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_match_expression_repeat1, 2), SHIFT_REPEAT(386),
  [326] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_match_expression_repeat1, 2), SHIFT_REPEAT(75),
  [329] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_match_expression_repeat1, 2), SHIFT_REPEAT(76),
  [332] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_match_expression_repeat1, 2), SHIFT_REPEAT(574),
  [335] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_match_expression_repeat1, 2), SHIFT_REPEAT(79),
  [338] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_match_expression_repeat1, 2), SHIFT_REPEAT(74),
  [341] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_match_expression_repeat1, 2), SHIFT_REPEAT(313),
  [344] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_match_expression_repeat1, 2), SHIFT_REPEAT(640),
  [347] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array_sub_pattern, 3),
  [349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [353] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_expression, 3),
  [355] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_expression, 3),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(407),
  [359] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qualified_identifier, 2),
  [361] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qualified_identifier, 2),
  [363] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qualified_type_identifier, 2),
  [365] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_expression, 2),
  [367] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_expression, 2),
  [369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(288),
  [371] = {.entry = {.count = 1, .reusable = true}}, SHIFT(283),
  [373] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_expression, 3),
  [375] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_expression, 3),
  [377] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qualified_identifier, 1),
  [379] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qualified_identifier, 1),
  [381] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [383] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_labeled_expression_pun, 1),
  [385] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_shorthand_let_pattern, 1),
  [387] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array_sub_pattern, 1),
  [389] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array_sub_pattern, 4),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(280),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(299),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [397] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1),
  [399] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression, 1),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [407] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_match_expression, 4),
  [409] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_match_expression, 4),
  [411] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dot_apply_expression, 6),
  [413] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dot_apply_expression, 6),
  [415] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_match_expression, 5),
  [417] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_match_expression, 5),
  [419] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unit_expression, 2),
  [421] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unit_expression, 2),
  [423] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array_expression, 5),
  [425] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array_expression, 5),
  [427] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_interpolation, 5),
  [429] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_interpolation, 5),
  [431] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_expression, 5),
  [433] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct_expression, 5),
  [435] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_expression, 5),
  [437] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tuple_expression, 5),
  [439] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_apply_expression, 5),
  [441] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_apply_expression, 5),
  [443] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array_expression, 2),
  [445] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array_expression, 2),
  [447] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constraint_expression, 5),
  [449] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constraint_expression, 5),
  [451] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_atomic_expression, 1),
  [453] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_atomic_expression, 1),
  [455] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [457] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_accessor, 1),
  [459] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_accessor, 1),
  [461] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_access_expression, 2),
  [463] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_access_expression, 2),
  [465] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_expression, 2),
  [467] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unary_expression, 2),
  [469] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [471] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dot_apply_expression, 4),
  [473] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dot_apply_expression, 4),
  [475] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array_access_expression, 4),
  [477] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array_access_expression, 4),
  [479] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_apply_expression, 4),
  [481] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_apply_expression, 4),
  [483] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method_expression, 2),
  [485] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_method_expression, 2),
  [487] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_expression, 4),
  [489] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_expression, 4),
  [491] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dot_apply_expression, 5),
  [493] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dot_apply_expression, 5),
  [495] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array_expression, 4),
  [497] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array_expression, 4),
  [499] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_anonymous_lambda_expression, 4),
  [501] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_anonymous_lambda_expression, 4),
  [503] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_interpolation, 4),
  [505] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_interpolation, 4),
  [507] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_expression, 4),
  [509] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct_expression, 4),
  [511] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_expression, 4),
  [513] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tuple_expression, 4),
  [515] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_simple_expression, 1),
  [517] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_simple_expression, 1),
  [519] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_apply_expression, 3),
  [521] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_apply_expression, 3),
  [523] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3),
  [525] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3),
  [527] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [529] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [531] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [533] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [535] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [539] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [541] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dot_apply_expression, 7),
  [543] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dot_apply_expression, 7),
  [545] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array_expression, 3),
  [547] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array_expression, 3),
  [549] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_anonymous_lambda_expression, 3),
  [551] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_anonymous_lambda_expression, 3),
  [553] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_clause, 2),
  [555] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_else_clause, 2),
  [557] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_expression, 2),
  [559] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct_expression, 2),
  [561] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_interpolation, 3),
  [563] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_interpolation, 3),
  [565] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_nonempty_block_expression, 3),
  [567] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_nonempty_block_expression, 3),
  [569] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_expression, 3),
  [571] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct_expression, 3),
  [573] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_apply_expression, 6),
  [575] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_apply_expression, 6),
  [577] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_expression, 3),
  [579] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tuple_expression, 3),
  [581] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_expression, 6),
  [583] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct_expression, 6),
  [585] = {.entry = {.count = 1, .reusable = false}}, SHIFT(428),
  [587] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qualified_type_identifier, 2),
  [589] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_left_value, 1),
  [591] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [593] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [595] = {.entry = {.count = 1, .reusable = false}}, SHIFT(192),
  [597] = {.entry = {.count = 1, .reusable = false}}, SHIFT(193),
  [599] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [601] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [603] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [605] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [607] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [609] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [611] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [613] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [615] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_block_expression_repeat1, 2),
  [617] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [619] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [621] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [623] = {.entry = {.count = 1, .reusable = false}}, SHIFT(296),
  [625] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [627] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [629] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [631] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [633] = {.entry = {.count = 1, .reusable = false}}, SHIFT(298),
  [635] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [637] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_shorthand_let_expression, 3),
  [639] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_shorthand_let_expression, 3),
  [641] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [643] = {.entry = {.count = 1, .reusable = false}}, SHIFT(189),
  [645] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_expression, 5),
  [647] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_expression, 5),
  [649] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_expression, 4),
  [651] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_expression, 4),
  [653] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_apply_expression_repeat1, 2),
  [655] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [657] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [659] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [661] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [663] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_definition, 5),
  [665] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value_definition, 5),
  [667] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_expression, 4),
  [669] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_let_expression, 4),
  [671] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_expression, 5),
  [673] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_let_expression, 5),
  [675] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [677] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [679] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [681] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [683] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assign_expression, 3),
  [685] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_assign_expression, 3),
  [687] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_case_clause, 3),
  [689] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_case_clause, 3),
  [691] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [693] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [695] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return_expression, 2),
  [697] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_return_expression, 2),
  [699] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [701] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [703] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_definition, 4),
  [705] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value_definition, 4),
  [707] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_definition, 6),
  [709] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value_definition, 6),
  [711] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement_expression, 1),
  [713] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statement_expression, 1),
  [715] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [717] = {.entry = {.count = 1, .reusable = true}}, SHIFT(371),
  [719] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [721] = {.entry = {.count = 1, .reusable = true}}, SHIFT(375),
  [723] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labeled_expression, 3),
  [725] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [727] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [729] = {.entry = {.count = 1, .reusable = true}}, SHIFT(431),
  [731] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_structure, 1),
  [733] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_structure_repeat1, 2),
  [735] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_structure_repeat1, 2), SHIFT_REPEAT(372),
  [738] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_structure_repeat1, 2), SHIFT_REPEAT(327),
  [741] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_structure_repeat1, 2), SHIFT_REPEAT(652),
  [744] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_structure_repeat1, 2), SHIFT_REPEAT(660),
  [747] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_structure_repeat1, 2), SHIFT_REPEAT(659),
  [750] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_structure_repeat1, 2), SHIFT_REPEAT(658),
  [753] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_structure_repeat1, 2), SHIFT_REPEAT(379),
  [756] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_structure_repeat1, 2), SHIFT_REPEAT(657),
  [759] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dotdot_pattern, 1),
  [761] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dotdot_pattern, 1),
  [763] = {.entry = {.count = 1, .reusable = true}}, SHIFT(256),
  [765] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_match_expression_repeat1, 2),
  [767] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dotdot_pattern, 2),
  [769] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dotdot_pattern, 2),
  [771] = {.entry = {.count = 1, .reusable = true}}, SHIFT(271),
  [773] = {.entry = {.count = 1, .reusable = false}}, SHIFT(373),
  [775] = {.entry = {.count = 1, .reusable = true}}, SHIFT(359),
  [777] = {.entry = {.count = 1, .reusable = true}}, SHIFT(396),
  [779] = {.entry = {.count = 1, .reusable = true}}, SHIFT(398),
  [781] = {.entry = {.count = 1, .reusable = true}}, SHIFT(362),
  [783] = {.entry = {.count = 1, .reusable = true}}, SHIFT(567),
  [785] = {.entry = {.count = 1, .reusable = true}}, SHIFT(438),
  [787] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [789] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constructor_pattern, 1),
  [791] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constructor_pattern, 1),
  [793] = {.entry = {.count = 1, .reusable = true}}, SHIFT(395),
  [795] = {.entry = {.count = 1, .reusable = true}}, SHIFT(355),
  [797] = {.entry = {.count = 1, .reusable = true}}, SHIFT(416),
  [799] = {.entry = {.count = 1, .reusable = true}}, SHIFT(400),
  [801] = {.entry = {.count = 1, .reusable = true}}, SHIFT(551),
  [803] = {.entry = {.count = 1, .reusable = true}}, SHIFT(480),
  [805] = {.entry = {.count = 1, .reusable = true}}, SHIFT(399),
  [807] = {.entry = {.count = 1, .reusable = true}}, SHIFT(349),
  [809] = {.entry = {.count = 1, .reusable = true}}, SHIFT(417),
  [811] = {.entry = {.count = 1, .reusable = true}}, SHIFT(471),
  [813] = {.entry = {.count = 1, .reusable = true}}, SHIFT(353),
  [815] = {.entry = {.count = 1, .reusable = true}}, SHIFT(262),
  [817] = {.entry = {.count = 1, .reusable = false}}, SHIFT(503),
  [819] = {.entry = {.count = 1, .reusable = false}}, SHIFT(427),
  [821] = {.entry = {.count = 1, .reusable = true}}, SHIFT(618),
  [823] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_simple_pattern, 1),
  [825] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_simple_pattern, 1),
  [827] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constructor_pattern, 6),
  [829] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constructor_pattern, 6),
  [831] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_pattern, 6),
  [833] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tuple_pattern, 6),
  [835] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_simple_pattern, 3),
  [837] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_simple_pattern, 3),
  [839] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_pattern, 2),
  [841] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct_pattern, 2),
  [843] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constructor_pattern, 5),
  [845] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constructor_pattern, 5),
  [847] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_or_pattern, 3),
  [849] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_or_pattern, 3),
  [851] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [853] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array_pattern, 2),
  [855] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array_pattern, 2),
  [857] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_as_pattern, 3),
  [859] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_as_pattern, 3),
  [861] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array_pattern, 3),
  [863] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array_pattern, 3),
  [865] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_pattern, 5),
  [867] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tuple_pattern, 5),
  [869] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constraint_pattern, 5),
  [871] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constraint_pattern, 5),
  [873] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_pattern, 7),
  [875] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tuple_pattern, 7),
  [877] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 1),
  [879] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pattern, 1),
  [881] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constructor_pattern, 4),
  [883] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constructor_pattern, 4),
  [885] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_pattern, 3),
  [887] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct_pattern, 3),
  [889] = {.entry = {.count = 1, .reusable = true}}, SHIFT(487),
  [891] = {.entry = {.count = 1, .reusable = true}}, SHIFT(577),
  [893] = {.entry = {.count = 1, .reusable = true}}, SHIFT(578),
  [895] = {.entry = {.count = 1, .reusable = true}}, SHIFT(279),
  [897] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qualified_type_identifier, 1),
  [899] = {.entry = {.count = 1, .reusable = true}}, SHIFT(590),
  [901] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_interface_definition_repeat1, 2), SHIFT_REPEAT(356),
  [904] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_interface_definition_repeat1, 2),
  [906] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_interface_definition_repeat1, 2), SHIFT_REPEAT(313),
  [909] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_interface_definition_repeat1, 2), SHIFT_REPEAT(640),
  [912] = {.entry = {.count = 1, .reusable = false}}, SHIFT(615),
  [914] = {.entry = {.count = 1, .reusable = false}}, SHIFT(372),
  [916] = {.entry = {.count = 1, .reusable = false}}, SHIFT(411),
  [918] = {.entry = {.count = 1, .reusable = true}}, SHIFT(539),
  [920] = {.entry = {.count = 1, .reusable = false}}, SHIFT(614),
  [922] = {.entry = {.count = 1, .reusable = true}}, SHIFT(356),
  [924] = {.entry = {.count = 1, .reusable = true}}, SHIFT(472),
  [926] = {.entry = {.count = 1, .reusable = true}}, SHIFT(543),
  [928] = {.entry = {.count = 1, .reusable = true}}, SHIFT(507),
  [930] = {.entry = {.count = 1, .reusable = true}}, SHIFT(518),
  [932] = {.entry = {.count = 1, .reusable = true}}, SHIFT(533),
  [934] = {.entry = {.count = 1, .reusable = true}}, SHIFT(560),
  [936] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_struct_definition_repeat1, 2), SHIFT_REPEAT(615),
  [939] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_struct_definition_repeat1, 2), SHIFT_REPEAT(372),
  [942] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_struct_definition_repeat1, 2), SHIFT_REPEAT(411),
  [945] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_struct_definition_repeat1, 2),
  [947] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_struct_definition_repeat1, 2), SHIFT_REPEAT(614),
  [950] = {.entry = {.count = 1, .reusable = true}}, SHIFT(647),
  [952] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_visibility, 1),
  [954] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pub, 1),
  [956] = {.entry = {.count = 1, .reusable = false}}, SHIFT(169),
  [958] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [960] = {.entry = {.count = 1, .reusable = false}}, SHIFT(423),
  [962] = {.entry = {.count = 1, .reusable = true}}, SHIFT(423),
  [964] = {.entry = {.count = 1, .reusable = false}}, SHIFT(197),
  [966] = {.entry = {.count = 1, .reusable = false}}, SHIFT(106),
  [968] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [970] = {.entry = {.count = 1, .reusable = false}}, SHIFT(190),
  [972] = {.entry = {.count = 1, .reusable = true}}, SHIFT(600),
  [974] = {.entry = {.count = 1, .reusable = false}}, SHIFT(196),
  [976] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_interpolation_repeat2, 2),
  [978] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_interpolation_repeat2, 2), SHIFT_REPEAT(40),
  [981] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_interpolation_repeat2, 2), SHIFT_REPEAT(423),
  [984] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_interpolation_repeat2, 2), SHIFT_REPEAT(423),
  [987] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_apply_type, 1),
  [989] = {.entry = {.count = 1, .reusable = true}}, SHIFT(277),
  [991] = {.entry = {.count = 1, .reusable = true}}, SHIFT(434),
  [993] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_filed_pattern, 2),
  [995] = {.entry = {.count = 1, .reusable = false}}, SHIFT(128),
  [997] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_filed_pattern, 3),
  [999] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [1001] = {.entry = {.count = 1, .reusable = true}}, SHIFT(621),
  [1003] = {.entry = {.count = 1, .reusable = false}}, SHIFT(147),
  [1005] = {.entry = {.count = 1, .reusable = false}}, SHIFT(202),
  [1007] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [1009] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_type, 2),
  [1011] = {.entry = {.count = 1, .reusable = true}}, SHIFT(303),
  [1013] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_interpolation_repeat1, 2),
  [1015] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_interpolation_repeat1, 2), SHIFT_REPEAT(423),
  [1018] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_interpolation_repeat1, 2), SHIFT_REPEAT(423),
  [1021] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_constructor_pattern_repeat1, 2),
  [1023] = {.entry = {.count = 1, .reusable = true}}, SHIFT(286),
  [1025] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_type, 5),
  [1027] = {.entry = {.count = 1, .reusable = true}}, SHIFT(306),
  [1029] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_type, 3),
  [1031] = {.entry = {.count = 1, .reusable = true}}, SHIFT(287),
  [1033] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_type, 4),
  [1035] = {.entry = {.count = 1, .reusable = true}}, SHIFT(301),
  [1037] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_identifier, 1),
  [1039] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [1041] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_apply_type, 1),
  [1043] = {.entry = {.count = 1, .reusable = false}}, SHIFT(309),
  [1045] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_arguments, 5),
  [1047] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_defintion, 3),
  [1049] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_defintion, 3),
  [1051] = {.entry = {.count = 1, .reusable = false}}, SHIFT(586),
  [1053] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_method_declaration, 7),
  [1055] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_interface_method_declaration, 7),
  [1057] = {.entry = {.count = 1, .reusable = false}}, SHIFT(275),
  [1059] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pub_attribute, 3),
  [1061] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_defintion, 2),
  [1063] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_defintion, 2),
  [1065] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_visibility, 2),
  [1067] = {.entry = {.count = 1, .reusable = true}}, SHIFT(454),
  [1069] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_field_expression, 2),
  [1071] = {.entry = {.count = 1, .reusable = true}}, SHIFT(295),
  [1073] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [1075] = {.entry = {.count = 1, .reusable = true}}, SHIFT(584),
  [1077] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labeled_pattern, 3),
  [1079] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [1081] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_visibility, 1),
  [1083] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_any, 1),
  [1085] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [1087] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [1089] = {.entry = {.count = 1, .reusable = true}}, SHIFT(342),
  [1091] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_identifier, 2),
  [1093] = {.entry = {.count = 1, .reusable = true}}, SHIFT(291),
  [1095] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [1097] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [1099] = {.entry = {.count = 1, .reusable = true}}, SHIFT(307),
  [1101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [1103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_arguments, 3),
  [1105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_type, 7),
  [1107] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_constructor_pattern_repeat1, 2), SHIFT_REPEAT(154),
  [1110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_field_expression, 4),
  [1112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_filed_pattern, 1),
  [1114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(340),
  [1116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_type, 4),
  [1118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_apply_type, 2),
  [1120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_field_expression, 5),
  [1122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_method_declaration, 3),
  [1124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_interface_method_declaration, 3),
  [1126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_method_declaration, 4),
  [1128] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_interface_method_declaration, 4),
  [1130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(285),
  [1132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(282),
  [1134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [1136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_method_declaration, 6),
  [1138] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_interface_method_declaration, 6),
  [1140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_method_declaration, 5),
  [1142] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_interface_method_declaration, 5),
  [1144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_arguments, 4),
  [1146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(313),
  [1148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_type, 6),
  [1150] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_struct_definition_repeat1, 2),
  [1152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_type, 5),
  [1154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constraints, 1),
  [1156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(430),
  [1158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [1160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(536),
  [1162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(412),
  [1164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_constraints_repeat1, 2),
  [1166] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_constraints_repeat1, 2), SHIFT_REPEAT(430),
  [1169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constructor, 1),
  [1171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_constructor, 1),
  [1173] = {.entry = {.count = 1, .reusable = false}}, SHIFT(281),
  [1175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(541),
  [1177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 1),
  [1179] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tuple_type, 5),
  [1181] = {.entry = {.count = 1, .reusable = false}}, SHIFT(305),
  [1183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tuple_type, 4),
  [1185] = {.entry = {.count = 1, .reusable = false}}, SHIFT(293),
  [1187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_parameters, 5),
  [1189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_definition_repeat1, 2),
  [1191] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_definition_repeat1, 2), SHIFT_REPEAT(412),
  [1194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(505),
  [1196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tuple_type, 3),
  [1198] = {.entry = {.count = 1, .reusable = false}}, SHIFT(284),
  [1200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_parameters, 4),
  [1202] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_fragement, 1),
  [1204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_fragement, 1),
  [1206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_constructor_repeat1, 2),
  [1208] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_constructor_repeat1, 2), SHIFT_REPEAT(300),
  [1211] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qualified_type_identifier, 1),
  [1213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [1215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constraints, 2),
  [1217] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_interpolator, 3),
  [1219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interpolator, 3),
  [1221] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_interface_definition_repeat1, 2),
  [1223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labeled_pattern_pun, 1),
  [1225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [1227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(532),
  [1229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_parameters, 3),
  [1231] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tuple_type, 2),
  [1233] = {.entry = {.count = 1, .reusable = false}}, SHIFT(304),
  [1235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_struct_filed_pattern_repeat1, 2),
  [1237] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_filed_pattern_repeat1, 2), SHIFT_REPEAT(436),
  [1240] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_apply_expression_repeat1, 2), SHIFT_REPEAT(50),
  [1243] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_expression, 3),
  [1245] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_expression, 3),
  [1247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(548),
  [1249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(547),
  [1251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 5),
  [1253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [1255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [1257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(255),
  [1259] = {.entry = {.count = 1, .reusable = false}}, SHIFT(255),
  [1261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [1263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(316),
  [1265] = {.entry = {.count = 1, .reusable = false}}, SHIFT(316),
  [1267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(637),
  [1269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(636),
  [1271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(633),
  [1273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_field_expression, 3),
  [1275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(390),
  [1277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_structure_item, 1),
  [1279] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_structure_item, 1),
  [1281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labeled_expression_pun, 1),
  [1283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [1285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [1287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(604),
  [1289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(361),
  [1291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(631),
  [1293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(257),
  [1295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [1297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(273),
  [1299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [1301] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constructor, 4),
  [1303] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_constructor, 4),
  [1305] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_named_lambda_expression, 5),
  [1307] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_named_lambda_expression, 5),
  [1309] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_filed_declaration, 4),
  [1311] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct_filed_declaration, 4),
  [1313] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 8),
  [1315] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_definition, 8),
  [1317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(324),
  [1319] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_parameters, 5),
  [1321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(260),
  [1323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(408),
  [1325] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constructor, 6),
  [1327] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_constructor, 6),
  [1329] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_definition, 6),
  [1331] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_interface_definition, 6),
  [1333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(602),
  [1335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [1337] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_struct_field_expression_repeat1, 2),
  [1339] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_struct_field_expression_repeat1, 2), SHIFT_REPEAT(441),
  [1342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(270),
  [1344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [1346] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_named_lambda_expression, 4),
  [1348] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_named_lambda_expression, 4),
  [1350] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 6),
  [1352] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_definition, 6),
  [1354] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_constructor, 5),
  [1356] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_constructor, 5),
  [1358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(268),
  [1360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [1362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [1364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [1366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(415),
  [1368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(558),
  [1370] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_filed_single_pattern, 1),
  [1372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(261),
  [1374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(557),
  [1376] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 9),
  [1378] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_definition, 9),
  [1380] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameters_repeat1, 2),
  [1382] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameters_repeat1, 2), SHIFT_REPEAT(599),
  [1385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(444),
  [1387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(266),
  [1389] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 4),
  [1391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [1393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(418),
  [1395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(522),
  [1397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [1399] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_method_declaration, 8),
  [1401] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_interface_method_declaration, 8),
  [1403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(267),
  [1405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(385),
  [1407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(274),
  [1409] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_any, 1),
  [1411] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type, 1),
  [1413] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_definition, 6),
  [1415] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_definition, 6),
  [1417] = {.entry = {.count = 1, .reusable = true}}, SHIFT(462),
  [1419] = {.entry = {.count = 1, .reusable = true}}, SHIFT(269),
  [1421] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_definition, 6),
  [1423] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct_definition, 6),
  [1425] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 3),
  [1427] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_definition, 3),
  [1429] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_filed_declaration, 3),
  [1431] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct_filed_declaration, 3),
  [1433] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_type_parameters_repeat1, 2), SHIFT_REPEAT(579),
  [1436] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_type_parameters_repeat1, 2),
  [1438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(468),
  [1440] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_parameters, 4),
  [1442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(321),
  [1444] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_retuern_type, 2),
  [1446] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_retuern_type, 2),
  [1448] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_apply_type, 2),
  [1450] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constraint, 1),
  [1452] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_definition, 5),
  [1454] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_interface_definition, 5),
  [1456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(414),
  [1458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [1460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(401),
  [1462] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_identifier, 1),
  [1464] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 5),
  [1466] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_definition, 5),
  [1468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [1470] = {.entry = {.count = 1, .reusable = true}}, SHIFT(421),
  [1472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(272),
  [1474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(495),
  [1476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(493),
  [1478] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 3),
  [1480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(498),
  [1482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(422),
  [1484] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_filed_declaration, 5),
  [1486] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct_filed_declaration, 5),
  [1488] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_definition, 7),
  [1490] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_definition, 7),
  [1492] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_definition, 4),
  [1494] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct_definition, 4),
  [1496] = {.entry = {.count = 1, .reusable = true}}, SHIFT(264),
  [1498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(403),
  [1500] = {.entry = {.count = 1, .reusable = false}}, SHIFT(403),
  [1502] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_definition, 4),
  [1504] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_definition, 4),
  [1506] = {.entry = {.count = 1, .reusable = true}}, SHIFT(531),
  [1508] = {.entry = {.count = 1, .reusable = true}}, SHIFT(437),
  [1510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(354),
  [1512] = {.entry = {.count = 1, .reusable = true}}, SHIFT(265),
  [1514] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_definition, 7),
  [1516] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct_definition, 7),
  [1518] = {.entry = {.count = 1, .reusable = true}}, SHIFT(394),
  [1520] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_definition, 5),
  [1522] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_definition, 5),
  [1524] = {.entry = {.count = 1, .reusable = true}}, SHIFT(589),
  [1526] = {.entry = {.count = 1, .reusable = false}}, SHIFT(589),
  [1528] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_definition, 5),
  [1530] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct_definition, 5),
  [1532] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_type, 7),
  [1534] = {.entry = {.count = 1, .reusable = true}}, SHIFT(259),
  [1536] = {.entry = {.count = 1, .reusable = true}}, SHIFT(511),
  [1538] = {.entry = {.count = 1, .reusable = true}}, SHIFT(513),
  [1540] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_parameters, 3),
  [1542] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_annotation, 2),
  [1544] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_arguments, 5),
  [1546] = {.entry = {.count = 1, .reusable = true}}, SHIFT(592),
  [1548] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 7),
  [1550] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_definition, 7),
  [1552] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_type, 4),
  [1554] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_defintion, 4),
  [1556] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_defintion, 4),
  [1558] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_type, 6),
  [1560] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_arguments, 3),
  [1562] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 2),
  [1564] = {.entry = {.count = 1, .reusable = true}}, SHIFT(433),
  [1566] = {.entry = {.count = 1, .reusable = false}}, SHIFT(433),
  [1568] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_definition, 4),
  [1570] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_interface_definition, 4),
  [1572] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 4),
  [1574] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_definition, 4),
  [1576] = {.entry = {.count = 1, .reusable = true}}, SHIFT(528),
  [1578] = {.entry = {.count = 1, .reusable = true}}, SHIFT(527),
  [1580] = {.entry = {.count = 1, .reusable = true}}, SHIFT(598),
  [1582] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_arguments, 4),
  [1584] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [1586] = {.entry = {.count = 1, .reusable = false}}, SHIFT(212),
  [1588] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_type, 5),
  [1590] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 2),
  [1592] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_filed_expression, 1),
  [1594] = {.entry = {.count = 1, .reusable = false}}, SHIFT(611),
  [1596] = {.entry = {.count = 1, .reusable = true}}, SHIFT(611),
  [1598] = {.entry = {.count = 1, .reusable = true}}, SHIFT(366),
  [1600] = {.entry = {.count = 1, .reusable = false}}, SHIFT(608),
  [1602] = {.entry = {.count = 1, .reusable = true}}, SHIFT(608),
  [1604] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_field_expression, 1),
  [1606] = {.entry = {.count = 1, .reusable = true}}, SHIFT(367),
  [1608] = {.entry = {.count = 1, .reusable = false}}, SHIFT(629),
  [1610] = {.entry = {.count = 1, .reusable = false}}, SHIFT(625),
  [1612] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_identifier, 3),
  [1614] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [1616] = {.entry = {.count = 1, .reusable = true}}, SHIFT(521),
  [1618] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [1620] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [1622] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [1624] = {.entry = {.count = 1, .reusable = true}}, SHIFT(323),
  [1626] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [1628] = {.entry = {.count = 1, .reusable = true}}, SHIFT(258),
  [1630] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [1632] = {.entry = {.count = 1, .reusable = true}}, SHIFT(629),
  [1634] = {.entry = {.count = 1, .reusable = true}}, SHIFT(278),
  [1636] = {.entry = {.count = 1, .reusable = true}}, SHIFT(310),
  [1638] = {.entry = {.count = 1, .reusable = true}}, SHIFT(405),
  [1640] = {.entry = {.count = 1, .reusable = true}}, SHIFT(311),
  [1642] = {.entry = {.count = 1, .reusable = true}}, SHIFT(294),
  [1644] = {.entry = {.count = 1, .reusable = true}}, SHIFT(292),
  [1646] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [1648] = {.entry = {.count = 1, .reusable = true}}, SHIFT(616),
  [1650] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_filed_pattern, 4),
  [1652] = {.entry = {.count = 1, .reusable = true}}, SHIFT(308),
  [1654] = {.entry = {.count = 1, .reusable = true}}, SHIFT(363),
  [1656] = {.entry = {.count = 1, .reusable = true}}, SHIFT(610),
  [1658] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [1660] = {.entry = {.count = 1, .reusable = true}}, SHIFT(519),
  [1662] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [1664] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [1666] = {.entry = {.count = 1, .reusable = true}}, SHIFT(514),
  [1668] = {.entry = {.count = 1, .reusable = true}}, SHIFT(360),
  [1670] = {.entry = {.count = 1, .reusable = true}}, SHIFT(325),
  [1672] = {.entry = {.count = 1, .reusable = true}}, SHIFT(380),
  [1674] = {.entry = {.count = 1, .reusable = true}}, SHIFT(314),
  [1676] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [1678] = {.entry = {.count = 1, .reusable = true}}, SHIFT(425),
  [1680] = {.entry = {.count = 1, .reusable = true}}, SHIFT(322),
  [1682] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [1684] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [1686] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [1688] = {.entry = {.count = 1, .reusable = true}}, SHIFT(630),
  [1690] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [1692] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [1694] = {.entry = {.count = 1, .reusable = true}}, SHIFT(364),
  [1696] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [1698] = {.entry = {.count = 1, .reusable = true}}, SHIFT(524),
  [1700] = {.entry = {.count = 1, .reusable = true}}, SHIFT(297),
  [1702] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [1704] = {.entry = {.count = 1, .reusable = true}}, SHIFT(638),
  [1706] = {.entry = {.count = 1, .reusable = true}}, SHIFT(477),
  [1708] = {.entry = {.count = 1, .reusable = true}}, SHIFT(470),
  [1710] = {.entry = {.count = 1, .reusable = true}}, SHIFT(467),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_moonbit_external_scanner_create(void);
void tree_sitter_moonbit_external_scanner_destroy(void *);
bool tree_sitter_moonbit_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_moonbit_external_scanner_serialize(void *, char *);
void tree_sitter_moonbit_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_moonbit(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_lowercase_identifier,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_moonbit_external_scanner_create,
      tree_sitter_moonbit_external_scanner_destroy,
      tree_sitter_moonbit_external_scanner_scan,
      tree_sitter_moonbit_external_scanner_serialize,
      tree_sitter_moonbit_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
