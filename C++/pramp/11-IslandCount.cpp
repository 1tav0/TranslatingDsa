#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
Given a 2D array binaryMatrix of 0s and 1s, implement a function
getNumberOfIslands that returns the number of islands of 1s in binaryMatrix.

An island is defined as a group of adjacent values that are all 1s.
A cell in binaryMatrix is considered adjacent to another cell if they are
next to each either on the same row or column. Note that two values of 1
are not part of the same island if they’re sharing only a mutual “corner”
(i.e. they are diagonally neighbors).

input:  binaryMatrix = [ [0,    1,    0,    1,    0],
                         [0,    0,    1,    1,    1],
                         [1,    0,    0,    1,    0],
                         [0,    1,    1,    0,    0],
                         [1,    0,    1,    0,    1] ]

output: 6 # since this is the number of islands in binaryMatrix.
          # See all 6 islands color-coded below.
*/
void bfs(int i, int j, vector<vector<int>> &vis, const vector<vector<int>> &binaryMatrix){
  int n = binaryMatrix.size();
  int m = binaryMatrix[0].size();
  queue<pair<int,int>> q;
  q.push({i, j});
  vis[i][j] = 1;
  int delrow[] = {-1, 0, 1, 0};
  int delcol[] = {0, -1, 0, 1};
  while(!q.empty()){
    int row = q.front().first;
    int col = q.front().second;
    q.pop();

    for(int i=0; i<4; i++){
      int newr = row + delrow[i];
      int newc = col + delcol[i];

      if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && binaryMatrix[newr][newc]==1){
        vis[newr][newc] = 1;
        q.push({newr, newc});
      }
    }
  }
}

int getNumberOfIslands( const vector<vector<int>>& binaryMatrix )
{
  int n = binaryMatrix.size();
  int m = binaryMatrix[0].size();
  vector<vector<int>> vis(n, vector<int>(m, 0));
  int cnt = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(binaryMatrix[i][j] == 1 && !vis[i][j]){
        bfs(i, j, vis, binaryMatrix);
        cnt++;
      }
    }
  }
  return cnt;
}

int main() {

  return 0;
}

/*
tc - O(n*m)
sc - O(n*m)+O(n*m)

https://www.linkedin.com/in/octavio-cruz-ortega/

*/


/*
   0     1     2     3     4
0 [0,    1,    0,    1,    0]
1 [0,    0,    1,    1,    1]
2 [1,    0,    0,    1,    0]
3 [0,    1,    1,    0,    0]
4 [1,    0,    1,    0,    1]



*/
