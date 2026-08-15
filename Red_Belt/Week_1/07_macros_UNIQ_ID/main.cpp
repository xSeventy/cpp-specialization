#include "test_runner.h"

using namespace std;


// Реализуйте этот макрос так, чтобы функция main компилировалась

// вспомогательный: раскрывает аргумент, а потом склеивает
#define JOIN_IMPL(a, b) a##b
#define JOIN(a, b) JOIN_IMPL(a, b)

// удобный макрос для создания уникального имени
#define UNIQ_ID JOIN(base, __LINE__)


int main() {
  int UNIQ_ID = 0;
  string UNIQ_ID = "hello";
  vector<string> UNIQ_ID = {"hello", "world"};
  vector<int> UNIQ_ID = {1, 2, 3, 4};
}
