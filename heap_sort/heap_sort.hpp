#include <iostream>
#include <utility>
#include <vector>

void MaxHeapify(std::vector<int> &arr, int root, size_t size) {
  int left = root * 2, right = root * 2 + 1, largest = root;
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

// index 0 of the array is not used,
// which makes it more easy to calculate child nodes by index

void BuildMaxHeap(std::vector<int> &arr) {
  // i > 0 because index 0 is not used
  for (size_t i = arr.size() / 2; i > 0; --i) {
    MaxHeapify(arr, i, arr.size() - 1);
  }
}

void HeapSort(std::vector<int> &arr) {
  // because index 0 will not be sorted
  arr.insert(arr.begin(), 0);
  // make the array become max heap, so can sort
  BuildMaxHeap(arr);

  size_t size = arr.size() - 1;
  // i > 1 because if only 1 remains, it's sorted
  for (size_t i = size; i > 1; --i) {
    // swap the leaf with the root
    std::swap(arr.at(1), arr.at(i));
    // omit the last one because it's in the sorted position
    MaxHeapify(arr, 1, --size);
  }
  // remove index 0, since it's not part of the original arr
  arr.erase(arr.begin());
}
