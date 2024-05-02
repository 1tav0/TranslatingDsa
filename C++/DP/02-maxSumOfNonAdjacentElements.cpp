#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  // Recursive Solution
  int helper1(int ind, vector<int> &nums){
    if(ind == 0){
      return nums[0];
    }

    int pick = nums[ind];
    if(ind>1) pick += helper1(ind-2, nums);
    int notPick = 0 + helper1(ind-1, nums);
    return max(pick, notPick);
  }
  int maximumNonAdjacentSum1(vector<int> &nums){
    int n = nums.size();
    return helper1(n-1, nums);
  }

  /* ------------------------------------------------------------------- */

  //Memoization
  int helper2(int ind, vector<int> &nums, vector<int>& dp){
    if(ind==0) return nums[0];

    if(dp[ind] != -1) return dp[ind];

    int pick = nums[ind];
    if(ind>1) pick += helper2(ind-2, nums, dp);
    int notPick = 0 + helper2(ind-1, nums, dp);

    return dp[ind] = max(pick, notPick);
  }
  int maximumNonAdjacentSum2(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n+1, -1);
    return helper2(n-1, nums, dp);
  }

  /* ------------------------------------------------------------------- */

  //Tabulation
  int maximumNonAdjacentSum3(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n+1, -1);
    dp[0] = nums[0];
    for(int ind=1; ind<n; ind++){
      int pick = nums[ind];
      if(ind>1) pick += dp[ind-2];
      int notPick = 0 + dp[ind-1];
      dp[ind] = max(pick, notPick);
    }
    return dp[n-1];
  }

  /* ------------------------------------------------------------------- */

  //Space Optimization
  int maximumNonAdjacentSum4(vector<int> &nums){
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for(int ind=1; ind<n; ind++){
      int pick = nums[ind];
      if(ind > 1) pick += prev2;
      int notPick = 0 + prev;

      int current = max(pick, notPick);
      prev2 = prev;
      prev = current;
    }
    return prev;
  }

};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> nums = { 1, 2, 3, 1, 3, 5, 8, 1, 9 };
  cout << "The array is: " << nums << endl;
  Solution obj;
  int ans = obj.maximumNonAdjacentSum4(nums);
  cout << "The maximum sum of a sequence in which no elements are adjacent in the given array/list is: " << ans;
  return 0;
}
