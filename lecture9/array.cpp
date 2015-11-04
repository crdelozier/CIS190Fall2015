#include <cassert>
#include <iostream>

#include "array.hpp"

int main(){
  using namespace cis;

  array<int,10> a;
  int count = 0;

  for(int& x : a){
    x = count;
    count++;
  }

  for(auto it = a.begin(), 
        end = a.end(); it != end; it++){
    *it = count;
    count++;
  }

  return 0;
}
