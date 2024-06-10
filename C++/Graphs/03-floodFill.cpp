#include <iostream>
#include <vector>
using namespace std;

// Flood Fill
ostream& operator<<(ostream &os, vector<vector<int>>& matrix){
  for(auto &row: matrix){
    for(auto val: row){
      os << val << ' ';
    }
    cout << endl;
  }
  return os;
}

class Solution{
public:
  void dfs(int initColor, vector<vector<int>> &vis, int delrow[], int delcol[],
  vector<vector<int>> &image, int row, int col, int newColor){
    vis[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();
    for(int i=0; i<4; i++){
      int newr = delrow[i] + row;
      int newc = delcol[i] + col;
      if(newr>=0 && newr<n && newc>=0 && newc<m && image[newr][newc]==initColor && vis[newr][newc]!=newColor){
        vis[newr][newc] = newColor;
        dfs(initColor, vis, delrow, delcol, image, newr, newc, newColor);
      }
    }
  }

  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor){
    int initColor = image[sr][sc];
    vector<vector<int>> vis(image);
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, -1, 0, 1};
    dfs(initColor, vis, delrow, delcol, image, sr, sc, newColor);
    return vis;
  }


};

int main(){

  vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
  int sr = 1;
  int sc = 2;
  int newColor = 2;
  Solution obj;
  vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
  cout << "old image: " << endl << image;
  cout << "-------------------------" << endl;
  cout << "new image: " << endl << ans;

  return 0;
}
