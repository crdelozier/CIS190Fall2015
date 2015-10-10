#include <iostream>

void f(int **ptp){
  // PRINT y (from the main function) HERE
}

int main(){
  int x = 1;
  int y = 2;
  int *p = &x;

  f(&p);

  return 0;
}
