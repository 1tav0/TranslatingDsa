#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

// Shortest distance in a binary maze
class Solution{
public:
  int shortestPath(vector<vector<int>> &grid, pair<int,int> source, pair<int,int> destination){
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,pair<int,int>>> q;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    q.push({0, {source.first, source.second}});
    dist[source.first][source.second] = 0;
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, -1, 0, 1};
    while(!q.empty()){
      int steps = q.front().first;
      int row = q.front().second.first;
      int col = q.front().second.second;
      q.pop();

      if(row==destination.first && col==destination.second){
        return steps;
      }

      for(int i=0; i<4; i++){
        int newr = delrow[i] + row;
        int newc = delcol[i] + col;

        if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && dist[row][col]+steps<dist[newr][newc]){
          dist[newr][newc] = dist[row][col] + steps;
          q.push({steps+1, {newr, newc}});
        }
      }
    }
    return -1;
  }
};

ostream& operator<<(ostream& os, vector<vector<int>> grid){
  for(auto& row: grid){
    for(auto val: row){
      os << val << " ";
    }
    os << endl;
  }
  return os;
}

int main(){
  vector<vector<int>> grid;

  int row = 0;
  int col = 0;
  cout << "Enter the number of rows: ";
  cin >> row;
  cout << "Enter the number of cols: ";
  cin >> col;

  for(int i=0; i<row; i++){
    vector<int> newRow;
    for(int j=0; j<col; j++){
      int value;
      cout << "Enter the value at (" << i << " , " << j << "): ";
      cin >> value;
      newRow.push_back(value);
    }
    grid.push_back(newRow);
  }

  cout << "The grid is: \n" << grid << endl;

  pair<int,int> source;
  cout << "Enter the source coordinates: " << endl;
  cin >> source.first >> source.second;
  pair<int,int> destination;
  cout << "Enter the destination coordinates: " << endl;
  cin >> destination.first >> destination.second;

  Solution obj;
  int shortestDistance = obj.shortestPath(grid, source, destination);
  cout << "The shortest distance from (" << source.first <<","<<source.second <<")";
  cout << " to (" << destination.first << "," << destination.second << ") is " << shortestDistance;

  return 0;
}
