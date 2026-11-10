"""
https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

You are given an integer array bloomDay, an integer m and an integer k.
You want to make m bouquets. To make a bouquet, you need to use k adjacent
flowers from the garden.
The garden consists of n flowers, the ith flower will bloom in the bloomDay[i]
and then can be used in exactly one bouquet.
Return the minimum number of days you need to wait to be able to make m
bouquets from the garden. If it is impossible to make m bouquets return -1.

Example 1:
Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means
flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.

Example 2:
Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6
flowers. We only have 5 flowers so it is impossible to get the needed
bouquets and we return -1.

Example 3:
Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here is the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot
make another bouquet from the last three flowers that bloomed because they
are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.

Constraints:
bloomDay.length == n
1 <= n <= 10^5
1 <= bloomDay[i] <= 10^9
1 <= m <= 10^6
1 <= k <= n
"""


class Solution:
    def minDays(self, bloomDay: list[int], m: int, k: int) -> int:
        # lets first define a function that given a day count, can tell us
        # if we can make a bouquet out of the available flowers
        def can_make_bouquets(n: int) -> bool:
            """n is the number of days at which we are checking this."""
            count_bouquets = 0
            active_bouquet_size = 0
            # greedily try to make a bouquet
            idx = 0
            while idx < len(bloomDay) and count_bouquets < m:
                # if we dont have any active bouquet, try to start one
                # this branch is apparently redundant, but kept here to capture
                # the thought process
                if active_bouquet_size == 0:
                    if bloomDay[idx] > n:
                        # cannot be used, continue
                        idx += 1
                    else:
                        # we can use this and we start a new bouquet basically
                        active_bouquet_size += 1
                        idx += 1

                        # edge case
                        # check if we have breached the size limit
                        if active_bouquet_size == k:
                            # we have a valid bouquet, increment variables
                            # and start a fresh bouquet from next flower
                            count_bouquets += 1
                            active_bouquet_size = 0
                            # idx is already incremented

                # we are already in middle of building a bouquet
                else:
                    if bloomDay[idx] > n:
                        # current bouquet must be broken
                        active_bouquet_size = 0
                        idx += 1
                    else:
                        # we can increase the size of current bouquet
                        active_bouquet_size += 1
                        idx += 1

                        # check if we have breached the size limit
                        if active_bouquet_size == k:
                            # we have a valid bouquet, increment variables
                            # and start a fresh bouquet from next flower
                            count_bouquets += 1
                            active_bouquet_size = 0
                            # idx is already incremented

            # if we exited the loop bec we built sufficient bouquets
            return count_bouquets >= m

        # we must use binary search to shrink the valid space of checks
        left, right = 1, max(bloomDay)

        while left < right:
            mid = (left + right) // 2
            if can_make_bouquets(mid):
                # try going further left for a smaller answer
                right = mid
            else:
                # must search in right
                left = mid + 1

        if can_make_bouquets(right):
            return right
        return -1
