#include <iostream>
#include <stdexcept>

void typesafe_printf(const char *s){
  while (*s) {
    if (*s == '%') {
      throw std::runtime_error("invalid format string: missing arguments");
    }
    std::cout << *s++;
  }
}

// template<int, (char, int)>
// void typesafe_printf("Test: %d %c %d\n",5,('a',3));

// template<char, (int)>
// void typesafe_printf("%c %d\n",'a',(3))

template<typename T, typename... Args>
void typesafe_printf(const char *s, T value, Args... args){
  while (*s) {
    if (*s == '%') {
      std::cout << value;
      s += 2;
      typesafe_printf(s, args...);
      return;
    }
    std::cout << *s++;
  }
}

int main(){
  typesafe_printf("Test: %d %c %d\n",5,'a',3);
  typesafe_printf("Test2: %d %d %d %d\n",1,2,3);

  return 0;
}
