# https://leetcode.com/problems/counting-bits/

"""
Given an integer n, return an array ans of length n + 1 such that for each
i (0 <= i <= n), ans[i] is the number of 1's in the binary representation
of i.

Example 1:
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Example 2:
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101

Constraints:
0 <= n <= 10^5

Follow up:
It is very easy to come up with a solution with a runtime of O(n log n).
Can you do it in linear time O(n) and possibly in a single pass?
Can you do it without using any built-in function
(i.e., like __builtin_popcount in C++)?
"""


class Solution:
    def countBits(self, n: int) -> List[int]:
        """Key idea is bitcount of 7 = bitcount 4 + bitcount (7 - 4)
        where 4 is the lowest power before 7
        """
        ans = [0] * (n + 1)
        ans[0] = 0
        if n >= 1:
            ans[1] = 1
            power_of_2 = 1
        if n >= 2:
            ans[2] = 1
            power_of_2 = 2
        if n >= 3:
            for i in range(3, n + 1):
                if i == power_of_2 * 2:
                    # power of 2 always has a single set bit
                    ans[i] = 1
                    power_of_2 *= 2
                else:
                    # ans[i] = ans[power_of_2] + ans[i - power_of_2]
                    # ans[power_of_2] = 1 always
                    ans[i] = 1 + ans[i - power_of_2]

        return ans
