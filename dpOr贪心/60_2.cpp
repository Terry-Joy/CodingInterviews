//dp O(n^2) O(n)
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> ans;
        vector<double> dp(6 * n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            vector<double> tmp(6 * (i + 1) + 1, 0);
            for (int j = 0; j <= i * 6; ++j) {
                for (int k = 1; k <= 6; ++k) {
                    tmp[j + k] += dp[j] * 1.0 / 6;
                }
            }
            for (int j = 0; j <= 6 * (i + 1); ++j) {
                dp[j] = tmp[j];
            }
        }
        for (int i = n; i <= 6 * n; ++i) {
            ans.emplace_back(dp[i]);
        }
        return ans;
    }
};