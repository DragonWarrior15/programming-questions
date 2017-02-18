# given an array of ints, find all pairs of nos
# such that their xor is odd

from sys import stdin

for i in range(int(input())):
  N = int(input())
  A = list(map(int, stdin.readline().split()))
  num_even = len([1 for x in A if (x & 1 == 0)])
  print (num_even * (N - num_even))