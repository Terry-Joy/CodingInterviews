class Solution {
  public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<string> ans;
        int len = s.size();
        vector<bool> vis(s.size(), 0);
        function<void(int, string)> dfs = [&](int now, string x) {
            if (now == s.size()) {
                ans.emplace_back(x);
                return;
            }
            for (int i = 0; i < len; ++i) {
                if (vis[i] || (i > 0 && (s[i] == s[i - 1] && !vis[i - 1])))
                    continue;
                vis[i] = 1;
                dfs(now + 1, x + s[i]);
                vis[i] = 0;
            }
        };
        dfs(0, "");
        return ans;
    }
};