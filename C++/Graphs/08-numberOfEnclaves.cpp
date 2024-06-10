#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Number of Enclaves
class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1){
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int newr = delrow[i] + r;
                int newc = delcol[i] + c;
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && !vis[newr][newc]){
                    vis[newr][newc] = 1;
                    q.push({newr, newc});
                }
            }
        }

        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }

    vector<vector<int>> newGrid(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        vector<vector<int>> ans(grid);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1){
                        q.push({i, j});
                        vis[i][j] = 1;
                        ans[i][j] = 0;
                    }
                }
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int newr = delrow[i] + r;
                int newc = delcol[i] + c;
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && !vis[newr][newc]){
                    vis[newr][newc] = 1;
                    ans[newr][newc] = 0;
                    q.push({newr, newc});
                }
            }
        }
        return ans;
    }

    void printGraph(vector<vector<int>> &graph){
      for(auto row: graph){
        for(auto val: row){
          cout << val << " ";
        }
        cout << endl;
      }
    }
};

int main(){
  vector<vector<int>> grid = {{0, 0, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {0, 1, 1, 0}};
  cout << "old grid: " << endl;
  Solution obj;
  obj.printGraph(grid);
  cout << "new grid: " << endl;
  vector<vector<int>> ans = obj.newGrid(grid);
  obj.printGraph(ans);
  cout << "Number of enclaves: " << obj.numberOfEnclaves(grid) << endl;
  return 0;
}
