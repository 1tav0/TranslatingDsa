#include <iostream>
#include <vector>
#include <string>
using namespace std;
/************************Strings*************************/
// we are given two strings A and B
// we need to return the number of different subsequences of s which equals t
// s = "rabbbit", t = "rabbit"
// there are 3 ways you can generate "rabbit" from s.
class Solution{
  const int mod = 1000000007;
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  //tc - exponential not 2`n bc standing at same index
  //sc - O(w)
  int helper1(int i, int j, string s, string t){
    if(j<0) return 1; // we exhaust all of t so means we got 1
    if(i<0) return 0; // we dont have a s anymore so cannot match anything

    if(s[i] == t[j]){ // they match so we add the match plus what if there are other letters in s that match t
      return helper1(i-1, j-1, s, t) + helper1(i-1, j, s, t);
    }

    return helper1(i-1, j, s, t);
  }
  int numDistinct1(string s, string t){
    int n = s.size();
    int m = t.size();
    return helper1(n-1, m-1, s, t);
  }
  /* ------------------------------------------------------------------- */
  //Memoization
  int helper2(int i, int j, string s, string t, vector<vector<int>>& dp){
    if(j==0) return 1;
    if(i==0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i-1] == t[j-1]){
      return dp[i][j] = helper2(i-1, j-1, s, t, dp) + helper2(i-1, j, s, t, dp);
    }

    return dp[i][j] = helper2(i-1, j, s, t, dp);
  }

  int numDistinct2(string s, string t){
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return helper2(n, m, s, t, dp);
  }
  /* ------------------------------------------------------------------- */
  //tabulation
  int numDistinct3(string s, string t){
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=0; i<=n; i++) dp[i][0] = 1;
    for(int j=1; j<=m; j++) dp[0][j] = 0;
    for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
        if(s[i-1] == t[j-1]){
          dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
        }else{
          dp[i][j] = (dp[i-1][j])%mod;
        }
      }
    }
    return dp[n][m];
  }
  /* ------------------------------------------------------------------- */
  //Space optimization
  int numDistinct4(string s, string t){
    int n = s.size();
    int m = t.size();
    vector<int> prev(m+1, 0);
    vector<int> current(m+1, 0);
    prev[0] = 1;
    current[0] = 1;
    for(int j=1; j<=m; j++) prev[j] = 0;
    for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
        if(s[i-1] == t[j-1]){
          current[j] = (prev[j-1] + prev[j])%mod;
        }else{
          current[j] = (prev[j])%mod;
        }
      }
      prev = current;
    }
    return prev[m];
  }
};


int main(){
  string s = "rabbbit";
  string t = "rabbit";
  cout << "The string s1 is: " << s << endl;
  cout << "The string s2 is: " << t << endl;
  Solution obj;
  int ans = obj.numDistinct3(s, t);
  cout << "There are " << ans << " ways you can generate " << t << " from " << s << endl;
  return 0;
}
