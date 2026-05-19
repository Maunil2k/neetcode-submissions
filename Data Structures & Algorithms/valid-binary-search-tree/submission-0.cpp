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
    bool isValidBST(TreeNode* root) {
        if (root->left) {
            if (root->val > root->left->val) return isValidBST(root->left);
            else return false;
        }
        if (root->right) {
            if (root->val < root->right->val) return isValidBST(root->right);
            else return false; 
        }
        return true;
    }
};
