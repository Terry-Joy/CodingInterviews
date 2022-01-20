/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// dfs O(n) O(n)
class Solution {
  public:
    TreeNode *mirrorTree(TreeNode *root) {
        if (!root)
            return root;
        function<void(TreeNode *)> dfs = [&](TreeNode *root) {
            if (!root)
                return;
            auto it = root->right;
            root->right = root->left;
            root->left = it;
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        return root;
    }
};