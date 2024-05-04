#include <iostream>
#include <vector>
using namespace std;
/************************Grid*************************/
class Solution{
private:
  int mod = 1000000007;
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  int helper1(int i, int j, vector<vector<int>>& mat){
    if(i<0 || j<0 || mat[i][j]==-1) return 0;
    if(i==0 && j==0) return 1;

    int left = helper1(i, j-1, mat);
    int right = helper1(i-1, j, mat);

    return left+right;
  }

  int mazeObstacles1(int n, int m, vector<vector<int>> &mat){
    return helper1(n-1, m-1, mat);
  }

  /* ------------------------------------------------------------------- */
  //Memoization
  int helper2(int i, int j, vector<vector<int>>& mat, vector<vector<int>> &dp){
    if(i<0 || j<0 || mat[i][j] == -1) return 0;
    if(i==0 && j==0) return 1;

    if(dp[i][j] != -1) return dp[i][j]%mod;

    int left = helper2(i, j-1, mat, dp);
    int up = helper2(i-1, j, mat, dp);

    return dp[i][j] = (left+up)%mod;
  }

  int mazeObstacles2(int n, int m, vector<vector<int>> &mat){
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return helper2(n-1, m-1, mat, dp);
  }

  /* ------------------------------------------------------------------- */
  //Tabulation
  int mazeObstacles3(int n, int m, vector<vector<int>> &mat){
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(i==0 && j==0){
          dp[i][j] = 1;
        }else if(mat[i][j] == -1){
          dp[i][j] = 0;
        }else{
          int left=0, up=0;
          if(j>0) left = dp[i][j-1];
          if(i>0) up = dp[i-1][j];
          dp[i][j] = (left+up)%mod;
        }
      }
    }
    return dp[n-1][m-1]%mod;
  }

  /* ------------------------------------------------------------------- */
  //Space Optimization
  int mazeObstacles4(int n, int m, vector<vector<int>> &mat){
    vector<int> prev(m+1, -1);
    for(int i=0; i<n; i++){
      vector<int> current(m+1, -1);
      for(int j=0; j<m; j++){
        if(i==0 && j==0){
          current[j] = 1;
        }else if(mat[i][j] == -1){
          current[j] = 0;
        }else{
          int left = 0, up = 0;
          if(j>0) left = current[j-1];
          if(i>0) up = prev[j];

          current[j] = (left+up)%mod;
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
  vector<vector<int>> matrix = { {0, 0, 0 }, {0, -1, 0 }, {0, 0, 0} };
  int n = matrix.size();
  int m = matrix[0].size();
  cout << "The matrix is: " << endl << matrix << endl;
  Solution obj;
  int ans = obj.mazeObstacles4(m, n, matrix);
  cout << "The total number of unique paths from the top cell to bottom cell is: " << ans;
}
