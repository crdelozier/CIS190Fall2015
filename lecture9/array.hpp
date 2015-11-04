#pragma once

#include <cstring>
#include <type_traits>

namespace cis{

template<class T> class array_iterator;

template <class T, unsigned int N>
class array{
  T data[N];

public:
  T& operator[] (unsigned int index){
    assert(index < N);
    return data[index];
  }

  array_iterator<T> begin(){
    return array_iterator<T>(&data[0]);
  }

  array_iterator<T> end(){
    return array_iterator<T>(&data[N]);
  }
};

template<class T>
class array_iterator{
  T *_p;

public:
  array(T *p) : _p(p) {}

  array& operator++(){
    _p++;
    return *this;
  }
  
  T& operator*(){
    return *_p;
  }
};

}
