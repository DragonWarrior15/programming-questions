# https://leetcode.com/problems/binary-tree-level-order-traversal/

"""
Given a binary tree, return the level order traversal of its nodes' values.
(ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []



Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
"""


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        import queue

        """We traverse in order root -> left -> right"""
        ans = []
        q = queue.Queue()

        if root is None:
            return ans

        q.put((root, 0))

        while not q.empty():
            node, level = q.get()
            try:
                ans[level].append(node.val)
            except IndexError:
                ans.append([node.val])

            if node.left is not None:
                q.put((node.left, level + 1))

            if node.right is not None:
                q.put((node.right, level + 1))

        return ans
