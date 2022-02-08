//O(n) dp
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1];
            if (s[i - 2] == '1')
                dp[i] += dp[i - 2];
            if(s[i - 2] == '2' && s[i - 1] >= '0' && s[i - 1] <= '5')
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};