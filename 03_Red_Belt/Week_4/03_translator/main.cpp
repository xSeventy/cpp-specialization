#include "test_runner.h"

#include <string_view>

#include <utility>
#include <unordered_map>

using namespace std;

class Translator {
public:
    void Add(string_view source, string_view target) {
        auto it1 = s.insert(string(source));
        auto it2 = s.insert(string(target));
        string_view source_ = *it1.first;
        string_view target_ = *it2.first;
        
        forw[source_] = target_;
        backw[target_] = source_;
        
    }
    
    string_view TranslateForward(string_view source) const {
        if(forw.count(source)) {
            return forw.at(source);
        }
        return "";
    }
    
    string_view TranslateBackward(string_view target) const {
        if(backw.count(target)) {
            return backw.at(target);
        }
        return "";
    }
    
private:
    unordered_map<string_view, string_view> forw;
    unordered_map<string_view, string_view> backw;
    set<string> s;
    
    //vector<pair<string_view, string_view>> v;
};

void TestSimple() {
    Translator translator;
    translator.Add(string("okno"), string("window"));
    translator.Add(string("stol"), string("table"));
    
    
    ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
    ASSERT_EQUAL(translator.TranslateForward("window"), "");
    ASSERT_EQUAL(translator.TranslateBackward("okno"), "");
    ASSERT_EQUAL(translator.TranslateBackward("window"), "okno");
    
    
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestSimple);
    
    
    
    return 0;
}
