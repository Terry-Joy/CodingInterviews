class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return int整型
     */
    int lengthOfLongestSubstring(string s) {
        // write code here
        unordered_map<char,int>mp;
        int num=s.length(),ans=1;
        vector<int>dp(num,0);
        dp[0]=1;mp[s[0]]=0;
        for(int i=1;i<num;++i){
            if(!mp.count(s[i])){
                dp[i]=dp[i-1]+1;
            }else{
                dp[i]=min(dp[i-1]+1,i-mp[s[i]]);
            }
            mp[s[i]]=i;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};