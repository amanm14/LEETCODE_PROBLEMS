class Solution {
public://O(n) is tc and sc
    int countHillValley(vector<int>& nums) {
        int cnt=0,idx=1;
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1]) idx++;
            else if(nums[i]>nums[i-idx]&&nums[i]>nums[i+1]){
                 cnt++;
                 idx=1;
            }
            else if(nums[i]<nums[i-idx]&&nums[i]<nums[i+1]){
                cnt++;
                idx=1;
            }
            else continue;
        }
        return cnt;
    }
};
