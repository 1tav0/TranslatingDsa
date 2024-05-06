#include <iostream>
#include <vector>
using namespace std;
/************************Strings*************************/
//  we are finding the longest common substring in this case
// a substring is a contigous string found in both s and t
class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Tabulation
  //sc - O(nxm)
  int lcs(string &s, string &t){
	   int n = s.size();
     int m = t.size();
     vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
     int maxi = -1e9;
     for(int i=1; i<=n; i++){
       for(int j=1; j<=m; j++){
         if(s[i-1] == t[j-1]){
           dp[i][j] = 1 + dp[i-1][j-1];
           maxi = max(maxi, dp[i][j]);
         }else{
           dp[i][j] = 0;
         }
       }
     }
     return maxi;
  }
};

int main(){
  string s = "abcjklp";
  string t = "acjkp";
  cout << "The string s is: " << s << endl;
  cout << "The string t is: " << t << endl;
  Solution obj;
  int ans = obj.lcs(s, t);
  cout << "The longest common substring is: " << ans << endl;
  return 0;
}
