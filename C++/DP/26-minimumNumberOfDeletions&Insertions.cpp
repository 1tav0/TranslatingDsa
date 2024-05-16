#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/************************Strings*************************/
// we are given 2 non-empty strings, s1 & s2
// we need to make s1 into s2
// we can only delete or insert characters
// intuition: find what are the common chars in s1 and s2 which is the lcs
// to get the minimum number of deletions to make a string s1 be s2 is n - lcs
// got the minimum number of insertions to make s2 be s1 is m - lcs
// therefore n+m - 2 * lcs
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

  int canYouMake(string &str, string &ptr){
      int n = str.size();
      int m = ptr.size();
      return (n+m) - 2*lcs(str, ptr);
  }
};

int main(){
  string str = "edl";
  string ptr = "xcqja";
  cout << "The string s1 is: " << str << endl;
  cout << "The string s2 is: " << ptr << endl;
  Solution obj;
  int ans = obj.canYouMake(str, ptr);
  cout << "The minimum number of operations required to convert string 's1' into 's2' is: "<< ans << endl;
  return 0;
}
