#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int N;
    string word;
    set<string> s;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> word;
        s.insert(word);
    }
    
    cout << s.size();
    
    return 0;
}









