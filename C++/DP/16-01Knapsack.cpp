#include <iostream>
#include <vector>
using namespace std;
/************************Subsequences*************************/
// in this problem a thief is trying to steal as much as possible but
// his knapsack has a weight limit on how much it can carry 
class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  //tc - O(2`n)
  //sc O(n) a.s.s
  int helper1(int ind, int maxWeight, vector<int> weight, vector<int> value){
    if(ind == 0){
      if(weight[ind] <= maxWeight){
        return value[ind];
      }else{
        return 0;
      }
    }

    int notPick = helper1(ind-1, maxWeight, weight, value);
    int pick = -1e9;
    if(weight[ind] <= maxWeight){
      pick = value[ind] + helper1(ind-1, maxWeight-weight[ind], weight, value);
    }
    return max(notPick, pick);
  }

  int knapsack1(vector<int> weight, vector<int> value, int n, int maxWeight){
    return helper1(n-1, maxWeight, weight, value);
  }
  /* ------------------------------------------------------------------- */
  //Memoization
  //tc - O(nxm)
  //sc - O(nxm) + O(n) a.s.s
  int helper2(int ind, int maxWeight, vector<int> weight, vector<int> value, vector<vector<int>> &dp){
    if(ind == 0){
      if(weight[ind] <= maxWeight) return value[ind];
      else return 0;
    }
    if(dp[ind][maxWeight] != -1) return dp[ind][maxWeight];

    int notPick = helper2(ind-1, maxWeight, weight, value, dp);
    int pick = -1e9;
    if(weight[ind] <= maxWeight){
      pick = value[ind] + helper2(ind-1, maxWeight-weight[ind], weight, value, dp);
    }
    return dp[ind][maxWeight] = max(notPick, pick);
  }

  int knapsack2(vector<int> weight, vector<int> value, int n, int maxWeight)
  {
    vector<vector<int>> dp(n+1, vector<int>(maxWeight+1, -1));
  	return helper2(n-1, maxWeight, weight, value, dp);
  }
  /* ------------------------------------------------------------------- */
  //Tabulation
  int knapsack3(vector<int> weight, vector<int> value, int n, int maxWeight)
  {
    vector<vector<int>> dp(n+1, vector<int>(maxWeight+1, 0));
    for(int W=weight[0]; W<=maxWeight; W++) dp[0][W] = value[0];
    for(int ind=1; ind<n; ind++){
      for(int W=0; W<=maxWeight; W++){
        int notPick = dp[ind-1][W];
        int pick = -1e9;
        if(weight[ind] <= W){
          pick = value[ind] + dp[ind-1][W-weight[ind]];
        }
        dp[ind][W] = max(notPick, pick);
      }
    }
    return dp[n-1][maxWeight];
  }

  /* ------------------------------------------------------------------- */
  //Space optimization
  int knapsack4(vector<int> weight, vector<int> value, int n, int maxWeight)
  {
    vector<int> prev(maxWeight+1, 0);
    vector<int> current(maxWeight+1, 0);
    for(int W=weight[0]; W<=maxWeight; W++) prev[W] = value[0];
    for(int ind=1; ind<n; ind++){
      for(int W=0; W<=maxWeight; W++){
        int notPick = prev[W];
        int pick = -1e9;
        if(weight[ind] <= W){
          pick = value[ind] + prev[W-weight[ind]];
        }
        current[W] = max(notPick, pick);
      }
      prev = current;
    }
    return prev[maxWeight];
  }

};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> weight = { 1, 2, 4, 5 };
  vector<int> value = { 5, 4, 8, 6 };
  int n = weight.size();
  int maxWeight = 5;
  Solution obj;
  int ans = obj.knapsack4(weight, value, n, maxWeight);
  cout << "The maximum value that a thief can steal with the maximum weight that his knapsack can carry is " << ans << endl;
  return 0;
}
