class Solution {
public://O(N) is tc and sc is O(1)
    int returnToBoundaryCount(vector<int>& nums) {
        int cnt=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            cnt+=nums[i];
            if(cnt==0) ans++;
        }
        return ans;
    }
};
