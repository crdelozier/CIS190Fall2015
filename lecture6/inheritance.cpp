#include <iostream>
#include <cstring>

namespace stuff{
class changeable{
public:
  virtual void change(int c) = 0;
};
}

using namespace stuff;
using namespace std;

class point : public changeable{
public:
  int x;
  int y;

  virtual void change(int c){
    x = c;
    y = c;
  }

  virtual void print() const {
    cout << "(" << x << "," << y << ")\n";
  }
};

class point3d : public point{
public:
  int z;

  virtual void print() const {
    std::cout << "(" << x << "," << y << "," << z << ")\n";
  }
};

class not_a_point{
public:
  double d;
};

void print_point(point *p){
  p->print();
}

void change(changeable *c){
  c->change(25);
}

int main(){
  const point * const p1 = new point;
  point * const p1 = new point;
  p1->x = 1;
  p1->y = 2;

  point3d * const p2 = new point3d;
  p2->x = 5;
  p2->y = 6;
  p2->z = 7;

  point3d *p3 = p2;

  change((changeable*)p1);
  change((changeable*)p2);

  print_point((point*)p1);

  // type t = (type)other;
  // type t = reinterpret_cast<type>(other);
  // type t = const_cast<type>(other);
  // type t = static_cast<type>(other);
  // type t = dynamic_cast<type>(other);
  print_point(p3);

  //p1 = static_cast<point*>(p2);

  //not_a_point *np = static_cast<not_a_point*>(p1);

  return 0;
}
