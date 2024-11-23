#include <iostream>
#include <string_utils.hpp>
#include "parser.hpp"

int main()
{
  char* inputString = kizhin::readString(std::cin);
  if (!inputString) {
    std::cerr << "Failed to input string\n";
    return 1;
  }
  std::cout << std::boolalpha << kizhin::parse(inputString) << '\n';
  free(inputString);
}
