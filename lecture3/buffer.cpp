#include <iostream>

int main(){
  int size = 10;
  int *A = new int[size];

  for(int c = 0; c < 20; c++){
    A[c] = c + 1000000;
  }

  return 0;
}
