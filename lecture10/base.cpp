#include <iostream>

class Base{
public:
 virtual void print(int x) {
    std::cout << x << "\n";
  }
};

class Derived : public Base{
public:
  virtual void print(float x) {
    std::cout << "Derived " << x << "\n";
  }
};
