"""
let P(x) = x ^ (x //2)
for some x, P(x) is know and is given as input
find the value of x
"""

from sys import stdin

N = int(stdin.readline().strip())

# x ^ (x//2) = N taken above as input,
# we have to get x

N_bin = bin(N)[2:]
x_bin = [1]

for i in range(1, len(N_bin)):
    # note that the second no in xor is just the original no
    # shifted by 1 bit
    # if x = 1010, x//2 = 101, if xor is known, we know the first bit, ie 1
    # and can work rightwards to get the original bits
    # 1 ^ 1 = 0 ^ 0 = 1
    if N_bin[i] == "0":
        x_bin.append(x_bin[i - 1])
    else:
        x_bin.append(1 - x_bin[i - 1])

x = int("".join(map(str, x_bin)), 2)
print(x)
