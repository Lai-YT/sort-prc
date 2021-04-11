#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "heap_sort.h"

int main(int argc, char const *argv[]) {
  srand(time(0));

  int arr[1000] = {0};
  for (int i = 0; i < 1000; ++i) {
    arr[i] = rand() % 10000;
  }

  HeapSort(arr, 1000);

  bool s_flag = true;
  for (int i = 1; i < 1000 && s_flag; ++i) {
    if (arr[i] < arr[i - 1]) {
      printf("fail\n");
      s_flag = false;
    }
  }
  if (s_flag) {
    printf("pass\n");
  }

  return 0;
}
