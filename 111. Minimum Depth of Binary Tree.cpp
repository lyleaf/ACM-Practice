/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 我觉得我应该被定在耻辱柱上。这么一个简单的题写了这么久还写得这么丑。
 我是用BFS，就算是BFS也不能写这么长。一搜果然发现有3行代码板。不过是用的是DFS。
 
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right){
            return 1;
        }
        bool flag = true;
        int r = 1;
        queue<TreeNode*> q; 
        q.push(root);
        queue<TreeNode*> qTemp;
        while (true){
            while(!q.empty()){
                TreeNode* x = q.front();
                q.pop();
                if (!x->left && !x->right) return r;
                else {
                    if (x->left)
                        qTemp.push(x->left);
                    if (x->right)
                        qTemp.push(x->right);
                }
            }
            q.swap(qTemp);
            r++;
        }
    }
};


int minDepth(TreeNode* root) {
    if (!root) return 0;
    int L = minDepth(root->left), R = minDepth(root->right);
    return 1 + (min(L, R) ? min(L, R) : max(L, R));
}

/*
看看人家的BFS版,用了一个Q，这样就不用Q.swap(tempQ)了。
可以的原因是它用了Q.size()。而我忘记了Q.size()这个函数。
*/

int minDepth(TreeNode* root) {
    if (root == NULL) return 0;
    queue<TreeNode*> Q;
    Q.push(root);
    int i = 0;
    while (!Q.empty()) {
        i++;
        int k = Q.size();
        for (int j=0; j<k; j++) {
            TreeNode* rt = Q.front();
            if (rt->left) Q.push(rt->left);
            if (rt->right) Q.push(rt->right);
            Q.pop();
            if (rt->left==NULL && rt->right==NULL) return i;
        }
    }
    return -1; //For the compiler thing. The code never runs here.
}
