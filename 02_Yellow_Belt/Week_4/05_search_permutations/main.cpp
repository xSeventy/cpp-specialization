#include <iostream>
#include <vector>
#include <algorithm>




using namespace std;



int main() {
    
    vector<int> v;
    int x = 0;
    cin >> x;
    
    for(int i = x; i > 0; i--) {
        v.push_back(i);
    }
    
    do {
            for (auto x : v) {
                cout << x << " ";
            }
            cout << endl;
        } while (prev_permutation(v.begin(), v.end()));
    
    return 0;
}


/*
 
 next_permutation(numbers.begin(), numbers.end())
 
 */
