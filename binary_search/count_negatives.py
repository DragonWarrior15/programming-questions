# https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

"""
Given a m x n matrix grid which is sorted in non-increasing order both
row-wise and column-wise, return the number of negative numbers in grid.

Example 1:
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:
Input: grid = [[3,2],[1,0]]
Output: 0

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100
"""


class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        # go row wise.. once we find a negative number in a row
        # in the next row, we can search only till that index
        # no need to check the remaining.. since they will all
        # be -ve anyway due to the structure of the problem
        count = 0
        last_neg_index = None
        for row in range(len(grid)):
            low = 0
            # we subtract 1 from last_neg_index as well to prevent double
            # counting.. when the index across consecutive rows is same
            high = (
                last_neg_index if last_neg_index is not None else len(grid[0])
            ) - 1
            high_boundary = high
            ans = None
            while low <= high:
                mid = (low + high) // 2
                if grid[row][mid] < 0:
                    # candidate index, keep going left
                    high = mid - 1
                    ans = mid
                else:
                    # go right to find smaller number
                    low = mid + 1

            # once we are out of the loop, we know the leftmost index
            # of a negative number.. if it exists..
            # if it exists.. the entire rectangle to the right and below this
            # index is made of all -ves
            if ans is not None:
                count += (high_boundary + 1 - ans) * (len(grid) - row)
                # update the last neg index
                last_neg_index = ans

        return count
