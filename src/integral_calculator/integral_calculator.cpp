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

IntegralCalculator::IntegralCalculator(long long intervals, int threads) {
  num_intervals = intervals;
  num_threads = threads;
  result = 0;
  computation_time = 0;
}

double IntegralCalculator::calculate_partial(long long start, long long end) {
  double dx = 1.0 / num_intervals;
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

  std::vector<double> results(num_threads);

  for (int i = 0; i < num_threads; ++i) {
    long long start = i * num_intervals / num_threads;
    long long end = (i + 1) * num_intervals / num_threads;

    threads.push_back(std::thread([this, start, end, i, &results]() {
      results[i] = calculate_partial(start, end);
      }));
  }

  for (auto& t : threads) {
    t.join();
  }

  result = 0;
  for (int i = 0; i < num_threads; i++) {
    result += results[i];
  }

  result *= 1.0 / num_intervals;

  auto end = std::chrono::high_resolution_clock::now();
  computation_time = std::chrono::duration<double>(end - start).count();
}

double IntegralCalculator::get_result() {
  return result;
}

double IntegralCalculator::get_computation_time() {
  return computation_time;
}
