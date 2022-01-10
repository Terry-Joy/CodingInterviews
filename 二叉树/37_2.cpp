/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//dfs O(n) 前序编码
class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (!root)
            return "";
        string ans = "";
        function<void(TreeNode *)> dfs = [&](TreeNode *x) {
            if (!x) {
                ans += "null,";
                return;
            } else {
                ans += to_string(x->val);
                ans += ",";
            }
            dfs(x->left);
            dfs(x->right);
        };
        dfs(root);
        ans.erase(ans.end() - 1);
        // cout<<ans;
        return ans;
    }
    // Decodes your encoded data to tree.
    TreeNode *dfs(queue<string> &ans) {
        auto it = ans.front();
        ans.pop();
        if (it == "null")
            return nullptr;
        TreeNode *root = new TreeNode(stoi(it));
        root->left = dfs(ans);
        root->right = dfs(ans);
        return root;
    }
    TreeNode *deserialize(string data) {
        if (!data.size())
            return nullptr;
        queue<string> ans;
        auto split = [&](string s) {
            int st = 0, ed = 0, n = s.size();
            while (st != n) {
                ed = s.find_first_of(",", st);
                if (ed == -1) {
                    ed = n;
                    string tmp = s.substr(st, ed - st);
                    ans.push(tmp);
                    break;
                } else {
                    string tmp = s.substr(st, ed - st);
                    ans.push(tmp);
                }
                st = ed + 1;
            }
        };
        split(data);
        TreeNode *root = dfs(ans);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));