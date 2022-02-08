//O(n) O(1)
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int flag = 0, mx = -1, mn = 15;
        for (auto u : numbers) {
            if(!u)
                continue;
            if(flag & (1 << u)){
                return false;
            }
            flag |= (1 << u);
            mx = max(mx, u);
            mn = min(mn, u);
        }
        return mx - mn < 5;
    }
};