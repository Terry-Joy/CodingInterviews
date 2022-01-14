/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/ 
//O(n) O(n)
class Solution {
  public:
    Node *treeToDoublyList(Node *root) {
        if (!root)
            return root;
        Node *head, *pre;
        function<void(Node *)> dfs = [&](Node *rt) {
            if (!rt)
                return;
            dfs(rt->left);
            if (!pre) {
                head = root;
            } else {
                pre->right = root;
                root->left = pre;
            }
            pre = rt;
            dfs(rt->right);
        };
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
};