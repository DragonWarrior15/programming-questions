"""
Little Shino loves to play with coins. In the city she lives, there are 26 different types of coins. 
Each coin is represented with a lowercase letter a to z. Shino has some number of coins and she placed 
them in some random sequence, S, on the table. She is wondering how many pairs (i,j) are there, where i<=j, 
such that number of distinct coins in sequence  is exactly equal to K. Two coins of same type (same letters) are 
considered equal and two coins of different types (different letters) are considered distinct.

Input:
First line contains one integer, K.
Second line contains a string, S, consist of lowercase letters only.

Output:
Print one integer, number of pairs , where , such that number of distinct coins in sequence  is exactly equal to K.

S consists of lowercase letters only.

SAMPLE INPUT 
3
abcaa
SAMPLE OUTPUT 
5
Explanation
Note:  denotes the sequence 
Since, 
Possible pairs  such that number of distinct coins in  is exactly equal to K are:
 and abc
 and abca
 and abcaa
 and bca
 and bcaa

So the answer is 5.
"""

"""
Basic idea here is to not do a brute force solution, but rather reduce the iterations we do for checking
this. If we have computed distinct elements in the range (i,j), we know that distinct elements in (i,j+1) will be
simply calculable by checking if A[j+1] is in the unique elements of (i,j) or not. Also, if the size of unique elements
already exceeds K, we do not need to check any further subsequence.
An even faster solution : https://www.geeksforgeeks.org/?p=134564
"""

from sys import stdin

data = stdin.read().split("\n")
K = int(data[0])
A = data[1]

# the answer to print
count = 0
for i in range(0, len(A) - K + 1):
    # get unique count in first sequence
    unique_set = set(A[i : i + K])
    unique_set_len = len(unique_set)
    # print(i, unique_set)
    if unique_set_len > K:
        # skip any further calculations
        continue
    if unique_set_len < K:
        # still not counted in the final answer
        pass
    if unique_set_len == K:
        count += 1
    for j in range(i + K, len(A)):
        # iterate over the subsequences starting from same i, but increasing the j,
        # keep increasing j and use similar if conditions as above
        # print(i, j, unique_set)
        if A[j] in unique_set:
            if unique_set_len == K:
                count += 1
            else:
                continue
        else:
            unique_set |= set([A[j]])
            unique_set_len += 1
            if unique_set_len < K:
                # check further subsequences
                continue
            if len(unique_set) == K:
                count += 1
                continue
            if len(unique_set) > K:
                break
print(count)
