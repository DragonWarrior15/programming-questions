# https://leetcode.com/problems/min-cost-climbing-stairs/submissions/

"""
You are given an integer array cost where cost[i] is the cost of ith step on
a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.

Example 1:
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

Constraints:
2 <= cost.length <= 1000
0 <= cost[i] <= 999
"""


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        """Solve from end since that is easier to determine
        Standing at last stair, only option is to pay and take one step
        One one step prior to that, we can choose from one step or two
        Now, at every step, we will know all the future minima
        """
        min_cost = [float("inf")] * len(cost)

        for i in range(len(cost) - 1, -1, -1):
            # assume we are at this step
            # either pay to climb one or two steps
            if i == len(cost) - 1:
                # can only take one step
                min_cost[i] = cost[i]
            elif i == len(cost) - 2:
                # either take one step, or directly jump to end
                min_cost[i] = min(cost[i] + min_cost[i + 1], cost[i])
            else:
                min_cost[i] = min(
                    cost[i] + min_cost[i + 1], cost[i] + min_cost[i + 2]
                )

        # required ans is minimum of either taking index 0 or index 1
        return min(min_cost[0], min_cost[1])
