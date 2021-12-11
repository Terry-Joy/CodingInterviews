class Solution {
public:
    int numWays(int n) {
		int x=1,y=1,z=1;
		const int mod=1e9+7;
		if(n<=1)return 1;
		for(int i=2;i<=n;++i){
			z=(x+y)%mod;
			x=y;
			y=z;
		}
		return z;
    }
};