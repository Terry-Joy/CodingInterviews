//普通解法 O(10^n - 1)
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> ans;
        int limit = 1;
        for(int i = 1; i <= n; ++i){
            limit *= 10;
        }
        limit--;
        int now = 1;
        while(now <= limit) {
            ans.emplace_back(now++);
        }
        return ans;
    }
};