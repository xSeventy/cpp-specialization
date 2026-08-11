#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> s;
    for(const auto& x : m) {
        s.insert(x.second);
    }
    return s;
}











