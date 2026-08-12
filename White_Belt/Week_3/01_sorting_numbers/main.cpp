#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

void printVector (vector<int>& m) {
    for(auto& i : m) {
        cout << i << " ";
    }
    cout << endl;
}

bool comparison(int &x , int& y) {
    if(abs(x) > abs(y)) {
        return false;
    } else {
        return true;
    }
}

int main() {
    vector<int> v;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int value;
        cin >> value;
        v.push_back(value);
    }
    //printVector(v);
    sort(begin(v), end(v), comparison);
    printVector(v);
    return 0;
}





