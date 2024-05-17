#include <iostream>
#include <vector>
using namespace std;
/************************Stocks*************************/
// we are given an array list 'prices'
// where PRICES[i] denotes the price of a given stock on the i-th day.
// calculate the maximum profit you can earn by trading stocks if you can only hold one stock at a time.
// After you sell your stock on the ‘i’th day, you can only buy another stock on ‘i + 2’ th day or later.

class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  int helper1(int ind, int buy, vector<int> &prices, int n){
    if(ind >= n) return 0; //the ind+2 will be out of bounds when n-1 if ind==n hence the ind>=n

    int profit = 0;
    if(buy){
      profit = max(-prices[ind] + helper1(ind+1, 0, prices, n), 0 + helper1(ind+1, 1, prices, n));
    }else{
      profit = max(prices[ind] + helper1(ind+2, 1, prices, n), 0 + helper1(ind+1, 0, prices, n));
    }
    return profit;
  }

  int stockProfit1(vector<int> &prices){
    int n = prices.size();
    return helper1(0, 1, prices, n);
  }

  /* ------------------------------------------------------------------- */
  //Memoization
  int helper2(int ind, int buy, vector<int>& prices, int n, vector<vector<int>> &dp){
    if(ind >= n) return 0;

    if(dp[ind][buy] != -1) return dp[ind][buy];

    int profit = 0;
    if(buy){
      profit = max(-prices[ind] + helper2(ind+1, 0, prices, n, dp), 0 + helper2(ind+1, 1, prices, n, dp));
    }else{
      profit = max(prices[ind] + helper2(ind+2, 1, prices, n, dp), 0 + helper2(ind+1, 0, prices, n, dp));
    }

    return dp[ind][buy] = profit;
  }

  int stockProfit2(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2, -1));
    return helper2(0, 1, prices, n, dp);
  }
  /* -------------------------------Version 1------------------------------------ */
  //Tabulation

  int stockProfit3(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n+2, vector<int>(2, 0));
    for(int ind=n-1; ind>=0; ind--){
      for(int buy=0; buy<=1; buy++){
        int profit = 0;
        if(buy){
          profit = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
        }else{
          profit = max(prices[ind] + dp[ind+2][1], 0 + dp[ind+1][0]);
        }
        dp[ind][buy] = profit;
      }
    }
    return dp[0][1];
  }

  /* -------------------------------Version 2------------------------------------ */
  //Tabulation
  int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n+2, vector<int>(2, 0));
    for(int ind=n-1; ind>=0; ind--){
        dp[ind][1] = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
        dp[ind][0] = max(prices[ind] + dp[ind+2][1], 0 + dp[ind+1][0]);

    }
    return dp[0][1];
  }

  /* ------------------------------------------------------------------- */
  //Space optimization
  int stockProfit3(vector<int> &prices){
    int n = prices.size();
    vector<int> front2(2, 0);
    vector<int> front1(2, 0);
    vector<int> current(2, 0);
    for(int ind=n-1; ind>=0; ind--){
        current[1] = max(-prices[ind] + front1[0], 0 + front1[1]);
        current[0] = max(prices[ind] + front2[1], 0 + front1[0]);

        front2 = front1;
        front1 = current;
    }
    return current[1];
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
