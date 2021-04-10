#ifndef HEAP_HPP_
#define HEAP_HPP_

#include <utility>
// compare deque with std::vector,
// push_front is more efficient than insert(begin, 0)
// and pop pop_front better than erase(begin)
#include <deque>

class Heap {
public:
  Heap(std::deque<int> &arr)
    :arr_(arr) {
    BuildMaxHeap();
  }

  void BuildMaxHeap() {
    // i > 0 because index 0 is not used
    for (size_t i = arr_.size() >> 1; i > 0; --i) {
      MaxHeapify(i, arr_.size() - 1);
    }
  }

  int& at(int index) {
    return arr_.at(index);
  }

  int size() const {
    return arr_.size();
  }

  void Sort() {
    // because index 0 will not be sorted
    arr_.push_front(0);
    // make the array become max heap, so can sort
    BuildMaxHeap();

    size_t size = arr_.size() - 1;
    // i > 1 because if only 1 remains, it's sorted
    for (size_t i = size; i > 1; --i) {
      // swap the leaf with the root
      std::swap(arr_.at(1), arr_.at(i));
      // omit the last one because it's in the sorted position
      MaxHeapify(1, --size);
    }
    // remove index 0, since it's not part of the original arr
    arr_.pop_front();
  }

private:
  std::deque<int> arr_;

  void MaxHeapify(int root, size_t size) {
    // precedence of bit-wise shift(<<) is behind addition(+)
    int left = root << 1,
        right = (root << 1) + 1,
        largest = root;
    // check if root is bigger then the children
    if (left <= size && arr_.at(left) > arr_.at(largest)) {
      largest = left;
    }
    if (right <= size && arr_.at(right) > arr_.at(largest)) {
      largest = right;
    }
    // if largest == root, root is the biggest,
    // which means it's a max heap, no more swap is needed
    if (largest != root) {
      std::swap(arr_.at(root), arr_.at(largest));
      MaxHeapify(largest, size);
    }
  }
};

#endif /* end of include guard: HEAP_HPP_ */
