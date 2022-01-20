//dp O(n^2) O(n^2)
class Solution {
public:
    int maxValue(vector<vector<int>> &grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!i && !j)
                    continue;
                if (i - 1 >= 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + grid[i][j]);
                if (j - 1 >= 0)
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }
        return dp[m - 1][n - 1];
    }
};