"""
https://leetcode.com/problems/delete-and-earn/

You are given an integer array nums. You want to maximize the number of points
you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must
delete every element equal to nums[i] - 1 and every element equal to
nums[i] + 1.
Return the maximum number of points you can earn by applying the above
operation some number of times.

Example 1:
Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.

Example 2:
Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.

Constraints:
1 <= nums.length <= 2 * 104
1 <= nums[i] <= 104
"""


class Solution:
    def deleteAndEarn(self, nums: list[int]) -> int:
        # The solution requires thinking this way: first, lets build a map
        # to track the unique numbers and their counts, that helps us get a
        # sense of overall value
        # now, note that we can form partitions, where a partition is made of
        # only continuous numbers, deleting a number in a partition only
        # affects that partition, not others, hence the same algo works for
        # each partition
        # next, consider one partition, say 1,2,3,4 the solution is either
        # take 1 or skip 1.. when we take 1, we must run the algo starting at
        # 3 while for the other case, we run algo starting at 2
        # so we must know the rightwards answers first to get back to 1/2
        # hence, we can solve the problem from right to left, where dp[4]
        # say represents the maximum possible answer obtainable starting at 4
        # where starting considers both taking and skipping 4
        # first form the map
        answer = 0
        nums_to_counts = {}
        for num in nums:
            nums_to_counts[num] = nums_to_counts.get(num, 0) + 1

        # sort the keys
        nums_unique = sorted(nums_to_counts.keys())

        # work through each partition
        start, end = 0, 0
        while end < len(nums_unique):
            if (
                end + 1 != len(nums_unique)
                and nums_unique[end + 1] == nums_unique[end] + 1
            ):
                # continue building the partition
                end += 1
            else:
                # we have found a break in the partition
                # apply our algo here
                dp = [0] * (end - start + 1)
                # idx works backward from end to start
                idx = len(dp) - 1
                while idx > -1:
                    # either skip or take
                    curr_num = nums_unique[start + idx]  # len(dp) - 1 = end
                    dp[idx] = max(
                        # take
                        curr_num * nums_to_counts[curr_num]
                        + (dp[idx + 2] if idx + 2 < len(dp) else 0),
                        # skip
                        dp[idx + 1] if idx + 1 < len(dp) else 0,
                    )
                    idx -= 1

                # update the answer as well
                answer += dp[0]

                # reset start and end
                start = end + 1
                end = start

        return answer
