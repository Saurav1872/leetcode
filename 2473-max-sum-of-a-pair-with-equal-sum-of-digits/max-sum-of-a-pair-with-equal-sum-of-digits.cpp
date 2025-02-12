class Solution {
public:
    int  digitSum(int n) {
        int sum = 0;
        while(n) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hm;
        int ans = -1;
        for(int i=0; i < n; ++i) {
            int sum = digitSum(nums[i]);
            if(hm.find(sum) != hm.cend()) {
                int prevIdx = hm[sum];
                ans = max(ans, nums[i] + nums[prevIdx]);
                if(nums[i] > nums[prevIdx]) hm[sum] = i;
            }
            else {
                hm[sum] = i;
            }
        }

        return ans;
    }
};