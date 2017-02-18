from sys import stdin
N, K = list(map(int, stdin.readline().split()))
A = list(map(int, stdin.readline().split()))
def fact(n):
 if n == 0 or n == 1:
  return 1
 ans = n
 i = n - 1
 while i > 1:
  ans *= i
  i -= 1
 return ans
even_list = [x for x in A if x % 2 == 0]
if (K > len(even_list)):
  print ('0')
else:
  print (fact(len(even_list))//(fact(len(even_list) - K) * fact(K)))