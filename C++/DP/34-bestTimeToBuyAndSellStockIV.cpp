#include <iostream>
#include <vector>
using namespace std;
/************************Stocks*************************/
// we are given an array list 'prices'
// where PRICES[i] denotes the price of a given stock on the i-th day.
// You are also given an integer 'K' denoting the number of possible transactions you can make.
// find the maximum profit in at most K transactions.
// A valid transaction involves buying a stock and then selling it.

class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  int helper1(int ind, int transactions, vector<int> &prices, int k){
    int n = prices.size();
    if(trasanctions == 2*k || ind == n) return 0;

    int profit = 0;
    if(trasanctions%2 == 0){
      profit = max(-prices[ind] + helper1(ind+1, transactions+1, prices, k), 0 + helper1(ind+1, trasanctions, prices, k));
    }else{
      profit = max(prices[ind] + helper1(ind+1, transactions+1, prices, k), 0 + helper1(ind+1, trasanctions, prices, k));
    }
    return profit;
  }
  int maximumProfit1(vector<int> &prices, int n, int k){
    return helper1(0, 0, prices, k);
  }

  /* ------------------------------------------------------------------- */
  //Memoization

  int helper2(int ind, int trans, vector<int> &prices, int k, vector<vector<int>> &dp){
    int n = prices.size();
    if(ind == n || trans == 2*k) return 0;

    if(dp[ind][trans] != -1) return dp[ind][trans];

    int profit = 0;
    if(trans%2==0){
      profit = max(-prices[ind] + helper2(ind+1, trans+1, prices, k, dp), 0 + helper2(ind+1, trans, prices, k, dp));
    }else{
      profit = max(prices[ind] + helper2(ind+1, trans+1, prices, k, dp), 0 + helper2(ind+1, trans, prices, k, dp));
    }

    return dp[ind][trans] = profit;
  }

  int maximumProfit2(vector<int> &prices, int n, int k){
    vector<vector<int>> dp(n+1, vector<int>(2*k+1, -1));
    return helper2(0, 0, prices, k, dp);
  }

  /* ------------------------------------------------------------------- */
  //Tabulation
  int maximumProfit3(vector<int> &prices, int n, int k){
    vector<vector<int>> dp(n+1, vector<int>(2*k+1, -1));
    for(int ind=n-1; ind>=0; ind--){
      for(int trans=2*k-1; trans>=0; trans--){
        int profit = 0;
        if(trans%2==0){
          profit = max(-prices[ind] + dp[ind+1][trans+1], 0 + dp[ind+1][trans]);
        }else{
          profit = max(prices[ind] + dp[ind+1][trans+1], 0 + dp[ind+1][trans]);
        }
        dp[ind][trans] = profit;
      }
    }
    return dp[0][0];
  }

  /* ------------------------------------------------------------------- */
  //Space optimization
  int maximumProfit4(vector<int> &prices, int n, int k){
    vector<int> ahead(2*k+1, 0);
    vector<int> current(2*k+1, 0);
    for(int ind=n-1; ind>=0; ind--){
      for(int trans=2*k-1; trans>=0; trans--){
        int profit = 0;
        if(trans%2==0){
          profit = max(-prices[ind] + ahead[trans+1], 0 + ahead[trans]);
        }else{
          profit = max(prices[ind] + ahead[trans+1], 0 + ahead[trans]);
        }
        current[trans] = profit;
      }
      ahead = current;
    }
    return ahead[0];
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
