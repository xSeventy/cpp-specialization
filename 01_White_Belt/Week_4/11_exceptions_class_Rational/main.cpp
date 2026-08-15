#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <stdexcept>
#include <map>

using namespace std;

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
        
        if (denominator == 0) {
                   throw invalid_argument("Denominator equals 0");
               }
        
        p = numerator;
        q = denominator;
        
        numerator = abs(numerator);
        denominator = abs(denominator);
        
        while(numerator > 0 && denominator > 0) {
            if(numerator > denominator) {
                numerator = numerator % denominator;
            } else {
                denominator = denominator % numerator;
            }
        }
         
        p = p / (denominator + numerator);
        q = q / (denominator + numerator);
    
        
        //cout << p << " " << q << "\n";
        
        if(p < 0 && q < 0) {
            p = abs(p);
            q = abs(q);
        } else if(p > 0 && q < 0) {
            q = abs(q);
            p = -p;
        } else if(p == 0 && q != 1) {
            q = 1;
        }
    }

    int Numerator() const {
        // Реализуйте этот метод
        return p;
    }

    int Denominator() const {
        // Реализуйте этот метод
        return q;
    }

    
private:
    // Добавьте поля
    int p, q;
};



Rational operator / (const Rational& lhs, const Rational& rhs) {
    if((lhs.Denominator() + rhs.Denominator()) == 0) {
        throw domain_error("Division by zero");
    }
    int x = lhs.Numerator() * rhs.Denominator();
    int y = lhs.Denominator() * rhs.Numerator();
    Rational rat(x, y);
    return rat;
}


int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}











