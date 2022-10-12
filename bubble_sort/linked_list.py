from __future__ import annotations
from functools import wraps
from typing import Callable


class Node:
    """
    val: float
    next: Node
    """
    def __init__(self, val: float, next: Node | None = None) -> None:
        self.val = val
        self.next = next

    def __str__(self) -> str:
        return str(self.val)


def list_invariant(method: Callable):
    @wraps(method)
    def wrapper(self, *args, **kwargs):
        res = method(self, *args, **kwargs)
        # front and back should both be None or both not None
        assert bool(self.front is None) == bool(self.back is None)
        return res
    return wrapper


class SinglyLinkedList:
    """
    head: Node
    """
    def __init__(self) -> None:
        self.front: Node | None = None
        self.back: Node | None = None

    @list_invariant
    def push_front(self, val: float) -> None:
        new_node = Node(val)
        if self.is_empty():
            self.front = new_node
            self.back = new_node
        else:
            new_node.next = self.front
            self.front = new_node

    @list_invariant
    def push_back(self, val: float) -> None:
        new_node = Node(val)
        if self.is_empty():
            self.front = new_node
            self.back = new_node
        else:
            self.back.next = new_node
            self.back = new_node

    @list_invariant
    def pop_front(self) -> None:
        if self.is_empty():
            return
        self.front = self.front.next

    @list_invariant
    def pop_back(self) -> None:
        if self.is_empty():
            return
        curr: Node = self.front
        while curr.next != self.back:
            curr = curr.next
        curr.next = None
        self.back = curr

    @list_invariant
    def is_empty(self) -> bool:
        return self.front is None

    @list_invariant
    def __str__(self) -> str:
        string: list[str] = []
        curr: Node | None = self.front
        while curr is not None:
            string.append(str(curr))
            curr = curr.next

        return '->'.join(string)
