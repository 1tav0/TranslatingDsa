from queue import Queue
from collections import deque
from typing import List, Tuple

class Solution:
    def printGraph(self, grid: List[List[int]]):
        for row in grid:
            print(" ".join(map(str, row)))

    # Function to find distance of nearest 1 in the grid for each cell.
    def nearestCell(self, grid):
        n, m = len(grid), len(grid[0])
        vis = [[0] * m for _ in range(n)]
        ans = [[0] * m for _ in range(n)]
        # queue to store the cell indexes which have grid value 1.
        q = deque()
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    q.append([i, j, 0])
                    vis[i][j] = 1
        delrow = [-1, 0, 1, 0]
        delcol = [0, -1, 0, 1]
        while len(q):
            front = q.popleft()
            row = front[0]
            col = front[1]
            steps = front[2]

            ans[row][col] = steps
            for i in range(4):
                newr = delrow[i] + row
                newc = delcol[i] + col
                if 0 <= newr < n and 0 <= newc < m and not vis[newr][newc]:
                    vis[newr][newc] = 1
                    q.append([newr, newc, steps + 1])
        return ans


grid = [
    [1,0,1],[1,1,0],[1,0,0]
]
print("old grid: ")
obj = Solution();
ans = obj.nearestCell(grid)
obj.printGraph(grid)
print("new grid: ")
obj.printGraph(ans)


        # TLE in GFG
  # def nearestCell(self, grid: List[List[int]]) -> List[List[int]]:
  #     n,m = len(grid), len(grid[0])
  #     vis = [[0] * m for _ in range(n)]
  #     ans = [[0] * m for _ in range(n)]
  #     q = Queue()
  #     for i in range(n):
  #         for j in range(m):
  #             if grid[i][j] == 1:
  #                 q.put(((i,j),0))
  #                 vis[i][j] = 1
  #     delrow = [-1, 0, 1, 0]
  #     delcol = [0, -1, 0, 1]
  #     while not q.empty():
  #         (row, col), steps = q.get()
  #
  #         ans[row][col] = steps
  #         for i in range(4):
  #             newr = delrow[i] + row
  #             newc = delcol[i] + col
  #             if 0<=newr<n and 0<=newc<m and not vis[newr][newc]:
  #                 vis[newr][newc] = 1
  #                 q.put(((newr,newc),steps+1))
  #
  #     return ans

# TLE
# def nearest(self, grid):
# 		  n,m = len(grid), len(grid[0])
#           vis = [[0] * m for _ in range(n)]
#           ans = [[0] * m for _ in range(n)]
#           q = []
#           for i in range(n):
#               for j in range(m):
#                   if grid[i][j] == 1:
#                       q.append(((i,j),0))
#                       vis[i][j] = 1
#           delrow = [-1, 0, 1, 0]
#           delcol = [0, -1, 0, 1]
#           while q:
#               (row, col), steps = q.pop(0)
#
#               ans[row][col] = steps
#               for i in range(4):
#                   newr = delrow[i] + row
#                   newc = delcol[i] + col
#                   if 0<=newr<n and 0<=newc<m and not vis[newr][newc]:
#                       vis[newr][newc] = 1
#                       q.append(((newr,newc),steps+1))
#
#           return ans
