class Solution {
public://O(n) is tc and O(1) sc 
    vector<int> runningSum(vector<int>& nums) {
        // vector<int>ans;
        int s=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            nums[i]=s;
        }
        return nums;
    }
};
