# https://leetcode.com/problems/delete-nodes-and-return-forest/

"""
Given the root of a binary tree, each node in the tree has a distinct value.
After deleting all nodes with a value in to_delete, we are left with a forest
(a disjoint union of trees).
Return the roots of the trees in the remaining forest. You may return the
result in any order.

Example 1:
Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]

Example 2:
Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]

Constraints:
The number of nodes in the given tree is at most 1000.
Each node has a distinct value between 1 and 1000.
to_delete.length <= 1000
to_delete contains distinct values between 1 and 1000.
"""


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def delNodes(
        self, root: Optional[TreeNode], to_delete: List[int]
    ) -> List[TreeNode]:
        # try a dfs style solution
        # at any node, if its not deleted, add a flag to it not deleted
        # carry that flag to its child nodes.. this way the children node
        # cannot be added if they are not deleted and their parent is already
        # added to the final answer
        # key observation: a node will be added to answer if its parent is
        # seleted
        ans = []
        to_delete = set(to_delete)
        # node, parent_deleted
        stack = [(root, True)]
        while stack:
            curr_node, parent_deleted = stack.pop()

            # if parent is deleted and this is not, add to ans
            if parent_deleted and curr_node.val not in to_delete:
                ans.append(curr_node)

            # append children to stack anyway
            if curr_node.left:
                stack.append((curr_node.left, curr_node.val in to_delete))
            if curr_node.right:
                stack.append((curr_node.right, curr_node.val in to_delete))

            # if any of the children are deleted, mark that side of
            # curr node as none, children reference is there in the stack anyway
            if curr_node.left and curr_node.left.val in to_delete:
                curr_node.left = None
            if curr_node.right and curr_node.right.val in to_delete:
                curr_node.right = None

        return ans
