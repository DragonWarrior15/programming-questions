# https://leetcode.com/problems/number-of-islands

"""
Given an m x n 2D binary grid grid which represents a map of '1's (land) and
'0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands
horizontally or vertically. You may assume all four edges of the grid are all
surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 300
    grid[i][j] is '0' or '1'.
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

    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        count_islands = 0
        # empty grid
        if len(grid) == 0:
            return 0

        # tag visited nodes here
        visited = []
        for _ in range(m):
            visited.append([0] * n)

        # traverse the graph and keep count of islands
        node_stack = [(0, 0)]
        while len(node_stack) > 0:
            row, col = node_stack.pop()
            if visited[row][col]:
                continue
            if grid[row][col] == "1":
                count_islands += 1
                # found an island, start process of checking its neighbors
                island_stack = [(row, col)]
                while len(island_stack) > 0:
                    row, col = island_stack.pop()

                    if visited[row][col]:
                        # skip
                        continue
                    visited[row][col] = 1
                    if grid[row][col] == "0":
                        # no need to explore beyond this
                        # but add the neighbors to the node stack
                        for row_n, col_n in self.get_neighbors(row, col, m, n):
                            # valid neighbor, add to stack
                            if not visited[row_n][col_n]:
                                node_stack.append((row_n, col_n))
                        continue
                    # otherwise add neighbors
                    for row_n, col_n in self.get_neighbors(row, col, m, n):
                        # valid neighbor, add to stack
                        if not visited[row_n][col_n]:
                            island_stack.append((row_n, col_n))
            else:
                visited[row][col] = 1
                # add neighbors for exploration
                for row_n, col_n in self.get_neighbors(row, col, m, n):
                    if not visited[row_n][col_n]:
                        node_stack.append((row_n, col_n))

        return count_islands
