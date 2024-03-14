import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

class Solution{
  public class Pair{
    int row;
    int col;
    int steps;
    Pair(int row, int col, int steps){
      this.row = row;
      this.col = col;
      this.steps = steps;
    }
  }

  public int[][] nearestCell(int[][] grid){
    int n = grid.length;
    int m = grid[0].length;
    int[][] vis = new int[n][m];
    int[][] ans = new int[n][m];
    Queue<Pair> q = new LinkedList<Pair>();
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(grid[i][j]==1){
          q.add(new Pair(i,j,0));
          vis[i][j] = 1;
        }
      }
    }
    int[] delrow = {-1, 0, 1, 0};
    int[] delcol = {0, -1, 0, 1};
    while(!q.isEmpty()){
      int row = q.peek().row;
      int col = q.peek().col;
      int steps = q.peek().steps;
      q.remove();

      ans[row][col] = steps;

      for(int i=0; i<4; i++){
        int newr = delrow[i] + row;
        int newc = delcol[i] + col;
        if(newr>=0 && newr<n && newc>=0 && newc<m && vis[newr][newc] == 0){
          vis[newr][newc] = 1;
          q.add(new Pair(newr, newc, steps+1));
        }
      }
    }
    return ans;
  }

  public void printGraph(int[][] grid){
    for(int[] row: grid){
      for(int val: row){
        System.out.print(val + " ");
      }
      System.out.println();
    }
  }

  public static void main(String[] args){
    int[][] grid = {{1,0,1},{1,1,0},{1,0,0}};
    Solution obj = new Solution();
    int[][] ans = obj.nearestCell(grid);
    System.out.println("old grid: ");
    obj.printGraph(grid);
    System.out.println("new grid: ");
    obj.printGraph(ans);
  }
}
