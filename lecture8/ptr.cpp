#include "ptr.hpp"
#include <shared_ptr>

void takeLHS(ptr<int>& lhs){
  
}

void takeRHS(const ptr<int>& rhs){
  
}

void takePtr(ptr<int> p){
  
}

ptr<int> createPtr(){
  return new_ptr<int>();
}

int main(){
  ptr<int> p; //new_ptr<int>();
  ptr<int> x = createPtr();

  takePtr(x);

  takeLHS(p);
  takeLHS(x);
  takeRHS(createPtr());

  return 0;
}
