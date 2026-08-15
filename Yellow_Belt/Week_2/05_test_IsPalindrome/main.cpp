#include "unit_test_framework.h"

 
using namespace std;


bool IsPalindrome(const string& str) {
  // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
    for(size_t i = 0; i < str.size() / 2; i++) {
        if(str[i] != str[str.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

void TestAll() {
    AssertEqual(IsPalindrome(""), true, "1");
    AssertEqual(IsPalindrome("c"), true, "2");
    AssertEqual(IsPalindrome("aca"), true, "3");
    AssertEqual(IsPalindrome("acdca"), true, "4");
    AssertEqual(IsPalindrome("AccA"), true, "5");
    AssertEqual(IsPalindrome("caZaZac"), true, "6");
    AssertEqual(IsPalindrome("++C++"), true, "7");
    AssertEqual(IsPalindrome("aBCBa"), true, "8");
    AssertEqual(IsPalindrome("   aBCBa   "), true, "9");
    AssertEqual(IsPalindrome("   aBcBa   "), true, "10");
    AssertEqual(IsPalindrome("a B c B a"), true, "11");
    AssertEqual(IsPalindrome("MalayalaM"), true, "12");
    AssertEqual(IsPalindrome("\t\n  \n\t"), true, "13");
    AssertEqual(IsPalindrome("abcdefghijklmnopqrstuvwxyzzyxwvutsrqponmlkjihgfedcba"), true, "14");
    
    AssertEqual(IsPalindrome("VC"), false, "15");
    AssertEqual(IsPalindrome("VVddVC"), false, "16");
    AssertEqual(IsPalindrome("VVddCV"), false, "17");
    AssertEqual(IsPalindrome("VCddVV"), false, "18");
    AssertEqual(IsPalindrome("CVddVV"), false, "19");
    AssertEqual(IsPalindrome("cvDdvc"), false, "20");
    AssertEqual(IsPalindrome("cvdDvc"), false, "21");
    AssertEqual(IsPalindrome("Cvddvc"), false, "22");
    AssertEqual(IsPalindrome("cvddvC"), false, "23");
    AssertEqual(IsPalindrome("cvddVc"), false, "24");
    AssertEqual(IsPalindrome("cVddvc"), false, "25");
    AssertEqual(IsPalindrome("abcdefghijklmnopqrstuvwxyzzyxwvutsrqponmlkjihgfedcbb"), false, "26");
    AssertEqual(IsPalindrome("   CVddVC"), false, "27");
    AssertEqual(IsPalindrome("CVddVC   "), false, "28");

    
}

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
    runner.RunTest(TestAll, "TestAll");
  return 0;
}

