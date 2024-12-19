#include <algorithm>

#include "utils.hpp"

std::string formatNumber(double number) {
  std::string result = std::to_string(number);
  std::replace(result.begin(), result.end(), '.', ',');
  return result;
}
