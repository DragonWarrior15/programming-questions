# https://leetcode.com/problems/container-with-most-water/

"""
You are given an integer array height of length n. There are n vertical
lines drawn such that the two endpoints of the ith line are (i, 0) and
(i, height[i]).
Find two lines that together with the x-axis form a container, such that
the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array
[1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section)
the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1

Constraints:
n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4
"""


class Solution:
    def maxArea(self, height: List[int]) -> int:
        """O(n^2) solution to use across the array repeatedly to find
        the largest area
        max_area = float("-inf")

        for i in range(len(height) - 1):
            for j in range(i + 1, len(height)):
                curr_area = min(height[i], height[j]) * (j - i)
                if curr_area > max_area:
                    max_area = curr_area

        return max_area
        """

        """Linear solution: we initialize two pointers at the extreme ends
        of the array and compute the possible area. Next, we move the
        pointer whichever is currently at the lesser of the heights, in
        an attempt to possibly increase the height of that pointer

        Proof of solution:
        https://leimao.github.io/blog/Proof-Container-With-Most-Water-Problem/

        Essentially, put the initial pointers at 1 and n and assume a1 <= an
        now, let A(i,j) denote area between indices i and j. We know that
        areas A(1,2), A(1,3), ... A(1,n-1) <= A(1,n) because any A(1,j) will
        be <= min(a1, aj) * (j-1) <= a1 * (j-1) < a1 * (n-1) = A(1,n)

        Now, we have eliminated the need to do these n-1 comparisons for
        calculating the maximum area

        We move the pointer and do similar calculations for how many candidates
        are eliminated which will show that O(n^2) candidates are eliminated
        resulting in a shorter runtime algorithm

        """

        left = 0
        right = len(height) - 1

        max_area = float("-inf")
        while left < right:
            curr_area = min(height[left], height[right]) * (right - left)
            if curr_area > max_area:
                max_area = curr_area

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return max_area
