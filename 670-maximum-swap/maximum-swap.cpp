class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int> lastIdx(10, -1);

        for(int i = 0; i < s.length(); ++i) {
            lastIdx[s[i]-'0'] = i;
        }

        for(int i = 0; i < s.length(); ++i) {
            for(int d = 9; d > s[i] - '0'; --d) {
                if(lastIdx[d] > i) {
                    swap(s[i], s[lastIdx[d]]);
                    return stoi(s);
                }
            }
        }

        return num;
    }
};