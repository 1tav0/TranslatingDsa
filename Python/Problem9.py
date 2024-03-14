from collections import deque
from typing import List, Tuple
class Solution:
  def dfs(self, row: int, col: int, vis: List[int], grid: List[List[int]], vec: List[int], row1: int, col1: int) -> None:
    vis[row][col] = 1;
    vec.append((row-row1, col-col1))
    n,m = len(grid), len(grid[0])
    delrow = [-1, 0, 1, 0]
    delcol = [0, -1, 0, 1]

    for i in range(4):
        newr = delrow[i] + row
        newc = delcol[i] + col
        if 0<=newr<n and 0<=newc<m and grid[newr][newc]==1 and not vis[newr][newc]:
            self.dfs(newr, newc, vis, grid, vec, row1, col1)



  def countDistinctIslands(self, grid: List[List[int]]) -> int:
      n,m = len(grid),len(grid[0])
      vis = [[0]*m for _ in range(n)]
      st = set()
      for i in range(n):
          for j in range(m):
              if grid[i][j]==1 and not vis[i][j]:
                  vec = []
                  self.dfs(i, j, vis, grid, vec, i, j)
                  st.add(tuple(vec))
      return len(st)


if __name__ == "__main__":
    grid = [
        [1, 1, 0, 1, 1],
        [1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1],
        [1, 1, 0, 1, 1]
    ]
    print("grid: ")
    for row in grid:
        print(" ".join(map(str, row)))
    obj = Solution()
    ans = obj.countDistinctIslands(grid)
    print("The number of distinct islands is: ", ans)
