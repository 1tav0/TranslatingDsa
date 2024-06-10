#include <iostream>
#include <vector>
#include <set>
using namespace std;
// Dijkstra's with a set
class Solution{
public:
  vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
    set<pair<int,int>> st;
    vector<int> dist(V, 1e9);
    st.insert({S, 0});
    dist[S] = 0;
    while(st.size()>0){
      auto it = *(st.begin());
      int node = it.first;
      int steps = it.second;
      st.erase(it);

      for(auto it: adj[node]){
        int v = it[0];
        int wt = it[1];
        if(steps + wt < dist[v]){
          dist[v] = steps + wt;
          st.insert({v, dist[v]});
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
  // int V = 3;
  // int S = 2;
  // vector<vector<int>> adj[V] = {
  //   {
  //     {1, 1},
  //     {2, 6}
  //   },
  //   {
  //     {2, 3},
  //     {0, 1}
  //   },
  //   {
  //     {1, 3},
  //     {0, 6}
  //   }
  // };
  int V = 2;
  int S = 0;
  vector<vector<int>> adj[V] = {
    {
      {1, 9}
    },
    {
      {0, 9}
    }
  };
  Solution obj;
  vector<int> ans = obj.dijkstra(V, adj, S);
  cout << "The shortest distance of all the vertex's from the source vertex " << S << " are: " << ans;
  return 0;
}
