//分治递归O(n^2) 左 右 根 
class Solution {
  public:
    bool verifyPostorder(vector<int> &postorder) {
        function<bool(int, int)> solve = [&](int l, int r) {
            if (l >= r)
                return true;
            int root = postorder[r];
            int mid = l;
            while (postorder[mid] < root && mid < r) {
                mid++;
            }
            if (mid == r)
                return solve(l, r - 1);
            int x = mid - 1;
            while (postorder[mid] > root && mid < r) {
                mid++;
            }
            if (mid < r)
                return false;
            return solve(l, x) && solve(x + 1, r - 1);
        };
        return solve(0, postorder.size() - 1);
    }
};