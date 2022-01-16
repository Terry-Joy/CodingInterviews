class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(!matrix.size())
            return ans;
        int l = 0, r = matrix[0].size() - 1, u = 0, d = matrix.size() - 1;
        while(true) {
            for(int i = l; i <= r; ++i)
                ans.emplace_back(matrix[u][i]);
            u++;
            if(u > d)
                break;
            for(int i = u; i <= d; ++i)
                ans.emplace_back(matrix[i][r]);
            r--;
            if(l > r)
                break;
            for(int i = r; i >= l; --i)
                ans.emplace_back(matrix[d][i]);
            d--;
            if(u > d)
                break;
            for(int i = d; i >= u; --i) 
                ans.emplace_back(matrix[i][l]);
            l++;
            if(l > r)
                break;
        } 
        return ans;
    }
};