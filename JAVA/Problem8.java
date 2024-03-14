import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

class Solution{
  class Pair{
    int row;
    int col;
    Pair(int row, int col){
      this.row = row;
      this.col = col;
    }
  }

  int numberOfEnclaves(int[][] grid){
    int n = grid.length;
    int m = grid[0].length;
    int[][] vis = new int[n][m];
    Queue<Pair> q = new LinkedList<Pair>();
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(i==0 || j==0 || i==n-1 || j==m-1){
          if(grid[i][j]==1){
            vis[i][j] = 1;
            q.add(new Pair(i, j));
          }
        }
      }
    }
    int[] delrow = {-1, 0, 1, 0};
    int[] delcol = {0, -1, 0, 1};
    while(!q.isEmpty()){
      int row = q.peek().row;
      int col = q.peek().col;
      q.remove();

      for(int i=0; i<4; i++){
        int newr = delrow[i] + row;
        int newc = delcol[i] + col;

        if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && vis[newr][newc]==0){
          vis[newr][newc] = 1;
          q.add(new Pair(newr, newc));
        }
      }
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(grid[i][j]==1 && vis[i][j]==0){
          cnt++;
        }
      }
    }
    return cnt;
  }

  int[][] newGrid(int[][] grid){
    int n = grid.length;
    int m = grid[0].length;
    int[][] vis = new int[n][m];
    Queue<Pair> q = new LinkedList<Pair>();
    int[][] ans = new int[n][m];

    for (int i = 0; i < grid.length; i++) {
        for (int j = 0; j < grid[i].length; j++) {
            ans[i][j] = grid[i][j];
        }
    }

    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(i==0 || j==0 || i==n-1 || j==m-1){
          if(grid[i][j]==1){
            vis[i][j] = 1;
            q.add(new Pair(i, j));
            ans[i][j] = 0;
          }
        }
      }
    }
    int[] delrow = {-1, 0, 1, 0};
    int[] delcol = {0, -1, 0, 1};
    while(!q.isEmpty()){
      int row = q.peek().row;
      int col = q.peek().col;
      q.remove();

      for(int i=0; i<4; i++){
        int newr = delrow[i] + row;
        int newc = delcol[i] + col;

        if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && vis[newr][newc]==0){
          vis[newr][newc] = 1;
          q.add(new Pair(newr, newc));
          ans[newr][newc] = 0;
        }
      }
    }

    return ans;
  }

  void printGraph(int[][] grid){
    for(int[] row: grid){
      for(int val: row){
        System.out.print(val + " ");
      }
      System.out.println();
    }
  }

  public static void main(String[] args){
    int[][] grid = {{0, 0, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {0, 1, 1, 0}};
    System.out.println("old grid: ");
    Solution obj = new Solution();
    obj.printGraph(grid);
    int[][] ans = obj.newGrid(grid);
    System.out.println("new grid: ");
    obj.printGraph(ans);
    int cnt = obj.numberOfEnclaves(grid);
    System.out.println("Number of enclaves in new grid: " + cnt);
  }
}
