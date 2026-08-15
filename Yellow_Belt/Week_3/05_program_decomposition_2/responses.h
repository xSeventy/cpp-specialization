#pragma once

#include <map>
#include <ostream>
#include <string>
#include <vector>

struct BusesForStopResponse {
    std::vector<std::string> stop_buses;
};

std::ostream& operator<<(
    std::ostream& os,
    const BusesForStopResponse& r
);

struct StopsForBusResponse {
    std::map<std::string, std::vector<std::string>> stop_buses;
    std::vector<std::string> bus_stops;
    std::string bus;
};

std::ostream& operator<<(
    std::ostream& os,
    const StopsForBusResponse& r
);

struct AllBusesResponse {
    std::map<std::string, std::vector<std::string>> bus_stops;
};

std::ostream& operator<<(
    std::ostream& os,
    const AllBusesResponse& r
);