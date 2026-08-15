#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    fstream input("input.txt");
    double line;
    cout << fixed << setprecision(3);
    
    while(input) {
        input >> line;
        cout << line << endl;
    }
    

    return 0;
}