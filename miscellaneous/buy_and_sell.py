# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

"""
You are given an array prices where prices[i] is the price of a given stock
on the ith day.
You want to maximize your profit by choosing a single day to buy one stock
and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot
achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6),
profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you
must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Constraints:
1 <= prices.length <= 10^5
0 <= prices[i] <= 10^4
"""


class Solution:
    def maxProfit_v1(self, prices: List[int]) -> int:
        """Get the minimum value preffix and position by traversing
        the array left to right; then we can find the maximum profit by
        traversing the two arrays in one go
        """
        min_price_prefix = []
        for i in range(len(prices)):
            if i <= 1:
                min_price_prefix.append(prices[0])
            else:
                min_price_prefix.append(
                    min(min_price_prefix[-1], prices[i - 1])
                )

        profit = 0
        for i in range(len(prices)):
            curr_profit = prices[i] - min_price_prefix[i]
            if curr_profit > profit:
                profit = curr_profit

        return profit

    def maxProfit(self, prices: List[int]) -> int:
        """We can optimize the above solution to use O(1) storage by keeping
        track of a running minimum rather than building a complete array
        Think of this like keeping track of the minimum price seen so far
        """
        min_price = prices[0]
        profit = 0
        for p in prices:
            # get the updated minimum so far
            min_price = min(p, min_price)
            # update the profit as well, if current p is minimum, profit will
            # still retain the old value as new profit will be 0 < maximum
            profit = max(p - min_price, profit)

        return profit
