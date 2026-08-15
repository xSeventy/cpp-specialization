#include <iostream>

using namespace std;


int main() {
    int N, R, W, H, D;
    uint64_t volume = 0;
    cin >> N >> R;
    
    
    for(int i = 0; i < N; i++) {
        cin >> W >> H >> D;
        volume += W * H * D;
    }
    
    uint64_t a = R * volume;
    cout << a;
    
    return 0;
}
