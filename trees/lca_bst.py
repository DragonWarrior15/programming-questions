# https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

"""
Given a binary search tree (BST), find the lowest common ancestor (LCA) of
two given nodes in the BST.
According to the definition of LCA on Wikipedia: "The lowest common ancestor
is defined between two nodes p and q as the lowest node in T that has both
p and q as descendants (where we allow a node to be a descendant of itself)."

tree structure is: [root, root.left, root.right,
                    root.left.left, root.left.right ...]

Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant
of itself according to the LCA definition.

Example 3:
Input: root = [2,1], p = 2, q = 1
Output: 2

Constraints:
The number of nodes in the tree is in the range [2, 105].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q
p and q will exist in the BST.
"""


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def lowestCommonAncestor(
        self, root: "TreeNode", p: "TreeNode", q: "TreeNode"
    ) -> "TreeNode":
        """Since we are given a BST, we have the following (assume p.val <
        q.val)
        1) if p <= root.val and root.val <= q: root must be the common
        ancestor since both values lie in different subtrees of root
        2) p, q <= root.val: LCA lies in the left subtree, we should
        do a recursive call LCA(root.left, p, q)
        3) root.val <= p, q: LCA lies in the right subtree, we should do a
        recursive call LCA(root.right, p, q)
        """

        if min(p.val, q.val) <= root.val and root.val <= max(p.val, q.val):
            return root

        if p.val <= root.val:
            return self.lowestCommonAncestor(root.left, p, q)

        return self.lowestCommonAncestor(root.right, p, q)
