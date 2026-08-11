#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;


void BuildCharCounters(const string& c, const string& d) {
    
    map<char, int> counter;
    map<char, int> counter1;

    for(const char& letter : c) {
        ++counter[letter];
    }

    for(const char& letter : d) {
        ++counter1[letter];
    }

    if(counter == counter1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}




int main() {
    int N;
    string a, b;

    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        BuildCharCounters(a, b);
    }
    
    return 0;
}
