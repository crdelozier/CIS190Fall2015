#include <cstdlib>
#include <iostream>

int main(int argc, char **argv){ // public static void main(String [] args)
  if(argc == 2){
    int year = atoi(argv[1]);
    std::cout << "Kanye " << year << "\n";
    // printf("Kanye %d\n",year);
  }else{
    std::cout << "Usage: " << argv[0] << " [number]\n";
    //printf("Usage: %s [number]\n",argv[0]);
  }
  return 0;
}
