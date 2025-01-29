class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
        while (j >= i) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            int minCost = INT_MAX;
            for (int j = i; j < n; ++j) {
                if (isPalindrome(s, i, j)) {
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }

            dp[i] = minCost;
        }

        return dp[0] - 1;
    }
};