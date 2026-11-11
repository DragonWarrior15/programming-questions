"""
https://leetcode.com/problems/minimum-operations-to-sort-a-string/description/

You are given a string s consisting of lowercase English letters.
In one operation, you can select any substring of s that is not the entire
string and sort it in non-descending alphabetical order.
Return the minimum number of operations required to make s sorted in
non-descending order. If it is not possible, return -1.

Example 1:
Input: s = "dog"
Output: 1
Explanation:
Sort substring "og" to "go".
Now, s = "dgo", which is sorted in ascending order. Thus, the answer is 1.

Example 2:
Input: s = "card"
Output: 2
Explanation:
Sort substring "car" to "acr", so s = "acrd".
Sort substring "rd" to "dr", making s = "acdr", which is sorted in ascending
order. Thus, the answer is 2.

Example 3:
Input: s = "gf"
Output: -1
Explanation:
It is impossible to sort s under the given constraints. Thus, the answer is -1.

Constraints:
1 <= s.length <= 10^5
s consists of only lowercase English letters.
"""


class Solution:
    def minOperations(self, s: str) -> int:
        # base case
        if len(s) == 2 and s != "".join(sorted(s)):
            return -1

        # alternate to sorting, runs in linear time
        if all(s[i] <= s[i + 1] for i in range(len(s) - 1)):
            return 0
        
        # s_sorted = "".join(sorted(s))

        # if s == s_sorted:
        #     return 0

        # read the minOperations_brute_force function to understand the brute
        # force solution.. following the pattern there, we can come to the
        # conclusion that what we are mainly trying to check is whether the
        # first position is occupied by the smallest char and the last
        # position is occupied by the largest char
        # if both are correctly occupied, a single sort of middle will do
        # the job
        # if only one is incorrectly occupied, sorting the corresponding
        # side will do the job
        # if both are incorrectly occupied, but not swapped for each other
        # we can do the job in two sorts, first will get either one of them
        # at the right place, while second will do the remaining part
        # if both are incorrectly occupied, and also swapped, we have two cases
        # if they are unique, we need 3 steps, because after 1st step, we need
        # two more to bring the first char at right place
        # in case of non-unique, the extra char must be somewhere in the middle
        # meaning, the first sort will automatically correct it and we would
        # only need 2 steps overall

        # count the chars and create a dictionary
        ord_to_count = {}
        for char in s:
            if char not in ord_to_count:
                ord_to_count[char] = 1
            else:
                ord_to_count[char] += 1

        unique_chars = sorted(ord_to_count.keys())

        if s[0] == unique_chars[0] or s[-1] == unique_chars[-1]:
            return 1
        else:
            # first case, they are swapped
            if s[0] == unique_chars[-1] and s[-1] == unique_chars[0]:
                # if both are unique, 3 sorts are needed
                if (
                    ord_to_count[unique_chars[0]] == 1
                    and ord_to_count[unique_chars[-1]] == 1
                ):
                    return 3
                else:
                    # 2 will do
                    return 2
            # second case, they are not swapped
            else:
                return 2

    def minOperations_brute_force(self, s: str) -> int:
        # base case
        if len(s) == 2 and s != "".join(sorted(s)):
            return -1

        s_sorted = "".join(sorted(s))

        if s == s_sorted:
            return 0

        # we can always be greedy and sort a sequence of n - 1 chars
        # this can either be the left one or the right one
        # we consider two types of operations, starting from the left
        # one or starting from the right one, and take the minimum
        # first left side one
        ops_ans = 0
        s_original = str(s)
        for start_side in [0, 1]:
            s_curr = s_original
            ops_curr = 0
            curr_start_side = start_side
            while s_curr != s_sorted:
                if curr_start_side == 0:
                    # left side
                    temp = "".join(sorted(s_curr[:-1]))
                    if temp != s_curr[:-1]:
                        ops_curr += 1
                        s_curr = temp + s_curr[-1]

                # right side
                else:
                    temp = "".join(sorted(s_curr[1:]))
                    if temp != s_curr[1:]:
                        ops_curr += 1
                        s_curr = s_curr[0] + temp

                # switch sides
                curr_start_side = 1 - curr_start_side

            # compare current count with overall
            if start_side == 0:
                ops_ans = ops_curr
            else:
                ops_ans = min(ops_ans, ops_curr)

        return ops_ans
