#include <cstdlib>
#include <iostream>

#include "points.h"

void point::print(){
  std::cout << "(" << x << "," << y << ")\n";
}

int point::manhattan_distance(point *other){
  return abs(x - other->x) + abs(y - other->y);
}

void point::add(point *p2){
    x += p2->x;
    y += p2->y;
}

bool point::equals(point *p2){
    return x == p2->x && y == p2->y;
}
