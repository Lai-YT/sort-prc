#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../merge_sort/merge_sort.h"

int main(int argc, char const *argv[]) {
  // give a random array with length 50
  srand(time(NULL));
  int arr[50];
  for (int i = 0; i < 50; i++) {
    arr[i] = (rand() % 50) + 1;
  }
  merge_sort(arr, 0, 49);
  for (int i = 0; i < 49; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
