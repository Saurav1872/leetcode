class Solution {
public:

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
    //         // case 2: use '*' to match one or more occurrence of s[i] but only if first Match is true 
    //         //          because we are considering one or more not zero

    //         return helper(s, p, i, j+2) || (firstMatch && helper(s, p, i+1, j));
    //     }

    //     // case of no '*', then skip both 
    //     return firstMatch && helper(s, p, i + 1, j + 1);
    // }

    bool helper(string s, string p, int i, int j, vector<vector<int>> &dp) {
        if(i == s.length() && j == p.length()) {
            return true;
        }

        if(j == p.length()) return false;

        if(dp[i][j] != -1) return dp[i][j];

        bool firstMatch = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

        if(j+1 < p.length() && p[j+1] == '*') {
            return dp[i][j] = helper(s, p, i, j+2, dp) || (firstMatch && helper(s, p, i+1, j, dp));
        }

        return dp[i][j] = firstMatch && helper(s, p, i+1, j+1, dp);
    }



    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return helper(s, p, 0, 0, dp);
    }
};