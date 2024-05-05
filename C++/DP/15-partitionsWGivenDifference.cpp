#include <iostream>
#include <vector>
using namespace std;
/************************Subsequences*************************/
// in this problem we have to find two subsets of the given array s1 and s2
// the sum of s1 has to be larger or equal to s2
// and their difference had to be equal to the given d
class Solution{
  int mod = 1000000007;
public:
  int findWays(vector<int> &arr, int k){
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    dp[0][0] = 1;
    if(arr[0] == 0) dp[0][0] = 2;
    else if(arr[0]<=k) dp[0][arr[0]] = 1;
    for(int ind=1; ind<n; ind++){
      for(int target=0; target<=k; target++){
        int notPick = dp[ind-1][target];
        int pick = 0;
        if(arr[ind] <= target){
          pick = dp[ind-1][target-arr[ind]];
        }
        dp[ind][target] = (notPick + pick)%mod;
      }
    }
    return dp[n-1][k];
  }

  int countPartitions(int n, int d, vector<int> &arr){
    int total = 0;
    for(auto &it: arr) total += it;
    if(total-d<0 || (total-d)%2) return 0;
    int k = (total-d)/2;
    return findWays(arr, k);
  }
};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> arr = { 5, 2, 5, 1 };
  int n = 4;
  int d = 3;
  cout << "The array is: " << arr << endl;
  Solution obj;
  int ans = obj.countPartitions(n, d, arr);
  cout << "The amount of possible partitions of the arr into a subset 1 and subset 2 in which";
  cout << " s1 is greater than s2 and their difference is equal to " << d << " are: " << ans;
  return 0;
}
