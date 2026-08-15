#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double a, b, x, y, n;
    cin >> n >> a >> b >> x >> y;

    if(a < b) {
        if (n > b) {
            cout << n * ((100 - y) / 100) << endl;;
        } else if (n <= b && n > a) {
            cout << n * ((100 - x) / 100) << endl;
        } else {
            cout << n << endl;
        }
    }

    return 0;
}



/*
N A B X Y
 if n > a && n < b discount x
 if n > b discount y
 n < b n < a 3
 n > a n < b  x discount fractional and x integer 2 n integer n fractional
 n < b y disount fractional and y integer 1 n integer n fractional

*/
