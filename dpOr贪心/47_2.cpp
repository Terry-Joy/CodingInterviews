//O(n^2) O(n^2)
class Solution {
public:
    int maxValue(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(!i && !j)
                    continue;
                int x = grid[i][j];
                if(i - 1 >= 0)
                    grid[i][j] = max(grid[i][j], grid[i - 1][j] + grid[i][j]);
                if(j - 1 >= 0)
                    grid[i][j] = max(grid[i][j], grid[i][j - 1] + x);
            }
        }
        return grid[m - 1][n - 1];
    }
};