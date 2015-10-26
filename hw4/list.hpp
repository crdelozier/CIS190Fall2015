#pragma once

#include <new>
#include <cassert>

extern "C" void* get_memory_block(unsigned long size);
extern "C" void return_memory_block(void *p);

template <typename Value>
class list_node{
public:
  list_node<Value> *_next;
  Value _value;

  list_node() : _next(nullptr), _value() {}
};

template <typename Value>
class List{
  list_node<Value> *_first;

  list_node<Value>* alloc_node(){
    void *pos = get_memory_block(sizeof(list_node<Value>));
    list_node<Value> *new_node = new (pos) list_node<Value>();
    return new_node;
  }

public:
  bool empty(){
    return _first == nullptr;
  }

  Value& front(){
    assert(!empty());
    return _first->_value;
  }

  void pop_front(){
    assert(!empty());
    list_node<Value> *tmp = _first;
    _first = _first->_next;
    return_memory_block(tmp);
  }

  void push_back(Value& value){
    if(empty()){
      _first = alloc_node();
      _first->_value = value;
    }else{
      list_node<Value> *current = _first;
      while(current->_next != nullptr){
        current = current->_next;
      }
      current->_next = alloc_node();
      current->_next->_value = value;
    }
  }
};
