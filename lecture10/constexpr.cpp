#include <iostream>

template <int n>
class Test{
public:
  constexpr int value() const {
    return n;
  }
};

#define SHIFT_N(n) (n * (1 << n))

constexpr int N = 25;

constexpr int shift_fn(int n){
  return 1 << n;
}

constexpr int multiply_n(int n){
  return n * shift_fn(n);
}

int main(){
  Test<SHIFT_N(5)> t1;
  Test<multiply_n(5)> t2;
  Test<N> t3;

  int A[N];
  int A[SHIFT_N(10)];

  std::cout << t1.value() << "\n";
  std::cout << t2.value() << "\n";

  return 0;
}
