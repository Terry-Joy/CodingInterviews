/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//递归 O(n) O(n)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        function<bool(TreeNode*, TreeNode*, TreeNode*)> dfs = [&](TreeNode* root, TreeNode* p, TreeNode* q) {
            if(!root)  //dfs(rt,p,q) 表示rt中是否有p或者q
                return false;
            bool l = dfs(root->left, p, q);
            bool r = dfs(root->right, p, q);
            bool f=0;            
            if((l&&r) || ((root->val == p->val || root->val == q->val) && (l||r))) 
                ans = root, f=1;
            return l || r || (root->val == p->val ) || (root->val == q->val);
        };
        dfs(root, p, q);
        return ans;
    }
};