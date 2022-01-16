
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0],now=nums[0];
        for(int i=1;i<nums.size();++i){
            if(now <0){
                now=nums[i];
            }else{
                now+=nums[i];
            }
            ans=max(ans,now);
        }
        return ans;
    }
};