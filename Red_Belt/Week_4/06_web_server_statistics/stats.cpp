#include "stats.h"

#include <cstddef>
#include <unordered_set>

using namespace std;


Stats::Stats() {
    MethodStats = {{"GET", 0}, {"POST", 0}, {"DELETE", 0}, {"PUT", 0}, {"UNKNOWN", 0}};
    UriStats = {{"/", 0}, {"/order", 0}, {"/product", 0}, {"/basket", 0}, {"/help", 0}, {"unknown", 0}};
}

void Stats::AddMethod(string_view method) {
    if(MethodStats.count(method)) {
        MethodStats[method]++;
    } else {
        MethodStats["UNKNOWN"]++;
    }
}

void Stats::AddUri(string_view uri) {
    if(UriStats.count(uri)) {
        UriStats[uri]++;
    } else {
        UriStats["unknown"]++;
    }
}

const map<string_view, int>& Stats::GetMethodStats() const {
    return MethodStats;
}

const map<string_view, int>& Stats::GetUriStats() const {
    return UriStats;
}



HttpRequest ParseRequest(string_view line) {
    HttpRequest hr;
    
    while (!line.empty() && line.front() == ' ') {
        line.remove_prefix(1);
    }

    size_t space = line.find(' ');
    hr.method = line.substr(0, space);
    line.remove_prefix(space + 1);
    

    space = line.find(' ');
    hr.uri = line.substr(0, space);
    line.remove_prefix(space + 1);
    
    hr.protocol = line;
    
    
    return hr;
    
    
}
