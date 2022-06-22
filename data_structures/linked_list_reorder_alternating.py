# https://leetcode.com/problems/reorder-list/

"""
You are given the head of a singly linked-list. The list can be
represented as:
L0 → L1 → … → Ln - 1 → Ln

Reorder the list to be on the following form:
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

You may not modify the values in the list's nodes. Only nodes
themselves may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

Constraints:
The number of nodes in the list is in the range [1, 5 * 10^4].
1 <= Node.val <= 1000
"""


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        old_list = head
        new_list = None

        while old_list is not None:
            temp = old_list.next
            old_list.next = new_list
            new_list = old_list
            old_list = temp

        return new_list

    def getMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.next is None:
            return head
        if head.next.next is None:
            return head.next

        pointer_left = head
        pointer_right = head.next

        while pointer_right.next is not None and pointer_right.next.next is not None:
            pointer_right = pointer_right.next.next
            pointer_left = pointer_left.next

        # case of odd length list, pointer_right.next is not None but
        # pointer_right.next.next is None
        if pointer_right.next is not None and pointer_right.next.next is None:
            pointer_left = pointer_left.next

        return pointer_left

    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """

        # get the middle point of the list
        middle = self.getMiddle(head)

        # reverse the list from middle to the end
        head_reverse = self.reverseList(middle)

        head_original = head
        # now alternately add elements from original and reverse
        while True:
            if head_original is None:
                break
            temp = head_original.next
            head_original.next = head_reverse
            head_original = temp

            if head_reverse is None:
                break
            temp = head_reverse.next
            head_reverse.next = head_original
            head_reverse = temp
