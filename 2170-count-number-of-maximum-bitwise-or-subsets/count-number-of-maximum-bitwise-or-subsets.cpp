class Solution {
public:
    int count = 0;
    void helper(vector<int>& nums, int idx, int curr, int maxor) {
        if(idx == nums.size()) {
            if(maxor == curr) ++count;
            return;
        };

        helper(nums, idx+1, curr, maxor);
        helper(nums, idx+1, curr | nums[idx], maxor);
    }


    int countMaxOrSubsets(vector<int>& nums) {
        int maxor = 0;
        for(int i : nums) {
            maxor |= i;
        }

        helper(nums, 0, 0, maxor);
        return count;
    }
};