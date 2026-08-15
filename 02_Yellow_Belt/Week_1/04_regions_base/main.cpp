#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <tuple>

 
using namespace std;

enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};

bool operator == (const Region& lhs, const Region& rhs) {
    return tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population) == tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population);
}

bool operator < (const Region& lhs, const Region& rhs) {
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) < tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    map<Region, int> m;
    if(regions.size() == 0) {
        return 0;
    } else {
        for(size_t i = 0; i < regions.size(); i++) {
            m[regions[i]]++;
        }
        int max_count = 0;
        for(const auto& pair : m) {
            if(pair.second > max_count) {
                max_count = pair.second;
            }
        }
        return max_count;
    }
    
}

int main() {
    
    return 0;
}
