#include "phone_number.h"
#include <sstream>

using namespace std;


PhoneNumber::PhoneNumber(const string &international_number) {
    
    stringstream ss(international_number);
    char res;
    ss.get(res);
    if(res != '+') {
        throw invalid_argument("first symbol is not +");
    }

    // Считываем код страны
    getline(ss, country_code_, '-');
    if (country_code_.empty()) {
        throw invalid_argument("incorrect country code");
    }

    // Проверяем, что '-' был в потоке
    if (ss.fail()) {
        throw invalid_argument("expected '-' after country code");
    }

    // Считываем код города
    getline(ss, city_code_, '-');
    if (city_code_.empty()) {
        throw invalid_argument("incorrect city code");
    }

    // Проверяем, что '-' был в потоке
    if (ss.fail()) {
        throw invalid_argument("expected '-' after city code");
    }

    // Считываем оставшийся локальный номер
    getline(ss, local_number_);
    if (local_number_.empty()) {
        throw invalid_argument("incorrect local number");
    }
    
    
}


string PhoneNumber::GetCountryCode() const {
    return country_code_;
}

string PhoneNumber::GetCityCode() const {
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}
