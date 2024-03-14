from typing import List

class Solution:
    def dfs(self, row: int, col: int, vis: List[List[int]], board: List[List[chr]], delrow: List[int], delcol: List[int]) -> None:
        vis[row][col] = 1
        n, m = len(board), len(board[0])
        for i in range(4):
            newr = delrow[i] + row
            newc = delcol[i] + col
            if 0 <= newr < n and 0 <= newc < m and board[newr][newc] == 'O' and not vis[newr][newc]:
                self.dfs(newr, newc, vis, board, delrow, delcol)

    def solve(self, board: List[List[chr]]) -> List[List[chr]]:
        n, m = len(board), len(board[0])
        vis = [[0] * m for _ in range(n)]
        delrow = [-1, 0, 1, 0]
        delcol = [0, -1, 0, 1]
        for i in range(n):
            # left col
            if board[i][0] == 'O' and not vis[i][0]:
                self.dfs(i, 0, vis, board, delrow, delcol)
            # right col
            if board[i][m - 1] == 'O' and not vis[i][m - 1]:
                self.dfs(i, m - 1, vis, board, delrow, delcol)

        for j in range(m):
            # top row
            if board[0][j] == 'O' and not vis[0][j]:
                self.dfs(0, j, vis, board, delrow, delcol)
            # bottom row
            if board[n - 1][j] == 'O' and not vis[n - 1][j]:
                self.dfs(n-1, j, vis, board, delrow, delcol)

        for i in range(n):
            for j in range(m):
                if board[i][j] == 'O' and not vis[i][j]:
                    board[i][j] = 'X'

        return board

    def printGraph(self, board: List[List[int]]) -> None:
        for row in board:
            print(" ".join(map(str, row)))


if __name__ == "__main__":
    board = [
        ["X", "X", "X", "X"],
        ["X", "O", "O", "X"],
        ["X", "X", "O", "X"],
        ["X", "O", "X", "X"]
    ]
    print("old grid: ")
    for row in board:
        print(" ".join(map(str, row)))
    obj = Solution()
    ans = obj.solve(board)
    print("new grid: ")
    obj.printGraph(ans)
