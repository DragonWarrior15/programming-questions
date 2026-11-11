"""
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

A conveyor belt has packages that must be shipped from one port to another
within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we
load the ship with packages on the conveyor belt (in the order given by
weights). We may not load more weight than the maximum weight capacity of
the ship.
Return the least weight capacity of the ship that will result in all the
packages on the conveyor belt being shipped within days days.

Example 1:
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in
5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10
Note that the cargo must be shipped in the order given, so using a ship of
capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

Example 2:
Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages
in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4

Example 3:
Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1

Constraints:
1 <= days <= weights.length <= 5 * 10^4
1 <= weights[i] <= 500
"""


class Solution:
    def shipWithinDays(self, weights: list[int], days: int) -> int:
        # we need to partition the weights array into a total
        # of days groups
        # among all such breakups, we want to find the configuration
        # that has the minimum of the maximum capacity across all days
        # in that configuration, that is our answer
        # to have the lowest capacity, we need to use all the days
        # and spread the weights across
        # also remember, we have to put in order given in the weights array
        # the solution actually lies in thinking for a given capacity, what
        # is the count of days.. if we increase the capacity, does the days
        # count go up ?
        # then we can translate the problem to a search space where we
        # basically flip from not doable in given days to doable
        # and it becomes a binary search problem
        def get_days_for_capacity(weights: list[int], capacity: int) -> int:
            count_days = 1
            curr_total = 0

            for weight in weights:
                if curr_total + weight > capacity:
                    count_days += 1
                    curr_total = 0

                curr_total += weight

            return count_days

        # now the capacity range is we can either ship just one item per day
        # or we ship all items on a single day
        left = max(weights)
        right = sum(weights)

        while left < right:
            mid = (left + right) // 2
            curr_days = get_days_for_capacity(weights, mid)
            if curr_days <= days:
                # keep searching left
                right = mid
            else:
                # search right
                left = mid + 1

        return left
