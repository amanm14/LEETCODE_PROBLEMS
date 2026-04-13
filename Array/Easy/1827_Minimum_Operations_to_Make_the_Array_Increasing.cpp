class Solution {
public://O(n) is tc and O(1) is sc
    int minOperations(vector<int>& nums) {
        int op=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            // while(nums[i]>=nums[i+1])
            // {
            //     nums[i+1]+=1;
            //     op++;
            // }
            if(nums[i]>=nums[i+1]){
                int z=nums[i]-nums[i+1]+1;
                nums[i+1]+=nums[i]-nums[i+1]+1;
                op=op+z;
            }
        }
        return op;
    }
};
