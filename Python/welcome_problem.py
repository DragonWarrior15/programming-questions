N = int(input())
nums = [2, 3, 11, 13]
quotient = [N//i + 1 for i in nums]
multiples = set()
for i in range(4):
  multiples = multiples.union(set([nums[i] * x for x in range(quotient[i])]))
numerator = len(multiples) - 1
denominator = N
def GCD(a, b):
  if (b == 0):
    return (a)
  return (GCD(b, a % b))
gcd = GCD(numerator, denominator)
numerator //= gcd
denominator //= gcd
print (numerator, denominator)