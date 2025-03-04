class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node, int dest, vector<int> curr,
             vector<vector<int>>& ans) {
        curr.push_back(node);
        if (node == dest) {
            ans.push_back(curr);
            return;
        }
        for (int neighbor : adj[node]) {
            dfs(adj, neighbor, dest, curr, ans);
        }
        curr.pop_back();
    } 
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        dfs(graph, 0, graph.size()-1, {}, ans);
        return ans;
    }
};