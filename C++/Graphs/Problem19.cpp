#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

//Shortest path in directed Acyclic Graph

class Solution{
public:
    void dfs(int node, vector<int>& vis, stack<int>& st, vector<pair<int,int>> adj[]){
        vis[node] = 1;

        for(auto it: adj[node]){
            if(!vis[it.first]){
                dfs(it.first,vis,st,adj);
            }
        }
        st.push(node);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        //get topo
        vector<int> vis(N,0);
        stack<int> st;
        for(int i=0; i<N;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        //relax the edges
        vector<int> dist(N, 1e9);
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();

            for(auto it: adj[node]){
                int adjNode = it.first;
                int adjWt = it.second;

                if(dist[node]+adjWt < dist[adjNode]){
                    dist[adjNode] = dist[node]+adjWt;
                }
            }
        }

        for(int i=0; i<N; i++){
            if(dist[i]==1e9) dist[i] = -1;
        }

        return dist;
    }
};

ostream& operator<<(ostream& os, vector<int> ans){
  for(auto &it: ans){
    os << it << " ";
  }
  return os;
}

int main(){
  // vector<vector<int>> edges = {
  //   {0,1,2},
  //   {0,4,1},
  //   {4,5,4},
  //   {4,2,2},
  //   {1,2,3},
  //   {2,3,6},
  //   {5,3,1}
  // };
  // int N = 6;
  // int M = 7;
  vector<vector<int>> edges = {
    {0,1,2},
    {0,2,1}
  };
  int N = 4;
  int M = 2;
  Solution obj;
  vector<int> ans = obj.shortestPath(N, M, edges);
  cout << "The shortes path is: " << ans;

  return 0;
}
