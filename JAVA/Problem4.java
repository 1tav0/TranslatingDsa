import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

class Solution{
  public int orangesRotting(int[][] grid){
    if(grid == null || grid.length == 0) return 0;
    int n = grid.length;
    int m = grid[0].length;
    Queue<int[]> q = new LinkedList<>();
    int orangesToRot = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(grid[i][j]==2){
          q.offer(new int[]{i,j});
        }
        if(grid[i][j]!= 0){
          orangesToRot++;
        }
      }
    }
    if (orangesToRot == 0) {
        // No fresh oranges to rot, return 0
        return 0;
    }
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, -1, 0, 1};
    int orangesRotted = 0;
    int time = 0;
    while(!q.isEmpty()){
      int qsize = q.size();
      orangesRotted += qsize;

      for(int t=0; t<qsize; t++){
        int[] arr = q.poll();
        for(int i=0; i<4; i++){
          int newr = delrow[i] + arr[0];
          int newc = delcol[i] + arr[1];
          if(newr<0 || newc<0 || newr>=n || newc>=m || grid[newr][newc]==0 || grid[newr][newc]==2)
            continue;

          grid[newr][newc] = 2;
          q.offer(new int[]{newr, newc});

        }
      }
      if(q.size() != 0){
        time++;
      }
    }
    return orangesToRot == orangesRotted ? time : -1;
  }

  public static void main(String[] args){

    int[][] grid = {{0,1,2},{0,1,2},{2,1,1}};
    System.out.println("original grid: ");
    for(int i=0; i<grid.length; i++){
      for(int j=0; j<grid[i].length; j++){
        System.out.print(grid[i][j] + " ");
      }
      System.out.println();
    }

    System.out.println("-------------------------------");

    Solution obj = new Solution();
    int ans = obj.orangesRotting(grid);

    System.out.println("new grid: ");
    for(int i=0; i<grid.length; i++){
      for(int j=0; j<grid[i].length; j++){
        System.out.print(grid[i][j] + " ");
      }
      System.out.println();
    }
    System.out.println("Time to take to rot all oranges: " + ans);
  }
}
