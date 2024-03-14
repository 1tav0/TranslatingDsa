#include <iostream>
#include <vector>
#include <set>
using namespace std;
// Number of Distinct Islands
class Solution{
public:

  void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int,int>> &vec, int row1, int col1){
    vis[row][col] = 1;
    vec.push_back({row-row1, col-col1});
    int n = grid.size();
    int m = grid[0].size();
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, -1, 0, 1};

    for(int i=0; i<4; i++){
      int newr = delrow[i] + row;
      int newc = delcol[i] + col;

      if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && grid[newr][newc]==1){
        dfs(newr, newc, vis, grid, vec, row1, col1);
      }
    }
  }

  int countDistinctIslands(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    set<vector<pair<int,int>>> st;

    vector<vector<int>> vis(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(grid[i][j]==1 && !vis[i][j]){
          vector<pair<int,int>> vec;
          dfs(i, j, vis, grid, vec, i, j);
          st.insert(vec);
        }
      }
    }
    return st.size();
  }

  void printGraph(vector<vector<int>> &grid){
    for(auto row: grid){
      for(auto val: row){
        cout << val << " ";
      }
      cout << endl;
    }
  }
};

int main(){
  vector<vector<int>> grid = {
    {1, 1, 0, 1, 1},
    {1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1},
    {1, 1, 0, 1, 1}
  };
  Solution obj;
  cout << "grid: " << endl;
  obj.printGraph(grid);
  int ans = obj.countDistinctIslands(grid);
  cout << "how many distinct islands: " << ans << endl;

  return 0;
}
