#include <vector>
#include <iostream>
#include <algorithm>

template <class Iterator>
void print(Iterator begin, Iterator end){
  for(Iterator it = begin; it != end; it++){
    std::cout << *it << ",";
  }
  std::cout << "\n";
}

void times_2(int& x){
  x = x * 2;
}

class Point{
public:
  int x;
  int y;
}

int main(){
  std::vector<int> v = {1,2,3};

  auto comparePoints = [](Point& p1, Point& p2) -> int {
    if(p1.x == p2.x && p1.y == p2.y){
      return 0;
    }else if(p1.x > p2.x && p1.y > p2.y){
      return 1;
    }else{
      return -1;
    }
  };

  sort(points.begin(),point.end(),comparePoints);
  
  print(v.begin(),v.end());
  
  // [](int& x) -> void { x = x * 2; }
  std::for_each(v.begin(),v.end(),[](int& x) -> void { x = x * 2; });
  std::for_each(v.begin(),v.end(),times_2);

  // [](int x) -> void { std::cout << x << ","; }
  // for_each(Iterator begin, Iterator end, UnaryFunction fn)
  std::for_each(v.begin(),v.end(),[](auto x) -> void { std::cout << x << ","; });
  std::cout << "\n";

  int factor = 5;
  auto sum = [](int x, int y) -> int { return (x + y); };

  std::cout << sum(5,10) << "\n";
 
  // accumulate(Iterator begin, Iterator end, T start_value, BinaryFunction fn)
  int total = std::accumulate(v.begin(), v.end(), 0, sum);
  std::cout << "Total: " << total << "\n";

  int total2 = 0;
  for(int value : v){
    total2 += value;
  }

  return 0;
}
