#include <iostream>
#include <vector>
using namespace std;

/*--------------------------------------LIS------------------------------------------------------*/
//  given an array 'arr' of strings, where each string consists of English lowercase letters.
// A string chain of 'arr' is defined as:
// (1) A sequence of string formed using elements of 'arr'.
// (2) Every string in the sequence can be formed by inserting a lowercase English letter
// into the previous string (except the first string).
// Find the length of the longest possible string chain of 'arr'.
// Input: 'arr' = ["x", "xx", "y", "xyx"]
// The longest possible string chain is “x” -> “xx” -> “xyx”.
// The length of the given chain is 3, hence the answer is 3.
class Solution{
public:
  bool isPossible(string &s, string &t){
    int n = s.size();
    int m = t.size();
    if(n!=m+1) return false;
    int i=0, j=0;
    while(i<n){
        if(j<m && s[i]==t[j]){
            i++;
            j++;
        }else{
            i++;
        }
    }
    if(i==n && j==m) return true;
    return false;
}
// Using <: The array is sorted in ascending order of string lengths. Result: ["x", "y", "xx", "xyx"]
// Using >: The array is sorted in descending order of string lengths. Result: ["xyx", "xx", "x", "y"]
// The choice of < or > in the comparator determines whether the sorting is in ascending or descending order based on the string lengths.
bool comp(string &s, string &t){
    return s.size() < t.size();
}

int longestStrChain(vector<string> &arr){
    int n = arr.size();
    vector<int> dp(n, 1);
    int maxi = 0;
    sort(arr.begin(), arr.end(), comp);
    for(int ind=0; ind<n; ind++){
        for(int prev=0; prev<ind; prev++){
            if(isPossible(arr[ind],arr[prev]) && 1 + dp[prev] > dp[ind]){
                dp[ind] = 1 + dp[prev];
            }
        }
        maxi = max(maxi, dp[ind]);
    }
    return maxi;
  }
};
