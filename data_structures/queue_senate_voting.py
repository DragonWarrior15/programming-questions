"""
https://leetcode.com/problems/dota2-senate/

In the world of Dota2, there are two parties: the Radiant and the Dire.
The Dota2 senate consists of senators coming from two parties. Now the Senate
wants to decide on a change in the Dota2 game. The voting for this change is
a round-based procedure. In each round, each senator can exercise one of the
two rights:
    - Ban one senator's right: A senator can make another senator lose all his
    rights in this and all the following rounds.
    - Announce the victory: If this senator found the senators who still have
    rights to vote are all from the same party, he can announce the victory and
    decide on the change in the game.

Given a string senate representing each senator's party belonging. The
character 'R' and 'D' represent the Radiant party and the Dire party. Then
if there are n senators, the size of the given string will be n.
The round-based procedure starts from the first senator to the last senator in
the given order. This procedure will last until the end of voting. All the senators
who have lost their rights will be skipped during the procedure.
Suppose every senator is smart enough and will play the best strategy for his
own party. Predict which party will finally announce the victory and change the
Dota2 game. The output should be "Radiant" or "Dire".

Example 1:
Input: senate = "RD"
Output: "Radiant"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And in round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.

Example 2:
Input: senate = "RDD"
Output: "Dire"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And the third senator comes from Dire and he can ban the first senator's right in round 1. 
And in round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.

Constraints:
    n == senate.length
    1 <= n <= 10^4
    senate[i] is either 'R' or 'D'.
"""

# brute force
"""
class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        # keep a counter for R and D in the senate str
        count_R = 0
        count_D = 0
        for s in senate:
            if s == "R":
                count_R += 1
            else:
                count_D += 1

        while True:

            # break condition
            if count_D == 0:
                return "Radiant"
            elif count_R == 0:
                return "Dire"
            else:
                pass

            # the rounds keep going until we have only R or D remaining
            # index 0 is the current player
            for idx in range(1, len(senate)):
                if senate[idx] == senate[0]:
                    # continue to play
                    idx += 1
                else:
                    # we eliminate the current player
                    if senate[idx] == "R":
                        count_R -= 1
                    else:
                        count_D -= 1
                    break
            
            # move the current player to the end
            senate = senate[1:idx] + senate[idx + 1:] + senate[0]
"""

class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        # only the positions of the R and D in the senate matter
        queue_r = []
        queue_d = []

        for idx, s in enumerate(senate):
            if s == "R":
                queue_r.append(idx)
            else:
                queue_d.append(idx)

        # when pushing the player to the end of the queue, give them an
        # idx bigger than current max value to continue the series
        # till as long as required
        idx += 1

        while queue_r and queue_d:
            # take the first element from both the queues
            curr_r = queue_r.pop(0)
            curr_d = queue_d.pop(0)

            if curr_r < curr_d:
                # R plays first and removes D
                queue_r.append(idx)
            else:
                queue_d.append(idx)
            
            idx += 1

        # check which queue remains
        if queue_r:
            return "Radiant"
        else:
            return "Dire"
