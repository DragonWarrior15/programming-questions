"""
https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is
nown as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2.
These are the only nodes with twins for n = 4.

The twin sum is defined as the sum of a node and its twin.
Given the head of a linked list with even length, return the maximum twin sum of the linked list.

Example 1:
Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6. 

Example 2:
Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 

Example 3:
Input: head = [1,100000]
Output: 100001
Explanation:
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.

Constraints:
    The number of nodes in the list is an even integer in the range [2, 10^5].
    1 <= Node.val <= 10^5


"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        # we use a stack to keep adding elements until we reach the
        # middle of the linked list, then start addding and popping
        # till we reach the end, while keeping track of the max sum
        stack = []

        # use double pointers to track middle of the linked list
        head_2 = head

        while True:
            stack.append(head.val)

            # jump
            head = head.next
            # this is double jump since head has already moved by one
            head_2 = head_2.next.next

            # check break condition for adding elements to the stack
            if not head_2:
                break
        
        # still continue to traverse the list, but pop elements from the stack
        max_sum = 0

        while True:
            # print(head.val, stack)
            if not stack or not head:
                break
            max_sum = max(head.val + stack.pop(), max_sum)

            # move the head
            head = head.next

        return max_sum
