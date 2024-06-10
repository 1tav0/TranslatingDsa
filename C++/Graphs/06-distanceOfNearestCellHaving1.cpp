#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Distance of Nearing cell having 1
class Solution{
public:
  vector<vector<int>> nearestCell(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m,0));
    vector<vector<int>> ans(n, vector<int>(m, 0));
    queue<pair<pair<int,int>,int>> q;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(grid[i][j]==1){
          q.push({{i,j}, 0});
          vis[i][j] = 1;
        }
      }
    }
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, -1, 0, 1};
    while(!q.empty()){
      int row = q.front().first.first;
      int col = q.front().first.second;
      int steps = q.front().second;
      q.pop();

      ans[row][col] = steps;

      for(int i=0; i<4; i++){
        int newr = delrow[i] + row;
        int newc = delcol[i] + col;
        if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc]){
          vis[newr][newc] = 1;
          q.push({{newr,newc}, steps+1});
        }
      }
    }
    return ans;
  }
};

int main(){
  vector<vector<int>> grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}};
  Solution obj;
  vector<vector<int>> ans;
  cout << "old grid: " << endl;
  for(int i=0; i<grid.size(); i++){
    for(int j=0; j<grid[i].size(); j++){
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }

  cout << "New grid with distance of nearest cell having 1: " << endl;
  ans = obj.nearestCell(grid);
  for(int i=0; i<ans.size(); i++){
    for(int j=0; j<ans[i].size(); j++){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
