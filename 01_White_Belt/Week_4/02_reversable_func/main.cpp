#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class FunctionPart {
public:
    FunctionPart(const char& new_operation, const double& new_value) {
        operation = new_operation;
        value = new_value;
    }
    
    double Apply(const double& source_value) const {
        if(operation == '+') {
            return source_value + value;
        } else {
            return source_value - value;
        }
    }
    
    void Invert() {
        if(operation == '+') {
            operation = '-';
        } else {
            operation = '+';
        }
    }
    
private:
    char operation;
    double value;
};

class Function {
public:
    void AddPart(const char& operation, const double& result) {
        parts.push_back({operation, result});
    }
    double Apply(double value) const {
        for(const FunctionPart& part : parts) {
            value = part.Apply(value);
        }
        return value;
    }
    
    void Invert() {
        for (FunctionPart& part : parts) {
            part.Invert();
        }
        reverse(parts.begin(), parts.end());
    }
    
private:
    vector<FunctionPart> parts;
};




