class AutoDestroyer{
  int *member;
  
  AutoDestroyer(const AutoDestroyer &other){}

public:
  AutoDestroyer(){
    member = new int;
  }
  
  ~AutoDestroyer(){
    delete member;
  }

  AutoDestroyer(AutoDestroyer &other){
    if(this != &other){
      member = new int;
      *member *other.member;
    }
  }
  
  AutoDestroyer& operator= (AutoDestroyer &other){
    if (this != &other){
      *member = *other.member;
    }
    return *this;
  }
};

int main(){
  AutoDestroyer *d1 = new AutoDestroyer();
  AutoDestroyer *d2 = new AutoDestroyer(d1);


    AutoDestroyer ad1;
    AutoDestroyer ad2;

    AutoDestroyer adCopy(ad1);

    ad2 = ad1;

    return 0;
}
