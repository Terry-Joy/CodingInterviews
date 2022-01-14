/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//O(n) O(1) 迭代
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root) {
            if(p->val < root ->val && q->val < root->val) 
                root = root -> left;
            else if(p->val > root ->val && q->val > root->val) 
                root = root -> right; 
            else break;
        }
        return root;
    }
};