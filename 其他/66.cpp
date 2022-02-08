class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n = A.size();
        vector<int> ans(n, 1);
        int s1 = 0, sum1 = A[0], pos1 = 1, s2 = n - 1, sum2 = A[n - 1], pos2 = n - 2;
        while (pos1 <= n - 1) {
            ans[pos1] *= sum1;
            sum1 *= A[++s1];
            pos1++;
            ans[pos2] *= sum2;
            sum2 *= A[--s2];
            pos2--;
        }
        return ans;
    }
};