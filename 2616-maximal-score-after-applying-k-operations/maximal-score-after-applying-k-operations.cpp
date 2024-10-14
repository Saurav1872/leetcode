class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i : nums) {
            pq.push(i);
        }

        long long score = 0;
        while(!pq.empty() && k > 0) {
            int x = pq.top();
            pq.pop();
            score += x;
            x = ceil((double)x / 3);
            if(x > 0) pq.push(x);
            --k;
        }

        return score;
    }
};