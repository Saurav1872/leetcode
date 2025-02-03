class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int curr = 1;
        int curr2 = 1;
        int prev = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] > prev) {
                ++curr;
            }
            else {
                ans = max(ans, curr);
                curr = 1;
            }

            if(nums[i] < prev) {
                ++curr2;
            }
            else {
                ans = max(ans, curr2);
                curr2 = 1;
            }
            prev = nums[i];
        }

        ans = max(ans, max(curr, curr2));
        return ans;
    }

};