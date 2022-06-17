# https://leetcode.com/problems/group-anagrams/
"""
Given an array of strings strs, group the anagrams together.
You can return the answer in any order.An Anagram is a word or phrase
formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

Constraints:
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
"""

"""
A naive solution is to first have a check_anagram function and then
start appending strs to an answer list, while checking if the current str
is anagram with any of the existing groups of anagrams. The complexity
will be O(number of groups * total strings in the input)

A faster approach is O(n) and uses hashmap to determine which group
to add the current string to. The key of the hashmap is cleverly formed
using the count of different characters that appear in the str. Since
we know the string is only made of lowercase letters, we can have a static
array of length 26 (initialized to 0), traverse the str and increase the
corresponding character counters by 1, join all the 26 numbers by an _
and the resulting str is the key to which we will append all the anagrams.
In this approach, we only traverse the input list once and insertion to
the map is always O(1) so for all elements it still O(n) making the entire
solution O(n).
"""


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # convert each string to a hash representing count of characters
        anagram_hash = {}
        for i in range(len(strs)):
            char_count_arr = [0] * 26
            for j in range(len(strs[i])):
                char_count_arr[ord(strs[i][j]) - ord("a")] += 1

            curr_key = "_".join(map(str, char_count_arr))
            try:
                anagram_hash[curr_key].append(strs[i])
            except KeyError:
                anagram_hash[curr_key] = [strs[i]]

        ans = []
        # convert to ans
        for k in anagram_hash:
            ans.append(anagram_hash[k])

        # all done
        return ans
