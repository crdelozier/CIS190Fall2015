#include <cstdlib>
#include <iostream>

void f(){
  int *x = new int;
  delete x;
  return;
}

int main(){
  // void* malloc(size_t size);
  int *p = new int; // (int*)malloc(sizeof(int));
  int *a = new int[10]; // (int*)malloc(10 * sizeof(int));

  int **t = new int*[10];
  for(int c = 0; c < 10; c++){
    t[c] = new int[10];
  }

  for(int c = 0; c < 10; c++){
    delete [] t[c];
  }
  delete [] t;

  *p = 1;

  f();

  std::cout << *p << "\n";

  delete p; // free(p);
  delete [] a; // free(a);

  return 0;
}
