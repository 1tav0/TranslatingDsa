#include <iostream>
#include <vector>
using namespace std;
// Find Eventual Safe States

class Solution {
    private:
    bool dfsCheckCycle(vector<int>& vis, vector<int>& safeNode, vector<int>& samePath, vector<int> adj[], int node){
        vis[node] = 1;
        samePath[node] = 1;

        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfsCheckCycle(vis,safeNode,samePath,adj,it) == true){
                    return true;
                    vis[it] = 1;
                    safeNode[it] = 0;
                }
            }
            else if(samePath[it]){
                return true;
                safeNode[it] = 0;
            }
        }

        samePath[node] = 0;
        safeNode[node] = 1;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> samePath(V, 0);
        vector<int> safeNode(V, 0);
        vector<int> ans;

        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfsCheckCycle(vis,safeNode,samePath,adj,i);
            }
        }

        for(int i=0; i<V; i++){
            if(safeNode[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

void printGraph(vector<int> ans){
  for(auto val: ans){
    cout << val << " ";
  }
}


int main(){
  int V = 4;
  vector<int> adj[V];
  // adj[0].push_back(1);
  // adj[0].push_back(2);
  // adj[1].push_back(3);
  // adj[1].push_back(2);
  // adj[2].push_back(5);
  // adj[3].push_back(0);
  // adj[4].push_back(5);
  adj[0].push_back(1);
  adj[1].push_back(2);
  adj[2].push_back(0);
  adj[2].push_back(3);
  Solution obj;
  for(int i=0; i<V; i++){
    cout << "Vertices of node " << i << ": ";
    for(auto it: adj[i]){
      cout << it << " ";
    }
    cout << endl;
  }
  vector<int> ans = obj.eventualSafeNodes(V, adj);
  cout << "The safe nodes are: " << endl;
  printGraph(ans);
  return 0;
}
