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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        ans.push_back(root->val);
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(it->left){
                q.push(it->left);
                ans.push_back(it->left->val);
            }
            if(it->right){
                q.push(it->right);
                ans.push_back(it->right->val);
            }
        }
        return ans;
    }
};