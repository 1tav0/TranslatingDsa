#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Biparite Graph
class Solution{
public:
  bool bfs(int node, vector<int> &color, vector<int> adj[]){
    color[node] = 1;
    queue<int> q;
    q.push(node);

    while(!q.empty()){
      int u = q.front();
      q.pop();

      for(auto v: adj[u]){
        if(color[v]==-1){
          color[v] = !color[u];
          q.push(v);
        }else if(color[u]==color[v]){
          return false;
        }
      }
    }
    return true;
  }
  bool isBiparte(int V, vector<int> adj[]){
    vector<int> color(V, -1);

    for(int i=0; i<V; i++){
      if(color[i]==-1){
        if(bfs(i, color, adj)==false){
          return false;
        }
      }
    }
    return true;
  }
};


int main(){
  int V = 2;
  vector<int> adj[V];
  // adj[0].push_back(2);
  // adj[2].push_back(0);
  // adj[1].push_back(3);
  // adj[3].push_back(1);
  // adj[3].push_back(0);
  // adj[0].push_back(3);
  // adj[3].push_back(2);
  // adj[2].push_back(3);
  adj[0].push_back(1);
  adj[1].push_back(0);
  adj[2].push_back(1);
  adj[1].push_back(2);

  cout << "Graph: " << endl;
  for(int i=0; i<V; i++){
    cout << "Vertices of Node " << i << ": ";
    for(auto it: adj[i]){
      cout << it << " ";
    }
    cout << endl;
  }

  Solution obj;
  bool ans = obj.isBiparte(V, adj);
  cout << "Is the graph biparte? " << ans;

  return 0;

}
