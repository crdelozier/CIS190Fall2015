#include <cstdlib>
#include <iostream>
#include <cassert>

void do_stuff(int *A, int c, int N){
#ifdef CHECKS
    assert(A != nullptr);
    assert(c < N);
#endif
    A[c] = c;
}

int main(int argc, char **argv){
  if(argc != 2){
    std::cout << "Usage: " << argv[0] << " [size]\n";
    return 1;
  }

  int N = atoi(argv[1]);
  int *A = new int[N];

  for(int c = 0; c < N; c++){
    do_stuff(A,c,N);
  }

  delete [] A;

  return 0;
}
