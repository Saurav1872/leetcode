class Solution {
    unordered_map<string, bool> dp;

public:
    bool isScramble(string s1, string s2) {
        // cout<<s1<<"-"<<s2<<endl;
        string memo = s1 + "-" + s2;
        if (dp.find(memo) != dp.end())
            return dp[memo];
        if (s1 == s2)
            return true;

        int n = s1.length();

        for (int i = 1; i < n; i++) {
            // no swap
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))) {
                dp[memo] = true;
                return true;
            }
            // swap
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i))) {
                dp[memo] = true;
                return true;
            }
        }

        return dp[memo] = false;
    }
};