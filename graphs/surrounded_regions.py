# https://leetcode.com/problems/surrounded-regions/

"""
Given an m x n matrix board containing 'X' and 'O', capture all regions that
are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example 1:
Input: board = [["X","X","X","X"],["X","O","O","X"],
                ["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],
         ["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.

Example 2:
Input: board = [["X"]]
Output: [["X"]]

Constraints:
    m == board.length
    n == board[i].length
    1 <= m, n <= 200
    board[i][j] is 'X' or 'O'.
"""


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        """
        This can be seen as a traversal problem. Starting from the edges,
        any Os that are connected to an O on the edge, we need to leave
        untouched. Hence, we first do a pass to find Os that are connected
        to the edge, mark them A, then make all the remaining positions
        on the board X and in the same pass make the A to O
        """
        m, n = len(board), len(board[0])

        def dfs(row, col):
            if not (0 <= row and row <= m - 1 and 0 <= col and col <= n - 1):
                return
            if board[row][col] == "X" or board[row][col] == "A":
                return

            # found an O connected to edge
            board[row][col] = "A"
            # explore neighbors
            dfs(row - 1, col)
            dfs(row + 1, col)
            dfs(row, col - 1)
            dfs(row, col + 1)

        # start from all of the edges
        for i in range(m):
            if board[i][0] == "O":
                dfs(i, 0)

            if board[i][n - 1] == "O":
                dfs(i, n - 1)

        for i in range(n):
            if board[0][i] == "O":
                dfs(0, i)

            if board[m - 1][i] == "O":
                dfs(m - 1, i)

        # now modify the board as per requirements
        for i in range(m):
            for j in range(n):
                if board[i][j] == "O":
                    # these are Os that are interal to the board and not
                    # connected with the edges
                    board[i][j] = "X"
                if board[i][j] == "A":
                    # these are original positions that were Os connected
                    # to one of the edges
                    board[i][j] = "O"
                # X can remain untouched
