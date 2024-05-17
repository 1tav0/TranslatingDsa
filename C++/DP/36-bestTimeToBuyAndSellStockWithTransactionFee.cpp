#include <iostream>
#include <vector>
using namespace std;
/************************Stocks*************************/
// we are given an array list 'prices'
// where PRICES[i] denotes the price of a given stock on the i-th day.
// Rahul can buy one stock at a time, and he must sell it before buying stock on another day.
// The entire transaction of selling and buying the stock requires some transaction fee, given as 'fee'.
// Find the maximum profit Rahul can achieve by trading on the stocks
class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  int helper1(int ind, int buy, vector<int>& prices, int n, int fee){
    if(ind == n) return 0;

    int profit = 0;
    if(buy){
      profit = max(-prices[ind] + helper1(ind+1, 0, prices, n, fee), 0 + helper1(ind+1, 1, prices, n, fee));
    }else{
      profit = max(prices[ind] - fee + helper1(ind+1, 1, prices, n, fee), 0 + helper1(ind+1, 0, prices, n, fee));
    }
    return profit;
  }

  int maximumProfit1(vector<int> &prices, int n, int fee){
    return helper1(0, 1, prices, n, fee);
  }
  /* ------------------------------------------------------------------- */
  //Memoization
  int helper2(int ind, int buy, vector<int>& prices, int n, int fee, vector<vector<int>> &dp){
    if(ind == n) return 0;

    if(dp[ind][buy] != -1) return dp[ind][buy];
    int profit = 0;
    if(buy){
      profit = max(-prices[ind] + helper2(ind+1, 0, prices, n, fee, dp), 0 + helper2(ind+1, 1, prices, n, fee, dp));
    }else{
      profit = max(prices[ind] - fee + helper2(ind+1, 1, prices, n, fee, dp), 0 + helper2(ind+1, 0, prices, n, fee, dp));
    }
    return dp[ind][buy] = profit;
  }

  int maximumProfit2(vector<int> &prices, int n, int fee){
    vector<vector<int>> dp(n+1, vector<int>(2, -1));
    return helper2(0, 1, prices, n, fee, dp);
  }
  /* -------------------------------Version 1------------------------------------ */
  //Tabulation
  int maximumProfit3(vector<int> &prices, int n, int fee){
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    for(int ind=n-1; ind>=0; ind--){
      for(int buy=0; buy<=1; buy++){
        int profit = 0;
        if(buy){
          profit = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
        }else{
          profit = max(prices[ind] - fee + dp[ind+1][1], 0 + dp[ind+1][0]);
        }
        dp[ind][buy] = profit;
      }
    }
    return dp[0][1];
  }
  /* -------------------------------Version 2------------------------------------ */
  //Tabulation

  /* ------------------------------------------------------------------- */
  //Space optimization
  int maximumProfit3(vector<int> &prices, int n, int fee){
    vector<int> ahead(2, 0);
    vector<int> current(2, 0);
    for(int ind=n-1; ind>=0; ind--){
      for(int buy=0; buy<=1; buy++){
        int profit = 0;
        if(buy){
          profit = max(-prices[ind] + ahead[0], 0 + ahead[1]);
        }else{
          profit = max(prices[ind] - fee + ahead[1], 0 + ahead[0]);
        }
        current[buy] = profit;
      }
      ahead = current;
    }
    return ahead[1];
  }
};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){

  return 0;
}
