#include "tree.hpp"

#include <iostream>
#include <cstdlib>
#include <cassert>

void *get_memory_block(unsigned long size){
  return malloc(size);
}

void return_memory_block(void *p){
  free(p);
}

int main(){
  ListTree<int,unsigned long> tree;

  tree.insert(5,20);
  tree.insert(5,25);
  tree.insert(10,10);
  tree.insert(2,3);
  tree.insert(10,63);

  assert(tree.retrieve(5) == 20);
  assert(tree.retrieve(10) == 10);
  assert(tree.retrieve(10) == 63);
  assert(tree.retrieve(2) == 3);
  assert(tree.retrieve(10) == 0);

  std::cout << "All tests passed!\n";

  return 0;
}
