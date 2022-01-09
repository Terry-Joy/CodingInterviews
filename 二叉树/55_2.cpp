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
    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;
        queue<pair<TreeNode *, int>> q;
        int ans = 1;
        q.push({root, 1});
        while (q.size()) {
            pair<TreeNode *, int> x = q.front();
            q.pop();
            ans = max(ans, x.second);
            if (x.first->left)
                q.push({x.first->left, x.second + 1});
            if (x.first->right)
                q.push({x.first->right, x.second + 1});
        }
        return ans;
    }
};