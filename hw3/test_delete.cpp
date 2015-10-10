#include "ptr.hpp"

int main(){
  ptr p = new_ptr();
  delete_ptr(p);

  *p = 3;

  return 0;
}
