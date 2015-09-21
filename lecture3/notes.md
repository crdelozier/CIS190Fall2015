Pointers
-----------

* Up to this point, most of the data-types that we have used have 
  directly stored the type of data specified.  For example, an int
  data-type directly declares and stores an integer.

* Pointers are used to hold the memory address of another piece of 
  data.  In the following program, we demonstrate how pointers can 
  be used to store the address and access the value of an integer
  allocated on the stack. [pointers.c](pointers.c)

```
#include <iostream>

int main(){
    int x = 0;
    int *p = &x;

    *p = 1;

    std::cout << x << "\n";

    return 0;
}
```
* The address-of (&) operator produces a pointer to the address of the 
variable or expression of the operand.  In the example above, the 
address-of operator yields the address of the local variable x.
This operator can also be used to find the address of a field of a
class or a particular array element (e.g. &arr[5]).

Null pointers
------------

* In the following example, we'll see a few ways in which pointers can cause
  errors in your C++ programs.

```
int main(){
    int *p1;
    int *p2 = nullptr;

    *p1 = 0;
    *p2 = 0;

    return 0;
}
```

* If we run this program with gdb (a C/C++ debugger), we'll see that the program 
  fails on the assignment to `p2`, but not on the assignment to `p1`.  `NULL` or 
  `0` is treated as a special value by most operating systems in that it cannot 
  be read or written.  Thus, when we try to dereference a pointer that points to 
  `NULL` on a Unix system, the system will kill the program with a Segmentation 
  Fault error.

* In Java, an attempt to assign into a reference that has not been initialized will 
  generate a `NullPointerException`.  However, in C, variables are not default initialized
  to any value and will simply contain whatever value was in memory at that address.
  These default values are often referred to as "garbage".  Dereferencing a pointer
  that contains "garbage" will lead to unexpected results because the address held 
  by the pointer could point to anything.  These errors are particularly dangerous
  because they are less likely than null-pointer dereferences to produce an error 
  like a Segmentation Fault.  It is important to always initialize pointers in your
  C programs to NULL.

void*
------------

* C provides the `void*` (void pointer) type in order to allow a programmer 
  to point to memory of an unknown type.  A void pointer cannot be dereferenced, 
  and therefore it must be type-cast to the (hopefully) correct type before
  using it.  A type-cast is of the form:

```
void *v;
int *p = (int*)v;
```

malloc()
------------

* The C programming language standard library provides the `malloc` (short
  for memory allocate) function.  `malloc()` is defined as shown below.

```
void* malloc(size_t size);
```

* As you can see, `malloc()` returns a void pointer.  So, the result of malloc
  must be cast to the correct type before using it.  Some versions of the 
  C programming language will allow implicit conversions from a void pointer
  to the specified pointer type, but it is a best practice to always cast
  the return value of malloc to the correct pointer type.

```
int *p = (int*)malloc(sizeof(int));
```

* Unlike allocating memory using `new` in Java, `malloc()` requires that the 
  programmer calculate the size, in bytes, of the allocated memory.  Thus, 
  when we want to allocate an integer, we need to pass the result of the 
  `sizeof()` function to `malloc()`.  If we instead want to allocate an 
  array of integers, we need to multiply the size of an integer by the 
  number of integers we want to allocate, as follows.

```
int *p = (int*)malloc(10 * sizeof(int));
```

* It is important to check the return value of `malloc()` to make sure 
  that it is not null.  If the return value is `NULL`, the system 
  has run out of memory and is unable to service the program's request.

```
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main(void){
    int *p = (int*)malloc(sizeof(int));
    assert(p != NULL);
    int *a = (int*)malloc(10 * sizeof(int));
    assert(a != NULL);
    int c = 0;

    for(c = 0; c < 10; c++){
        a[c] = c;
    }

    for(c = 0; c < 10; c++){
        *p += a[c];
    }

    printf("%d\n",*p);

    return 0;
}
```

* This example demonstrates using malloc to allocate both a single 
  integer and an array of integers.  The program then uses both the 
  singleton pointer dereference operator (`*`) and the array indexing 
  operator (`[]`) to access these allocations.  In most cases, you 
  should access arrays using the indexing operator.  However, in 
  some cases, pointer arithmetic can be useful.

* As shown below, we can rewrite the second for-loop to use pointer
  arithmetic instead of array indexing.

```
for(c = 0; c < 10; c++){
    *p += *a;
    a++;
}
```
* Each increment on the pointer `a` adds sizeof(int) to the address
  currently held by `a`, moving it to the next integer in memory.
  We can imaging that the heap looks something like the diagram below.

```
  Heap
  ------
      p    [  ]
a --> a[0] [  ]
      a[1] [  ]
      ...
      a[9] [  ]
```

