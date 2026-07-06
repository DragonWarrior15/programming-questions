# https://leetcode.com/problems/longest-univalue-path/description/

"""
Given the root of a binary tree, return the length of the longest path,
where each node in the path has the same value. This path may or may not
passthrough the root.

The length of the path between two nodes is represented by the number of edges
between them.

Example 1:
Input: root = [5,4,5,1,1,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 5).

Example 2:
Input: root = [1,4,5,4,4,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 4).

Constraints:
The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
The depth of the tree will not exceed 1000.
"""


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        # a single node always returns 0 as it is not having any edge
        # we maintain two values, one is the overall longest path in a subtree
        # and second is the overall longest chain that starts at the root
        # and goes in either left or right direction
        # idea being if this chain can be carried over, it might be longer

        if not root:
            return 0

        def get_longest_path(root: Optional[TreeNode]) -> List[int]:
            if not root:
                return 0, 0

            # base case of a single node
            if not root.left and not root.right:
                return 0, 0

            if not root.left:
                right_child_inclusive_max, right_max = get_longest_path(
                    root.right
                )

                if root.val == root.right.val:
                    return 1 + right_child_inclusive_max, max(
                        right_max, 1 + right_child_inclusive_max
                    )

                else:
                    return 0, max(right_max, right_child_inclusive_max)

            if not root.right:
                left_child_inclusive_max, left_max = get_longest_path(
                    root.left
                )

                if root.val == root.left.val:
                    return 1 + left_child_inclusive_max, max(
                        left_max, 1 + left_child_inclusive_max
                    )

                else:
                    return 0, max(left_max, left_child_inclusive_max)

            left_child_inclusive_max, left_max = get_longest_path(root.left)
            right_child_inclusive_max, right_max = get_longest_path(root.right)

            if root.val != root.left.val and root.val != root.right.val:
                return 0, max(
                    left_max,
                    right_max,
                    left_child_inclusive_max,
                    right_child_inclusive_max,
                )

            if root.val != root.left.val and root.val == root.right.val:
                return 1 + right_child_inclusive_max, max(
                    left_max,
                    right_max,
                    1 + right_child_inclusive_max,
                    left_child_inclusive_max,
                )

            if root.val == root.left.val and root.val != root.right.val:
                return 1 + left_child_inclusive_max, max(
                    left_max,
                    right_max,
                    1 + left_child_inclusive_max,
                    right_child_inclusive_max,
                )

            return 1 + max(
                left_child_inclusive_max, right_child_inclusive_max
            ), max(
                left_max,
                right_max,
                left_child_inclusive_max + 1 + 1 + right_child_inclusive_max,
            )

        return max(get_longest_path(root))
