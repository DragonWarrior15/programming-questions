# https://leetcode.com/problems/longest-consecutive-sequence/

"""
Given an unsorted array of integers nums, return the length of the
longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence
is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:
0 <= nums.length <= 105
-10^9 <= nums[i] <= 10^9
"""


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        """Store all the numbers in a dict and iterate through the keys
        one by one. At any element check if there is another element in the
        dict that is +1 or -1 away from this element: if yes then these
        two elements are part of a consecutive sequence and we can go
        on to the new found element and continue from there. Else, this
        element is a singleton element in a consecutive sequence. Once
        we have visited an element, we can simply mark the value as 0
        so as to not visit it again"""

        if len(nums) == 0:
            return 0

        nums_dict = {}
        for num in nums:
            # dont care about the repeats
            nums_dict[num] = 1

        max_seq_len = float("-inf")
        all_keys = list(nums_dict.keys())
        for num in all_keys:
            # if not visited
            if nums_dict[num] != 0:
                # try to look for other elements that can be part
                # of the group
                seq_len = 0
                seq_stack = [num]
                while len(seq_stack) > 0:
                    # get the last element from the stack and find
                    # its neighbors in the dict
                    curr_elem = seq_stack.pop()
                    nums_dict[curr_elem] = 0
                    seq_len += 1
                    for j in [-1, 1]:
                        try:
                            if nums_dict[curr_elem + j] != 0:
                                seq_stack.append(curr_elem + j)
                        except KeyError:
                            pass

                # check if this seq length is longer than already found
                if seq_len > max_seq_len:
                    max_seq_len = seq_len

            # if visited, no point, move to the next element
            else:
                continue

        return int(max_seq_len)
