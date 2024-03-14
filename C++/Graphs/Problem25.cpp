#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*You are given a weighted undirected graph having n+1 vertices numbered from 0 to n
and m edges describing there are edges between a to b with some weight, find the
shortest path between the vertex 1 and the vertex n, and if the path does not exist
then return a list consisting of only -1.*/
class Solution{
public:
  vector<int> shortestPath(int n, int m, vector<vector<int>> &edges){
    vector<pair<int,int>> adj[n+1];
    for(auto it: edges){
      int u = it[0];
      int v = it[1];
      int wt = it[2];
      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n+1, 1e9);
    vector<int> parent(n+1);
    for(int i=0; i<n; i++){
      parent[i] = i;
    }
    dist[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
      int node = pq.top().second;
      int steps = pq.top().first;
      pq.pop();

      for(auto it: adj[node]){
        int v = it.first;
        int wt = it.second;
        if(steps + wt < dist[v]){
          dist[v] = steps+wt;
          pq.push({dist[v], v});
          parent[v] = node;
        }
      }
    }
    if(dist[n] == 1e9) return {-1};

    vector<int> path;
    int node = n;
    while(parent[node] != node){
      path.push_back(node);
      node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    return path;
  }
};

ostream& operator<<(ostream& os, vector<int> ans){
  for(auto it: ans){
    os << it << " ";
  }
  return os;
}

int main(){
  int V = 5;
  int E = 6;
  vector<vector<int>> edges = {
    {1, 2, 2},
    {2, 5, 5},
    {2, 3, 4},
    {1, 4, 1},
    {4, 3, 3},
    {3, 5, 1}
  };
  Solution obj;
  vector<int> ans = obj.shortestPath(V, E, edges);
  cout << "The shortest path between the vertex 1 and the vertex " << V << " is: " << ans;
  return 0;
}
