class Solution {
public://O(n^2) is tc and O(1) is sc 
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            ans.insert(ans.begin()+index[i],nums[i]);
        }
        return ans;
    }
};
