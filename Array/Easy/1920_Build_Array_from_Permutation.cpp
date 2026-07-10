class Solution {
public://O(n) is tc and O(1) is sc
    vector<int> buildArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i]=nums[nums[i]];
        }
        return ans;
    }
};
