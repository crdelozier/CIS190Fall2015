#include <iostream>

int *p;

int f(){
  int x = 0;
  p = &x;
}

int g(){
  int y = 1;
  *p = 2;
  std::cout << "y: " << y << "\n";
}

int main(){
  f();
  g();

  return 0;
}
