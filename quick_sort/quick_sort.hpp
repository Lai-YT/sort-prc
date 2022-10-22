#ifndef QUICK_SORT_HPP_
#define QUICK_SORT_HPP_

#include <iostream>
#include <utility>
#include <vector>

using Index = int;

template<typename T>
Index Partition(std::vector<T>& arr, const Index front, const Index rear) {
  const T pivot = arr.at(rear - 1);
  Index sp = front;
  for (Index i = front; i < rear; ++i) {
    if (arr.at(i) <= pivot) {
      std::swap(arr.at(sp++), arr.at(i));
    }
  }
  // the pivot is swapped into where it should be in the last iteration
  // since pivot (rear - 1) == pivot
  return sp - 1;
}

// rear is excluded
template<typename T>
void QuickSort(std::vector<T>& arr, const Index front, const Index rear) {
  if (rear <= front) return;
  const Index mid = Partition(arr, front, rear);
  // mid is the true middle of sub-arr, no more move
  QuickSort(arr, front, mid);
  QuickSort(arr, mid + 1, rear);
}

#endif /* end of include guard: QUICK_SORT_HPP_ */
