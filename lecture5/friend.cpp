#include <iostream>

class FloatVectorFriend;

class FloatVector{
  float x;
  float y;
  float z;
  
  friend void printVector(FloatVector);
  friend class FloatVectorFriend;

public:
  void stealX(FloatVectorFriend fvf);
};

class FloatVectorFriend{
  float x;
  
public:
  void stealX(FloatVector fv){
    x = fv.x;
  }

  friend class FloatVector;
};

void FloatVector::stealX(FloatVectorFriend fvf){
  x = fvf.x;
}

void printVector(FloatVector fv){
    std::cout << "[" << fv.x << "," << fv.y << "," << fv.z << "]";    
}

int main(){
    FloatVector fv;
    FloatVectorFriend f;

    f.stealX(fv);
    printVector(fv);

    return 0;
}
