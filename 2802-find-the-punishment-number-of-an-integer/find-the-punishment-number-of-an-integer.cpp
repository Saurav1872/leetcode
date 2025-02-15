class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(check(0, 0, to_string(i*i), 0, i)) {
                ans += i * i;
            }
        }
        return ans;
    }

private:
    bool check(int ac, int rn, const string &numChar, int s, int target) {
        if(s == numChar.length()) return target == ac + rn;

        const int d = numChar[s] - '0';
        return check(ac, rn*10 + d, numChar, s + 1, target)
            || check(ac + rn, d, numChar, s + 1, target);
    }
};