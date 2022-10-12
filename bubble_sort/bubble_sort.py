from __future__ import annotations
from typing import TYPE_CHECKING

from linked_list import SinglyLinkedList

if TYPE_CHECKING:
    from linked_list import Node


def bubble_sort(list: SinglyLinkedList) -> None:
    # Technique:
    # Maintain @end to get close to list.front.
    # Every loop of bubble swap goes from list.front to @end.
    # So when @end reaches list.front, sorting is complete.

    # directly return empty list
    if list.is_empty():
        return

    end: Node = list.back
    while end != list.front:
        curr: Node = list.front
        prev: Node = curr
        while curr != end:
            # swap
            if curr.val > curr.next.val:
                curr.val, curr.next.val = curr.next.val, curr.val

            prev = curr
            curr = curr.next
        # nodes after "end" are sorted
        end = prev
