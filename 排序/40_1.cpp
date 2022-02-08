//大根堆 O(nlogk) O(k)
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.size() < k)
            return arr;
        vector<int> ans;
        if(!k)
            return ans;
        priority_queue<int> q;
        for (int i : arr) {
            if (q.size() < k) {
                q.push(i);
            } else if (q.size() == k && q.top() > i) {
                q.pop();
                q.push(i);
            }
        }
        while(!q.empty()) {
            ans.emplace_back(q.top());
            q.pop();
        }
        return ans;
    }
};