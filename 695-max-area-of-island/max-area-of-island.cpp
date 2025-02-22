class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j) {
                int area = dfs(grid, i, j);
                if(area > maxArea) maxArea = area;
            }

        return maxArea;
    }

private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
            return 0;
        if (grid[i][j] != 1)
            return 0;

        grid[i][j] = 0;

        return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
    }
};