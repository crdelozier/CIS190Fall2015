int f(int x){
  int y = 5;
  return x + y;
}

int main(){
  int x = 1;
  int y = 2;
  int z = 3;

  z = z + x;
  y = 2 * z;
  x = y + 1;

  z = f(x);
  y = f(x);

  return 0;
}
