class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        bool f = (n < 0) ? 1 : 0;
        long long b = n;
        if (b < 0)
            b = - b;    
        while(b) {
            if(b & 1)
                ans = ans * x;
            x = x * x;
            b >>= 1;
        }
        return f ? 1.0/ans : ans; 
    }
};