#include <iostream>
#include <vector>
using namespace std;
/************************Grid*************************/
class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  int helper1(int i, int j){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;

    int left = helper1(i, j-1);
    int up = helper1(i-1, j);

    return left + up;
  }

  int uniquePaths1(int m, int n){
    return helper1(m-1, n-1);
  }

  /* ------------------------------------------------------------------- */
  //Memoization
  int helper2(int i, int j, vector<vector<int>>& dp){
    if(i<0 || j<0) return 0;
    if(i==0 && j==0) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    int left = helper2(i, j-1, dp);
    int right = helper2(i-1, j, dp);

    return dp[i][j] = left + right;
  }

  int uniquePaths2(int m, int n){
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    return helper2(m-1, n-1, dp);
  }

  /* ------------------------------------------------------------------- */
  //Tabulation

  int uniquePaths3(int m, int n){
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
        if(i == 0 && j == 0){
          dp[i][j] = 1;
        }else{
          int left = 0, up = 0;
          if(j>0) left = dp[i][j-1];
          if(i>0) up = dp[i-1][j];

          dp[i][j] = left + up;
        }
      }
    }
    return dp[m-1][n-1];
  }

  /* ------------------------------------------------------------------- */
  //Space Optimization
  int uniquePaths4(int m, int n){
    vector<int> prev(n+1, -1);
    for(int i=0; i<m; i++){
      vector<int> current(n+1, -1);
      for(int j=0; j<n; j++){
        if(i==0 && j==0){
          current[j] = 1;
        }else{
          int left=0, up=0;
          if(j>0) left = current[j-1];
          if(i>0) up = prev[j];

          current[j] = left+up;
        }
      }
      prev = current;
    }
    return prev[n-1];
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
  vector<vector<int>> matrix = { {3, 2}, {1, 6} };
  int m = matrix.size();
  int n = matrix[0].size();
  cout << "The matrix is: " << endl << matrix << endl;
  Solution obj;
  int ans = obj.uniquePaths4(m, n);
  cout << "The total number of unique paths from the cell is: " << ans;
}
