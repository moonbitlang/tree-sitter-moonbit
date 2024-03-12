#include "tree_sitter/parser.h"
#include <wctype.h>

enum TokenType { FLOAT_LITERAL };

void *tree_sitter_moonbit_external_scanner_create() { return NULL; }
void tree_sitter_moonbit_external_scanner_destroy(void *p) {}
void tree_sitter_moonbit_external_scanner_reset(void *p) {}
unsigned tree_sitter_moonbit_external_scanner_serialize(void *p, char *buffer) {
  return 0;
}
void tree_sitter_moonbit_external_scanner_deserialize(void *p, const char *b,
                                                      unsigned n) {}

static void advance(TSLexer *lexer) { lexer->advance(lexer, false); }
static void skip(TSLexer *lexer) { lexer->advance(lexer, true); }
static bool is_num_char(int32_t c) { return c == '_' || iswdigit(c); }

bool tree_sitter_moonbit_external_scanner_scan(void *payload, TSLexer *lexer,
                                               const bool *valid_symbols) {
  if (valid_symbols[FLOAT_LITERAL]) {
    lexer->result_symbol = FLOAT_LITERAL;

    while (iswspace(lexer->lookahead)) {
      skip(lexer);
    }

    if (!iswdigit(lexer->lookahead)) {
      return false;
    }

    advance(lexer);

    while (is_num_char(lexer->lookahead)) {
      advance(lexer);
    }

    bool has_fraction = false, has_exponent = false;

    if (lexer->lookahead == '.') {
      has_fraction = true;
      advance(lexer);
      if (iswalpha(lexer->lookahead)) {
        // this is an integer
        return false;
      }

      if (lexer->lookahead == '.') {
        return false;
      }

      while (is_num_char(lexer->lookahead)) {
        advance(lexer);
      }
    }

    lexer->mark_end(lexer);

    if (lexer->lookahead == 'e' || lexer->lookahead == 'E') {
      has_exponent = true;
      advance(lexer);
      if (lexer->lookahead == '+' || lexer->lookahead == '-') {
        advance(lexer);
      }
      if (!is_num_char(lexer->lookahead)) {
        return true;
      }
      advance(lexer);
      while (is_num_char(lexer->lookahead)) {
        advance(lexer);
      }
      lexer->mark_end(lexer);
    }
    if (!has_fraction && !has_fraction) {
      return false;
    }
    return true;
  }
  return false;
}
