"""
Given an array of integers, and a sum S, find if it is possible to form the sum S
using some or none of the integers. 0 can always be formed using none of the elements
"""

from sys import stdin


def checkSum(S, A, n):
    if S == 0:
        return True
    elif n <= 0:
        return False
    else:
        return checkSum(S, A, n - 1) or checkSum(S - A[n - 1], A, n - 1)


T = int(stdin.readline().strip())

data = stdin.readlines().strip()
for i in range(T):
    N = int(data[i * 3].strip())
    A = list(map(int, data[i * 3 + 1].strip()))
    S = int(data[i * 3 + 2].strip())

    if S == 0:
        print("YES")
    else:
        if checkSum(S, A, len(A)):
            print("YES")
        else:
            print("NO")
