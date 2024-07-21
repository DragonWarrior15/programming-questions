"""
https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the
resulting array. Return 0 if there is no such subarray.

Example 1:
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3
numbers with value of 1's.

Example 2:
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1]
longest subarray with value of 1's is [1,1,1,1,1].

Example 3:
Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.

Constraints:
    1 <= nums.length <= 10^5
    nums[i] is either 0 or 1.
"""


class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        # base case
        if len(nums) == 1:
            # answer is always 0 since we need to remove one element
            return 0

        n = len(nums)
        max_ones = 0
        # first make an array that keeps a track of counts of
        # 1s and 0s that are contiguous
        left_idx, right_idx = 0, 1

        nums_count = []
        loc_single_zeros = []
        # track if there are only 1s in the array
        ind_only_ones = True

        while True:
            # once out of array and everything is processed
            if right_idx > n or left_idx > n:
                break

            if right_idx < n and nums[left_idx] == nums[right_idx]:
                # still in a continuous array, continue
                right_idx += 1
            else:
                # found a break point or reached the end of the array
                nums_count.append(right_idx - left_idx)

                if nums[left_idx] == 0:
                    ind_only_ones = False

                # also keep a track of max ones
                if nums[left_idx] == 1:
                    max_ones = max(max_ones, right_idx - left_idx)

                # also keep a track of pos where there is a single 0
                # in this new array (not towards the ends)
                if (
                    nums[left_idx] == 0
                    and right_idx - left_idx == 1
                    and left_idx != 0
                    and left_idx != n - 1
                ):
                    # this could be potential break point
                    loc_single_zeros.append(len(nums_count) - 1)

                # now move left and right indices
                left_idx = right_idx
                right_idx += 1

        # if there are only 1s, remove one 1 and return the answer
        if ind_only_ones:
            return max_ones - 1

        # do a check if there is a possible single 0 that we can eleminate
        for loc_zero in loc_single_zeros:
            max_ones = max(
                max_ones, nums_count[loc_zero - 1] + nums_count[loc_zero + 1]
            )

        return max_ones
