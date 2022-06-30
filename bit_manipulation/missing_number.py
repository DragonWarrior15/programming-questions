# https://leetcode.com/problems/missing-number/

"""
Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.

Example 1:
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the
range [0,3]. 2 is the missing number in the range since it does not appear
in nums.

Example 2:
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the
range [0,2]. 2 is the missing number in the range since it does not appear
in nums.

Example 3:
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the
range [0,9]. 8 is the missing number in the range since it does not appear
in nums.

Constraints:
n == nums.length
1 <= n <= 10^4
0 <= nums[i] <= n
All the numbers of nums are unique.

Follow up: Could you implement a solution using only O(1) extra space
complexity and O(n) runtime complexity?
"""


class Solution:
    def missingNumber_v1(self, nums: List[int]) -> int:
        # since all numbers in 0,n are distinct
        theoretical_total = sum([x for x in range(len(nums) + 1)])
        # actual total is shy of theoretical_total by only one number
        # which is the missing number
        actual_total = sum(nums)

        return theoretical_total - actual_total

    def missingNumber(self, nums: List[int]) -> int:
        """XOR, key points
        a ^ a = 0 and a ^ 0 = a
        now, consider n = 2 and the given list is [0, 1]
        consider list [0, 1, 2] if we xor both the lists, the 0^0 will return
        0, 1^1 will return 0 hence final answer will be 2^0 = 2 and we get
        the missing number always
        """
        ans = 0
        for i in range(len(nums) + 1):
            ans = ans ^ i

        for num in nums:
            ans = ans ^ num

        return ans
