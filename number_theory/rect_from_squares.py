"""
Given S squares, what is the total no of unique rectangles possible,
using some or all of them, rectangle that can be obtained from rotation of
another should not be counted again
"""
from sys import stdin

T = int(stdin.readline().strip())
data = list(map(int, stdin.readlines()))

square_dict = {}

for S in data:
    ans = 0
    for i in range(1, S + 1):
        try:
            ans += square_dict[i]
        except KeyError:
            square_dict[i] = 0
            # calculate square root, perfect squares and odd nos will be special cases
            root = int(i**0.5)
            for j in range(1, root + 1):
                if i % j == 0:
                    square_dict[i] += 1
            ans += square_dict[i]
    print(ans)
