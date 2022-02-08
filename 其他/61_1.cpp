//O(nlogn) O(1)
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        set<int> ans;
        for (auto u : numbers) {
            if(!u)
                continue;
            if (ans.find(u) != ans.end()) {
                return false; 
            }else
                ans.insert(u);
        }
        auto it = ans.end(), it2 = ans.begin();
        it--;
        return *it - *it2 < 5;
    }
};