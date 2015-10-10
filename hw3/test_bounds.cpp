#include "array_ptr.hpp"

int main(){
  array_ptr a1 = new_array_ptr(10);

  for(int c = 0; c < 11; c++){
    a1[c] = c;
  }

  return 0;
}
