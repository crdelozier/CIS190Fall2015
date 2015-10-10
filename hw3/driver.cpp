#include "ptr.hpp"
#include "array_ptr.hpp"

#include <iostream>
#include <cassert>

int main(){
  ptr p1 = new_ptr();
  ptr p2 = new_ptr();

  *p1 = 5;
  *p2 = 5;

  assert(*p1 == *p2);

  ptr p3(p1);

  assert(*p1 == *p3);

  array_ptr a1 = new_array_ptr(20);

  for(int c = 0; c < 20; c++){
    a1[c] = c;
  }

  // TODO: Add additional tests

  delete_ptr(p1);
  delete_ptr(p2);

  delete_array_ptr(a1);

  std::cout << "All tests passed!\n";

  return 0;
}
