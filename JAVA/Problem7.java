import java.util.ArrayList;

class Solution{

  public void dfs(int row, int col, int[][] vis, char[][] board, int[] delrow, int[] delcol){
        vis[row][col] = 1;
        int n = board.length;
        int m = board[0].length;

        for(int i=0; i<4; i++){
            int newr = delrow[i] + row;
            int newc = delcol[i] + col;
            if(newr>=0 && newr<n && newc>=0 && newc<m && board[newr][newc]=='O' && vis[newr][newc]==0){
                dfs(newr, newc, vis, board, delrow, delcol);
            }
        }
    }

  public char[][] solve(char[][] board){
    int n = board.length;
    int m = board[0].length;
    int[][] vis = new int[n][m];
    int[] delrow = {-1, 0, 1, 0};
    int[] delcol = {0, -1, 0, 1};
    for(int i=0; i<n; i++){
      //left col
      if(board[i][0]=='O' && vis[i][0]==0){
        dfs(i, 0, vis, board, delrow, delcol);
      }
      //right col
      if(board[i][m-1]=='O' && vis[i][m-1]==0){
        dfs(i, m-1, vis, board, delrow, delcol);
      }
    }
    for(int j=0; j<m; j++){
      //top row
      if(board[0][j]=='O' && vis[0][j]==0){
        dfs(0, j, vis, board, delrow, delcol);
      }
      //bottom row
      if(board[n-1][j]=='O' && vis[n-1][j]==0){
        dfs(n-1, j, vis, board, delrow, delcol);
      }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]=='O' && vis[i][j]==0){
                board[i][j] = 'X';
            }
        }
    }

    return board;
  }

  public void printGraph(char[][] board){
    for(char[] row: board){
      for(char val: row){
        System.out.print(val + " ");
      }
      System.out.println();
    }
  }

  public static void main(String[] args){
    char[][] board = {
      {'X','X','X','X'},
      {'X','O','O','X'},
      {'X','X','O','X'},
      {'X','O','X','X'}
    };

    System.out.println("old grid: ");
    Solution obj = new Solution();
    obj.printGraph(board);
    System.out.println("new grid: ");
    char[][] ans = obj.solve(board);
    obj.printGraph(ans);

  }
}
