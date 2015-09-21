#include <iostream>

int main(){
  int x = 0;
  int *p = &x;
  int *null_pointer = nullptr; // int *
  //int *null_pointer = NULL; // NULL == 0
  
  *p = 1;

  std::cout << x << "\n";
  std::cout << p << "\n";

  return 0;
}
