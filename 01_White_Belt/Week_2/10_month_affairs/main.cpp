#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int Q, i, month_num = 1;
    string operation, s;

    vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> affairs(31);

    cin >> Q;

    for(int j = 0; j < Q; j++) {

        cin >> operation;

        if(operation == "ADD") {

            cin >> i >> s;
            affairs[i - 1].push_back(s);

        } else if(operation == "DUMP") {
            
            cin >> i;
            cout << affairs[i - 1].size() << " ";
            for(string x : affairs[i - 1]) {
                cout << x << " ";
            }
            cout << endl;

        } else if(operation == "NEXT") {
            
            if(month_num > 11) {
                month_num = 0;
            }

            vector<vector<string>> new_affairs(days_in_month[month_num]);

            if(new_affairs.size() >= affairs.size()) {
            
                affairs.resize(new_affairs.size());
                new_affairs.clear();

            } else if (new_affairs.size() < affairs.size()){
                
                for(int h = 0; h < new_affairs.size(); h++) {
                    new_affairs[h] = affairs[h];
                }
                for(auto k = new_affairs.size(); k < affairs.size(); k++) {
                    new_affairs.back().insert(end(new_affairs.back()), begin(affairs[k]), end(affairs[k]));
                }
                
                affairs = new_affairs;

            }
            
            month_num++;
        }
    }
    
    return 0;
}
