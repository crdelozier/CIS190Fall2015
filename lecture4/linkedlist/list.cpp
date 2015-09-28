#include "list.hpp"

void list_init(list *l)
{
  l->_first = nullptr;
}

void list_insert(list *l, int value)
{
  node *new_node = new node;
  new_node->_data = value;
  new_node->_next = nullptr;

  if(l->_first == nullptr){
    l->_first = new_node;
    return;
  }

  node *current = l->_first;
  while(current->_next != nullptr){
    current = current->_next;
  }

  current->_next = new_node;
}

unsigned int list_length(list *l)
{
  node *current = l->_first;

  if(current == nullptr){
    return 0;
  }

  unsigned int count = 0;
  while(current != nullptr){
    count++;
    current = current->_next;
  }
  
  return count;
}

void list_print(list *l)
{
  node *current = l->_first;

  if(current == nullptr){
    std::cout << "Empty list!\n";
    return;
  }

  while(current != nullptr){
    std::cout << current->_data << "\n";
    current = current->_next;
  }
}
