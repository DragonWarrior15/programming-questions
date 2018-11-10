'''
A big international retailer is setting up shop in India and plans to open stores in N towns (3 ≤ N ≤ 1000), denoted by 1, 2, . . . , N. 
There are direct routes connecting M pairs among these towns. The company decides to build warehouses to ensure that for any town X, 
there will be a warehouse located either in X or in an immediately neighboring town of X.

Write a program to find the minimum number of warehouses the company has to build.

[Input]:
Input will be given in the following format 
N M
S1 E1 (Start Pt and End Pt of a direct route)
S2 E2
S3 E3
....
SM EM
Each route is bidirectional
No combination of towns will be repeated.

[Output]:
Output should be in a file in the following format
Wx - Minimum # of warehouses

*Problem provided by JDA

SAMPLE INPUT 
10 7
1 2
2 4
2 5
3 6
8 6
9 7
10 7
'''

'''
solution idea is simple, start with the node having maximum connections, and
place warehouse on that node, remove all the connected nodes and this selected from the graph
and rerun the whole process on the remaining part of the graph
'''

from sys import stdin

data = stdin.read().strip().split('\n')

N, M = list(map(int, data[0].split(' ')))

# stores for every node, what are the set of nodes connected to it
connections_dict = {}
# the set which will keep shrinking as more and more warehouses are added
connections_set = set(list(range(1, N + 1)))

for i in range(1, len(data)):
    start, end = list(map(int, data[i].split(' ')))
    try:
        connections_dict[start] |= set([end])
    except KeyError:
        connections_dict[start] = set([end])
    try:
        connections_dict[end] |= set([start])
    except KeyError:
        connections_dict[end] = set([start])

warehouse_count = 0
while(len(connections_set) > 0):
    # get the node with max connections
    node_connections_size = [[i, len(connections_dict[i])] for i in connections_set]
    node_connections_size = sorted(node_connections_size, key = lambda x: x[1])
    node_max_connections = node_connections_size[-1][0]
    # define the new set of nodes = current set - all the nodes connected to the max node
    connections_set = set([i for i in connections_set if i not in connections_dict[node_max_connections]])
    connections_set -= set([node_max_connections])
    warehouse_count += 1

print(warehouse_count)

