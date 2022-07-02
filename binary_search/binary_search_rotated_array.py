# https://leetcode.com/problems/search-in-rotated-sorted-array/

"""
There is an integer array nums sorted in ascending order
(with distinct values).
Prior to being passed to your function, nums is possibly rotated at an
unknown pivot index k (1 <= k < nums.length) such that the resulting array is
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
(0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3
and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target,
return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1

Constraints:
1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-10^4 <= target <= 10^4
"""


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low = 0
        high = len(nums) - 1

        if nums[low] == target:
            return low

        if nums[high] == target:
            return high

        while 1 < high - low:
            mid = (low + high) // 2

            if nums[mid] == target:
                return mid

            if nums[low] == target:
                return low

            if nums[high] == target:
                return high

            # not found, conditional change of mid
            if nums[low] < nums[high]:
                # we are in portion of array where numbers are in
                # correct increasing order
                if target < nums[mid]:
                    high = mid
                else:
                    low = mid
            else:
                # we are in portion of array where numbers first
                # increase, the restart from a lower value and increase
                # but we dont know if the pivot lies to the left of mid
                if nums[high] < target and target < nums[low]:
                    # number not in list
                    return -1
                elif nums[low] < nums[mid]:
                    # pivot is on right of mid
                    if nums[low] < target and target < nums[mid]:
                        # easy, search between the two
                        high = mid
                    elif nums[low] < target and nums[mid] < target:
                        # target might lie to the right of mid
                        low = mid
                    elif target < nums[low] and target < nums[high]:
                        # target might lie to the left of high but after mid
                        low = mid
                    else:
                        return -1
                elif nums[mid] < nums[high]:
                    # pivot lies to left of mid
                    if nums[mid] < target and target < nums[high]:
                        # target between the two
                        low = mid
                    elif target < nums[mid] and target < nums[high]:
                        # target is to the left of mid
                        high = mid
                    elif target > nums[high] and target > nums[low]:
                        # target potentially to right of low
                        high = mid
                    else:
                        return -1
                else:
                    return -1

        return -1
