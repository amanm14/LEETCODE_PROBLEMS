class Solution {
public://O(n) is tc and O(n) is sc
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;
        for(auto i:nums)
        {
            if(i<pivot) ans.push_back(i);
        }
        for( auto i:nums)
        {
            if(i==pivot) ans.push_back(i);
        }
        for(auto i:nums)
        {
            if(i>pivot) ans.push_back(i);
        }
        return ans;
    }
};
