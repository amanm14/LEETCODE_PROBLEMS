class Solution {
public://O(n) is tc and sc is O(1)
    int maxProduct(vector<int>& nums) {
        // if(nums.size()==0) return
        int n=nums.size();
        int maxt=nums[0];
        int mint=nums[0],res=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]<0)
            {
                int t=maxt;
                maxt=mint;
                mint=t;
            }

            maxt=max(nums[i],maxt*nums[i]);
            mint=min(nums[i],mint*nums[i]);

            res=max(maxt,res);
        }
        if(res==INT_MIN) res=nums[0];
        return res;
    }
};
