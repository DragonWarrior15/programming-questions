# https://leetcode.com/problems/matchsticks-to-square/

"""
You are given an integer array matchsticks where matchsticks[i] is the
length of the ith matchstick. You want to use all the matchsticks to make one
square. You should not break any stick, but you can link them up, and each
matchstick must be used exactly one time.
Return true if you can make this square and false otherwise.

Example 1:
Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came
two sticks with length 1.

Example 2:
Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.

Constraints:
1 <= matchsticks.length <= 15
1 <= matchsticks[i] <= 10^8
"""


class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        # we do a backtracking to try out possible combinations of sticks
        # constraint is that the length of each side equals total / 4

        perimeter = sum(matchsticks)
        if perimeter % 4 != 0:
            return False

        square_side = perimeter // 4

        # sort the array in descending order, we start by assigning the
        # largest stick first as it reduces the number of combinations we
        # need to try out
        matchsticks.sort(reverse=True)

        # biggest stick should be less than square side
        if matchsticks[0] > square_side:
            return False

        # track the size of each side
        curr_sizes = [0] * 4

        # memory, track idx and sorted curr sizes: bool
        memory = {}

        def build(idx: int) -> bool:
            # try to fit the current index idx into one of the square sides

            k = tuple([idx] + sorted(curr_sizes))

            if k in memory:
                return memory[k]

            # base case
            if idx == len(matchsticks):
                # we have fit each matchstick into a side and made a valid
                # square
                return True

            # loop over sides and assign
            for side_idx in range(4):
                if curr_sizes[side_idx] + matchsticks[idx] <= square_side:
                    # can be fit here
                    curr_sizes[side_idx] += matchsticks[idx]

                    # early return
                    if build(idx + 1):
                        return True

                    # else continue
                    curr_sizes[side_idx] -= matchsticks[idx]

            # store in memory as well
            memory[k] = False
            return False

        return build(0)
