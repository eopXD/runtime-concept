#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using object_t = int;

void draw(const object_t& obj, std::ostream& out, size_t position)
{
  out << std::string(position, ' ') << obj << std::endl;
}

using document_t = std::vector<object_t>;

void draw(const document_t& document, std::ostream& out, size_t position)
{
  out << std::string(position, ' ') << "<document>" << std::endl;
  for (const auto& obj : document) {
    draw(obj, out, position + 2);
  }
  out << std::string(position, ' ') << "</document>" << std::endl;
}
