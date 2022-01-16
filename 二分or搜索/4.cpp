class Solution {
  public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        if (!matrix.size())
            return false;
        int i = matrix.size() - 1, j = 0, m = matrix[0].size();
        while (i >= 0 && j < m) {
            if (matrix[i][j] > target)
                i--;
            else if (matrix[i][j] < target)
                j++;
            else
                return true;
        }
        return false;
    }
};