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
    // returns max value with the split
    int dfs(TreeNode* root, int &res) {
        if (!root) return 0;
        int l = dfs(root->left,res);
        int r = dfs(root->right, res);
        l = max(0, l);
        r = max(0, r);
        // Compute the max path without splitting 
        res = max(res, root->val+l+r);
        return root->val + max(l, r);
    }
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        dfs(root, res);
        return res;
    }
};
