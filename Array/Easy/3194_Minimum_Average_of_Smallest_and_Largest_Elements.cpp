class Solution {
public://O(NlogN) is tc and O(1) is sc
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        for(int i=0;i<nums.size()/2;i++)
        {
            int t=nums[i]+nums[nums.size()-i-1];
            ans=min(ans,t);
        }
        return (double)ans/2;
    }
};
