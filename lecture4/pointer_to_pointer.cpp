#include <iostream>

typedef struct point_t{
  int x;
  int y;
  int z;
}point;

const int SUCCESS = 0;
const int NO_MEM = 1;
const int OTHER = 2;

int create_point(point **p){
  point *new_point = new point;

  if(*new_point == nullptr){
    return NO_MEM;
  }

  new_point->x = 0;
  new_point->y = 0;
  new_point->z = 0;

  *p = new_point;

  return SUCCESS;
}

int main(){
  int **ptp = new int*;
  int *p1 = new int;
  int *p2 = new int;
  int x = 5;

  *p1 = 1;
  *p2 = 2;
  
  *ptp = p1;
  *ptp = p2;
  
  std::cout << "Address: " << *ptp << ", Value: " << **ptp << "\n";

  delete ptp;
  delete p1;
  delete p2;

  point *p;
  
  if(!create_point(&p)){
    std::cout << "Created point\n";
  }else{
    return 1;
  }
  
  delete p;
  
  return 0;
}
