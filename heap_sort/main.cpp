#include <cstdlib>
#include <iostream>
#include <vector>

#include "heap_sort.hpp"

int main(int argc, char const *argv[]) {
  std::srand(time(0));
  // get radom array
  std::vector<int> arr(25);
  for (int &n : arr) {
    n = std::rand() % 100;
  }

  HeapSort(arr);

  // output result
  for (auto n : arr) {
    std::cout << n << ' ';
  }
  std::cout << '\n';

  // order check
  for (size_t i = 1; i < arr.size(); ++i) {
    if (arr.at(i) < arr.at(i - 1)) {
      std::cout << "Fail!" << '\n';
    }
  }
  std::cout << "Success!" << '\n';

  return 0;
}
