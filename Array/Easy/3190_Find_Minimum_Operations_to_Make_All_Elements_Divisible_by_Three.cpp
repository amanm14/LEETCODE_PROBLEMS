class Solution {
public://O(n) is tc and O(1) is sc
    int minimumOperations(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%3!=0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
