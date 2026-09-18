class Solution {
public://O(N^2) is tc and sc is O(1)
    int countPairs(vector<int>& nums, int target) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]<target) cnt++;
            }
        }
        return cnt;
    }
};
