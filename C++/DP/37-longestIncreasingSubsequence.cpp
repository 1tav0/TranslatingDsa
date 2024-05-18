#include <iostream>
#include <vector>
using namespace std;
/************************LIS*************************/
// we are given an array with N elements
// find the longest subsequence from the array
// but all the elements in the subsequence are in increasing order
// each term in the sequence is larger than the preceding term
// [5, 4, 11, 1, 16, 8]
// LIS -> Length of longest subsequence is 3 i.e. [5, 11, 16] or [4, 11, 16].
class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  //tc - 2`n
  /* version 1 */
  int helper(int ind, int arr[], int prev, int n){
    if(ind == n) return 0;

    int notPick = 0 + helper(ind+1, arr, prev, n);
    int pick = -1e9;
    if(prev == -1 || arr[prev] < arr[ind]){
        pick = 1 + helper(ind+1, arr, ind, n);
    }

    return max(notPick, pick);
  }

  int longestIncreasingSubsequence(int arr[], int n){
      return helper(0, arr, -1, n);
  }

  /* version 2 */
  int helper1(int ind, int arr[], int prev, int n){
    if(ind == n) return 0;

    int len = 0 + helper1(ind+1, arr, prev, n);
    if(prev == -1 || arr[prev] < arr[ind]){
        len = max(len, 1 + helper1(ind+1, arr, ind, n));
    }

    return len;
  }

  int longestIncreasingSubsequence1(int arr[], int n){
      return helper(0, arr, -1, n);
  }

  /* ------------------------------------------------------------------- */
  //Memoization
  //tc - O(nxn)
  //sc - O(nxn) + O(n)
  int helper2(int ind, int arr[], int prev, int n, vector<vector<int>> &dp){
    if(ind == n) return 0;

    if(dp[ind][prev+1] != -1) return dp[ind][prev+1];

    int notPick = 0 + helper2(ind+1, arr, prev, n, dp);
    int pick = -1e9;
    if(prev == -1 || arr[ind] > arr[prev]){
      pick = 1 + helper2(ind+1, arr, ind, n, dp);
    }

    return dp[ind][prev+1] = max(notPick, pick);
  }

  int longestIncreasingSubsequence2(int arr[], int n){
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return helper2(0, arr, -1, n, dp);
  }
  /* --------------------------version1----------------------------------------- */
  //Tabulation
  //tc - O(n`2)
  //sc - O(n)
  int longestIncreasingSubsequence3(int arr[], int n){
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int ind=n-1; ind>=0; ind--){
      for(int prev=ind-1; prev>=-1; prev--){
        int notPick = 0 + dp[ind+1][prev+1];
        int pick = -1e9;
        if(prev == -1 || arr[ind] > arr[prev]){
          pick = 1 + dp[ind+1][ind+1];
        }
        dp[ind][prev] = max(notPick, pick);
      }
    }
    return dp[0][0];
  }
  /* ------------------------------------------------------------------- */
  //Space optimization
  //tc - O(n`2)
  //sc - O(n)x2
  int longestIncreasingSubsequence3(int arr[], int n){
    vector<int> ahead(n+1, 0);
    for(int ind=n-1; ind>=0; ind--){
      vector<int> current(n+1, 0);
      for(int prev=ind-1; prev>=-1; prev--){
          int notPick = ahead[prev+1];
          int pick = -1e9;
          if(prev==-1 || arr[ind] > arr[prev]){
            pick = 1 + ahead[ind+1];
          }
          current[prev+1] = max(notPick, pick);
      }
      ahead = current;
    }
    return ahead[-1+1];
  }
  /* --------------------------version2------------------------------------ */
  //Tabulation
  //tc - O(n`2)
  //sc - O(n)
  int longestIncreasingSubsequence3(int arr[], int n){
    vector<int> dp(n+1, 1);
    int maxi = 0;
    for(int ind=0; ind<n; ind++){
      for(int prev=0; prev<ind; prev++){
        if(arr[prev] < arr[ind]){
          dp[ind] = max(dp[ind], 1 + dp[prev]);
        }
      }
      maxi = max(maxi, dp[ind]);
    }
    return maxi;
  }
/* ------------------------------------------------------------------- */
  //binarysearch
  //tc - O(nxlog(n))
  //sc - O(n)
  int longestIncreasingSubsequence3(int arr[], int n){
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for(int ind=0; ind<n; ind++){
      if(arr[ind] > temp.back()){
        temp.push_back(arr[ind]);
        len++;
      }else{
        int i = lower_bound(temp.begin(), temp.end(), arr[ind]) - temp.begin();
        temp[i] = arr[ind];
      }
    }
    return len;
  }
};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){

}
