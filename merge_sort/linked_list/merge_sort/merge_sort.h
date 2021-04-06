#include "./linked_list.h"

LinkedList Merge(LinkedList leftList, LinkedList rightList) {
  Node *leftCurr = leftList.head, *rightCurr = rightList.head;
  LinkedList newList = {
    .head = NULL,
    .size = leftList.size + rightList.size
  };
  if (leftCurr->data < rightCurr->data) {
    newList.head = leftCurr;
    leftCurr = leftCurr->next;
  } else {
    newList.head = rightCurr;
    rightCurr = rightCurr->next;
  }
  Node *tail = newList.head;
  while (leftCurr && rightCurr) {
    if (leftCurr->data < rightCurr->data) {
      tail->next = leftCurr;
      tail = tail->next;
      leftCurr = leftCurr->next;
    } else {
      tail->next = rightCurr;
      tail = tail->next;
      rightCurr = rightCurr->next;
    }
  }
  if (leftCurr)
    tail->next = leftCurr;
  else if (rightCurr)
    tail->next = rightCurr;

  return newList;
}

LinkedList MergeSort(LinkedList list) {
  if (list.size == 1) {
    return list;
  }
  Node *temp = list.head;
  for (int i = 0; i < list.size / 2 - 1; i++) {
    temp = temp->next;
  }
  Node *mid = temp->next;
  temp->next = NULL;

  LinkedList leftList = {
    .head = list.head,
    .size = list.size / 2
  };
  LinkedList rightList = {
    .head = mid,
    .size = list.size - list.size / 2
  };
  return Merge(MergeSort(leftList), MergeSort(rightList));
}
