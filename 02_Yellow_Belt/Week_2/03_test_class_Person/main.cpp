#include "unit_test_framework.h"

using namespace std;

class Person {
public:
  // Вы можете вставлять сюда различные реализации класса,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
  void ChangeFirstName(int year, const string& first_name) {
      name_hist[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
      surname_hist[year] = last_name;
  }
  string GetFullName(int year) {
      string current_name, current_surname;

      for(const auto& x : name_hist) {
          if(year >= x.first) {
              current_name = x.second;
          }
      }

      for(const auto& x : surname_hist) {
          if(year >= x.first) {
              current_surname = x.second;
          }
      }


      if(current_surname.empty() && current_name.empty()) {
          return "Incognito";
      } else if (current_name.empty()) {
          return current_surname + " with unknown first name";
      } else if (current_surname.empty()) {
          return current_name + " with unknown last name";
      } else {
          return current_name + " " + current_surname;
      }

  }

private:
    map<int, string> name_hist;
    map<int, string> surname_hist;
};

void TestAll () {
    Person pr;
    
    pr.ChangeFirstName(2005, "Seva");
    AssertEqual(pr.GetFullName(2005), "Seva with unknown last name", "first");
    
    pr.ChangeLastName(2005, "Pikush");
    AssertEqual(pr.GetFullName(2005), "Seva Pikush", "second");
    
    pr.ChangeFirstName(2006, "Dima");
    AssertEqual(pr.GetFullName(2006), "Dima Pikush", "third");
    
    pr.ChangeLastName(2007, "lol");
    AssertEqual(pr.GetFullName(2007), "Dima lol", "fourth");
    
    AssertEqual(pr.GetFullName(2000), "Incognito", "fifth");
    
    pr.ChangeLastName(2004, "kek");
    AssertEqual(pr.GetFullName(2004), "kek with unknown first name");
    
}

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
    runner.RunTest(TestAll, "TestAll");
  return 0;
}
