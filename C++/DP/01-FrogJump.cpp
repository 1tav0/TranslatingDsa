#include <iostream>
#include <vector>
using namespace std;

/************************Fibonacci*************************/

class Solution{
public:
  //Recursive Solution
  int helper1(int ind, vector<int> &heights){
    if(ind==0) return 0;

    int left = helper1(ind-1, heights) + abs(heights[ind]-heights[ind-1]);
    int right = 1e9;
    if(ind>1) right = helper1(ind-2, heights) + abs(heights[ind]-heights[ind-2]);

    return min(left, right);
  }
  int frogJump1(int n, vector<int> &heights){
    return helper1(n-1, heights);
  }

/* ------------------------------------------------------------------- */

  //Memoization Solution
  int helper2(int ind, vector<int> &heights, vector<int> &dp){
    if(ind == 0){
      return 0;
    }

    if(dp[ind] != -1) return dp[ind];

    int left = helper2(ind-1, heights, dp) + abs(heights[ind]-heights[ind-1]);
    int right = 1e9;
    if(ind>1) right = helper2(ind-2, heights, dp) + abs(heights[ind]-heights[ind-2]);

    return dp[ind] = min(left, right);
  }

  int frogJump2(int n, vector<int> &heights){
    vector<int> dp(n+1, -1);
    return helper2(n-1, heights, dp);
  }

/* ------------------------------------------------------------------- */

  // Tabulation Solution
  int frogJump3(int n, vector<int> &heights){
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    for(int ind=1; ind<n; ind++){
      int left = dp[ind-1] + abs(heights[ind] - heights[ind-1]);
      int right = 1e9;
      if(ind>1) right = dp[ind-2] + abs(heights[ind]-heights[ind-2]);
      dp[ind] = min(left, right);
    }
    return dp[n-1];
  }

/* ------------------------------------------------------------------- */

  // Space Optimization
  int frogJump4(int n, vector<int> &heights){
    int prev = 0;
    int prev2 = 0;
    for(int ind=1; ind<n; ind++){
      int left = prev + abs(heights[ind]-heights[ind-1]);
      int right = 1e9;
      if(ind>1) right = prev2 + abs(heights[ind]-heights[ind-2]);
      int current = min(left, right);
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
  vector<int> heights = { 7, 4, 4, 2, 6, 6, 3, 4  };
  int n = heights.size();
  cout << "The heights array is: " << heights << endl;
  Solution obj;
  int ans = obj.frogJump3(n, heights);
  cout << "The minimum total energy wasted is: " << ans;
}
