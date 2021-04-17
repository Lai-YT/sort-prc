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

  int left = 0, right = 0, total = head;
  // start merging. ascending order
  while (left < left_len && right < right_len) {
    if (left_arr[left] <= right_arr[right]) {
      arr[total++] = left_arr[left++];
    } else {
      arr[total++] = right_arr[right++];
    }
  }
  // if one side is used up, just put the other side back
  while (left < left_len) {
    arr[total++] = left_arr[left++];
  }
  while (right < right_len) {
    arr[total++] = right_arr[right++];
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
