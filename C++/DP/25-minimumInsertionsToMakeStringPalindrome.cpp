#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/************************Strings*************************/
// we are given a string we need to find the minimum number of insertions
// to make the string a palindrome
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

  int minCharsforPalindrome(string str){
    int n = str.size();
    return n - longestPalindromicSubsequence(str);
  }
};

int main(){
  string A = "abcd";
  cout << "The string A is: " << A << endl;
  Solution obj;
  int ans = obj.minCharsforPalindrome(A);
  cout << "The minimum number of insertions to make the given string a palindrome is: "<< ans << endl;
  return 0;
}
