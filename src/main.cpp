/**
 * @author Mateusz Basiaga (basmateusz@wp.pl)
 * @brief
 * @date 2024-12-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <fstream>

#include "main.hpp"
#include "integral_calculator/integral_calculator.hpp"
#include "utils/utils.hpp"

int main(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--benchmark") {
    run_benchmark("benchmark_1", 50, 100'000'000);
    run_benchmark("benchmark_2", 50, 1'000'000'000);
    run_benchmark("benchmark_3", 50, 3'000'000'000);
    run_benchmark("benchmark_4", 50, 10'000'000'000);

    return 0;
  }

  return show_menu();
}

void run_benchmark(const std::string& name, int max_threads, long long max_intervals, int step) {
  std::ofstream file;
  file.open(name + ".csv");

  std::cout << "Running benchmark: " << name << " (" << max_intervals << " intervals)" << std::endl;

  double totalTime = 0;

  for (int i = 1; i <= max_threads; i += step) {
    std::cout << "Computing using " << i << " threads..." << std::endl;

    IntegralCalculator integralCalculator(max_intervals, i);
    integralCalculator.calculate();

    double computationTime = integralCalculator.getComputationTime();
    totalTime += computationTime;

    std::string formattedResult = formatNumber(computationTime);

    file << i << ", " << formattedResult << std::endl;
    std::cout << i << " threads finished in " << formattedResult << " seconds" << std::endl;
  }

  file.close();
  std::cout << "Completed benchmark: " << name << " in " << totalTime << " seconds" << std::endl;
  std::cout << std::endl;
}

int show_menu() {
  long long intervals;
  std::cout << "Podaj liczbe przedzialow: ";
  std::cin >> intervals;

  long long threads;
  std::cout << "Podaj liczbe watkow: ";
  std::cin >> threads;

  IntegralCalculator integralCalculator(intervals, threads);
  integralCalculator.calculate();

  std::cout << "PI ~=" << integralCalculator.getResult() << std::endl;
  std::cout << "Czas obliczen: " << integralCalculator.getComputationTime() << " sekund" << std::endl;

  return 0;
}
