# https://leetcode.com/problems/subsets/

"""
Given an integer array nums of unique elements, return all possible subsets
(the power set).
The solution set must not contain duplicate subsets. Return the solution in
any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
"""


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        """Use a recursion/backtracking
        if the length of nums = 0, base case and return [[]], empty list
        if the length of nums = 1, can return an empty list or single element
        i.e., [[], [nums[0]]]
        otherwise, we have the option to either include the first element
        or exclude it from the subsets that we are going to return
        if including the first element
            return [[nums[0]] + any lists using same subset function on
            remaining list, i.e., subsets(nums[1:])]
        otherwise
            simply return the subset function on the remaining list
            i.e., subsets(nums[1:])
        """
        # empty list is always part of the solution
        if len(nums) == 0:
            return [[]]
        elif len(nums) == 1:
            return [[], nums]
        else:
            ans = []
            # subsets using remaining list
            subsets_remaining_list = self.subsets(nums[1:])
            # either have the first element always appear with remaining
            # subsets
            ans += [[nums[0]] + x for x in subsets_remaining_list]
            # or dont include the first element
            ans += subsets_remaining_list
            return ans
        return [[]]
