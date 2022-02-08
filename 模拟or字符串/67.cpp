//O(n) O(1) 
class Solution {
public:
    int strToInt(string str) {
        int fi = str.find_first_not_of(' '), se = str.find_last_not_of(' ');
        if (fi == -1 && se == -1)
            return 0;
        str = str.substr(fi, se - fi + 1);
        int flag = 1;
        long long ans = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (!i && str[i] == '-') {
                flag = -1;
                continue;
            }
            else if(!i && str[i] == '+')
                continue;
            if (isdigit(str[i])) {
                ans = ans * 10 + str[i] - '0';
                if (ans * flag <= INT_MIN) 
                    return INT_MIN;
                else if (ans * flag >= INT_MAX)
                    return INT_MAX;
            } else
                break;        
        }
        return ans * flag;
    }
};