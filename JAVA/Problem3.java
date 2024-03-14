import java.util.ArrayList;
import java.util.Arrays;
class Solution{

  public void dfs(int initColor, int[][] vis, int[] delrow, int[] delcol, int[][] image, int row, int col, int newColor){
    vis[row][col] = newColor;
    int n = image.length;
    int m = image[0].length;
    for(int i=0; i<4; i++){
      int newr = delrow[i] + row;
      int newc = delcol[i] + col;
      if(newr>=0 && newr<n && newc>=0 && newc<m && image[newr][newc]==initColor && vis[newr][newc] != newColor){
        vis[newr][newc] = newColor;
        dfs(initColor, vis, delrow, delcol, image, newr, newc, newColor);
      }
    }
  }

  public int[][] floodFill(int[][] image, int sr, int sc, int newColor){
    int initColor = image[sr][sc];
    int[][] vis = new int[image.length][image[0].length];
    // for(int i=0; i<image.length; i++){
    //   vis[i] = Arrays.copyOf(image[i], image[i].length);
    // }
    for (int i = 0; i < image.length; i++) {
        for (int j = 0; j < image[i].length; j++) {
            vis[i][j] = image[i][j];
        }
    }
    int[] delrow = {-1, 0, 1, 0};
    int[] delcol = {0, -1, 0, 1};
    dfs(initColor, vis, delrow, delcol, image, sr, sc, newColor);
    return vis;
  }

  public static void main(String[] args){
    int[][] image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1;
    int sc = 1;
    int newColor = 2;
    Solution obj = new Solution();
    int[][] ans = obj.floodFill(image, sr, sc, newColor);
    System.out.println("old image: ");
    for(int[] row: image){
      for(int val: row){
        System.out.print(val + " ");
      }
      System.out.println();
    }

    System.out.println("-----------------------------------");

    System.out.println("new image: ");
    for(int[] row: ans){
      for(int val: row){
        System.out.print(val + " ");
      }
      System.out.println();
    }
  }
}
