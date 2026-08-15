#include "test_runner.h"
#include "profile.h"
#include <list>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    list<int> athletes;
    vector<list<int>::iterator> iters(100001);
    vector<bool> v(100001, false);
    
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        if(v[b]) {
            auto it = athletes.insert(iters[b], a);
            iters[a] = it;
        } else {
            auto it = athletes.insert(athletes.end(), a);
            iters[a] = it;
        }
        
        v[a] = true;
    
    }
       
    
    for(auto it = athletes.begin(); it != athletes.end(); it++) {
        cout << *it << " ";
    }
    
   
       
    
    
        
    return 0;
}
