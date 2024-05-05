#include <iostream>
#include <vector>
using namespace std;
/************************Subsequences*************************/
class Solution{
  int mod = 1000000007;
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  //tc - O(2`n)
  //sc - O(n)
  int helper1(int ind, vector<int> &arr, int target){
    if(target == 0) return 1;
    if(ind == 0) return (arr[0]==target);

    int notPick = helper1(ind-1, arr, target);
    int pick = 0;
    if(arr[ind]<=target){
      pick = helper1(ind-1, arr, target-arr[ind]);
    }
    return notPick + pick;
  }
  int findWays1(vector<int> &arr, int k){
    int n = arr.size();
    return helper1(n-1, arr, k)%mod;
  }
  /* ------------------------------------------------------------------- */
  //Memoization
  //tc - O(nxsum)
  //sc - O(nxsum)+ O(n) a.s.s
  int helper2(int ind, vector<int> &arr, int target, vector<vector<int>> &dp){
    if(target == 0) return 1;
    // if target is 0 and the only element in the array is also 0
    if(target == 0 && arr[0] == 0) return 2;
    if(ind == 0) return (arr[0]==target)%mod;

    if(dp[ind][target] != -1) return dp[ind][target]%mod;

    int notPick = helper2(ind-1, arr, target, dp);
    int pick = 0;
    if(arr[ind] <= target){
      pick = helper2(ind-1, arr, target-arr[ind], dp);
    }

    return dp[ind][target] = (notPick + pick)%mod;
  }
  int findWays2(vector<int> &arr, int k){
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return helper2(n-1, arr, k, dp);
  }

  /* ------------------------------------------------------------------- */
  //Tabulation
  //tc - O(nxsum)
  //sc - O(nxsum)
  int findWays3(vector<int> &arr, int k){
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    for(int i=0; i<n; i++) dp[i][0] = 1;
    dp[0][0] = 1;
    if(arr[0] == 0) dp[0][0] = 2;
    else if(arr[0] <= k) dp[0][arr[0]] = 1;

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

  /* ------------------------------------------------------------------- */
  //Space optimization
  //tc - O(nxsum)
  //sc - O(n) 1d vectors instead of 2d
  int findWays4(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> prev(k+1, 0);
    vector<int> current(k+1, 0);
    current[0] = 1;
    prev[0] = 1;
    if(arr[0] == 0) prev[0] = 2;
    else if(arr[0] <= k) prev[arr[0]] = 1;

    for(int ind=1; ind<n; ind++){
      for(int target=0; target<=k; target++){
        int notPick = prev[target];
        int pick = 0;
        if(arr[ind] <= target){
          pick = prev[target-arr[ind]];
        }
        current[target] = (notPick + pick)%mod;
      }
      prev = current;
    }
    return prev[k];
  }
};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> arr = {1, 4, 4, 5};
  int k = 5;
  cout << "The given array is: " << arr << endl;
  Solution obj;
  int ans = obj.findWays4(arr, k);
  cout << "The numbers of subset ways that add up to " << k << " is: " << ans;
  return 0;
}

int mod = 10e9+7;
int findWays(vector<int>& arr, int k)
{
    int n = arr.size();
	vector<vector<int>> dp(n,vector<int>(k+1, 0));

	if(arr[0]==0) dp[0][0] = 2;
    else dp[0][0] = 1;

	if(arr[0] != 0 && arr[0]<=k) dp[0][arr[0]] = 1;

  for(int ind=1; ind<n; ind++){
		for(int sum=0; sum<=k; sum++){
			int notTake = dp[ind-1][sum];
			int take = 0;
			if(arr[ind]<=sum) take = dp[ind-1][sum-arr[ind]];

			dp[ind][sum] = (notTake + take)%mod;
		}
	}

	return dp[n-1][k];
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = 0;
    for(auto &it: arr) totSum += it;
    if(totSum-d<0 || (totSum-d)%2) return false;
    return findWays(arr,(totSum-d)/2);
}

/* ------------------------------------------------------------------- */
//Recursion

/* ------------------------------------------------------------------- */
//Memoization


/* ------------------------------------------------------------------- */
//Tabulation


/* ------------------------------------------------------------------- */
//Space optimization
