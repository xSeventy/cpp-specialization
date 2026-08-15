#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int Q, i;
    vector<bool> queue;
    cin >> Q;
    
    for(int j = 0; j < Q; j++) {
        string command;
        cin >> command;
        
        if(command == "WORRY" || command == "QUIET") {

            cin >> i;
            
            if(queue[i] == true) {
                queue[i] = false;
            } else {
                queue[i] = true;
            }
            
        } else if (command == "COME") {
            int k;
            cin >> k;
            
            if(k > 0) {
                for(int i = 0; i < k; i++) {
                    queue.push_back(true);
                }
            } else {
                for(int i = 0; i < abs(k); i++) {
                    queue.pop_back();
                }
            }
            
        } else if (command == "WORRY_COUNT") {
            int counter = 0;
            for(const auto x : queue) {
                if(x == false) {
                    counter++;
                }
            }
            cout << counter << endl;
        }
        
    }
    
    return 0;
}
