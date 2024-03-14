from queue import Queue
from typing import List, Tuple
import copy

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n,m = len(grid), len(grid[0])
        if n==0:
            return 0
        q = Queue()
        vis = [[0] * m for _ in range(n)]
        orangesToRot = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2 and not vis[i][j]:
                    q.put(((i,j),0))
                    vis[i][j] = 2
                if grid[i][j] == 1:
                    orangesToRot += 1

        if orangesToRot == 0:
            return 0

        delrow = [-1, 0, 1, 0]
        delcol = [0, -1, 0, 1]
        rottedOranges = 0
        time = 0
        while not q.empty():
            (row, col), t = q.get()
            time = max(time, t)

            for i in range(4):
                newr = delrow[i] + row
                newc = delcol[i] + col
                if 0<=newr<n and 0<=newc<m and grid[newr][newc]==1 and not vis[newr][newc]:
                    vis[newr][newc] = 2
                    q.put(((newr,newc), t+1))
                    rottedOranges += 1


        if rottedOranges != orangesToRot:
            return -1

        return time

    def newGrid(self, grid: List[List[int]]) -> List[List[int]]:
        n,m = len(grid), len(grid[0])
        if n==0:
            return [[]]
        q = Queue()
        # vis = [grid[:] for row in grid] # Create a deep copy of the input grid
        vis = copy.deepcopy(grid)
        # print("vis before:", vis)
        orangesToRot = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    q.put(((i,j),0))
                if grid[i][j] == 1:
                    orangesToRot += 1

        if orangesToRot == 0:
            return vis

        delrow = [-1, 0, 1, 0]
        delcol = [0, -1, 0, 1]
        rottedOranges = 0
        time = 0
        while not q.empty():
            # print("Queue contents:", q.queue)
            (row, col), t = q.get()
            time = max(time, t)
            # print("row:", row, "col:", col, "t:", t)

            for i in range(4):
                newr = delrow[i] + row
                newc = delcol[i] + col
                # print("newr:", newr, "newc:", newc)
                if 0<=newr<n and 0<=newc<m and grid[newr][newc]==1 and vis[newr][newc]==1:
                    vis[newr][newc] = 2
                    q.put(((newr,newc), t+1))
                    rottedOranges += 1


        if rottedOranges != orangesToRot:
            return [[]]

        return vis


if __name__ == "__main__":
    grid = [[0, 1, 2], [0, 1, 2], [2, 1, 1]]

    print("original grid: ")
    for row in grid:
        print(" ".join(map(str, row)))

    print("---------------------")
    obj = Solution()
    ans = obj.orangesRotting(grid)
    newGrid = obj.newGrid(grid);

    print("new grid: ")
    for row in newGrid:
        print(" ".join(map(str, row)))

    print("time to rot all oranges: ", ans)
