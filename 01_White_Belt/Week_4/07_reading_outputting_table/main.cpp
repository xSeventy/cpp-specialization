#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    ifstream input("input.txt");
    int i = 0, j = 0;
    
    input >> i;
    input.ignore(1);
    input >> j;
    input.ignore(1);
    
    string line;
    for(int h = 0; h < i; h++) {
        for(int k = 0; k < j; k++) {
            if(k == j - 1) {
                getline(input, line);
                cout << setw(10) << line;
            } else {
                getline(input, line, ',');
                cout << setw(10) << line << " ";
            }
            
        }
        if(h != i - 1) {
            cout << endl;
        }
    }
    
    
    return 0;
}
















