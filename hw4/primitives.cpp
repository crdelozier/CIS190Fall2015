#include <dlfcn.h>
#include <cassert>

extern "C"{

void* get_memory_block(unsigned long size)
{
  static void* (*original_malloc)(unsigned long) = nullptr;
  if(original_malloc == nullptr){
    original_malloc = (void* (*)(unsigned long))dlsym(RTLD_NEXT,"malloc");
    assert(original_malloc != nullptr);
  }
  void *block = original_malloc(size + sizeof(unsigned long));
  unsigned long *size_ptr = (unsigned long*)block;
  *size_ptr = size;
  block = (void*)(size_ptr+1);
  return block;
}

void return_memory_block(void *p)
{
  static void (*original_free)(void*) = nullptr;
  if(original_free == nullptr){
    original_free = (void (*)(void*))dlsym(RTLD_NEXT,"free");
    assert(original_free != nullptr);
  }
  unsigned long *size_ptr = (unsigned long*)p;
  size_ptr--;
  original_free((void*)size_ptr);
}

unsigned long get_block_size(void *block)
{
  unsigned long *size_ptr = (unsigned long*)block;
  size_ptr--;
  return *size_ptr;
}

}
