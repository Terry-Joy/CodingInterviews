/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
//递归
class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        if(!pRoot)return 0;
        return max(TreeDepth(pRoot->left),TreeDepth(pRoot->right))+1;
    }
};