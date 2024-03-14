#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Rotten Oranges
class Solution{
public:
  int orangesRotting(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int,pair<int,int>>> q;
    int orangesToRot = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
          if(grid[i][j]==2 && !vis[i][j]){
            q.push({0, {i, j}});
            vis[i][j] = 2;
          }
          if(grid[i][j]==1){
            orangesToRot++;
          }
        }
    }
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, -1, 0, 1};
    int orangesRotted = 0;
    int tim = 0;
    while(!q.empty()){
      int row = q.front().second.first;
      int col = q.front().second.second;
      int t = q.front().first;
      q.pop();

      tim = max(tim, t);
      for(int i=0; i<4; i++){
        int newr = delrow[i] + row;
        int newc = delcol[i] + col;

        if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && !vis[newr][newc]){
          vis[newr][newc] = 2;
          q.push({t+1, {newr, newc}});
          orangesRotted++;
        }
      }
    }
    if(orangesToRot != orangesRotted) return -1;

    return tim;
  }

  vector<vector<int>> newGrid(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(grid);
    queue<pair<int,pair<int,int>>> q;
    int orangesToRot = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
          if(grid[i][j]==2){
            q.push({0, {i, j}});
          }
          if(grid[i][j]==1){
            orangesToRot++;
          }
        }
    }
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, -1, 0, 1};
    int orangesRotted = 0;
    int tim = 0;
    while(!q.empty()){
      int row = q.front().second.first;
      int col = q.front().second.second;
      int t = q.front().first;
      q.pop();

      tim = max(tim, t);
      for(int i=0; i<4; i++){
        int newr = delrow[i] + row;
        int newc = delcol[i] + col;

        if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && vis[newr][newc]==1){
          vis[newr][newc] = 2;
          q.push({t+1, {newr, newc}});
          orangesRotted++;
        }
      }
    }
    if(orangesToRot != orangesRotted) return {{}};

    return vis;
  }
};


int main(){
  vector<vector<int>> grid = {{0,1,2,1,0,1,2},{0,1,2,0,1,2,1},{2,1,1,1,2,0,1}};
  cout << "old grid" << endl;
  for(auto row: grid){
    for(auto val: row){
      cout << val << " ";
    }
    cout << endl;
  }

  Solution obj;
  vector<vector<int>> mat = obj.newGrid(grid);
  cout << "new grid" << endl;
  for(auto row: mat){
    for(auto val: row){
      cout << val << " ";
    }
    cout << endl;
  }

  cout << "Time taken to rot all oranges: " << obj.orangesRotting(grid) << " sec";
}
