#include <iostream>
#include <vector>
using namespace std;
/************************Subsequences*************************/
// we are given two arrays a profit and a weight arrays
// we have a knapsack with weight limit
// we need to get the maximum profit possible if we are able
// to take an item multiple times
class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  //tc - exponential not 2`n bc standing at same index
  //sc - O(w)
  int helper1(int ind, int W, vector<int> &profit, vector<int> &weight){
    if(ind == 0){
        return ((int)W/weight[ind]*profit[ind]);
    }

    int notPick = helper1(ind-1, W, profit, weight);
    int pick = -1e9;
    if(weight[ind] <= W){
      pick = profit[ind] + helper1(ind, W-weight[ind], profit, weight);
    }
    return max(notPick, pick);
  }
  int unboundedKnapsack1(int n, int w, vector<int> &profit, vector<int> &weight){
    return helper1(n-1, w, profit, weight);
  }
  /* ------------------------------------------------------------------- */
  //Memoization
  int helper2(int ind, int W, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp){
    if(ind == 0){
      return ((int)W/weight[ind]*profit[ind]);
    }

    if(dp[ind][W] != -1) return dp[ind][W];

    int notPick = helper2(ind-1, W, profit, weight, dp);
    int pick = -1e9;
    if(weight[ind] <= W){
      pick = profit[ind] + helper2(ind, W-weight[ind], profit, weight, dp);
    }
    return dp[ind][W] = max(notPick, pick);
  }

  int unboundedKnapsack2(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
    return helper2(n-1, w, profit, weight, dp);
  }

  /* ------------------------------------------------------------------- */
  //Tabulation
  int unboundedKnapsack3(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
    for(int W=weight[0]; W<=w; W++){
      dp[0][W] = (int)W/weight[0]*profit[0];
    }
    for(int ind=1; ind<n; ind++){
      for(int W=0; W<=w; W++){
        int notPick = dp[ind-1][W];
        int pick = -1e9;
        if(weight[ind] <= W){
          pick = profit[ind] + dp[ind][W-weight[ind]];
        }
        dp[ind][W] = max(notPick, pick);
      }
    }
    return dp[n-1][w];
  }

  /* ------------------------------------------------------------------- */
  //Space optimization
  int unboundedKnapsack4(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int> prev(w+1, 0);
    vector<int> current(w+1, 0);
    for(int W=weight[0]; W<=w; W++){
      prev[W] = (int)W/weight[0]*profit[0];
    }
    for(int ind=1; ind<n; ind++){
      for(int W=0; W<=w; W++){
        int notPick = prev[W];
        int pick = -1e9;
        if(weight[ind] <= W){
          pick = profit[ind] + current[W-weight[ind]];
        }
        current[W] = max(notPick, pick);
      }
      prev = current;
    }
    return prev[w];
  }

};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> profit = { 5, 11, 13 };
  vector<int> weight = { 2, 4, 6 };
  int n = profit.size();
  int w = 10;
  // 1 item of weight 6 and 1 item of weight 4.
  // 1 item of weight 6 and 2 items of weight 2.
  // 2 items of weight 4 and 1 item of weight 2.
  // 5 items of weight 2.
  //
  // The maximum profit will be from case 3 = 11 + 11 + 5 = 27.
  // Therefore maximum profit = 27.
  cout << "The profit array is: " << profit << endl;
  cout << "The weight array is: " << weight << endl;
  Solution obj;
  int ans = obj.unboundedKnapsack4(n, w, profit, weight);
  cout << "The maximum profit we can get if we fill the unbounded knapsack is: " << ans;
  return 0;
}
