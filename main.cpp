#include "library.h"

object_t func()
{
  object_t result = 5;
  return result;
}

int main ()
{
  document_t document;
  
  // reservation does not call object constructor
  document.reserve(5);

  document.emplace_back(1);
  document.emplace_back(1);
  document.emplace_back(2);
  document.emplace_back(3);
  document.emplace_back(5);

  reverse(document.begin(), document.end());

  draw(document, std::cout, 0);

  /*std::cout << "======================\n";
  object_t x = func();
  std::cout << "======================\n";
  object_t y = 0;
  y = func();
  */
  return 0;
}
