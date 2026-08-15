#pragma once

#include "http_request.h"


#include <map>
#include <cstddef>
#include <unordered_set>
#include <iostream>


class Stats {
public:
    
    Stats();
    
    void AddMethod(std::string_view method);
    void AddUri   (std::string_view uri);
    const std::map<std::string_view, int>& GetMethodStats() const;
    const std::map<std::string_view, int>& GetUriStats() const;
    
private:
    std::map<std::string_view, int> MethodStats;
    std::map<std::string_view, int> UriStats;
};

HttpRequest ParseRequest(std::string_view line);
