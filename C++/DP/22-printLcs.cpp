#include <iostream>
#include <vector>
using namespace std;
/************************Strings*************************/
// we are printing the longest common subsequence using the tabulation answer
// and iterating from it starting from the back
class Solution{
public:
  string printLcs(string s, string t){
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

    int len = dp[n][m];
    string ans = "";
    for(int i=0; i<len; i++){
      ans += '$';
    }
    int ind = len-1;
    int i = n, j = m;
    while(i > 0 && j > 0){
      if(s[i-1] == t[j-1]){
        ans[ind] = s[i-1];
        ind--;
        // ans += s[i-1];
        i--, j--;
      }else if(dp[i-1][j] > dp[i][j-1]){
        i--;
      }else{
        j--;
      }
    }
    return ans;
  }
};

int main(){
  string s = "abcde";
  string t = "bdgek";
  cout << "The string s is: " << s << endl;
  cout << "The string t is: " << t << endl;
  Solution obj;
  string ans = obj.printLcs(s, t);
  cout << "The longest common subsequence is: " << ans << endl;
  return 0;
}
