#include <iostream>
#include <string>



bool IsPalindrome(const std::string& str) {
    if (str.empty()) {
        return true;
    }

    size_t mid = str.size() / 2;
    size_t last = str.size() - 1;
    for (size_t i = 0; i < mid; i++) {
        if (str[i] != str[last - i]) {
            return false;
        }
    }
    
    return true;
}