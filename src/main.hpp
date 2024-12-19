/**
 * @author Mateusz Basiaga (basmateusz@wp.pl)
 * @brief
 * @date 2024-12-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef MAIN_HPP
#define MAIN_HPP

int show_menu();

void run_benchmark(const std::string& name, int max_threads, long long max_intervals, int step = 1);

#endif /* MAIN_HPP */
