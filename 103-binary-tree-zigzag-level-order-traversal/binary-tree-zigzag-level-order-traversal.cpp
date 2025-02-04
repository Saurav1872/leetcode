/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};

        queue<TreeNode*> q({root});
        vector<vector<int>> ans;
        int rev = false;
        while (!q.empty()) {
            int size = q.size();
            vector<int> currLevel(size);
            int i = 0;
            while (size--) {
                TreeNode* curr = q.front();
                q.pop();
                if(rev) currLevel[size] = curr->val;
                else currLevel[i++] = curr->val;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            // if (rev)
            //     reverse(currLevel.begin(), currLevel.end());
            ans.push_back(currLevel);
            rev = !rev;
        }

        return ans;
    }
};