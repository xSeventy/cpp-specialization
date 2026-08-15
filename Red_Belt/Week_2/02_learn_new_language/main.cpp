#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include "profile.h"

using namespace std;

class Learner {
 private:
  vector<string> dict;

 public:
    int Learn(const vector<string>& words) {
        //LOG_DURATION("Learn");
    int newWords = 0;
    for (const auto& word : words) {
        if (find(dict.begin(), dict.end(), word) == dict.end()) {
            ++newWords;
            dict.push_back(word);
        }
    }
    return newWords;
  }
    
  vector<string> KnownWords() {
        sort(dict.begin(), dict.end());
      
        dict.erase(unique(dict.begin(), dict.end()), dict.end());
    return dict;
  }
};


int main() {
    //LOG_DURATION("main");
  Learner learner;
  string line;
  while (getline(cin, line)) {
    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word) {
      words.push_back(word);
    }
    cout << learner.Learn(words) << "\n";
  }
  cout << "=== known words ===\n";
  for (const auto& word : learner.KnownWords()) {
    cout << word << "\n";
  }
    return 0;
}
