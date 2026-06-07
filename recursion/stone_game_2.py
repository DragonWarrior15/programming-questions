# https://leetcode.com/problems/stone-game-ii/description/?envType=problem-list-v2&envId=array

"""
Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row,
and each pile has a positive integer number of stones piles[i]. The objective of the game
is to end with the most stones.

Alice and Bob take turns, with Alice starting first.

On each player's turn, that player can take all the stones in the first X remaining
piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.



Example 1:

Input: piles = [2,7,9,4,4]

Output: 10

Explanation:

If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2
piles again. Alice can get 2 + 4 + 4 = 10 stones in total.
If Alice takes two piles at the beginning, then Bob can take all three piles left.
In this case, Alice get 2 + 7 = 9 stones in total.
So we return 10 since it's larger.

Example 2:

Input: piles = [1,2,3,4,5,100]

Output: 104


Constraints:

1 <= piles.length <= 100
1 <= piles[i] <= 104
"""


class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        # observing that piles length can be maximum of 100, we do not need
        # to go for a O(n) solution

        # lets start with a recursive approach, where we iterate over turns
        # and get the one which gives the maximum result

        # keep a map for already seen states
        m = {}

        def play(player_idx: int, pile_idx: int, M: int) -> List[int]:
            k = (player_idx, pile_idx, M)
            if k in m:
                return m[k]
            # get the maximum each player can earn from here
            # focusing on current player

            out = [0, 0]

            # base case, if we can take all stones of the current pile
            # that will be done
            if len(piles) - pile_idx <= 2 * M:
                out[player_idx] = sum(piles[pile_idx:])
                return list(out)

            future_reward = [0, 0]

            # else we play
            for stones_taken in range(1, min(2 * M + 1, len(piles))):
                future_reward = list(
                    play(1 - player_idx, pile_idx + stones_taken, max(M, stones_taken))
                )
                curr_score = sum(piles[pile_idx : pile_idx + stones_taken])
                future_reward[player_idx] += curr_score

                if future_reward[player_idx] > out[player_idx]:
                    out = list(future_reward)

            m[k] = out
            return list(out)

        return play(0, 0, 1)[0]
