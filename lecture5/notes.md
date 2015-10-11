C structs
-----------

* C provides `structs` for grouping data-types together into a
  data structure.  However, since C is a procedural language and not an 
  object-oriented language, these data structures do not have any methods 
  associated with the data.  They are simply a convenient mechanism for 
  grouping related pieces of data.  The following example demonstrates how
  to declare and use structures. [structs.c](structs.c).

```
#include <stdio.h>

struct point_t{
    int x;
    int y;
};

int main(void){
    struct point_t p;
    p.x = 1;
    p.y = 2;

    printf("(%d,%d)\n",p.x,p.y);

    return 0;
}
```

* In this example, we declare a point structure with two integers (an x and 
  y coordinate).  This `struct` is simply a more convenient way to group 
  pieces of data together.

* As a matter of pragmatics, this bare `struct` definition is rarely what we
  want.  The reason for this is that whenever we want to use this `struct`,
  e.g., a local variable, we must qualify `point` with the `struct` keyword:
  `struct point p`.  This is because the `struct` definition doesn't define a
  type proper but a `struct`.

* Main takeaway from this example:
  * Struct syntax
  * Not object-oriented - No methods

* To define `point` as a type that we can use without qualification, we use
  `typedef` to create an alias for `struct point`.  In general, `typedef`s have
  the following form:

``` c
typedef int error_code;
```

* This example `typedef` defines `error_code` as an alias for `int`.  Therefore
  `error_code` can be used where ever we expect an `int`.  This is useful as a
  point of documentation to have an `error_code` type that is really an `int`.

* We also use `typedef` to bring a `struct` into the type world.  For example,
  in [point.h](src/point.h) we combine `typedef` and `struct` as follows:

``` c
typedef struct point {
    int x;
    int y;
} point;
```

* While it looks redundant, this has the effect of making `point` an alias for
  `struct point` which allows us to use `point` as a type throughout our code.

C++ Classes
-----------

* C++ provides a richer abstraction than structs in classes.  Classes accomplish 
the same goal as structs of grouping data, but they also allow methods to be
grouped with their associated data.

* For example, we might have a "point" struct in a C program that stores the x and 
  y coordinates of a point.  If we want to provide any functionality for this point 
  struct, we would need to define functions that work with a pointer to a point.

``` c
#include <stdlib.h>
#include <stdio.h>

typedef struct point{
    int x;
    int y;
} point;

void init_point(point *p, int x, int y){
    p->x = x;
    p->y = y;
}

void print_point(point *p){
    printf("(%d,%d)\n",p->x,p->y);
}

int point_manhattan_distance(point *p1, point *p2){
    return abs(p1->x - p2->x) + abs(p1->y - p2->y);
}

void add_point(point *p1, point *p2){
    p1->x += p2->x;
    p1->y += p2->y;
}

int equals_point(point *p1, point *p2){
    return p1->x == p2->x && p1->y == p2->y;
}

int main(){
    point p1;
    point p2;
    point *p3 = (point*)malloc(sizeof(point));

    init_point(&p1,1,0);
    init_point(&p2,2,2);
    init_point(&p3,1,0);
    
    print_point(&p1);
    print_point(&p2);

    printf("Distance: %d\n",point_manhattan_distance(&p1,&p2));

    if(equals_point(&p1,&p3)){
        printf("Points are equal!\n");
    }

    add_point(&p1,&p2);

    print_point(&p1);

    free(p3);
    
    return 0;
}
```

* In C++, we can package these methods with the data, rather than having 
  separate functions.  This idiom generally leads to cleaner code and a less
  polluted function namespace.

Classes - Access Modifiers
-----------

* Like Java, C++ allows you to protect data from other pieces of code by 
  giving it an access modifier.  C++ provides 3 levels of access protection:
  public, protected, and private.

* public members are accessible anywhere outside of the class.  These members 
  can get read or written to without a getter or setter method.

* protected members can be accessed within the class or in any child classes.

* private members can only be accessed within the class.  The private modifier 
  is the default access modifier for class members.  For structs, the public 
  modifier is the default access specifier.

```
class Sample{
public:
    int x;

protected:
    int y;

private:
    int z;
};
```

* Note: Class members are only guaranteed to be ordered within memory within a 
  single access specifier.  In the above example, the compiler can place 
  x, y, and z in any order in memory that it chooses to.  In most cases, they 
  will still be placed in a natural order, but this is not guaranteed.  In general,
  your code should not assume any particular ordering for class and struct members.

* Classes can selectively give access to their private and protected members via 
  the "friend" keyword.  Both functions and classes can be friends of a class.  

```
#include <iostream>

class FloatVector{
    float x;
    float y;
    float z;

    friend void printVector(FloatVector);
    friend class FloatVectorFriend;
};

class FloatVectorFriend{
    float x;

public:
    void stealX(FloatVector fv){
        x = fv.x;
    }
};

void printVector(FloatVector fv){
    std::cout << "[" << fv.x << "," << fv.y << "," << fv.z << "]";    
}

int main(){
    FloatVector fv;
    FloatVectorFriend f;

    f.stealX(fv);
    printVector(fv);

    return 0;
}
```

Classes - Constructors and Initializer Lists
-----------

* Class constructors are used to initialize the members of a class.  The constructor
  is called every time that an object is created, either on the stack or on the 
  heap using "new".

* Note: A constructor is NOT called when an object is allocated using "malloc".

* Like other methods and functions in C++, constructors can be overloaded
  to provide different ways of initializing the class.  Usually, you will want 
  to provide a default constructor (with no arguments) that initializes all values
  to zero and at least one more constructor that allows the programmer to properly 
  initialize the fields of the object.

* For simple initialization, constructors can use initializer lists to specify a 
  default value for each member.

```
class IntListNode{
    IntListNode *next;
    int data;

public:
    IntListNode() : next(nullptr), data(0){
    }

    IntListNode(int d) : next(nullptr), data(d){
    }
};
```

* Classes can also define destructors, which release any resources held by 
  the object.  This might include memory allocated using new, open files, and 
  anything else that needs to be cleaned up.

```
class AutoDestroyer{
    int *member;
public:
    AutoDestroyer(){
        member = new int;
    }

    ~AutoDestroyer(){
        delete member;
    }
};
```

* When a class defines a destructor, it generally must also define a copy 
  constructor and an assignment operator.  The compiler will automatically 
  generate a copy constructor and assignment operator for every class.  However,
  as in the above example, the default copy constructor and assignment operators
  might not have the proper behavior.  If we blindly copy "member" to another
  object and try to delete the memory in both destructor calls, we will encounter
  a "double-free" error from the allocator.  Thus, we must define how to handle 
  copies of our object.

```
class AutoDestroyer{
    int *member;
public:
    AutoDestroyer(){
        member = new int;
    }

    ~AutoDestroyer(){
        delete member;
    }

    AutoDestroyer(AutoDestroyer &other){
        member = new int;
        
    }

    AutoDestroyer& operator= (AutoDestroyer &other){
        if (this != &other){
            *member = *other.member;
        }

        return *this;
    }
};

int main(){
    AutoDestroyer ad1;
    AutoDestroyer ad2;

    AutoDestroyer adCopy(ad1);

    ad2 = ad1;

    return 0;
}
```