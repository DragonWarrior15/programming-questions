"""
https://leetcode.com/problems/sliding-window-maximum/submissions/2193879625/
"""

class Solution:
    def maxSlidingWindow(self, nums: list[int], k: int) -> list[int]:
        # we need to use a deque here, and keep information about how the max
        # changes based on the incoming and outgoing elements
        from collections import deque

        max_dq: deque[(int, int)] = deque([])
        answer: list[int] = []

        idx = 0
        # first build the first array of length k, and then slide
        while idx < len(nums):
            # if the incoming element is more than the rightmost/most recent
            # element of deque, if we shrink the array from right by that element
            # the maximum will not change bec curr element is anyway maximum
            # hence we can remove that right most element
            while max_dq and nums[idx] >= max_dq[-1][0]:
                max_dq.pop()

            # now append our element to the right
            max_dq.append((nums[idx], idx))

            # in case we are in the sliding window phase, we need to pop the
            # elements from the left end depending on the position
            # idx + 1 >= k just establishes that we are in the sliding window
            # phase, and not the phase of building the first subarray
            while idx + 1 > k and max_dq and max_dq[0][1] < idx - k + 1:
                max_dq.popleft()

            # we are at the tail of the first window or higher
            if idx + 1 >= k:
                # left most element is the max of current subarray
                answer.append(max_dq[0][0])

            idx += 1

        return answer
