class Solution {
public:
    string reverseWords(string s) {
        string str = " ";
        str += s;
        string ans = "";
        int l = str.size() - 1, r = str.size() - 1;
        while (l >= 0) {
            if (str[l] == ' ' && str[r] != ' ') {
                ans += str.substr(l + 1, r - l);
                ans += ' ';
                r = l;
            }
            if(str[r] == ' ')
                r--;
            l--;
        }
        ans.pop_back();
        return ans;
    }
};