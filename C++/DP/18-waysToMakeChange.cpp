#include <iostream>
#include <vector>
using namespace std;
/************************Subsequences*************************/
// given infinite amount of denominations we need to find the TOTAL number of ways
// we can make change that matches the target
// similar to grids thats why we only return 1 when we reach that target
class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  //tc - >>O(2`n) for every index we got, the opitons can go more than 2`n cuz is stands in the same index
  //sc - O(target) bigger than O(n)
  long helper1(int ind, int *denominations, int target){
    if(target == 0) return 1;
    if(ind == 0){
      return (target%denominations[ind]==0);
    }

    int notPick = helper1(ind-1, denominations, target);
    int pick = 0;
    if(denominations[ind] <= target){
      pick = helper1(ind, denominations, target-denominations[ind]);
    }
    return notPick + pick;
  }

  long countWaysToMakeChange1(int *denominations, int n, int value)
  {
    return helper1(n-1, denominations, value);
  }

  /* ------------------------------------------------------------------- */
  //Memoization
  //tc - O(nxTarget)
  //sc - O(nxtarget) + O(target) a.s.s
  long helper2(int ind, int *denominations, int target, vector<vector<long>> &dp){
    if(target == 0) return 1;
    if(ind == 0){
      return (target%denominations[ind] == 0);
    }

    if(dp[ind][target] != -1){
      return dp[ind][target];
    }

    long notPick = helper2(ind-1, denominations, target, dp);
    long pick = 0;
    if(denominations[ind] <= target){
      pick = helper2(ind, denominations, target-denominations[ind], dp);
    }
    return dp[ind][target] = notPick + pick;
  }

  long countWaysToMakeChange2(int *denominations, int n, int value){
    vector<vector<long>> dp(n+1, vector<long>(value+1, -1));
    return helper2(n-1, denominations, value, dp);
  }
  /* ------------------------------------------------------------------- */
  //Tabulation
  long countWaysToMakeChange3(int *denominations, int n, int value){
    vector<vector<long>> dp(n+1, vector<long>(value+1, 0));
    for(int ind=0; ind<n; ind++) dp[ind][0] = 1;
    for(int target=0; target<=value; target++){
      if(target%denominations[0] == 0) dp[0][target] = 1;
    }
    for(int ind=1; ind<n; ind++){
      for(int target=0; target<=value; target++){
        long notPick = dp[ind-1][target];
        long pick = 0;
        if(denominations[ind] <= target){
          pick = dp[ind][target-denominations[ind]];
        }
        dp[ind][target] = notPick + pick;
      }
    }
    return dp[n-1][value];
  }

  /* ------------------------------------------------------------------- */
  //Space optimization
  long countWaysToMakeChange4(int *denominations, int n, int value){
    vector<long> prev(value+1, 0);
    vector<long> current(value+1, 0);
    prev[0] = 1;
    current[0] = 1;
    for(int target=0; target<=value; target++){
      if(target%denominations[0]==0){
        prev[target] = 1;
      }
    }
    for(int ind=1; ind<n; ind++){
      for(int target=0; target<=value; target++){
        long notPick = prev[target];
        long pick = 0;
        if(denominations[ind] <= target){
          pick = current[target-denominations[ind]];
        }
        current[target] = notPick + pick;
      }
      prev = current;
    }
    return prev[value];
  }
};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> arr = { 1,2,3 };
  int* denominations = arr.data();
  // int denominations[] = { 1, 2, 3 };
  // We can make a change for the value V = 4 in four ways.
  // 1. (1,1,1,1),
  // 2. (1,1, 2), [One thing to note here is, (1, 1, 2) is same as that of (2, 1, 1) and (1, 2, 1)]
  // 3. (1, 3), and
  // 4. (2, 2)
  int n = arr.size();
  int value = 4;
  cout << "The array is: " << arr << endl;
  Solution obj;
  int ans = obj.countWaysToMakeChange4(denominations, n, value);
  cout << "The total number of ways, in which you can make change for value " << value << " using coins of denominations " << arr;
  cout << " is " << ans;
  return 0;
}
