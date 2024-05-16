#include <iostream>
#include <vector>
#include <string>
using namespace std;
/************************Strings*************************/
// we are given a text and a wildcard pattern
// we have to find if the wildcard pattern is matched with the text
// the wildcard pattern can include '?' and '*'
// ‘?’ – matches any single character
// ‘*’ – Matches any sequence of characters(sequence can be of length 0 or more)
class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion
  // version 1
  bool helper(int i, int j, string text, string pattern){
    if(i<0 && j<0) return true; // both strings are exhausted
    if(j<0 && i>=0) return false; // pattern is exhausted
    if(i<0 && j>=0){ // text is exhuasted but pattern is not
      for(int k=0; k<=j; k++){ // check if all chars in pattern are '*'
        if(pattern[k] != '*'){
          return false;
        }
      }
      return true;
    }

    if(text[i] == pattern[j] || pattern[j] == '?'){
      return helper(i-1, j-1, text, pattern);
    }

    if(pattern[j] == '*'){
      // Two cases: ignore '*' (match zero characters) or use '*' (match one or more characters)
      return helper(i, j-1, text, pattern) | helper(i-1, j, text, pattern);
    }
    return false;
  }
  bool wildcardMatching(string text, string pattern){
    int n = text.size();
    int m = pattern.size();
    return helper(n-1, m-1, text, pattern);
  }

  // version 2
  bool helper1(int j, int i, string text, string pattern){
    if(i<0 && j<0) return true; // both strings are exhausted
    if(j<0 && i>=0) return false; // pattern is exhausted
    if(i<0 && j>=0){ // text is exhuasted but pattern is not
      for(int k=0; k<=j; k++){ // check if all chars in pattern are '*'
        if(pattern[k] != '*'){
          return false;
        }
      }
      return true;
    }

    if(text[i] == pattern[j] || pattern[j] == '?'){
      return helper1(j-1, i-1, text, pattern);
    }

    if(pattern[j] == '*'){
      // Two cases: ignore '*' (match zero characters) or use '*' (match one or more characters)
      return helper1(j-1, i, text, pattern) | helper1(j, i-1, text, pattern);
    }
    return false;
  }

bool wildcardMatching1(string pattern, string text)
{
    int n = text.size();
    int m = pattern.size();
    return helper1(m-1, n-1, text, pattern);
}
  /* ------------------------------------------------------------------- */
  //Memoization
  bool helper2(int j, int i, string text, string pattern, vector<vector<int>> &dp){
      if(i<0 && j<0) return true; // both strings are exhausted
      if(j<0 && i>=0) return false; // pattern is exhausted
      if(i<0 && j>=0){ // text is exhuasted but pattern is not
        for(int k=0; k<=j; k++){ // check if all chars in pattern are '*'
          if(pattern[k] != '*'){
            return false;
          }
        }
        return true;
      }

      if(dp[i][j] != -1) return dp[i][j];

      if(text[i] == pattern[j] || pattern[j] == '?'){
        return dp[i][j] =  helper2(j-1, i-1, text, pattern, dp);
      }

      if(pattern[j] == '*'){
        // Two cases: ignore '*' (match zero characters) or use '*' (match one or more characters)
        return dp[i][j] =  helper2(j-1, i, text, pattern, dp) | helper2(j, i-1, text, pattern, dp);
      }
      return dp[i][j] = false;
    }

  bool wildcardMatching2(string pattern, string text)
  {
      int n = text.size();
      int m = pattern.size();
      vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
      return helper2(m-1, n-1, text, pattern, dp);
  }
  /* ------------------------------------------------------------------- */
  //tabulation
  // note: pattern is s, text is t
  bool wildcardMatching3(string pattern, string text){
   int n = pattern.size();
   int m = text.size();
   vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
   dp[0][0] = true;
   for(int j=1; j<=m; j++){
      dp[0][j] = false;
   }
   for(int i=1; i<=n; i++){
      int flag = true;
      for(int ii=1; ii<=i; ii++){
         if(pattern[ii-1]!='*'){
            flag = false;
            break;
         }
      }
      dp[i][0] = flag;
   }

   for(int i=1; i<=n; i++){
      for(int j=1;j<=m; j++){
         if(pattern[i-1]==text[j-1] || pattern[i-1]=='?'){
            dp[i][j] = dp[i-1][j-1];
         }
         else if(pattern[i - 1] == '*') {
           dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
         }
         else dp[i][j] = false;
      }
   }

   return dp[n][m];
}

  /* ------------------------------------------------------------------- */
  //space optimization
  bool wildcardMatching4(string pattern, string text){
     int n = pattern.size();
     int m = text.size();
     vector<bool> prev(m+1, false), current(m+1, false);
     prev[0] = true;
     for(int j=1; j<=m; j++){
        prev[j] = false;
     }

     for(int i=1; i<=n; i++){
        bool flag = true;
        for(int ii=1; ii<=i; ii++){
           if(pattern[ii-1]!='*'){
              flag = false;
              break;
           }
        }
        current[0] = flag;
        for(int j=1;j<=m; j++){
           if(pattern[i-1]==text[j-1] || pattern[i-1]=='?'){
              current[j] = prev[j-1];
           }
           else if(pattern[i - 1] == '*') {
             current[j] = prev[j] | current[j - 1];
           }
           else current[j] = false;
        }
        prev = current;
     }

     return prev[m];
  }
};


int main(){
  string pattern = "ab?d";
  string text = "abcc";
  cout << "The string pattern is: " << pattern << endl;
  cout << "The string text is: " << text << endl;
  Solution obj;
  bool ans = obj.wildcardMatching4(pattern, text);
  cout << "Can the text '" << text << "' be formed from the pattern '" << pattern << "' " << ans << endl;
  return 0;
}
