//O(n) O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        int ans = 0;
        for (auto [u,v] : mp) {
            if (v == 1) {
                ans = u;
                break;
            }
        }
        return ans;
    }
};