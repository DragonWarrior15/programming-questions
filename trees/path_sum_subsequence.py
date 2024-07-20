"""
https://leetcode.com/problems/path-sum-iii/description/

Given the root of a binary tree and an integer targetSum, return the number
of paths where the sum of the values along the path equals targetSum.
The path does not need to start or end at the root or a leaf, but it must
go downwards (i.e., traveling only from parent nodes to child nodes).

Example 1:
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.

Example 2:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3

Constraints:
    The number of nodes in the tree is in the range [0, 1000].
    -10^9 <= Node.val <= 10^9
    -1000 <= targetSum <= 1000
"""


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # one major flaw in checking all subsequences that there might be some paths
    # that overlap with each other, instead lets check paths
    # that end on the current node
    """
    def count_subsequences_with_sum(self, sequence: List, targetSum: int) -> int:
        count = 0
        if len(sequence) == 0:
            return 0
        if len(sequence) == 1:
            if targetSum == sequence[0]:
                return 1
            else:
                return 0
        # sliding window, keep expanding window while sum < target sum
        # keep shrinking from left if sum > target sum
        left_idx, right_idx = 0, 0
        while (
            left_idx <= right_idx
            and right_idx < len(sequence)
            and left_idx < len(sequence)
        ):
            curr_sum = sum(sequence[left_idx : right_idx + 1])
            print(curr_sum, sequence, left_idx, right_idx)
            if curr_sum == targetSum:
                count += 1
                right_idx += 1
            elif curr_sum > targetSum:
                left_idx += 1
                if left_idx > right_idx:
                    right_idx += 1
            else:
                # curr_sum < targetSum
                right_idx += 1

        return count
    """

    def count_subsequences_with_sum(self, sequence: List, targetSum: int) -> int:
        if not sequence:
            return 0

        if len(sequence) == 1:
            if sequence[0] == targetSum:
                return 1
            else:
                return 0

        count = 0

        # traverse the list in reverse

        curr_sum = sequence[-1]
        # base case
        if curr_sum == targetSum:
            count += 1
        for idx in range(len(sequence) - 2, -1, -1):
            curr_sum += sequence[idx]
            # print(curr_sum, idx, sequence)
            if curr_sum == targetSum:
                count += 1

        return count

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        if not root:
            return 0

        count = 0

        stack = [(root, [])]
        while stack:
            stack_top_node, stack_top_path = stack.pop()

            path_with_top_node = stack_top_path + [stack_top_node.val]

            # check sum till current path
            count += self.count_subsequences_with_sum(
                sequence=path_with_top_node, targetSum=targetSum
            )

            if stack_top_node.left:
                stack.append(
                    (
                        stack_top_node.left,
                        path_with_top_node,
                    )
                )
            if stack_top_node.right:
                stack.append(
                    (
                        stack_top_node.right,
                        path_with_top_node,
                    )
                )

        return count
