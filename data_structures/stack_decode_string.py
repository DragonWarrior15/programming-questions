"""
https://leetcode.com/problems/decode-string/

Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the
square brackets is being repeated exactly k times. Note that k is guaranteed
to be a positive integer.
You may assume that the input string is always valid; there are no extra white
spaces, square brackets are well-formed, etc. Furthermore, you may assume that the
original data does not contain any digits and that digits are only for those repeat
numbers, k. For example, there will not be input like 3a or 2[4].
The test cases are generated so that the length of the output will never exceed 10^5.

Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

Constraints:
    1 <= s.length <= 30
    s consists of lowercase English letters, digits, and square brackets '[]'.
    s is guaranteed to be a valid input.
    All the integers in s are in the range [1, 300].
"""

class Solution:
    def decodeString(self, s: str) -> str:
        # base case
        if len(s) <= 1:
            return s

        nums = set([str(x) for x in range(0, 10)])
        
        # use a stack to track
        stack = []
        curr_num = ""
        for idx in range(len(s)):
            # print(idx, stack)
            # check for a num
            if s[idx] in nums:
                curr_num += s[idx]
            
            # check for a [
            elif s[idx] == "[":
                # if a num exists, put it in the stack, else put 1
                if curr_num:
                    stack.append(int(curr_num))
                else:
                    stack.append(1)

                # clear the current num as well
                curr_num = ""

            # check for a ]
            elif s[idx] == "]":
                # we need to process the stack
                stack_str = None
                stack_num = None
                while True:
                    stack_top = stack.pop()
                    if isinstance(stack_top, int):
                        stack_num = stack_top
                        break
                    else:
                        stack_str = stack_top
                
                # process the popped elements and put back on stack
                stack_str = stack_str * stack_num

                # concatenate all str at the top of the stack before putting back
                if stack:
                    stack_top = stack.pop()
                    if isinstance(stack_top, str):
                        stack_top = stack_top + stack_str
                        stack.append(stack_top)
                    else:
                        # put as is since a number
                        stack.append(stack_top)
                        stack.append(stack_str)
                else:
                    stack.append(stack_str)
            
            # a char/str
            else:
                if stack:
                    stack_top = stack.pop()
                    if isinstance(stack_top, int):
                        stack.append(stack_top)
                        stack.append(s[idx])
                    else:
                        # we do not stack chars, but append them together
                        # for ease of manipulation
                        stack.append(stack_top + s[idx])
                else:
                    stack.append(s[idx])
        # print(idx, stack)
        # whole thing processed, get the concatenated stack as answer
        return "".join(stack)
