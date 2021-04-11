#ifndef HEAP_SORT_H_
#define HEAP_SORT_H_

static inline void Swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// index 0 of the array is not used,
// which makes it more easy to calculate child nodes by index

void MaxHeapify(int *arr, int root, const int size) {
  // precedence of bit-wise shift(<<) is behind addition(+)
  int left = root << 1,
      right = (root << 1) + 1,
      largest = root;
  // check if root is bigger then the children
  if (left <= size && arr[left] > arr[largest]) {
    largest = left;
  }
  if (right <= size && arr[right] > arr[largest]) {
    largest = right;
  }
  // if largest == root, root is the biggest,
  // which means it's a max heap, no more swap is needed
  if (largest != root) {
    Swap(arr + root, arr + largest);
    MaxHeapify(arr, largest, size);
  }
}

void BuildMaxHeap(int *arr, const int size) {
  // through all those has child
  for (int i = size >> 1; i > 0; --i) {
    MaxHeapify(arr, i, size);
  }
}

void HeapSort(int *arr, const int size) {
  // because index 0 will not be sorted
  int *tech_arr = malloc(sizeof(int) * (size + 1));
  tech_arr[0] = 0;
  for (int i = 1; i <= size; ++i) {
    tech_arr[i] = arr[i - 1];
  }

  // make the array become max heap, so can sort
  BuildMaxHeap(tech_arr, size);

  // i > 1 because if only 1 remains, it's sorted
  for (int i = size; i > 1; --i) {
    // swap the leaf with the root
    Swap(tech_arr + 1, tech_arr + i);
    // omit the last one because it's in the sorted position
    MaxHeapify(tech_arr, 1, i - 1);
  }
  // remove index 0, since it's not part of the original arr
  for (int i = 0; i < size; ++i) {
    arr[i] = tech_arr[i + 1];
  }

  free(tech_arr);
}

#endif /* end of include guard: HEAP_SORT_H_ */
