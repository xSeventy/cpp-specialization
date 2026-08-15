#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v) {
    for(int i = 0; i < v.size() / 2; i++) {
        int x = v[i];
        v[i] = v[v.size() - 1 - i];
        v[v.size() - 1 - i] = x;
    }
}

vector<int> Reversed(const vector<int>& v) {
    vector<int> x;
    for(int i : v) {
        x.push_back(i);
    }
    Reverse(x);
    
    return x;
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2, 6};
    Reverse(numbers);

    for(int i : numbers) {
        cout << i << " ";
    }
    
    return 0;
}


