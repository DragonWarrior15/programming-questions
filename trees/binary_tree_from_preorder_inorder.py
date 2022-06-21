# https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

"""
Given two integer arrays preorder and inorder where preorder is the
preorder traversal of a binary tree and inorder is the inorder traversal of
the same tree, construct and return the binary tree.

tree structure is: [root, root.left, root.right,
                    root.left.left, root.left.right ...]
for the output mentioned below

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]

Constraints:
1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        """Let's only use the list to find the current parent node and
        the left and right subtrees (if they exist)
        The first element of the preorder list gives the current node
        We can then look it up in the inorder list and make a decision
        based on the idx
        1) if the idx == 0: then there is only a right subtree for this node
        2) if the idx == len(inorder) - 1: then only a left subtree
        3) else there are both left and right subtree

        We can directly split the inorder list to get the inorder lists
        for the left and right subtrees
        Since the length of the sublists should be same for both inorder
        and preorder, we can now split the preorder list as well based
        on the length of inorder sublists

        Then, we can call the buildTree function again on these sublists
        """
        if len(preorder) == 0:
            return None

        curr_node = TreeNode(preorder[0])

        # locate in the inorder list
        node_idx = None
        for i in range(len(inorder)):
            if inorder[i] == curr_node.val:
                node_idx = i
                break

        left_inorder, right_inorder = [], []

        if node_idx == 0:
            right_inorder = inorder[1:].copy()
        elif node_idx == len(inorder) - 1:
            left_inorder = inorder[:-1].copy()
        else:
            left_inorder = inorder[:node_idx].copy()
            right_inorder = inorder[node_idx + 1 :].copy()

        left_preorder, right_preorder = [], []

        if len(left_inorder) > 0:
            left_preorder = preorder[1 : len(left_inorder) + 1]
            curr_node.left = self.buildTree(left_preorder, left_inorder)

        if len(right_inorder) > 0:
            right_preorder = preorder[1 + len(left_inorder) :]
            curr_node.right = self.buildTree(right_preorder, right_inorder)

        return curr_node
