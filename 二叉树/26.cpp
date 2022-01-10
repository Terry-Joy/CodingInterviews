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
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        function<bool(TreeNode *, TreeNode *)> is = [&](TreeNode *a,
                                                        TreeNode *b) {
            if (!b)
                return true;
            if (!a || a->val != b->val)
                return false;
            return is(a->left, b->left) && is(a->right, b->right);
        };
        if (!B || !A)
            return false;
        return is(A, B) || isSubStructure(A->left, B) ||
               isSubStructure(A->right, B);
    }
};