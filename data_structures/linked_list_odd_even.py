"""
https://leetcode.com/problems/odd-even-linked-list/description/

Given the head of a singly linked list, group all the nodes with odd indices together
followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain
as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

Constraints:
    The number of nodes in the linked list is in the range [0, 10^4].
    -10^6 <= Node.val <= 10^6
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # edge case
        if not head:
            return head

        # edge cases
        if not head.next:
            return head

        # edge cases
        if not head.next.next:
            return head

        even_head = ListNode()
        odd_head = ListNode()

        even_curr = even_head
        odd_curr = odd_head

        idx = 1
        while True:
            if idx % 2 == 1:
                # odd
                odd_curr.next = head
                # also move the current pointer by one
                odd_curr = odd_curr.next
            else:
                even_curr.next = head
                # also move the current pointer by one
                even_curr = even_curr.next

            if not head.next:
                break
            else:
                head = head.next
                idx += 1

        # edge case, next of current even should always be None
        # to avoid cycles
        even_curr.next = None

        # at the end, curr odd next must be even head
        # not even_head var itself since that is dummy
        odd_curr.next = even_head.next

        # not odd_head var itself since that is dummy
        return odd_head.next