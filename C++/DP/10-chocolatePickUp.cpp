#include <iostream>
#include <vector>
using namespace std;
/************************3D Grid*************************/
class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  //tc - O(3`nx3`n) //3 options every time
  //sc - O(n) recursion auxilary stack space
  int helper1(int i, int j1, int j2, int row, int col, vector<vector<int>> &grid){
    if(j1<0 || j2<0 || j1>=col || j2>=col) return -1e9;
    if(i == row-1){
      if(j1 == j2){
        return grid[i][j1];
      }else{
        return grid[i][j1] + grid[i][j2];
      }
    }

    int maxi = -1e9;
    for(int dj1=-1; dj1<=1; dj1++){
      for(int dj2=-1; dj2<=1; dj2++){
        int value = 0;
        if(j1 == j2){
          value = grid[i][j1];
        }else{
          value = grid[i][j1] + grid[i][j2];
        }

        value += helper1(i+1, j1+dj1, j2+dj2, row, col, grid);
        maxi = max(maxi, value);
      }
    }
    return maxi;
  }

  int maximumChocolates1(int r, int c, vector<vector<int>> &grid){
    return helper1(0, 0, c-1, r, c, grid);
  }

  /* ------------------------------------------------------------------- */
  //memoization
  //tc - O(nxmxm)x9 number of states at worst case scenerio has 3*3 states
  //sc - O(nxmxm) + O(n) dp array + auxilary stack space
  int helper2(int i, int j1, int j2, int row, int col, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
    if(j1<0 || j2<0 || j1>=col || j2>=col) return -1e9;
    if(i == row-1){
      if(j1 == j2){
        return grid[i][j1];
      }else{
        return grid[i][j1] + grid[i][j2];
      }
    }

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    for(int dj1=-1; dj1<=1; dj1++){
      for(int dj2=-1; dj2<=1; dj2++){
        int value = 0;
        if(j1 == j2){
          value = grid[i][j1];
        }else{
          value = grid[i][j1] + grid[i][j2];
        }
        value += helper2(i+1, j1+dj1, j2+dj2, row, col, grid, dp);
        dp[i][j1][j2] = max(dp[i][j1][j2], value);
      }
    }
    return dp[i][j1][j2];
  }

  int maximumChocolates2(int r, int c, vector<vector<int>> &grid){
    vector<vector<vector<int>>> dp(r+1, vector<vector<int>>(c+1, vector<int>(c+1, -1)));
    return helper2(0, 0, c-1, r, c, grid, dp);
  }

  /* ------------------------------------------------------------------- */
  //Tabulation
  //tc - O(nxm) + O(n)
  //sc - O(nxm)
  int maximumChocolates3(int r, int c, vector<vector<int>> &grid){
    vector<vector<vector<int>>> dp(r+1, vector<vector<int>>(c+1, vector<int>(c+1, -1)));
    // take care of the base cases
    for(int j1=0; j1<c; j1++){
      for(int j2=0; j2<c; j2++){
        if(j1 == j2){
          dp[r-1][j1][j2] = grid[r-1][j1];
        }else{
          dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
      }
    }

    for(int i=r-2; i>=0; i--){
      for(int j1=0; j1<c; j1++){
        for(int j2=0; j2<c; j2++){
          int maxi = -1e9;
          for(int dj1=-1; dj1<=1; dj1++){
            for(int dj2=-1; dj2<=1; dj2++){
              int value = 0;
              if(j1 == j2){
                value = grid[i][j1];
              }else{
                value = grid[i][j1] + grid[i][j2];
              }
              // traverse the grid if is not outta bounds
              if(j1+dj1>=0 && j1+dj1<=c && j2+dj2>=0 && j2+dj2<=c){
                value += dp[i+1][j1+dj1][j2+dj2];
              }else{
                value += -1e9;
              }
              maxi = max(maxi, value);
            }
          }
          dp[i][j1][j2] = maxi;
        }
      }
    }
    return  dp[0][0][c-1];
  }

/* ------------------------------------------------------------------- */
  //space optimization
  //tc - O(n`3x3x3)
  //sc - O(nxm) no more dp auxilary stack space
  int maximumChocolates4(int r, int c, vector<vector<int>> &grid) {
    vector<vector<int>> current(r+1, vector<int>(c+1, -1));
    vector<vector<int>> ahead(r+1, vector<int>(c+1, -1));
    for(int j1=0; j1<c; j1++){
        for(int j2=0; j2<c; j2++){
            if(j1 == j2){
                ahead[j1][j2] = grid[r-1][j1];
            }else{
                ahead[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
            }
        }
    }

    for(int i=r-2; i>=0; i--){
        for(int j1=0; j1<c; j1++){
            for(int j2=0; j2<c; j2++){
                int maxi = -1e9;
                for(int dj1=-1; dj1<=1; dj1++){
                    for(int dj2=-1; dj2<=1; dj2++){
                        if(j1+dj1 >=0 && j1+dj1<c && j2+dj2>=0 && j2+dj2<c){
                            int value = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                            value += ahead[j1+dj1][j2+dj2];
                             maxi = max(maxi, value);
                        }
                    }
                }
                current[j1][j2] = maxi;
            }
        }
        ahead = current;
    }
    return ahead[0][c-1];
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
  vector<vector<int>> matrix = { {2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5} };
  int n = matrix.size();
  int m = matrix[0].size();
  cout << "The matrix is: " << endl << matrix << endl;
  Solution obj;
  int ans = obj.maximumChocolates4(n, m, matrix);
  cout << "The maximum number of chocolates Ninja can collect with the help of his friends will be: " << ans;
}
