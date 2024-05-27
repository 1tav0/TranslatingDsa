#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestCellPath(const vector<vector<int>>& grid, int sr, int sc, int tr, int tc)
{
	// your code goes here
  int n = grid.size();
  int m = grid[0].size();
  queue<pair<int, pair<int,int>>> q;
  q.push({0, {sr, sc}});
  vector<vector<int>> vis(n+1, vector<int>(m+1, 0));
  vis[sr][sc] = 1;
  int delrow[] = {-1, 0, 1, 0};
  int delcol[] = {0, -1, 0, 1};
  while(!q.empty()){
    int steps = q.front().first;
    int row = q.front().second.first;
    int col = q.front().second.second;
    q.pop();

    if(row == tr && col == tc){
      return steps;
    }

    for(int i=0; i<4; i++){
      int newr = delrow[i] + row;
      int newc = delcol[i] + col;
      if(newr>=0 && newc>=0 && newr<n && newc<m && !vis[newr][newc] && grid[newr][newc]==1){
        vis[newr][newc] = 1;
        q.push({steps+1, {newr, newc}});
      }
    }
  }
  return -1;
}



int main()
{
  const vector<vector<int>> grid {{1, 1, 1, 1}, {0, 0, 0, 1}, {1, 1, 1, 1}};
  int sr = 0;
  int sc = 0;
  int tr = 2;
  int tc = 0;

  int ans = shortestCellPath(grid, sr, sc, tr, tc);
  cout << ans;
	return 0;
}

/*

https://www.linkedin.com/in/octavio-cruz-ortega/

tc = O(n*m)
sc = O(n*m)


    0  1  2  3
 0 [1, 1, 1, 1]
 1 [0, 0, 0, 1]
 2 [1, 1, 1, 1]


[sr,sc] = [0,0]

[tr,tc] = [2, 0]

queue<pair<int,pair<int,int>>>

int delrow[] = {-1, 0, 1, 0}
int delcol[] = {0, -1, 0, 1}

newr = delrow[i] + r



*/
