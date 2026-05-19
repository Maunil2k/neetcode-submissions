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
    bool recursiveFunc(TreeNode *root, long lb, long rb) {
        if (!root) return true;
        if (root->val > lb && root->val < rb) {
            return recursiveFunc(root->left, lb, root->val) && recursiveFunc(root->right, root->val, rb);
        }
        else return false;
    }
    bool isValidBST(TreeNode* root) {
        return recursiveFunc(root, LONG_MIN, LONG_MAX);
    }
};
