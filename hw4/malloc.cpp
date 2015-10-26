#include "memory.hpp"

extern "C"{

void* malloc(unsigned long size)
{
  return memory::malloc(size);
}

void free(void* ptr)
{
  memory::free(ptr);
}

}
