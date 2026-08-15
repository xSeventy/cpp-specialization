#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input("input.txt");
    string line;
    //ofstream output("output.txt", ios::app);
    while (getline(input, line)) {
        cout << line << "\n"; //закомментируем эту строку, для 2 части
        // output << line << "\n"; //закомментируем эту строку, для 1 части
    }
    return 0;
}