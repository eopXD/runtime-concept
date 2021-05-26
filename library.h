#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <memory>

//using object_t = int;

// extract actual implementation as a seperate function
void draw(const int& obj, std::ostream& out, size_t position)
{
  out << std::string(position, ' ') << obj << std::endl;
}

// Create a actual class for object_t. Rewrite object with PIMPL idiom
// indirection allows underlying private implementation to change and
// don't need to compile for the original object.
class object_t
{
public:
  object_t(int x) : self_(new int_model_t(std::move(x)))
  { std::cout << "ctor\n"; }
  object_t(const object_t& x) : self_(new int_model_t(*x.self_))
  { std::cout << "copy\n"; }
  object_t(object_t&& x) : self_(std::move(x.self_))
  { std::cout << "move\n"; }

  object_t& operator=(const object_t& x)
  {
    std::cout << "copy assignment\n";
    object_t tmp(x);
    this->self_ = std::move(tmp.self_);
    return *this;
  }
  object_t& operator=(object_t&& x)
  {
    std::cout << "move assignment\n";
    this->self_ = std::move(x.self_);
    return *this;
  }


  friend void draw(const object_t& obj, std::ostream& out, size_t position)
  {
    obj.self_->draw(out, position);
  }
private: // private implementaion (PIMPL)
  struct int_model_t
  {
    int_model_t(int x) : data_ (std::move(x))
    { }
    // this method gives caller interface, no underlying data exposed.
    void draw(std::ostream& out, size_t position) const
    {
      ::draw(data_, out, position);
    }
    int data_;
  };
private:
// we create data on the heap
  std::unique_ptr<int_model_t> self_;
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
