#include <iostream>
#include <vector>

using namespace std;

// Number of provinces
class Problem1{
  public:
    static void dfs(int node, vector<int> adjL[], vector<int> &vis){
      vis[node] = 1;

      for(auto it: adjL[node]){
        if(!vis[it]){
          dfs(it, adjL, vis);
        }
      }
    }

    static int numProvinces(vector<vector<int>> adj, int V){
      vector<int> adjL[V];
      for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
          if(adj[i][j]==1 && i!=j){
            adjL[i].push_back(j);
            adjL[j].push_back(i);
          }
        }
      }
      vector<int> vis(V, 0);
      int cnt = 0;
      for(int i=0; i<V; i++){
        if(!vis[i]){
          cnt++;
          dfs(i, adjL, vis);
        }
      }
      return cnt;
    }
};

int main(){
  vector<vector<int>> adj = {
    {1,0,1},
    {0,1,0},
    {1,0,1}
  };

  Problem1 obj;

  int result = obj.numProvinces(adj, 3);
  cout << "number of provinces: " << result << endl;
  return 0;
}
