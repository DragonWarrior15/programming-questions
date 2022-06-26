# https://leetcode.com/problems/add-two-numbers/

"""
You are given two non-empty linked lists representing two non-negative
integers. The digits are stored in reverse order, and each of their nodes
contains a single digit. Add the two numbers and return the sum as a
linked list.
You may assume the two numbers do not contain any leading zero, except
the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have
leading zeros.
"""


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        ans = ListNode(val=None)
        ans_head = ans

        # initial carry over is 0
        carry_over = 0
        while True:
            # base is initially always 0
            base = 0

            # exit case, check for carry overs too
            if l1 is None and l2 is None and carry_over == 0:
                break

            if l1 is not None:
                base += l1.val
                # move to next position of l1
                l1 = l1.next

            if l2 is not None:
                base += l2.val
                # move to next position of l2
                l2 = l2.next

            base += carry_over

            # calculate the new carry over and base
            carry_over = base // 10
            base = base % 10

            # no need to create a new node for the first value
            if ans.val is None:
                ans.val = base
            else:
                node = ListNode(base)
                ans.next = node
                # move to the next position
                ans = ans.next

        return ans_head
