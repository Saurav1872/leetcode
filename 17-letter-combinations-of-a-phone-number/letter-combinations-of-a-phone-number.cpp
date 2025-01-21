class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> keypad{"abc", "def",  "ghi", "jkl",
                              "mno", "pqrs", "tuv", "wxyz"};
        if (digits.length())
            return findCombi(keypad, digits, "", 0);
        else
            return {};
    }

    vector<string> findCombi(vector<string>& keypad, string dialed, string curr,
                             int x) {
        int n = dialed.length();
        vector<string> ans, temp;
        if (x == n) {
            ans.push_back(curr);
            return ans;
        }

        for (char c : keypad[dialed[x] - '0' - 2]) {
            temp = findCombi(keypad, dialed, curr + c, x + 1);
            for (auto z : temp) {
                ans.push_back(z);
            }
        }

        return ans;
    }
};