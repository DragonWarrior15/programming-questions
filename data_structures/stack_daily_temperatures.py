# https://leetcode.com/problems/daily-temperatures/

"""
Given an array of integers temperatures represents the daily temperatures,
return an array answer such that answer[i] is the number of days you have to
wait after the ith day to get a warmer temperature. If there is no future day
for which this is possible, keep answer[i] == 0 instead.

Example 1:
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:
Input: temperatures = [30,60,90]
Output: [1,1,0]

Constraints:
1 <= temperatures.length <= 10^5
30 <= temperatures[i] <= 100
"""


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        """maintain a stack where we keep adding temperatures as long as every
        successive temperature is less than the top of the stack (this means
        that we have not obtained a higher temperature)
        at certain point, next temperature to be added is higher than the top
        of the stack; then this means that this temperature is higher than
        all the elements that are present on the stack (otherwise we violate
        how we are adding the lower temperatures to the top of the stack)
        we can add both the temp and its index to the stack to keep track of
        number of days till a higher temperature is observed
        """

        temperature_stack = []
        n = len(temperatures)
        days_count = [None] * n
        idx = 0
        while True:
            if idx >= n:
                break
            elif len(temperature_stack) == 0:
                temperature_stack.append((temperatures[idx], idx))
                idx += 1
            elif temperature_stack[-1][0] >= temperatures[idx]:
                temperature_stack.append((temperatures[idx], idx))
                idx += 1
            else:
                # found a higher temperature
                days_count[temperature_stack[-1][1]] = (
                    idx - temperature_stack[-1][1]
                )
                temperature_stack.pop()

        # check if the stack is non empty
        while len(temperature_stack) > 0:
            if len(temperature_stack) == 0:
                break
            else:
                days_count[temperature_stack[-1][1]] = 0
                temperature_stack.pop()

        return days_count
