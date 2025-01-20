class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();     // rows
        int m = mat[0].size();  // cols

        vector<int> rows(n, m);
        vector<int> cols(m, n);

        unordered_map<int, int> hm;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                hm[mat[i][j]] = i * m + j;
            }
        }

        for(int i = 0; i < arr.size(); ++i) {
            int x = hm[arr[i]];
            int r = x / m;
            int c = x % m;
            rows[r]--;
            cols[c]--;
            if(rows[r] == 0 || cols[c] == 0) return i;
        }

        return -1;

    }
};