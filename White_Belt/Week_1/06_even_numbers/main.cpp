#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if(a <= b && a >= 1) {
        while(a <= b) {
            if(a % 2 == 0) {
                cout << a << " ";
            }
            a++;
        }
    }
    
    return 0;
}

