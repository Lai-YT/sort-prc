#include <cstdlib>
#include <iostream>
#include <vector>

#include "quick_sort.hpp"

template<typename Container>
void CheckAscending(Container& arr) {

  for (size_t i = 1; i < arr.size(); ++i) {
    if (arr.at(i) < arr.at(i - 1)) {
      std::cout << "fail" << '\n';
      return;
    }
  }
  std::cout << "pass" << '\n';
}

int main(int argc, char const *argv[]) {
  std::srand(time(0));

  // get random array
  std::vector<int> arr(1000);
  for (int &n : arr) {
    n = std::rand() % 10000;
  }
  QuickSort(arr, 0, 1000);

  CheckAscending(arr);
}
