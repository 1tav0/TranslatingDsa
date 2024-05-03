#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  int helper1(int i, int j, vector<vector<int>> &triangle, int n){
    if(i == n-1){
      return triangle[i][j];
    }

    int down = triangle[i][j] + helper1(i+1, j, triangle, n);
    int digDown = triangle[i][j] + helper1(i+1, j+1, triangle, n);

    return min(down, digDown);
  }
  int minimumPathSum1(vector<vector<int>> &triangle, int n){
    return helper1(0, 0, triangle, n);
  }

  /* ------------------------------------------------------------------- */
  //Memoization
  int helper2(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>>& dp){
    if(i == n-1){
      return triangle[i][j];
    }

    if(dp[i][j] != -1) return dp[i][j];

    int down = triangle[i][j] + helper2(i+1, j, triangle, n, dp);
    int digDown = triangle[i][j] + helper2(i+1, j+1, triangle, n, dp);

    return dp[i][j] = min(down, digDown);
  }
  int minimumPathSum2(vector<vector<int>> &triangle, int n){
    vector<vector<int>> dp(n+1, vector<int>(n, -1));
    return helper2(0, 0, triangle, n, dp);
  }

  /* ------------------------------------------------------------------- */
  //Tabulation
  int minimumPathSum3(vector<vector<int>> &triangle, int n){
    vector<vector<int>> dp(n+1, vector<int>(n, -1));
    for(int j=0; j<n; j++) dp[n-1][j] = triangle[n-1][j];
    for(int i=n-2; i>=0; i--){
      for(int j=i; j>=0; j--){
        int down = triangle[i][j] + dp[i+1][j];
        int digDown = triangle[i][j] + dp[i+1][j+1];
        dp[i][j] = min(down, digDown);
      }
    }
    return dp[0][0];
  }

  /* ------------------------------------------------------------------- */
  //Space Optimization
  int minimumPathSum4(vector<vector<int>> &triangle, int n){
    vector<int> current(n+1, 0);
    vector<int> ahead(n+1, 0);
    for(int j=0; j<n; j++) current[j] = triangle[n-1][j];
    for(int i=n-1; i>=0; i--){
      for(int j=i; j>=0; j--){
        int down = triangle[i][j] + ahead[j];
        int digDown = triangle[i][j] + ahead[j+1];
        current[j] = min(down, digDown);
      }
      ahead = current;
    }
    return ahead[0];
  }

};

ostream& operator<<(ostream& os, vector<vector<int>> matrix){
  int n = matrix.size();
  // int m = matrix[0].size();
  for(int row=0; row<n; row++){
    for(int column=0; column<matrix[row].size(); column++){
      os << matrix[row][column] << " ";
    }
    os << endl;
  }
  return os;
}

int main(){
  vector<vector<int>> triangle = { {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3} };
  int n = triangle.size();
  cout << "The triangle is: " << endl << triangle << endl;
  Solution obj;
  int ans = obj.minimumPathSum4(triangle, n);
  cout << "For the given triangle array the minimum sum path is: " << ans;
}
