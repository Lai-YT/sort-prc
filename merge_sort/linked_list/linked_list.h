#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct LinkedList {
  int size;
  struct Node *head;
};

typedef struct Node Node;
typedef struct LinkedList LinkedList;


void freeMemory(LinkedList list) {
  Node *curr = list.head;
  while (curr != NULL) {
    Node *temp = curr;
    curr = curr->next;
    free(temp);
  }
}

void printList (LinkedList const list) {
  Node *curr = list.head;
  while (curr) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}
