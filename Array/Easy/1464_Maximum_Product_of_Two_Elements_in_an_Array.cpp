class Solution {
public://O(n) is tc and O(1) is sc
    int maxProduct(vector<int>& nums) {
        int temp=INT_MIN,stemp=INT_MIN+1;
        int idx=0;
        for(int i=0;i<nums.size();i++)
        {
            if(temp<nums[i])
            {
                temp=nums[i];
                idx=i;
            }
            // temp=max(temp,nums[i]);
            
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>stemp&&(nums[i]<=temp&&i!=idx))
            {
                stemp=nums[i];
            }
        }
        return (stemp-1)*(temp-1);

    }
};
