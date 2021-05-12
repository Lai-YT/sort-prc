from __future__ import annotations
from typing import List


class Node:
    """
    val: float
    next: Node
    """
    def __init__(self, val: float = 0, next: Node = None):
        self.val: float = val
        self.next: Node = next

    def __str__(self) -> str:
        return str(self.val)


class SinglyLinkedList:
    """
    head: Node
    """
    def __init__(self):
        self.front = None
        self.back = None

    def push_front(self, val: float) -> None:
        new_node = Node(val)
        if self.front is None:
            self.front = new_node
            self.back = new_node
        else:
            new_node.next = self.front
            self.front = new_node

    def push_back(self, val: float) -> None:
        new_node = Node(val)
        if self.front is None:
            self.front = new_node
            self.back = new_node
        else:
            self.back.next = new_node
            self.back = new_node

    def pop_front(self) -> None:
        if not self.front:
            return
        self.front, self.front.next = self.front.next, None

    def pop_back(self) -> None:
        if not self.front:
            return
        curr = self.front
        while curr.next != self.back:
            curr = curr.next
        curr.next = None
        self.back = curr

    def __str__(self) -> str:
        string: List[str] = []
        curr = self.front
        while curr:
            string.append(str(curr))
            curr = curr.next
            if curr:
                string.append('->')

        return ''.join(string)
