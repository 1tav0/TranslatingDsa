#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/************************Strings*************************/
// we are given two strings A and B
// we need the shortest supersequence that has both A & B as its subsequence
// A string 's' is a subsequence of string 't' if deleting some number of
// characters from 't' (possibly 0) results in the string 's'.
// Suppose ‘A’ = “brute”, and ‘B’ = “groot”
// The shortest supersequence will be “bgruoote”.
// intution: common guys are taken only once to avoid making it longer
// common in string means lcs
// in “brute” && “groot” lcs is "rt"
// then in "brute" we wake "bue" all of it besides the "rt" which we only take once
// then in "groot" we take "goo" all of it besides the "rt"
// n+m - len(lcs) is the shortest longets supersequence
class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Tabulation
  //sc - O(nxm)
  string shortestSupersequence(string s, string t){
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
      string ans = "";
      int i = n, j = m;
      while(i>0 && j>0){
        if(s[i-1] == t[j-1]){
          ans += s[i-1];
          i--;
          j--;
        }else if(dp[i-1][j] > dp[i][j-1]){
          ans += s[i-1];
          i--;
        }else{
          ans += t[j-1];
          j--;
        }
      }
      while(i > 0){
        ans += s[i-1];
        i--;
      }
      while(j > 0){
        ans += t[j-1];
        j--;
      }
      reverse(ans.begin(), ans.end());
      return ans;
  }
};

int main(){
  string s = "brute";
  string t = "groot";
  cout << "The string s1 is: " << s << endl;
  cout << "The string s2 is: " << t << endl;
  Solution obj;
  string ans = obj.shortestSupersequence(s, t);
  cout << "The shortest supersequence between 's1' and 's2' will be: "<< ans << endl;
  return 0;
}
