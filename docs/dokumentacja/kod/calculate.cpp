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
