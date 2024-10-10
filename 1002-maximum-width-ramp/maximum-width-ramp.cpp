class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans = 0;
        stack<int> st;

        for(int i = 0; i < nums.size(); ++i) {
            if(st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }

        for(int i = nums.size() - 1; i > ans; --i) {
            while(!st.empty() && nums[i] >= nums[st.top()]) {
                ans = max(ans, i - st.top());
                st.pop();
            }
        }

        return ans;
    }
};