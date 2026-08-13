#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Specialization {
    string a;
    explicit Specialization(const string& s) {
        a = s;
    }
};

struct Course {
    string b;
    explicit Course(const string& s) {
        b = s;
    }
};

struct Week {
    string c;
    explicit Week(const string& s) {
        c = s;
    }
};


struct LectureTitle {
    string specialization;
    string course;
    string week;
    LectureTitle(Specialization s, Course c, Week w) {
        specialization = s.a;
        course = c.b;
        week = w.c;
    };
};

int main() {
    /*LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    );
    
    
    cout << title.specialization << " "
    << title.course << " "
    << title.week;
    */
    return 0;
    
}
