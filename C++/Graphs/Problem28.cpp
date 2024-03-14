#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
  int cheapestFlight(int n, vector<vector<int>>& flights, int src, int dst, int K){
    vector<pair<int,int>> adj[n];
    for(auto it: flights){
      int u = it[0];
      int v = it[1];
      int wt = it[2];
      adj[u].push_back({v, wt});
    }
    vector<int> dist(n, 1e9);
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    dist[src] = 0;
    pq.push({0, {src, 0}});
    while(!pq.empty()){
      int stops = pq.top().first;
      int node = pq.top().second.first;
      int cost = pq.top().second.second;
      pq.pop();

      if(stops>K) continue;

      for(auto it: adj[node]){
        int v = it.first;
        int wt = it.second;
        if(cost+wt<dist[v] && stops<=K){
          dist[v] = cost + wt;
          pq.push({stops+1, {v, dist[v]}});
        }
      }
    }
    if(dist[dst]==1e9) return -1;

    return dist[dst];
  }
};

ostream& operator<<(ostream& os, vector<vector<int>> flights){
  for(auto row: flights){
    for(int val: row){
      os << val << " ";
    }
    os << endl;
  }
  return os;
}

int main(){
  vector<vector<int>> flights;
  int rows=0;
  int cols=0;
  cout << "Enter the number of rows: ";
  cin >> rows;
  cout << "Enter the number of cols: ";
  cin >> cols;
  int citites=0;
  cout << "Enter the number of citites: ";
  cin >> citites;
  int src=0;
  cout << "Enter the source node: ";
  cin >> src;
  int dst=0;
  cout << "Enter the destination node: ";
  cin >> dst;
  int stops=0;
  cout << "Enter the number of stops: ";
  cin >> stops;

  for(int i=0; i<rows; i++){
    vector<int> newRow;
    for(int j=0; j<cols; j++){
      int val;
      cout << "Enter the value at (" << i << "," << j << "): ";
      cin >> val;
      newRow.push_back(val);
    }
    flights.push_back(newRow);
  }

  cout << "The Flights: " << endl << flights << endl;
  Solution obj;
  int cost = obj.cheapestFlight(citites, flights, src, dst, stops);
  cout << "The optimal path with at most " << stops << " stop from city " << src << " to " << dst << " is: " << cost;

  return 0;
}
