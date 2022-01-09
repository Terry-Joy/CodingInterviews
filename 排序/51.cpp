class Solution {
  public:
    int InversePairs(vector<int> data) {
	#define lowb(i) (i & (-i))
        vector<int> mp;
        for (auto &u : data)
            u++;
        const int mod = 1e9 + 7;
        int mx = *max_element(data.begin(), data.end());
        mp.resize(mx + 1);
        auto add = [&](int x, int val) {
            for (int i = x; i <= mx; i += lowb(i))
                mp[i] += val;
        };
        auto ask = [&](int x) {
            if (x <= 0)
                return 0ll;
            long long ans = 0;
            for (int i = x; i; i -= lowb(i))
                ans += mp[i];
            return ans % mod;
        };
        long long sum = 0;
        for (int i = data.size() - 1; i >= 0; --i) {
            sum += ask(data[i] - 1);
            sum %= mod;
            add(data[i], 1);
        }
        return sum;
    }
};