"""
https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/description/

Given an array nums that represents a permutation of integers from 1 to n.
We are going to construct a binary search tree (BST) by inserting the elements
of nums in order into an initially empty BST. Find the number of different ways
to reorder nums so that the constructed BST is identical to that formed from
the original array nums.

For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left
child, and 3 as a right child. The array [2,3,1] also yields the same BST but
[3,2,1] yields a different BST.
Return the number of ways to reorder nums such that the BST formed is identical
to the original BST formed from nums.

Since the answer may be very large, return it modulo 10**9 + 7.

Example 1:
Input: nums = [2,1,3]
Output: 1
Explanation: We can reorder nums to be [2,3,1] which will yield the same BST.
There are no other ways to reorder nums which will yield the same BST.

Example 2:
Input: nums = [3,4,5,1,2]
Output: 5
Explanation: The following 5 arrays will yield the same BST:
[3,1,2,4,5]
[3,1,4,2,5]
[3,1,4,5,2]
[3,4,1,2,5]
[3,4,1,5,2]

Example 3:
Input: nums = [1,2,3]
Output: 0
Explanation: There are no other orderings of nums that will yield the same BST.

Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= nums.length
All integers in nums are distinct.
"""


class Solution:
    def numOfWays(self, nums: list[int]) -> int:
        mod = 10**9 + 7

        # idea is simple, the root of the tree must always be inserted first
        # after which, we can give the elements in any order as long as
        # their relative orders are maintained, basically after root, if we
        # give left subtree first and right next, or vice versa, both will
        # produce the same eventual tree
        def get_factorial(n: int) -> int:
            """Calculate the factorial of n."""
            if n <= 1:
                return 1
            ans = 1
            while n:
                ans *= n
                n -= 1
            return ans

        def get_combinations(n: int, k: int) -> int:
            """Calculates nCk, no of ways to select k objects out of n."""
            return get_factorial(n) // (
                get_factorial(n - k) * get_factorial(k)
            )

        def count_arrangements(nums: list[int]) -> int:
            """Count simple ways to arrange numbers, not positions in nums."""
            n = len(nums)

            # base cases
            if n <= 2:
                return 1

            root = nums[0]
            left_subtree = [x for x in nums if x < root]
            right_subtree = [x for x in nums if x > root]

            curr_combinations = get_combinations(n - 1, len(left_subtree))
            left_combinations = count_arrangements(left_subtree)
            right_combinations = count_arrangements(right_subtree)

            return (
                curr_combinations * left_combinations * right_combinations
            ) % mod

        # else go recursively and find answers
        return count_arrangements(nums) - 1
