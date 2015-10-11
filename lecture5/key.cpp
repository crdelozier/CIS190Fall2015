#include <iostream>
#include <string>

class Key{
  std::string key;

public:
  Key(std::string k) : key(k){}

  explicit operator std::string() const {
    return key;
  }
};

int main(){
  Key key1("Hello world!\n");
  std::string k = key1;

  std::cout << (std::string)key1 << "\n";

  return 0;
}
