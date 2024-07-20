""""
https://leetcode.com/problems/maximum-depth-of-binary-tree/

Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path 
from the root node down to the farthest leaf node.
Note: A leaf is a node with no children.

Example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
"""


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        depth = 0
        stack = [(root, 1)]
        while stack:
            stack_top_node, stack_top_depth = stack.pop()
            depth = max(stack_top_depth, depth)

            if stack_top_node.left:
                stack.append((stack_top_node.left, stack_top_depth + 1))
            if stack_top_node.right:
                stack.append((stack_top_node.right, stack_top_depth + 1))

        return depth
