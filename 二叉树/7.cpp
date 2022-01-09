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
    unordered_map<int,int>mp;
    TreeNode* find(vector<int>&preorder,vector<int>&inorder,int root,int L,int R){
        if(L>R)return NULL;
        int pos=mp[preorder[root]];
        TreeNode*rt=new TreeNode(inorder[pos]);
        rt->left=find(preorder,inorder,root+1,L,pos-1);
        rt->right=find(preorder,inorder,root+(pos-L+1),pos+1,R);
        return rt;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();++i){
            mp[inorder[i]]=i;
        }
        return find(preorder,inorder,0,0,inorder.size()-1);
    }
};