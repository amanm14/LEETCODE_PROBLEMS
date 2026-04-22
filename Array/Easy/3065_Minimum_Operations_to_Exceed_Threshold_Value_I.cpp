class Solution {
public://o(nlogn) is tc and o(1) is sc
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=k){
                return i;
            }
        }
        return -1;
    }
};
