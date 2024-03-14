from collections import deque
from typing import List, Tuple
import copy
class Solution:
    def numberOfEnclaves(self, grid: List[List[int]]) -> int:
        n,m = len(grid), len(grid[0])
        vis = [[0]*m for _ in range(n)]
        q = deque()
        for i in range(n):
            for j in range(m):
                if i==0 or i==n-1 or j==0 or j==m-1:
                    if grid[i][j]==1:
                        q.append([i,j])
                        vis[i][j] = 1

        delrow = [-1, 0, 1, 0]
        delcol = [0, -1, 0, 1]
        while len(q):
            front = q.popleft()
            row = front[0]
            col = front[1]

            for i in range(4):
                newr = delrow[i] + row
                newc = delcol[i] + col
                if 0<=newr<n and 0<=newc<m and grid[newr][newc]==1 and not vis[newr][newc]:
                    vis[newr][newc] = 1
                    q.append([newr, newc])

        cnt = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j]==1 and not vis[i][j]:
                    cnt += 1

        return cnt

    def newGrid(self, grid: List[List[int]]) -> List[List[int]]:
        n,m = len(grid), len(grid[0])
        vis = [[0]*m for _ in range(n)]
        ans = copy.deepcopy(grid)
        q = deque()
        for i in range(n):
            for j in range(m):
                if i==0 or i==n-1 or j==0 or j==m-1:
                    if grid[i][j]==1:
                        q.append([i,j])
                        vis[i][j] = 1
                        ans[i][j] = 0

        delrow = [-1, 0, 1, 0]
        delcol = [0, -1, 0, 1]
        while len(q):
            front = q.popleft()
            row = front[0]
            col = front[1]

            for i in range(4):
                newr = delrow[i] + row
                newc = delcol[i] + col
                if 0<=newr<n and 0<=newc<m and grid[newr][newc]==1 and not vis[newr][newc]:
                    vis[newr][newc] = 1
                    q.append([newr, newc])
                    ans[newr][newc] = 0

        return ans

    def printGraph(self, grid: List[List[int]]) -> None:
        for row in grid:
            print(" ".join(map(str, row)))

if __name__ == "__main__":
    grid = [
        [0, 0, 0, 0],
        [1, 0, 1, 0],
        [0, 1, 1, 0],
        [0, 0, 0, 0]
    ]
    obj = Solution()
    print("old grid: ")
    obj.printGraph(grid)
    print("new grid: ")
    ans = obj.newGrid(grid)
    obj.printGraph(ans)
    cnt = obj.numberOfEnclaves(grid)
    print("The number of enclaves in the new grid: ", cnt)
