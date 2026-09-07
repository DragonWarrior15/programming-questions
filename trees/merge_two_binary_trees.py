"""
https://leetcode.com/problems/merge-two-binary-trees/

617. Merge Two Binary Trees

You are given two binary trees root1 and root2.
Imagine that when you put one of them to cover the other, some nodes of the two
trees are overlapped while the others are not. You need to merge the two trees
into a new binary tree. The merge rule is that if two nodes overlap, then sum
node values up as the new value of the merged node. Otherwise, the NOT null
node will be used as the node of the new tree.

Return the merged tree.
Note: The merging process must start from the root nodes of both trees.

Example 1:
Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]

Example 2:
Input: root1 = [1], root2 = [1,2]
Output: [2,2]

Constraints:
The number of nodes in both trees is in the range [0, 2000].
-10^4 <= Node.val <= 10^4
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(
        self, root1: Optional[TreeNode], root2: Optional[TreeNode]
    ) -> Optional[TreeNode]:
        # base case
        if not root1 and not root2:
            return None

        if not root1:
            return TreeNode(root2.val, root2.left, root2.right)

        if not root2:
            return TreeNode(root1.val, root1.left, root1.right)

        # merge left subtree
        left_subtree = self.mergeTrees(
            root1.left if root1.left else None,
            root2.left if root2.left else None,
        )

        # merge right subtree
        right_subtree = self.mergeTrees(
            root1.right if root1.right else None,
            root2.right if root2.right else None,
        )

        # create a new root
        root = TreeNode(
            val=root1.val + root2.val, left=left_subtree, right=right_subtree
        )

        return root
