class Solution {
public:
    int minSwaps(string s) {
        int notMatch = 0;
        for(char c : s) {
            if(c == '[') {
                ++notMatch;
            }
            else if(notMatch > 0) {
                --notMatch;
            }
        }

        return (notMatch+1) / 2;
    }
};