#include <stdio.h>

/* this method modifies the input array */

void merge(int *arr, int const head, int const mid, int const tail) {
  int const left_len = mid - head + 1, right_len = tail - mid;
  // copy the data, which will be put back into arr
  int left_arr[left_len], right_arr[right_len];
  for (int i = 0; i < left_len; i++) {
    left_arr[i] = arr[head + i];
  }
  for (int i = 0; i < right_len; i++) {
    right_arr[i] = arr[mid + 1 + i];
  }

  int left_idx = 0, right_idx = 0, total_idx = head;
  // start merging. ascending order
  while (left_idx < left_len && right_idx < right_len) {
    if (left_arr[left_idx] <= right_arr[right_idx]) {
      arr[total_idx++] = left_arr[left_idx++];
    } else {
      arr[total_idx++] = right_arr[right_idx++];
    }
  }
  // if one side is used up, just put the other side back
  while (left_idx < left_len) {
    arr[total_idx++] = left_arr[left_idx++];
  }
  while (right_idx < right_len) {
    arr[total_idx++] = right_arr[right_idx++];
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
