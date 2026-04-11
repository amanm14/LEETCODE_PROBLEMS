class Solution {
public://O(ologn) is tc and O(1) is sc
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=nums.size()-1;i>0;i--)
        {
            ans=ans+min(nums[i-1],nums[i]);
            i--;
        }
        return ans;
    }
};
