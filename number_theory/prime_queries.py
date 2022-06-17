'''
With the help of the tessaract, the Chitauri army is ready to attack planet Earth. It's finally time when the Avengers must get together to save the planet. Captain Fury, along with the beautiful Agent Maria Hill is trying to work out a plan. He is well aware that Loki, the leader of the enemies has identified certain prime spots to attack. Each spot on the planet is identified by a specific number. A prime spot is one that is represented by a prime number. Now, the Captain's intelligence team has provided him with a list of N locations . From time to time, the team also replaces one location in the list with another one. Every now and then, Captain Fury asks Maria to report the number of prime locations between positions X & Y (inclusive) in the list so that he could position the Avengers at those locations. Now the beautiful lady is tired. Help her.

Input:
The first line consists of an integer T, the number of test cases. Then the description of T test cases follow. The first line of each test case consists of an integer N, the number of locations in the list given to Doctor Fury. The next line contains N space separated integers. The next line contains Q, the total number of times either the list is changed or the Captain asks Maria his query. Then Q lines follow, each of the line having one of the following format

i)  - where C is UpperCase alphabet 'C' representing a change in the list, X represents the list index where the change is to be made, Y represents the new location that is added to the above index e.g. 

ii)  - where A is Uppercase alphabet 'A' representing asking prime spots between indexes X and Y (inclusive) in the list e.g. 

Output:

For each of the query for asking number of prime spots, output a single integer, the answer to Captain Fury's question.

Constraints:

 1 <= T <= 10
 1 <= N <= 32000
 1 <= A[i] <= 10^6
 1 <= Q <= 20000


*NOTE: *
Large Input File (~2 MB)

Use 1-based indexing for all list queries

SAMPLE INPUT 
1
10
1 3 18 960 22 17 15 31 99 231
5
A 1 10
C 3 17
C 5 23
A 1 10
A 1 5
SAMPLE OUTPUT 
3
5
3

'''


from sys import stdin

a prime checker function
def isPrime(n) : 
    # Corner cases 
    if (n <= 1) : 
        return False
    if (n <= 3) : 
        return True
  
    # This is checked so that we can skip  
    # middle five numbers in below loop 
    if (n % 2 == 0 or n % 3 == 0) : 
        return False
  
    i = 5
    while(i * i <= n) : 
        if (n % i == 0 or n % (i + 2) == 0) : 
            return False
        i = i + 6
  
    return True


# read the data
data = stdin.read().strip().split('\n')
# get the no of test cases
T = int(data[0])
# we will keep incrementing this value whenever we process a single line from data
data_index = 1
for _ in range(T):
    # the no of integers in list
    N = int(data[data_index])
    data_index += 1
    # the list
    A = list(map(int, data[data_index].split(' ')))
    
    # create a new list containing boolean value for isPrime
    # this is important as this significantly speeds up the process
    # instead of checking primality on the fly
    A_isprime = list(map(isPrime, A))
    data_index += 1
    Q = int(data[data_index])
    data_index += 1
    # loop over the queries
    for _ in range(Q):
        query_type, query_1, query_2 = data[data_index].split(' ')
        data_index += 1

        query_1, query_2 = int(query_1), int(query_2)

        if(query_type == 'C'):
            A[query_1 - 1] = query_2
            # important step to modify the isprime list also
            A_isprime[query_1 - 1] = isPrime(query_2)
        elif(query_type == 'A'):
            prime_count = 0
            for i in range(query_1 - 1, query_2):
                if(A_isprime[i]):
                    prime_count += 1
            print(prime_count)
        else:
            pass
