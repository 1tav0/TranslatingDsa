#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Implementing Dijkstra Algorithm with a priority_queue
class Solution{
public:
  vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V, 1e9);
    pq.push({0, S});
    dist[S] = 0;
    while(!pq.empty()){
      int steps = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      for(auto it: adj[node]){
        int v = it[0];
        int wt = it[1];
        if(steps+wt < dist[v]){
          dist[v] = dist[node] + wt;
          pq.push({dist[v], v});
        }
      }
    }
    return dist;
  }
};

ostream& operator<<(ostream& os, vector<int> ans){
  for(auto it: ans){
    os << it << " ";
  }
  return os;
}

int main(){
  // int V = 2;
  // vector<vector<int>> adj[V] = {
  //   {{1, 9}},
  //   {{0, 9}}
  // };
  // int S = 0;
  int V = 3;
  vector<vector<int>> adj[V] = {
    {{1, 1},
    {2, 6}},
    {{2, 3},
    {0, 1}},
    {{1, 3},
    {0, 6}}
  };
  int S = 2;
  Solution obj;
  vector<int> ans = obj.dijkstra(V, adj, S);
  cout << "The shortest steps(wt) of all the vertex's from the source vertex " << S << " are: " << ans;
  return 0;
}
