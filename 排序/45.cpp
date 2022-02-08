class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> tmp;
        for (auto u : nums) {
            tmp.push_back(to_string(u));
        }
        sort(tmp.begin(), tmp.end(), [&](string & x, string & y) {
            return x + y < y + x;
        });
        string ans = "";
        for (auto u : tmp)
            ans += u;
        return ans;
    }
};