/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inorderTraversalHelper(TreeNode* root, vector<int>& x) {
        if (!root) return;
        if (root->left)
            inorderTraversalHelper(root->left,x);
        x.push_back(root->val);
        if (root->right)
            inorderTraversalHelper(root->right,x);
    }
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> x;
        inorderTraversalHelper(root,x);
        return x;
    }
};
