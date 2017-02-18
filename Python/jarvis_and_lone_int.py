# from an array of integers, find the one which doesn't pair with any other int
# pairing is defined as two same integers at different indices

from sys import stdin

T = int(input())

for i in range(T):
  N = int(input())
  A = list(map(int, stdin.readline().split()))
  ans = -1
  xor_result =  0
  for j in range(N):
    xor_result ^= A[j]
  print (ans if xor_result == 0 else xor_result)