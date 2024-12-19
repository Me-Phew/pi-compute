/**
 * @author Mateusz Basiaga (basmateusz@wp.pl)
 * @brief
 * @date 2024-12-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include "integral_calculator/integral_calculator.hpp"

int main() {
  long long intervals;
  std::cout << "Podaj liczbe przedzialow: ";
  std::cin >> intervals;

  long long threads;
  std::cout << "Podaj liczbe watkow: ";
  std::cin >> threads;

  IntegralCalculator integralCalculator(intervals, threads);
  integralCalculator.calculate();

  std::cout << "PI ~=" << integralCalculator.get_result() << std::endl;
  std::cout << "Czas obliczen: " << integralCalculator.get_computation_time() << " sekund" << std::endl;
}
