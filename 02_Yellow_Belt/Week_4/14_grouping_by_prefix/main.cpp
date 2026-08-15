#include <iostream>
#include <string>
#include <vector>
#include <utility>



using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    const string& prefix) {
    
    //string lower_bound_str = prefix;
    //string upper_bound_str = prefix;
    //
    //if(!upper_bound_str.empty()) {
    //    upper_bound_str[upper_bound_str.size() - 1]++;
    //}
    //
    //auto lower = lower_bound(range_begin, range_end, lower_bound_str);
    //auto upper = upper_bound(range_begin, range_end, upper_bound_str);
    //
    //return {lower, upper};
    
    auto lower = lower_bound(range_begin, range_end, prefix);
        
    string upper_bound_str = prefix;
    upper_bound_str.push_back(char(255));  // Добавляем максимальный символ

    auto upper = lower_bound(range_begin, range_end, upper_bound_str);
        
    return {lower, upper};
    
}


int main() {
    const vector<string> sorted_strings = {"b", "cx", "cz"};
  
  const auto mo_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
  for (auto it = mo_result.first; it != mo_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;
  
  const auto mt_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "b");
  cout << (mt_result.first - begin(sorted_strings)) << " " <<
      (mt_result.second - begin(sorted_strings)) << endl;
  
  const auto na_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "bb");
  cout << (na_result.first - begin(sorted_strings)) << " " <<
      (na_result.second - begin(sorted_strings)) << endl;
    const auto _result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), "cy");
    cout << (_result.first - begin(sorted_strings)) << " " <<
        (_result.second - begin(sorted_strings)) << endl;
  return 0;
}
                       
