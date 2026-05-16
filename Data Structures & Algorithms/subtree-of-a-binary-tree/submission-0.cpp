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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        else if (root && subRoot) {
            if (root->val == subRoot->val) return isSubtree(root->left, subRoot->left) && isSubtree(root->right, subRoot->right);
            else return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
        else return false;
    }
};
