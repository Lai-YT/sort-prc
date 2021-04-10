#include <cstdlib>
#include <iostream>
#include <deque>

#include "heap_sort.hpp"

int main(int argc, char const *argv[]) {
  std::srand(time(0));
  // get radom array
  std::deque<int> arr(1000);
  for (int &n : arr) {
    n = std::rand() % 100000;
  }

  HeapSort(arr);

  // output result
  // for (auto n : arr) {
  //   std::cout << n << ' ';
  // }
  // std::cout << '\n';

  // order check
  bool s_flag = true;  // success flag
  for (size_t i = 1; i < arr.size() && s_flag; ++i) {
    if (arr.at(i) < arr.at(i - 1)) {
      std::cout << "Fail!" << '\n';
      s_flag = false;
    }
  }
  if (s_flag) {
    std::cout << "Success!" << '\n';
  }

  return 0;
}
