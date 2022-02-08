class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        int l = 1, r= 2, sum = 3;
        while (l < r) {
            while (sum < target) {
                r++;
                sum += r;
            }
            while(sum > target) {
                sum -= l;
                l++;
            }
            if(sum == target) {
                vector<int>a;
                for (int i = l; i <= r; ++i) {
                    a.emplace_back(i);
                }
                ans.emplace_back(a);
                sum -= l;
                l++;
            }
        }
        return ans;
    }
};