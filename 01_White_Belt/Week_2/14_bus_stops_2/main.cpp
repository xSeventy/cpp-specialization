#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
    int Q, N;
    int a = 1;
    cin >> Q;
    
    map<vector<string>, int> buses;
    
    
    for (int i = 0; i < Q; ++i) {
        vector<string> bus_stops;

        if(buses.empty()) {

            cin >> N;

            for(int j = 0; j < N; j++) {
                string bus_stop;
                cin >> bus_stop;
                bus_stops.push_back(bus_stop);
            }

            buses[bus_stops] = a;
            cout << "New bus " << a << endl;
            a++;

        } else {
            
            cin >> N;

            for(int j = 0; j < N; j++) {
                string bus_stop;
                cin >> bus_stop;
                bus_stops.push_back(bus_stop);
            }

            if(buses[bus_stops] > 0) {

                cout << "Already exists for " << buses[bus_stops] << endl;

            } else {
                
                buses[bus_stops] = a;
                cout << "New bus " << a << endl;
                a++;
                
            }
        }
    }

    return 0;
}











