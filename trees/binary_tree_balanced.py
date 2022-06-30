# https://leetcode.com/problems/balanced-binary-tree

"""
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:
    a binary tree in which the left and right subtrees of every node differ
    in height by no more than 1.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:
Input: root = []
Output: true

Constraints:
The number of nodes in the tree is in the range [0, 5000].
-10^4 <= Node.val <= 10^4
"""


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def get_height(self, root: Optional[TreeNode]) -> bool:
        if root is None or not root:
            return 0
        else:
            left_height = 0
            right_height = 0
            if root.left is not None:
                left_height = self.get_height(root.left)
            if root.right is not None:
                right_height = self.get_height(root.right)
            return 1 + max(left_height, right_height)

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        """For every node, check if abs (left height - right height) <= 1
        Current solution is O(n^2) and can be optimized by backtracking
        sort of an approach
        """
        from queue import Queue

        q = Queue()
        if root is None or not root:
            return True
        q.put(root)

        while not q.empty():
            curr_node = q.get()
            left_height = self.get_height(curr_node.left)
            right_height = self.get_height(curr_node.right)

            # print(curr_node.val, left_height, right_height)

            if abs(left_height - right_height) > 1:
                return False

            if curr_node.left is not None:
                q.put(curr_node.left)

            if curr_node.right is not None:
                q.put(curr_node.right)

        return True
