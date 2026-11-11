"""
https://leetcode.com/problems/maximum-k-to-sort-a-permutation/description/

3644. Maximum K to Sort a Permutation
You are given an integer array nums of length n, where nums is a permutation
of the numbers in the range [0..n - 1].
You may swap elements at indices i and j only if nums[i] AND nums[j] == k,
where AND denotes the bitwise AND operation and k is a non-negative integer.
Return the maximum value of k such that the array can be sorted in
non-decreasing order using any number of such swaps. If nums is already
sorted, return 0.

Example 1:
Input: nums = [0,3,2,1]
Output: 1
Explanation:
Choose k = 1. Swapping nums[1] = 3 and nums[3] = 1 is allowed since
nums[1] AND nums[3] == 1, resulting in a sorted permutation: [0, 1, 2, 3].

Example 2:
Input: nums = [0,1,3,2]
Output: 2
Explanation:
Choose k = 2. Swapping nums[2] = 3 and nums[3] = 2 is allowed since
nums[2] AND nums[3] == 2, resulting in a sorted permutation: [0, 1, 2, 3].

Example 3:
Input: nums = [3,2,1,0]
Output: 0
Explanation:
Only k = 0 allows sorting since no greater k allows the required swaps
where nums[i] AND nums[j] == k.

Constraints:
1 <= n == nums.length <= 10^5
0 <= nums[i] <= n - 1
nums is a permutation of integers from 0 to n - 1.
"""


class Solution:
    def sortPermutation(self, nums: list[int]) -> int:
        # very difficult to find insight, basically each number that is
        # misplaced, will participate in at least one swap.. meaning the value
        # of k, will come from the common set of set bits across all the
        # misplaced values
        # this logic holds for whatever you choose as a placeholder value
        # to anchor all the swaps on

        k = None
        for idx, num in enumerate(nums):
            if idx != num:
                # misplaced
                if k is None:
                    k = num
                else:
                    k = k & num

        if k is None:
            return 0
        return k
