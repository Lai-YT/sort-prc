#include <cstdlib>
#include <deque>
#include <iostream>

#include "heap.hpp"
#include "heap_sort.hpp"

template<typename Container>
void CheckAscending(Container& arr) {

  for (size_t i = 1; i < arr.size(); ++i) {
    if (arr.at(i) < arr.at(i - 1)) {
      std::cout << "Fail!" << '\n';
      return;
    }
  }
  std::cout << "Success!" << '\n';
}

int main(int argc, char const *argv[]) {
  std::srand(time(0));

  {
    // get radom array
    std::deque<int> arr(1000);
    for (int &n : arr) {
      n = std::rand() % 100000;
    }

    HeapSort(arr);

    CheckAscending(arr);
  }

  //-----Heap-----

  {
    std::deque<int> arr(1000);
    for (int &n : arr) {
      n = std::rand() % 100000;
    }

    Heap<int> heap(arr);
    heap.Sort();

    CheckAscending(heap);

    for (size_t i = 0; i < 100; ++i) {
      heap.Append(std::rand() % 100);
    }

    heap.Sort();

    CheckAscending(heap);
  }

  return 0;
}
