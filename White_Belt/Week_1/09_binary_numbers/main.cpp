#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a;
    int x = 0;

    while(n > 0) {
        int b = n % 2;
        a.push_back(b);
        n = n / 2;
        x++;
    }

    for(int i = x - 1; i >= 0; i--) {
        cout << a[i];
    }
    
    return 0;
}


