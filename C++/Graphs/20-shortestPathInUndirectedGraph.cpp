#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Shortest path in Undirected Graph having unit distance
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(N, 1e9);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: adj[node]){
                if(dist[node] + 1 < dist[it]){
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }

        vector<int> ans(N, -1);
        for(int i=0; i<N; i++){
            if(dist[i]!=1e9){
                ans[i] = dist[i];
            }
        }
        return ans;
    }
};

ostream& operator<<(ostream& os, vector<int> ans){
  for(auto it: ans){
    os << it << " ";
  }
  return os;
}

ostream& operator<<(ostream& os, vector<vector<int>>& edges){
  int n = edges.size();
  int m = edges[0].size();
  for(int i=0; i<n; i++){
    os << "The vertices of node " << i << ": ";
    for(int j=0; j<m; j++){
      os << edges[i][j] << " ";
    }
    os << endl;
  }
  return os;
}

// int main() {
//     int t;
//     cout << "enter the number of test cases: ";
//     cin >> t;
//     while (t--) {
//         int n, m;
//         cout << "enter number of nodes n: ";
//         cin >> n;
//         cout << "enter the number of edges: ";
//         cin >> m;
//         vector<vector<int>> edges;
//
//         for (int i = 0; i < m; ++i) {
//             vector<int> temp;
//             for(int j=0; j<2; ++j){
//                 int x;
//                 cout << "vertices pair: ";
//                 cin>>x;
//                 temp.push_back(x);
//             }
//             edges.push_back(temp);
//         }
//
//         int src;
//         cout << "enter the src: ";
//         cin >> src;
//
//         Solution obj;
//
//         vector<int> res = obj.shortestPath(edges, n, m, src);
//
//         for (auto x : res){
//             cout<<x<<" ";
//         }
//         cout << "\n";
//     }
// }

int main(){
  vector<vector<int>> edges = {
    {0, 1},
    {0, 3},
    {3, 4},
    {4, 5},
    {5, 6},
    {1, 2},
    {2, 6},
    {6, 7},
    {7, 8},
    {6, 8}
  };
  int N = 9;
  int M = 10;
  int src = 0;
  Solution obj;
  vector<int> ans = obj.shortestPath(edges, N, M, src);
  cout << "The graph: " << edges << endl;
  cout << "The shortest path from src to all the vertex: " << ans << endl;
  return 0;
}
