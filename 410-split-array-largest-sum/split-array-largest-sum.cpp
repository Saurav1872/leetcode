class Solution {
public:
    bool isPossible(vector<int>&nums, int k, int mid) {
        int n = nums.size();
        int split = 1;
        int currSum = 0;
        for(int i = 0; i < n; ++i) {
            if(currSum + nums[i] > mid) {
                ++split;
                currSum = nums[i];
            }
            else {
                currSum += nums[i];
            }
        }

        return split <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int max = 0;
        int sum = 0;

        for(int i : nums) {
            if(i > max) max = i;
            sum += i;
        }


        int left = max, right = sum;
        int mid;
        int ans = 0;
        while(left <= right) {
            mid = left + (right - left) / 2;

            if(isPossible(nums, k, mid)) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};