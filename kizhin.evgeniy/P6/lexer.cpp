#include "lexer.hpp"
#include <cctype>
#include "string_managment.hpp"

kizhin::detail::TokenType determineTokenType(const char*);
bool isValidIdentifier(char);

kizhin::detail::TokenType kizhin::detail::popCurrentTokenType()
{
  using kizhin::detail::incrementPosition;
  using kizhin::detail::position;

  if (!position()) {
    return TokenType::END;
  }
  while (std::isspace(*position())) {
    incrementPosition();
  }
  TokenType currentTokenType = determineTokenType(position());
  if (currentTokenType == TokenType::NUMBER) {
    while (std::isdigit(*position())) {
      incrementPosition();
    }
  } else {
    incrementPosition();
  }
  return currentTokenType;
}

kizhin::detail::TokenType determineTokenType(const char* lexem)
{
  using kizhin::detail::TokenType;
  if (std::isdigit(*lexem)) {
    return TokenType::NUMBER;
  } else if (isValidIdentifier(*lexem)) {
    return TokenType::IDENTIFIER;
  } else if (*lexem == '+' || *lexem == '-') {
    return TokenType::PLUS_MINUS;
  } else if (*lexem == '*' || *lexem == '/') {
    return TokenType::MULTIPLY_DIVIDE;
  } else if (*lexem == ')') {
    return TokenType::CLOSE_PARENTHESIS;
  } else if (*lexem == '(') {
    return TokenType::OPEN_PARENTHESIS;
  } else if (*lexem == '\0') {
    return TokenType::END;
  }
  return TokenType::UNKNOWN;
}

bool isValidIdentifier(char value)
{
  const char* valid = "abcdefxyz";
  for (const char* i = valid; *i != '\0'; ++i) {
    if (*i == value) {
      return true;
    }
  }
  return false;
}
