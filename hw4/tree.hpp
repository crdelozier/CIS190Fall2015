#pragma once

#include "list.hpp"
#include <new>

extern "C" void* get_memory_block(unsigned long size);

template <typename Key, typename Value>
class node{
public:
  node<Key,Value> *_left;
  node<Key,Value> *_right;
  Key _key;
  List<Value> _values;

  node() : _left(nullptr), _right(nullptr), _key(), _values() {}

  static node<Key,Value>* alloc_node(){
    void *pos = get_memory_block(sizeof(node<Key,Value>));
    node<Key,Value> *new_node = new (pos) node<Key,Value>();
    return new_node;    
  }
};

// TODO: Rename template parameters to something meaningful
template <typename S, typename T>
class ListTree{
  // TODO: Ensure that ListTree is not copy-able or assign-able

public:

  ListTree() {
    // TODO: Implement constructor and/or initializer list
  }

  ~ListTree(){
    // TODO: Implement destructor
  }

  /*
   * Insert a value into the tree at a specified key
   * At each node, if the key is smaller than the key
   * stored in the node, go to the left.  
   * If it's larger, go to the right.
   */
  void insert(S key, T value){
    // TODO: Implement insert
  }

  /*
   * Find the value in the tree that is closest to but 
   * larger than the requested value
   */
  T retrieve(S key){
    // TODO: Implement retrieve

    // Return the default value if nothing there
    return T();
  }
};
