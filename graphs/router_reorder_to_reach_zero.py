"""
https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

There are n cities numbered from 0 to n - 1 and n - 1 roads such that there
is only one way to travel between two different cities (this network form a
tree). Last year, The ministry of transport decided to orient the roads in
one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi]
represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people
want to travel to this city.

Your task consists of reorienting some roads such that each city can visit
the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.

Example 1:
Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node
can reach the node 0 (capital).

Example 2:
Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node
can reach the node 0 (capital).

Example 3:
Input: n = 3, connections = [[1,0],[2,0]]
Output: 0

Constraints:
    2 <= n <= 5 * 10^4
    connections.length == n - 1
    connections[i].length == 2
    0 <= ai, bi <= n - 1
    ai != bi
"""


class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        # check all the leaf nodes and get the connected to city 0
        # this will ensure any other city is also connected to city 0

        # store the bidirectional connections as a dict
        graph = {}
        # also maintain a dict to keep track of directions
        directions = {}

        for connection in connections:
            try:
                graph[connection[0]].append(connection[1])
            except KeyError:
                graph[connection[0]] = [connection[1]]

            try:
                graph[connection[1]].append(connection[0])
            except KeyError:
                graph[connection[1]] = [connection[0]]

            directions[(connection[0], connection[1])] = 1

        # a list to keep track of cities connected to 0
        connected = [0] * n
        # 0th city is always connected to 0
        connected[0] = 1

        # variable to track the changes
        count_changes = 0

        # build a stack and start a depth traversal
        stack = [0]

        while stack:
            curr_elem = stack.pop()
            connected[curr_elem] = 1

            # check the neighbors of curr elem
            # and connect them to curr elem if needed
            for k in graph[curr_elem]:
                if not connected[k]:
                    # check if directly connect as of now
                    if (k, curr_elem) in directions:
                        # we are good
                        connected[k] = 1
                    else:
                        # we need to update the edge
                        if (curr_elem, k) in directions:
                            directions[(k, curr_elem)] = 1
                            count_changes += 1
                            del directions[(curr_elem, k)]
                        else:
                            # not possible
                            pass

                    # append to stack for further processing
                    stack.append(k)

        return count_changes
