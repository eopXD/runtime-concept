#include <iostream>
#include <ostream>
#include <string>
#include <vector>

//using object_t = int;

// extract actual implementation as a seperatre function 
void draw(const int& obj, std::ostream& out, size_t position)
{
  out << std::string(position, ' ') << obj << std::endl;
}

// create a actual class for object_t
class object_t
{
public:
  object_t(const int& x) : self_(x)
  { }

  friend void draw(const object_t& obj, std::ostream& out, size_t position)
  {
    draw(obj.self_, out, position);
  }
private:
  int self_;
};

using document_t = std::vector<object_t>;

void draw(const document_t& document, std::ostream& out, size_t position)
{
  out << std::string(position, ' ') << "<document>" << std::endl;
  for (const auto& obj : document) {
    draw(obj, out, position + 2);
  }
  out << std::string(position, ' ') << "</document>" << std::endl;
}
