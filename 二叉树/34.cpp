/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>>ans;
        vector<int>tmp;
		if(!root) return ans;
        tmp.push_back(root->val);
		function<void(TreeNode*,int)>dfs=[&](TreeNode*x,int num){
            if(num==expectNumber&&!x->left&&!x->right){
               ans.push_back(tmp);
               return;
            }
            if(x->left){
                tmp.push_back(x->left->val);
                dfs(x->left,num+x->left->val);
                tmp.pop_back();
            }
            if(x->right){
                tmp.push_back(x->right->val);
                dfs(x->right,num+x->right->val);
                tmp.pop_back();
            }
        };
        dfs(root,root->val);
        return ans;
    }
};