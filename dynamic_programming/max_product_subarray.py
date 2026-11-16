"""
https://leetcode.com/problems/maximum-product-subarray/description/
"""


class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        """
        the way we are approaching it is partitioning at zeros, max product
        subarray will lie somewhere in the array partitioned by zeros
        next, within that partition, we need to look for the number of
        negative ints, if its even, we can take all numbers from partition
        else, we need to consider the two negative numbers on either tails
        and only pick one of them to compute the maximum product
        we need to track the positions of 0, and the positions of negatives

        this is very difficult to implement though.. and as always, there is
        a simpler solution using dp

        maintain both the minimum and maximum products ending at that position
        why minimum ? bec if the current product is -12, and next number is -2
        multiplying both will give us a new max which is 24
        the updates come from x, previous max * x and previous min * x
        zero is also automatically handled
        """
        previous_min = None
        previous_max = None
        answer = None

        for num in nums:
            if previous_max is not None:
                previous_min = num
                previous_max = num
                answer = num
            else:
                previous_max, previous_min = (
                    max(num, previous_min * num, previous_max * num),
                    min(num, previous_min * num, previous_max * num),
                )
                answer = max(answer, previous_max, previous_min)

        return answer
