class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        dfs(rooms, 0, visited);

        for(bool v : visited) {
            if(!v) return false;
        }

        return true;
    }

private:
    void dfs(const vector<vector<int>>& rooms, int node, vector<bool>& visited) {
        visited[node] = true;
        for (int c : rooms[node])
            if (!visited[c])
                dfs(rooms, c, visited);
    }
};