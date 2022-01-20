class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size())  
            return 0;
        unordered_map<char, int> mp;
        int len = s.size(), ans = 0;
        vector<int> dp(len, 0);
        for (int i = 0; i < len; ++i) {
            if(!i)
                dp[i] = 1;
            else{
                dp[i] = dp[i-1] + 1;
                if(mp.count(s[i]))
                    dp[i] = min(dp[i], i - mp[s[i]]);
            }
            mp[s[i]] = i;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};