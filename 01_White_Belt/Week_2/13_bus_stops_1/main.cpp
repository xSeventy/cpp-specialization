#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    int Q;
    map<string, vector<string>> bus_stops;
    map<string, vector<string>> stop_buses;
    
    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
       
        string command;
        cin >> command;
        if (command == "NEW_BUS") {
            string bus;
            int stop_count;
            
            cin >> bus >> stop_count;
            for(int j = 0; j < stop_count; j++) {
                string bus_stop;
                cin >> bus_stop;
                bus_stops[bus].push_back(bus_stop);
                stop_buses[bus_stop].push_back(bus);
            }
            
        } else if (command == "BUSES_FOR_STOP") {
            
            string stop;
            cin >> stop;
            /*for(const auto& x : bus_stops) {
                for(const auto& y : x.second) {
                    if(y == stop) {
                        stop_buses[stop].push_back(x.first);
                    }
                }
            } */
            if(stop_buses.count(stop) > 0) {
                for(const auto& x : stop_buses[stop]) {
                    cout << x << " ";
                }
                cout << endl;
            } else {
                cout << "No stop" << endl;
            }
            
        } else if (command == "STOPS_FOR_BUS") {
            
            string bus;
            cin >> bus;
            if(bus_stops.count(bus) == 0) {
                cout << "No bus" << endl;
            } else {
                for(const auto& x : bus_stops[bus]) {
                    cout << "Stop " << x << ":";
                    if(stop_buses[x].size() == 1) {
                        cout << " no interchange" << endl;
                    } else {
                        for (const string& other_bus : stop_buses[x]) {
                          if (bus != other_bus) {
                              cout << " " << other_bus;
                          }
                        }
                        cout << endl;
                    }
                }
            }
            
            
        } else if (command == "ALL_BUSES") {
            
            if(bus_stops.empty()) {
                cout << "No buses" << endl;
            } else {
                for(const auto& x : bus_stops) {
                    cout << "Bus " << x.first << ":";
                    for(const auto& y : x.second) {
                        cout << " " << y;
                    }
                    cout << endl;
                }
            }
            
        }
    }
    
    
    return 0;
}

/*
10
NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
BUSES_FOR_STOP Vnukovo
 
10
ALL_BUSES
BUSES_FOR_STOP Marushkino
NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
BUSES_FOR_STOP Vnukovo
 */
