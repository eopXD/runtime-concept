#include "library.h"

int main ()
{
  document_t document;
  
  // reservation does not call object constructor
  document.reserve(5);

  /*document.emplace_back(1);
  document.emplace_back(1);
  document.emplace_back(2);
  document.emplace_back(3);
  document.emplace_back(5);
*/

  document.push_back(1);
  document.push_back(1);
  document.push_back(2);
  document.push_back(3);
  document.push_back(5);

  draw(document, std::cout, 0);

  return 0;
}
