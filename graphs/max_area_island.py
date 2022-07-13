# https://leetcode.com/problems/max-area-of-island/

"""
You are given an m x n binary matrix grid. An island is a group of 1's
(representing land) connected 4-directionally (horizontal or vertical.) You
may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.

Example 1:
Input: grid = [
    [0,0,1,0,0,0,0,1,0,0,0,0,0],
    [0,0,0,0,0,0,0,1,1,1,0,0,0],
    [0,1,1,0,1,0,0,0,0,0,0,0,0],
    [0,1,0,0,1,1,0,0,1,0,1,0,0],
    [0,1,0,0,1,1,0,0,1,1,1,0,0],
    [0,0,0,0,0,0,0,0,0,0,1,0,0],
    [0,0,0,0,0,0,0,1,1,1,0,0,0],
    [0,0,0,0,0,0,0,1,1,0,0,0,0]
]
Output: 6
Explanation: The answer is not 11, because the island must be connected
4-directionally.

Example 2:
Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 50
    grid[i][j] is either 0 or 1.
"""


class Solution:
    def get_neighbors(self, row: int, col: int, m: int, n: int) -> int:
        neighbors = []
        for row_delta, col_delta in zip([-1, 1, 0, 0], [0, 0, -1, 1]):
            if (
                0 <= row + row_delta
                and row + row_delta <= m - 1
                and 0 <= col + col_delta
                and col + col_delta <= n - 1
            ):
                neighbors.append((row + row_delta, col + col_delta))

        return neighbors

    def maxAreaOfIsland(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        max_area = 0
        # empty grid
        if len(grid) == 0:
            return 0

        # tag visited nodes here
        visited = []
        for _ in range(m):
            visited.append([0] * n)

        # traverse the graph and keep max area of island
        node_stack = [(0, 0)]
        while len(node_stack) > 0:
            row, col = node_stack.pop()
            if visited[row][col]:
                continue
            if grid[row][col] == 1:
                curr_area = 0
                # found an island, start process of checking its neighbors
                island_stack = [(row, col)]
                while len(island_stack) > 0:
                    row, col = island_stack.pop()

                    if visited[row][col]:
                        # skip
                        continue
                    visited[row][col] = 1
                    if grid[row][col] == 0:
                        # no need to explore beyond this
                        # but add the neighbors to the node stack
                        for row_n, col_n in self.get_neighbors(row, col, m, n):
                            # valid neighbor, add to stack
                            if not visited[row_n][col_n]:
                                node_stack.append((row_n, col_n))
                        continue
                    # otherwise add neighbors since we found a 1
                    curr_area += 1
                    for row_n, col_n in self.get_neighbors(row, col, m, n):
                        # valid neighbor, add to stack
                        if not visited[row_n][col_n]:
                            island_stack.append((row_n, col_n))
                # update max area
                max_area = max(curr_area, max_area)
            else:
                visited[row][col] = 1
                # add neighbors for exploration
                for row_n, col_n in self.get_neighbors(row, col, m, n):
                    if not visited[row_n][col_n]:
                        node_stack.append((row_n, col_n))

        return max_area
