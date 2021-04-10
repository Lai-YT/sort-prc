#include <cstdlib>
#include <iostream>
#include <deque>

#include "heap.hpp"
#include "heap_sort.hpp"

int main(int argc, char const *argv[]) {
  std::srand(time(0));

  {
    // get radom array
    std::deque<int> arr(1000);
    for (int &n : arr) {
      n = std::rand() % 100000;
    }

    HeapSort(arr);

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
  }

  //-----Heap-----

  {
    std::deque<int> arr(25);
    for (int &n : arr) {
      n = std::rand() % 100;
    }

    Heap heap(arr);
    heap.Sort();

    // order check
    bool s_flag = true;  // success flag
    for (size_t i = 1; i < heap.size() && s_flag; ++i) {
      if (heap.at(i) < heap.at(i - 1)) {
        std::cout << "Fail!" << '\n';
        s_flag = false;
      }
    }
    if (s_flag) {
      std::cout << "Success!" << '\n';
    }
  }
  return 0;
}
