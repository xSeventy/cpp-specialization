#include <iostream>
#include <vector>




using namespace std;



int main() {
    vector<int64_t> v;
    int64_t n;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int64_t temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    int64_t sum = 0;
    for(const auto& x : v) {
        sum += x;
    }
    int64_t avg = sum / static_cast<int>(v.size());
    
    vector<size_t> res;
    for(size_t i = 0; i < v.size(); i++) {
        if(v[i] > avg) {
            res.push_back(i);
        }
    }
    
    cout << res.size() << endl;
    for(const size_t& x : res) {
        cout << x << " ";
    }
    
    
    return 0;
}
