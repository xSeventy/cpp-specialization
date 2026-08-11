#include <iostream>
#include <vector>
#include <string>

 
using namespace std;

bool IsPalindrome(const string& x) {
    for(size_t i = 0; i < x.size() / 2; i++) {
        if(x[i] != x[x.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

ostream& operator<< (ostream& os, const vector<string>& v) {
    for(const auto& x : v) {
        os << x;
    }
    return os;
}

vector<string> PalindromeFilter (const vector<string>& words, const int& minLength) {
    vector<string> w;
    for(const auto& x : words) {
        if(IsPalindrome(x) && x.size() >= minLength) {
            w.push_back(x);
        }
    }
    return w;
    
}

int main() {
    
    cout << PalindromeFilter({"abacaba", "aba"}, 5) << endl;
    
 
    return 0;
}
