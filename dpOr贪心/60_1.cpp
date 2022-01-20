class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> ans;
        vector<vector<double>> dp(n + 1, vector<double>(n * 6 + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i * 6; ++j) {
                for (int k = 1; k <= 6; ++k) {
                    dp[i + 1][k + j] += dp[i][j] * 1.0/6;
                }
            }
        }
        for (int i = n; i <= 6 * n; ++i) {
            ans.emplace_back(dp[n][i]);
        }
        return ans;
    }
};