from typing import List, Tuple
import copy
class Solution:
    def dfs(self, initColor: int, vis: List[List[int]], delrow: List[int], delcol: List[int], image: List[List[int]], row: int, col: int, newColor: int) -> None:
        vis[row][col] = newColor
        n,m = len(image),len(image[0])
        for i in range(0,4):
            newr = delrow[i] + row
            newc = delcol[i] + col
            if(0<=newr<n and 0<=newc<m and image[newr][newc]==initColor and vis[newr][newc]!=newColor):
                vis[newr][newc] = newColor
                self.dfs(initColor, vis, delrow, delcol, image, newr, newc, newColor)


    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        initColor = image[sr][sc];
        vis = copy.deepcopy(image);
        delrow = [-1, 0, 1, 0]
        delcol = [0, -1, 0, 1]
        self.dfs(initColor, vis, delrow, delcol, image, sr, sc, newColor)
        return vis;

image = [
    [1,1,1],
    [1,1,0],
    [1,0,1]
]

sr = 1
sc = 1
newColor = 2

obj = Solution()
ans = obj.floodFill(image, sr, sc, newColor)

print("old image: ")
# prints out the same way
# for row in image:
#         print(' '.join(map(str, row)))
for i in range(len(image)):
    for j in range(len(image[i])):
        print(image[i][j], end=' ')
    print()

print("----------------")

print("new image")
# for row in ans:
#         print(' '.join(map(str, row)))
for i in range(len(ans)):
    for j in range(len(ans[i])):
        print(ans[i][j], end=' ')
    print()
