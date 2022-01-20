//数学推导 O(logn) O(1)
class Solution {
    const int mod = 1e9 + 7;

  public:
    int cuttingRope(int n) {
        auto mypow = [&](int a, int b) {
            int ans = 1;
            while (b) {
                if (b & 1)
                    ans = (long long)ans * a % mod;
                a = (long long)a * a % mod;
                b >>= 1;
            }
            return ans;
        };
        if (n <= 3)
            return n - 1;
        int res = n % 3, cnt = n / 3;
        if (res == 1) {
            cnt--;
            return (long long)mypow(3, cnt) * 4 % mod;
        } else if (res == 2) {
            return mypow(3, cnt) * 2 % mod;
        } else
            return mypow(3, cnt);
    }
};