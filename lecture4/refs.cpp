#include <iostream>

void changePointer(int **p){
  int y = 2;
  std::cout << "Pointer addr: " << (void*)p << "\n";
  *p = &y;
  std::cout << "Pointer addr: " << (void*)p << "\n";
}

void changeReference(int &r){
  int y = 2;
  std::cout << "Reference addr: " << (void*)&r << "\n";
  r = y;
  std::cout << "Reference addr: " << (void*)&r << "\n";
}

void printInt(int &r){
  std::cout << r << "\n";
}

typedef struct point_t{
  int x;
  int y;
} point;

int main(){
  int x = 0;
  int y = 1;

  int& r = x; // r = &x;
  r = y; // *r = y;

  int *p2 = &x;
  p2 = &y;

  point p;

  point *ptp = &p;
  ptp->x = 1; // (*ptp).x = 1;
  ptp->y = 2;

  point& rp = p;
  rp.x = 1;
  rp.y = 2;

  changePointer(p2);
  std::cout << "x: " << x << "\n";
  changeReference(x);
  std::cout << "x: " << x << "\n";

  return 0;
}
