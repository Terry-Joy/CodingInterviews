//快排思想 O(n) O(n)
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k >= arr.size())
            return arr;
        function<vector<int> (int, int, int)> dfs = [&](int l, int r, int k) {
            int i = l, j = r;
            while (i < j) {
                while (i < j && arr[j] >= arr[l])
                    j--;
                while (i < j && arr[i] <= arr[l])
                    i++;
                swap(arr[i], arr[j]);
            }
            swap(arr[i], arr[l]);
            if (i > k)
                return dfs(l, i - 1, k);
            if (i < k)
                return dfs(i + 1, r, k);
            vector<int> ans;
            ans.assign(arr.begin(), arr.begin() + k);   
            return ans;           
        };
        return dfs(0, arr.size() - 1, k);
    }
};