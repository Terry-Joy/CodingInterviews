//O(bit n) O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0, st = 0;
        for (int i = 0; i < 31; ++i) {
            st = 0;
            for (auto u : nums) {
                if (u & (1 << i)) {
                    st = (st + 1) % 3;
                }
            }
            ans |= (st << i);
        }
        return ans;
    }
};