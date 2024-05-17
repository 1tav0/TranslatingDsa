#include <iostream>
#include <vector>
using namespace std;
/************************Stocks*************************/
// we are given an array list 'prices'
// where PRICES[i] denotes the price of a given stock on the i-th day.
// You don't want to do more than 2 transactions.
// Find the maximum profit that you can earn from these transactions.

class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  int helper1(int ind, int buy, int cap, vector<int> &prices, int n){
    if(cap < 0) return 0;
    if(ind == n) return 0;

    int profit = 0;
    if(buy){
      profit = max(-prices[ind] + helper1(ind+1, 0, cap, prices, n), 0 + helper1(ind+1, 1, cap, prices, n));
    }else{
      profit = max(prices[ind] + helper1(ind+1, 1, cap-1, prices, n), 0 + helper1(ind+1, 0, cap, prices, n));
    }
    return profit;
  }
  int maxProfit2(vector<int>& prices){
    int n = prices.size();
    return helper1(0, 1, 1, prices, n);
  }

  /* ------------------------------------------------------------------- */
  //Memoization

  int helper2(int ind, int buy, vector<int> &prices, int cap, vector<vector<vector<int>>> &dp){
    int n = prices.size();
    if(ind == n || cap == 0) return 0;

    if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

    int profit = 0;
    if(buy){
      profit = max(-prices[ind] + helper2(ind+1, 0, prices, cap, dp), 0 + helper2(ind+1, 1, prices, cap, dp));
    }else{
      profit = max(prices[ind] + helper2(ind+1, 1, prices, cap-1, dp), 0 + helper2(ind+1, 0, prices, cap, dp));
    }

    return dp[ind][buy][cap] = profit;
  }

  int maxProfit2(vector<int>& prices){
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
    return helper2(0, 1, prices, 2, dp);
  }

  /* ------------------------------------------------------------------- */
  //Tabulation
  int maxProfit3(vector<int>& prices){
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    for(int ind=n-1; ind>=0; ind--){
      for(int buy=0; buy<=1; buy++){
        for(int cap=1; cap<=2; cap++){
          int profit = 0;
          if(buy){
            profit = max(-prices[ind] + dp[ind+1][0][cap], 0 + dp[ind+1][1][cap]);
          }else{
            profit = max(prices[ind] + dp[ind+1][1][cap-1], 0 + dp[ind+1][0][cap]);
          }
          dp[ind][buy][cap] = profit;
        }
      }
    }
    return dp[0][1][2];
  }

  /* ------------------------------------------------------------------- */
  //Space optimization
  int maxProfit4(vector<int>& prices){
    int n = prices.size();
    vector<vector<int>> ahead(2, vector<int>(3, 0));
    vector<vector<int>> current(2, vector<int>(3, 0));
    for(int ind=n-1; ind>=0; ind--){
      for(int buy=0; buy<=1; buy++){
        for(int cap=1; cap<=2; cap++){
          int profit = 0;
          if(buy){
            profit = max(-prices[ind] + ahead[0][cap], 0 + ahead[1][cap]);
          }else{
            profit = max(prices[ind] + ahead[1][cap-1], 0 + ahead[0][cap]);
          }
          current[buy][cap] = profit;
        }
      }
      ahead = current;
    }
    return ahead[1][2];
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
