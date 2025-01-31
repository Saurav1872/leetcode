class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> sizes = {0, 0};
        int idCnt = 2, ans = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    sizes.push_back(bfs(grid, i, j, idCnt++, directions));
                }
            }
        }

        bool hasZero = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    hasZero = true;
                    unordered_set<int> neighbors;
                    int size = 1;

                    for (auto [dx, dy] : directions) {
                        int ni = i + dx, nj = j + dy;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                            grid[ni][nj] > 1) {
                            neighbors.insert(grid[ni][nj]);
                        }
                    }

                    for (int id : neighbors) {
                        size += sizes[id];
                    }

                    ans = max(ans, size);
                }
            }
        }

        return hasZero ? ans : n * m;
    }

private:
    int bfs(vector<vector<int>>& grid, int i, int j, int id, vector<pair<int, int>>& directions) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = id;
        int size = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    grid[nx][ny] == 1) {
                    grid[nx][ny] = id;
                    q.push({nx, ny});
                    size++;
                }
            }
        }
        return size;
    }
};