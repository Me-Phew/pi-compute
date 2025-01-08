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
