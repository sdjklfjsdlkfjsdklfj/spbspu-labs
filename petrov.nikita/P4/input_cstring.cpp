#include "making_new_cstring.hpp"
#include <iostream>
#include <exception>

char * petrov::inputCString(std::istream & in, size_t & capacity)
{
  std::noskipws(in);
  char * string = nullptr;
  try
  {
    string = new char[2];
  }
  catch (const std::bad_alloc & e)
  {
    throw;
  }
  in >> string[0];
  if (string[0] == '\n' || std::cin.eof())
  {
    return string;
  }
  string[1] = '\0';
  size_t i = 2;
  try
  {
    while (string[i - 2] != '\n')
    {
      char * temp_string = new char[++i];
      size_t j = 0;
      while (string[j] != '\0')
      {
        temp_string[j] = string[j];
        j++;
      }
      temp_string[j] = '\0';
      if (i == 3)
      delete[] string;
      string = temp_string;
      in >> string[i - 2];
      string[i - 1] = '\0';
      if ((i - 1) > capacity)
      {
        capacity++;
      }
      if (in.eof())
      {
        return string;
      }
    }
    string[i - 2] = '\0';
    return string;
  }
  catch (const std::bad_alloc & e)
  {
    delete[] string;
    throw;
  }
}
