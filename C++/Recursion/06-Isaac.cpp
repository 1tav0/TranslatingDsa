#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  bool helper(int i, int j, string s, string t){
    if(i<0 && j<0) return true;
    if(i<0 && j>=0) return false;

    /*
      konar
      ronak
    */
    if(s[i] == t[j]){
      // helper(5, 3, s, t);
      return helper(i-1, j-1, s, t);
    }

    return helper(i-1, j, s, t);

  }
  bool function(string s, string t){
    int n = s.size(); //6
    int m = t.size(); //3
    //helper(6, 3, s, t);
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, 0));
    dp[0][0] = true;
    for(int j=1; j<=m; j++) dp[0][j] = false;

    for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
        if(s[i-1] == t[j-1]){
          // helper(5, 3, s, t);
          dp[i][j] = dp[i-1][j-1];
        }

        dp[i][j] = dp[i-1][j];
      }
    }
    return dp[n][m];
  }
};

int main(){
  string s = "konar";
  string t = "onar";

  Solution obj;
  bool ans = obj.function(s, t);
  cout << "Is " << t << " in " << s << " 1 for yes. 0 for no: " << ans;

}
