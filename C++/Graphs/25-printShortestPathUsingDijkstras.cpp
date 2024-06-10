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
  vector<int> shortestPath1(int n, int m, vector<vector<int>> &edges){
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

  vector<int> shortestPath2(int n, int m, vector<vector<int>>& edges) {
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
    pq.push({0, 1});
    dist[1] = 0;
    vector<int> parent(n+1);
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    while(!pq.empty()){
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for(auto it: adj[node]){
            int v = it.first;
            int wt = it.second;
            if(dis+wt < dist[v]){
                dist[v] = dis+wt;
                pq.push({dist[v], v});
                parent[v] = node;
            }
        }
    }
    vector<int> path;
    if(dist[n] == 1e9) return {-1};

    int node = n;
    while(node != parent[node]){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    path.push_back(dist[n]);
    reverse(path.begin(), path.end());

    return path;
}

  /*
  class Pair{
    int first;
    int second;

    Pair(int first, int second){
        this.first = first;
        this.second = second;
    }
}

class Solution{
    public List<Integer> shortestPath(int n, int m, int edges[][]){
        // we are expected to print path from source = '1' to 'm'

        ArrayList<ArrayList<Pair>> adj = new ArrayList<>();

        for(int i = 0 ; i <=n ; i++){
            adj.add(new ArrayList<>());
        }

        for(int i = 0 ; i < m ; i++){
            // { {v, wt} , {v, wt} }
            // first holds v
            // second holds wt
            adj.get(edges[i][0]).add(new Pair(edges[i][1], edges[i][2]));
            adj.get(edges[i][1]).add(new Pair(edges[i][0], edges[i][2]));
        }

        // min heap based on distance
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>((x,y) -> x.first - y.first);

        // distance array
        int distance [] = new int[n+1];
        // parent array to keep a track of where the previous edge is coming from
        int parent [] = new int[n+1];

        for(int i = 1 ; i <=n ; i++){
            distance[i] = (int)(1e9);
            parent[i] = i;
        }

        //soruce node is 1
        distance[1] = 0;
        // add it like (distance, node)
        // distance - first
        // node - second
        pq.add(new Pair(0, 1));

        while(!pq.isEmpty()){
            Pair it = pq.peek();
            int dis = it.first;
            int node = it.second;

            pq.remove();

            for(Pair iter : adj.get(node)){
                int adjNode = iter.first;     // remember the adj arrayList stores <v, wt>
                int edW = iter.second;

                if(dis + edW < distance[adjNode]){
                    distance[adjNode] = dis + edW;
                    pq.add(new Pair(distance[adjNode], adjNode));
                    //update parent of the adjNode to node
                    parent[adjNode] = node;
                }
            }
        }

        List<Integer> path = new ArrayList<>();
        if(distance[n] == (int)(1e9)){
            path.add(-1);
            return path;

        }
        int node = n;

        while(parent[node] != node){
            path.add(node);
            node = parent[node];
        }


        path.add(1);
        // first ele should be the weight of the path hence added at the last before reversing
        // rest of the ele in the list will represent the path of the graph from 1 to 'n'
        path.add(distance[n]);  // additonal line to be added (as per latest updated problem statement)
        Collections.reverse(path);

        return path;
    }
}
  */
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
