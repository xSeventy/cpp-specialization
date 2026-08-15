#include <string>
#include <deque>
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
        bool prior;          // true - предыдущее выражение + или -          false - предыдущее выражение * или /
        int a;
        cin >> operation >> a;
        if(operation == "+" || operation == "-") {
            prior = true;
            d.push_back(" " + operation + " " + to_string(a));
        } else if((operation == "*" || operation == "/") && prior == true) {
            prior = false;
            d.push_front("(");
            d.push_back(string(")") + " " + operation + " " + to_string(a));
        } else if((operation == "*" || operation == "/") && prior == false) {
            d.push_back(" " + operation + " " + to_string(a));
        }
            
    }
    
    for(auto& x : d) {
        cout << x;
    }
    
    
    
    return 0;
}
