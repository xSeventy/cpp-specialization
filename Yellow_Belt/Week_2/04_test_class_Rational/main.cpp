#include "unit_test_framework.h"

 
using namespace std;



int GCD(int a, int b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return abs(a);
}

class Rational {
public:
  // Вы можете вставлять сюда различные реализации,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный

    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        p = numerator;
        q = denominator;

        p = p / GCD(numerator, denominator);
        q = q / GCD(numerator, denominator);


        if (q < 0) {
            q = abs(q);
            p = -p;
        } else if (p == 0) {
            q = 1;
        }
    }

  int Numerator() const {
      return p;
  }

  int Denominator() const {
      return q;
  }

private:
    int p, q;
};

void TestAll() {
    Rational r;
    AssertEqual(r.Numerator(), 0, "second");
    AssertEqual(r.Denominator(), 1, "first");

    Rational ra(3, 6);
    AssertEqual(ra.Numerator(), 1, "third");
    AssertEqual(ra.Denominator(), 2, "fourth");
    
    Rational rat(3, -6);
    AssertEqual(rat.Numerator(), -1, "fifth");
    AssertEqual(rat.Denominator(), 2, "sixth");
    
    Rational rati(-3, -6);
    AssertEqual(rati.Numerator(), 1, "seventh");
    AssertEqual(rati.Denominator(), 2, "eighth");
    
    Rational ratio(0, -5);
    AssertEqual(ratio.Numerator(), 0, "nineth");
    AssertEqual(ratio.Denominator(), 1, "tenth");
    
    //Rational ration(6, 7);
    //AssertEqual(ration.Numerator(), 6, "eleventh");
    //AssertEqual(ration.Denominator(), 7, "twelveth");
    //
    //Rational rationa(-3, 6);
    //AssertEqual(rationa.Numerator(), -1, "thirteenth");
    //AssertEqual(rationa.Denominator(), 2, "fourteenth");
}

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
    runner.RunTest(TestAll, "TestAll");
  return 0;
}

