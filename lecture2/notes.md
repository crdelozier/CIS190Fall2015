Booleans in C
-----------

* Before we dive into pointers, we need to cover one more primitive "data-type"
  in C - booleans.

* As you may have noticed, there is no similar type to Java's `boolean` in C
  C does not explicitly provide a boolean type.

* Instead of providing an actual boolean type that holds either "true" or "false", 
  C treats integer values as booleans.  If a number of non-zero, it evaluates to 
  true.  If a number is zero, it evaluates to false.

``` c
#include <stdio.h>

int main() {
    int TRUE = 1;
    int FALSE = 0;

    if(TRUE){
        printf("This statement should print!\n");
    }

    if(FALSE){
        printf("This statement should not print.\n");
    }

    if(-500){
        printf("This statement should also print!\n");
    }

    printf("True: %d, False: %d\n",10 == 10, 2 == 5);

    return 0;
}
```

* In this example, we see that positive numbers and negative numbers are treated
  as "true", while zero is treated as "false".  We can also see from the output 
  that C and C++ will generally default to 1 as the value for true and 0 as the 
  value for false.

* C and C++ also treat integers as boolean expressions when used in for and while
  loops.

* Main takeaways from this example:
  * No explicit "boolean" type in C
  * Positive and negative numbers evaluate to "true"
  * Zero evaluates to "false"

``` c
#include <stdio.h>

int main() {
    // for(initialization; termination condition; increment)
    for(int c = 10; c > 0; c--){
        printf("%d,",c);
    }
    printf("\n");


    int d = 10;
    // while(condition)
    while(d){
        printf("%d,",d);
        d--;
    }
    printf("\n");

    int e = 10;
    do{
        printf("%d,",e);
        e--;
    }while(e);
    printf("\n");

    return 0;
}
```

* Main takeaways from this example:
  * Loop constructs in C and C++

* C++ introduces the `bool` type but also retains C's treatment of integers as 
  boolean values.

``` c
#include <iostream>

int main() {
    bool value = true | false;

    if(true){
        std::cout << "This statement should print!\n";
    }

    if(false){
        std::cout << "This statement should not print.\n";
    }

    std::cout << value << "\n";

    return 0;
}
```

C Arrays
-----------

* Like most languages, C also provides arrays.  In C, arrays can be either 
  stack-allocated or heap-allocated.  In future lectures, we'll cover the 
  difference and trade-offs between these two types of arrays.  In this 
  example, we examine how to declare a stack-allocated array in C.
  [simple_arrays.c](simple_arrays.c).

``` c
#include <stdio.h>

int main(void) {
    int arr [] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
```

* If you are familiar with Java, you have a leg up here as it is a *C-like*
  language.  Programming-in-the-small basics, e.g., variable declarations, basic
  types, for-loops, and arrays, all transfer with some minor differences:

  + The declaration of `arr` is the declaration of a *stack-allocated* array in
    C.  In Java, you would flip the position of the brackets and write `int[]
    arr = { 1, ..., 10 };`.  There is a subtle, yet very important distinction
    here in that the Java array is (always) *heap-allocated* which we will visit
    later in these notes.

  + Note that we declare `i` on a line separate from the head of the `for` loop.
    This is our first example of writing *safely standards compliant* code.  C
    compilers typically support many different versions of the C language.
    Typically the default compilation mode for most compilers is the *C89*
    version of the spec which says that all local variables must be declared at
    the top of the *scope blocks* they are declared in (i.e., each block
    enclosed by curly braces).  To be safe, we respect this rule, but if you
    know your compiler supports declaration of variable like in Java, e.g., C89
    with GNU extensions (the gcc default) or later versions of the standard, you
    can declare locals in the same places as you would in Java.

* Main takeaways from this example:
  * C array syntax
  * Stack allocation
  * Standards compliant code

A Mental Model for Memory in C and C++
-----------

* See Powerpoint Slides

gdb
-----------

* gdb is a debugger for C and C++ programs that can be used on most UNIX based
operating systems.

* For the following examples, we will be using this simple code found in debugging.cpp.

``` c
int f(int x){
  int y = 5;
  return x + y;
}

int main(){
  int x = 1;
  int y = 2;
  int z = 3;

  z = z + x;
  y = 2 * z;
  x = y + 1;

  return 0;
}
```

* To compile a program for use with gdb, the "-g" flag must be added to the 
compilation commands.  This flag instructs the compiler to add user-readable
symbols to the executable for function and variable names.

```
g++ -o debugging debugging.cpp -g
```

* Once the program has been compiled with the "-g" flag, it can be run 
using gdb.

```
gdb ./test
```

* Once the gdb prompt has loaded, the program can be started using the "run"
command.  The command-line output when gdb starts will look something like this.

```
GNU gdb (GDB; openSUSE 13.1) 7.6.50.20130731-cvs
Copyright (C) 2013 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-suse-linux".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://bugs.opensuse.org/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word".
..
Reading symbols from /mnt/eclipse/acg/users/delozier/git/cis190/CIS190/lecture2/debugging...done.
(gdb) run
```

* Simply running the program using a debugger is often not very useful.  Instead, 
we would like to be able to stop the program's execution at certain points 
to examine the program's state (the values of its variables).  We can do this by 
setting "breakpoints" for the debugger to use.  At each breakpoint, gdb will 
halt the execution of the program and return control to the user.

```
(gdb) break main
Breakpoint 1 at 0x4005e4: file debugging.cpp, line 2.
(gdb) break debugging.cpp:4
Breakpoint 2 at 0x4005f2: file debugging.cpp, line 4.
```

* First, we set a breakpoint at the start of the main function.  Next, we set a breakpoint
at line 4 in debugging.cpp.  gdb allows us to set breakpoints at specific line numbers or
at specific functions.  When we run the program, gdb will halt its execution at lines 2 and 
4.

* Once we've encountered a breakpoint in the program, we might want to know what the 
current state of the program is.  We can use the where (or backtrace), list, and 
print commands to print the current state of the program.

```
Breakpoint 1, main () at debugging.cpp:2
2         int x = 1;
(gdb) where
#0  main () at debugging.cpp:2
(gdb) list
1       int main(){
2         int x = 1;
3         int y = 2;
4         int z = 3;
5
6         z = z + x;
7         y = 2 * z;
8         x = y + 1;
9
10        return 0;
(gdb) print x
$1 = 0
```

* We can also advance the program's execution using the next, step, and continue 
commands.  "next" moves to the next line of code and avoids tracing into any function 
calls that are made.  On the other hand, "step" moves to the next line of code and will 
enter any functions that are called.  Finally, "continue" starts execution from the 
current line of code and continues until the next breakpoint or the end of the program.

```
Breakpoint 1, main () at debugging.cpp:7
7         int x = 1;
(gdb) next
8         int y = 2;
(gdb) next
9         int z = 3;
(gdb) next
11        z = z + x;
(gdb) next
12        y = 2 * z;
(gdb) next
13        x = y + 1;
(gdb) next
15        z = f(x);
(gdb) step
f (x=9) at debugging.cpp:2
2         int y = 5;
(gdb) continue
Continuing.
[Inferior 1 (process 32491) exited normally]
```

* The "quit" command exits the debugger and returns the user to the UNIX
command line.

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
#include <stdio.h>

int main(void){
    int x = 0;
    int *p = &x;

    *p = 1;

    printf("%d\n",x);

    return 0;
}
```

Null pointers
------------

* In the following example, we'll see a few ways in which pointers can cause
  errors in your C programs. [null_pointers.c](null_pointers.c)

```
#include <stdlib.h>

int main(void){
    int *p1;
    int *p2 = NULL;

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