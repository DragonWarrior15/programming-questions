"""
https://leetcode.com/problems/find-peak-element/description/

A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its
index. If the array contains multiple peaks, return the index to any of the
peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is
always considered to be strictly greater than a neighbor that is outside
the array.

You must write an algorithm that runs in O(log n) time.

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index
number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak
element is 2, or index number 5 where the peak element is 6.

Constraints:

    1 <= nums.length <= 1000
    -2^31 <= nums[i] <= 2^31 - 1
    nums[i] != nums[i + 1] for all valid i.
"""

# O(n) solution
"""
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        n = len(nums)
        for i in range(n):
            if i == 0 and nums[i] > nums[i + 1]:
                return i
            elif i == n - 1 and nums[i] > nums[i - 1]:
                return i
            elif nums[i - 1] < nums[i] and nums[i] > nums[i + 1]:
                return i
            else:
                pass
"""


# O(log n) solution
# taken from https://www.youtube.com/watch?v=kMzJy9es7Hc
# intuition is that the half of the array with the higher element
# at mid point is guaranteed to contain at least one peak element
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        n = len(nums)
        left_idx, right_idx = 0, n - 1

        while left_idx < right_idx:
            mid = (left_idx + right_idx) // 2

            if nums[mid] < nums[mid + 1]:
                # go right for potential increase/peak
                left_idx = mid + 1
            else:
                # check in left half for potential increase/peak
                right_idx = mid
            # neighboring elements are always distinct as per problem

        # both left and right idx are same at this point
        return left_idx
