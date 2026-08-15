#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
class People {
public:
    virtual void Walk(string destination) const = 0;
    
    virtual string GetName() const = 0;
    
};
 
class Student : public People {
public:
 
    Student(string name, string favouriteSong) : Name(name), FavouriteSong(favouriteSong) {}
 
    void Learn() {
        cout << "Student: " << Name << " learns" << endl;
    }
 
    void Walk(string destination) const override {
        cout << "Student: " << Name << " walks to: " << destination << endl;
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }
 
    void SingSong() {
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }
    
    string GetName() const override {
        return Name;
    }
 
public:
    string Name;
    string FavouriteSong;
};
 
 
class Teacher : public People {
public:
 
    Teacher(string name, string subject) : Name(name), Subject(subject) {}
 
    void Teach() {
        cout << "Teacher: " << Name << " teaches: " << Subject << endl;
    }
 
    void Walk(string destination) const override {
        cout << "Teacher: " << Name << " walks to: " << destination << endl;
    }
    
    string GetName() const override {
        return Name;
    }
 
public:
    string Name;
    string Subject;
};
 
 
class Policeman : public People {
public:
    Policeman(string name) : Name(name) {}
    
    void Check(People& t) {
        cout << "Policeman: " << Name << " checks Teacher. Teacher's name is: " << t.GetName() << endl;
    }
    
 
    void Walk(string destination) const override {
        cout << "Policeman: " << Name << " walks to: " << destination << endl;
    }
    
    string GetName() const override {
        return Name;
    }
 
public:
    string Name;
};
 
template <typename T>
void VisitPlaces(T t, vector<string> places) {
    for (auto p : places) {
        t.Walk(p);
    }
}
 
int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");
 
    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}