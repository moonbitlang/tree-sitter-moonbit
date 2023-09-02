#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 73
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 35
#define ALIAS_COUNT 0
#define TOKEN_COUNT 19
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_SEMI = 1,
  anon_sym_func = 2,
  anon_sym_type = 3,
  anon_sym_LBRACK = 4,
  anon_sym_COMMA = 5,
  anon_sym_RBRACK = 6,
  anon_sym_COLON = 7,
  anon_sym_DASH_GT = 8,
  anon_sym_LPAREN = 9,
  anon_sym_RPAREN = 10,
  sym_type = 11,
  anon_sym_LBRACE = 12,
  anon_sym_RBRACE = 13,
  sym_statement_expression = 14,
  sym_identifier = 15,
  anon_sym_priv = 16,
  anon_sym_pub = 17,
  anon_sym_readonly = 18,
  sym_structure = 19,
  sym_structure_item = 20,
  sym_function_definition = 21,
  sym_type_defintion = 22,
  sym_type_parameters = 23,
  sym_type_annotation = 24,
  sym_retuern_type = 25,
  sym_parameter = 26,
  sym_parameters = 27,
  sym_block_expression = 28,
  sym_visibility = 29,
  sym_pub_attr = 30,
  aux_sym_structure_repeat1 = 31,
  aux_sym_type_parameters_repeat1 = 32,
  aux_sym_parameters_repeat1 = 33,
  aux_sym_block_expression_repeat1 = 34,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_SEMI] = ";",
  [anon_sym_func] = "func",
  [anon_sym_type] = "type",
  [anon_sym_LBRACK] = "[",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACK] = "]",
  [anon_sym_COLON] = ":",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym_type] = "type",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym_statement_expression] = "statement_expression",
  [sym_identifier] = "identifier",
  [anon_sym_priv] = "priv",
  [anon_sym_pub] = "pub",
  [anon_sym_readonly] = "readonly",
  [sym_structure] = "structure",
  [sym_structure_item] = "structure_item",
  [sym_function_definition] = "function_definition",
  [sym_type_defintion] = "type_defintion",
  [sym_type_parameters] = "type_parameters",
  [sym_type_annotation] = "type_annotation",
  [sym_retuern_type] = "retuern_type",
  [sym_parameter] = "parameter",
  [sym_parameters] = "parameters",
  [sym_block_expression] = "block_expression",
  [sym_visibility] = "visibility",
  [sym_pub_attr] = "pub_attr",
  [aux_sym_structure_repeat1] = "structure_repeat1",
  [aux_sym_type_parameters_repeat1] = "type_parameters_repeat1",
  [aux_sym_parameters_repeat1] = "parameters_repeat1",
  [aux_sym_block_expression_repeat1] = "block_expression_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_func] = anon_sym_func,
  [anon_sym_type] = anon_sym_type,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_type] = sym_type,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_statement_expression] = sym_statement_expression,
  [sym_identifier] = sym_identifier,
  [anon_sym_priv] = anon_sym_priv,
  [anon_sym_pub] = anon_sym_pub,
  [anon_sym_readonly] = anon_sym_readonly,
  [sym_structure] = sym_structure,
  [sym_structure_item] = sym_structure_item,
  [sym_function_definition] = sym_function_definition,
  [sym_type_defintion] = sym_type_defintion,
  [sym_type_parameters] = sym_type_parameters,
  [sym_type_annotation] = sym_type_annotation,
  [sym_retuern_type] = sym_retuern_type,
  [sym_parameter] = sym_parameter,
  [sym_parameters] = sym_parameters,
  [sym_block_expression] = sym_block_expression,
  [sym_visibility] = sym_visibility,
  [sym_pub_attr] = sym_pub_attr,
  [aux_sym_structure_repeat1] = aux_sym_structure_repeat1,
  [aux_sym_type_parameters_repeat1] = aux_sym_type_parameters_repeat1,
  [aux_sym_parameters_repeat1] = aux_sym_parameters_repeat1,
  [aux_sym_block_expression_repeat1] = aux_sym_block_expression_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_func] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_type] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_statement_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_priv] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pub] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_readonly] = {
    .visible = true,
    .named = false,
  },
  [sym_structure] = {
    .visible = true,
    .named = true,
  },
  [sym_structure_item] = {
    .visible = true,
    .named = true,
  },
  [sym_function_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_type_defintion] = {
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
  [sym_block_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_visibility] = {
    .visible = true,
    .named = true,
  },
  [sym_pub_attr] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_structure_repeat1] = {
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
  [aux_sym_block_expression_repeat1] = {
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
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(25);
      if (lookahead == '(') ADVANCE(34);
      if (lookahead == ')') ADVANCE(35);
      if (lookahead == ',') ADVANCE(30);
      if (lookahead == '-') ADVANCE(2);
      if (lookahead == ':') ADVANCE(32);
      if (lookahead == ';') ADVANCE(26);
      if (lookahead == 'I') ADVANCE(11);
      if (lookahead == '[') ADVANCE(29);
      if (lookahead == ']') ADVANCE(31);
      if (lookahead == 'f') ADVANCE(21);
      if (lookahead == 'p') ADVANCE(17);
      if (lookahead == 'r') ADVANCE(7);
      if (lookahead == 't') ADVANCE(23);
      if (lookahead == '{') ADVANCE(37);
      if (lookahead == '}') ADVANCE(38);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == ')') ADVANCE(35);
      if (lookahead == ']') ADVANCE(31);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(40);
      END_STATE();
    case 2:
      if (lookahead == '>') ADVANCE(33);
      END_STATE();
    case 3:
      if (lookahead == 'a') ADVANCE(6);
      if (lookahead == 't') ADVANCE(20);
      END_STATE();
    case 4:
      if (lookahead == 'b') ADVANCE(42);
      END_STATE();
    case 5:
      if (lookahead == 'c') ADVANCE(27);
      END_STATE();
    case 6:
      if (lookahead == 'd') ADVANCE(15);
      END_STATE();
    case 7:
      if (lookahead == 'e') ADVANCE(3);
      END_STATE();
    case 8:
      if (lookahead == 'e') ADVANCE(28);
      END_STATE();
    case 9:
      if (lookahead == 'i') ADVANCE(22);
      END_STATE();
    case 10:
      if (lookahead == 'l') ADVANCE(24);
      END_STATE();
    case 11:
      if (lookahead == 'n') ADVANCE(19);
      END_STATE();
    case 12:
      if (lookahead == 'n') ADVANCE(5);
      END_STATE();
    case 13:
      if (lookahead == 'n') ADVANCE(10);
      END_STATE();
    case 14:
      if (lookahead == 'n') ADVANCE(39);
      END_STATE();
    case 15:
      if (lookahead == 'o') ADVANCE(13);
      END_STATE();
    case 16:
      if (lookahead == 'p') ADVANCE(8);
      END_STATE();
    case 17:
      if (lookahead == 'r') ADVANCE(9);
      if (lookahead == 'u') ADVANCE(4);
      END_STATE();
    case 18:
      if (lookahead == 'r') ADVANCE(14);
      END_STATE();
    case 19:
      if (lookahead == 't') ADVANCE(36);
      END_STATE();
    case 20:
      if (lookahead == 'u') ADVANCE(18);
      END_STATE();
    case 21:
      if (lookahead == 'u') ADVANCE(12);
      END_STATE();
    case 22:
      if (lookahead == 'v') ADVANCE(41);
      END_STATE();
    case 23:
      if (lookahead == 'y') ADVANCE(16);
      END_STATE();
    case 24:
      if (lookahead == 'y') ADVANCE(43);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_func);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_type);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_type);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_statement_expression);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_identifier);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(40);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_priv);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_pub);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_readonly);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 1},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 1},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 1},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 1},
  [67] = {.lex_state = 1},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 1},
  [72] = {.lex_state = 1},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_func] = ACTIONS(1),
    [anon_sym_type] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_type] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym_statement_expression] = ACTIONS(1),
    [anon_sym_priv] = ACTIONS(1),
    [anon_sym_pub] = ACTIONS(1),
    [anon_sym_readonly] = ACTIONS(1),
  },
  [1] = {
    [sym_structure] = STATE(58),
    [sym_structure_item] = STATE(19),
    [sym_function_definition] = STATE(53),
    [sym_type_defintion] = STATE(53),
    [sym_visibility] = STATE(57),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_func] = ACTIONS(5),
    [anon_sym_type] = ACTIONS(7),
    [anon_sym_priv] = ACTIONS(9),
    [anon_sym_pub] = ACTIONS(11),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 8,
    ACTIONS(5), 1,
      anon_sym_func,
    ACTIONS(7), 1,
      anon_sym_type,
    ACTIONS(9), 1,
      anon_sym_priv,
    ACTIONS(11), 1,
      anon_sym_pub,
    ACTIONS(13), 1,
      ts_builtin_sym_end,
    STATE(31), 1,
      sym_structure_item,
    STATE(57), 1,
      sym_visibility,
    STATE(53), 2,
      sym_function_definition,
      sym_type_defintion,
  [26] = 8,
    ACTIONS(5), 1,
      anon_sym_func,
    ACTIONS(7), 1,
      anon_sym_type,
    ACTIONS(9), 1,
      anon_sym_priv,
    ACTIONS(11), 1,
      anon_sym_pub,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    STATE(31), 1,
      sym_structure_item,
    STATE(57), 1,
      sym_visibility,
    STATE(53), 2,
      sym_function_definition,
      sym_type_defintion,
  [52] = 7,
    ACTIONS(5), 1,
      anon_sym_func,
    ACTIONS(7), 1,
      anon_sym_type,
    ACTIONS(9), 1,
      anon_sym_priv,
    ACTIONS(11), 1,
      anon_sym_pub,
    STATE(31), 1,
      sym_structure_item,
    STATE(57), 1,
      sym_visibility,
    STATE(53), 2,
      sym_function_definition,
      sym_type_defintion,
  [75] = 6,
    ACTIONS(17), 1,
      anon_sym_DASH_GT,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    STATE(8), 1,
      sym_parameters,
    STATE(36), 1,
      sym_retuern_type,
    STATE(46), 1,
      sym_block_expression,
  [94] = 3,
    ACTIONS(25), 1,
      anon_sym_COLON,
    STATE(43), 1,
      sym_type_annotation,
    ACTIONS(23), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [105] = 3,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    STATE(41), 1,
      sym_type_parameters,
    ACTIONS(27), 2,
      ts_builtin_sym_end,
      anon_sym_SEMI,
  [116] = 4,
    ACTIONS(17), 1,
      anon_sym_DASH_GT,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    STATE(26), 1,
      sym_block_expression,
    STATE(37), 1,
      sym_retuern_type,
  [129] = 3,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    STATE(29), 1,
      sym_type_parameters,
    ACTIONS(31), 2,
      ts_builtin_sym_end,
      anon_sym_SEMI,
  [140] = 3,
    ACTIONS(33), 1,
      anon_sym_COMMA,
    ACTIONS(35), 1,
      anon_sym_RPAREN,
    STATE(24), 1,
      aux_sym_parameters_repeat1,
  [150] = 3,
    ACTIONS(37), 1,
      anon_sym_SEMI,
    ACTIONS(39), 1,
      anon_sym_RBRACE,
    STATE(25), 1,
      aux_sym_block_expression_repeat1,
  [160] = 3,
    ACTIONS(41), 1,
      anon_sym_COMMA,
    ACTIONS(43), 1,
      anon_sym_RPAREN,
    STATE(10), 1,
      aux_sym_parameters_repeat1,
  [170] = 3,
    ACTIONS(35), 1,
      anon_sym_RPAREN,
    ACTIONS(45), 1,
      sym_identifier,
    STATE(56), 1,
      sym_parameter,
  [180] = 3,
    ACTIONS(47), 1,
      anon_sym_COMMA,
    ACTIONS(50), 1,
      anon_sym_RBRACK,
    STATE(14), 1,
      aux_sym_type_parameters_repeat1,
  [190] = 3,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    ACTIONS(52), 1,
      anon_sym_SEMI,
    STATE(23), 1,
      aux_sym_structure_repeat1,
  [200] = 3,
    ACTIONS(54), 1,
      anon_sym_COMMA,
    ACTIONS(56), 1,
      anon_sym_RBRACK,
    STATE(14), 1,
      aux_sym_type_parameters_repeat1,
  [210] = 3,
    ACTIONS(58), 1,
      anon_sym_COMMA,
    ACTIONS(60), 1,
      anon_sym_RBRACK,
    STATE(16), 1,
      aux_sym_type_parameters_repeat1,
  [220] = 3,
    ACTIONS(45), 1,
      sym_identifier,
    ACTIONS(62), 1,
      anon_sym_RPAREN,
    STATE(12), 1,
      sym_parameter,
  [230] = 3,
    ACTIONS(64), 1,
      ts_builtin_sym_end,
    ACTIONS(66), 1,
      anon_sym_SEMI,
    STATE(15), 1,
      aux_sym_structure_repeat1,
  [240] = 3,
    ACTIONS(68), 1,
      anon_sym_SEMI,
    ACTIONS(70), 1,
      anon_sym_RBRACE,
    STATE(11), 1,
      aux_sym_block_expression_repeat1,
  [250] = 3,
    ACTIONS(45), 1,
      sym_identifier,
    ACTIONS(72), 1,
      anon_sym_RPAREN,
    STATE(56), 1,
      sym_parameter,
  [260] = 3,
    ACTIONS(74), 1,
      anon_sym_type,
    ACTIONS(76), 1,
      anon_sym_LPAREN,
    STATE(60), 1,
      sym_pub_attr,
  [270] = 3,
    ACTIONS(78), 1,
      ts_builtin_sym_end,
    ACTIONS(80), 1,
      anon_sym_SEMI,
    STATE(23), 1,
      aux_sym_structure_repeat1,
  [280] = 3,
    ACTIONS(83), 1,
      anon_sym_COMMA,
    ACTIONS(86), 1,
      anon_sym_RPAREN,
    STATE(24), 1,
      aux_sym_parameters_repeat1,
  [290] = 3,
    ACTIONS(88), 1,
      anon_sym_SEMI,
    ACTIONS(91), 1,
      anon_sym_RBRACE,
    STATE(25), 1,
      aux_sym_block_expression_repeat1,
  [300] = 1,
    ACTIONS(93), 2,
      ts_builtin_sym_end,
      anon_sym_SEMI,
  [305] = 1,
    ACTIONS(91), 2,
      anon_sym_SEMI,
      anon_sym_RBRACE,
  [310] = 1,
    ACTIONS(95), 2,
      ts_builtin_sym_end,
      anon_sym_SEMI,
  [315] = 1,
    ACTIONS(27), 2,
      ts_builtin_sym_end,
      anon_sym_SEMI,
  [320] = 1,
    ACTIONS(97), 2,
      ts_builtin_sym_end,
      anon_sym_SEMI,
  [325] = 1,
    ACTIONS(78), 2,
      ts_builtin_sym_end,
      anon_sym_SEMI,
  [330] = 2,
    ACTIONS(45), 1,
      sym_identifier,
    STATE(56), 1,
      sym_parameter,
  [337] = 1,
    ACTIONS(99), 2,
      anon_sym_DASH_GT,
      anon_sym_LBRACE,
  [342] = 1,
    ACTIONS(101), 2,
      ts_builtin_sym_end,
      anon_sym_SEMI,
  [347] = 1,
    ACTIONS(103), 2,
      anon_sym_DASH_GT,
      anon_sym_LBRACE,
  [352] = 2,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    STATE(26), 1,
      sym_block_expression,
  [359] = 2,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    STATE(50), 1,
      sym_block_expression,
  [366] = 2,
    ACTIONS(105), 1,
      anon_sym_RBRACE,
    ACTIONS(107), 1,
      sym_statement_expression,
  [373] = 2,
    ACTIONS(109), 1,
      anon_sym_RBRACK,
    ACTIONS(111), 1,
      sym_identifier,
  [380] = 1,
    ACTIONS(50), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [385] = 1,
    ACTIONS(113), 2,
      ts_builtin_sym_end,
      anon_sym_SEMI,
  [390] = 1,
    ACTIONS(115), 2,
      ts_builtin_sym_end,
      anon_sym_SEMI,
  [395] = 1,
    ACTIONS(117), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [400] = 2,
    ACTIONS(119), 1,
      anon_sym_RBRACE,
    ACTIONS(121), 1,
      sym_statement_expression,
  [407] = 1,
    ACTIONS(123), 2,
      anon_sym_DASH_GT,
      anon_sym_LBRACE,
  [412] = 1,
    ACTIONS(125), 2,
      ts_builtin_sym_end,
      anon_sym_SEMI,
  [417] = 2,
    ACTIONS(39), 1,
      anon_sym_RBRACE,
    ACTIONS(121), 1,
      sym_statement_expression,
  [424] = 1,
    ACTIONS(127), 2,
      ts_builtin_sym_end,
      anon_sym_SEMI,
  [429] = 1,
    ACTIONS(129), 2,
      ts_builtin_sym_end,
      anon_sym_SEMI,
  [434] = 1,
    ACTIONS(131), 2,
      ts_builtin_sym_end,
      anon_sym_SEMI,
  [439] = 2,
    ACTIONS(56), 1,
      anon_sym_RBRACK,
    ACTIONS(111), 1,
      sym_identifier,
  [446] = 1,
    ACTIONS(133), 2,
      ts_builtin_sym_end,
      anon_sym_SEMI,
  [451] = 1,
    ACTIONS(135), 2,
      ts_builtin_sym_end,
      anon_sym_SEMI,
  [456] = 1,
    ACTIONS(137), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [461] = 1,
    ACTIONS(139), 2,
      anon_sym_DASH_GT,
      anon_sym_LBRACE,
  [466] = 1,
    ACTIONS(86), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [471] = 1,
    ACTIONS(141), 1,
      anon_sym_type,
  [475] = 1,
    ACTIONS(143), 1,
      ts_builtin_sym_end,
  [479] = 1,
    ACTIONS(145), 1,
      anon_sym_readonly,
  [483] = 1,
    ACTIONS(147), 1,
      anon_sym_type,
  [487] = 1,
    ACTIONS(149), 1,
      sym_identifier,
  [491] = 1,
    ACTIONS(74), 1,
      anon_sym_type,
  [495] = 1,
    ACTIONS(151), 1,
      sym_type,
  [499] = 1,
    ACTIONS(153), 1,
      sym_type,
  [503] = 1,
    ACTIONS(155), 1,
      anon_sym_type,
  [507] = 1,
    ACTIONS(157), 1,
      sym_identifier,
  [511] = 1,
    ACTIONS(159), 1,
      sym_identifier,
  [515] = 1,
    ACTIONS(161), 1,
      anon_sym_LBRACE,
  [519] = 1,
    ACTIONS(163), 1,
      anon_sym_RPAREN,
  [523] = 1,
    ACTIONS(121), 1,
      sym_statement_expression,
  [527] = 1,
    ACTIONS(165), 1,
      sym_identifier,
  [531] = 1,
    ACTIONS(111), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 26,
  [SMALL_STATE(4)] = 52,
  [SMALL_STATE(5)] = 75,
  [SMALL_STATE(6)] = 94,
  [SMALL_STATE(7)] = 105,
  [SMALL_STATE(8)] = 116,
  [SMALL_STATE(9)] = 129,
  [SMALL_STATE(10)] = 140,
  [SMALL_STATE(11)] = 150,
  [SMALL_STATE(12)] = 160,
  [SMALL_STATE(13)] = 170,
  [SMALL_STATE(14)] = 180,
  [SMALL_STATE(15)] = 190,
  [SMALL_STATE(16)] = 200,
  [SMALL_STATE(17)] = 210,
  [SMALL_STATE(18)] = 220,
  [SMALL_STATE(19)] = 230,
  [SMALL_STATE(20)] = 240,
  [SMALL_STATE(21)] = 250,
  [SMALL_STATE(22)] = 260,
  [SMALL_STATE(23)] = 270,
  [SMALL_STATE(24)] = 280,
  [SMALL_STATE(25)] = 290,
  [SMALL_STATE(26)] = 300,
  [SMALL_STATE(27)] = 305,
  [SMALL_STATE(28)] = 310,
  [SMALL_STATE(29)] = 315,
  [SMALL_STATE(30)] = 320,
  [SMALL_STATE(31)] = 325,
  [SMALL_STATE(32)] = 330,
  [SMALL_STATE(33)] = 337,
  [SMALL_STATE(34)] = 342,
  [SMALL_STATE(35)] = 347,
  [SMALL_STATE(36)] = 352,
  [SMALL_STATE(37)] = 359,
  [SMALL_STATE(38)] = 366,
  [SMALL_STATE(39)] = 373,
  [SMALL_STATE(40)] = 380,
  [SMALL_STATE(41)] = 385,
  [SMALL_STATE(42)] = 390,
  [SMALL_STATE(43)] = 395,
  [SMALL_STATE(44)] = 400,
  [SMALL_STATE(45)] = 407,
  [SMALL_STATE(46)] = 412,
  [SMALL_STATE(47)] = 417,
  [SMALL_STATE(48)] = 424,
  [SMALL_STATE(49)] = 429,
  [SMALL_STATE(50)] = 434,
  [SMALL_STATE(51)] = 439,
  [SMALL_STATE(52)] = 446,
  [SMALL_STATE(53)] = 451,
  [SMALL_STATE(54)] = 456,
  [SMALL_STATE(55)] = 461,
  [SMALL_STATE(56)] = 466,
  [SMALL_STATE(57)] = 471,
  [SMALL_STATE(58)] = 475,
  [SMALL_STATE(59)] = 479,
  [SMALL_STATE(60)] = 483,
  [SMALL_STATE(61)] = 487,
  [SMALL_STATE(62)] = 491,
  [SMALL_STATE(63)] = 495,
  [SMALL_STATE(64)] = 499,
  [SMALL_STATE(65)] = 503,
  [SMALL_STATE(66)] = 507,
  [SMALL_STATE(67)] = 511,
  [SMALL_STATE(68)] = 515,
  [SMALL_STATE(69)] = 519,
  [SMALL_STATE(70)] = 523,
  [SMALL_STATE(71)] = 527,
  [SMALL_STATE(72)] = 531,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_structure, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_structure, 3),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_structure, 2),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 1),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_defintion, 3),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_defintion, 2),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [47] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_type_parameters_repeat1, 2), SHIFT_REPEAT(72),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_type_parameters_repeat1, 2),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_structure, 1),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_visibility, 1),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_structure_repeat1, 2),
  [80] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_structure_repeat1, 2), SHIFT_REPEAT(4),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameters_repeat1, 2), SHIFT_REPEAT(32),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameters_repeat1, 2),
  [88] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_expression_repeat1, 2), SHIFT_REPEAT(70),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_expression_repeat1, 2),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 4),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_parameters, 5),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_expression, 5),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 2),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_expression, 2),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 5),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_defintion, 4),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_parameters, 4),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 2),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 3),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 3),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_expression, 3),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_expression, 4),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 5),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_parameters, 3),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_structure_item, 1),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_annotation, 2),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 4),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [143] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_visibility, 2),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pub_attr, 3),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_retuern_type, 2),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
};

#ifdef __cplusplus
extern "C" {
#endif
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
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
