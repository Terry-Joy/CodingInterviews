// two pointers O(n) O(n)
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        if (!s.size())
            return 0;
        unordered_map<char, int> mp;
        int len = s.size(), ans = 0;
        int l = 0, r = 0;
        while (r < len) {
            if (mp[s[r]]) {
                while (l <= r && mp[s[r]]) {
                    mp[s[l++]] = 0;
                }
            }
            mp[s[r]] = 1;
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};