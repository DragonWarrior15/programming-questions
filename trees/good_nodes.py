# https://leetcode.com/problems/count-good-nodes-in-binary-tree/

"""
Given a binary tree root, a node X in the tree is named good
if in the path from root to X there are no nodes with a value greater than X.
Return the number of good nodes in the binary tree.

tree structure is: [root, root.left, root.right,
                    root.left.left, root.left.right ...]

Example 1:
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.

Example 2:
Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.

Example 3:
Input: root = [1]
Output: 1
Explanation: Root is considered as good.

Constraints:
The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4].
"""


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        """Store in a queue (along with the node) the maximum value
        obtained so far, the update rule is max_val = max(max_val, node_val)
        Traversal order will not matter in this case
        """

        import queue

        q = queue.Queue()
        ans = 0

        if root is None:
            return 1

        # max value so far is nothing
        q.put((root, float("-inf")))

        # traverse the tree
        while not q.empty():
            curr_node, max_val = q.get()
            if max_val <= curr_node.val:
                ans += 1

            if curr_node.left is not None:
                q.put((curr_node.left, max(max_val, curr_node.val)))

            if curr_node.right is not None:
                q.put((curr_node.right, max(max_val, curr_node.val)))

        return ans
