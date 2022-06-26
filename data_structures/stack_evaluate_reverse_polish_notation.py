# https://leetcode.com/problems/evaluate-reverse-polish-notation/

"""
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or
another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means
the expression would always evaluate to a result, and there will not be any
division by zero operation.

Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

Constraints:
1 <= tokens.length <= 10^4
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the
range [-200, 200].
"""


class Solution:
    def perform_operation(self, a, b, operator_char):
        a = int(a)
        b = int(b)
        if operator_char == "+":
            return str(a + b)
        elif operator_char == "-":
            return str(a - b)
        elif operator_char == "*":
            return str(a * b)
        else:
            return str(int(a / b))

    def evalRPN(self, tokens: List[str]) -> int:
        evaluation_stack = []
        idx = 0
        while True:
            if len(evaluation_stack) == 0 and idx < len(tokens):
                # can add tokens
                evaluation_stack.append(tokens[idx])
                idx += 1
            elif idx >= len(tokens) and len(evaluation_stack) == 1:
                # idx finished and nothing to compute on stack
                break
            elif evaluation_stack[-1] in ("+", "-", "*", "/"):
                # perform computation
                operator_char = evaluation_stack.pop()
                b = evaluation_stack.pop()
                a = evaluation_stack.pop()
                evaluation_stack.append(
                    self.perform_operation(a, b, operator_char)
                )
            else:
                # we have a number at the index, insert it into the stack
                evaluation_stack.append(tokens[idx])
                idx += 1

        return int(evaluation_stack.pop())
