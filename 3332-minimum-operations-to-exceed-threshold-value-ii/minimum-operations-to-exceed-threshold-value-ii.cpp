class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        int count = 0;

        long long x = pq.top();
        pq.pop();
        long long y = pq.top();
        pq.pop();
        while(x < k) {
            ++count;
            long long a = min(x, y) * 2 + max(x, y);
            pq.push(a);

            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();
        }

        return count;

    }
};