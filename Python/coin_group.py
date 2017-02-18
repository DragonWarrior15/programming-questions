from sys import stdin
t = int(input())
n = list(map(int, stdin.read().split('\n')))
for i in range(t):
  num = n[i]
  ans = 0
  num_sqrt = int(num ** 0.5)
  for j in range(1, num_sqrt + 1):
    if (num % j == 0):
      ans += 2
  if (num_sqrt * num_sqrt == num):
    ans -= 1
  print (ans)