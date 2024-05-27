// Implement a regular expression function isMatch that supports the '.'
//and '*' symbols. The function receives two strings - text and pattern - and
//should return true if the text matches the pattern as a regular expression.
//For simplicity, assume that the actual symbols '.' and '*' do not appear in
//the text string and are used as special symbols only in the pattern string.
// In case you aren’t familiar with regular expressions, the function determines
//if the text and pattern are the equal, where the '.' is treated as a single a
//character wildcard (see third example), and '*' is matched for a zero or more
//sequence of the previous letter (see fourth and fifth examples). For more
//information on regular expression matching, see the Regular Expression
//Wikipedia page.
// Explain your algorithm, and analyze its time and space complexities.

// #include <iostream>
// #include <string>
//
// using namespace std;
//
// class Solution{
//   public:
//   bool helper(int i, int j, string& t,string &p){
//   if(j < 0 && i > 0) return false;
//   if(j >0 && i <0) return false;
//
//   if(i==0 && j==0) return true;
//
//   if(t[i] == p[j] ||p[j] == '.'){
//     return helper(i-1, j-1, t, p);
//
//   }else if(p[j] == '*' && p[j-1] == t[i]){
//     return helper(i-1, j, t, p);
//   }else if(p[j] == '*' && p[j-1] != t[i]){
//     return helper(i, j-1, t, p);
//   }
//   return true;
// }
//
//
// bool isMatch( const string &text, const string &pattern ) // aa, aaa
// {
//   int n = text.size(); // 2
//   int m = pattern.size(); // 3
//   return helper(n-1, m-1, text, pattern); // helper(1,2,aa, aaa)
// }
//
// };
//
// int main() {
//
//   string t = "aa";
//   string p = "aaa";
//   Solution obj;
//
//   bool ans = obj.isMatch(t, p);
//   cout << ans;
//
//   return 0;
// }

/*----------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool helper(int i, int j, string& t, string& p) {
        // If both strings are fully matched
        if (j < 0 && i < 0) return true;

        // If pattern is empty but text is not
        if (j < 0) return false;

        // If text is empty but pattern is not
        if (i < 0) {
            // Pattern can match if it's something like a*b*c* which can result in empty string
            if (p[j] == '*') return helper(i, j-2, t, p);
            else return false;
        }

        // If the current characters match or pattern has a '.' wildcard
        if (t[i] == p[j] || p[j] == '.') {
            return helper(i-1, j-1, t, p);
        }

        // If there's a '*' in the pattern
        if (p[j] == '*') {
            // '*' can match zero of the preceding element
            if (helper(i, j-2, t, p)) return true;

            // '*' can match one or more of the preceding element
            if (p[j-1] == t[i] || p[j-1] == '.') {
                return helper(i-1, j, t, p);
            }
        }

        return false;
    }

    bool isMatch(const string& text, const string& pattern) {
        int n = text.size();
        int m = pattern.size();
        string t = text;
        string p = pattern;
        return helper(n-1, m-1, t, p);
    }
};

int main() {
    string t = "aa";
    string p = "a";
    Solution obj;

    bool ans = obj.isMatch(t, p);
    cout << (ans ? "true" : "false") << endl;

    return 0;
}




/*-----------------------------------------DP------------------------------------------------------------------*/
// #include <iostream>
// #include <vector>
// #include <string>
//
// using namespace std;
//
// class Solution {
// public:
//     bool isMatch(const string &text, const string &pattern) {
//         int n = text.size();
//         int m = pattern.size();
//
//         vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
//         dp[0][0] = true;  // Empty pattern matches empty text
//
//         // Handle patterns like a*, a*b*, a*b*c* etc.
//         for (int j = 1; j <= m; ++j) {
//             if (pattern[j - 1] == '*') {
//                 dp[0][j] = dp[0][j - 2];
//             }
//         }
//
//         for (int i = 1; i <= n; ++i) {
//             for (int j = 1; j <= m; ++j) {
//                 if (pattern[j - 1] == text[i - 1] || pattern[j - 1] == '.') {
//                     dp[i][j] = dp[i - 1][j - 1];
//                 } else if (pattern[j - 1] == '*') {
//                     dp[i][j] = dp[i][j - 2]; // Consider zero occurrence of character before '*'
//                     if (pattern[j - 2] == text[i - 1] || pattern[j - 2] == '.') {
//                         dp[i][j] = dp[i][j] || dp[i - 1][j]; // Consider one or more occurrence
//                     }
//                 }
//             }
//         }
//
//         return dp[n][m];
//     }
// };
//
// int main() {
//     Solution solution;
//
//     string text = "aa";
//     string pattern = "a*";
//     cout << (solution.isMatch(text, pattern) ? "true" : "false") << endl; // Output: true
//
//     text = "ab";
//     pattern = ".*";
//     cout << (solution.isMatch(text, pattern) ? "true" : "false") << endl; // Output: true
//
//     text = "aab";
//     pattern = "c*a*b";
//     cout << (solution.isMatch(text, pattern) ? "true" : "false") << endl; // Output: true
//
//     text = "mississippi";
//     pattern = "mis*is*p*.";
//     cout << (solution.isMatch(text, pattern) ? "true" : "false") << endl; // Output: false
//
//     return 0;
// }
