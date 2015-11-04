#pragma once

#include <cassert>

template <class T>
class ptr{
  T *_data;

public:
  ptr() : _data(nullptr) {}

  ptr(T *data) : _data(data) {
  }

  ptr(ptr& other) : _data(other._data) {
  }
 
  ptr(ptr&& other) : _data(other._data) {
  }

  ptr& operator=(ptr& other){
    _data = other._data;
    return *this;
  }

  ptr& operator=(ptr&& other){
    _data = other._data;
    return *this;
  }

  T& operator*(){
    assert(_data != nullptr);
    return *_data;
  }

  template <class S> 
  friend bool operator==(const ptr<S>& lhs, const ptr<S>& rhs);
  template <class S> 
  friend bool operator!=(const ptr<S>& lhs, const ptr<S>& rhs);
};

class Foo{
  int x;
  int y;

public:
  Foo(int _x, int _y) : x(_x), y(_y) {}
};

/// template <class Foo, int, int> ptr<Foo> new_ptr(int, int) {
// ptr<Foo> foo = new_ptr<Foo>(5,10);

template <class S, typename... Args>
ptr<S> new_ptr(Args... args){
  return ptr<S>(new S(args...));
}

template <class S>
bool operator==(const ptr<S>& lhs, const ptr<S>& rhs){
  return lhs._data == rhs._data;
}

template <class S>
bool operator!=(const ptr<S>& lhs, const ptr<S>& rhs){
  return !(lhs == rhs);
}
