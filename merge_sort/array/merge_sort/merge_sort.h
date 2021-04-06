#include <stdio.h>

/* this method modifies the input array */

void merge(int *arr, int const head, int const mid, int const tail) {
  int const left_length = mid - head + 1, right_length = tail - mid;
  // copy the data, which will be put back into arr
  int left_arr[left_length], right_arr[right_length];
  for (int i = 0; i < left_length; i++) {
    left_arr[i] = arr[head + i];
  }
  for (int i = 0; i < right_length; i++) {
    right_arr[i] = arr[mid + 1 + i];
  }

  int left_index = 0, right_index = 0, total_index = head;
  // start merging. ascending order
  while (left_index < left_length && right_index < right_length) {
    if (left_arr[left_index] <= right_arr[right_index]) {
      arr[total_index++] = left_arr[left_index++];
    } else {
      arr[total_index++] = right_arr[right_index++];
    }
  }
  // if one side is used up, just put the other side back
  while (left_index < left_length) {
    arr[total_index++] = left_arr[left_index++];
  }
  while (right_index < right_length) {
    arr[total_index++] = right_arr[right_index++];
  }
}

// by recursion, divide until single and then merge
void merge_sort(int *arr, int const head, int const tail) {
  if (head < tail) {
    int mid = (tail + head) / 2;
    merge_sort(arr, head, mid);
    merge_sort(arr, mid + 1, tail);
    // each side is already sorted in the previous recursion
    merge(arr, head, mid, tail);
  }
}
