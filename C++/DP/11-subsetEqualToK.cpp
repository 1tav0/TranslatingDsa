#include <iostream>
#include <vector>
using namespace std;
/************************Subsequences*************************/
class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  //tc - O(2^n) pick and not pick every step
  //sc - O(n) recursion auxilary stack space
  bool helper1(int ind, int target, vector<int> &arr){
    if(target == 0) return true;
    if(ind == 0){
      return (arr[0] == target);
    }

    int notPick = helper1(ind-1, target, arr);
    int pick = false;
    if(target >= arr[ind]){
      pick = helper1(ind-1, target-arr[ind], arr);
    }
    return notPick | pick;
  }

  bool subsetSumToK1(int n, int k, vector<int> &arr){
    return helper1(n-1, k, arr);
  }

  /* ------------------------------------------------------------------- */
  //Memoization
  //tc - O(nxtarget) number of states at worst case scenerio has 3*3 states
  //sc - O(nxtarget) + O(n) dp array + auxilary stack space
  bool helper2(int ind, int target, vector<int>& arr, vector<vector<bool>> &dp){
    if(target == 0) return true;
    if(ind == 0) return (arr[0]==target);

    if(dp[ind][target] != false) return dp[ind][target];

    bool notPick = helper2(ind-1, target, arr, dp);
    bool pick = false;
    if(arr[ind] <= target){
      pick = helper2(ind-1, target-arr[ind], arr, dp);
    }

    return dp[ind][target] = notPick | pick;
  }

  bool subsetSumToK2(int n, int k, vector<int> &arr){
    vector<vector<bool>> dp(n+1, vector<bool>(k+1, false));
    return helper2(n-1, k, arr, dp);
  }

  /* ------------------------------------------------------------------- */
  //Tabulation
  //tc - O(nxtarget)
  //sc - O(nxtarget)
  bool subsetSumToK3(int n, int k, vector<int> &arr){
    vector<vector<bool>> dp(n+1, vector<bool>(k+1, false));
    for(int i=0; i<n; i++){
      dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for(int i=1; i<n; i++){
      for(int target=1; target<=k; target++){
        bool notPick = dp[i-1][target];
        bool pick = false;
        if(arr[i] <= target){
          pick = dp[i-1][target-arr[i]];
        }

        dp[i][target] = notPick | pick;
      }
    }
    return dp[n-1][k];
  }

  /* ------------------------------------------------------------------- */
  //Space optimization
  //tc - O(nxtarget)
  //sc - O(target) no 2d array
  bool subsetSumToK4(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, false);
    vector<bool> current(k+1, false);
    prev[0] = true;
    current[0] = true;
    prev[arr[0]] = true;
    for(int ind=1; ind<n; ind++){
      for(int target=1; target<=k; target++){
        bool notPick = prev[target];
        bool pick = false;
        if(arr[ind] <= target){
          pick = prev[target-arr[ind]];
        }
        current[target] = notPick | pick;
      }
      prev = current;
    }
    return prev[k];
  }

};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> arr = {4, 3, 2, 1};
  cout << "The given array is: " << arr << endl;
  int n = arr.size();
  int k = 8;
  Solution obj;
  bool ans = obj.subsetSumToK4(n, k, arr);
  cout << "Does there exist a subset with sum equal to " << k << " in the array ? " << ans;
}
