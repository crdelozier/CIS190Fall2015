#include <iostream>

int main(){
  int x = 0;
  char *p = (char*)&x; // new char[4];

  p[1] = 1;

  // What does this line print?
  std::cout << "x: " << x << "\n";

  return 0;
}
