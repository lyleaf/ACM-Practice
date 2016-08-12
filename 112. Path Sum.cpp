/**https://leetcode.com/problems/path-sum/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 简单版PathSum,本以为自己写得不错，结果又有一个三行代码..
 */
class Solution {
public:
    void hasPathSumHelper(TreeNode* root, int s, bool &flag){
        s = s - root->val;
        if (!root->left && !root->right){
            if (s==0) {
                flag = true;
                return;
            }
        }
        if (root->left) hasPathSumHelper(root->left,s,flag);
        if (root->right) hasPathSumHelper(root->right,s,flag);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        bool flag = false;
        hasPathSumHelper(root, sum, flag);
        return flag;
    }
};

/*
用root->right == root->left来判断是否当前是叶子结点
如果不是，则分别向左右重新进行DFS.
如果叶子结点不是，只要不返回false就好了。而不需要专门用一个flag去存储。
*/
bool hasPathSum(TreeNode* root, int sum) {
    if(root == NULL)  return false;
    if(root->right == root->left)  return sum == root->val;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val) ;
}
