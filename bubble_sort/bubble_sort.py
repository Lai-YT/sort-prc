from linked_list import *


def bubble_sort(list: SinglyLinkedList) -> None:
    # Technique:
    # Maintain @end to get close to list.front.
    # Every loop of bubble swap goes from list.head to @end.
    # So when @end reaches list.head, sorting is complete.

    # directly return empty list
    if list.front is None:
        return

    end = list.back
    while end != list.front:
        curr = list.front
        prev: Node = None
        while curr != end:
            # swap
            if curr.val > curr.next.val:
                curr.val, curr.next.val = curr.next.val, curr.val

            # increment
            prev = curr
            curr = curr.next
        # increment
        end = prev
