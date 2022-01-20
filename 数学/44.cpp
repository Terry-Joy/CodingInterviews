class Solution {
  public:
    int findNthDigit(int n) {
        if (!n)
            return 0;
        int bit = 0, res = 0, ans = n;
        long long sum = 9, st = 1;
        while (n > 0) { //找bit和剩余多少个数字
            if (n <= sum)
                break;
            n -= sum;
            bit++;
            sum = sum / bit * 10 * (bit + 1);
            st *= 10;
        }
        bit++;
        if (bit == 1)
            return ans;
        int num = st + n / bit - 1 + (n % bit != 0);
        n -= n / bit * bit;
        sum = (!n) ? 1 : bit - n + 1, st = 0;
        while (st < sum) {
            ans = num % 10;
            num /= 10;
            st++;
        }
        return ans;
    }
};