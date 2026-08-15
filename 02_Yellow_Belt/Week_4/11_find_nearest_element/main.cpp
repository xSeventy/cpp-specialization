#include <utility>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include "profile.h"

using namespace std;

// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел
set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border) {
    if(numbers.empty()) {
        return numbers.begin();
    }
    auto it1 = numbers.lower_bound(border);
    auto it2 = prev(it1);
    if(it1 == numbers.end()) {
        return it2;
    } else if(it1 == numbers.begin()) {
        return it1;
    }
    
    if(border - *it2 <= *it1 - border) {
        return it2;
    } else {
        return it1;
    }
    
    
}




int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;
      
  set<int> empty_set;

  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
