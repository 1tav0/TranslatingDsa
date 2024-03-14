from typing import List, Tuple
class Problem2:

    def bfs(self, i: int, j: int, vis: List[List[int]], grid: List[List[int]]) -> None:
        n, m = len(grid), len(grid[0])
        vis[i][j] = 1
        queue = [(i,j)]

        while queue:
            r,c = queue.pop(0);

            for dr in range(-1, 2):
                for dc in range(-1, 2):
                    newr = r + dr
                    newc = c + dc
                    if(0<=newr<n and 0<=newc<m and grid[newr][newc]=="1" and not vis[newr][newc]):
                        vis[newr][newc] = 1
                        queue.append((newr, newc))


    def numIslands(self, grid: List[List[str]]) -> int:
            n, m = len(grid), len(grid[0])
            vis = [[0] * m for _ in range(n)]
            cnt = 0
            for i in range(n):
                for j in range(m):
                    if grid[i][j]=="1" and not vis[i][j]:
                        cnt += 1
                        self.bfs(i, j, vis, grid)
            return cnt

grid = [
    ['0', '1', '1', '1', '0', '0', '0'],
    ['0', '0', '1', '1', '0', '1', '0']
]

obj = Problem2()
result = obj.numIslands(grid)
print("number of islands: ", result)
