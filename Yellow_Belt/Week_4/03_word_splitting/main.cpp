#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
    vector<string> res;
    string result;
    
    //auto it = find(s.begin(), s.end(), ' ');
   //
   // for(auto iterator = s.begin(); iterator != it; iterator++) {
   //     result += string(1, *iterator);
   // }
   //
   // res.push_back(result);
   //
   // it++;
   // auto it1 = find(it, s.end(), ' ');
   // result.clear();
   //
   // for(auto iterator = it; iterator != it1; iterator++) {
   //     result += string(1, *iterator);
   // }
   //
   // res.push_back(result);
    
    auto it = s.begin();
    while(it != s.end()) {
        auto iterator = find(it, s.end(), ' ');
        string str(it, iterator);
        res.push_back(str);
        if (iterator != s.end()) {
            it = iterator + 1; // Пропускаем пробел и переходим к следующему слову
        } else {
            break; // Дошли до конца строки
        }
    }
    
    
    
    return res;
    
}


int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
    cout << words.size() << endl;
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}
