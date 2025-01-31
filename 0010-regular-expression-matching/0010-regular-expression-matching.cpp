class Solution {
public:
    // /* Pure Recursion */
    // bool helper(string s, string p, int i, int j) {
    //     if(i == s.length() && j == p.length()) {
    //         return true;
    //     }

    //     if(j == p.length()) return false;

    //     // check normal case or case of '.'
    //     bool firstMatch = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

    //     // case of '*'
    //     if(j+1 < p.length() && p[j+1] == '*') {
    //         // case 1: skip current char for zero occurrence
    //         // case 2: use '*' to match one or more occurrence of s[i] but
    //         only if first Match is true
    //         //          because we are considering one or more not zero

    //         return helper(s, p, i, j+2) || (firstMatch && helper(s, p, i+1,
    //         j));
    //     }

    //     // case of no '*', then skip both
    //     return firstMatch && helper(s, p, i + 1, j + 1);
    // }

    // /* memo code */
    // bool helper(string s, string p, int i, int j, vector<vector<int>> &dp) {
    //     if(i == s.length() && j == p.length()) {
    //         return true;
    //     }

    //     if(j == p.length()) return false;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     bool firstMatch = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

    //     if(j+1 < p.length() && p[j+1] == '*') {
    //         return dp[i][j] = helper(s, p, i, j+2, dp) || (firstMatch &&
    //         helper(s, p, i+1, j, dp));
    //     }

    //     return dp[i][j] = firstMatch && helper(s, p, i+1, j+1, dp);
    // }

    bool isMatch(string s, string p) {

        /* Recursion Code Start */

        // return helper(s, p, 0, 0);

        /* Recursion Code End */

        /* Memo Code Start */

        // int n = s.length(), m = p.length();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return helper(s, p, 0, 0, dp);

        /* Memo Code End */



        /* Tabulation Code Start */
        
        int n = s.length(), m = p.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        // base case mapping
        dp[n][m] = true;

        for(int i = n; i>= 0; --i) {
            for(int j = m-1; j >= 0; --j) {
                bool firstMatch = i < n && (s[i] == p[j] || p[j] == '.');
                if(j+1 < m && p[j+1] == '*') {
                    dp[i][j] = dp[i][j+2] || (firstMatch && dp[i+1][j]);
                }
                else {
                    dp[i][j] = firstMatch && dp[i+1][j+1];
                }
            }
        }

        return dp[0][0];

        /* Tabulation Code End */
    }
};