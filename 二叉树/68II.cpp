/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//递归，两条路径取点，O(n) O(n)
class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        vector<TreeNode *> path1, path2, tmp;
        tmp.emplace_back(root);
        function<void(vector<TreeNode *> &, TreeNode *, TreeNode *)> dfs =
            [&](vector<TreeNode *> &ans, TreeNode *now, TreeNode *x) {
                if (now == x) {
                    ans = tmp;
                    return;
                }
                if (now->left) {
                    tmp.emplace_back(now->left);
                    dfs(ans, now->left, x);
                    tmp.pop_back();
                }
                if (now->right) {
                    tmp.emplace_back(now->right);
                    dfs(ans, now->right, x);
                    tmp.pop_back();
                }
            };
        dfs(path1, root, p);
        tmp.clear();
        tmp.emplace_back(root);
        dfs(path2, root, q);
        int len = min(path1.size(), path2.size());
        int now = 0;
        while (now < len && path1[now] == path2[now])
            now++;
        now--;
        return path1[now];
    }
};