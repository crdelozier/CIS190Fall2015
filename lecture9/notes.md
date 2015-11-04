Type Traits
-----------

* The Boost type traits library provides functionality for 
  examining types.  As discussed earlier in the course, template
  specialization and partial template specialization allow a 
  programmer to write special code for a function or class for
  specified types.

* Boost's type traits library provides many different templates
  that can be used for template specialization.

```
#include <iostream>
#include <boost/type_traits.hpp>

class Foo{
};

class Bar{
public:
  Bar(){
    std::cout << "In Bar constructor\n";
  }
};

int main(){
  std::cout << boost::is_void<void>::value << "\n"; // True
  std::cout << boost::is_void<Foo>::value << "\n"; // False

  std::cout << boost::is_pointer<Foo>::value << "\n"; // False
  std::cout << boost::is_pointer<Foo*>::value << "\n"; // True

  std::cout << boost::is_unsigned<int>::value << "\n"; // False
  std::cout << boost::is_unsigned<unsigned int>::value << "\n"; // True

  std::cout << boost::has_trivial_constructor<Foo>::value << "\n"; // True
  std::cout << boost::has_trivial_constructor<Bar>::value << "\n"; // False

  return 0;
}
```

* In the above example, we check a few types for the properties "is_void", 
  "is_pointer", "is_unsigned", and "has_trivial_constructor".

* The Boost type traits library contains many other properties of types 
  that can be checked.  The full listing can be found here:
  http://www.boost.org/doc/libs/1_58_0/libs/type_traits/doc/html/index.html

enable_if
-----------

* enable_if provides the ability to choose a template based off of 
  the traits of a type.

* enable_if exploits the C++ compilation rule that Substitution 
  Failure is Not an Error (SFINAE).

```
int negate(int i) { return -i; }

template <class F>
typename F::result_type negate(const F& f) { return -f(); }
```

* SFINAE is useful because we don't want to break existing code
  by adding templates that the compiler may attempt to instantiate.

* Essentially, all the compiler needs is a single possible option 
  for a function call.  Having additional function calls that 
  fail to instantiate is fine as long as some function exists that 
  can be properly instantiated (type-checks).

* enable_if uses SFINAE to direct the compiler to a specific instantiation
  desired by the programmer.

