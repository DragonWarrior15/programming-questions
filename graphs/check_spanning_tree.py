"""
Given a graph with N nodes and M edges, some edges are selected to form a tree
check if that tree is a spanning tree for the graph
T
N M
M edges
single line with edge indices for tree
"""

from sys import stdin

T = int(stdin.readline().strip())
data = stdin.readlines()
i = 0
start_test_case = True
start_graph = False
while 1:
    if start_test_case:
        N, M = list(map(int, data[i].strip().split(" ")))
        start_graph = True
        start_test_case = False
        i += 1
        curr_graph = []
        continue

    if start_graph:
        curr_graph.append(list(map(int, data[i].strip().split(" "))))
        i += 1
        if len(curr_graph) == M:
            start_graph = False
            start_test_case = False
        continue

    # else we are reading the list of edges in spanning tree
    spanning_tree = list(map(int, data[i].strip().split(" ")))
    i += 1
    start_graph = False
    start_test_case = True

    # print(curr_graph)
    node_set = set()
    for edge in spanning_tree:
        # print(edge, node_set)
        node_set = node_set | set(curr_graph[edge - 1])

    if len(node_set) == N:
        # all nodes covered
        print("YES")
    else:
        print("NO")

    if i == len(data):
        break
