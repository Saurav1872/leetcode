/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string &traversal, int level = 0) {
        if(traversal.length() == 0) return nullptr;

        int count = 0;
        int i = 0;
        while(i < traversal.length()) {
            if(traversal[i] == '-') {
                count++;
                i++;
            }
            else {
                break;
            }
        }

        if(count == level) {
            string num = "";
            char ch;
            while(i < traversal.length()) {
                ch = traversal[i];
                if(isdigit(ch)) {
                    num += ch;
                    ++i;
                }
                else {
                    break;
                }
            }
            TreeNode* node = new TreeNode(stoi(num));
            traversal = traversal.substr(i);
            node->left = recoverFromPreorder(traversal, level+1);
            node->right = recoverFromPreorder(traversal, level+1);
            return node;
        }
        else {
            return nullptr;
        }
    }
};