#ifndef HEAP_SORT_HPP_
#define HEAP_SORT_HPP_

// compare deque with std::vector,
// push_front is more efficient than insert(begin, 0)
// and pop pop_front better than erase(begin)
#include <deque>
#include <utility>

// index 0 of the array is not used,
// which makes it more easy to calculate child nodes by index

using Index = int;

void MaxHeapify(std::deque<int> &arr, Index root, const size_t size) {
  Index largest = root;
  Index left = root << 1;
  // precedence of bit-wise shift(<<) is behind addition(+)
  Index right = (root << 1) + 1;

  // check if root is bigger then the children
  if (left <= size && arr.at(left) > arr.at(largest)) {
    largest = left;
  }
  if (right <= size && arr.at(right) > arr.at(largest)) {
    largest = right;
  }
  // if largest == root, root is the biggest,
  // which means it's a max heap, no more swap is needed
  if (largest != root) {
    std::swap(arr.at(root), arr.at(largest));
    MaxHeapify(arr, largest, size);
  }
}

void BuildMaxHeap(std::deque<int> &arr) {
  // i > 0 because index 0 is not used
  for (Index i = arr.size() >> 1; i > 0; --i) {
    MaxHeapify(arr, i, arr.size() - 1);
  }
}

void HeapSort(std::deque<int> &arr) {
  // because index 0 will not be sorted
  arr.push_front(0);
  // make the array become max heap, so can sort
  BuildMaxHeap(arr);

  // i > 1 because if only 1 remains, it's sorted
  for (Index i = arr.size() - 1; i > 1; --i) {
    // Swap the root (with is the current max) to i.
    // In each iteration, we obtained that i ... arr.size() - 1 is sorted,
    // so when i == 1, we're done.
    std::swap(arr.at(1), arr.at(i));
    MaxHeapify(arr, 1, i - 1);
  }
  // remove index 0, since it's not part of the original arr
  arr.pop_front();
}

#endif /* end of include guard: HEAP_SORT_HPP_ */
