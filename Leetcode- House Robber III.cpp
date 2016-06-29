//Typical DFS question. 用递归来做。

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
    int rob(TreeNode* root) {
        return max(dfs(root).first,dfs(root).second);
    }
    
    pair<int,int> dfs(TreeNode* root){
        if (root == NULL)
            return pair<int,int>(0,0);

        //if (root->left == NULL && root->right == NULL)
        //    return pair<int,int>(root->val,0);
        //cout << "hehe";
        pair<int,int> a = dfs(root->left);
        pair<int,int> b = dfs(root->right);
        
        int notRob = max(a.first, a.second) + max(b.first,b.second);
        int Rob = a.second + b.second + root->val;
        
        return pair<int,int>(Rob,notRob);
    }
    
    
};
