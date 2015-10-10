#pragma once

#include <cassert>

class ptr{
  int *_data;

  ptr(int *data) : _data(data) {}
public:
  ptr() : _data(nullptr) {}

  // TODO: Implement copy constructors
  // TODO: Implement assignment operators

  // TODO: Implement dereference operator

  friend ptr new_ptr();
  friend void delete_ptr(ptr& p);

  // TODO: Implement operator==
  // TODO: Implement operator!=
};

ptr new_ptr(){
  return ptr(new int);
}

void delete_ptr(ptr& p){
  // TODO: Deallocate using delete and set to null
}
