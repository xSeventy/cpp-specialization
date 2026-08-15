#include <deque>
#include <string>
#include <iostream>

using namespace std;



int main() {
    deque<string> d;
    
    int x;
    cin >> x;
    d.push_back(to_string(x));
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        
        string operation;
        int a;
        cin >> operation >> a;
        d.push_front("(");
        d.push_back(")" + string(" ") + operation + string(" ") + to_string(a));
            
    }
    
    for(auto& x : d) {
        cout << x;
    }
    
    
    
    return 0;
}
