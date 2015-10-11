#pragma once

#include <cassert>

class IntMatrix{
  int *matrix;
  int N; // Only dealing with NxN matrices

public:
  IntMatrix(int _N) : N(_N){
    matrix = new int[N * N];
  }

  ~IntMatrix(){
    delete [] matrix;
  }

  int& operator() (int x, int y){
    assert(x < N && y < N);
    return matrix[x*N + y];
  }
  
  IntMatrix& operator+=(const IntMatrix& rhs){
    for(int i = 0; i < N*N; i++){
      matrix[i] += rhs.matrix[i];
    }
    return *this;
  }

  friend IntMatrix& operator+(IntMatrix& lhs, const IntMatrix& rhs){
    return lhs += rhs;
  }
};
