#include "memory.hpp"

#include <cassert>
#include <iostream>

int main(){
  void *p = memory::malloc(64);
  void *pOld = p;
  memory::free(p);
  p = memory::malloc(64);
  assert(p == pOld);

  for(int c = 16; c < 256; c += 16){
    p = memory::malloc(c);
    memory::free(p);
  }

  std::cout << "All tests passed!\n";

  return 0;
}
