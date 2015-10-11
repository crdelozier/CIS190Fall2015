#pragma once

class point{
  int x;
  int y;

public:
  point() : x(0), y(0){
  }

  point(int _x, int _y) : x(_x), y(_y){
  }

  int getX(){
    return x;
  }

  int getY(){
    return y;
  }

  void setX(int x){
    this->x = x;
  }

  void setY(int y){
    this->y = y;
  }

  void print();
  int manhattan_distance(point *other);
  void add(point *other);
  bool equals(point *other);
};

/* typedef 
struct point{
    int x;
    int y;
}
point;*/
