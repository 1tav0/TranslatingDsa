#include <iostream>
#include <vector>
using namespace std;
/************************Grid*************************/
class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  //tc - 3`n //3 options every time
  //sc - O(n) recursion stack space
  int helper1(int i, int j, vector<vector<int>>& matrix){
    int m = matrix[0].size();
    if(j<0 || j>=m) return -1e9;
    if(i == 0) return matrix[i][j];

    int up = matrix[i][j] + helper1(i-1, j, matrix);
    int leftDigUp = matrix[i][j] + helper1(i-1, j-1, matrix);
    int rightDigUp = matrix[i][j] + helper1(i-1, j+1, matrix);

    return max(up, max(leftDigUp, rightDigUp));
  }
  int getMaxPathSum1(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = -1e9;
    for(int j=0; j<m; j++){
      maxi = max(maxi, helper1(n-1, j, matrix));
    }
    return maxi;
  }

  /* ------------------------------------------------------------------- */
  //Memoization
  //tc - O(nxm) number of states at worst case scenerio
  //sc - O(nxm) + O(n) dp array + stack space
  int helper2(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
    int m = matrix[0].size();
    if(j<0 || j>=m) return -1e9;
    if(i == 0) return matrix[i][j];

    if(dp[i][j] != -1) return dp[i][j];

    int up = matrix[i][j] + helper2(i-1, j, matrix, dp);
    int leftDigUp = matrix[i][j] + helper2(i-1, j-1, matrix, dp);
    int rightDigUp = matrix[i][j] + helper2(i-1, j+1, matrix, dp);

    return dp[i][j] = max(up, max(leftDigUp, rightDigUp));
  }

  int getMaxPathSum2(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    int maxi = -1e9;
    for(int j=0; j<m; j++){
      maxi = max(maxi, helper2(n-1, j, matrix, dp));
    }
    return maxi;
  }

  /* ------------------------------------------------------------------- */
  //Tabulation
  //tc - O(nxm) + O(n)
  //sc - O(nxm)
  int getMaxPathSum3(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    for(int j=0; j<m; j++){
      dp[0][j] = matrix[0][j];
    }

    for(int i=1; i<n; i++){
      for(int j=0; j<m; j++){
        int up = matrix[i][j] + dp[i-1][j];

        int leftDigUp = matrix[i][j];
        if(j-1>=0) leftDigUp += dp[i-1][j-1];
        else leftDigUp += -1e9;

        int rightDigUp = matrix[i][j];
        if(j+1<m) rightDigUp += dp[i-1][j+1];
        else rightDigUp += -1e9;

        dp[i][j] = max(up, max(leftDigUp, rightDigUp));
      }
    }

    int maxi = -1e9;
    for(int j=0; j<m; j++){
      maxi = max(maxi, dp[n-1][j]);
    }

    return maxi;
  }

  /* ------------------------------------------------------------------- */
  //Space Optimization
  //tc - O(nxm) + O(m)
  //sc - O(n) no more dp auxilary array
  int getMaxPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev(m+1, -1);
    for(int j=0; j<m; j++) prev[j] = matrix[0][j];

    for(int i=1; i<n; i++){
      vector<int> current(m+1, -1);
      for(int j=0; j<m; j++){

        int up = matrix[i][j] + prev[j];

        int leftDigUp = matrix[i][j];
        if(j-1>=0) leftDigUp += prev[j-1];
        else leftDigUp += -1e9;

        int rightDigUp = matrix[i][j];
        if(j+1<m) rightDigUp += prev[j+1];
        else rightDigUp += -1e9;

        current[j] = max(up, max(leftDigUp, rightDigUp));
      }
      prev = current;
    }

    int maxi = -1e9;
    for(int j=0; j<m; j++){
      maxi = max(maxi, prev[j]);
    }
    return maxi;
  }
};

ostream& operator<<(ostream& os, vector<vector<int>> matrix){
  int n = matrix.size();
  int m = matrix[0].size();
  for(int row=0; row<n; row++){
    for(int column=0; column<m; column++){
      os << matrix[row][column] << " ";
    }
    os << endl;
  }
  return os;
}

int main(){
  vector<vector<int>> matrix = { {1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1} };
  // int n = triangle.size();
  cout << "The matrix is: " << endl << matrix << endl;
  Solution obj;
  int ans = obj.getMaxPathSum2(matrix);
  cout << "The maximum path sum will be: " << ans;
}
