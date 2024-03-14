import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

class Solution{
  public static class Pair{
    int row;
    int col;
    public Pair(int row, int col){
      this.row = row;
      this.col = col;
    }
  }


  public static void bfs(int i, int j, int[][] vis, int[][] grid){
    int n = grid.length;
    int m = grid[0].length;
    Queue<Pair> q = new LinkedList<Pair>();
    vis[i][j] = 1;
    q.add(new Pair(i, j));

    while(!q.isEmpty()){
      int row = q.peek().row;
      int col = q.peek().col;
      q.remove();

      for(int dr=-1; dr<=1; dr++){
        for(int dc=-1; dc<=1; dc++){
          int newr = dr + row;
          int newc = dc + col;
          if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && vis[newr][newc]==0){
            vis[newr][newc] = 1;
            q.add(new Pair(newr, newc));
          }
        }
      }
    }

  }

  public static int numIslands(int[][] grid){
    int n = grid.length;
    int m = grid[0].length;
    int[][] vis = new int[n][m];
    int cnt = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(grid[i][j]==1 && vis[i][j]==0){
          cnt++;
          bfs(i, j, vis, grid);
        }
      }
    }
    return cnt;
  }

  public static void main(String[] args){
    int[][] grid = {{0,1},{1,0},{1,1},{1,0}};
    Solution obj = new Solution();
    int ans = obj.numIslands(grid);
    System.out.println("The number of islands is: " + ans);
  }
}


// import java.util.ArrayList;
// import java.util.LinkedList;
// import java.util.Queue;
//
// public class Solution{
//   public void bfs(int i, int j, int[][] vis, int[][] grid){
//     vis[i][j] = 1;
//     int n = grid.length;
//     int m = grid[0].length;
//     Queue<int[]> q = new LinkedList<>();
//     q.offer
//   }
//
//   publis int numIslands(int[][] grid){
//       int n = grid.length;
//       int m = grid[0].length;
//       int[][] vis = new int[n][m];
//       int cnt = 0;
//       for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//           if(grid[i][j] == 1 && !vis[i][j]){
//             cnt++;
//             bfs(i, j, vis, adjL);
//           }
//         }
//       }
//       return cnt;
//   }
//
//   public static void main(String[] args){
//     int[][] adj  = {
//       {0, 1}, {1, 0}, {1, 1}, {1, 0}
//     }
//     Solution obj = new Solution();
//     int result = obj.numIslands(adj);
//     System.out.println("Number of islands: " + result);
//   }
// }
