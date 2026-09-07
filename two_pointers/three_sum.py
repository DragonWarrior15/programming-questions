"""
https://leetcode.com/problems/3sum/description/

Given an integer array nums, return all the triplets [nums[i], nums[j],
nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k]
== 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not
matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:
3 <= nums.length <= 3000
-10^5 <= nums[i] <= 10^5
"""

class Solution:
    def threeSum_brute(self, nums: list[int]) -> list[list[int]]:
        # do a double loop over nums to get possible sums of i + j
        # also keep storing which number appears at what index in a dict
        # in the end, we will pass over the possible sum X dict combinations
        # to get the required 3 sums

        num_to_idx = {}
        ans = set()

        for i in range(len(nums)):
            # add to num to idx
            # we want to ensure last number also gets
            # added to num to idx
            if nums[i] in num_to_idx:
                num_to_idx[nums[i]].append(i)
            else:
                num_to_idx[nums[i]] = [i]

        unique_nums = list(num_to_idx.keys())

        for i in range(len(unique_nums)):
            for j in range(i, len(unique_nums)):
                num_1 = unique_nums[i]
                num_2 = unique_nums[j]
                # we can use the same number twice also
                if i == j and len(num_to_idx[num_1]) <= 2:
                    # not possible to use
                    continue

                # now i and j are different, meaning different numbers
                num_3 = 0 - num_1 - num_2

                if num_3 not in num_to_idx:
                    continue

                nums_sorted_tuple = tuple(sorted([num_1, num_2, num_3]))

                if nums_sorted_tuple in ans:
                    continue

                # either num_3 is new, or equal to one of num_1 and num_2
                if num_3 == num_1:
                    # check if num_1 can be used twice, if yes, good to add
                    if len(num_to_idx[num_1]) >= 2:
                        ans.add(nums_sorted_tuple)

                elif num_3 == num_2:
                    # check if num_2 can be used twice, if yes, good to add
                    if len(num_to_idx[num_2]) >= 2:
                        ans.add(nums_sorted_tuple)

                else:
                    # directly add
                    ans.add(nums_sorted_tuple)

        return list(ans)

    def threeSum(self, nums: list[int]) -> list[list[int]]:
        # sort the numbers and then just do a linear search
        nums = sorted(nums)
        n = len(nums)
        ans = []
        for i in range(n - 2):
            # duplicates case
            if i >= 1 and nums[i] == nums[i - 1]:
                continue

            # use two pointers
            j, k = i + 1, n - 1

            while True:
                # check the sum, if < 0, move j to right else k to left
                # bec numbers are sorted
                s = nums[i] + nums[j] + nums[k]

                if j >= k:
                    break
                elif s < 0:
                    j += 1
                elif s > 0:
                    k -= 1
                else:
                    # found a match
                    ans.append([nums[i], nums[j], nums[k]])
                    # we move j, but till the number changes as
                    # duplicates are not allowed
                    # can move any pointer
                    while True:
                        j += 1
                        if j >= k:
                            break
                        if nums[j] != ans[-1][1]:
                            break

        return list(ans)