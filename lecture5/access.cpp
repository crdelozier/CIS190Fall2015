#include <iostream>

class Sample{
public:
  int x;
  
  Sample() : x(1), y(2), z(3){}

  void test(Sample &sample){
    sample.y = 0;
    sample.z = 0;
  }
  
protected:
  int y;
  
private:
  int z;
};

int main(){
  Sample sample;
  Sample sample2;

  int *p = &sample.x;
  p += 2;

  sample.y = 5;

  std::cout << *p << "\n";

  sample.test(sample2);

  return 0;
}
