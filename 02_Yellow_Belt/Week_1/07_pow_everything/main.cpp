#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <cmath>

 
using namespace std;

template<typename T>
vector<T> Sqr (vector<T> v);

template<typename first, typename second>
pair<first, second> Sqr(pair<first, second> p);

template<typename f, typename s>
map<f, s> Sqr (map<f, s> m);

template<typename T>
vector<T> Sqr (vector<T> v) {
    for(auto& x : v) {
        x = pow(x, 2);
    }
    return v;
}

template<typename f, typename s>
map<f, s> Sqr (map<f, s> m) {
    for(auto& x : m) {
        x.second = Sqr(x.second);
    }
    return m;
}

template<typename f, typename s>
pair<f, s> Sqr(pair<f, s> p) {
    p.first = pow(p.first, 2);
    p.second = pow(p.second, 2);
    return p;
}



int main() {
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
      cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
        {4, {2, 2}},
        {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    
    pair<int, int> p = {2, 3};
    auto x = Sqr(p);
    cout << x.first << " " << x.second << endl;
    
    return 0;
}
