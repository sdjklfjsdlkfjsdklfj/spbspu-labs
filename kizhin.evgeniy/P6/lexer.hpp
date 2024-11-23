#ifndef LEXER_HPP
#define LEXER_HPP

namespace kizhin {
  namespace detail {
    enum class TokenType;
    TokenType popCurrentTokenType();
  }
}

enum class kizhin::detail::TokenType {
  NUMBER,
  IDENTIFIER,
  PLUS_MINUS,
  MULTIPLY_DIVIDE,
  OPEN_PARENTHESIS,
  CLOSE_PARENTHESIS,
  END,
  UNKNOWN,
};

#endif
