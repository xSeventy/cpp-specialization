#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

struct Student {
    string name;
    string surname;
    int birth_day;
    int birth_month;
    int birth_year;
};

int main() {
    int N, n;
    string operation;
    
    cin >> N;
    vector<Student> students(N);
    for(int i = 0; i < N; i++) {
        cin >> students[i].name >> students[i].surname >> students[i].birth_day >> students[i].birth_month >> students[i].birth_year;
    }
    
    cin >> n;
    
    for(int j = 0; j < n; j++) {
        int K;
        cin >> operation >> K;
        if(K > N || K < 1) {
            cout << "bad request" << "\n";
        } else if(operation == "name") {
                cout << students[K - 1].name << " " << students[K - 1].surname << "\n";
        } else if(operation == "date") {
                cout << students[K - 1].birth_day << "." << students[K - 1].birth_month << "." << students[K - 1].birth_year << "\n";
        } else {
            cout << "bad request" << "\n";
        }
    }
    return 0;
}



