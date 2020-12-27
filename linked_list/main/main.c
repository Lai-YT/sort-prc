#include "../MergeSort/merge_sort.h"

int main(int argc, char const *argv[]) {
  int size_of_list = 0;
  scanf("%d", &size_of_list);
  LinkedList list = {
    .head = NULL,
    .size = size_of_list
  };
  for (int i = 0; i < list.size; i++) {
    Node *newNode = malloc (sizeof(Node));
    newNode->data = i;
    newNode->next = list.head;
    list.head = newNode;
  }
  LinkedList newList = MergeSort(list);
  printList(newList);
  freeMemory(newList);
  return 0;
}
