# https://leetcode.com/problems/longest-substring-without-repeating-characters/

"""
Given a string s, find the length of the longest substring without
repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not
a substring.

Constraints:
0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.
"""


class Solution:
    def lengthOfLongestSubstring_v1(self, s: str) -> int:
        """Maintain a map that contains the characters of the current ongoing
        substring; the values of the map will be the indexes corresponding
        to the position in string s; when a char is encountered that is
        already in the map, we simply restart the substring from the next
        position of the char already in map
        """

        if len(s) == 0:
            return 0

        substr_start = 0
        largest_substr_len = 1
        substr_dict = {s[0]: 0}
        idx = 1

        while idx < len(s):
            if s[idx] not in substr_dict:
                # found a new element that can be added to the dict
                substr_dict[s[idx]] = idx
            else:
                # found a repeat element, restart the substr
                substr_start = substr_dict[s[idx]] + 1
                # reset the map
                substr_dict = {}
                for i in range(substr_start, idx + 1):
                    substr_dict[s[i]] = i

            # check for largest substr at every iteration
            largest_substr_len = max(
                largest_substr_len, idx - substr_start + 1
            )
            # increment the index at every iteration
            idx += 1
        return largest_substr_len

    def lengthOfLongestSubstring(self, s: str) -> int:
        """This version builds on top of the above
        Instead of clearing the entire map and looking through the old
        window, we smartly update the map as follows
        if a char is not found in map, its a new unique char
        if the char is found in the map, but its index < start index
            update the new index for this char
        else:
            proceed same as the previous approach
        """

        if len(s) == 0:
            return 0

        substr_start = 0
        largest_substr_len = 1
        substr_dict = {s[0]: 0}
        idx = 1

        while idx < len(s):
            if s[idx] not in substr_dict:
                # found a new element that can be added to the dict
                substr_dict[s[idx]] = idx
            elif substr_dict[s[idx]] < substr_start:
                substr_dict[s[idx]] = idx
            else:
                # found a repeat element, restart the substr
                substr_start = substr_dict[s[idx]] + 1
                substr_dict[s[idx]] = idx

            # check for largest substr at every iteration
            largest_substr_len = max(
                largest_substr_len, idx - substr_start + 1
            )
            # increment the index at every iteration
            idx += 1
        return largest_substr_len
