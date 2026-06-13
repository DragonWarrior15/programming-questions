# https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero

"""
You are given an integer array nums and an integer x. In one operation, you can
either remove the leftmost or the rightmost element from the array nums and
subtract its value from x. Note that this modifies the array for future
operations.
Return the minimum number of operations to reduce x to exactly 0 if it is
possible, otherwise, return -1.

Example 1:
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce
x to zero.

Example 2:
Input: nums = [5,6,7,8,9], x = 4
Output: -1

Example 3:
Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the
first two elements (5 operations in total) to reduce x to zero.

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^4
1 <= x <= 10^9
"""


class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        # this is a very difficult to get intuition, but we should think of the
        # complementary problem instead.. whats left behind once elements are
        # removed from left and right.. its a continuous array whose sum equals
        # the total array sum - x
        # this should give an intuition that we can approach this in a sliding
        # window pattern
        total_sum = 0
        for _, num in enumerate(nums):
            total_sum += num

        target_sum = total_sum - x
        if target_sum == 0:
            # remove all elements
            return len(nums)
        if target_sum < 0:
            # impossible to solve
            return -1

        count_ops = float("inf")
        # initialize two pointers left and right, keep traversing to find
        # valid subarrays and record count of min operations so far
        left = 0
        curr_sum = 0

        # control right using a for loop as that is the standard pattern
        for right in range(len(nums)):
            # calculate the current sum
            curr_sum += nums[right]

            # shrink the left side if we over shot
            while curr_sum > target_sum and left <= right:
                curr_sum -= nums[left]
                left += 1

            # out of the loop, check for equality
            if curr_sum == target_sum:
                # this is a potential answer
                count_ops = min(count_ops, len(nums) - (right - left + 1))

        if count_ops == float("inf"):
            # we did not find a valid subarray
            return -1

        return count_ops

    def minOperations_suboptimal(self, nums: List[int], x: int) -> int:

        def remove_an_element(
            left_ptr: int, right_ptr: int, curr_x: int
        ) -> int:
            # removes either left or right and recursively calls itself
            # returns the minimum steps from this position

            if curr_x < 0:
                return None

            if curr_x == 0:
                return 0

            curr_steps = None

            # try to remove the left element
            if (
                left_ptr < right_ptr
                and left_ptr < len(nums)
                and nums[left_ptr] <= curr_x
            ):
                # this can be removed
                next_steps = remove_an_element(
                    left_ptr + 1, right_ptr, curr_x - nums[left_ptr]
                )
                if next_steps is not None:
                    if curr_steps is not None:
                        curr_steps = min(curr_steps, 1 + next_steps)
                    else:
                        curr_steps = 1 + next_steps

            # try to remove the right element
            if (
                left_ptr < right_ptr
                and right_ptr > -1
                and nums[right_ptr] <= curr_x
            ):
                # this can be removed
                next_steps = remove_an_element(
                    left_ptr, right_ptr - 1, curr_x - nums[right_ptr]
                )
                if next_steps is not None:
                    if curr_steps is not None:
                        curr_steps = min(curr_steps, 1 + next_steps)
                    else:
                        curr_steps = 1 + next_steps

            return curr_steps

        steps = remove_an_element(0, len(nums) - 1, x)
        if steps is None:
            return -1
        return steps
