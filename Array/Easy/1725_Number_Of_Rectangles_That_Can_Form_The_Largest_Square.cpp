class Solution {
public://O(n) is tc and sc
    int countGoodRectangles(vector<vector<int>>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(min(nums[i][0],nums[i][1]));
        }
        int p=0,cnt=0;

        for(auto i:ans)
        {
            p=max(p,i);
        }
        for(auto i:ans)
        {
            if(i==p) cnt++;
        }
        return cnt;
    }
};
