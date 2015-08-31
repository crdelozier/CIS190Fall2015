Hello World!
==========

* First example, the canonical [Hello World! (hello.c) program](hello.c).

``` c
#include <stdio.h>

int main(void) {
    printf("Hello World!\n");
    return 0;
}
```

* C is a *procedural* language.  Unlike object-oriented languages like C++ and
  Java C programs are merely a collection of functions.  There are data structures
  (structs), but they only store data and have no associated methods.

* `#include <stdio.h>` includes the *function prototype* or *header* for
  `printf` which prints a string to the console.  Note that `printf` does not
  include a newline character automatically so we must manually enter it.

* The signature for `main` states that `main` takes no arguments (i.e.,
  `void`) and returns an `int`.  The return value corresponds to the program's
  exit code which is used to signal to other programs if the program terminated
  successfully or failed in some way.

  + Note that in C using `void` is identical to specifying nothing within
    the parenthesis for *function definitions*.  According to the C
    standard, `void` is required for function prototypes, i.e., forward
    declarations of a function's parameters and return type without its
    corresponding function body.  However, most compilers will accept empty
    parenthesis in either situation without complaint.

* Main takeaways from this example:
  * "main" - You'll need it in every executable that you produce
  * printf - Used to output to the command-line

* Next, let's look at how to pass arguments to the program from the command-line.

``` c
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    if (argc == 2) {
        int val = atoi(argv[1]);
        if (val == 100) {
            printf("That's a good number!\n");
        } else {
            printf("%d is a bad number!\n", val);
        }
    }
    return 0;
}
```

* Here we actually process the arguments passed in from the user (after
  verifying they indeed pass an argument in addition to the name of the
  program).

  * To process the argument we use the `atoi` function (i.e., ascii string
    **to** integer) which is declared in ```stdlib.h``` header which
    contains a variety of essential functions such as the type converters like
    `atoi` and others.

  * The argument `argv` is a two-dimensional array of characters.  If you're 
    not already familiar with two-dimensional arrays from another language
    ,like Java, ignore it for now.  We will cover arrays in the next few
    sections.

  * In this example, we use a format string as the argument to `printf`.
    This function accepts a string that contains special format placeholders, 
    such as `%d`.  These format placeholds tell the printf function to 
    expect a certain type of data to be printed.  In this case, `%d` tells 
    the function to expect an integer.  This function can be dangerous 
    if the data-types specified in the format string do not match 
    the number or types of the arguments to the function.  The `printf`
    function will blindly attempt to print the arguments as the data-types
    specified in the format string, possibly causing it to perform unsafe
    actions.

* Main takeaways from this example:
  * argc and argv for command-line arguments
  * printf format specifiers and the dangers of getting them wrong

C data types
------------

* When designing programs, we describe the real-world data that we work with
  using various *types* that our programming language provides.  For example,
  the collection of students in a class can be represented as a list of strings
  (each string denoting a student's name) or the actors in a simulation can be
  represented as a collection of different objects in an (object-oriented) class
  hierarchy.

* When using C, it pays not to only think of our data in these higher-level
  terms, but also at a lower-level, i.e., how C itself views types.

  * This is because to take advantage of the "close to the metal" nature of C,
    we must know what is going on underneath the hood

  * Also, many of the errors that we face as C programmers can be diagnosed as
    long as we have crisp model in our heads of how C executes.

Fundamental Datatypes
---------------------

* In C, *all data is a collection of bits interpreted in various ways*.  In
  fact, C only distinguishes data on two axes:

  * The datum's size, i.e., how many bytes is it, and
  * How do we interpret these bits?

* To explore the fundamental types in C, we can build a small program that
  inspects the sizes of each type as implmented in
  [basic_types.c](src/basic_types.c).

``` c
#include <stdio.h>

int main(void) {
    printf("%d\n",sizeof(char));
    printf("%d\n",sizeof(short));
    printf("%d\n",sizeof(int));
    printf("%d\n",sizeof(unsigned int));
    printf("%d\n",sizeof(long));

    printf("%d\n",sizeof(float));
    printf("%d\n",sizeof(double));

    return 0;
}
```

* There are only two primary interpretations of data in C: *integers* and
  floating-point* values.

* The standard `int` is 4 bytes (32 bits) on most modern machines and devices.
  We can access the value of the maximum integer by the `INT_MAX` constant
  defined in `limits.h`.

  * This value turns out to be `2^(32-1) - 1` which corresponds to the bit
    pattern of all `1`s except for a `0` in the most-significant digit.

  * This representation of integers is called
    (twos-complement)[http://en.wikipedia.org/wiki/Two's_complement] which makes
    implementation of basic numerical operations over these numbers easy.

  * As a result, `1 + INT_MAX` produces the bit pattern `10000000 ... 0`.
    Interpreting this in twos-complement results in the *most-negative* integer
    possible.  This is an example of *arithmetic overflow*.

  * If we know we do not need negative integer values, we can tell C to
    *interpret* the bits not in two's complement but as a standard binary number
    thus reclaiming the sign bit as an additional digit) by using the `unsigned`
    modifier.  Note that the size of the integer type does not change with
    `unsigned`, only the *interpretation* of the bit pattern changes!  Note: 
    `unsigned` can be used to modify any integer data type (e.g. `unsigned char`).

* `long` and `short` are modifiers on the primitive types to change sizes but
   not their interpretation.

* `char` is defined to be the smallest addressable chunk of memory on the
  underlying hardware, i.e., 1 byte.  This comes from the fact that we represent
  individual characters in C using the
  [ASCII](http://en.wikipedia.org/wiki/Ascii) encoding which assigns the values
  0-255 to different characters in the English alphabet along with other
  symbols.

  * Because `char` is a single byte, you frequently see `char` used to represent
    raw byte arrays, e.g., `char buf [100]` declares an array of size 100 bytes
    on the stack.

* The floating point numbers are represented using the [IEEE standard for
  floating-point arithmetic](http://en.wikipedia.org/wiki/IEEE_floating_point)
  which defines how floats are represented with bit strings as well as
  requirements on how operations over those floats should behave.

* Main takeaways from this example:
  * Basic data-types: ints and floats and chars
  * unsigned vs. signed and integer overflow
  * char is a byte

C-String
-----------

* There is no "String" data-type in C.  Instead, we use arrays of characters 
  to construct strings.

```
#include <stdio.h>

int main(){
    char str[] = "Hello world!";
    printf("%s\n",str);
    return 0;
}
```
* C-strings are null terminated.  They must end with the character '\0', 
  or functions that use C-strings will not behave correctly.

* Since C-strings are simple arrays of characters, you cannot compare them 
  using "==" or use other mathematical operators on them.  Instead, you will
  need to use the functions provided by the "string.h" header file.