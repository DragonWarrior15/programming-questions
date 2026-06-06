# https://leetcode.com/problems/sum-of-subarray-minimums/

"""
Given an array of integers arr, find the sum of min(b), where b ranges over every
(contiguous) subarray of arr. Since the answer may be large, return the answer
modulo 10**9 + 7.

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444


Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104
"""


class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        """
        if we have the said left and right boundaries at say index a and b, the count of subarrays
        from the perspective of arr[i] will become (i - a + 1) * (b - i + 1), basically we can choose any starting point
        between a & i inclusive, and any point between b and i inclusive..

        lets take the example of 3, 4, 1, 2; lets start building a stack that tracks (value, left, right) safe boundaries
        we add 3 to the stack as (3, 0, None)
        we move to 4, since 4 is bigger, add it as (4, 1, None)
        we move to 1, since 1 is smaller than 4.. start expanding wrt 1 now
        pop 4, its right becomes 1 (current index of value 1 - 1), total += 4 * (1 - 1 + 1) * (1 - 1 + 1)
        next, compare stack top and 1, 1 is still smaller than 3, pop 3, update right of 3 as 1, total += 3 * (0 - 0 + 1) * (1 - 0 + 1)
        put 1 on stack as (1, 0, None) where the left boundary was obtained as the index of the next largest element to 1 on stack
        net we move to 2, since its bigger than 1, add (2, 3, None)
        now we have run through the list, start popping off the stack, replace right with len(arr) everywhere)
        stack += 2 * (3 - 3 + 1) * (3 - 3 + 1)
        pop and go the the final entry in stack of 1.. total += 1 * (2 - 0 + 1) * (3 - 2 + 1)
        """
        MODULO = 10**9 + 7
        # we will track only the current index on stack, right is determined at
        # runtime anyway, and left will always be the previous element on stack
        # + 1
        stack = []
        idx = 0
        ans = 0
        while idx < len(arr):
            if not stack or stack[-1][0] <= arr[idx]:
                # append directly to the stack with current index as
                # the left boundary
                stack.append((arr[idx], idx))
                idx += 1
            else:
                # we have encountered a smaller element, pop the element
                # add to the running total, but wait for adding new element
                # till the next cycle
                top, self_top = stack.pop()
                left_top = stack[-1][1] + 1 if stack else 0
                # since current element is smaller, it should not be part of
                # the right boundary
                ans = (ans + top * (self_top - left_top + 1) * (idx - 1 - self_top + 1)) % (
                    MODULO
                )
                # do not add idx to the stack yet, there might be more elements
                # that need to be popped off

        # once we are out of the loop, if the stack still has any elements
        # we pop them off with right boundary as last index of arr
        while stack:
            top, self_top = stack.pop()
            left_top = stack[-1][1] + 1 if stack else 0
            ans = (ans + top * (self_top - left_top + 1) * (len(arr) - 1 - self_top + 1)) % (
                MODULO
            )

        return ans
