/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//O(n)
class Solution {
  public:
    bool isBalanced(TreeNode *root) {
        if (!root)
            return true;
        bool flag = 1;
        function<int(TreeNode *)> dfs = [&](TreeNode *x) {
            if (!x->left && !x->right) {
                return 1;
            }
            int h1 = (x->left) ? dfs(x->left) : 0;
            int h2 = (x->right) ? dfs(x->right) : 0;
            if (abs(h1 - h2) > 1)
                flag = 0;
            return max(h1, h2) + 1;
        };
        dfs(root);
        return flag;
    }
};