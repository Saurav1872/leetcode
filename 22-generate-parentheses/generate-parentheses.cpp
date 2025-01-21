class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, n, n, "");
        return ans;
    }

    void helper(vector<string>& result, int open, int close,
                string currentstr) {

        if (open > 0) {
            helper(result, open - 1, close, currentstr + "(");
        }
        if (close > open) {
            helper(result, open, close - 1, currentstr + ")");
        }
        if (open + close == 0) {
            result.push_back(currentstr);
        }
    }
};