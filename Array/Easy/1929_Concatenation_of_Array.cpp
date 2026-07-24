class Solution {
public://O(n) is tc and O(n) is sc
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans(nums.begin(),nums.end());
        for(auto it:nums)ans.push_back(it);
        return ans;
    }
};
