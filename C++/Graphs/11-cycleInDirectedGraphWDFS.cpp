#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in a directed graph.

    bool dfs(int node, vector<int> &samePath, vector<int> &vis, vector<int> adj[]){
        vis[node] = 1;
        samePath[node] = 1;

        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it, samePath, vis, adj) == true){
                    return true;
                }
            }else if(samePath[it]){
                return true;
            }
        }

        samePath[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> samePath(V);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, samePath, vis, adj)==true){
                    return true;
                }
            }
        }
        return false;
    }

/****Detect A cycle using BFS topo ****/

    bool isCyclic2(int V, vector<int> adj[]) {
       vector<int> inDegrees(V);
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                inDegrees[it]++;
            }
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(inDegrees[i]==0){
                q.push(i);
            }
        }

        vector<int> topo;
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            cnt++;
            for(auto it: adj[node]){
                inDegrees[it]--;
                if(inDegrees[it]==0){
                    q.push(it);
                }
            }
        }

        if(cnt == V) return false;

        return true;
    }
};

int main(){
  int V = 3;
  vector<int> adj[V+1];
  adj[0].push_back(1);
  adj[1].push_back(2);
  adj[2].push_back(3);
  adj[3].push_back(3);
  // adj[0].push_back(1);
  // adj[1].push_back(2);

  cout << "Graph:" << endl;

  for(int i=0; i<=V; i++){
    cout << "Vertices of node " << i << ": ";
    for(auto it: adj[i]){
      cout << it << " ";
    }
    cout << endl;
  }

  Solution obj;
  bool ans = obj.isCyclic(V, adj);
  cout << "Is there a cycle in the graph: " << ans << endl;
}