* After an increment operation, the pointer a would move to the 
  next element in the array, like so.

```
  Heap
  ------
      p    [  ]
      a[0] [  ]
a --> a[1] [  ]
      ...
      a[9] [  ]
```

free()
------------

* As noted in the prior section, if the system runs out of memory, 
  `malloc()` will return a null pointer and possibly cause the program 
  to crash.  To prevent this failure case, the programmer must return 
  memory to the operating system when the program is finished using it.
  This can be accomplished by calling `free()` on a pointer to the 
  memory to be released.  `free()` has the following form.

```
void free(void* ptr);
```

* To demonstrate how to use free correctly, a modified version of the 
  malloc example is shown below with free inserted to return memory 
  to the operating system.

```
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main(void){
    int *p = (int*)malloc(sizeof(int));
    assert(p != NULL);
    int *a = (int*)malloc(10 * sizeof(int));
    assert(a != NULL);
    int c = 0;

    for(c = 0; c < 10; c++){
        a[c] = c;
    }

    for(c = 0; c < 10; c++){
        *p += a[c];
    }

    printf("%d\n",*p);

    free(p);
    free(a);

    return 0;
}
```

new and delete
------------

* C++ provides the "new" and "delete" functions to replace the C-style
"malloc" and "free" functions.  Instead of returning an untyped pointer, 
the C++ "new" function returns a typed pointer that matches the allocated
type.

* Unlike "free", which only has a single form, "delete" has a different
form for singletons and arrays.  Singleton objects (e.g. those allocated
with "new") must be deallocated using "delete".  Arrays (e.g. those allocated
with "new []") must be deallocated using "delete []".  If an array 
is deallocated using "delete", only 1 of the array elements will be reclaimed, 
which is a "memory leak".  Memory leaks can lead to an eventual system crash
due to a lack of free memory.

Memory Safety
------------

* Manual memory management is often prone to bugs.  The most common of these bugs are
  buffer overflow and use-after-free errors.

* Buffer overflows occur when memory outside of the allocated region is accessed.  An 
  example is shown below.

```
int main(void){
    int *a = new int[10];
    int c = 0;

    for(c = 0; c < 100; c++){
        a[c] = c;
    }

    return 0;
}
```

* In this example, we allocate an array of size 10, but then attempt to access
  100 elements of that array.  This example is not particularly dangerous, but 
  if other data had been allocated after the 10 element array, the writes to elements
  10 through 99 would be overwriting other memory.

* When we run this program, it is possible (and even likely) that the program will 
  not crash.  This is because C does not check for out-of-bounds errors like Java 
  does.  Although this is faster, it can lead to dangerous security vulnerabilities
  and hard to track down bugs.  To prevent these sorts of errors, it is recommended 
  that you run a tool like valgrind to find any possible memory safety errors in your
  programs.  We will cover this tool later in the bootcamp.

* The other common memory safety error is use-after-free.  This error is shown in the 
  following example.

```
int main(){
    int *p = new int;
    delete p;

    *p = 5;

    return 0;
}
```

* In this example, we allocate an integer and then immediately free it.  However, we 
  access the integer after it has been freed.  Again, this is not particularly bad in 
  this program, but in other programs, it is possible that the freed memory will be
  reallocated by the operating system.  If this occurs, the access to the freed memory 
  will overwrite memory that it should not overwrite.

Pointers-to-Pointers and Pointers-to-Pointers-to-Pointers
-----------

* Pointers can be used to provide an arbitrary level of indirection.  For example, 
  if we want to be able to indirectly change the address pointed to by a pointer, 
  we can use a pointer to a pointer.  A pointer to a pointer holds the address 
  of a pointer, instead of the address of some data.

``` c
#include <iostream>

int main(){
    int **ptp = new int*;
    int *p1 = new int;
    int *p2 = new int;

    *p1 = 1;
    *p2 = 2;

    *ptp = p1;
    *ptp = p2;
    
    std::cout << "Address: " << *ptp << ", Value: " << **ptp << "\n";

    delete ptp;
    delete p1;
    delete p2;

    return 0;
}
```

* Note that in the above example we delete the pointer to the pointer first because
  we don't want to leave a dangling pointer in the pointer to a pointer.

* Pointer to pointers can also we used to manage two-dimensional arrays in C++.

``` c
int main(){
    int **twod - new int*[10];

    for(int c = 0; c < 10; c++){
        twod[c] = new int[10];
    }

    ...

    for(int c = 0; c < 10; c++){
        delete [] twod[c];
    }
    delete [] twod;

    return 0;
}
```

* As you can see, we need to allocate an array of pointers and then 
  allocate an array for each one of those pointers.

* Similarly, we need to delete each internal array and then the outer array.

Mental Model of Memory (now with heaps!)
-----------

* See powerpoint slides.
