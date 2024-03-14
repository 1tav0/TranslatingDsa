#include <iostream>
#include <vector>
using namespace std;
// Detect a cycle in a undirected graph
class Solution{
public:
  bool dfs(int node, int parent, vector<int> &vis, vector<int> adj[]){
    vis[node] = 1;

    for(auto it: adj[node]){
      if(!vis[it]){
        if(dfs(it, node, vis, adj)==true) return true;
      }else if(it != parent){
        return true;
      }
    }
    return false;
  }

  bool isCycle(int V, vector<int> adj[]){
    vector<int> vis(V, 0);
    for(int i=0; i<V; i++){
        if(!vis[i]){
          if(dfs(i, -1, vis, adj)==true) return true;
        }
    }
    return false;
  }
};

int main(){
  int V = 5;
  vector<int> adj[V] = {{}, {2}, {1, 3}, {2}};
  Solution obj;
  bool ans = obj.isCycle(V, adj);
  cout << "Is there a cycle in the graph: " << ans;
}
