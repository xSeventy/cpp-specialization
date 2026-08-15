#include "test_runner.h"

using namespace std;

#define PRINT_VALUES(out, x, y)            \
    do {                                   \
        (out) << (x) << endl;              \
        (out) << (y) << endl;              \
    } while (0)




void Test () {
    TestRunner tr;
    stringstream output;
    
    vector<int> v = {1,2,3};
    PRINT_VALUES(output, v, "lol");
    ASSERT_EQUAL(output.str(), "{1, 2, 3}\nlol\n");
    
    
    
}


int main() {
    TestRunner tr;
    RUN_TEST(tr, Test);
    
    stringstream output;
    bool b = true;
    int y = 1;
    
    if(b)
        PRINT_VALUES(output, b, y);
    else
        cout << "lol" << endl;
    
    cout << output.str();
    
}


// PRINT_VALUES(output, 5, "red belt");
// ASSERT_EQUAL(output.str(), "5\nred belt\n");
//
