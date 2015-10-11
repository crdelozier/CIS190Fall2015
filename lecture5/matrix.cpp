#include "matrix.hpp"

#include <cstdlib>
#include <iostream>

int main(int argc, char **argv){
  if(argc != 3){
    std::cout << "Usage: " << argv[0] << " matrix_size iterations\n";
    return 1;
  }

  int N = atoi(argv[1]);
  int iters = atoi(argv[2]);
  IntMatrix matrix(N);
  IntMatrix result(N);

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      matrix(i,j) = rand() % 10000;
      result(i,j) = 0;
    }
  }

  for(int c = 0; c < iters; c++){
    result += matrix;
  }

  return 0;
}
