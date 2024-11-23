#include "string_managment.hpp"
#include <stdexcept>

const char* parsingString = nullptr;
const char* position_ = nullptr;

void kizhin::detail::setString(const char* string)
{
  if (parsingString == nullptr) {
    parsingString = string;
    position_ = string;
  } else {
    throw std::logic_error("String must be released before reseting.");
  }
}

const char* kizhin::detail::position()
{
  return position_;
}

void kizhin::detail::incrementPosition()
{
  if (parsingString != nullptr) {
    ++position_;
  } else {
    throw std::logic_error("Can't increment to empty position.");
  }
}

void kizhin::detail::releaseString()
{
  parsingString = nullptr;
  position_ = nullptr;
}

