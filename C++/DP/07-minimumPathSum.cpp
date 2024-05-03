#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  int helper1(int i, int j, vector<vector<int>> &grid){
    if(i<0 || j<0) return 1e9;
    if(i==0 && j==0) return grid[i][j];

    int left = grid[i][j] + helper1(i, j-1, grid);
    int right = grid[i][j] + helper1(i-1, j, grid);

    return min(left, right);
  }
  int minSumPath1(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    return helper1(n-1, m-1, grid);
  }

  /* ------------------------------------------------------------------- */
  //Memoization
  int helper2(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(i<0 || j<0) return 1e9;
    if(i==0 && j==0) return grid[i][j];

    if(dp[i][j] != -1) return dp[i][j];

    int left = grid[i][j] + helper2(i, j-1, grid, dp);
    int right = grid[i][j] + helper2(i-1, j, grid, dp);

    return dp[i][j] = min(left, right);
  }
  int minSumPath2(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return helper2(n-1, m-1, grid, dp);
  }

  /* ------------------------------------------------------------------- */
  //Tabulation
  int minSumPath3(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(i==0 && j==0){
          dp[i][j] = grid[i][j];
        }else{
          int left=1e9, up=1e9;
          if(j>0) left = grid[i][j] + dp[i][j-1];
          if(i>0) up = grid[i][j] + dp[i-1][j];
          dp[i][j] = min(left, up);
        }
      }
    }
    return dp[n-1][m-1];
  }

  /* ------------------------------------------------------------------- */
  //Space Optimization
  int minSumPath4(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m+1, -1);
    for(int i=0; i<n; i++){
      vector<int> current(m+1, -1);
      for(int j=0; j<m; j++){
        if(i==0 && j==0){
          current[j] = grid[i][j];
        }else{
          int left=1e9, up=1e9;
          if(j>0) left = grid[i][j] + current[j-1];
          if(i>0) up = grid[i][j] + prev[j];
          current[j] = min(left, up);
        }
      }
      prev = current;
    }
    return prev[m-1];
  }
};

ostream& operator<<(ostream& os, vector<vector<int>> matrix){
  int n = matrix.size();
  int m = matrix[0].size();
  for(int row=0; row<n; row++){
    for(int column=0; column<m; column++){
      os << matrix[row][column] << " " ;
    }
    os << endl;
  }
  return os;
}

int main(){
  vector<vector<int>> matrix = { {5, 9, 6}, {11, 5, 2 } };
  cout << "The matrix is: " << endl << matrix << endl;
  Solution obj;
  int ans = obj.minSumPath4(matrix);
  cout << "The minimum sum of the cost of all the numbers along the path is: " << ans;
}
