#include <iostream>

// typedef <type to call something> <thing to call it>

typedef struct data{
  void (*fn)(char*);
}data;

void hello(char *name){
  std::cout << "Hello " << name << "\n";
}

void goodbye(char *name){
  std::cout << "Goodbye " << name << "\n";
}

int main(){
  data *d = new data;
  d->fn = hello;

  d->fn("Chris");

  delete d;
  
  long *p = new long;
  void (*fn2)(char*) = goodbye;
  *p = (long)fn2;
  
  d->fn("Chris");

  delete p;

  return 0;
}
