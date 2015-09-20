#include <iostream>

int main(){
  char *password = "correct";
  std::string userInput;
  char *comp;

  std::cout << "Please enter the password: ";
  std::cin >> userInput;

  userInput = comp;

  if(userInput.compare(password) == 0){
    std::cout << "Correct!\n";
  }else{
    std::cout << "Incorrect!\n";
  }

  return 0;
}
