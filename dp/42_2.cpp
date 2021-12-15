class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int n=array.size(),ans=array[0];
        vector<int>dp(n,0);
        dp[0]=array[0];
        for(int i=1;i<n;++i){
            dp[i]=max(array[i],dp[i-1]+array[i]);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};