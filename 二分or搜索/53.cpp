class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(!nums.size())
            return 0;
        int cnt = 0;
        int l = 0, r = nums.size();
        while(l < r) {
            int mid = l + r >> 1;
            if(nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        if(r == nums.size() || nums[r] != target)
            return 0;
        int fi = r;
        l = 0, r = nums.size();
        while(l < r) {
            int mid = l + r >> 1;
            if(nums[mid] > target)
                r = mid;
            else 
                l = mid + 1;
        }
        r--;
        return r - fi + 1;
    }
};