'''
Shil, Aditya and Utkarsh go to a candy shop. There are N candies present in the shop, which are indexed from 1 to N. All three of them select one candy to eat.

However, a candy tastes delicious if and only if, the index of candy chosen by Shil is strictly less than the index of candy chosen by Aditya and the index of candy chosen by Aditya is strictly greater than index of candy chosen by Utkarsh.

To state in simple Mathematical terms, if Shil chooses ith candy, Aditya chooses jth candy and Utkarsh chooses kth candy, then the candies would taste delicious

if and only if i < j and j > k.

You have to find the total number of ways in which they can choose candies such that the candies would taste delicious to them. Note that all of them choose distinct number of candies i.e., i!=j and j!=k and i!=k.

Input format:
The only line of input consists of a single integer N denoting the total number of candies.

Output format:
Find the total number of ways by which all three can choose candies such that the candies would taste delicious to them.

Constraints:
3 ≤ N ≤ 1000

SAMPLE INPUT 
4
SAMPLE OUTPUT 
8
Explanation
All the possible ways to choose candies are:

[1,3,2]
[2,3,1]
[2,4,3]
[3,4,2]
[1,4,3]
[3,4,1]
[2,4,1]
[1,4,2]
The first integer in all the tuples denotes index of candy chosen by Shil, the second integer denotes index of candy chosen by Aditya and the third integer denotes index of candy chosen by Utkarsh.
'''

'''
approach
for any j that is chosen, there at j - 1 ways to choose i
and j - 2 ways to choose k. sum this over 3 to the no of candies
'''

from sys import stdin

N = int(stdin.readline().strip())

ans = 0
for i in range(3,  N + 1):
    ans += (i - 1) * (i - 2)

print(ans)
