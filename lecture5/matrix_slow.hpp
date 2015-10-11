#pragma once

#include <cassert>

class IntMatrix{
  int **matrix;
  int N; // Only dealing with NxN matrices

public:
  IntMatrix(int _N) : N(_N){
    matrix = new int*[N];
    for(int i = 0; i < N; i++){
      matrix[i] = new int[N];
    }
  }

  ~IntMatrix(){
    for(int i = 0; i < N; i++){
      delete [] matrix[i];
    }
    delete [] matrix;
  }

  int& operator() (int x, int y){
    assert(x < N && y < N);
    return matrix[x][y];
  }
  
  IntMatrix& operator+=(const IntMatrix& rhs){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        matrix[i][j] += rhs.matrix[i][j];
      }
    }
    return *this;
  }

  friend IntMatrix& operator+(IntMatrix& lhs, const IntMatrix& rhs){
    return lhs += rhs;
  }
};
