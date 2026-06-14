# https://leetcode.com/problems/maximum-total-damage-with-spell-casting

"""
A magician has various spells.
You are given an array power, where each element represents the damage of a
spell. Multiple spells can have the same damage value.
It is a known fact that if a magician decides to cast a spell with a damage
of power_unique[i], they cannot cast any spell with a damage of
power_unique[i] - 2, power_unique[i] - 1, power_unique[i] + 1,
or power_unique[i] + 2. Each spell can be cast only once.
Return the maximum possible total damage that a magician can cast.

Example 1:
Input: power = [1,1,3,4]
Output: 6
Explanation:
The maximum possible damage of 6 is produced by casting spells 0, 1, 3 with
damage 1, 1, 4.

Example 2:
Input: power = [7,1,6,6]
Output: 13
Explanation:
The maximum possible damage of 13 is produced by casting spells 1, 2, 3 with
damage 1, 6, 6.

Constraints:
1 <= power.length <= 10^5
1 <= power[i] <= 10^9
"""


class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        # greedy algo will not fit in this problem due to several different
        # possible scenarios
        # we tackle this with a DP approach
        # lets first sort the array after finding unique values
        from collections import Counter
        import bisect

        power_counts = Counter(power)

        power_unique = list(power_counts.keys())
        power_unique.sort()

        # create another array to track the max damage till index i
        max_total_damage = [0] * len(power_unique)

        # recursively iterate
        idx = 1
        max_total_damage[0] = power_unique[0] * power_counts[power_unique[0]]

        while idx < len(power_unique):
            # at current index, we can either take the current spell
            # in that case, we need to find the closest spell with power
            # at most power_unique[idx] - 3
            potential_idx = bisect.bisect_right(
                power_unique, power_unique[idx] - 3, 0, idx
            )

            curr_max = power_unique[idx] * power_counts[power_unique[idx]]
            # if a potential index was found, use that
            if potential_idx != 0:
                curr_max += max_total_damage[potential_idx - 1]

            # other option is to ignore the current power, then we are free
            # to take the value at the last index
            curr_max = max(max_total_damage[idx - 1], curr_max)

            # curr max is found, now assign it
            max_total_damage[idx] = curr_max

            idx += 1

        return max_total_damage[-1]
