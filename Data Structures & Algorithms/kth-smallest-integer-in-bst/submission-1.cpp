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
    int kthSmallest(TreeNode* root, int k) {
        // stack<TreeNode *> s;
        // s.push(root);
        // while (!s.empty()) {
        //     TreeNode *top = s.top();
        //     if (top->left) {
        //         s.push(top->left);
        //         top->left = nullptr;
        //     }
        //     else {
        //         s.pop();
        //         k--;
        //         if (k==0) return top->val;
        //         if (top->right) {
        //             s.push(top->right);
        //             top->right = nullptr; 
        //         }
        //     }
        // }
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while (curr != nullptr || !st.empty()) {
            // Go as far left as possible
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            
            // Process the current node
            curr = st.top();
            st.pop();
            
            k--; // We've found the next smallest element
            if (k == 0) {
                return curr->val;
            }
            
            // Move to the right subtree
            curr = curr->right;
        }
        
        return -1;
    }
};
