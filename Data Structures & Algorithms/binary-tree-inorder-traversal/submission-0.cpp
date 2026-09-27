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
private:
    void dfs(vector<int>& res, TreeNode* root) {
        if (root -> left) dfs(res, root->left);
        res.push_back(root->val);
        if (root -> right) dfs(res, root->right);
        return;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        dfs(res, root);
        return res;
    }
};