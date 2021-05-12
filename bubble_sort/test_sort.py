import unittest

from linked_list import *
from bubble_sort import *

class SortTestCase(unittest.TestCase):
    def setUp(self):
        self._list = SinglyLinkedList()

    def test_sort(self):
        self._list.push_back(10)
        self._list.push_back(5)
        self._list.push_back(9)
        self._list.push_back(6)
        self._list.push_back(7)
        self._list.push_back(8)
        self._list.push_back(4)
        self._list.push_back(1)
        self._list.push_back(2)
        self._list.push_back(3)
        # 10->5->9->6->7->8->4->1->2->3

        bubble_sort(self._list)
        # 1->2->3->4->5->6->7->8->9->10

        curr = self._list.front
        for i in range(1, 11):
            self.assertEqual(i, curr.val)
            curr = curr.next
