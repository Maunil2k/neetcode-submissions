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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            for (int i =0; i<n; i++) {
                TreeNode* front = q.front();
                q.pop();
                if (front) {
                    tmp.push_back(front->val);
                    q.push(front->left);
                    q.push(front->right);
                }
            }
            if (tmp.size()) ans.push_back(tmp.back());
        }
        return ans;
    }
};
