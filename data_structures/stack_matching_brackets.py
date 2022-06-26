# https://leetcode.com/problems/valid-parentheses/

"""
Given a string s containing just the characters
'(', ')', '{', '}', '[' and ']', determine if the input string is
valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Constraints:
1 <= s.length <= 10^4
s consists of parentheses only '()[]{}'.
"""


class Solution:
    def isValid(self, s: str) -> bool:
        """Possible brackets are ()[]{}, if we encounter opening bracket
        we add it to a stack, else we compare with the topmost and pop"""
        brackets_list = []
        for bracket in s:
            if bracket in ["(", "[", "{"]:
                brackets_list.append(bracket)
            else:
                if len(brackets_list) == 0:
                    return False
                elif bracket == ")":
                    if brackets_list[-1] == "(":
                        brackets_list.pop()
                    else:
                        return False
                elif bracket == "]":
                    if brackets_list[-1] == "[":
                        brackets_list.pop()
                    else:
                        return False
                elif bracket == "}":
                    if brackets_list[-1] == "{":
                        brackets_list.pop()
                    else:
                        return False

        if len(brackets_list) > 0:
            return False

        return True
