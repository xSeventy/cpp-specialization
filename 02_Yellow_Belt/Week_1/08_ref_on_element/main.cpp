#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <exception>

 
using namespace std;

template<typename key, typename value>
value& GetRefStrict(map<key, value>& m, const key& k);

template<typename key, typename value>
value& GetRefStrict(map<key, value>& m, const key& k) {
    if(m.count(k) == 0) {
        throw runtime_error("");
    } else {
        return m[k];
    }
}


int main() {
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl;

    return 0;
}
