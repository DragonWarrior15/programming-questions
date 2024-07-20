"""
https://leetcode.com/problems/number-of-provinces/description/

There are n cities. Some of them are connected, while some are not. If city a
is connected directly with city b, and city b is connected directly with city c,
then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other
cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith
city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

Constraints:
    1 <= n <= 200
    n == isConnected.length
    n == isConnected[i].length
    isConnected[i][j] is 1 or 0.
    isConnected[i][i] == 1
    isConnected[i][j] == isConnected[j][i]
"""


class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        # make a an array that holds whether a province has been visited
        n = len(isConnected)
        visited = [0] * n
        visited_idx = 0

        # count of provinces
        count_provinces = 0

        while visited_idx < n:
            # a stack for traversal of a connected province
            stack = []
            # check the city not visited yet
            if not visited[visited_idx]:
                stack = [visited_idx]
                # one province explored, increment count by 1
                count_provinces += 1

            visited_idx += 1

            while stack:
                # check for all neighbors of current element of stack
                curr_idx = stack.pop()
                # once processed in stack, this is visited
                visited[curr_idx] = 1
                for idx in range(n):
                    if (
                        idx != curr_idx
                        and isConnected[curr_idx][idx]
                        and not visited[idx]
                    ):
                        # every city is connected to itself
                        # add to graph for exploration
                        stack.append(idx)

        return count_provinces
