class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);
            while (!q.empty() && q.back() - q.front() + 1 > k)
                q.pop_front();
            if (i >= k - 1)
                ans.emplace_back(nums[q.front()]);
        }
        return ans;
    }
};