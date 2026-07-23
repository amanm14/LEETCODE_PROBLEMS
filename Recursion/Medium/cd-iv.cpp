class Solution {
public://tc is O(N^T) and O(T) is sc
    void dfs(int target, vector<int>& nums, int &ans)
    {
        if(target == 0)
        {
            ans++;
            return;
        }

        if(target < 0)
            return;

        for(int i = 0; i < nums.size(); i++)
        {
            dfs(target - nums[i], nums, ans);
        }
    }

    int combinationSum4(vector<int>& nums, int target) {
        int ans = 0;
        dfs(target, nums, ans);
        return ans;
    }
};
