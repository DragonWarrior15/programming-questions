# https://leetcode.com/problems/pacific-atlantic-water-flow/

"""
There is an m x n rectangular island that borders both the Pacific Ocean and
Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and
the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n
integer matrix heights where heights[r][c] represents the height above sea
level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring
cells directly north, south, east, and west if the neighboring cell's height
is less than or equal to the current cell's height. Water can flow from any
cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes
that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic
oceans.

Example 1:
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

Example 2:
Input: heights = [[2,1],[1,2]]
Output: [[0,0],[0,1],[1,0],[1,1]]

Constraints:
    m == heights.length
    n == heights[r].length
    1 <= m, n <= 200
    0 <= heights[r][c] <= 10^5
"""


class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        """
        Consider the solution for finding the nodes which can flow into
        pacific, all the nodes at top edge and left edge can always flow
        into pacific irrespective of height, now any node inside the graph
        that is connected to the top or left edge by a path such that the
        height is decreasing as we go from node to top or left edge, that
        node is connected to pacific
        in essence, we need to start travelling from top or left edge and
        travel along all nodes that have equal or greater height
        then we are simply doing a conditional dfs

        same approach can be followed for connection to atlantic

        if we go about working from inside towards the edge then the program
        can get stuck in loop, consider a node (node_1) whose connection we
        want to find and we check its neighbor (node_2) whose connection is
        not known, node_2 will also check its neighbors in the next step and
        will find that node_1's connection is not known and will try to find
        it first, this way we will keep alternating between node_1 and node_2
        """
        m, n = len(heights), len(heights[0])

        visited_pacific, visited_atlantic = set(), set()

        # dfs function is just meant to traverse the graph and collect nodes
        # into the set along the way, we dont need it to return anything
        def dfs(row, col, visit_set, prev_height):
            # check if node is valid and not visited
            if row < 0 or col < 0 or row == m or col == n:
                return

            # if visited no need to visit again
            if (row, col) in visit_set:
                return

            # height check
            if heights[row][col] < prev_height:
                # water cannot flow, stop
                return

            # else a node that needs to be added to our set
            visit_set.add((row, col))
            # now try to check the neighbors, prev_height is current nodes
            # height
            dfs(row + 1, col, visit_set, heights[row][col])
            dfs(row - 1, col, visit_set, heights[row][col])
            dfs(row, col + 1, visit_set, heights[row][col])
            dfs(row, col - 1, visit_set, heights[row][col])

        # top and left edge are connected to pacific, start dfs from there
        for i in range(n):
            # equal heights allow flow of water
            if (0, i) not in visited_pacific:
                dfs(0, i, visited_pacific, heights[0][i])

        for i in range(m):
            if (i, 0) not in visited_pacific:
                dfs(i, 0, visited_pacific, heights[i][0])

        # bottom and right edge are connected to atlantic, start dfs from there
        for i in range(n):
            # equal heights allow flow of water
            if (m - 1, i) not in visited_atlantic:
                dfs(m - 1, i, visited_atlantic, heights[m - 1][i])

        for i in range(m):
            if (i, n - 1) not in visited_atlantic:
                dfs(i, n - 1, visited_atlantic, heights[i][n - 1])

        ans = []
        # now iterate to check which nodes are in both sets
        for i in range(m):
            for j in range(n):
                if (i, j) in visited_pacific and (i, j) in visited_atlantic:
                    ans.append([i, j])

        return ans
