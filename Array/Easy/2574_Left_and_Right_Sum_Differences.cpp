class Solution {
public://O(n) is tc and sc
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>ans(nums.size());
        int x=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            ans[i]=abs(x-(sum-x-nums[i]));
            x+=nums[i];
        }
        return ans;
    }
};
