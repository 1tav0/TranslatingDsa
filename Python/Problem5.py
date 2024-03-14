from typing import List
class Solution:
    def dfs(self, node: int, parent: int, vis: List[int], adj: List[List[int]]) -> bool:
        vis[node] = 1
        for v in adj[node]:
            if not vis[v]:
                if self.dfs(v, node, vis, adj)==True:
                    return True
            elif v != parent:
                return True

        return False


    def isCycle(self, V: int, adj: List[List[int]]) -> bool:
        vis = [0] * V
        for i in range(V):
            if not vis[i]:
                if self.dfs(i, -1, vis, adj)==True:
                    return True

        return False

    def printGraph(self, adj: List[List[int]]):
        for i in range(len(adj)):
            print("Adjacency list of vertex", i, ": ", end="")
            for j in range(len(adj[i])):
                print(adj[i][j] ,"", end="")
            print()

adj = [
    [1], [0, 2, 4], [1, 3], [2, 4], [1, 3]
]

V = 5

obj = Solution()
ans = obj.isCycle(V, adj)
obj.printGraph(adj)
print("Is there a cycle in the graph: ", ans)
