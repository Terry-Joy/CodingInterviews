//分组异或 O(n) O(1)
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ans = 0;
        for (auto u : nums)
            ans ^= u;
        int i = 0, bit;
        while (ans) {
            if (ans & 1) {
                bit = i;
                break;
            }
            ++i;
            ans >>= 1;
        }
        int ans1 = 0, ans2 = 0;
        for (auto u : nums) {
            if (u & (1 << bit)) {
                ans1 ^= u;
            } else {
                ans2 ^= u;
            }
        }
        return {ans1, ans2};
    }
};