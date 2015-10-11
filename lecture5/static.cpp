#include <iostream>

class Foo{
public:
  static int x;

  static void setX(int new_value);
};

int Foo::x = 0;

void Foo::setX(int new_value){
  x = new_value;
}

void print_int(int x){
  static int value = 0;
  int value2 = 0;
  std::cout << "Value: " << value << "\n";
  value = x;
}

int main(){
  print_int(5);
  print_int(10);
  print_int(15);

  Foo::x = 5;
  Foo::setX(6);

  return 0;
}
