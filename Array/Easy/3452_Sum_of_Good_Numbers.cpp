class Solution {
public://O(N) is tc and O(1) is sc
    int sumOfGoodNumbers(vector<int>& nums, int k){
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            cout<<"H "<<nums[i]<<endl;
            if((i-k)>=0&&(i+k)<nums.size()){
                if(nums[i-k]<nums[i]&&nums[i]>nums[i+k])ans+=nums[i];
            }
            else if((i-k)<0&&(i+k)>nums.size()-1) ans+=nums[i];
            else{    
                if((i-k)>=0&&nums[i-k]<nums[i]){
                    cout<<"i-k "<<nums[i-k]<<endl;
                    ans+=nums[i];
                }
                if((i+k)<nums.size()&&nums[i]>nums[i+k]){
                    cout<<"i+k "<<nums[i+k]<<endl;
                    ans+=nums[i];
                }
            }
        }
        return ans;
    }
};
