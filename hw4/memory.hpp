#pragma once

#include "tree.hpp"

class memory{
public:
  static void* malloc(unsigned long size);
  static void free(void *ptr);
};
