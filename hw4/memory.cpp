#include "memory.hpp"

#include <cassert>

extern "C" void* get_memory_block(unsigned long size);
extern "C" unsigned long get_block_size(void *block);

void* memory::malloc(unsigned long size)
{
  // TODO: Implement memory allocation using 
  // the primitives above and ListTree
  assert(false);
  return nullptr;
}

void memory::free(void *ptr)
{
  // TODO: Implement memory deallocation using
  // the primitives above and ListTree
  assert(false);
}
