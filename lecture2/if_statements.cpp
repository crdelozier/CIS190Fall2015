#include <iostream>

int main() {
  //bool TRUE = true; // boolean TRUE = true;
  //bool FALSE = false;

  if(true){
    std::cout << "This statement should print!\n";
  }

  if(false){
    std::cout << "This statement should not print.\n";
  }

  if(-500){
    std::cout << "This should also print\n";
  }
    
  std::cout << "True: " << true 
            << ", False: " << false << "\n";

  return 0;
}
