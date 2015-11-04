#include <vector>
#include <map>
#include <list>
#include <set>

#include <iostream>

class UnOptimized{
public:
  static const bool allowsOptimization = false;
};

class Optimized{
public:
  static const bool allowsOptimiziation = true;
};

template <bool optimize>
void unoptimized(){
  // Unoptimized version
}

template<>
void unoptimized<true>{
  // Optimized version
}

template <class Iterator>
void print_helper(Iterator begin, Iterator end, bidirectional_iterator_tag t){

}

template <class Iterator>
void print_helper(Iterator begin, Iterator end, random_access_iterator_tag t){

}

template <class Iterator>
void print(Iterator begin, Iterator end){
  for(Iterator it = begin; it != end; it++){
    std::cout << *it << ",";
  }
  print_helper(begin,end,Iterator::iterator_category);
  std::cout << "\n";
}

int main(){
  using namespace std;

  vector<int> v;
  list<int> l;
  map<int,int> m;
  set<int> s;

  v.push_back(5);
  v.push_back(2);
  v.insert(v.begin() + 1,3);

  v.resize(10);

  v[5] = 100;

  print(v.begin(),v.end());

  l.push_front(2);
  l.push_back(6);
  l.push_front(1);

  l.pop_back();

  print(l.begin(),l.end());

  m[5] = 10;
  m[2] = 3;

  for(map<int,int>::iterator it = m.begin(), end = m.end(); it != end; it++){
    std::cout << it->first << " - " << it->second << ",";
  }
  std::cout << "\n";

  s.insert(2);
  s.insert(3);

  if(s.find(2) != s.end()){
    std::cout << "Found 2!\n";
  }

  if(s.find(5) == s.end()){
    std::cout << "Did not find 5!\n";
  }
  
  return 0;
}
