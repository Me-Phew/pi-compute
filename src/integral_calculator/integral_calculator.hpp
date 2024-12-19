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
  long long numIntervals;
  int numThreads;
  double result;
  double computationTime;

  double calculatePartial(long long start, long long end);

public:
  IntegralCalculator(long long intervals, int threads);

  void calculate();

  double getResult();

  double getComputationTime();
};

#endif /* INTEGRAL_CALCULATOR_HPP */
