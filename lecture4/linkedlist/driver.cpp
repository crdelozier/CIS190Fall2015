#include "list.hpp"

#include <iostream>

int main(){
  list *l = new list;
  list_init(l);

  list_insert(l,5);
  list_insert(l,10);
  list_insert(l,15);
  list_insert(l,20);
  list_insert(l,25);

  std::cout << "List length: " << list_length(l) << "\n";
  list_print(l);

  return 0;
}
