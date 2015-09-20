#include <time.h>
#include <cstdlib>
#include <iostream>
#include <string>

int main() {
  char password[4] = {'a','a','a','a'};
  std::string userInput;
  srand(time(NULL));
  int idx1 = rand() % 4;
  int idx2 = rand() % 4;
  int val1 = rand() % 27 + 97;
  int val2 = rand() % 27 + 97;
  password[idx1] = val1;
  password[idx2] = val2;
  std::cout << "Please enter the password: ";
  std::cin >> userInput;
  if(userInput.compare(password) == 0){
    std::cout << "Correct!\n";
  }else{
    std::cout << "Incorrect!\n";
  }
  return 0;
}
