// dp O(n^2) O(n^2)
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp = {0, 1, 1, 2, 4};
        if(n <= 4)
            return dp[n];
        dp.resize(n + 1);
        for(int len = 5; len <= n; ++len) {
            for(int j = 1; j < len; ++j) {
                dp[len] = max(dp[len], max(j*(len - j), j * dp[len - j]));
            }
        }
        return dp[n];
    }
};