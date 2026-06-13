# https://leetcode.com/problems/plates-between-candles/

"""
There is a long table with a line of plates and candles arranged on top of it.
You are given a 0-indexed string s consisting of characters '*' and '|' only,
where a '*' represents a plate and a '|' represents a candle.
You are also given a 0-indexed 2D integer array queries where
queries[i] = [lefti, righti] denotes the substring s[lefti...righti]
(inclusive). For each query, you need to find the number of plates between
candles that are in the substring. A plate is considered between candles if
there is at least one candle to its left and at least one candle to its right
in the substring.

For example, s = "||**||**|*", and a query [3, 8] denotes the substring
"*||**|". The number of plates between candles in this substring is 2, as
each of the two plates has at least one candle in the substring to its left
and right.
Return an integer array answer where answer[i] is the answer to the ith query.

Example 1:
Input: s = "**|**|***|", queries = [[2,5],[5,9]]
Output: [2,3]
Explanation:
- queries[0] has two plates between candles.
- queries[1] has three plates between candles.

Example 2:
Input: s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],
[15,16]]
Output: [9,0,0,0,0]
Explanation:
- queries[0] has nine plates between candles.
- The other queries have zero plates between candles.

Constraints:
3 <= s.length <= 10^5
s consists of '*' and '|' characters.
1 <= queries.length <= 10^5
queries[i].length == 2
0 <= lefti <= righti < s.length
"""


class Solution:
    def platesBetweenCandles(
        self, s: str, queries: List[List[int]]
    ) -> List[int]:
        # we will be running muiltiple queries over the dataset.. hence we need
        # to come up with an approach such that the cost of per query is nearly
        # constant
        # to achieve this, we can try to build some sort of precalculated
        # count of plates, so that once a query comes in, we can just do a
        # quick subtraction to get the answer

        # first, lets build an array to store the count of plates between
        # all pairs of candles seen so far
        counts = [0] * len(s)

        # second, lets build two arrays, one to track closest left candle
        # and the other one to track the closest right candle
        closest_left_candle = [-1] * len(s)
        closest_right_candle = [-1] * len(s)

        last_candle_idx = None
        for idx, char in enumerate(s):
            # first set the candle
            if char == "|":
                # this is the closest left and right candle
                closest_left_candle[idx] = idx
                closest_right_candle[idx] = idx

                if last_candle_idx is None:
                    last_candle_idx = idx

                    # this is special case of finding the first candle
                    # for all the plates to the left of this candle
                    # the closest right candle is this
                    for idx1 in range(0, idx):
                        closest_right_candle[idx1] = idx

                else:
                    # we already saw a previous candle and are now seeing
                    # its pair candle.. count the number of plates between
                    # these two and add them to counts
                    counts[idx] = counts[idx - 1] + (idx - last_candle_idx - 1)

                    # this is the closest right candle for all the plates
                    # between the last candle and this candle
                    for idx1 in range(last_candle_idx + 1, idx):
                        closest_right_candle[idx1] = idx

                    # reset last candle idx
                    last_candle_idx = idx

            # if we dont observe a pair, carry forward the value of counts
            # and also update the closest left candle
            else:
                if idx != 0:
                    counts[idx] = counts[idx - 1]

                if last_candle_idx is not None:
                    closest_left_candle[idx] = last_candle_idx

        # all pre indexing is done, now run through the queries
        ans = [0] * len(queries)

        for idx, (left, right) in enumerate(queries):
            # first find the relevant closest candles
            # for the left index, find the closest right candle and vice
            # versa
            left_candle = closest_right_candle[left]
            right_candle = closest_left_candle[right]

            # bounday checks
            if (
                left_candle > right
                or right_candle < left
                or left_candle == -1
                or right_candle == -1
            ):
                # does not make sense to count, continue
                continue

            # everything satisfied, get the answer
            ans[idx] = counts[right_candle] - counts[left_candle]

        return ans
