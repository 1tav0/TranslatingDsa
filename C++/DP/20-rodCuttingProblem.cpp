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
/************************Subsequences*************************/
// we are given a rod of lenth n
// the rod can be cut into different sizes but each cut/size has a cost
// we gotta find the maximum cost we can get by cutting the rod and selling
// the pieces (this is taken care of in the base case)
class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  int helper1(int ind, vector<int>& price, int N){
    if(ind == 0){
      return N*price[ind];
    }

    int notPick = helper1(ind-1, price, N);
    int pick = -1e9;
    int rodLength = ind+1;
    if(rodLength <= N){
      pick = price[ind] + helper1(ind, price, N-rodLength);
    }
    return max(notPick, pick);
  }
  int cutRod1(vector<int> &price, int n){
    return helper1(n-1, price, n);
  }
  /* ------------------------------------------------------------------- */
  //Memoization
  //tc - O(nxn)
  //sc - O(nxn) + O(target)
  int helper2(int ind, vector<int>& price, int N, vector<vector<int>> &dp){
    if(ind == 0){
      return N*price[ind];
    }

    if(dp[ind][N] != -1) return dp[ind][N];

    int notPick = helper2(ind-1, price, N, dp);
    int pick = -1e9;
    int rodLength = ind+1;
    if(rodLength <= N){
      pick = price[ind] + helper2(ind, price, N-rodLength, dp);
    }
    return dp[ind][N] = max(notPick, pick);
  }

  int cutRod2(vector<int> &price, int n){
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return helper2(n-1, price, n, dp);
  }
  /* ------------------------------------------------------------------- */
  //Tabulation
  int cutRod3(vector<int> &price, int n){
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int N=0; N<=n; N++){
      dp[0][N] = N*price[0];
    }
    for(int ind=1; ind<n; ind++){
      for(int N=0; N<=n; N++){
        int notPick = dp[ind-1][N];
        int pick = -1e9;
        int rodLength = ind+1;
        if(rodLength <= N){
          pick = price[ind] + dp[ind][N-rodLength];
        }
        dp[ind][N] = max(notPick, pick);
      }
    }
    return dp[n-1][n];
  }

  /* ------------------------------------------------------------------- */
  //Space optimization
  int cutRod4(vector<int> &price, int n){
    vector<int> prev(n+1, 0);
    vector<int> current(n+1, 0);
    for(int N=0; N<=n; N++){
      prev[N] = N*price[0];
    }
    for(int ind=1; ind<n; ind++){
      for(int N=0; N<=n; N++){
        int notPick = prev[N];
        int rodLength = ind+1;
        int pick = -1e9;
        if(rodLength <= N){
          pick = price[ind] + current[N-rodLength];
        }
        current[N] = max(notPick, pick);
      }
      prev = current;
    }
    return prev[n];
  }
  /* ------------------------------------------------------------------- */
  //Space optimization One array
  int cutRod5(vector<int> &price, int n)
  {
  	vector<int> prev(n+1, 0);
  	for(int N=0; N<=n; N++) prev[N] = N*price[0];

  	for(int ind=1; ind<n; ind++){
  		for(int N=0; N<=n; N++){
  			int notTake = prev[N];
  			int take = -1e9;
  			int rodLength = ind+1;
  			if(rodLength<=N) take = price[ind] + prev[N-rodLength];

  			prev[N] = max(take, notTake);
  		}
  	}

  	return prev[n];
  }
};

int main(){
  vector<int> price = {}
}
