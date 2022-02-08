class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int n = str.size();
        if(!n)
            return -1;
        unordered_map<char, int> mp;
        for (auto u : str)
             mp[u]++;
        for (auto u : str) 
            if(mp[u] == 1)
                return str.find_first_of(u);
        return -1;
    }
};