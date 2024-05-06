#include <iostream>
#include <vector>
using namespace std;
/************************Strings*************************/
// we have two Strings
// we need to find the length of the longest common subsequence substring
// the subsequence may be not necessarily contiguos but in the same order
class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  int helper1(int i, int j, string s, string t){
    if(i<0 || j<0) return 0;
    if(s[i] == t[j]) return 1 + helper1(i-1, j-1, s, t);

    return max(helper1(i-1, j, s, t), helper1(i, j-1, s, t));
  }
  int lcs1(string s, string t){
    int n = s.size();
    int m = t.size();
    return helper1(n-1, m-1, s, t);
  }
  /* ------------------------------------------------------------------- */
  //Memoization
  int helper2(int i, int j, string s, string t, vector<vector<int>> &dp){
    if(i<0 || j<0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == t[j]){
      return 1 + helper2(i-1, j-1, s, t, dp);
    }

    return dp[i][j] = max(helper2(i-1, j, s, t, dp), helper2(i, j-1, s, t, dp));

  }

  int lcs2(string s, string t){
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return helper2(n-1, m-1, s, t, dp);
  }

  /* ------------------------------------------------------------------- */
  //Tabulation
  int lcs3(string s, string t){
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
          if(s[i-1] == t[j-1]){
            dp[i][j] = 1 + dp[i-1][j-1];
          }else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    for(int i=0; i<=n; i++){
      for(int j=0; j<=m; j++){
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }

    return dp[n-1+1][m-1+1];
  }

  /* ------------------------------------------------------------------- */
  //Space optimization
  int lcs4(string s, string t){
    int n = s.size();
    int m = t.size();
    vector<int> prev(m+1);
    vector<int> current(m+1);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
          if(s[i-1] == t[j-1]){
            current[j] = 1 + prev[j-1];
          }else current[j] = max(prev[j], current[j-1]);
        }
        prev = current;
    }
    return prev[m-1+1];
  }

};

int main(){
  string s = "abcde";
  string t = "bdgek";
  cout << "The string s is: " << s << endl;
  cout << "The string t is: " << t << endl;
  Solution obj;
  int ans = obj.lcs3(s, t);
  cout << "The longest common subsequence is of length: " << ans << endl;
  return 0;
}
