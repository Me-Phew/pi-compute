/**
 * @author Mateusz Basiaga (basmateusz@wp.pl)
 * @brief
 * @date 2024-12-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef INTEGRAL_CALCULATOR_HPP
#define INTEGRAL_CALCULATOR_HPP

#include <vector>
#include <chrono>

class IntegralCalculator {

private:
  long long num_intervals;
  int num_threads;
  double result;
  double computation_time;

  double calculate_partial(long long start, long long end);

public:
  IntegralCalculator(long long intervals, int threads);

  void calculate();

  double get_result();

  double get_computation_time();
};

#endif /* INTEGRAL_CALCULATOR_HPP */
