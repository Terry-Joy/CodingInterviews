#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
    vector<vector<vector<int>>> dp(35,
                                   vector<vector<int>>(2, vector<int>(35, -1)));
    vector<int> bit;
    function<int(int, bool, int)> dfs = [&](int pos, bool limit, int sum) {
        if (pos == -1)
            return sum;
        if (dp[pos][limit][sum] != -1)
            return dp[pos][limit][sum];
        int up = limit ? bit[pos] : 9;
        int ans = 0;
        for (int i = 0; i <= up; ++i) {
            ans += dfs(pos - 1, limit && i == up, sum + (i == 1));
        }
        dp[pos][limit][sum] = ans;
        return ans;
    };
    auto solve = [&](int x) {
        int pos = 0;
        while (x) {
            bit.emplace_back(x % 10);
            x /= 10;
        }
        return dfs(pos - 1, true, 0);
    };
    cout << solve(n);
}