int foo(int val){
  return val;
}

int& bar(int& val){
  return val;
}



int main(){
  int x,y;

  x = y; // x and y are both lvalues

  5 = x; // 5 is an rvalue, cannot assign into it

  y = 2; // y is an lvalue and 2 is an rvalue

  x + y = 3; // x + y is an rvalue, cannot assign into it

  foo(x) = 5; // foo() is an rvalue

  bar(x) = 2; // Fine, bar(x) returns an lvalue

  return 0;
}
