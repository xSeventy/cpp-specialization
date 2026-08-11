#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int k = 0;
    int x = 0;
    cin >> n;

    vector<int> temperatures(n);
    for(int i = 0; i < n; i++) {
        cin >> temperatures[i];
        x += temperatures[i];
    }

    int arithmetic_mean = x / n;
    for(int i = 0; i < n; i++) {
        if(temperatures[i] > arithmetic_mean) {
            k++;
        }
    }

    cout << k << endl;
    
    for(int i = 0; i < n; i++) {
        if(temperatures[i] > arithmetic_mean) {
            cout << i << " ";
        }
    }
    
    return 0;
}


