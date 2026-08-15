#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
      name[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
      surname[year] = last_name;
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
      string current_name, current_surname;
      
      for(const auto& x : name) {
          if(x.first <= year) {
              current_name = x.second;
          }
      }
      for(const auto& x : surname) {
          if(x.first <= year) {
              current_surname = x.second;
          }
      }
      if(current_name.empty() && current_surname.empty()) {
          return "Incognito";
      } else if(current_name.empty()) {
          return current_surname + " with unknown first name";
      } else if(current_surname.empty()){
          return current_name + " with unknown last name";
      } else {
          return current_name + " " + current_surname;
      }
  }
private:
  // приватные поля
    map<int, string> name;
    map<int, string> surname;
};


int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}
