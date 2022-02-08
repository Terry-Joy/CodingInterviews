//O(n) 
class Solution {
public:
    bool isNumber(string s) {
        if(!s.length())
            return false;
        int fi = s.find_first_not_of(' '), se = s.find_last_not_of(' ');
        if (fi == -1 && se == -1)
            return false;
        s = s.substr(fi, se - fi + 1);
        bool isDot = false, isNum = false, isE = false;
        for (int i = 0; i < s.size(); ++i) {
            if(isdigit(s[i])) { //遇到数字
                isNum = true;
            } else if (s[i] == '.') { //不能有重点且不能出现e
                if (isDot || isE) 
                    return false;
                isDot = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (!isNum || isE) 
                    return false;
                isE = true;
                isNum = false; //123e
            } else if (s[i] == '-' || s[i] == '+') { //符号该出现的位置
                if (i && s[i-1] != 'E' && s[i-1] != 'e')
                    return false;
            } else //其他都不合法
                return false;
        }
        return isNum;
    }
};