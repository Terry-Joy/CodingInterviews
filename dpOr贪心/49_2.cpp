class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long> > q;
        q.push(1);
        int cnt = 0;
        unordered_set<long long> s;
        s.insert(1);
        while (true) {
            int x = q.top();
            q.pop();
            cnt++;
            if (cnt == n)
                return x;
            for (auto u: {2, 3, 5}) {
                long long val =(long long) u * x;
                if(!s.count(val)) {
                    q.push(val);
                    s.insert(val);
                }
            }
        }
    }
};