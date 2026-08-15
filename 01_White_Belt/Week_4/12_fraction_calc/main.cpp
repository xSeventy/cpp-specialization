#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
#include <stdexcept>


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
            throw invalid_argument("Invalid argument");
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

Rational operator + (const Rational& lhs, const Rational& rhs) {
    int x = rhs.Denominator() * lhs.Numerator() + rhs.Numerator() * lhs.Denominator();
    int y = lhs.Denominator() * rhs.Denominator();
    Rational rat(x, y);
    return rat;
}

Rational operator - (const Rational& lhs, const Rational& rhs) {
    int x = rhs.Denominator() * lhs.Numerator() - rhs.Numerator() * lhs.Denominator();
    int y = lhs.Denominator() * rhs.Denominator();
    Rational rat(x, y);
    return rat;
}

bool operator == (const Rational& lhs, const Rational& rhs) {
    if(lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()) {
        return true;
    } else {
        return false;
    }
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
    int x = lhs.Numerator() * rhs.Numerator();
    int y = lhs.Denominator() * rhs.Denominator();
    Rational rat(x, y);
    return rat;
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
    int x = lhs.Numerator() * rhs.Denominator();
    int y = lhs.Denominator() * rhs.Numerator();
    Rational rat(x, y);
    return rat;
}

bool operator < (const Rational lhs, const Rational rhs) {
    if(lhs.Numerator() * (rhs.Denominator()) < rhs.Numerator() * lhs.Denominator()) {
        return true;
    } else {
        return false;
    }
}

ostream& operator << (ostream& stream, const Rational& rational) {
    int x = rational.Numerator();
    int y = rational.Denominator();
    
    stream << x << "/" << y;
    
    return stream;
}

istream& operator >> (istream& stream, Rational& rational) {
    int x = rational.Numerator();
    int y = rational.Denominator();
    
    stream >> x;
    stream.ignore(1);
    stream >> y;
     
    rational = Rational(x, y);
    
    return stream;
}


int main() {
    int x, y, z, h;
    char a, b ,c;
    cin >> x >> b >> y >> a >> z >> c >> h;
    
    
    if(y == 0 || h == 0) {
        try {
            Rational rat1(x, y);
            Rational rat2(z, h);
            if(a == '*') {
                cout << Rational(x, y) * Rational(z, h) << endl;
            } else if(a == '/') {
                cout << Rational(x, y) / Rational(z, h) << endl;
            } else if(a == '+') {
                cout << Rational(x, y) + Rational(z, h) << endl;
            } else if(a == '-') {
                cout << Rational(x, y) - Rational(z, h) << endl;
            }
        } catch(invalid_argument& i) {
            cout << i.what() << endl;
        }
    } else if(z == 0 && a == '/') {
        try {
            Rational rat1(x, y);
            Rational rat2(z, h);
            rat1 / rat2;
            if(a == '*') {
                cout << Rational(x, y) * Rational(z, h) << endl;
            } else if(a == '/') {
                cout << Rational(x, y) / Rational(z, h) << endl;
            } else if(a == '+') {
                cout << Rational(x, y) + Rational(z, h) << endl;
            } else if(a == '-') {
                cout << Rational(x, y) - Rational(z, h) << endl;
            }
        } catch(domain_error& d) {
            cout << d.what() << endl;
        }

    } else {
        if(a == '*') {
            cout << Rational(x, y) * Rational(z, h) << endl;
        } else if(a == '/') {
            cout << Rational(x, y) / Rational(z, h) << endl;
        } else if(a == '+') {
            cout << Rational(x, y) + Rational(z, h) << endl;
        } else if(a == '-') {
            cout << Rational(x, y) - Rational(z, h) << endl;
        }   
    }
    
    
    
    
    
    return 0;
}











