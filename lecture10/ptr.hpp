class ptr{
  int *p;

public:

  explicit operator bool(){
    return p != 0;
  }
};

int main(){
  ptr p1 = nullptr;
  int *p2 = nullptr;

  if(!p2){
    p2 = new int;
  }

  if((bool)p1){
    
  }

  bool done = false;
  done = (bool)p1;

  return 0;
}
