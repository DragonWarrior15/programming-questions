# https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/?envType=problem-list-v2&envId=array

"""
Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum
less than or equal to threshold or return 0 if there is no such square.

Example 1:
Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
Output: 2
Explanation: The maximum side length of square with sum less than or equal to 4 is 2 as shown.

Example 2:
Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
Output: 0

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 300
0 <= mat[i][j] <= 10^4
0 <= threshold <= 10^5
"""


class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        # first build mat to be an array such that the value at index i,j
        # represents the sum of all elements of mat with row,col <= i,j

        m, n = len(mat), len(mat[0])

        for r in range(m):
            for c in range(n):
                if r == 0 and c == 0:
                    continue
                elif r == 0:
                    mat[r][c] += mat[r][c - 1]
                elif c == 0:
                    mat[r][c] += mat[r - 1][c]
                else:
                    # normal number inside the matrix
                    mat[r][c] += mat[r - 1][c] + mat[r][c - 1] - mat[r - 1][c - 1]

        # now we can do an iteration across the mat to maximize the area
        # maximum square size is min of length of side of matrix
        max_square_length = min(m, n)

        ans = 0

        for r in range(m):
            for c in range(n):
                # we are always interested in the biggest square possible
                # hence we can use the ans itself as a starting point
                # when moving between cells
                side_length = max(0, ans - 1)
                while side_length < max_square_length:
                    # if this is impossible, skip
                    if r + side_length >= m or c + side_length >= n:
                        break

                    # else get the sum and check its validtity
                    total = mat[r + side_length][c + side_length]

                    if r == 0 and c == 0:
                        # total remains as is, no need to change
                        pass
                    elif r == 0:
                        # only remove the extra left part
                        total -= mat[r + side_length][c - 1]
                    elif c == 0:
                        # only remove the extra top part
                        total -= mat[r - 1][c + side_length]
                    else:
                        # remove both left and top parts
                        total -= (
                            mat[r + side_length][c - 1]
                            + mat[r - 1][c + side_length]
                            - mat[r - 1][c - 1]
                        )

                    if total > threshold:
                        # no need to check any further sizes as bigger squares
                        # will not fit
                        break

                    if total <= threshold and side_length >= ans:
                        ans = side_length + 1

                    side_length += 1

        return ans
