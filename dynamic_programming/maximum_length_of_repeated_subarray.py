"""
https://leetcode.com/problems/maximum-length-of-repeated-subarray/
"""


class Solution:
    def findLength(self, nums1: list[int], nums2: list[int]) -> int:
        n1 = len(nums1)
        n2 = len(nums2)
        # we can use a simple dp array of the dimensions n1 X n2
        # d[i,j] in this array answers what is the longest subarray
        # ending at i,j and we can fill it with a basic rule,
        # if both positions equal each other, we consider 1 + dp[i-1,j-1]
        # we do not consider anything else as we need the last element to match
        # and we want contiguous matching
        dp = []

        answer = 0
        
        for _ in range(n2):
            dp.append([0] * n1)

        for i in range(n2):
            if nums2[i] == nums1[0]:
                dp[i][0] = 1
                answer = 1

        for j in range(n1):
            if nums1[j] == nums2[0]:
                dp[0][j] = 1
                answer = 1

        for i in range(1, n2):
            for j in range(1, n1):
                if nums2[i] == nums1[j]:
                    # dp[i-1][j-1] already carries info about longest
                    # contiguous subarray ending at i-1,j-1
                    # if no such subarray exists, the value is 0, else whatever
                    # is the length obtained till that point
                    dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1])
                answer = max(answer, dp[i][j])

        return answer
