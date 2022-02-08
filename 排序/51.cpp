//归并排序 分治 O(nlogn) O(n)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (!nums.size())
            return 0;
        vector<int> tmp(nums.size(), 0);
        long long ans = 0;
        function<void(int, int)> merge = [&](int l, int r) {
            if (l >= r)
                return;
            int mid = (l + r) >> 1;
            merge(l, mid);
            merge(mid + 1, r);
            int i = l, j = mid + 1, k = l;
            while (i <= mid && j <= r) {
                if (nums[i] <= nums[j]) {
                    tmp[k++] = nums[i++];
                } else {
                    tmp[k++] = nums[j++];
                    ans += mid - i + 1;
                }
            }
            while (i <= mid)
                tmp[k++] = nums[i++];
            while (j <= r)
                tmp[k++] = nums[j++];
            for (int i = l; i <= r; ++i)
                nums[i] = tmp[i];
        };
        merge(0, nums.size() - 1);
        return ans;
    }
};