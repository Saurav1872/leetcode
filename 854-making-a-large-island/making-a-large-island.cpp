class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> sizes{0, 0};
        int idCnt = 2;      // 0 and 1 are reserve as its binary grid

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 1) {
                    sizes.push_back(dfs(grid, i, j, idCnt++));
                }
            }
        }

        vector<pair<int, int>> dir = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        int ans = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 0) {
                    unordered_set<int> s;
                    for(auto [dx, dy] : dir) {
                        int ni = i + dx, nj = j + dy;
                        if(ni < 0 || ni >= grid.size() || nj < 0 || nj >= grid[0].size()) continue;
                        s.insert(grid[ni][nj]);
                    }
                    int size = 1;
                    for(int id : s) {
                        size += sizes[id];
                    }
                    ans = max(ans, size);
                    
                }
            }
        }


        return ans == 0 ? n * m : ans;

    }

private:
    int dfs(vector<vector<int>>& grid, int i, int j, int id) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) {
            return 0;
        }

        grid[i][j] = id;


        return 1 + dfs(grid, i+1, j, id) + dfs(grid, i, j+1, id)
                 + dfs(grid, i-1, j, id) + dfs(grid, i, j-1, id);

    }
};