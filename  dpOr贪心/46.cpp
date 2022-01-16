class Solution {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int solve(string nums) {
        int n=nums.size();
        vector<int>dp(nums.size()+1,0);
        if(nums[0]=='0')return 0;
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;++i){
            if(nums[i-1]!='0')
                dp[i]=dp[i-1];
            if(nums[i-2]=='1'&&(nums[i-1]<='9'&&nums[i-1]>='0'))
               dp[i]+=dp[i-2];
            else if(nums[i-2]=='2'&&nums[i-1]>='0'&&nums[i-1]<='6')
               dp[i]+=dp[i-2];
            else if(nums[i-1]=='0')return 0;
        }
        return dp[n];
        // write code here
    }
};