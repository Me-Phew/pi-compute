/**
 * @author Mateusz Basiaga (basmateusz@wp.pl)
 * @brief
 * @date 2024-12-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "integral_calculator.hpp"
#include <iostream>
#include <thread>
#include <vector>
#include <cmath>

IntegralCalculator::IntegralCalculator(long long intervals, int threads) : numIntervals(intervals), numThreads(threads), result(0), computationTime(0) {}

double IntegralCalculator::calculatePartial(long long start, long long end) {
  double dx = 1.0 / numIntervals;
  double sum = 0;

  for (long long i = start; i < end; ++i) {
    double x = (i + 0.5) * dx;
    sum += 4.0 / (1.0 + x * x);
  }

  return sum;
}

void IntegralCalculator::calculate() {
  auto start = std::chrono::high_resolution_clock::now();
  std::vector<std::thread> threads;

  std::vector<double> results(numThreads);

  for (int i = 0; i < numThreads; ++i) {
    long long start = i * numIntervals / numThreads;
    long long end = (i + 1) * numIntervals / numThreads;

    threads.push_back(std::thread([this, start, end, i, &results]() {
      results[i] = calculatePartial(start, end);
      }));
  }

  for (auto& t : threads) {
    t.join();
  }

  result = 0;
  for (int i = 0; i < numThreads; i++) {
    result += results[i];
  }

  result *= 1.0 / numIntervals;

  auto end = std::chrono::high_resolution_clock::now();
  computationTime = std::chrono::duration<double>(end - start).count();
}

double IntegralCalculator::getResult() {
  return result;
}

double IntegralCalculator::getComputationTime() {
  return computationTime;
}
