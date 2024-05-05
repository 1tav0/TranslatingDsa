#include <iostream>
#include <vector>
using namespace std;
/************************Subsequences*************************/
class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  //tc - >>O(2`n) for every index we got, the opitons can go more than 2`n cuz is stands in the same index
  //sc - O(target) bigger than O(n)
  int helper1(int ind, vector<int> &arr, int targetSum){
    if(ind == 0){
      if(targetSum%arr[ind]==0) return targetSum/arr[ind];
      else return 1e9;
    }

    int notPick = helper1(ind-1, arr, targetSum);
    int pick = 1e9;
    if(arr[ind] <= targetSum){
      pick = 1 + helper1(ind, arr, targetSum-arr[ind]);
    }
    return min(notPick, pick);
  }

  int minimumElements1(vector<int> &arr, int targetSum){
    int n = arr.size();
    int ans = helper1(n-1, arr, targetSum);
    if(ans >= 1e9) return -1;
    return ans;
  }
  /* ------------------------------------------------------------------- */
  //Memoization
  //tc - O(nxTarget)
  //sc - O(nxtarget) + O(target) a.s.s
  int helper2(int ind, vector<int> &arr, int targetSum, vector<vector<int>> &dp){
    if(ind == 0){
      if(targetSum%arr[ind]==0) return targetSum/arr[ind];
      else return 1e9;
    }

    if(dp[ind][targetSum] != -1) return dp[ind][targetSum];

    int notPick = helper2(ind-1, arr, targetSum, dp);
    int pick = 1e9;
    if(arr[ind] <= targetSum){
      pick = 1 + helper2(ind, arr, targetSum-arr[ind], dp);
    }
    return dp[ind][targetSum] = min(notPick, pick);
  }

  int minimumElements2(vector<int> &arr, int targetSum){
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(targetSum+1, -1));
    int ans = helper2(n-1, arr, targetSum, dp);
    if(ans >= 1e9) return -1;
    return ans;
  }
  /* ------------------------------------------------------------------- */
  //Tabulation
  int minimumElements3(vector<int> &arr, int targetSum){
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(targetSum+1, -1));
    for(int x=0; x<=targetSum; x++){
      if(x%arr[0]==0) dp[0][x] = x/arr[0];
      else dp[0][x] = 1e9;
    }

    for(int ind=1; ind<n; ind++){
      for(int sum=0; sum<=targetSum; sum++){
        int notPick = dp[ind-1][sum];
        int pick = 1e9;
        if(arr[ind] <= sum){
          pick = 1 + dp[ind][sum-arr[ind]];
        }
        dp[ind][sum] = min(notPick, pick);
      }
    }
    int ans = dp[n-1][targetSum];
    if(ans >= 1e9) return -1;
    return ans;
  }

  /* ------------------------------------------------------------------- */
  //Space optimization
  int minimumElements4(vector<int> &arr, int targetSum){
    int n = arr.size();
    vector<int> prev(targetSum+1, 0);
    vector<int> current(targetSum+1, 0);
    for(int T=0; T<=targetSum; T++){
      if(T%arr[0] == 0) prev[T] = T/arr[0];
      else prev[T] = 1e9;
    }
    for(int ind=1; ind<n; ind++){
      for(int T=0; T<=targetSum; T++){
        int notPick = prev[T];
        int pick = 1e9;
        if(arr[ind] <= T){
          pick = 1 + current[T-arr[ind]];
        }
        current[T] = min(notPick, pick);
      }
      prev = current;
    }
    int ans = prev[targetSum];
    if(ans >= 1e9) return -1;
    return ans;
  }
};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> arr = { 1,2,3 };
  int n = arr.size();
  int targetSum = 7;
  cout << "The array is: " << arr << endl;
  Solution obj;
  int ans = obj.minimumElements1(arr, targetSum);
  cout << "The minimum number of elements you have to take to reach the target sum ";
  cout << targetSum << " is: " << ans;
  return 0;
}
