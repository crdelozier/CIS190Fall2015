#include <iostream>

int main(){
  int i = -256; // 32-bits, 4 bytes
  unsigned int u = 512;

  u = i;

  short s = 25; // 16-bits, 2 bytes

  long l = 235251; // 64-bits, 8 bytes

  char c = 'X'; // 8-bits, 1 byte

  char name[100];
  char zipped_data[1024];

  for(int c = 0; c < 100; c++){
    name[c] = c+1;
  }

  for(auto x : name){
    std::cout << x;
  }

  float f = 2.5;

  // A LOT MORE CODE

  //for(std::vector<class_name>::iterator it = v.begin(), end = v.end(); it != end; ++it){
  //  decltype(it) position = it;
  //}
  //for(auto it = v.begin(), end = v.end(); it != end; ++it){
  //}
  for(auto x : v){
  }

  auto a = i; // typeof(a) -> int
  decltype(a) b = a + f;

  std::cout << u << "\n";

  return 0;
}
