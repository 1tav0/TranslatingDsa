#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// toposort algorithm using a stack
class Solution{
public:
  void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st){
      vis[node] = 1;

      for(auto it: adj[node]){
          if(!vis[it]){
              dfs(it, vis, adj, st);
          }
      }

      st.push(node);
  }
  //Function to return list containing vertices in Topological order.
  vector<int> topoSort(int V, vector<int> adj[])
  {
      vector<int> vis(V);
      stack<int> st;
      for(int i=0; i<V; i++){
          if(!vis[i]){
              dfs(i, vis, adj, st);
          }
      }
      vector<int> ans;
      while(!st.empty()){
          int node = st.top();
          st.pop();

          ans.push_back(node);
      }
      return ans;
  }
};

void print(vector<int> ans){
  for(auto it: ans){
    cout << it << " ";
  }
}


int main(){
  int V = 4;
  vector<int> adj[V];
  // adj[1].push_back(3);
  // adj[2].push_back(3);
  // adj[4].push_back(0);
  // adj[5].push_back(0);
  // adj[5].push_back(2);
  adj[1].push_back(0);
  adj[2].push_back(0);
  adj[3].push_back(0);


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
