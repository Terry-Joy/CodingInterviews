/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param proot TreeNode类 
     * @param k int整型 
     * @return int整型
     */
    int KthNode(TreeNode* proot, int k) {
        // write code here
        vector<int>ans;
        if(!proot||!k)return -1;
        function<void(TreeNode*)>dfs=[&](TreeNode*x){
            if(x->left){
                dfs(x->left);
            }
            ans.push_back(x->val);
            if(x->right){
                dfs(x->right);
            }
        };
        dfs(proot);
        return (k>ans.size())?-1:ans[k-1];
    }
};