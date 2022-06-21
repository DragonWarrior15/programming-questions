# https://leetcode.com/problems/product-of-array-except-self/
"""
Given an integer array nums, return an array answer such that
answer[i] is equal to the product of all the elements of nums
except nums[i].
The product of any prefix or suffix of nums is guaranteed to
fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and
without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Constraints:
2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to
fit in a 32-bit integer.
"""


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # since the solution is required without the division operation
        # we will use prefix and postfix arrays
        # prefix array sequentially multiplies numbers left to right
        # postfix does the same thing in opposite order
        # then the product of all elements except self is simply
        # the product of the two values from the prefix and postfix arrays
        total_nums = len(nums)
        prefix = [0] * total_nums
        postfix = [0] * total_nums
        answer = [0] * total_nums

        # fill prefix
        for i in range(total_nums):
            if i == 0:
                prefix[i] = nums[i]
            else:
                prefix[i] = nums[i] * prefix[i - 1]

        # fill postfix
        for i in range(total_nums - 1, -1, -1):
            if i == total_nums - 1:
                postfix[i] = nums[i]
            else:
                postfix[i] = nums[i] * postfix[i + 1]

        # fill the answer array
        for i in range(total_nums):
            if i == 0:
                answer[i] = postfix[i + 1]
            elif i == total_nums - 1:
                answer[i] = prefix[i - 1]
            else:
                answer[i] = prefix[i - 1] * postfix[i + 1]

        return answer
