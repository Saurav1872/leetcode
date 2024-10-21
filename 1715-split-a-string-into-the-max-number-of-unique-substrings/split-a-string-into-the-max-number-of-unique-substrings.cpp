class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> hs;
        return helper(s, 0, hs);
    }

    int helper(const string &s, int idx, unordered_set<string> &hs) {
        if(idx == s.length()) {
            return hs.size();
        }

        int ans = 0;
        for(int i = idx; i < s.length(); ++i) {
            string current = s.substr(idx, i - idx + 1);

            if(hs.find(current) == hs.end()) {
                hs.insert(current);
                ans = max(ans, helper(s, i+1, hs));
                hs.erase(current);
            }
        }

        return ans;
        

    }
};