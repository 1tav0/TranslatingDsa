#include <iostream>
#include <vector>
using namespace std;

/*--------------------------------------LIS------------------------------------------------------*/
// given a array of distinct numbers
// of size n
// return the largest subset of numbers from ‘arr’,
// such that any pair of numbers ‘a’ and ‘b’ from the subset satisfies the following:
// a % b == 0 or b % a == 0.
class Solution{
public:
  //tc - O(n`2) + O(n)
  vector<int> divisibleSet(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n+1, 1);
    vector<int> hash(n);
    int maxi = 0;
    int lastIndex = 0;
    sort(arr.begin(), arr.end()); // key for this to work
    for(int ind=0; ind<n; ind++){
        hash[ind] = ind;
        for(int prev=0; prev<ind; prev++){
            if(arr[ind]%arr[prev] == 0 && 1 + dp[prev] > dp[ind]){
                dp[ind] = 1 + dp[prev];
                hash[ind] = prev;
            }
        }
        if(dp[ind] > maxi){
            maxi = dp[ind];
            lastIndex = ind;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while(lastIndex != hash[lastIndex]){
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(), temp.end());
    return temp;
  }
};
