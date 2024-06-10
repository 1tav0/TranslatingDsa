#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//Number of islands I
class Problem2{
  public:

    int bfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid){
      int n = grid.size();
      int m = grid[0].size();
      vis[i][j] = 1;
      queue<pair<int,int>> q;
      q.push({i, j});
      while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int dr=-1; dr<=1; dr++){
          for(int dc=-1; dc<=1; dc++){
            int newr = r + dr;
            int newc = c + dc;
            if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]=='1' && !vis[newr][newc]){
                vis[newr][newc] = 1;
                q.push({newr, newc});
            }
          }
        }
      }
    }

    int numIslands(vector<vector<char>> &grid){
      int n = grid.size();
      int m = grid[0].size();
      vector<vector<int>> vis(n, vector<int>(m, 0));
      int cnt = 0;
      for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
          if(grid[i][j] == '1' && !vis[i][j]){
            cnt++;
            bfs(i, j, vis, grid);
          }
        }
      }
      return cnt;
    }
};

int main(){

  vector<vector<char>> grid = {
    {'0','1','1','1','0','0','0'},
    {'0','0','1','1','0','1','0'}
  };

  Problem2 obj;
  int result = obj.numIslands(grid);
  cout << "number of islands: " << result;

  return 0;
}
