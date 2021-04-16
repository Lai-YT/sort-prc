#ifndef QUICK_SORT_HPP_
#define QUICK_SORT_HPP_

#include <iostream>
#include <vector>
#include <utility>

template<typename T>
int Partition(std::vector<T>& arr, const int front, const int rear) {

  const T pivot = arr.at(rear - 1);
  int sp = front;
  for (size_t i = front; i < rear; ++i) {
    if (arr.at(i) <= pivot) {
      std::swap(arr.at(sp++), arr.at(i));
    }
  }
  return sp - 1;
}

// rear is excluded
template<typename T>
void QuickSort(std::vector<T>& arr, const int front, const int rear) {
  if (rear <= front) return;
  int mid = Partition(arr, front, rear);
  // mid is the true middle of sub-arr, no more move
  QuickSort(arr, front, mid);
  QuickSort(arr, mid + 1, rear);
}

#endif /* end of include guard: QUICK_SORT_HPP_ */
