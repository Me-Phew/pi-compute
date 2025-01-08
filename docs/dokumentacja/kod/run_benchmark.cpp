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
