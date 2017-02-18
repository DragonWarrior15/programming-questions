from sys import stdin

for i in range(int(input())):
  N = int(input())
  tot_sum = 0
  # get the highest power of 2 in the num
  N_1 = N
  count = 0
  while (N_1 > 0):
      N_1 >>= 1
      count += 1
  count -= 1
  N_3 = 2 ** count
  for j in range(count):
      N_2 = 2 ** j
      tot_sum += ((N_2 * (j + 1)) - 1)
      if (N_3 + N_2 <= N):
          tot_sum += (N_3 + N_2)
  print (tot_sum)