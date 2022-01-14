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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        int flag = 0;
        q.push(root);
        while (!q.empty()) {
            vector<int> tmp;
            vector<TreeNode *> tmp2;
            for (int i = q.size(); i; --i) { //按层取走
                auto it = q.front();
                tmp2.emplace_back(it);
                q.pop();
                tmp.emplace_back(it->val);
            }
            while (tmp2.size()) { //模拟栈重新扔进去
                auto it = tmp2.back();
                tmp2.pop_back();
                if (flag) {
                    if (it->left)
                        q.push(it->left);
                    if (it->right)
                        q.push(it->right);
                } else {
                    if (it->right)
                        q.push(it->right);
                    if (it->left)
                        q.push(it->left);
                }
            }
            flag ^= 1;
            ans.emplace_back(tmp);
        }
        return ans;
    }
};