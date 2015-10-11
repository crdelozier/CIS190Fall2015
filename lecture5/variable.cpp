#include <iostream>

#include <cstdlib>
#include <cstring>

/*
 *  Is this data-structure efficient?
 *  Is there any way that we can optimize it?
 *  Note: We want "s" to be variable-length.
 */
typedef struct key{
  int length;
  char s[1];
} key;

key* create_key(int length){
  //key *new_key = new key;
  key *new_key = (key*)malloc(sizeof(int) + (sizeof(char) * length));
  new_key->length = length;
  //new_key->s = new char[length];
  return new_key;
}

void destroy_key(key *k){
  //free(k->s);
  free(k);
}

int main(){
  key *k1 = create_key(10);
  key *k2 = create_key(30);

  free(k1);
  k1 = create_key(20);

  strncpy(k1->s,"Test12345",10);
  strncpy(k2->s,"ABCDEFGHIJKLMNOP",30);

  std::cout << k1->s << "\n";
  std::cout << k2->s << "\n";

  destroy_key(k1);
  destroy_key(k2);

  return 0;
}
