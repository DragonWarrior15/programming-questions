# https://leetcode.com/problems/reverse-linked-list/

"""
Given the head of a singly linked list, reverse the list, and return
the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []

Constraints:
The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000

Follow up: A linked list can be reversed either iteratively or recursively.
Could you implement both?
"""


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # iterative solution
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        old_list = head
        new_list = None

        while old_list is not None:
            temp = old_list.next
            old_list.next = new_list
            new_list = old_list
            old_list = temp

        return new_list

    """
    # recursive solution
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # base case
        if head is None or head.next is None:
            return head

        new_head = self.reverseList(head.next)
        # append current/original head to the end of list
        curr_node = new_head
        while curr_node.next is not None:
            curr_node = curr_node.next

        curr_node.next = head
        head.next = None

        return new_head
    """
