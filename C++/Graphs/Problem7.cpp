#include <iostream>
#include <vector>
using namespace std;
// Replace O's with X's
class Solution{
public:
  void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board, int delrow[], int delcol[]){
    vis[row][col] = 1;
    int n = board.size();
    int m = board[0].size();

    for(int i=0; i<4; i++){
      int newr = delrow[i] + row;
      int newc = delcol[i] + col;
      if(newr>=0 && newr<n && newc>=0 && newc<m && board[newr][newc]=='O' && !vis[newr][newc]){
        dfs(newr, newc, vis, board, delrow, delcol);
      }
    }
  }

  vector<vector<char>> solve(vector<vector<char>> board){
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, -1, 0, 1};

    for(int i=0; i<m; i++){
      //left col
      if(board[i][0]=='O' && !vis[i][0]){
        dfs(i, 0, vis, board, delrow, delcol);
      }
      //right col
      if(board[i][m-1]=='O' && !vis[i][m-1]){
        dfs(i, m-1, vis, board, delrow, delcol);
      }
    }

    for(int j=0; j<m; j++){
      //top row
      if(board[0][j]=='O' && !vis[0][j]){
        dfs(0, j, vis, board, delrow, delcol);
      }
      //bottom row
      if(board[n-1][j]=='O' && !vis[n-1][j]){
        dfs(n-1, j, vis, board, delrow, delcol);
      }
    }

    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(board[i][j]=='O' && !vis[i][j]){
          board[i][j] = 'X';
        }
      }
    }

    return board;
  }



  void printGraph(vector<vector<char>> board){
    for(auto row: board){
      for(auto val: row){
        cout << val << " ";
      }
      cout << endl;
    }
  }
};

int main(){
  vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
  cout << "old grid: " << endl;
  Solution obj;
  obj.printGraph(board);
  cout << "new grid: " << endl;
  vector<vector<char>> ans = obj.solve(board);
  obj.printGraph(ans);
}
