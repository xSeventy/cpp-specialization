#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string PrintVector(const vector<string>& v) {
    if (v.empty()) {
        return "";
    }
    string result = " (";
    for (int i = v.size() - 2; i > 0; --i) {
        result += v[i] + ", ";
    }
    result += v[0] + ")";
    return result;
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        name[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        surname[year] = last_name;
    }

    string GetFullName(int year) {
        string cur_name = "";
        string cur_surname = "";
        
        for (const auto& item : name) {
            if (item.first <= year) {
                cur_name = item.second;
            }
        }
        for (const auto& item : surname) {
            if (item.first <= year) {
                cur_surname = item.second;
            }
        }
        
        if (cur_name.empty() && cur_surname.empty()) {
            return "Incognito";
        } else if (!cur_name.empty() && cur_surname.empty()) {
            return cur_name + " with unknown last name";
        } else if (cur_name.empty() && !cur_surname.empty()) {
            return cur_surname + " with unknown first name";
        } else {
            return cur_name + " " + cur_surname;
        }
    }

    string GetFullNameWithHistory(int year) {
        vector<string> name_history;
        vector<string> surname_history;
        
        string cur_name = "";
        string cur_surname = "";
        
        for (const auto& item : name) {
            if (item.first <= year) {
                if (cur_name != item.second) {
                    name_history.push_back(item.second);
                    cur_name = item.second;
                }
            }
        }
        for (const auto& item : surname) {
            if (item.first <= year) {
                if (cur_surname != item.second) {
                    surname_history.push_back(item.second);
                    cur_surname = item.second;
                }
            }
        }

        if (name_history.empty() && surname_history.empty()) {
            return "Incognito";
        } else if (name_history.empty()) {
            return cur_surname + (surname_history.size() > 1 ? PrintVector(surname_history) : "") + " with unknown first name";
        } else if (surname_history.empty()) {
            return cur_name + (name_history.size() > 1 ? PrintVector(name_history) : "") + " with unknown last name";
        } else {
            return cur_name + (name_history.size() > 1 ? PrintVector(name_history) : "") + " " + cur_surname + (surname_history.size() > 1 ? PrintVector(surname_history) : "");
        }
    }

private:
    map<int, string> name;
    map<int, string> surname;
};

int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
}







