# https://leetcode.com/problems/koko-eating-bananas/

"""
Koko loves to eat bananas. There are n piles of bananas, the ith pile has
piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she
chooses some pile of bananas and eats k bananas from that pile. If the pile
has less than k bananas, she eats all of them instead and will not eat any
more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas
before the guards return.
Return the minimum integer k such that she can eat all the bananas within
h hours.

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23

Constraints:
1 <= piles.length <= 10^4
piles.length <= h <= 10^9
1 <= piles[i] <= 10^9
"""


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        """Take k = max(piles), then h = len(piles), in the other extreme
        case, k = 1, then h = sum(piles), hence we know that the range of
        k is 1 to max(piles) and also we know that as k increases, value
        of h decreases
        to find the k corresponding to the optimal h, we do a binary search
        over k = 1 to max(piles),  if the h at k_mid is higher than required
        h, we simply move to a lower k

        since we want the minimum value of k, we need to keep doing the
        search till the left index is at the left

        we also define a separate function that can calculate the h for
        any given value of k
        """

        def calculate_h_given_k(k: int) -> int:
            h = 0
            for p in piles:
                # for any banana count at p, we can divide it into groups
                # of k bananas and eat them up
                h += (p // k) + (p % k > 0)  # equivalent to math.ceil

            return h

        low, high = 1, max(piles)
        mid = (low + high) // 2
        ans = high  # max possible value for k

        while high - low > 1:
            curr_h = calculate_h_given_k(mid)
            print(low, mid, high, curr_h)
            if curr_h <= h:
                # we have to eat within h hours, not necessarilly exactly h
                ans = mid
                high = mid
            else:
                low = mid

            mid = (low + high) // 2

        for temp in [low, mid, high]:
            if calculate_h_given_k(temp) <= h and temp < ans:
                ans = temp

        return ans
