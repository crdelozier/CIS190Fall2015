#pragma once

#include "tree.hpp"

class memory{
  // TODO: Add a ListTree that contains the free memory blocks

public:
  static void* malloc(unsigned long size);
  static void free(void *ptr);
};
