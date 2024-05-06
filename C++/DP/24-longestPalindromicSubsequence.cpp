#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/************************Strings*************************/
//  we are finding the longest palindromic subsequence in the given string
// the approach will be reversing the given string ans using the lcs to find the answer
class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Tabulation
  //sc - O(nxm)
  int lcs(string &s, string &t){
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
        if(s[i-1] == t[j-1]){
          dp[i][j] = 1 + dp[i-1][j-1];
        }else{
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
      }
    }
    return dp[n][m];
  }
  int longestPalindromicSubsequence(string A){
    string B = A;
    reverse(B.begin(), B.end());
    return lcs(A, B);
  }
};

int main(){
  string A = "bbabcbcab";
  cout << "The string A is: " << A << endl;
  Solution obj;
  int ans = obj.longestPalindromicSubsequence(A);
  cout << "The longest subsequence which is also a palindrome has length: "<< ans << endl;
  return 0;
}
