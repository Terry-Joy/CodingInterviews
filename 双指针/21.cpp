//two pointers O(n) O(1)
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(!nums.size())
            return nums;
        int l = 0, r = nums.size() - 1;
        auto isOdd = [&](int x){
            return x & 1;
        };
        while(l < r) {
            while(l < r && isOdd(nums[l]))
                l++;
            while(l < r && !isOdd(nums[r]))
                r--;
            swap(nums[l], nums[r]);
        }
        return nums;
    }
};