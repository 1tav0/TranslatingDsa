import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

class Solution{

  private void dfs(int row, int col, int[][] vis, int[][] grid, ArrayList<String> vec, int row1, int col1){
    vis[row][col] = 1;
    vec.add(toString(row-row1, col-col1));
    int n = grid.length;
    int m = grid[0].length;
    int[] delrow = {-1, 0, 1, 0};
    int[] delcol = {0, -1, 0, 1};

    for(int i=0; i<4; i++){
      int newr = delrow[i] + row;
      int newc = delcol[i] + col;
      if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && vis[newr][newc]==0){
        dfs(newr, newc, vis, grid, vec, row1, col1);
      }
    }
  }

  private String toString(int r, int c){
    return Integer.toString(r) + " " + Integer.toString(c);
  }

  int countDistinctIslands(int[][] grid){
    int n = grid.length;
    int m = grid[0].length;
    int[][] vis = new int[n][m];
    HashSet<ArrayList<String>> st = new HashSet<>();
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(grid[i][j]==1 && vis[i][j]==0){
          ArrayList<String> vec = new ArrayList<>();
          dfs(i, j, vis, grid, vec, i, j);
          st.add(vec);
        }
      }
    }
    return st.size();
  }

  private void printGraph(int[][] grid){
    for(int[] row: grid){
      for(int val: row){
        System.out.print(val + " ");
      }
      System.out.println();
    }
  }

  public static void main(String[] args){
    int[][] grid = {
      {1, 1, 0, 0, 0},
      {1, 1, 0, 0, 0},
      {0, 0, 0, 1, 1},
      {0, 0, 0, 1, 1}
    };

    Solution obj = new Solution();
    System.out.println("grid: ");
    obj.printGraph(grid);
    int ans = obj.countDistinctIslands(grid);
    System.out.println("The number of distinct islands is: " + ans);

  }
}
