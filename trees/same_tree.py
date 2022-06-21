# https://leetcode.com/problems/same-tree/

"""
Given the roots of two binary trees p and q, write a function to
check if they are the same or not.
Two binary trees are considered the same if they are structurally
identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true
    1      1
   / \    / \
  2  3   2  3

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false
    1      1
   /        \
  2          2

Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false

Constraints:
The number of nodes in both trees is in the range [0, 100].
-10^4 <= Node.val <= 10^4
"""


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        """The check can be divided into three parts
        1. check p.val == q.val
        2. check isSameTree(p.left, q.left)
        3. check isSameTree(p.right, q.right)
        """

        if p is None and q is None:
            return True

        if (p is None and q is not None) or (p is not None and q is None):
            return False

        if p.val != q.val:
            return False

        if not self.isSameTree(p.left, q.left):
            return False

        if not self.isSameTree(p.right, q.right):
            return False

        return True
