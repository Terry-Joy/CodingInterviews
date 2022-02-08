//O(n) 等差数列
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size() * (nums.size() + 1) / 2;
        for(auto u : nums) {
            ans -= u;
        }
        return ans;
    }
};