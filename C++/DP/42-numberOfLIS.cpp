#include <iostream>
#include <vector>
using namespace std;

/*--------------------------------------LIS------------------------------------------------------*/
//  Given an integer array ‘arr’ of length ‘n’,
//  return the number of longest increasing subsequences in it.
// The longest increasing subsequence(LIS) is the longest subsequence of the given sequence
// such that all subsequent elements are in strictly increasing order.
// Input: ‘n’ = 5, ‘arr’ = [50, 3, 90, 60, 80].
// In this array, the longest increasing subsequences are [50, 60, 80] and [3, 60, 80].
// There are other increasing subsequences as well,
// but we need the number of the longest ones. Hence the answer is 2.
class Solution{
public:
  int findNumberOfLIS(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n, 1);
    vector<int> cnt(n, 1);
    int maxi = 0;
    for(int ind=0; ind<n; ind++){
        for(int prev=0; prev<ind; prev++){
            if(arr[prev]<arr[ind] && 1 + dp[prev] > dp[ind]){
                dp[ind] = 1 + dp[prev];
                cnt[ind] = cnt[prev];
            }else if(arr[prev]<arr[ind] && 1 + dp[prev]==dp[ind]){
                cnt[ind] += cnt[prev];
            }
        }
        maxi = max(maxi, dp[ind]);
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        if(dp[i]==maxi){
            ans += cnt[i];
        }
    }
    return ans;
  }
};
