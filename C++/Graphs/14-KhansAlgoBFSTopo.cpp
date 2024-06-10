#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// khans algorithms toposort 
class Solution{
  public:
  vector<int> topoSort(int V, vector<int> adj[]){
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
    while(!q.empty()){
      int node = q.front();
      q.pop();

      topo.push_back(node);
      for(auto v: adj[node]){
        inDegrees[v]--;
        if(inDegrees[v]==0){
          q.push(v);
        }
      }
    }
    return topo;
  }
};

void print(vector<int> ans){
  for(auto it: ans){
    cout << it << " ";
  }
}

int main(){
  int V = 6;
  vector<int> adj[V];
  adj[1].push_back(3);
  adj[2].push_back(3);
  adj[4].push_back(0);
  adj[5].push_back(0);
  adj[5].push_back(2);
  // adj[1].push_back(0);
  // adj[2].push_back(0);
  // adj[3].push_back(0);


  Solution obj;
  for(int i=0; i<V; i++){
    cout << "Vertices of node " << i << ": ";
    for(auto it: adj[i]){
      cout << it << " ";
    }
    cout << endl;
  }

  vector<int> ans = obj.topoSort(V,adj);
  cout << "The toposort is: " << endl;
  print(ans);

  return 0;
}
