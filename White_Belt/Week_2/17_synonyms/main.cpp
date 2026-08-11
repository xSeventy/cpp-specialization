#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>


using namespace std;



int main() {

    int Q, a = 0;
    map<string, set<string>> m;
    cin >> Q;

    for(int i = 0; i < Q; i++) {

        string command;
        cin >> command;

        if(command == "ADD") {

            string word1, word2;
            cin >> word1 >> word2;
            
            m[word1].insert(word2);
            m[word2].insert(word1);

        } else if(command == "COUNT") {
            
            string word;
            cin >> word;
            
            cout << m[word].size() << endl;
            
        } else if(command == "CHECK") {
            
            string word1, word2;
            cin >> word1 >> word2;

            if(m[word1].count(word2) == 1 || m[word2].count(word1) == 1) {
                
                cout << "YES" << endl;

            } else {
                
                cout << "NO" << endl;

            }

        }
    }
    
    
    return 0;
}











