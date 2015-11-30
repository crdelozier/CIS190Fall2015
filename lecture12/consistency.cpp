#include <thread>
#include <iostream>

#include "barrier.hpp"

int A = 0;
int B = 0;
int Z = 0;

void thread1(barrier *bar){
  bar->wait();
  if(A == 0){
    B = 1;
  }
}

void thread2(barrier *bar){
  bar->wait();
  if(B == 0){
    A = 1;
  }
}

int main(){
  barrier bar(2);
  std::thread t1(thread1,&bar);
  std::thread t2(thread2,&bar);

  t1.join();
  t2.join();

  std::cout << "A: " << A << "\n";
  std::cout << "B: " << B << "\n";

  return 0;
}
