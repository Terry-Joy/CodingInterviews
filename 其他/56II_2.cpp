//O(n) O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int A = 0, B = 0;
        for (int i : nums) {
            A = (i ^ A) & (~B);
            B = (i ^ B) & (~A);
        }
        return A;
    }
};