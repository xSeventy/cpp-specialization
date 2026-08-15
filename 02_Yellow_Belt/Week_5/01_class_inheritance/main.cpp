#include <iostream>
#include <string>



using namespace std;

class Animal {
public:
    Animal(const string& n) : Name(n) {
    }
    const string Name;
};


class Dog : public Animal{
public:
    
    Dog(const string& x) : Animal(x) {
    }
    
    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }

};

int main() {
    
    Dog dog("Barbos");
    dog.Bark();
    
  return 0;
}
