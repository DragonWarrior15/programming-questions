"""
https://leetcode.com/problems/maximum-sum-circular-subarray/
"""


class Solution:
    def maxSubarraySumCircular(self, nums: list[int]) -> int:
        """
        The key insight here is that. when you find a circular subarray of max
        sum, the remaining portion is actually just a continuous subarray
        (non circular) whose sum is total array sum - max circular subarray sum
        Hence the problem becomes finding the minimum sum continuous subarray
        We just need to account for cases when the maximum sum is actually
        non circular, and when the minimum sum takes up the entire array
        """
        total_array_sum = sum(nums)
        min_sum_at_curr_idx = None
        max_sum_at_curr_idx = None
        answer_min = None
        answer_max = None
        for num in nums:
            if min_sum_at_curr_idx is None:
                min_sum_at_curr_idx = num
                max_sum_at_curr_idx = num
                answer_min = num
                answer_max = num
            else:
                # continue the previous sum to make it lower, say negative
                # or just take the current element
                min_sum_at_curr_idx = min(num, min_sum_at_curr_idx + num)
                max_sum_at_curr_idx = max(num, max_sum_at_curr_idx + num)
                answer_min = min(answer_min, min_sum_at_curr_idx)
                answer_max = max(answer_max, max_sum_at_curr_idx)

        # edge case, if the minimum sum eats up the entire array, it is not
        # valid, in that case the answer is the maximum element of the array
        if answer_min == total_array_sum:
            return answer_max
        return max(total_array_sum - answer_min, answer_max)
