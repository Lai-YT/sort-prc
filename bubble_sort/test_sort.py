import unittest

from bubble_sort import bubble_sort
from linked_list import SinglyLinkedList


class SortTestCase(unittest.TestCase):
    def setUp(self) -> None:
        self._list = SinglyLinkedList()

    def test_sort(self) -> None:
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

        self.assertEqual(
            str(self._list),
            '1->2->3->4->5->6->7->8->9->10'
        )


if __name__ == '__main__':
    unittest.main()
