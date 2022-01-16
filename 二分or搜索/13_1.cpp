class Solution {
  public:
    int movingCount(int m, int n, int k) {
        vector<int> dx = {1, 0};
        vector<int> dy = {0, 1};
        vector<vector<bool>> vis(m, vector<bool>(n, 0)),
            wrong(m, vector<bool>(n, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;
        while (!q.empty()) {
            pair<int, int> x = q.front();
            q.pop();
            auto getBit = [&](int x) {
                int sum = 0;
                while (x) {
                    sum += x % 10;
                    x /= 10;
                }
                return sum;
            };
            auto Wrong = [&](int x, int y) {
                return getBit(x) + getBit(y) > k;
            };
            auto check = [&](int x, int y) {
                return x >= 0 && x <= m - 1 && y >= 0 && y <= n - 1;
            };
            for (int i = 0; i < 2; ++i) {
                int xx = x.first + dx[i];
                int yy = x.second + dy[i];
                if (!check(xx, yy))
                    continue;
                if (Wrong(xx, yy))
                    wrong[xx][yy] = 1;
                if (vis[xx][yy] || wrong[xx][yy])
                    continue;
                vis[xx][yy] = 1;
                q.push({xx, yy});
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!wrong[i][j] && vis[i][j])
                    ans++;
            }
        }
        return ans;
    }
};