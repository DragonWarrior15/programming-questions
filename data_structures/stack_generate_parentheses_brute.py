# https://leetcode.com/problems/generate-parentheses/

"""
Given n pairs of parentheses, write a function to generate all combinations
of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

Constraints:
1 <= n <= 8
"""


class Solution:
    def isValid(self, s: str) -> bool:
        """Possible brackets are ()[]{}, if we encounter opening bracket
        we add it to a stack, else we compare with the topmost and pop"""
        brackets_list = []
        for bracket in s:
            if bracket == "(":
                brackets_list.append(bracket)
            else:
                if len(brackets_list) == 0:
                    return False
                elif brackets_list[-1] == "(":
                    brackets_list.pop()
                else:
                    return False

        if len(brackets_list) > 0:
            return False

        return True

    def get_combinations(self, left_brackets=0, right_brackets=0):
        if not left_brackets and not right_brackets:
            return [""]
        elif not left_brackets and right_brackets:
            return [
                ")" + x
                for x in self.get_combinations(
                    left_brackets=left_brackets,
                    right_brackets=right_brackets - 1,
                )
            ]
        elif left_brackets and not right_brackets:
            return [
                "(" + x
                for x in self.get_combinations(
                    left_brackets=left_brackets - 1,
                    right_brackets=right_brackets,
                )
            ]
        else:
            return [
                "(" + x
                for x in self.get_combinations(
                    left_brackets=left_brackets - 1,
                    right_brackets=right_brackets,
                )
            ] + [
                ")" + x
                for x in self.get_combinations(
                    left_brackets=left_brackets,
                    right_brackets=right_brackets - 1,
                )
            ]

    def generateParenthesis(self, n: int) -> List[str]:
        all_combinations = self.get_combinations(
            left_brackets=n, right_brackets=n
        )
        all_combinations = [x for x in all_combinations if self.isValid(x)]

        return all_combinations
