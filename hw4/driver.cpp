#include <cstdlib>
#include <cassert>

#include <iostream>

int main(){
  void *p = nullptr;

  p = malloc(64);
  void *pOld = p;
  free(p);
  p = malloc(64);
  assert(p == pOld);

  void *sizes[10];
  sizes[0] = malloc(64);
  sizes[1] = malloc(16);
  sizes[2] = malloc(128);
  sizes[3] = malloc(32);
  sizes[4] = malloc(256);
  sizes[5] = malloc(512);
  sizes[6] = malloc(64);
  sizes[7] = malloc(1024);
  sizes[8] = malloc(8);
  sizes[9] = malloc(4096);

  for(int c = 0; c < 10; c++){
    p = malloc(128);
    assert(p != nullptr);
    free(p);
  }

  for(int c = 0; c < 10; c++){
    assert(sizes[c] != nullptr);
    free(sizes[c]);
  }

  std::cout << "All tests passed!\n";

  return 0;
}
