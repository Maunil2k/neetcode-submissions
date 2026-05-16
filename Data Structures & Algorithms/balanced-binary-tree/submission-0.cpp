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
    int maxh(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(maxh(root->left), maxh(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int lh = maxh(root->left);
        int rh = maxh(root->right);
        if (abs(lh-rh) > 1) return false;
        else return isBalanced(root->left) && isBalanced(root->right); 
    }
};
