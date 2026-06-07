# https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

"""
Given an integer array nums of size n, return the minimum number of moves
required to make all array elements equal.
In one move, you can increment n - 1 elements of the array by 1.

Example 1:
Input: nums = [1,2,3]
Output: 3
Explanation: Only three moves are needed (remember each move increments two
elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

Example 2:
Input: nums = [1,1,1]
Output: 0

Constraints:
n == nums.length
1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
The answer is guaranteed to fit in a 32-bit integer.
"""


class Solution:
    def minMoves(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return 0

        # key insight: increasing n - 1 elements by 1 is same as decreasing
        # 1 element by 1.. since we do not care about the final number all
        # elements in the array are equal to
        # this means we must only worry about the difference of each element
        # with the minimum and the total of these differences is the required
        # number of steps we wish to take

        min_num = min(nums)
        ans = sum([num - min_num for num in nums])
        return ans
