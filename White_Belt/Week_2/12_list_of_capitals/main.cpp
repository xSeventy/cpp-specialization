#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;


int main() {

    int Q, counter = 0, counter1 = 0, counter2 = 0;
    string command, country, new_capital, old_capital, new_country;
    map<string, string> country_capital;

    cin >> Q;

    for(int i = 0; i < Q; i++) {
    
        cin >> command;

        if(command == "CHANGE_CAPITAL") {

            cin >> country >> new_capital;
            //country_capital[country] = new_capital; // !!!!!!
            for(const auto& x : country_capital) {
                if(x.first == country && x.second == new_capital) {
                    cout << "Country " << country << " hasn't changed its capital" << endl;
                    country_capital[country] = new_capital;
                }
            }

            for(const auto& x : country_capital) {
                if(x.first == country) {
                    counter1++;

                }
            }

            if(counter1 == 0) {
             cout << "Introduce new country " << country << " with capital " << new_capital << endl;
             country_capital[country] = new_capital;
            }

            for(const auto& x : country_capital) {
                if(x.first == country && x.second != new_capital) {
                    cout << "Country " << country  << " has changed its capital from " << x.second << " to " << new_capital << endl;
                    country_capital[country] = new_capital;
                }
            }

        } else if(command == "DUMP") {
            
            if(country_capital.size() == 0) {
                cout << "There are no countries in the world" << endl;
            } else {
                for(const auto& x : country_capital) {
                    cout << x.first << "/" << x.second << " ";
                }
            }

        } else if(command == "ABOUT") {
            
            cin >> country;

            for(const auto& x : country_capital) {
                if(x.first == country) {
                    counter++;
                    cout << "Country " << x.first << " has capital " << x.second << endl;
                }
            }

            if(counter == 0) {
                cout << "Country " << country << " doesnt't exist" << endl;
            }

        } else if (command == "RENAME") {
            
            cin >> country >> new_country;
            
            for(const auto& x : country_capital) {
                if(x.first == new_country) {
                    cout << "Incorrect rename, skip" << endl;
                    break;
                } else if(x.first == country) {
                    country_capital[new_country] = new_capital;
                    country_capital.erase(country);
                    cout << "Country " << country  <<  " with capital " << new_capital << " has been renamed to " << new_country << endl;
                    break;
                } else if(x.first != new_country) {
                    counter2++;
                    if(counter2 == country_capital.size()) {
                        cout << "Incorrect name, skip" << endl;
                    }
                }
            }
            
        }
    }
    return 0;
}


/*10
 CHANGE_CAPITAL RussianEmpire Petrograd
 RENAME USSR RussianEmpire
 DUMP
 ABOUT USSR
 DUMP
 RENAME RussianEmpire RussianEmpire
 DUMP
 CHANGE_CAPITAL UnitedStatesOfBrazil Brasilia
 RENAME RussianEmpire UnitedStatesOfBrazil
 DUMP
*/
