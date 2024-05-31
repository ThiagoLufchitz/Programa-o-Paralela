#include <iostream>
#include <numeric>
#include <vector>
#include <chrono>

#include "src/lib/utility.h"

// A demo for creating two threads
// Run this using one of the following methods:
//  1. With bazel: bazel run src/main:main
//  2. With plain g++: g++ -std=c++17 -lpthread src/main/main.cc  -I ./
int main() {
  //const int number_of_threads = 2;
  const int number_of_elements = 1000 * 1000 * 1000;
  //const int step = number_of_elements / number_of_threads;
  std::vector<uint64_t> partial_sums(1);

  //std::thread t1(AccumulateRange, std::ref(partial_sums[0]), 0, step);
  //std::thread t2(AccumulateRange, std::ref(partial_sums[1]), step,
  //               number_of_threads * step);

  //t1.join();
  //t2.join();
  auto st = std::chrono::high_resolution_clock::now();
  AccumulateRange(partial_sums[0],0,number_of_elements);
  


  uint64_t total = std::accumulate(partial_sums.begin(), partial_sums.end(), uint64_t(0));
  auto fn = std::chrono::high_resolution_clock::now();
  PrintVector(partial_sums); // Prints partial_sums
  std::cout << "total: " << total << std::endl;

  std::chrono::duration<double, std::milli> ms_double = fn - st;

  std::cout << ms_double.count() << "ms";

  return 0;
}