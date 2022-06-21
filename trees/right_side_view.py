# https://leetcode.com/problems/binary-tree-right-side-view/

"""
Given the root of a binary tree, imagine yourself standing on the right side
of it, return the values of the nodes you can see ordered from top to bottom.

tree structure is: [root, root.left, root.right,
                    root.left.left, root.left.right ...]

Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:
Input: root = [1,null,3]
Output: [1,3]

Example 3:
Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
"""


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        """For every level, we need to find the rightmost element"""
        if root is None:
            return []

        import queue

        # queue to do level order traversal or breadth first search
        q = queue.Queue()

        right_side_view = []

        q.put((root, 0))

        while not q.empty():
            curr_node, level = q.get()
            if len(right_side_view) == level:
                # we are starting a new level, append to the view
                right_side_view.append(curr_node.val)

            # add the right and left child to the queue
            if curr_node.right is not None:
                q.put((curr_node.right, level + 1))

            if curr_node.left is not None:
                q.put((curr_node.left, level + 1))

        return right_side_view
