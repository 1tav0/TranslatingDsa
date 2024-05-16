#include <iostream>
#include <vector>
using namespace std;
/* ------------------------------------------------------------------- */
//Recursion

/* ------------------------------------------------------------------- */
//Memoization


/* ------------------------------------------------------------------- */
//Tabulation


/* ------------------------------------------------------------------- */
//Space optimization
/************************Stocks*************************/
// have been given the stock values/prices for N days
// find the max profit which we can get buy buying and selling the Stocks
// can make as many trasanctions as we want
// but we have to buy and sell first before making another transaction
class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  //tc - 2`n
  //sc - O(n)
  // intuition : if we can buy then we buy if we cannot we sell first
  // and want to get the max profit we can

  long helper1(int ind, int buy, long *values, int n){
    if(ind == n) return 0; // we have exhuasted the list cannot buy anything

    long profit = 0;
    if(buy){
      profit = max(-value[ind] + helper1(ind+1, 0, values, n), 0 + helper1(ind+1, 1, values, n));
    }else{
      profit = max(values[ind] + helper1(ind+1, 1, values, n), 0 + helper1(ind+1, 0, values, n));
    }
    return profit;
  }

  long getMaximumProfit1(long *values, int n){
    return helper1(0, 1, values, n);
  }

  /* ------------------------------------------------------------------- */
  //memoization
  //tc - O(nx2)
  //sc - O(nx2) + O(n)
  long helper2(int ind, int buy, long *values, int n, vector<vector<int>> &dp){
    if(ind == n) return 0;

    if(dp[ind][buy] != -1) return dp[ind][buy];

    long profit = 0;
    if(buy){
      profit = max(-values[ind] + helper2(ind+1, 0, values, n, dp), 0 + helper2(ind+1, 1, values, n, dp));
    }else{
      profit = max(values[ind] + helper2(ind+1, 1, values, n, dp), 0 + helper2(ind+1, 0, values, n, dp));
    }
    return dp[ind][buy] = profit;
  }
  long getMaximumProfit2(long *values, int n){
    vector<vector<int>> dp(n+1, vector<int>(2, -1));
    return helper2(0, 1, values, n, dp);
  }

  /* ------------------------------------------------------------------- */
  //Tabulation
  long getMaximumProfit3(long *values, int n){
    vector<vector<long>> dp(n+1, vector<long>(2, 0));
    for(int buy=0; buy<=1; buy++) dp[n][buy] = 0;
    for(int ind=n-1; ind>=0; ind--){
      for(int buy=0; buy<=1; buy++){
        long profit = 0;
        if(buy){
          profit = max(-values[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
        }else{
          profit = max(values[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
        }
        dp[ind][buy] = profit;
      }
    }
    return dp[0][1];
  }

  /* ------------------------------------------------------------------- */
  //Space optimization
  long getMaximumProfit4(long *values, int n){
    vector<long> ahead(2, 0);
    vector<long> current(2, 0);
    for(int buy=0; buy<=1; buy++) ahead[buy] = 0;
    for(int ind=n-1; ind>=0; ind--){
      for(int buy=0; buy<=1; buy++){
        long profit = 0;
        if(buy){
          profit = max(-values[ind] + ahead[0], 0 + ahead[1]);
        }else{
          profit = max(values[ind] + ahead[1], 0 + ahead[0]);
        }
        current[buy] = profit;
      }
      ahead = current;
    }
    return ahead[1];
  }
  /* ------------------------------------------------------------------- */
  // More Space optimization
  long getMaximumProfit5(long *values, int n){
    long aheadNotBuy, aheadBuy, currentBuy, currentNotBuy;
    aheadNotBuy = 0;
    aheadBuy = 0;
    for(int ind=n-1; ind>=0; ind--){
        currentNotBuy = max(values[ind] + aheadBuy,
                           0 + aheadNotBuy);

        currentBuy = max(-values[ind] + aheadNotBuy,
                            0 + aheadBuy);

        aheadBuy = currentBuy;
        aheadNotBuy = currentNotBuy;
    }
    return aheadBuy;
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
