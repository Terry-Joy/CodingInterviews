//dp O(n*m) O(n*m)	
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<int> dx = {1, 0};
        vector<int> dy = {0, 1};
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vis[0][0] = 1;
        auto getBit = [&](int x) {
            int sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            return sum;
        };
        int ans = 1;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if((!i && !j) || getBit(i) + getBit(j) > k)
                    continue;
                if(i - 1 >= 0)
                    vis[i][j] |= vis[i-1][j];
                if(j - 1 >= 0)
                    vis[i][j] |= vis[i][j-1];                                   
                ans += vis[i][j];
            }
        }
        return ans;
    }
};