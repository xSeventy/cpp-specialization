#include "unit_test_framework.h"
#include <cmath>

using namespace std;

int GetDistinctRealRootCount(double a, double b, double c) {
  // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
    if(a == 0) {
        // уравнение линейное bx + c = 0
        if(b != 0) {
            return 1;
        } else {
            return 0;
        }
    } else {
        int D = pow(b, 2) - 4 * a * c;
        if(sqrt(D) == 0) {
            return 1;
        } else if (D < 0) {
            return 0;
        } else {
            return 2;
        }
    }
    

}

void TestGetDistinctRealRootCount() {
    AssertEqual(GetDistinctRealRootCount(0, 2, 1), 1, "first");
    AssertEqual(GetDistinctRealRootCount(4, -2, -1), 2, "second");
    AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0, "third");
    AssertEqual(GetDistinctRealRootCount(1, 4, 4), 1, "fourth");
    AssertEqual(GetDistinctRealRootCount(-1, -4, -64), 0, "fifth");
    
    
    
}

//void TestFunction() {
//    AssertEqual(2 + 2, 4, "Basic math");
//    AssertEqual(5, 3 + 2, "Addition works");
//}


int main() {
    TestRunner tr;
    //tr.RunTest(TestFunction, "TestFunction");
    tr.RunTest(TestGetDistinctRealRootCount, "TestGetDistinctRealRootCount");
    
    return 0;
}