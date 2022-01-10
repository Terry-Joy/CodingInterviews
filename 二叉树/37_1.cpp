/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//O(n) 层序编码
class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (!root)
            return "";
        string ans = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            if (!it) {
                ans += "null,";
            } else {
                ans += to_string(it->val);
                ans += ',';
                q.push(it->left);
                q.push(it->right);
            }
        }
        ans.erase(ans.end() - 1);
        return ans;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (!data.size())
            return nullptr;
        vector<string> ans;
        auto split = [&](string s) {
            int st = 0, ed = 0, n = s.size();
            while (st != n) {
                ed = s.find_first_of(",", st);
                if (ed == -1) {
                    ed = n;
                    string tmp = s.substr(st, ed - st);
                    ans.emplace_back(tmp);
                    break;
                } else {
                    string tmp = s.substr(st, ed - st);
                    ans.emplace_back(tmp);
                }
                st = ed + 1;
            }
        };
        split(data);
        TreeNode *root = new TreeNode(stoi(ans[0]));
        int i = 1;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            if (i < ans.size() && ans[i] != "null") {
                it->left = new TreeNode(stoi(ans[i]));
                q.push(it->left);
            }
            i++;
            if (i < ans.size() && ans[i] != "null") {
                it->right = new TreeNode(stoi(ans[i]));
                q.push(it->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));