#include <iostream>
#include <string>

char* getPassword(){
  return "54321234";
}

int main() {
  std::string userInput;
  std::cout << "Please enter the password: ";
  std::cin >> userInput;
  if(userInput.compare(getPassword()) == 0){
    std::cout << "Correct!\n";
  }else{
    std::cout << "Incorrect!\n";
  }
  return 0;
}
