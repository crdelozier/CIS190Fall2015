#pragma once

#include <cstring>
#include <type_traits>

namespace cis{

template <class T, unsigned int N, 
          bool Copyable = 
          std::is_copy_constructible<T>::value >
class array{
  T data[N];

public:
  array(array& other){
    for(int c = 0; c < N; c++){
      data[c].copy(other.data[c]);
    }
  }

  T& operator[] (unsigned int index){
    assert(index < N);
    return data[index];
  }
};

template <class T, unsigned int N>
class array<T,N,true>{
  T data[N];

public:
  array(array& other){
    memcpy((void*)data,(void*)other.data,
           N * sizeof(T));
  }
};

}
