"""
https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/

You are given the root of a binary tree.
A ZigZag path for a binary tree is defined as follow:

    Choose any node in the binary tree and a direction (right or left).
    If the current direction is right, move to the right child of the current node;
    otherwise, move to the left child.
    Change the direction from right to left or from left to right.
    Repeat the second and third steps until you can't move in the tree.

Zigzag length is defined as the number of nodes visited - 1.
(A single node has a length of 0).
Return the longest ZigZag path contained in that tree.

Example 1:
Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).

Example 2:
Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).

Example 3:
Input: root = [1]
Output: 0
"""

# this does not perfectly work, try to work out the solution for the
# first tree and it will be clear that some possible paths
# are always missed since after the root we always start exploring
# only particular directions
"""
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode], direction=None) -> int:
        # direction False means left and direction True means right
        if not root:
            return 0
        # never count the last node since we need total nodes - 1
        if not root.left and not root.right:
            return 0
        # longest path can include root or not include it
        # when counting, if there is no node next, do not count it
        longest_path = 0
        if direction is None:
            # explore both left and right
            longest_path = max(
                1 + self.longestZigZag(root.right, False) if root.right else 0,
                1 + self.longestZigZag(root.left, True) if root.left else 0,
                # excuding current node
                # we dont need to explore both directions, since some already
                # explored in the above two calls
                self.longestZigZag(root.right, True) if root.right else 0,
                self.longestZigZag(root.left, False) if root.left else 0,
            )
        elif direction:
            # continue in the direction
            longest_path = (
                1 + self.longestZigZag(root.right, not direction) if root.right else 0,
            )
        else:
            longest_path = (
                1 + self.longestZigZag(root.left, not direction) if root.left else 0,
            )

        return longest_path
"""


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        """
        do a dfs, store the path lengths left onward and right onward
        """
        # base case
        if not root:
            return 0

        answer = 0

        # the tuple is node,
        # longest path to node where its on left
        # longest path to node where its on right
        stack = [(root, 0, 0)]

        while stack:
            (
                stack_top_node,
                stack_top_node_ending_left,
                stack_top_node_ending_right,
            ) = stack.pop()

            answer = max(
                answer, stack_top_node_ending_left, stack_top_node_ending_right
            )

            if stack_top_node.left:
                # can take the path till previous node (where that node was
                # the one with path ending on right) and add 1 to go left
                # or, can start independently from current node to right
                stack.append((stack_top_node.left, stack_top_node_ending_right + 1, 0))

            if stack_top_node.right:
                # can take the path till previous node (where that node was
                # the one with the path ending on left) and add 1 to go right
                # or, can start independently from current node to left
                stack.append((stack_top_node.right, 0, stack_top_node_ending_left + 1))

        return answer
