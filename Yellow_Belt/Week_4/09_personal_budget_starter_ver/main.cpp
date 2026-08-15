#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <map>
#include <iomanip>
#include <sstream>


using namespace std;



int JDN(const string& x) {
    stringstream ss(x);
    int year, month, day, y, a, m, jdn;
    ss >> year;
    ss.ignore(1);
    ss >> month;
    ss.ignore(1);
    ss >> day;
    
    a = (14 - month) / 12;
    y = year + 4800 - a;
    m = month + 12 * a - 3;
    jdn = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
    return jdn;
}


int main() {
    int Q = 0;
    cin >> Q;
    map<int, double> m;
    
    for(int i = 0; i < Q; i++) {
        string command;
        cin >> command;
        
        if(command == "ComputeIncome") {
            string from, to;
            cin >> from >> to;
            int f = JDN(from);
            int t = JDN(to);
            auto it1 = m.lower_bound(f);
            auto it2 = m.upper_bound(t);
            auto s = accumulate(it1, it2, 0.0, [](double sum, const pair<int, double>& p) {
                return static_cast<double>(sum + p.second); // Суммируем только значения (вторые элементы пары)
            });
            cout << fixed << setprecision(25) << s << endl;
            
        } else if (command == "Earn") {
            double value = 0;
            string from, to;
            cin >> from >> to >> value;
            int f = JDN(from);
            int t = JDN(to);
            double day_value = value / (t - f + 1);
            for(int i = f; i <= t; i++) {
                m[i] += day_value;
            }
            
            
        }
        
    }
    
}

/*
2
Earn 2000-1-1 2000-1-5 6.6
ComputeIncome 2000-1-1 2000-1-1
*/
