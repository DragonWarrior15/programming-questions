# https://leetcode.com/problems/rotting-oranges/

"""
You are given an m x n grid where each cell can have one of three values:
    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten
orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a
fresh orange. If this is impossible, return -1.

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never
rotten, because rotting only happens 4-directionally.

Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer
is just 0.

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 10
    grid[i][j] is 0, 1, or 2.
"""


# solution 1
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        """
        Think of this as finding the depth of the tree that starts at rotten
        orange and is connected through fresh oranges; the maximum dept of
        any such tree is the minimum

        Thus, for each fresh orange, we need its minimum distance from
        any rotten orange

        if the min distance does not exist, that fresh orange is not in
        contact with any rotten orange, return -1
        """
        """
        an even more optimum version of solution is to treat this as a
        simulation problem, iterate through the entire grid and put the
        rotten oranges in a queue (and keep a counter of fresh oranges)
        now, for every orange in original queue, check its neighbors, if
        they are fresh, make them rotten and add to the same queue (but
        remember we will not pop this in the current iteration) this way
        we have stepped one step in time
        we continue while the queue exists and fresh oranges > 0
        this way we dont need to worry about whether the same fresh orange
        is connected to multiple rotten oranges, it will always become
        rotten because of the closer rotten orange
        """
        # 101 chosen bec max grid size is 10*10 in the problem
        infinite_distance = 101
        m, n = len(grid), len(grid[0])
        # a dictionary to maintain the minimum distance
        distances = {}

        def dfs(start_row, start_col):
            # start row and start col is always a rotten orange
            queue = [(start_row, start_col, -1)]

            visited = set()
            while queue:
                row, col, prev_distance = queue.pop(0)

                visited.add((row, col))

                if grid[row][col] == 1:
                    # fresh orange, update distance
                    try:
                        # same fresh orange can be connected to multiple rotten
                        # oranges
                        distances[(row, col)] = min(
                            distances[(row, col)], prev_distance + 1
                        )
                    except KeyError:
                        distances[(row, col)] = prev_distance + 1

                # add neighbors to the queue
                for row_delta, col_delta in zip([-1, 1, 0, 0], [0, 0, -1, 1]):
                    if (
                        0 <= row + row_delta
                        and row + row_delta <= m - 1
                        and 0 <= col + col_delta
                        and col + col_delta <= n - 1
                    ):
                        if (
                            grid[row + row_delta][col + col_delta] == 1
                            and (row + row_delta, col + col_delta) not in visited
                        ):
                            queue.append(
                                (
                                    row + row_delta,
                                    col + col_delta,
                                    prev_distance + 1,
                                )
                            )

        # start the dfs from any rotten orange
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    if (i, j) not in distances:
                        # some fresh oranges may not be connected to any
                        # rotten one
                        distances[(i, j)] = infinite_distance
                if grid[i][j] == 2:
                    # reset visited at start of every iteration
                    dfs(i, j)

        # now iterate through the min distances of all fresh oranges
        max_distance = 0
        for k in distances:
            if distances[k] == infinite_distance:
                # not connected fresh orange
                return -1
            max_distance = max(max_distance, distances[k])

        return max_distance


# solution 2
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        # immediate idea is to do a breadth first traversal
        # starting from any rotten orange
        # keep a set of rotten orange at every round of traversal
        # we only traverse one neighbor at a time

        # queue of rotten oranges that can affect a fresh orange
        rotten_oranges_active = []

        # a dict of fresh oranges to check if we remain with
        # any fresh orange at the end
        fresh_oranges = {}

        # visited nodes
        visited = {}

        # time elapsed counter
        time_elapsed = 0

        def is_in_grid(row, col):
            if 0 <= row and row < m and 0 <= col and col < n:
                return True
            return False

        def is_fresh_orange(row, col):
            if grid[row][col] == 1:
                return True
            return False

        def is_rotten_orange(row, col):
            if grid[row][col] == 2:
                return True
            return False

        for row in range(m):
            for col in range(n):
                if is_rotten_orange(row, col):
                    rotten_oranges_active.append((row, col, time_elapsed))
                    visited[(row, col)] = 1
                if is_fresh_orange(row, col):
                    fresh_oranges[(row, col)] = 1

        while rotten_oranges_active:
            # go through the queue of rotten oranges
            curr_rotten_orange = rotten_oranges_active.pop(0)

            time_elapsed = max(time_elapsed, curr_rotten_orange[2])

            # dfs around it
            for row_delta, col_delta in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
                row, col = (
                    curr_rotten_orange[0] + row_delta,
                    curr_rotten_orange[1] + col_delta,
                )
                if is_in_grid(row, col):
                    if (row, col) not in visited:
                        if is_fresh_orange(row, col):
                            rotten_oranges_active.append(
                                (row, col, curr_rotten_orange[2] + 1)
                            )
                            # update the grid and dictionaries
                            del fresh_oranges[(row, col)]
                            visited[(row, col)] = 1
                            grid[row][col] = 2

        # if fresh oranges remain, return -1
        if fresh_oranges:
            return -1

        return time_elapsed
