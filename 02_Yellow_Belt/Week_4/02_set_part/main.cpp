#include <iostream>
#include <string>
#include <vector>
#include <set>


using namespace std;


template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    vector<T> v;
    auto iter = elements.end();
   // auto it = find_if(elements.begin(), elements.end(), [border](const T& elem) {
   //     return elem == border;
   // });
   
    for(auto it = elements.begin(); it != elements.end(); it++) {
        if(*it >= border) {
            iter = it;
            break;
        }
    }
    
    for(iter; iter != elements.end(); iter++) {
        if(*iter != border)  {
            v.push_back(*iter);
        }
    
    }
    return v;
}



int main() {
  for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, -1)) {
    cout << x << " ";
  }
  cout << endl;
  
  string to_find = "Python";
  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
  return 0;
}
