"""
https://leetcode.com/problems/asteroid-collision/description/

We are given an array asteroids of integers representing asteroids in a row.
For each asteroid, the absolute value represents its size, and the sign represents its direction
(positive meaning right, negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller
one will explode. If both are the same size, both will explode. Two asteroids moving in the
same direction will never meet.

Example 1:
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Example 2:
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

Example 3:
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

Constraints:
    2 <= asteroids.length <= 104
    -1000 <= asteroids[i] <= 1000
    asteroids[i] != 0
"""

class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        # we maintain a stack, as long as elements are of the same sign
        # we put them on the stack, and element of opposite sign decide
        # when to pop, else keep stacking

        if len(asteroids) <= 1:
            return asteroids

        stack = []

        idx = 0
        # iterate till all asteroids are processed
        while idx < len(asteroids):
            if not stack:
                # put as is
                stack.append(asteroids[idx])
                idx += 1
            elif (stack[-1] < 0 and asteroids[idx] < 0) or (stack[-1] > 0 and asteroids[idx] > 0):
                # put on the stack as is
                stack.append(asteroids[idx])
                idx += 1
            elif (stack[-1] < 0 and asteroids[idx] > 0):
                # collision is not possible as - means left and + means right
                stack.append(asteroids[idx])
                idx += 1
            elif abs(stack[-1]) == abs(asteroids[idx]):
                # both get destroyed
                stack.pop()
                idx += 1
            elif abs(stack[-1]) > abs(asteroids[idx]):
                # no need to worry, asteroids[idx] gets destroyed, move on
                idx += 1
            else:
                # pop the top element and continue comparison with the next element of stack
                stack.pop()

        return stack

