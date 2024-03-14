class Solution:
    def dfs(self, node, adjList, vis):
        vis[node] = 1
        for it in adjList[node]:
            if not vis[it]:
                self.dfs(it, adjList, vis)

    def numProvinces(self, adj, V):
        adjList = [[] for _ in range(V)]
        for i in range(V):
            for j in range(V):
                if adj[i][j] == 1:
                    adjList[i].append(j)
                    adjList[j].append(i)

        vis = [0] * V
        cnt = 0
        
        for i in range(V):
            if not vis[i]:
                self.dfs(i, adjList, vis)
                cnt += 1

        return cnt;
matrix = [
    [1,0,1],
    [0,1,0],
    [1,0,1],
]
V = len(matrix)
obj = Solution()
ans = obj.numProvinces(matrix, V)
print("Number of provinces:", ans)
