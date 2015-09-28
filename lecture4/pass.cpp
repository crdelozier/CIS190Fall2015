#include <iostream>

typedef struct point_t{
    long x;
    long y;
} point;

void by_value(point p){
    p.x = 1;
    std::cout << "by_value: " << p.x << "," << p.y << "\n";
}

void by_pointer(point *p){
    p->x = 1;
    std::cout << "by_pointer: " << p->x << "," << p->y << "\n";
}

void by_reference(point &p){
    p.y = 1;
    std::cout << "by_reference: " << p.x << "," << p.y << "\n";
}

int main(void){
    point p;
    
    p.x = 0;
    p.y = 0;
    
    by_value(p);
    std::cout << p.x << "," << p.y << "\n";

    by_pointer(&p);
    std::cout << p.x << "," << p.y << "\n";

    by_reference(p);
    std::cout << p.x << "," << p.y << "\n";

    return 0;
}
