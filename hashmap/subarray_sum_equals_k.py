"""
https://leetcode.com/problems/subarray-sum-equals-k/description/

Given an array of integers nums and an integer k, return the total number of
subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2

Constraints:
1 <= nums.length <= 2 * 10^4
-1000 <= nums[i] <= 1000
-10^7 <= k <= 10^7
"""

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        # build prefix sums
        ans = 0
        from collections import defaultdict
        prefix_dict = defaultdict(int)
        # One empty prefix exists before the array begins
        prefix_dict[0] = 1

        for i in range(len(nums)):
            if i > 0:
                nums[i] = nums[i] + nums[i - 1]

            # store these in the prefix sum set
            prefix_dict[nums[i]] += 1

            # check how many earlier starts + k give current index i
            ans += prefix_dict[nums[i] - k]

            if k == 0:
                # double counting
                # this is a convoluted handling, simpler approach is to
                # query first and then insert
                ans -= 1

        return ans