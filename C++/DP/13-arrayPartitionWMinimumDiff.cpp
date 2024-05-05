#include <iostream>
#include <vector>
using namespace std;
/************************Subsequences*************************/
class Solution{
public:
  int minSubsetSumDifference(vector<int> &arr, int n){
    int total = 0;
    for(int i=0; i<n; i++){
      total += arr[i];
    }
    int k = total;
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    for(int i=0; i<n; i++) dp[i][0] = true;
    if(arr[0] <= k) dp[0][arr[0]] = true;
    for(int ind=1; ind<n; ind++){
      for(int target=0; target<=k; target++){
        bool notPick = dp[ind-1][target];
        bool pick = false;
        if(arr[ind]<=target){
          pick = dp[ind-1][target-arr[ind]];
        }
        dp[ind][target] = notPick | pick;
      }
    }
    //dp[n-1][0...total];
    int mini = 1e9;
    for(int s1=0; s1<=total; s1++){
      if(dp[n-1][s1] == true){
        mini = min(mini, abs((total-s1)-s1));
      }
    }
    return mini;
  }
};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> arr = { 8, 6, 5 };
  int n = arr.size();
  cout << "The given array is: " << arr << endl;
  Solution obj;
  int ans = obj.minSubsetSumDifference(arr, n);
  cout << "the minimum absolute difference if we partition this array into two subsets is: " << ans;
  return 0;
}
