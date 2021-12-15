class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        // write code here
        int ans=array[0],tmp=array[0];
        int tmpst=0,tmped=1,st=0,ed=1,n=array.size();
        for(int i=1;i<n;++i){
            if(tmp<0){
                tmp=array[i];
                tmpst=i;
                tmped=i+1;
            }else{
                tmp+=array[i];
                tmped++;
            }
            if(tmp>ans){
                ans=tmp;
                st=tmpst;
                ed=tmped;
            }else if(tmp==ans&&ed-st<tmped-tmpst){
				st=tmpst;
				ed=tmped;
			}
        }
        vector<int>a;
		for(int i=st;i<ed;++i)a.push_back(array[i]);
        return a;
    }
};