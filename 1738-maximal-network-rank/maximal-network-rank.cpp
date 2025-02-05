class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> count(n, 0);
        vector<vector<bool>> connected(n, vector<bool>(n, false));
        for(auto edge : roads) {
            count[edge[0]]++;
            count[edge[1]]++;
            connected[edge[0]][edge[1]] = true;
            connected[edge[1]][edge[0]] = true;

        }

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                int rank = count[i] + count[j];
                if(connected[i][j]) rank -= 1;

                ans = max(ans, rank);
            }
        }

        return ans;
    }
};