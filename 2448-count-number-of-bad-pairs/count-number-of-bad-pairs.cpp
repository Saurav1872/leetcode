class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hm;
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += i - hm[nums[i] - i]++;
        }

        return ans;
    }
};