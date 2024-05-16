#include <iostream>
#include <vector>
#include <string>
using namespace std;
/************************Strings*************************/
// we are given two strings s and t
// Edit Distance of two strings is the minimum number of
// steps required to make one string equal to the other.
// can perform 3 operations
// 1. delete a character
// 2. replace a character
// 3. insert a character
class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  int helper1(int i, int j, string s, string t){
    if(i<0) return j+1;
    if(j<0) return i+1;

    if(s[i] == t[j]){
      return 0 + helper1(i-1, j-1, s, t);
    }

    int del = helper1(i-1, j, s, t);
    int insert = helper1(i, j-1, s, t);
    int replace = helper1(i-1, j-1, s, t);

    return 1 + min(del, min(insert, replace));
  }

  int editDistance1(string s, string t){
    int n = s.size();
    int m = t.size();
    return helper1(n-1, m-1, s, t);
  }
  /* ------------------------------------------------------------------- */
  //Memoization
  int helper2(int i, int j, string s, string t, vector<vector<int>> &dp){
    if(j==0) return i;
    if(i==0) return j;

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i-1]==t[j-1]){
      return dp[i][j] = helper2(i-1, j-1, s, t, dp);
    }

    int del = helper2(i-1, j, s, t, dp);
    int replace = helper2(i, j-1, s, t, dp);
    int insert = helper2(i-1, j-1, s, t, dp);

    return dp[i][j] = 1 + min(del, min(replace, insert));
  }

  int editDistance2(string s, string t){
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return helper2(n, m, s, t, dp);
  }
  /* ------------------------------------------------------------------- */
  //tabulation
  int editDistance3(string s, string t){
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=0; i<=n; i++) dp[i][0] = i;
    for(int j=1; j<=m; j++) dp[0][j] = j;
    for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
        if(s[i-1] == t[j-1]){
          dp[i][j] = dp[i-1][j-1];
        }else{
          int del = dp[i-1][j];
          int replace = dp[i][j-1];
          int insert = dp[i-1][j-1];

          dp[i][j] = 1 + min(del, min(replace, insert));
        }
      }
    }
    return dp[n][m];
  }

  /* ------------------------------------------------------------------- */
  //space optimization
  int editDistance4(string s, string t){
    int n = s.size();
    int m = t.size();
    vector<int> prev(m+1, 0);
    vector<int> current(m+1, 0);
    for(int j=1; j<=m; j++) prev[j] = j;

    for(int i=1; i<=n; i++){
      current[0] = i;
      for(int j=1; j<=m; j++){
        if(s[i-1] == t[j-1]){
          current[j] = prev[j-1];
        }else{
          int del = prev[j];
          int replace = current[j-1];
          int insert = prev[j-1];

          current[j] = 1 + min(del, min(replace, insert));
        }
      }
      prev = current;
    }
    return prev[m];
  }
};


int main(){
  string s = "whgtdwhgtdg";
  string t = "aswcfg";
  cout << "The string s1 is: " << s << endl;
  cout << "The string s2 is: " << t << endl;
  Solution obj;
  int ans = obj.editDistance1(s, t);
  cout << "In " << ans << " operations we can make the string '" << t << "' to look like string '" << s <<"'" << endl; 
  return 0;
}
