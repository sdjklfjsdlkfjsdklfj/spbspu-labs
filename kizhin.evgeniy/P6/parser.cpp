#include "parser.hpp"
#include "lexer.hpp"
#include "string_managment.hpp"

static kizhin::detail::TokenType currentTokenType;

bool parseExpression();
bool parseTerm();
bool parseFactor();

void nextToken()
{
  currentTokenType = kizhin::detail::popCurrentTokenType();
}

bool kizhin::parse(const char* string)
{
  kizhin::detail::setString(string);
  nextToken();
  bool result = parseExpression();
  kizhin::detail::releaseString();
  return result;
}

bool parseExpression()
{
  using kizhin::detail::TokenType;
  if (!parseTerm()) {
    return false;
  } else if (currentTokenType == TokenType::END) {
    return true;
  } else if (currentTokenType == TokenType::PLUS_MINUS) {
    nextToken();
    return parseExpression();
  }
  return false;
}

bool parseTerm()
{
  using kizhin::detail::TokenType;
  if (!parseFactor()) {
    return false;
  }
  if (currentTokenType == TokenType::MULTIPLY_DIVIDE) {
    nextToken();
    return parseTerm();
  }
  return true;
}

bool parseFactor()
{
  using kizhin::detail::TokenType;
  if (currentTokenType == TokenType::OPEN_PARENTHESIS) {
    nextToken();
    if (!parseExpression() || currentTokenType != TokenType::CLOSE_PARENTHESIS) {
      return false;
    }
    nextToken();
    return true;
  }
  if (currentTokenType == TokenType::NUMBER || currentTokenType == TokenType::IDENTIFIER) {
    nextToken();
    return true;
  }
  return false;
}
