"""
Oz has a list arr[] of M integers. He has to find all integers K such that :

1) K > 1
2) arr[1]%K = arr[2]%K = arr[3]%K = ... = arr[M]%K where '%' is a modulus operator
Help Oz to find all such K's.

Input :
First line of input contains an integer M. Then M lines follow each containing one integer of the list. Input data is such that at least one integer K will always exist.

Output :
Output all possible integers K separated by space in increasing order.

Constraints :
- 2<= M <=100
- 1< value of each integer <109
- All integers will be distinct

SAMPLE INPUT 
3
38
6
34
SAMPLE OUTPUT 
2 4 
"""

from sys import stdin

data = stdin.read().split("\n")

M = int(data[0])
A = map(int, data[1:])

# let b be the max of A, and a be the min of A, then
# (a + d)%k == a%k, then d%k == 0
# hence the task is simply to find all the divisors of d, such that all the
# elements of A have the same modulo with them

d = max(A) - min(A)

div_list = [x for x in range(2, d**0.5 + 1) if d % x == 0]

k_list = []

for k in div_list:
    if len(set([x % k for x in A])) == 1:
        k_list.append(k)

print(" ".join(map(str, k_list)))
