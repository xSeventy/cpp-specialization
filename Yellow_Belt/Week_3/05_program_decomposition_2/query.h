#pragma once

#include <string>
#include <istream>
#include <vector>



enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  std::string bus, stop;
  std::vector<std::string> stops;
};

std::istream& operator >> (std::istream& is, Query& q);
