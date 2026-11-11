"""
https://leetcode.com/problems/hand-of-straights/description/

Alice has some number of cards and she wants to rearrange the cards into groups
so that each group is of size groupSize, and consists of groupSize consecutive
cards.
Given an integer array hand where hand[i] is the value written on the ith card
and an integer groupSize, return true if she can rearrange the cards, or
false otherwise.

Example 1:
Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

Example 2:
Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

Constraints:
1 <= hand.length <= 10^4
0 <= hand[i] <= 10^9
1 <= groupSize <= hand.length
"""

class Solution:
    def isNStraightHand(self, hand: list[int], groupSize: int) -> bool:
        # we store the card value in a map where we track total
        # such available cards
        # we also maintain a heap to get the current smallest value
        # card
        # idea is, if we are starting a new group, current smallest
        # card has to go in that group, and then we just search for
        # remaining cards, if they are there, group exists, else
        # it does not
        from heapq import heapify, heappop

        # first build the map
        cards = {}
        for num in hand:
            cards[num] = cards.get(num, 0) + 1

        heap = list(cards.keys())
        heapify(heap)

        while heap:
            # get the lowest card
            start = heap[0]

            # if start is not in cards, all cards might have been used up
            # just pop and continue
            if start not in cards or cards[start] == 0:
                heappop(heap)
                continue

            if cards[start] == 1:
                # we are going to use this card, better to remove
                heappop(heap)

            # check for all cards in the map and update it accordingly
            for num in range(start, start + groupSize):
                if num not in cards or cards[num] == 0:
                    return False

                # update map since we are using this card
                cards[num] -= 1

        # gone through all groups, good to form groups
        return True
