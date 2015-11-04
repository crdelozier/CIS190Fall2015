#pragma once

#include <cassert>

template <class T>
class ptr{
  T *_data;

  ptr(T *data) : _data(data) {}
public:
  ptr() : _data(nullptr) {}

  ~ptr(){
    if(_data != nullptr){
      delete _data;
    }
  }

  ptr(ptr& other) : _data(other._data) {
    other._data = nullptr;
  }
 
  ptr(ptr&& other) : _data(other._data) {
    other._data = nullptr;
  }

  ptr& operator=(ptr& other){
    _data = other._data;
    other._data = nullptr;
    return *this;
  }

  ptr& operator=(const ptr& other){
    _data = other._data;
    return *this;
  }

  T& operator*(){
    assert(_data != nullptr);
    return *_data;
  }

  template <class S> friend ptr<S> new_ptr();

  template <class S> 
  friend bool operator==(const ptr<S>& lhs, const ptr<S>& rhs);
  template <class S> 
  friend bool operator!=(const ptr<S>& lhs, const ptr<S>& rhs);
};

template <class S>
ptr<S> new_ptr(){
  return ptr<S>(new S);
}

template <class S>
bool operator==(const ptr<S>& lhs, const ptr<S>& rhs){
  return lhs._data == rhs._data;
}

template <class S>
bool operator!=(const ptr<S>& lhs, const ptr<S>& rhs){
  return !(lhs == rhs);
}
