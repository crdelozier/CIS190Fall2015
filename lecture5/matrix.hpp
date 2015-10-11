#pragma once

#include <cassert>

class IntMatrix{
  int N; // Only dealing with NxN matrices
  int *matrix; 

public:
  IntMatrix(int _N) : N(_N), matrix(new int[N * N]){
  }

  ~IntMatrix(){
    delete [] matrix;
  }

  IntMatrix(IntMatrix &other) : N(other.N), matrix(other.matrix){
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

  friend IntMatrix& operator+(IntMatrix lhs, const IntMatrix& rhs){
    return lhs += rhs;
  }
};
