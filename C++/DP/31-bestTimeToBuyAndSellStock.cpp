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
// we are given an array list 'prices'
// elements represent the prices of the stock as they were yesterday
// indices represent minutes
// find and return the max profit one can make by buying and selling the Stocks
// can buy and sell only once
// cannot sell without buying first
class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Brute force
  // intuition : buy at lowest price and sell at highest price
  int maximumProfit(vector<int> &prices){
      int n = prices.size();
      int minPrice = prices[0];
      int maxProfit = 0;
      for(int i=1; i<n; i++){
        int profit = prices[i] - minPrice; // the profit we get when we sell is what we bought for subtracted from the sell
        maxProfit = max(maxProfit, profit); // get highest price sold
        minPrice = min(minPrice, prices[i]); // choose lowest price
      }
      return maxProfit;
  }

};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> price = { 2, 5, 7, 8, 10 };
  int n = price.size();
  // All possible partitions are:
  // 1,1,1,1,1           max_cost=(2+2+2+2+2)=10
  // 1,1,1,2             max_cost=(2+2+2+5)=11
  // 1,1,3               max_cost=(2+2+7)=11
  // 1,4                 max_cost=(2+8)=10
  // 5                   max_cost=(10)=10
  // 2,3                 max_cost=(5+7)=12
  // 1,2,2               max _cost=(1+5+5)=12
  // if we cut the rod into lengths 1,2,2, or 2,3, we get the maximum
  // cost which is 12
  cout << "The price array is: " << price << endl;
  Solution obj;
  int ans = obj.cutRod5(price, n);
  cout << "The maximum cost obtained by cutting the rod and selling its pieces is: " << ans;
  return 0;
}
