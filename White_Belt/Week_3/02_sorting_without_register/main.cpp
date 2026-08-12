#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

void printVector (vector<char>& m) {
    for(auto& i : m) {
        cout << i << " ";
    }
    cout << endl;
}

bool comparison(char& x , char& y) {
    if(tolower(x) > tolower(y)) {
        return false;
    } else {
        return true;
    }
}

int main() {
    vector<char> v;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        char value;
        cin >> value;
        v.push_back(value);
    }
    // printVector(v);
    sort(begin(v), end(v), comparison);
    printVector(v);
    return 0;
}





