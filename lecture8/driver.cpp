#include "ptr.hpp"
#include <iostream>

class Foo{
  ptr<int> p;

public:
  Foo() : p(new_ptr<int>()) {
    std::cout << "Foo()\n";
  }

  ~Foo(){
    std::cout << "~Foo()\n";
  }
};

class Bar{
  ptr<Foo> _foo;

public:
  Bar() : _foo(new_ptr<Foo>()) {
    std::cout << "Bar()\n";
  }

  ~Bar(){
    std::cout << "~Bar()\n";
  }
};

void takeBar(Bar bar){
}

int main(){
  Bar bar;
  Bar bar2 = bar;

  return 0;
}
