# https://leetcode.com/problems/permutation-in-string/

"""
Given two strings s1 and s2, return true if s2 contains a permutation of s1,
or false otherwise.
In other words, return true if one of s1's permutations is the substring of
s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Constraints:
1 <= s1.length, s2.length <= 10^4
s1 and s2 consist of lowercase English letters.
"""


class Solution:
    def check_palindrome(self, s1: dict, s2: str) -> bool:
        # we assume that same length strings are passed
        # and also that all elements in s2 are in s1
        for c in s2:
            try:
                s1[c] -= 1
            except KeyError:
                return False

            if s1[c] < 0:
                return False

        return True

    def checkInclusion_v1(self, s1: str, s2: str) -> bool:
        """We iterate over s2 in blocks of length = s1 since the permutation
        must be exactly as long as s1
        For s1, we convert it to a map
        For the current block, we check whether all elements are in the map
        and also the counts of their occurrence is same or not
        """

        # base cases
        if len(s2) < len(s1):
            return False

        if len(s2) * len(s1) == 0:
            return False

        # try and see
        start_idx = 0
        idx = 0
        s1_map = {}
        for c in s1:
            try:
                s1_map[c] += 1
            except KeyError:
                s1_map[c] = 1

        while idx < len(s2):
            if s2[idx] not in s1_map:
                # restart the block
                start_idx = idx + 1
                idx += 1
            else:
                # check if block is complete or incomplete
                if idx - start_idx + 1 < len(s1):
                    # continue down the string
                    idx += 1
                else:
                    # found a block of same length as s1
                    # check for substring
                    if self.check_palindrome(
                        s1_map.copy(), s2[start_idx : idx + 1]
                    ):
                        return True
                    else:
                        # restart the search from start + 1
                        start_idx += 1
                        idx += 1

        return False

    def checkInclusion(self, s1: str, s2: str) -> bool:
        """We build on the previous solution and try to remove one place
        of repeated match trials + permutation check
        we exploit that fact that there are only 26 chars possible
        in any of the strings; hence we can maintain counters for all
        26 chars in two lists and only if both match, we have a correct
        permutation
        When going from one block to another, we can simply change the count
        for exiting and entering elements in the list of s2 and again do a
        check by maintaining a running counter for matches (instead of doing
        repeated 26 checks again and again) (since we know that if exiting
        element count was matching, match count -= 1 and if entering char
        count now matches, match count += 1)
        """

        if len(s1) > len(s2):
            return False

        if len(s1) * len(s2) == 0:
            return False

        s1_count = [0] * 26
        s2_count = [0] * 26

        for c in s1:
            s1_count[ord(c) - ord("a")] += 1

        matches = 0
        start_idx = 0

        for i in range(start_idx, len(s1)):
            # note we only keep counter for a block of size len(s1)
            s2_count[ord(s2[i]) - ord("a")] += 1

        for i in range(len(s1_count)):
            if s1_count[i] == s2_count[i]:
                matches += 1

        if matches == 26:
            return True

        while True:
            # add and remove
            # removed one is the start one
            outgoing = ord(s2[start_idx]) - ord("a")
            if start_idx + len(s1) >= len(s2):
                break
            incoming = ord(s2[start_idx + len(s1)]) - ord("a")

            if s2_count[outgoing] == s1_count[outgoing]:
                matches -= 1
            elif s2_count[outgoing] - 1 == s1_count[outgoing]:
                matches += 1
            else:
                pass
            s2_count[outgoing] -= 1

            if s2_count[incoming] + 1 == s1_count[incoming]:
                matches += 1
            elif s2_count[incoming] == s1_count[incoming]:
                matches -= 1
            else:
                pass
            s2_count[incoming] += 1

            if matches == 26:
                return True

            start_idx += 1

        return False
