class Solution {
  public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;
        auto is = [&](int i, int j) {
            if (!i)
                return false; // 0只能与<=2的（x*)匹配
            if (p[j - 1] == '.')
                return true;
            else
                return s[i - 1] == p[j - 1];
        };
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] |= dp[i][j - 2];
                    if (is(i, j - 1)) {
                        dp[i][j] |= dp[i - 1][j];
                    }
                } else {
                    if (is(i, j))
                        dp[i][j] |= dp[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};