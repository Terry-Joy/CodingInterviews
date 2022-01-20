//大数解法
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> ans;
        function<void(int, int, string)> dfs = [&](int num, int limit, string s){
            if(num == limit){
                ans.emplace_back(stoi(s));
                return;
            }
            for(char j = '0'; j <= '9'; ++j)
                dfs(num + 1, limit, s + j);
        }; 
        for(int i = 1; i <= n; ++i) {
            for(char j = '1'; j <= '9'; ++j) {
                string s(1, j);
                dfs(1, i, s);
            }
        }
        return ans;
    }
};