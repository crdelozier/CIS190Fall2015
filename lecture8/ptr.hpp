#pragma once

#include <cassert>

template <class T>
class ptr{
  T *_data;

  ptr(T *data) : _data(data) {
  }
public:
  ptr() : _data(nullptr) {}

  ~ptr(){
    if(_data != nullptr){
      _data->decrement();
      if(*_count == 0){
        delete _data;
        delete _count;
      }
    }
  }

  ptr(ptr& other) : _data(other._data), _count(other._count) {
    _data->increment();
  }
 
  ptr(ptr&& other) : _data(other._data), _count(other._count) {
    _data->increment();
  }

  void swap(ptr& rhs){
    T *tmp = _data;
    _data = rhs._data;
    rhs._data = tmp;
    int *tmpcount = _count;
    _count = rhs._count;
    rhs._count = _count;
  }

  ptr& operator=(ptr& other){
    ptr(other).swap(*this);
    return *this;
  }

  ptr& operator=(ptr&& other){
    ptr(other).swap(*this);
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
