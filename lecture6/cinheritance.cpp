#include <iostream>

typedef struct point_t{
  int x;
  int y;
} point;

typedef struct point_3d_t{
  int x; // point p.x
  int y; // point p.y
  int z;
} point3d;

void print_point(point *p){
  std::cout << p->x << "," << p->y << "\n";
}

int main(){
  point p1;
  p1.x = 1;
  p1.y = 2;

  point3d p2;
  p2.x = 5;
  p2.y = 6;
  p2.z = 7;

  print_point(&p1);
  print_point((point*)&p2);

  return 0;
}
