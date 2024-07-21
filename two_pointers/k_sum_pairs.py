"""
https://leetcode.com/problems/max-number-of-k-sum-pairs/description/

You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum
equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

Example 1:
Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.

Example 2:
Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.

Constraints:
    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^9
    1 <= k <= 10^9
"""

# solution using hashmaps
"""
class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        # create a dictionary to store the count of occurrences of each num
        # in the given array, then start iterating to locate pairs
        nums_dict = {}
        nums_unique = []

        count_pairs = 0

        for num in nums:
            try:
                nums_dict[num] += 1
            except KeyError:
                nums_dict[num] = 1
                nums_unique.append(num)

        # now loop to find the matching pairs
        for num in nums_unique:
            if nums_dict[num] > 0:
                if k - num in nums_dict:
                    # special case
                    if k - num != num:
                        possible_pairs = min(nums_dict[num], nums_dict[k - num])
                        # also update the dict to reflect that these pairs are used
                        nums_dict[num] -= possible_pairs
                        nums_dict[k - num] -= possible_pairs
                    else:
                        # repeated number
                        if nums_dict[num] % 2 == 0:
                            # use all of them up
                            possible_pairs = nums_dict[num] // 2
                            nums_dict[num] = 0
                        else:
                            # use all but 1
                            possible_pairs = (nums_dict[num] - 1) // 2
                            nums_dict[num] = 1

                    count_pairs += possible_pairs

        return count_pairs
"""


# solution using two pointers
class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        count_pairs = 0

        # first sort the array
        nums = sorted(nums)

        n = len(nums)

        # now initiate two pointers, one at start and another at end
        # move them while we dont have the desired sum
        left_idx, right_idx = 0, n - 1

        while True:
            # break condition
            if left_idx >= right_idx:
                break
            if nums[left_idx] + nums[right_idx] == k:
                # a possible pair
                count_pairs += 1
                # move both pointers, since both these nums cannot be used
                left_idx += 1
                right_idx -= 1
            elif nums[left_idx] + nums[right_idx] > k:
                # try a smaller num on right side
                right_idx -= 1
            else:
                # try a higher number on left side
                left_idx += 1

        return count_pairs
