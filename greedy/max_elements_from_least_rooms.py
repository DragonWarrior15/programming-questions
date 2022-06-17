"""
Milly loves chocolates very much. She is at the land of chocolates. This land has N rooms such that there are some chocolates of different brands in every room. It is possible that there can be multiple chocolates of same brand in a particular room. Now she is in a dilemma that whether she can eat at least K distinct branded chocolates at least once. Your task is to print the minimum number of rooms she must visit to eat at least those K distinct brands at least once.

Note : Once she enters a particular room, she will eat all of the chocolates available in that room.

Input
First line of the input will contain a integer T (number of test cases).
Then for every test case there will be one line containing the values of N (denoting the number of rooms) and K separated by a space.
Now each of the next N lines will first have a value P then P space separated strings denoting the names of the brands.
Output
For every test case, print the required answer and if it is not possible to eat those K distinct chocolates then print -1.
Constraints
1 ≤ T ≤ 3
1 ≤ N ≤ 16
1 ≤ K ≤ 40
1 ≤ P ≤ 10
1 ≤ Length of the strings ≤ 10

SAMPLE INPUT 
1
3 2
1 KITKAT
2 FIVESTAR KITKAT
2 KITKAT PERK

SAMPLE OUTPUT 
1
"""

from sys import stdin

T = int(stdin.readline().strip())
data = stdin.readlines()

data_index = 0
N_start = True
data_start = False

while 1:
    if N_start:
        # get values of N and K
        N, K = list(map(int, data[data_index].split(" ")))
        N_start = False
        data_start = True
        data_index += 1
        brand_data = []
        continue

    if data_start:
        brand_data.append(data[data_index].split(" ")[1:])
        data_index += 1
        if len(brand_data) == N:
            # all rooms data entered
            N_start = False
            data_start = False
        continue

    # solve the problem
    # start with the room with the highest no of distinct chocolates
    # then recursively add rooms that add more distinct chocolates
    k = 0
    room_ind = [0] * N
    all_chocolates_set = set()
    while k < K and sum(room_ind) < N:
        max_chocolates = 0
        max_chocolates_room = -1
        for i in range(N):
            if room_ind[i] == 0:
                # room not picked not yet
                if len(all_chocolates_set | set(data[i])) > max_chocolates:
                    max_chocolates = len(all_chocolates_set | set(data[i]))
                    max_chocolates_room = i

        all_chocolates_set = all_chocolates_set | set(data[max_chocolates_room])
        k = len(all_chocolates_set)
        room_ind[max_chocolates_room] = 1

    if k == K:
        print(sum(room_ind))
    else:
        print("-1")

    N_start = True
    data_start = False

    if data_index == len(data):
        break
